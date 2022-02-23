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
  
  // data
  
  std::string btagcsvfile( "btag_sf/reshaping_deepCSV_106XUL17_v3.csv" );
  std::string btagdjcsvfile("btag_sf/reshaping_deepJet_106XUL17_v3.csv");
  if( Year == "2016APV" ){
    btagcsvfile = "btag_sf/reshaping_deepCSV_106XUL16preVFP_v2.csv";
    btagdjcsvfile = "btag_sf/reshaping_deepJet_106XUL16preVFP_v2.csv";
  }
  else if( Year == "2016" ){
    btagcsvfile = "reshaping_deepCSV_106XUL16postVFP_v3.csv";
    btagdjcsvfile = "reshaping_deepJet_106XUL16postVFP_v3.csv";
  }
  else if( Year == "2018" ){
    btagcsvfile = "reshaping_deepCSV_106XUL18_v2.csv";
    btagdjcsvfile = "reshaping_deepJet_106XUL18_v2.csv";
  }

  cout << "[OPT] Using deepCSV reshaping file: " << btagcsvfile << endl;
  cout << "[OPT] Using deepJet reshaping file: "<< btagdjcsvfile << endl;
  auto calib = new const BTagCalibrationForLJMet( "DeepCSV", btagcsvfile ); 
  auto dj_calib = new const BTagCalibrationForLJMet( "DeepJet", btagdjcsvfile );

  if ( inputFile.Contains("Run2016") || inputFile.Contains("Run2017") || inputFile.Contains("Run2018") || inputFile.Contains("Single") || inputFile.Contains("Double") || inputFile.Contains("MuonEG") || inputFile.Contains("EGamma") || inputFile.Contains("JetHT") ) { 
    cout << endl << "[START] Running step1 for data" << endl;
    step1 t(inputFile,outputFile.ReplaceAll(".root","nominal.root"),Year);
    t.Loop("ljmet", "ljmet", calib, dj_calib); 
  }
  else { // MC
    cout << endl << "[START] Running step1 for MC shift: " << shift << endl;
    TString tName = "ljmet";
    if ( shift != "nominal" ) { tName.Append("_"); tName.Append( shift ); }
      step1 t(inputFile,outputFile.ReplaceAll(".root", shift + ".root"),Year); //"shifts[i]" is now changed to "shifts[i].root"
      t.saveHistograms();
      t.Loop(tName, "ljmet", calib, dj_calib);
      outputFile.ReplaceAll(shift,".root"); //Change outputFile back to its original name.
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
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      auto pos = line.find(",");
      Files.emplace_back(line.substr(0, pos),line.substr(pos + 1));
    }
    myfile.close();

    std::string btagcsvfile( "reshaping_deepCSV_106XUL17_v3.csv" );
    std::string btagdjcsvfile("reshaping_deepJet_106XUL17_v3.csv");
    if( Year == "2016APV" ){
      btagcsvfile = "reshaping_deepCSV_106XUL16preVFP_v2.csv";
      btagdjcsvfile = "reshaping_deepJet_106XUL16preVFP_v2.csv";
    }
    else if( Year == "2016" ){
      btagcsvfile = "reshaping_deepCSV_106XUL16postVFP_v3.csv";
      btagdjcsvfile = "reshaping_deepJet_106XUL16postVFP_v3.csv";
    }
    else if( Year == "2018" ){
      btagcsvfile = "reshaping_deepCSV_106XUL18_v2.csv";
      btagdjcsvfile = "reshaping_deepJet_106XUL18_v2.csv";
    }
    
    cout << "[OPT] Using deepCSV reshaping file: " << btagcsvfile << endl;
    cout << "[OPT] Using deepJet reshaping file: "<< btagdjcsvfile << endl;
    auto calib = new const BTagCalibrationForLJMet( "DeepCSV", btagcsvfile ); 
    auto dj_calib = new const BTagCalibrationForLJMet( "DeepJet", btagdjcsvfile );
   
    for (auto f : Files){
      TString inputFile(f.first);
      TString outputFile(f.second);
      if ( inputFile.Contains("Run2016") || inputFile.Contains("Run2017") || inputFile.Contains("Run2018") || inputFile.Contains("Single") || inputFile.Contains("EGamma") ){ 
        step1 t(inputFile,outputFile.ReplaceAll(".root","nominal.root"),Year);
        t.Loop("ljmet", "ljmet",calib, dj_calib); 
      }
      else{
        cout << endl << ">> Running " << inputFile << " for shift: " << shift << endl;
        TString tName = "ljmet";
        if (  shift != "nominal" ){
          tName.Append("_"); tName.Append(shift);
        }
        step1 t(inputFile,outputFile.ReplaceAll(".root", shift + ".root"),Year); //"shifts[i]" is now changed to "shifts[i].root"
        t.saveHistograms();
        t.Loop( tName, "ljmet",calib, dj_calib );
        outputFile.ReplaceAll(shift,".root"); //Change outputFile back to its original name.
      }
    }
  }
  else cout << "[ERR] Unable to open filelist"; 
}
