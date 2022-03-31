#define HardcodedConditions_cxx
#include <cmath>
#include "HardcodedConditions.h"
#include <unordered_map>


using namespace std;

HardcodedConditions::HardcodedConditions() {}

HardcodedConditions::HardcodedConditions( std::string year ) {

  TString sfFileName( "HT_njets_SF_UL17_sys.root" );
  if( year == "2016APV" ){
    sfFileName = "HT_njets_SF_UL16APV_sys.root" ); 
  }
  else if( year == "2016" ){
    sfFileName = "HT_njets_SF_UL16_sys.root" ); 
  }
  else if( year == "2018" ){
    sfFileName = "HT_njets_SF_UL18_sys.root" );
  }

  cout << ">> Reading scale factor file: " << sfFileName << endl;
  if( !( tfile_HTNJ_SF = TFile::Open( sfFileName ) ) ){
    std::cout << "[WARN] File does not exist. Exiting..." << std::endl;
    exit(1);  
  }

  std::string SYSs[19] = { "", "_HFup", "_HFdn", "_LFup", "_LFdn", "_jesup", "_jesdn", "_hfstats1up", "_hfstats1dn", "_hfstats2up", "_hfstats2dn", "_cferr1up", "_cferr1dn", "_cferr2up", "_cferr2dn", "_lfstats1up", "_lfstats1dn", "_lfstats2up", "_lfstats2dn" };  
  for( size_t i = 0; i < 19; i++ ){
    hscale_tttw[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTTW"+SYSs[i]).c_str())->Clone();
    hscale_tttj[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTTJ"+SYSs[i]).c_str())->Clone();  
    hscale_tttt[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTTT"+SYSs[i]).c_str())->Clone();
    hscale_ttjj[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_ttjj"+SYSs[i]).c_str())->Clone();
    hscale_ttbb[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_ttbb"+SYSs[i]).c_str())->Clone();
    hscale_ttcc[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_ttcc"+SYSs[i]).c_str())->Clone();
    hscale_tt2b[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_tt2b"+SYSs[i]).c_str())->Clone();
    hscale_tt1b[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_tt1b"+SYSs[i]).c_str())->Clone();
    hscale_HT500Njet9_ttjj[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_HT500ttjj"+SYSs[i]).c_str())->Clone();
    hscale_HT500Njet9_ttbb[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_HT500ttbb"+SYSs[i]).c_str())->Clone();
    hscale_HT500Njet9_ttcc[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_HT500ttcc"+SYSs[i]).c_str())->Clone();
    hscale_HT500Njet9_tt2b[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_HT500tt2b"+SYSs[i]).c_str())->Clone();
    hscale_HT500Njet9_tt1b[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_HT500tt1b"+SYSs[i]).c_str())->Clone();
    hscale_STs[SYSs[i]]     = (TH2F*)tfile_HTNJ_SF->Get(("hscale_STs"+SYSs[i]).c_str())->Clone();
    hscale_STtw[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_STtw"+SYSs[i]).c_str())->Clone();
    hscale_STt[SYSs[i]]     = (TH2F*)tfile_HTNJ_SF->Get(("hscale_STt"+SYSs[i]).c_str())->Clone();
    hscale_WJets[SYSs[i]]   = (TH2F*)tfile_HTNJ_SF->Get(("hscale_WJets"+SYSs[i]).c_str())->Clone();
    hscale_QCD[SYSs[i]]     = (TH2F*)tfile_HTNJ_SF->Get(("hscale_QCD"+SYSs[i]).c_str())->Clone();
    hscale_DYM[SYSs[i]]     = (TH2F*)tfile_HTNJ_SF->Get(("hscale_DYM"+SYSs[i]).c_str())->Clone();
    hscale_TTHB[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTHB"+SYSs[i]).c_str())->Clone();
    hscale_TTHnonB[SYSs[i]] = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTHnonB"+SYSs[i]).c_str())->Clone();
    hscale_TTHH[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTHH"+SYSs[i]).c_str())->Clone();
    hscale_TTXY[SYSs[i]]    = (TH2F*)tfile_HTNJ_SF->Get(("hscale_TTXY"+SYSs[i]).c_str())->Clone();
    hscale_EWK[SYSs[i]]     = (TH2F*)tfile_HTNJ_SF->Get(("hscale_EWK"+SYSs[i]).c_str())->Clone();
  }
}

HardcodedConditions::~HardcodedConditions() {}

float HardcodedConditions::GetDeepJetRenorm2DSF_HTnj( float HT, int njets, std::string sampleType, std::string sysType ){
  if( hscale_ttjj.find( sysType ) == hscale_ttjj.end() ) return 1.0;
  if( sampleType == "" ) return 1.0;
  int njets_idx = njets;
  if( njets_idx > 7 ) njets_idx = 7;

  if( sampleType == "tttw" ){
    return hscale_tttw[ sysType ]->GetBinContent( hscale_tttw[ sysType ]->FindBin( njets_idx, HT ) );
  }

  if( sampleType == "tttj" ){
    return hscale_tttj[ sysType ]->GetBinContent( hscale_tttj[ sysType ]->FindBin( njets_idx, HT ) );
  }  

  if( sampleType == "tttt" ){
    return hscale_tttt[ sysType ]->GetBinContent( hscale_tttt[ sysType ]->FindBin( njets_idx, HT ) );
  }  

  if( sampleType == "ttjj" ){
    return hscale_ttjj[ sysType ]->GetBinContent( hscale_ttjj[ sysType ]->FindBin( njets_idx, HT ) );
  }  

  if( sampleType == "ttcc" ){
    return hscale_ttcc[ sysType ]->GetBinContent( hscale_ttcc[ sysType ]->FindBin( njets_idx, HT ) );
  }

  if( sampleType == "ttbb" ){
    return hscale_ttbb[ sysType ]->GetBinContent( hscale_ttbb[ sysType ]->FindBin( njets_idx, HT ) );
  }  

  if( sampleType == "tt2b" ){
    return hscale_tt2b[ sysType ]->GetBinContent( hscale_tt2b[ sysType ]->FindBin( njets_idx, HT ) );
  }
  
  if( sampleType == "tt1b" ){
    return hscale_tt1b[ sysType ]->GetBinContent( hscale_tt1b[ sysType ]->FindBin( njets_idx, HT ) );
  }  

  if( sampleType == "HT500Njet9_ttjj" ){
    return hscale_HT500Njet9_ttjj[ sysType ]->GetBinContent( hscale_HT500Njet9_ttjj[ sysType ]->FindBin( njets_idx, HT ) );
  }  

  if( sampleType == "HT500Njet9_ttcc" ){
    return hscale_HT500Njet9_ttcc[ sysType ]->GetBinContent( hscale_HT500Njet9_ttcc[ sysType ]->FindBin( njets_idx, HT ) );
  }

  if( sampleType == "HT500Njet9_ttbb" ){
    return hscale_HT500Njet9_ttbb[ sysType ]->GetBinContent( hscale_HT500Njet9_ttbb[ sysType ]->FindBin( njets_idx, HT ) );
  }  

  if( sampleType == "HT500Njet9_tt2b" ){
    return hscale_HT500Njet9_tt2b[ sysType ]->GetBinContent( hscale_HT500Njet9_tt2b[ sysType ]->FindBin( njets_idx, HT ) );
  }
  
  if( sampleType == "HT500Njet9_tt1b" ){
    return hscale_HT500Njet9_tt1b[ sysType ]->GetBinContent( hscale_HT500Njet9_tt1b[ sysType ]->FindBin( njets_idx, HT ) );
  }  


  if( sampleType == "STs" ){
    return hscale_STs[ sysType ]->GetBinContent( hscale_STs[ sysType ]->FindBin( njets_idx, HT ) );
  } 

  if( sampleType == "STt" ){
    return hscale_STt[ sysType ]->GetBinContent( hscale_STt[ sysType ]->FindBin( njets_idx, HT ) );
  }

  if( sampleType == "STtW" ){
    return hscale_STtw[ sysType ]->GetBinContent( hscale_STtw[ sysType ]->FindBin( njets_idx, HT ) );
  }

  if( sampleType == "WJets" ){
    return hscale_WJets[ sysType ]->GetBinContent( hscale_WJets[ sysType ]->FindBin( njets_idx, HT ) );
  }
  if( sampleType == "QCD" ){
    return hscale_QCD[ sysType ]->GetBinContent( hscale_QCD[ sysType ]->FindBin( njets_idx, HT ) );
  }
  if( sampleType == "DYM" ){
    return hscale_DYM[ sysType ]->GetBinContent( hscale_DYM[ sysType ]->FindBin( njets_idx, HT ) );
  }
  if( sampleType == "TTHB" ){
    return hscale_TTHB[ sysType ]->GetBinContent( hscale_TTHB[ sysType ]->FindBin( njets_idx, HT ) );
  }
  if( sampleType == "TTHnonB" ){
    return hscale_TTHnonB[ sysType ]->GetBinContent( hscale_TTHnonB[ sysType ]->FindBin( njets_idx, HT ) );
  }
  if( sampleType == "TTHH" ){
    return hscale_TTHH[ sysType ]->GetBinContent( hscale_TTHnonB[ sysType ]->FindBin( njets_idx, HT ) );
  }
  if( sampleType == "TTXY" ){
    return hscale_TTXY[ sysType ]->GetBinContent( hscale_TTXY[ sysType ]->FindBin( njets_idx, HT ) );
  }
  if( sampleType == "EWK" ){
    return hscale_EWK[ sysType ]->GetBinContent( hscale_EWK[ sysType ]->FindBin( njets_idx, HT ) );
  }

  return 1.0;  
} 

float HardcodedConditions::GetCrossSectionEfficiency( TString inputFileName, std::string Year ){ // used for event weighting, only compute for samples used in DNN training
  if( Year == "2016APV" ){
    return 1.0; // hasn't been implemented yet 
  }
  else if( Year == "2016" ){
    return 1.0;
  }
  else if( Year == "2017" ){
    if( inputFileName.Contains( "TTToSemiLeptonic_TuneCP5" ) && inputFileName.Contains( "HT0Njet0" ) ) return 0.04269313;
    else if( inputFileName.Contains( "TTToSemiLepton_HT500Njet9_TuneCP5" ) ) return 0.00918382;
    else if( inputFileName.Contains( "TTToSemiLeptonic_TuneCP5" ) && inputFileName.Contains( "HT500Njet9" ) ) return 0.00026545;
    else if( inputFileName.Contains( "TTToHadronic_TuneCP5" ) ) return 0.06751867;
    else if( inputFileName.Contains( "TTTo2L2Nu_TuneCP5" ) ) return 0.01840806;
    else if( inputFileName.Contains( "TTTT" ) ) return 0.000109821;
    else if( inputFileName.Contains( "TTTW" ) ) return 0.00008437;
    else if( inputFileName.Contains( "TTTJ" ) ) return 0.00004662;
    else return 1.0;
  }
  else if( Year == "2018" ){
    return 1.0; // hasn't been implemented yet 
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
