#ifndef BTagEntryForLJMet_H
#define BTagEntryForLJMet_H

/**
 *
 * BTagEntryForLJMet
 *
 * Represents one pt- or discriminator-dependent calibration function.
 *
 * measurement_type:    e.g. comb, ttbar, di-mu, boosted, ...
 * sys_type:            e.g. central, plus, minus, plus_JEC, plus_JER, ...
 *
 * Everything is converted into a function, as it is easiest to store it in a
 * txt or json file.
 *
 ************************************************************/

#include <string>
#include <TF1.h>
#include <TH1.h>


class BTagEntryForLJMet
{
public:
  enum OperatingPoint {
    OP_LOOSE=0,
    OP_MEDIUM=1,
    OP_TIGHT=2,
    OP_RESHAPING=3,
  };
  enum JetFlavor {
    FLAV_B=5,
    FLAV_C=4,
    FLAV_UDSG=0,
  };
  struct Parameters {
    OperatingPoint operatingPoint;
    std::string measurementType;
    std::string sysType;
    JetFlavor jetFlavor;
    float etaMin;
    float etaMax;
    float ptMin;
    float ptMax;
    float discrMin;
    float discrMax;

    // default constructor
    Parameters(
      OperatingPoint op=OP_TIGHT,
      std::string measurement_type="comb",
      std::string sys_type="central",
      JetFlavor jf=FLAV_B,
      float eta_min=-99999.,
      float eta_max=99999.,
      float pt_min=0.,
      float pt_max=99999.,
      float discr_min=0.,
      float discr_max=99999.
    );

  };

  BTagEntryForLJMet() {}
  BTagEntryForLJMet(const std::string &csvLine);
  BTagEntryForLJMet(const std::string &func, Parameters p);
  BTagEntryForLJMet(const TF1* func, Parameters p);
  BTagEntryForLJMet(const TH1* histo, Parameters p);
  ~BTagEntryForLJMet() {}
  static std::string makeCSVHeader();
  std::string makeCSVLine() const;
  static std::string trimStr(std::string str);

  // public, no getters needed
  std::string formula;
  Parameters params;

};

#endif  // BTagEntryForLJMet_H


#ifndef BTagCalibrationForLJMet_H
#define BTagCalibrationForLJMet_H

/**
 * BTagCalibrationForLJMet
 *
 * The 'hierarchy' of stored information is this:
 * - by tagger (BTagCalibrationForLJMet)
 *   - by operating point or reshape bin
 *     - by jet parton flavor
 *       - by type of measurement
 *         - by systematic
 *           - by eta bin
 *             - as 1D-function dependent of pt or discriminant
 *
 ************************************************************/

#include <map>
#include <vector>
#include <string>
#include <istream>
#include <ostream>


class BTagCalibrationForLJMet
{
public:
  BTagCalibrationForLJMet() {}
  BTagCalibrationForLJMet(const std::string &tagger);
  BTagCalibrationForLJMet(const std::string &tagger, const std::string &filename);
  ~BTagCalibrationForLJMet() {}

  std::string tagger() const {return tagger_;}

  void addEntry(const BTagEntryForLJMet &entry);
  const std::vector<BTagEntryForLJMet>& getEntries(const BTagEntryForLJMet::Parameters &par) const;

  void readCSV(std::istream &s);
  void readCSV(const std::string &s);
  void makeCSV(std::ostream &s) const;
  std::string makeCSV() const;

protected:
  static std::string token(const BTagEntryForLJMet::Parameters &par);

  std::string tagger_;
  std::map<std::string, std::vector<BTagEntryForLJMet> > data_;

};

#endif  // BTagCalibrationForLJMet_H


#ifndef BTagCalibrationForLJMetReader_H
#define BTagCalibrationForLJMetReader_H

/**
 * BTagCalibrationForLJMetReader
 *
 * Helper class to pull out a specific set of BTagEntryForLJMet's out of a
 * BTagCalibrationForLJMet. TF1 functions are set up at initialization time.
 *
 ************************************************************/

#include <memory>
#include <string>



class BTagCalibrationForLJMetReader
{
public:
  class BTagCalibrationForLJMetReaderImpl;

  BTagCalibrationForLJMetReader() {}
  BTagCalibrationForLJMetReader(BTagEntryForLJMet::OperatingPoint op,
                        const std::string & sysType="central",
                        const std::vector<std::string> & otherSysTypes={});

  void load(const BTagCalibrationForLJMet & c,
            BTagEntryForLJMet::JetFlavor jf,
            const std::string & measurementType="comb");

  double eval(BTagEntryForLJMet::JetFlavor jf,
              float eta,
              float pt,
              float discr=0.) const;

  double eval_auto_bounds(const std::string & sys,
                          BTagEntryForLJMet::JetFlavor jf,
                          float eta,
                          float pt,
                          float discr=0.) const;

  std::pair<float, float> min_max_pt(BTagEntryForLJMet::JetFlavor jf,
                                     float eta,
                                     float discr=0.) const;

protected:
  std::shared_ptr<BTagCalibrationForLJMetReaderImpl> pimpl;
};


#endif  // BTagCalibrationForLJMetReader_H
