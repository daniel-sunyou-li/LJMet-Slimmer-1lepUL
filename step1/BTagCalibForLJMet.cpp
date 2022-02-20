#include "BTagCalibForLJMet.h"
#include <iostream>
#include <exception>
#include <algorithm>
#include <sstream>


BTagEntryForLJMet::Parameters::Parameters(
  OperatingPoint op,
  std::string measurement_type,
  std::string sys_type,
  JetFlavor jf,
  float eta_min,
  float eta_max,
  float pt_min,
  float pt_max,
  float discr_min,
  float discr_max
):
  operatingPoint(op),
  measurementType(measurement_type),
  sysType(sys_type),
  jetFlavor(jf),
  etaMin(eta_min),
  etaMax(eta_max),
  ptMin(pt_min),
  ptMax(pt_max),
  discrMin(discr_min),
  discrMax(discr_max)
{
  std::transform(
    measurementType.begin(), 
    measurementType.end(),
    measurementType.begin(), 
    ::tolower);
  std::transform(
    sysType.begin(), 
    sysType.end(),
    sysType.begin(), 
    ::tolower);
}

BTagEntryForLJMet::BTagEntryForLJMet(const std::string &csvLine){
  // make tokens
  std::stringstream buff(csvLine);
  std::vector<std::string> vec;
  std::string token;
  while( std::getline( buff, token, ","[0] ) ){
    token = BTagEntryForLJMet::trimStr(token);
    if (token.empty()){
      continue;
    }
    vec.push_back(token);
  }
  if (vec.size() != 11) {
std::cerr << "ERROR in BTagCalibrationForLJMet: "
          << "Invalid csv line; num tokens != 11: "
          << csvLine;
throw std::exception();
  }

  // clean string values
  char chars[] = " \"\n";
  for (unsigned int i = 0; i < strlen(chars); ++i) {
    vec[1].erase(remove(vec[1].begin(),vec[1].end(),chars[i]),vec[1].end());
    vec[2].erase(remove(vec[2].begin(),vec[2].end(),chars[i]),vec[2].end());
    vec[10].erase(remove(vec[10].begin(),vec[10].end(),chars[i]),vec[10].end());
  }

  // make formula
  formula = vec[10];
  TF1 f1("", formula.c_str());  // compile formula to check validity
  if (f1.IsZombie()) {
    std::cerr << "ERROR in BTagCalibrationForLJMet: "
              << "Invalid csv line; formula does not compile: "
              << csvLine;
    throw std::exception();
  }

  // make parameters
  unsigned op = stoi(vec[0]);
  if (op > 4) {
    std::cerr << "ERROR in BTagCalibrationForLJMet: "
              << "Invalid csv line; OperatingPoint > 4: "
              << csvLine;
    throw std::exception();
  }
  unsigned jf = stoi(vec[3]);
  if (jf > 6) {
    std::cerr << "ERROR in BTagCalibrationForLJMet: "
              << "Invalid csv line; JetFlavor > 6: "
              << csvLine;
    throw std::exception();
  }
  params = BTagEntryForLJMet::Parameters(
    BTagEntryForLJMet::OperatingPoint(op),
    vec[1],
    vec[2],
    BTagEntryForLJMet::JetFlavor(jf),
    stof(vec[4]),
    stof(vec[5]),
    stof(vec[6]),
    stof(vec[7]),
    stof(vec[8]),
    stof(vec[9])
  );
}

BTagEntryForLJMet::BTagEntryForLJMet(const std::string &func, BTagEntryForLJMet::Parameters p):
  formula(func),
  params(p)
{
  TF1 f1("", formula.c_str());  // compile formula to check validity
  if (f1.IsZombie()) {
    std::cerr << "ERROR in BTagCalibrationForLJMet: "
              << "Invalid func string; formula does not compile: "
              << func;
    throw std::exception();
  }
}

BTagEntryForLJMet::BTagEntryForLJMet(const TF1* func, BTagEntryForLJMet::Parameters p):
  formula(std::string(func->GetExpFormula("p").Data())),
  params(p)
{
  if (func->IsZombie()) {
    std::cerr << "ERROR in BTagCalibrationForLJMet: "
              << "Invalid TF1 function; function is zombie: "
              << func->GetName();
    throw std::exception();
  }
}

