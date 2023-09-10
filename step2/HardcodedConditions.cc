#define HardcodedConditions_cxx
#include <cmath>
#include "HardcodedConditions.h"
#include <unordered_map>


using namespace std;

HardcodedConditions::HardcodedConditions() {}

HardcodedConditions::HardcodedConditions( std::string year ) {

  TString sfFileName( "HT_njets_SF_UL17_sys.root" );
  if( year == "2016APV" ){
    sfFileName = "HT_njets_SF_UL16APV_sys.root"; 
  }
  else if( year == "2016" ){
    sfFileName = "HT_njets_SF_UL16_sys.root"; 
  }
  else if( year == "2018" ){
    sfFileName = "HT_njets_SF_UL18_sys.root";
  }

  cout << ">> Reading scale factor file: " << sfFileName << endl;
  if( !( tfile_HTNJ_SF = TFile::Open( sfFileName ) ) ){
    std::cout << "[WARN] File does not exist. Exiting..." << std::endl;
    exit(1);  
  }

  std::string SYSs[19] = { "", "_HFup", "_HFdn", "_LFup", "_LFdn", "_jesup", "_jesdn", "_hfstats1up", "_hfstats1dn", "_hfstats2up", "_hfstats2dn", "_cferr1up", "_cferr1dn", "_cferr2up", "_cferr2dn", "_lfstats1up", "_lfstats1dn", "_lfstats2up", "_lfstats2dn" };  
  for( size_t i = 0; i < 19; i++ ){
    hscale_TTTX[SYSs[i]]         = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTTX"+SYSs[i]).c_str())->Clone();
    hscale_TTNOBB[SYSs[i]]       = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTNOBB"+SYSs[i]).c_str())->Clone();
    hscale_TTBB[SYSs[i]]         = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTBB"+SYSs[i]).c_str())->Clone();
    hscale_TTNOBBHT500[SYSs[i]]  = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTNOBBHT500"+SYSs[i]).c_str())->Clone();
    hscale_TTBBHT500[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTBBHT500"+SYSs[i]).c_str())->Clone();
    hscale_ST[SYSs[i]]           = (TH2F*)tfile_HTNJ_SF->Get(("hscale_ST"+SYSs[i]).c_str())->Clone();
    hscale_QCD[SYSs[i]]          = (TH2F*)tfile_HTNJ_SF->Get(("hscale_QCD"+SYSs[i]).c_str())->Clone();
    hscale_TTH[SYSs[i]]          = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTH"+SYSs[i]).c_str())->Clone();
    hscale_TTXY[SYSs[i]]         = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTXY"+SYSs[i]).c_str())->Clone();
    hscale_EWK[SYSs[i]]          = (TH2F*)tfile_HTNJ_SF->Get(("hscale_EWK"+SYSs[i]).c_str())->Clone();
  }
}

HardcodedConditions::~HardcodedConditions() {}

float HardcodedConditions::GetDeepJetRenorm2DSF_HTnj( float HT, int njets, std::string sampleType, std::string sysType ){
  if( hscale_TTNOBB.find( sysType ) == hscale_TTNOBB.end() ) return 1.0;
  if( sampleType == "" ) return 1.0;
  int njets_idx = njets;
  if( njets_idx > 8 ) njets_idx = 8;

  if( sampleType == "TTTW" || sampleType == "TTTJ" || sampleType == "TTTT" ){
    return hscale_TTTX[ sysType ]->GetBinContent( hscale_TTTX[ sysType ]->FindBin( njets_idx, HT ) );
  }

  if( sampleType == "ttjj" || sampleType == "ttcc" || sampleType == "tt2b" || sampleType == "tt1b" ){
    return hscale_TTNOBB[ sysType ]->GetBinContent( hscale_TTNOBB[ sysType ]->FindBin( njets_idx, HT ) );
  }  

  if( sampleType == "ttbb" ){
    return hscale_TTBB[ sysType ]->GetBinContent( hscale_TTBB[ sysType ]->FindBin( njets_idx, HT ) );
  }  

  if( sampleType == "HT500ttjj" || sampleType == "HT500ttcc" || sampleType == "HT500tt2b" || sampleType == "HT500tt1b" ){
    return hscale_TTNOBBHT500[ sysType ]->GetBinContent( hscale_TTNOBBHT500[ sysType ]->FindBin( njets_idx, HT ) );
  }  

  if( sampleType == "HT500ttbb" ){
    return hscale_TTBBHT500[ sysType ]->GetBinContent( hscale_TTBBHT500[ sysType ]->FindBin( njets_idx, HT ) );
  }  

  if( sampleType == "ST" ){
    return hscale_ST[ sysType ]->GetBinContent( hscale_ST[ sysType ]->FindBin( njets_idx, HT ) );
  } 

  if( sampleType == "QCD" ){
    return hscale_QCD[ sysType ]->GetBinContent( hscale_QCD[ sysType ]->FindBin( njets_idx, HT ) );
  }

  if( sampleType == "ttHTobb" || sampleType == "ttHToNonbb" ){
    return hscale_TTH[ sysType ]->GetBinContent( hscale_TTH[ sysType ]->FindBin( njets_idx, HT ) );
  }

  if( sampleType == "TTXY" || sampleType == "TTHH" ){
    return hscale_TTXY[ sysType ]->GetBinContent( hscale_TTXY[ sysType ]->FindBin( njets_idx, HT ) );
  }

  if( sampleType == "EWK" || sampleType == "WJets" || sampleType == "DYM" ){
    return hscale_EWK[ sysType ]->GetBinContent( hscale_EWK[ sysType ]->FindBin( njets_idx, HT ) );
  }

  return 1.0;  
} 

float HardcodedConditions::GetCrossSectionEfficiency( TString inputFileName, std::string Year ){ // used for event weighting, only compute for samples used in DNN training
  if( Year == "2016APV" ){
    if( inputFileName.Contains( "TTToSemiLeptonic_TuneCP5" ) && inputFileName.Contains( "HT0Njet0" ) ) return 0.0528778;
    else if( inputFileName.Contains( "TTToSemiLeptonic_TuneCP5" ) ) return 0.00032878;
    else if( inputFileName.Contains( "TTToSemiLepton_HT500Njet9_TuneCP5" ) ) return 0.009888;
    else if( inputFileName.Contains( "TTToHadronic_TuneCP5" ) ) return 0.079669;
    else if( inputFileName.Contains( "TTTo2L2Nu_TuneCP5" ) ) return 0.0417654;
    else if( inputFileName.Contains( "TTTT" ) ) return 0.00006756;
    else if( inputFileName.Contains( "TTTW" ) ) return 0.00004199;
    else if( inputFileName.Contains( "TTTJ" ) ) return 0.00002569;
    else return 1.0;

  }
  else if( Year == "2016" ){
    if( inputFileName.Contains( "TTToSemiLeptonic_TuneCP5" ) && inputFileName.Contains( "HT0Njet0" ) ) return 0.04090;
    else if( inputFileName.Contains( "TTToSemiLepton_HT500Njet9_TuneCP5" ) ) return 0.00818;
    else if( inputFileName.Contains( "TTToSemiLeptonic_TuneCP5" ) ) return 0.00025;
    else if( inputFileName.Contains( "TTToHadronic_TuneCP5" ) ) return 0.03069;
    else if( inputFileName.Contains( "TTTo2L2Nu_TuneCP5" ) ) return 0.03099;
    else if( inputFileName.Contains( "TTTT" ) ) return 0.00009;
    else if( inputFileName.Contains( "TTTW" ) ) return 0.00007;
    else if( inputFileName.Contains( "TTTJ" ) ) return 0.00004;
    else return 1.0;
  }
  else if( Year == "2017" ){
    if( inputFileName.Contains( "TTToSemiLeptonic_TuneCP5" ) && inputFileName.Contains( "HT0Njet0" ) ) return 0.021966;
    else if( inputFileName.Contains( "TTToSemiLepton_HT500Njet9_TuneCP5" ) ) return 0.005377;
    else if( inputFileName.Contains( "TTToSemiLeptonic_TuneCP5" ) ) return 0.000137;
    else if( inputFileName.Contains( "TTToHadronic_TuneCP5" ) ) return 0.067437;
    else if( inputFileName.Contains( "TTTo2L2Nu_TuneCP5" ) ) return 0.034275;
    else if( inputFileName.Contains( "TTTT" ) ) return 0.0000823;
    else if( inputFileName.Contains( "TTTW" ) ) return 0.0000677;
    else if( inputFileName.Contains( "TTTJ" ) ) return 0.0000354;
    else return 1.0;
  }
  else if( Year == "2018" ){
    if( inputFileName.Contains( "TTToSemiLeptonic_TuneCP5" ) && inputFileName.Contains( "HT0Njet0" ) ) return 0.039594;
    else if( inputFileName.Contains( "TTToSemiLepton_HT500Njet9_TuneCP5" ) ) return 0.0083537;
    else if( inputFileName.Contains( "TTToSemiLeptonic_TuneCP5" ) ) return 0.00024618;
    else if( inputFileName.Contains( "TTToHadronic_TuneCP5" ) ) return 0.070496;
    else if( inputFileName.Contains( "TTTo2L2Nu_TuneCP5" ) ) return 0.041249;
    else if( inputFileName.Contains( "TTTT" ) ) return 0.0001737;
    else if( inputFileName.Contains( "TTTW" ) ) return 0.0000616;
    else if( inputFileName.Contains( "TTTJ" ) ) return 0.0000372;
    else return 1.0;
  }
  else return 1.0;
}

float HardcodedConditions::GetBTagWP( std::string Year, std::string tagger ){
  if( tagger == "deepJet" ){
    if( Year == "2017" ) return 0.3040;
    else if( Year == "2018" ) return 0.2783;
    else if( Year == "2016" ) return 0.2489;
    else if( Year == "2016APV" ) return 0.2598;
    else return 1.0;
  }
  else if( tagger == "deepCSV" ){
    if( Year == "2017" ) return 0.4506;
    else if( Year == "2018" ) return 0.4168;
    else if( Year == "2016" ) return 0.5847;
    else if( Year == "2016APV" ) return 0.6001;
    else return 1.0;
  }
  else return 1.0;
}
