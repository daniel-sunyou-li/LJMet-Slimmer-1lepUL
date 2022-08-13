#include <TSystem.h>
#include "step1.cc"
#include "BTagCalibForLJMet.cpp"
#include "HardcodedConditions.cc"
#include<vector>
#include<string>
using namespace std;

// single file use
void make_step1( TString macroDir, TString inputFile, TString outputFile, string shift, string Year ){
  gROOT->SetMacroPath(macroDir);

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  TString incl("-I");
  incl+=macroDir;
  gSystem->AddIncludePath(incl);

  string btagcsvfile;
  string btagdjcsvfile;
  
  // data
  if( debug == 1 ){
    std::cout << "[INFO] Running in debug mode, using test b-tag reshaping file" << std::endl;
    btagcsvfile = "btag_sf/reshaping_deepCSV_106XUL17_test.csv";
    btagdjcsvfile = "btag_sf/reshaping_deepJet_106XUL17_test.csv";
  }
  else if( Year == "2017" ){
    btagcsvfile = "btag_sf/reshaping_deepCSV_106XUL17_v3.csv";
    btagdjcsvfile = "btag_sf/reshaping_deepJet_106XUL17_v3.csv";
  }
  else if( Year == "2016APV" ){
    btagcsvfile = "btag_sf/reshaping_deepCSV_106XUL16preVFP_v2.csv";
    btagdjcsvfile = "btag_sf/reshaping_deepJet_106XUL16preVFP_v2.csv";
  }
  else if( Year == "2016" ){
    btagcsvfile = "btag_sf/reshaping_deepCSV_106XUL16postVFP_v3.csv";
    btagdjcsvfile = "btag_sf/reshaping_deepJet_106XUL16postVFP_v3.csv";
  }
  else if( Year == "2018" ){
    btagcsvfile = "btag_sf/reshaping_deepCSV_106XUL18_v2.csv";
    btagdjcsvfile = "btag_sf/reshaping_deepJet_106XUL18_v2.csv";
  }

  cout << "[OPT] Using deepCSV reshaping file: " << btagcsvfile << endl;
  cout << "[OPT] Using deepJet reshaping file: "<< btagdjcsvfile << endl;
  auto dc_calib = new const BTagCalibrationForLJMet( "DeepCSV", btagcsvfile ); 
  auto dj_calib = new const BTagCalibrationForLJMet( "DeepJet", btagdjcsvfile );
    
  outputFile.ReplaceAll( ".root", "" );

  if ( inputFile.Contains("Run2016") || inputFile.Contains("Run2017") || inputFile.Contains("Run2018") || inputFile.Contains("Single") || inputFile.Contains("Double") || inputFile.Contains("MuonEG") || inputFile.Contains("EGamma") || inputFile.Contains("JetHT") ) { 
    cout << endl << "[START] Running step1 for data" << endl;
    step1 t( inputFile, outputFile + "nominal.root", Year, "nominal" );
    t.Loop( "ljmet", "ljmet", dc_calib, dj_calib ); 
  }
  else { // MC
    cout << endl << "[START] Running step1 for MC shift: " << shift << endl;
    TString tName = "ljmet";
    if ( shift == "JECup" || shift == "JECdown" || shift == "JERdown" || shift == "JERup" ){ 
      tName.Append( "_" + shift ); 
    }
    step1 t( inputFile, outputFile + shift + ".root", Year, shift );
      t.saveHistograms();
      t.Loop( tName, "ljmet", dc_calib, dj_calib );
  }
}

// multiple file use
void make_step1( TString macroDir, string filelist, string shift, string Year ){
  gROOT->SetMacroPath(macroDir);

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");

  TString incl("-I");
  incl+=macroDir;
  gSystem->AddIncludePath(incl);

  string line;
  ifstream myfile (filelist);
  vector<pair<string,string> > Files;
  if( myfile.is_open() )
  {
    while ( getline (myfile,line) )
    {
      auto pos = line.find(",");
      Files.emplace_back(line.substr(0, pos),line.substr(pos + 1));
    }
    myfile.close();
    
    string btagcsvfile = "reshaping_deepCSV_106XUL16preVFP_v2.csv";
    string btagdjcsvfile = "reshaping_deepJet_106XUL16preVFP_v2.csv";
    if( debug == 1 ){
      cout << "[DEBUG] Using test btag reshaping files" << endl;
      btagcsvfile = "reshaping_deepCSV_106XUL17_test.csv";
      btagdjcsvfile = "reshaping_deepJet_106XUL17_test.csv";
    }
    if( Year == "2016" ){
      btagcsvfile = "reshaping_deepCSV_106XUL16postVFP_v3.csv";
      btagdjcsvfile = "reshaping_deepJet_106XUL16postVFP_v3.csv";
    }
    else if( Year == "2017" ){
      btagcsvfile = "reshaping_deepCSV_106XUL17_v3.csv";
      btagdjcsvfile = "reshaping_deepJet_106XUL17_v3.csv";
    }
    else if( Year == "2018" ){
      btagcsvfile = "reshaping_deepCSV_106XUL18_v2.csv";
      btagdjcsvfile = "reshaping_deepJet_106XUL18_v2.csv";
    }
    
    cout << "[OPT] Using deepCSV reshaping file: " << btagcsvfile << endl;
    cout << "[OPT] Using deepJet reshaping file: " << btagdjcsvfile << endl;
    auto dc_calib = new const BTagCalibrationForLJMet( "DeepCSV", btagcsvfile ); 
    auto dj_calib = new const BTagCalibrationForLJMet( "DeepJet", btagdjcsvfile );
   
    for (auto f : Files){
      TString inputFile(f.first);
      TString outputFile(f.second);
      outputFile.ReplaceAll( ".root", "" );
      if ( inputFile.Contains("Run2016") || inputFile.Contains("Run2017") || inputFile.Contains("Run2018") || inputFile.Contains("Single") || inputFile.Contains("EGamma") ){ 
        step1 t( inputFile, outputFile + "nominal.root", Year, "nominal" );
        t.Loop( "ljmet", "ljmet", dc_calib, dj_calib); 
      }
      else{
        cout << endl << ">> Running " << inputFile << " for shift: " << shift << endl;
        TString tName = "ljmet";
        if( shift == "JECup" || shift == "JECdown" || shift == "JERup" || shift == "JERdown" ){
          tName.Append( "_" + shift ); // only JEC/JER+up/down were stored as separate trees
        }
        step1 t( inputFile, outputFile + shift + ".root", Year, shift ); 
        t.saveHistograms();
        t.Loop( tName, "ljmet", dc_calib, dj_calib );
      }
    }
  }
  else cout << "[ERR] Unable to open filelist"; 
}