// Creates chained step functions like this:
// "<prevous_bin> : x<bin_high_bound ? bin_value : <next_bin>"
// e.g. "x<0 ? 1 : x<1 ? 2 : x<2 ? 3 : 4"
std::string th1ToFormulaLin(const TH1* hist) {
  int nbins = hist->GetNbinsX();
  TAxis const* axis = hist->GetXaxis();
  std::stringstream buff;
  buff << "x<" << axis->GetBinLowEdge(1) << " ? 0. : ";  // default value
  for (int i=1; i<nbins+1; ++i) {
    char tmp_buff[50];
    sprintf(tmp_buff,
            "x<%g ? %g : ",  // %g is the smaller one of %e or %f
            axis->GetBinUpEdge(i),
            hist->GetBinContent(i));
    buff << tmp_buff;
  }
  buff << 0.;  // default value
  return buff.str();
}

// Creates step functions making a binary search tree:
// "x<mid_bin_bound ? (<left side tree>) : (<right side tree>)"
// e.g. "x<2 ? (x<1 ? (x<0 ? 0:0.1) : (1)) : (x<4 ? (x<3 ? 2:3) : (0))"
std::string th1ToFormulaBinTree(const TH1* hist, int start=0, int end=-1) {
  if (end == -1) {                      // initialize
    start = 0.;
    end = hist->GetNbinsX()+1;
    TH1* h2 = (TH1*) hist->Clone();
    h2->SetBinContent(start, 0);  // kill underflow
    h2->SetBinContent(end, 0);    // kill overflow
    std::string res = th1ToFormulaBinTree(h2, start, end);
    delete h2;
    return res;
  }
  if (start == end) {                   // leave is reached
    char tmp_buff[20];
    sprintf(tmp_buff, "%g", hist->GetBinContent(start));
    return std::string(tmp_buff);
  }
  if (start == end - 1) {               // no parenthesis for neighbors
    char tmp_buff[70];
    sprintf(tmp_buff,
            "x<%g ? %g:%g",
            hist->GetXaxis()->GetBinUpEdge(start),
            hist->GetBinContent(start),
            hist->GetBinContent(end));
    return std::string(tmp_buff);
  }

  // top-down recursion
  std::stringstream buff;
  int mid = (end-start)/2 + start;
  char tmp_buff[25];
  sprintf(tmp_buff,
          "x<%g ? (",
          hist->GetXaxis()->GetBinUpEdge(mid));
  buff << tmp_buff
       << th1ToFormulaBinTree(hist, start, mid)
       << ") : ("
       << th1ToFormulaBinTree(hist, mid+1, end)
       << ")";
  return buff.str();
}

BTagEntryForLJMet::BTagEntryForLJMet(const TH1* hist, BTagEntryForLJMet::Parameters p):
  params(p)
{
  int nbins = hist->GetNbinsX();
  TAxis const* axis = hist->GetXaxis();

  // overwrite bounds with histo values
  if (params.operatingPoint == BTagEntryForLJMet::OP_RESHAPING) {
    params.discrMin = axis->GetBinLowEdge(1);
    params.discrMax = axis->GetBinUpEdge(nbins);
  } else {
    params.ptMin = axis->GetBinLowEdge(1);
    params.ptMax = axis->GetBinUpEdge(nbins);
  }

  // balanced full binary tree height = ceil(log(2*n_leaves)/log(2))
  // breakes even around 10, but lower values are more propable in pt-spectrum
  if (nbins < 15) {
    formula = th1ToFormulaLin(hist);
  } else {
    formula = th1ToFormulaBinTree(hist);
  }

  // compile formula to check validity
  TF1 f1("", formula.c_str());
  if (f1.IsZombie()) {
std::cerr << "ERROR in BTagCalibrationForLJMet: "
          << "Invalid histogram; formula does not compile (>150 bins?): "
          << hist->GetName();
throw std::exception();
  }
}

std::string BTagEntryForLJMet::makeCSVHeader()
{
  return "OperatingPoint, "
         "measurementType, "
         "sysType, "
         "jetFlavor, "
         "etaMin, "
         "etaMax, "
         "ptMin, "
         "ptMax, "
         "discrMin, "
         "discrMax, "
         "formula \n";
}

std::string BTagEntryForLJMet::makeCSVLine() const
{
  std::stringstream buff;
  buff << params.operatingPoint
       << ", " << params.measurementType
       << ", " << params.sysType
       << ", " << params.jetFlavor
       << ", " << params.etaMin
       << ", " << params.etaMax
       << ", " << params.ptMin
       << ", " << params.ptMax
       << ", " << params.discrMin
       << ", " << params.discrMax
       << ", \"" << formula
       << "\" \n";
  return buff.str();
}

std::string BTagEntryForLJMet::trimStr(std::string str) {
  size_t s = str.find_first_not_of(" \n\r\t");
  size_t e = str.find_last_not_of (" \n\r\t");

  if((std::string::npos == s) || (std::string::npos == e))
    return "";
  else
    return str.substr(s, e-s+1);
}


#include <fstream>
#include <sstream>



BTagCalibrationForLJMet::BTagCalibrationForLJMet(const std::string &taggr):
  tagger_(taggr)
{}

BTagCalibrationForLJMet::BTagCalibrationForLJMet(const std::string &taggr,
                                 const std::string &filename):
  tagger_(taggr)
{
  std::ifstream ifs(filename);
  if (!ifs.good()) {
std::cerr << "ERROR in BTagCalibrationForLJMet: "
          << "input file not available: "
          << filename;
throw std::exception();
  }
  readCSV(ifs);
  ifs.close();
}

void BTagCalibrationForLJMet::addEntry(const BTagEntryForLJMet &entry)
{
  data_[token(entry.params)].push_back(entry);
}

const std::vector<BTagEntryForLJMet>& BTagCalibrationForLJMet::getEntries(
  const BTagEntryForLJMet::Parameters &par) const
{
  std::string tok = token(par);
  if (!data_.count(tok)) {
std::cerr << "ERROR in BTagCalibrationForLJMet: "
          << "(OperatingPoint, measurementType, sysType) not available: "
          << tok;
throw std::exception();
  }
  return data_.at(tok);
}

void BTagCalibrationForLJMet::readCSV(const std::string &s)
{
  std::stringstream buff(s);
  readCSV(buff);
}

void BTagCalibrationForLJMet::readCSV(std::istream &s)
{
  std::string line;

  // firstline might be the header
  getline(s,line);
  if (line.find("OperatingPoint") == std::string::npos) {
    addEntry(BTagEntryForLJMet(line));
  }

  while (getline(s,line)) {
    line = BTagEntryForLJMet::trimStr(line);
    if (line.empty()) {  // skip empty lines
      continue;
    }
    addEntry(BTagEntryForLJMet(line));
  }
}

void BTagCalibrationForLJMet::makeCSV(std::ostream &s) const
{
  s << tagger_ << ";" << BTagEntryForLJMet::makeCSVHeader();
  for (std::map<std::string, std::vector<BTagEntryForLJMet> >::const_iterator i
           = data_.cbegin(); i != data_.cend(); ++i) {
    const std::vector<BTagEntryForLJMet> &vec = i->second;
    for (std::vector<BTagEntryForLJMet>::const_iterator j
             = vec.cbegin(); j != vec.cend(); ++j) {
      s << j->makeCSVLine();
    }
  }
}

std::string BTagCalibrationForLJMet::makeCSV() const
{
  std::stringstream buff;
  makeCSV(buff);
  return buff.str();
}

std::string BTagCalibrationForLJMet::token(const BTagEntryForLJMet::Parameters &par)
{
  std::stringstream buff;
  buff << par.operatingPoint << ", "
       << par.measurementType << ", "
       << par.sysType;
  return buff.str();
}




class BTagCalibrationForLJMetReader::BTagCalibrationForLJMetReaderImpl
{
  friend class BTagCalibrationForLJMetReader;

public:
  struct TmpEntry {
    float etaMin;
    float etaMax;
    float ptMin;
    float ptMax;
    float discrMin;
    float discrMax;
    TF1 func;
  };

private:
  BTagCalibrationForLJMetReaderImpl(BTagEntryForLJMet::OperatingPoint op,
                            const std::string & sysType,
                            const std::vector<std::string> & otherSysTypes={});

  void load(const BTagCalibrationForLJMet & c,
            BTagEntryForLJMet::JetFlavor jf,
            std::string measurementType);

  double eval(BTagEntryForLJMet::JetFlavor jf,
              float eta,
              float pt,
              float discr) const;

  double eval_auto_bounds(const std::string & sys,
                          BTagEntryForLJMet::JetFlavor jf,
                          float eta,
                          float pt,
                          float discr) const;

  std::pair<float, float> min_max_pt(BTagEntryForLJMet::JetFlavor jf,
                                     float eta,
                                     float discr) const;

  BTagEntryForLJMet::OperatingPoint op_;
  std::string sysType_;
  std::vector<std::vector<TmpEntry> > tmpData_;  // first index: jetFlavor
  std::vector<bool> useAbsEta_;                  // first index: jetFlavor
  std::map<std::string, std::shared_ptr<BTagCalibrationForLJMetReaderImpl>> otherSysTypeReaders_;
};


BTagCalibrationForLJMetReader::BTagCalibrationForLJMetReaderImpl::BTagCalibrationForLJMetReaderImpl(
                                             BTagEntryForLJMet::OperatingPoint op,
                                             const std::string & sysType,
                                             const std::vector<std::string> & otherSysTypes):
  op_(op),
  sysType_(sysType),
  tmpData_(3),
  useAbsEta_(3, true)
{
  for (const std::string & ost : otherSysTypes) {
    if (otherSysTypeReaders_.count(ost)) {
std::cerr << "ERROR in BTagCalibrationForLJMet: "
            << "Every otherSysType should only be given once. Duplicate: "
            << ost;
throw std::exception();
    }
    otherSysTypeReaders_[ost] = std::auto_ptr<BTagCalibrationForLJMetReaderImpl>(
        new BTagCalibrationForLJMetReaderImpl(op, ost)
    );
  }
}

void BTagCalibrationForLJMetReader::BTagCalibrationForLJMetReaderImpl::load(
                                             const BTagCalibrationForLJMet & c,
                                             BTagEntryForLJMet::JetFlavor jf,
                                             std::string measurementType)
{
  if (tmpData_[jf].size()) {
std::cerr << "ERROR in BTagCalibrationForLJMet: "
          << "Data for this jet-flavor is already loaded: "
          << jf;
throw std::exception();
  }

  BTagEntryForLJMet::Parameters params(op_, measurementType, sysType_);
  const std::vector<BTagEntryForLJMet> &entries = c.getEntries(params);

  for (const auto &be : entries) {
    if (be.params.jetFlavor != jf) {
      continue;
    }

    TmpEntry te;
    te.etaMin = be.params.etaMin;
    te.etaMax = be.params.etaMax;
    te.ptMin = be.params.ptMin;
    te.ptMax = be.params.ptMax;
    te.discrMin = be.params.discrMin;
    te.discrMax = be.params.discrMax;

    if (op_ == BTagEntryForLJMet::OP_RESHAPING) {
      te.func = TF1("", be.formula.c_str(),
                    be.params.discrMin, be.params.discrMax);
    } else {
      te.func = TF1("", be.formula.c_str(),
                    be.params.ptMin, be.params.ptMax);
    }

    tmpData_[be.params.jetFlavor].push_back(te);
    if (te.etaMin < 0) {
      useAbsEta_[be.params.jetFlavor] = false;
    }
  }

  for (auto & p : otherSysTypeReaders_) {
    p.second->load(c, jf, measurementType);
  }
}

double BTagCalibrationForLJMetReader::BTagCalibrationForLJMetReaderImpl::eval(
                                             BTagEntryForLJMet::JetFlavor jf,
                                             float eta,
                                             float pt,
                                             float discr) const
{
  bool use_discr = (op_ == BTagEntryForLJMet::OP_RESHAPING);
  if (useAbsEta_[jf] && eta < 0) {
    eta = -eta;
  }

  // search linearly through eta, pt and discr ranges and eval
  // future: find some clever data structure based on intervals
  const auto &entries = tmpData_.at(jf);
  for (unsigned i=0; i<entries.size(); ++i) {
    const auto &e = entries.at(i);
    if (
      e.etaMin <= eta && eta < e.etaMax                   // find eta
      && e.ptMin < pt && pt <= e.ptMax                    // check pt
    ){
      if (use_discr) {                                    // discr. reshaping?
        if (e.discrMin <= discr && discr < e.discrMax) {  // check discr
          return e.func.Eval(discr);
        }
      } else {
        return e.func.Eval(pt);
      }
    }
  }

  return 0.;  // default value
}

double BTagCalibrationForLJMetReader::BTagCalibrationForLJMetReaderImpl::eval_auto_bounds(
                                             const std::string & sys,
                                             BTagEntryForLJMet::JetFlavor jf,
                                             float eta,
                                             float pt,
                                             float discr) const
{
  auto sf_bounds = min_max_pt(jf, eta, discr);
  float pt_for_eval = pt;
  bool is_out_of_bounds = false;

  if (pt < sf_bounds.first) {
    pt_for_eval = sf_bounds.first + .0001;
    is_out_of_bounds = true;
  } else if (pt > sf_bounds.second) {
    pt_for_eval = sf_bounds.second - .0001;
    is_out_of_bounds = true;
  }

  // get central SF (and maybe return)
  double sf = eval(jf, eta, pt_for_eval, discr);
  if (sys == sysType_) {
    return sf;
  }

  // get sys SF (and maybe return)
  if (!otherSysTypeReaders_.count(sys)) {
std::cerr << "ERROR in BTagCalibrationForLJMet: "
        << "sysType not available (maybe not loaded?): "
        << sys;
throw std::exception();
  }
  double sf_err = otherSysTypeReaders_.at(sys)->eval(jf, eta, pt_for_eval, discr);
  if (!is_out_of_bounds) {
    return sf_err;
  }

  // double uncertainty on out-of-bounds and return
  sf_err = sf + 2*(sf_err - sf);
  return sf_err;
}

std::pair<float, float> BTagCalibrationForLJMetReader::BTagCalibrationForLJMetReaderImpl::min_max_pt(
                                               BTagEntryForLJMet::JetFlavor jf,
                                               float eta,
                                               float discr) const
{
  bool use_discr = (op_ == BTagEntryForLJMet::OP_RESHAPING);
  if (useAbsEta_[jf] && eta < 0) {
    eta = -eta;
  }

  const auto &entries = tmpData_.at(jf);
  float min_pt = -1., max_pt = -1.;
  for (const auto & e: entries) {
    if (
      e.etaMin <= eta && eta < e.etaMax                   // find eta
    ){
      if (min_pt < 0.) {                                  // init
        min_pt = e.ptMin;
        max_pt = e.ptMax;
        continue;
      }

      if (use_discr) {                                    // discr. reshaping?
        if (e.discrMin <= discr && discr < e.discrMax) {  // check discr
          min_pt = min_pt < e.ptMin ? min_pt : e.ptMin;
          max_pt = max_pt > e.ptMax ? max_pt : e.ptMax;
        }
      } else {
        min_pt = min_pt < e.ptMin ? min_pt : e.ptMin;
        max_pt = max_pt > e.ptMax ? max_pt : e.ptMax;
      }
    }
  }

  return std::make_pair(min_pt, max_pt);
}


BTagCalibrationForLJMetReader::BTagCalibrationForLJMetReader(BTagEntryForLJMet::OperatingPoint op,
                                             const std::string & sysType,
                                             const std::vector<std::string> & otherSysTypes):
  pimpl(new BTagCalibrationForLJMetReaderImpl(op, sysType, otherSysTypes)) {}

void BTagCalibrationForLJMetReader::load(const BTagCalibrationForLJMet & c,
                                 BTagEntryForLJMet::JetFlavor jf,
                                 const std::string & measurementType)
{
  pimpl->load(c, jf, measurementType);
}

double BTagCalibrationForLJMetReader::eval(BTagEntryForLJMet::JetFlavor jf,
                                   float eta,
                                   float pt,
                                   float discr) const
{
  return pimpl->eval(jf, eta, pt, discr);
}

double BTagCalibrationForLJMetReader::eval_auto_bounds(const std::string & sys,
                                               BTagEntryForLJMet::JetFlavor jf,
                                               float eta,
                                               float pt,
                                               float discr) const
{
  return pimpl->eval_auto_bounds(sys, jf, eta, pt, discr);
}

std::pair<float, float> BTagCalibrationForLJMetReader::min_max_pt(BTagEntryForLJMet::JetFlavor jf,
                                                          float eta,
                                                          float discr) const
{
  return pimpl->min_max_pt(jf, eta, discr);
}
