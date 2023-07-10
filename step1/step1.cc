#define step1_cxx
#include "step1.h"
#include <fstream>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <TH2.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <TH3.h>
#include "HardcodedConditions.h"
#include "BTagCalibForLJMet.h"

using namespace std;

// ----------------------------------------------------------------------------
// Define functions
// ----------------------------------------------------------------------------

bool comparepair( const std::pair<double,int> a, const std::pair<double,int> b) { return a.first > b.first; }
bool comparefloat( const float a, const float b) { return a < b; }
int debug = 0;

TRandom3 Rand;

const double MTOP  = 173.5;
const double MW    = 80.4; 

double step1::compute_SFWeight( vector<double>& SF, vector<double>& Eff, vector<int>& Tag ){
  double pMC = 1.;
  double pData = 1.;
  for( unsigned int i = 0; i < Tag.size(); i++ ){
    if( Tag.at(i) == 1 ){
      pMC *= Eff.at(i);
      pData *= ( SF.at(i) * Eff.at(i) );
    }
    else {
      pMC *= ( 1. - Eff.at(i) );
      pData *= ( 1. - SF.at(i) * Eff.at(i) );
    }
  }
  return pData / pMC;
}

bool step1::applySF(bool& isTagged, float tag_SF, float tag_eff){
  
  bool newTag = isTagged;
  if (tag_SF == 1) return newTag; //no correction needed 

  //throw die
  float coin = Rand.Uniform(1.);    

  if(tag_SF > 1){  // use this if SF>1

    if( !isTagged ) {

      //fraction of jets that need to be upgraded
      float mistagPercent = (1.0 - tag_SF) / (1.0 - (tag_SF/tag_eff) );

      //upgrade to tagged
      if( coin < mistagPercent ) {newTag = true;}
    }

  }else{  // use this if SF<1
      
    //downgrade tagged to untagged
    if( isTagged && coin > tag_SF ) {newTag = false;}

  }

  return newTag;
}

// -------------------------------------
// Function- SAVE Histograms from ljmet
//--------------------------------------
void step1::saveHistograms() { 
TH1D* numhist = (TH1D*)inputFile->Get("mcweightanalyzer/NumTrueHist");
TH1D* wgthist = (TH1D*)inputFile->Get("mcweightanalyzer/weightHist");
outputFile->cd();
numhist->Write();
wgthist->Write();

}


// ----------------------------------------------------------------------------
// MAIN EVENT LOOP
// ----------------------------------------------------------------------------

void step1::Loop(TString inTreeName, TString outTreeName, const BTagCalibrationForLJMet* calib = NULL, const BTagCalibrationForLJMet* calib_dj = NULL){
  if( debug == 1 ) cout << "[DEBUG] Running in debugging mode" << endl;
  
  // Reduced JEC systematic uncertainties
  bool shiftUp = true;
  string bSyst = "nominal";
  if( isMC && !( Syst == "nominal" || Syst == "JECup" || Syst == "JECdown" || Syst == "JERup" || Syst == "JERdown" ) ){
    // select the corresponding file for the year
    string fJEC;
    if( Syst.Contains( "FlavorPure" ) ){
      fJEC = "Summer19UL16APV_V7_MC_UncertaintySources_AK4PFchs.txt";
      if( Year == "2016" ) fJEC = "Summer19UL16_V7_MC_UncertaintySources_AK4PFchs.txt";
      else if( Year == "2017" ) fJEC = "Summer19UL17_V5_MC_UncertaintySources_AK4PFchs.txt";
      else if( Year == "2018" ) fJEC = "Summer19UL18_V5_MC_UncertaintySources_AK4PFchs.txt";
    }
    else{
      fJEC = "RegroupedV2_Summer19UL16APV_V7_MC_UncertaintySources_AK4PFchs.txt";
      if( Year == "2016" ) fJEC = "RegroupedV2_Summer19UL16_V7_MC_UncertaintySources_AK4PFchs.txt";
      else if( Year == "2017" ) fJEC = "RegroupedV2_Summer19UL17_V5_MC_UncertaintySources_AK4PFchs.txt";
      else if( Year == "2018" ) fJEC = "RegroupedV2_Summer19UL18_V5_MC_UncertaintySources_AK4PFchs.txt";
    }
    cout << ">> Syst: " << Syst << endl;
    if( Syst.EndsWith( "up" ) ) shiftUp = true;
    else if( Syst.EndsWith( "down" ) ) shiftUp = false;

    bSyst = (std::string)Syst.ReplaceAll( "JEC_", "" ).ReplaceAll( "up", "" ).ReplaceAll( "down", "" ); // base name of the systematic
    cout << "[INFO] Running reduced JEC source: " << Syst << endl;
    cout << ">> JEC File: " << fJEC << endl;
    cout << ">> Shift: ";
    if( shiftUp ) cout << "up" << endl;
    else cout << "down" << endl;
    jecUnc = std::shared_ptr<JetCorrectionUncertainty>( new JetCorrectionUncertainty( *( new JetCorrectorParameters( fJEC, bSyst ) ) ) );
  }

  string btag_prefix = "up_";
  if( !shiftUp ) btag_prefix = "down_";
  vector<string> btag_syst;
  if( debug == 1 ){
    btag_syst = { "down_hfstats2" };
  }
  else {
    btag_syst = {"up_jes", "down_jes", "up_lf", "down_lf", "up_hfstats1", "down_hfstats1",
     "up_hfstats2", "down_hfstats2", "up_cferr1", "down_cferr1", "up_cferr2",
     "down_cferr2", "up_hf", "down_hf", "up_lfstats1", "down_lfstats1",
     "up_lfstats2", "down_lfstats2"};
  }
  auto bYear = Year;
  if( Year == "2016APV" ) bYear = "2016";

  if( bSyst == "Absolute" ) btag_syst.push_back( btag_prefix + "jesAbsolute" );
  else if( bSyst == "Absolute_" + bYear ) btag_syst.push_back( btag_prefix + "jesAbsolute_" + bYear );
  else if( bSyst == "HF" ) btag_syst.push_back( btag_prefix + "jesHF" );
  else if( bSyst == "HF_" + bYear ) btag_syst.push_back( btag_prefix + "jesHF_" + bYear );
  else if( bSyst == "BBEC1" ) btag_syst.push_back( btag_prefix + "jesBBEC1" );
  else if( bSyst == "BBEC1_" + bYear ) btag_syst.push_back( btag_prefix + "jesBBEC1_" + bYear );
  else if( bSyst == "EC2" ) btag_syst.push_back( btag_prefix + "jesEC2" );
  else if( bSyst == "EC2_" + bYear ) btag_syst.push_back( btag_prefix + "jesEC2_" + bYear );
  else if( bSyst == "FlavorQCD" ) btag_syst.push_back( btag_prefix + "jesFlavorQCD" );
  else if( bSyst == "FlavorPureGluon" ) btag_syst.push_back( btag_prefix + "jesFlavorQCD" );   // no FlavorPureGluon shift in deepJet systematics as of 03/09/2023
  else if( bSyst == "FlavorPureQuark" ) btag_syst.push_back( btag_prefix + "jesFlavorQCD" );   // no FlavorPureQuark shift in deepJet systematics as of 03/09/2023
  else if( bSyst == "FlavorPureCharm" ) btag_syst.push_back( btag_prefix + "jesFlavorQCD" );   // no FlavorPureCharm shift in deepJet systematics as of 03/09/2023
  else if( bSyst == "FlavorPureBottom" ) btag_syst.push_back( btag_prefix + "jesFlavorQCD" );  // no FlavorPureBottom shift in deepJet systematics as of 03/09/2023
  else if( bSyst == "RelativeBal" ) btag_syst.push_back( btag_prefix + "jesRelativeBal" );
  else if( bSyst == "RelativeSample_" + bYear ) btag_syst.push_back( btag_prefix + "jesRelativeSample_" + bYear );


  BTagCalibrationForLJMetReader reader(
    BTagEntryForLJMet::OP_RESHAPING,  // operating point
    "central",             // central sys type
    btag_syst );
 
  reader.load( *calib, BTagEntryForLJMet::FLAV_B, "iterativefit" );       
  reader.load( *calib, BTagEntryForLJMet::FLAV_C, "iterativefit" );   
  reader.load( *calib, BTagEntryForLJMet::FLAV_UDSG, "iterativefit" );

  BTagCalibrationForLJMetReader reader_dj(
    BTagEntryForLJMet::OP_RESHAPING,  // operating point
    "central",             // central sys type
    btag_syst  );      
  
  reader_dj.load(*calib_dj, BTagEntryForLJMet::FLAV_B, "iterativefit");       
  reader_dj.load(*calib_dj, BTagEntryForLJMet::FLAV_C, "iterativefit");     
  reader_dj.load(*calib_dj, BTagEntryForLJMet::FLAV_UDSG, "iterativefit");  

  HardcodedConditions hardcodedConditions;


  // ----------------------------------------------------------------------------
  // Turn on input tree branches
  // ----------------------------------------------------------------------------
  inputTree=(TTree*)inputFile->Get(inTreeName+"/"+inTreeName);
  if( inputTree->GetEntries() == 0 ) {
    cout << "[WARNING] Found 0 events in the tree, quitting..." << endl;
    return;
  }
  Init( inputTree );

  if ( inputTree == 0 ) return;

  inputTree->SetBranchStatus( "*", 0 );


  //Event info
  inputTree->SetBranchStatus("event_CommonCalc",1);
  inputTree->SetBranchStatus("run_CommonCalc",1);
  inputTree->SetBranchStatus("lumi_CommonCalc",1);
  //   inputTree->SetBranchStatus("nPV_MultiLepCalc",1);
  inputTree->SetBranchStatus("nTrueInteractions_MultiLepCalc",1);
  inputTree->SetBranchStatus("MCWeight_MultiLepCalc",1);
  inputTree->SetBranchStatus("evtWeightsMC_MultiLepCalc",1);
  inputTree->SetBranchStatus("LHEweightids_MultiLepCalc",1);
  inputTree->SetBranchStatus("LHEweights_MultiLepCalc",1);
  inputTree->SetBranchStatus("NewPDFweights_MultiLepCalc",1);
  inputTree->SetBranchStatus("HTfromHEPUEP_MultiLepCalc",1);
  inputTree->SetBranchStatus("L1NonPrefiringProb_CommonCalc",1);
  inputTree->SetBranchStatus("L1NonPrefiringProbUp_CommonCalc",1);
  inputTree->SetBranchStatus("L1NonPrefiringProbDown_CommonCalc",1);

  //triggers
  inputTree->SetBranchStatus("vsSelMCTriggersHad_MultiLepCalc",1);
  inputTree->SetBranchStatus("viSelMCTriggersHad_MultiLepCalc",1);
  inputTree->SetBranchStatus("vsSelMCTriggersEl_MultiLepCalc",1);
  inputTree->SetBranchStatus("viSelMCTriggersEl_MultiLepCalc",1);
  inputTree->SetBranchStatus("vsSelMCTriggersMu_MultiLepCalc",1);
  inputTree->SetBranchStatus("viSelMCTriggersMu_MultiLepCalc",1);

  inputTree->SetBranchStatus("vsSelTriggersHad_MultiLepCalc",1);
  inputTree->SetBranchStatus("viSelTriggersHad_MultiLepCalc",1);
  inputTree->SetBranchStatus("vsSelTriggersEl_MultiLepCalc",1);
  inputTree->SetBranchStatus("viSelTriggersEl_MultiLepCalc",1);
  inputTree->SetBranchStatus("vsSelTriggersMu_MultiLepCalc",1);
  inputTree->SetBranchStatus("viSelTriggersMu_MultiLepCalc",1);

  //electrons
  inputTree->SetBranchStatus("elCharge_MultiLepCalc",1);
  inputTree->SetBranchStatus("elPt_MultiLepCalc",1);
  inputTree->SetBranchStatus("elEta_MultiLepCalc",1);
  inputTree->SetBranchStatus("elPhi_MultiLepCalc",1);
  inputTree->SetBranchStatus("elEnergy_MultiLepCalc",1);
  inputTree->SetBranchStatus("elMiniIso_MultiLepCalc",1);  
  inputTree->SetBranchStatus("elRelIso_MultiLepCalc",1);
  inputTree->SetBranchStatus("elMother_id_MultiLepCalc",1);
  inputTree->SetBranchStatus("elNumberOfMothers_MultiLepCalc",1);
   
  //muons
  inputTree->SetBranchStatus("muCharge_MultiLepCalc",1);
  inputTree->SetBranchStatus("muPt_MultiLepCalc",1);
  inputTree->SetBranchStatus("muEta_MultiLepCalc",1);
  inputTree->SetBranchStatus("muPhi_MultiLepCalc",1);
  inputTree->SetBranchStatus("muEnergy_MultiLepCalc",1);
  inputTree->SetBranchStatus("muMiniIso_MultiLepCalc",1);
  inputTree->SetBranchStatus("muRelIso_MultiLepCalc",1);
  inputTree->SetBranchStatus("muMother_id_MultiLepCalc",1);
  inputTree->SetBranchStatus("muNumberOfMothers_MultiLepCalc",1);

  //missing et
  inputTree->SetBranchStatus("corr_met_MultiLepCalc",1);
  inputTree->SetBranchStatus("corr_met_phi_MultiLepCalc",1);
  inputTree->SetBranchStatus("corr_metmod_MultiLepCalc",1);
  inputTree->SetBranchStatus("corr_metmod_phi_MultiLepCalc",1);

  //boosted truth
  inputTree->SetBranchStatus("HadronicVHtPt_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtEta_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtPhi_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtEnergy_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtID_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtD0Pt_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtD0Eta_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtD0Phi_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtD0E_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtD1Pt_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtD1Eta_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtD1Phi_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtD1E_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtD2Pt_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtD2Eta_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtD2Phi_JetSubCalc",1);
  inputTree->SetBranchStatus("HadronicVHtD2E_JetSubCalc",1);

  //genParticles
  inputTree->SetBranchStatus("genPt_MultiLepCalc",1);
  inputTree->SetBranchStatus("genEta_MultiLepCalc",1);
  inputTree->SetBranchStatus("genPhi_MultiLepCalc",1);
  inputTree->SetBranchStatus("genEnergy_MultiLepCalc",1);
  inputTree->SetBranchStatus("genStatus_MultiLepCalc",1);
  inputTree->SetBranchStatus("genID_MultiLepCalc",1);
  inputTree->SetBranchStatus("genIndex_MultiLepCalc",1);
  inputTree->SetBranchStatus("genMotherID_MultiLepCalc",1);
  inputTree->SetBranchStatus("genMotherIndex_MultiLepCalc",1);
  inputTree->SetBranchStatus("genJetPt_MultiLepCalc",1);
  inputTree->SetBranchStatus("genJetEta_MultiLepCalc",1);
  inputTree->SetBranchStatus("genJetPhi_MultiLepCalc",1);
  inputTree->SetBranchStatus("genJetEnergy_MultiLepCalc",1);
  inputTree->SetBranchStatus("genJetPtNoClean_MultiLepCalc",1);
  inputTree->SetBranchStatus("genJetEtaNoClean_MultiLepCalc",1);
  inputTree->SetBranchStatus("genJetPhiNoClean_MultiLepCalc",1);
  inputTree->SetBranchStatus("genJetEnergyNoClean_MultiLepCalc",1);

  //JetSubCalc
  inputTree->SetBranchStatus("theJetHFlav_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetPFlav_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetPt_JetSubCalc",1);
  //inputTree->SetBranchStatus("theJetPileupJetId_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetPileupJetTight_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetEta_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetPhi_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetEnergy_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetDeepFlavB_JetSubCalc",1);
  // inputTree->SetBranchStatus("theJetDeepCSVb_JetSubCalc",1);
  // inputTree->SetBranchStatus("theJetDeepCSVbb_JetSubCalc",1);
  // inputTree->SetBranchStatus("theJetDeepCSVc_JetSubCalc",1);
  // inputTree->SetBranchStatus("theJetDeepCSVudsg_JetSubCalc",1);
  inputTree->SetBranchStatus("AK4JetDeepCSVb_MultiLepCalc",1);
  inputTree->SetBranchStatus("AK4JetDeepCSVbb_MultiLepCalc",1);
  inputTree->SetBranchStatus("AK4JetDeepCSVc_MultiLepCalc",1);
  inputTree->SetBranchStatus("AK4JetDeepCSVudsg_MultiLepCalc",1);
  inputTree->SetBranchStatus("AK4JetDeepFlavb_MultiLepCalc", 1);
  inputTree->SetBranchStatus("AK4JetDeepFlavbb_MultiLepCalc", 1);
  inputTree->SetBranchStatus("AK4JetDeepFlavc_MultiLepCalc", 1);
  inputTree->SetBranchStatus("AK4JetDeepFlavg_MultiLepCalc", 1);
  inputTree->SetBranchStatus("AK4JetDeepFlavlepb_MultiLepCalc", 1);
  inputTree->SetBranchStatus("AK4JetDeepFlavuds_MultiLepCalc", 1);

  inputTree->SetBranchStatus("AK4JetBTag_MultiLepCalc",1);
  inputTree->SetBranchStatus("AK4JetBTag_bSFdn_MultiLepCalc",1);
  inputTree->SetBranchStatus("AK4JetBTag_bSFup_MultiLepCalc",1);
  inputTree->SetBranchStatus("AK4JetBTag_lSFdn_MultiLepCalc",1);
  inputTree->SetBranchStatus("AK4JetBTag_lSFup_MultiLepCalc",1);
  inputTree->SetBranchStatus("theJetAK8DoubleB_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetBTag_bSFup_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetBTag_bSFdn_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetBTag_lSFup_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetBTag_lSFdn_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetBTag_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8Pt_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8Eta_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8Phi_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8Mass_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8Energy_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8NjettinessTau1_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8NjettinessTau2_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8NjettinessTau3_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8CHSTau1_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8CHSTau2_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8CHSTau3_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8CHSPrunedMass_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8CHSSoftDropMass_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8SoftDropRaw_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8SoftDropCorr_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8SoftDrop_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8SoftDrop_JMSup_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8SoftDrop_JMSdn_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8SoftDrop_JMRup_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8SoftDrop_JMRdn_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8SDSubjetNDeepCSVL_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8SDSubjetHFlav_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8SDSubjetIndex_JetSubCalc",1);
  inputTree->SetBranchStatus("theJetAK8SDSubjetSize_JetSubCalc",1);
  inputTree->SetBranchStatus("maxProb_JetSubCalc",1);

  //top
  inputTree->SetBranchStatus("ttbarMass_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topEnergy_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topEta_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topMass_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topPhi_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topPt_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topID_TTbarMassCalc",1);

  inputTree->SetBranchStatus("allTopsEnergy_TTbarMassCalc",1);
  inputTree->SetBranchStatus("allTopsEta_TTbarMassCalc",1);
  inputTree->SetBranchStatus("allTopsPhi_TTbarMassCalc",1);
  inputTree->SetBranchStatus("allTopsPt_TTbarMassCalc",1);
  inputTree->SetBranchStatus("allTopsID_TTbarMassCalc",1);
  inputTree->SetBranchStatus("allTopsStatus_TTbarMassCalc",1);

  inputTree->SetBranchStatus("genTtbarIdCategory_TTbarMassCalc",1);
  inputTree->SetBranchStatus("genTtbarId_TTbarMassCalc",1);

  //top W
  inputTree->SetBranchStatus("topWEnergy_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topWEta_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topWPhi_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topWPt_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topWID_TTbarMassCalc",1);

  //top b
  inputTree->SetBranchStatus("topbEnergy_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topbEta_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topbPhi_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topbPt_TTbarMassCalc",1);
  inputTree->SetBranchStatus("topbID_TTbarMassCalc",1);

  //HOTTaggerCalc
  inputTree->SetBranchStatus("topJet1Index_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topJet2Index_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topJet3Index_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topNAK4_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topNtops_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topBestGenEnergy_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topBestGenEta_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topBestGenPhi_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topBestGenPt_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topDRmax_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topDThetaMax_HOTTaggerCalc", 1);
  inputTree->SetBranchStatus("topDThetaMin_HOTTaggerCalc", 1);
  inputTree->SetBranchStatus("topDiscriminator_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topEta_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topMass_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topNconstituents_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topPhi_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topPt_HOTTaggerCalc",1);
  inputTree->SetBranchStatus("topType_HOTTaggerCalc",1);

   
  // ----------------------------------------------------------------------------
  // Create output tree and define branches
  // ----------------------------------------------------------------------------

  // OUTPUT FILE
  outputFile->cd();
  TTree *outputTree = new TTree(outTreeName, outTreeName);


  //Common
  outputTree->Branch("event_CommonCalc",&event_CommonCalc,"event_CommonCalc/L");
  outputTree->Branch("run_CommonCalc",&run_CommonCalc,"run_CommonCalc/I");
  outputTree->Branch("lumi_CommonCalc",&lumi_CommonCalc,"lumi_CommonCalc/I");
  outputTree->Branch("nTrueInteractions_MultiLepCalc",&nTrueInteractions_MultiLepCalc,"nTrueInteractions_MultiLepCalc/I");
  outputTree->Branch("isElectron",&isElectron,"isElectron/I");
  outputTree->Branch("isMuon",&isMuon,"isMuon/I");
  outputTree->Branch("MCPastTriggerX",&MCPastTriggerX,"MCPastTriggerX/I");
  outputTree->Branch("DataPastTriggerX",&DataPastTriggerX,"DataPastTriggerX/I");
  outputTree->Branch("MCPastTrigger",&MCPastTrigger,"MCPastTrigger/I");
  outputTree->Branch("DataPastTrigger",&DataPastTrigger,"DataPastTrigger/I");
  outputTree->Branch("MCLepPastTrigger",&MCLepPastTrigger,"MCLepPastTrigger/I");
  outputTree->Branch("DataLepPastTrigger",&DataLepPastTrigger,"DataLepPastTrigger/I");
  outputTree->Branch("MCHadPastTrigger",&MCHadPastTrigger,"MCHadPastTrigger/I");
  outputTree->Branch("DataHadPastTrigger",&DataHadPastTrigger,"DataHadPastTrigger/I");
  outputTree->Branch("L1NonPrefiringProb_CommonCalc",&L1NonPrefiringProb_CommonCalc,"L1NonPrefiringProb_CommonCalc/D");
  outputTree->Branch("L1NonPrefiringProbUp_CommonCalc",&L1NonPrefiringProbUp_CommonCalc,"L1NonPrefiringProbUp_CommonCalc/D");
  outputTree->Branch("L1NonPrefiringProbDown_CommonCalc",&L1NonPrefiringProbDown_CommonCalc,"L1NonPrefiringProbDown_CommonCalc/D");

  // Triggers for Preselection
  // ---- e-channel
  outputTree->Branch("HLT_Ele15_IsoVVVL_PFHT350",&HLT_Ele15_IsoVVVL_PFHT350,"HLT_Ele15_IsoVVVL_PFHT350/I"); //off in 17B
  outputTree->Branch("HLT_Ele15_IsoVVVL_PFHT400",&HLT_Ele15_IsoVVVL_PFHT400,"HLT_Ele15_IsoVVVL_PFHT400/I"); //off in 17B
  outputTree->Branch("HLT_Ele15_IsoVVVL_PFHT450",&HLT_Ele15_IsoVVVL_PFHT450,"HLT_Ele15_IsoVVVL_PFHT450/I"); //off in 17B
  outputTree->Branch("HLT_Ele28_eta2p1_WPTight_Gsf_HT150",&HLT_Ele28_eta2p1_WPTight_Gsf_HT150,"HLT_Ele28_eta2p1_WPTight_Gsf_HT150/I");
  outputTree->Branch("HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned",&HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned,"HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned/I"); 
  // ----- mu-channel
  outputTree->Branch("HLT_Mu15_IsoVVVL_PFHT350",&HLT_Mu15_IsoVVVL_PFHT350,"HLT_Mu15_IsoVVVL_PFHT350/I");
  outputTree->Branch("HLT_Mu15_IsoVVVL_PFHT400",&HLT_Mu15_IsoVVVL_PFHT400,"HLT_Mu15_IsoVVVL_PFHT400/I");
  outputTree->Branch("HLT_Mu15_IsoVVVL_PFHT450",&HLT_Mu15_IsoVVVL_PFHT450,"HLT_Mu15_IsoVVVL_PFHT450/I");
  outputTree->Branch("HLT_PFHT400_SixJet30_DoubleBTagCSV_p056",&HLT_PFHT400_SixJet30_DoubleBTagCSV_p056,"HLT_PFHT400_SixJet30_DoubleBTagCSV_p056/I");

  // Triggers Used in Lep OR Had Strategy
  outputTree->Branch("HLT_IsoMu24",&HLT_IsoMu24,"HLT_IsoMu24/I");
  outputTree->Branch("HLT_IsoMu24_eta2p1",&HLT_IsoMu24_eta2p1,"HLT_IsoMu24_eta2p1/I");
  outputTree->Branch("HLT_IsoMu27",&HLT_IsoMu27,"HLT_IsoMu27/I");
  outputTree->Branch("HLT_Ele32_WPTight_Gsf",&HLT_Ele32_WPTight_Gsf,"HLT_Ele32_WPTight_Gsf/I");
  outputTree->Branch("HLT_Ele35_WPTight_Gsf",&HLT_Ele35_WPTight_Gsf,"HLT_Ele35_WPTight_Gsf/I");
  outputTree->Branch("HLT_PFHT380_SixJet32_DoubleBTagCSV_p075",&HLT_PFHT380_SixJet32_DoubleBTagCSV_p075,"HLT_PFHT380_SixJet32_DoubleBTagCSV_p075/I");// only data
  outputTree->Branch("HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2",&HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2,"HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2/I"); // only MC
  outputTree->Branch("HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2",&HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2,"HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2/I");
  outputTree->Branch("HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94",&HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94,"HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94/I");


  //weights
  outputTree->Branch("MCWeight_MultiLepCalc",&MCWeight_MultiLepCalc,"MCWeight_MultiLepCalc/D");
  outputTree->Branch("renormWeights",&renormWeights);
  outputTree->Branch("renormPSWeights",&renormPSWeights);
  outputTree->Branch("pdfWeights",&pdfWeights);
  outputTree->Branch("pdfNewWeights",&pdfNewWeights);
  outputTree->Branch("pdfNewNominalWeight",&pdfNewNominalWeight,"pdfNewNominalWeight/F");
  outputTree->Branch("pileupJetIDWeight",&pileupJetIDWeight,"pileupJetIDWeight/F");
  outputTree->Branch("pileupJetIDWeightUp",&pileupJetIDWeightUp,"pileupJetIDWeightUp/F");
  outputTree->Branch("pileupJetIDWeightDown",&pileupJetIDWeightDown,"pileupJetIDWeightDown/F");
  outputTree->Branch("pileupJetIDWeight_tag",&pileupJetIDWeight_tag,"pileupJetIDWeight_tag/F");
  outputTree->Branch("pileupJetIDWeightUp_tag",&pileupJetIDWeightUp_tag,"pileupJetIDWeightUp_tag/F");
  outputTree->Branch("pileupJetIDWeightDown_tag",&pileupJetIDWeightDown_tag,"pileupJetIDWeightDown_tag/F");
  outputTree->Branch("pileupWeight",&pileupWeight,"pileupWeight/F");
  outputTree->Branch("pileupWeightUp",&pileupWeightUp,"pileupWeightUp/F");
  outputTree->Branch("pileupWeightDown",&pileupWeightDown,"pileupWeightDown/F");
  outputTree->Branch("HTSF_Pol",&HTSF_Pol,"HTSF_Pol/F");
  outputTree->Branch("HTSF_PolUp",&HTSF_PolUp,"HTSF_PolUp/F");
  outputTree->Branch("HTSF_PolDn",&HTSF_PolDn,"HTSF_PolDn/F");
  outputTree->Branch("topPtWeight13TeV",&topPtWeight13TeV,"topPtWeight13TeV/F");          
  outputTree->Branch("EGammaGsfSF",&EGammaGsfSF,"EGammaGsfSF/F");
  outputTree->Branch("EGammaGsfSF_up",&EGammaGsfSF_up,"EGammaGsfSF_up/F");
  outputTree->Branch("EGammaGsfSF_down",&EGammaGsfSF_down,"EGammaGsfSF_down/F");
  outputTree->Branch("lepIdSF",&lepIdSF,"lepIdSF/F");
  outputTree->Branch("lepIdSF_up",&lepIdSF_up,"lepIdSF_up/F");
  outputTree->Branch("lepIdSF_down",&lepIdSF_down,"lepIdSF_down/F");
  outputTree->Branch("triggerSF",&triggerSF,"triggerSF/F");
  outputTree->Branch("triggerHadSF",&triggerHadSF,"triggerHadSF/F");
  outputTree->Branch("triggerXSF",&triggerXSF,"triggerXSF/F");
  //outputTree->Branch("triggerVlqXSF",&triggerVlqXSF,"triggerVlqXSF/F");
  outputTree->Branch("isoSF",&isoSF,"isoSF/F");
  outputTree->Branch("btagCSVWeight",&btagCSVWeight,"btagCSVWeight/F");
  outputTree->Branch("btagCSVWeight_HFup",&btagCSVWeight_HFup,"btagCSVWeight_HFup/F");
  outputTree->Branch("btagCSVWeight_HFdn",&btagCSVWeight_HFdn,"btagCSVWeight_HFdn/F");
  outputTree->Branch("btagCSVWeight_LFup",&btagCSVWeight_LFup,"btagCSVWeight_LFup/F");
  outputTree->Branch("btagCSVWeight_LFdn",&btagCSVWeight_LFdn,"btagCSVWeight_LFdn/F");

  outputTree->Branch("btagDeepJetWeight", &btagDeepJetWeight, "btagDeepJetWeight/F");
  outputTree->Branch("btagDeepJetWeight_HFup", &btagDeepJetWeight_HFup, "btagDeepJetWeight_HFup/F");
  outputTree->Branch("btagDeepJetWeight_HFdn", &btagDeepJetWeight_HFdn, "btagDeepJetWeight_HFdn/F");
  outputTree->Branch("btagDeepJetWeight_LFup", &btagDeepJetWeight_LFup, "btagDeepJetWeight_LFup/F");
  outputTree->Branch("btagDeepJetWeight_LFdn", &btagDeepJetWeight_LFdn, "btagDeepJetWeight_LFdn/F");
  outputTree->Branch("btagDeepJetWeight_jesup", &btagDeepJetWeight_jesup, "btagDeepJetWeight_jesup/F");
  outputTree->Branch("btagDeepJetWeight_jesdn", &btagDeepJetWeight_jesdn, "btagDeepJetWeight_jesdn/F");
  outputTree->Branch("btagDeepJetWeight_hfstats1up", &btagDeepJetWeight_hfstats1up, "btagDeepJetWeight_hfstats1up/F");
  outputTree->Branch("btagDeepJetWeight_hfstats1dn", &btagDeepJetWeight_hfstats1dn, "btagDeepJetWeight_hfstats1dn/F");
  outputTree->Branch("btagDeepJetWeight_hfstats2up", &btagDeepJetWeight_hfstats2up, "btagDeepJetWeight_hfstats2up/F");
  outputTree->Branch("btagDeepJetWeight_hfstats2dn", &btagDeepJetWeight_hfstats2dn, "btagDeepJetWeight_hfstats2dn/F");
  outputTree->Branch("btagDeepJetWeight_cferr1up", &btagDeepJetWeight_cferr1up, "btagDeepJetWeight_cferr1up/F");
  outputTree->Branch("btagDeepJetWeight_cferr1dn", &btagDeepJetWeight_cferr1dn, "btagDeepJetWeight_cferr1dn/F");
  outputTree->Branch("btagDeepJetWeight_cferr2up", &btagDeepJetWeight_cferr2up, "btagDeepJetWeight_cferr2up/F");
  outputTree->Branch("btagDeepJetWeight_cferr2dn", &btagDeepJetWeight_cferr2dn, "btagDeepJetWeight_cferr2dn/F");
  outputTree->Branch("btagDeepJetWeight_lfstats1up", &btagDeepJetWeight_lfstats1up, "btagDeepJetWeight_lfstats1up/F");
  outputTree->Branch("btagDeepJetWeight_lfstats1dn", &btagDeepJetWeight_lfstats1dn, "btagDeepJetWeight_lfstats1dn/F"); 
  outputTree->Branch("btagDeepJetWeight_lfstats2up", &btagDeepJetWeight_lfstats2up, "btagDeepJetWeight_lfstats2up/F");
  outputTree->Branch("btagDeepJetWeight_lfstats2dn", &btagDeepJetWeight_lfstats2dn, "btagDeepJetWeight_lfstats2dn/F");

  outputTree->Branch("njetsWeight",&njetsWeight,"njetsWeight/F");
  outputTree->Branch("njetsWeightUp",&njetsWeightUp,"njetsWeightUp/F");
  outputTree->Branch("njetsWeightDown",&njetsWeightDown,"njetsWeightDown/F");
  outputTree->Branch("tthfWeight",&tthfWeight,"tthfWeight/F");
  outputTree->Branch("btagCSVRenormWeight",&btagCSVRenormWeight,"btagCSVRenormWeight/F");

  //ttbar generator
  outputTree->Branch("ttbarMass_TTbarMassCalc",&ttbarMass_TTbarMassCalc,"ttbarMass_TTbarMassCalc/D");
  outputTree->Branch("genTopPt",&genTopPt,"genTopPt/F");
  outputTree->Branch("genAntiTopPt",&genAntiTopPt,"genAntiTopPt/F");
  outputTree->Branch("topEnergy_TTbarMassCalc",&topEnergy_TTbarMassCalc);
  outputTree->Branch("topEta_TTbarMassCalc",&topEta_TTbarMassCalc);
  outputTree->Branch("topMass_TTbarMassCalc",&topMass_TTbarMassCalc);
  outputTree->Branch("topPhi_TTbarMassCalc",&topPhi_TTbarMassCalc);   
  outputTree->Branch("topPt_TTbarMassCalc",&topPt_TTbarMassCalc);      
  outputTree->Branch("topID_TTbarMassCalc",&topID_TTbarMassCalc);
  outputTree->Branch("topWEnergy_TTbarMassCalc",&topWEnergy_TTbarMassCalc);
  outputTree->Branch("topWEta_TTbarMassCalc",&topWEta_TTbarMassCalc);
  outputTree->Branch("topWPhi_TTbarMassCalc",&topWPhi_TTbarMassCalc);
  outputTree->Branch("topWPt_TTbarMassCalc",&topWPt_TTbarMassCalc);   
  outputTree->Branch("topWID_TTbarMassCalc",&topWID_TTbarMassCalc);      
  outputTree->Branch("topbEnergy_TTbarMassCalc",&topbEnergy_TTbarMassCalc);
  outputTree->Branch("topbEta_TTbarMassCalc",&topbEta_TTbarMassCalc);
  outputTree->Branch("topbPhi_TTbarMassCalc",&topbPhi_TTbarMassCalc);
  outputTree->Branch("topbPt_TTbarMassCalc",&topbPt_TTbarMassCalc);   
  outputTree->Branch("topbID_TTbarMassCalc",&topbID_TTbarMassCalc);

  //leptons
  outputTree->Branch("corr_met_MultiLepCalc",&corr_met_MultiLepCalc,"corr_met_MultiLepCalc/D");
  outputTree->Branch("corr_met_phi_MultiLepCalc",&corr_met_phi_MultiLepCalc,"corr_met_phi_MultiLepCalc/D");
  outputTree->Branch("corr_metmod_MultiLepCalc",&corr_metmod_MultiLepCalc,"corr_metmod_MultiLepCalc/D");
  outputTree->Branch("corr_metmod_phi_MultiLepCalc",&corr_metmod_phi_MultiLepCalc,"corr_metmod_phi_MultiLepCalc/D");
  outputTree->Branch("leptonCharge_MultiLepCalc",&leptonCharge_MultiLepCalc,"leptonCharge_MultiLepCalc/F");
  outputTree->Branch("leptonPt_MultiLepCalc",&leptonPt_MultiLepCalc,"leptonPt_MultiLepCalc/F");
  outputTree->Branch("leptonEta_MultiLepCalc",&leptonEta_MultiLepCalc,"leptonEta_MultiLepCalc/F");
  outputTree->Branch("leptonPhi_MultiLepCalc",&leptonPhi_MultiLepCalc,"leptonPhi_MultiLepCalc/F");
  outputTree->Branch("leptonEnergy_MultiLepCalc",&leptonEnergy_MultiLepCalc,"leptonEnergy_MultiLepCalc/F");
  outputTree->Branch("leptonMVAValue_MultiLepCalc",&leptonMVAValue_MultiLepCalc,"leptonMVAValue_MultiLepCalc/F");
  outputTree->Branch("leptonMiniIso_MultiLepCalc",&leptonMiniIso_MultiLepCalc,"leptonMiniIso_MultiLepCalc/F");
  outputTree->Branch("leptonRelIso_MultiLepCalc",&leptonRelIso_MultiLepCalc,"leptonRelIso_MultiLepCalc/F");
  outputTree->Branch("elMother_id_MultiLepCalc",&elMother_id_MultiLepCalc);
  outputTree->Branch("elNumberOfMothers_MultiLepCalc",&elNumberOfMothers_MultiLepCalc);
  outputTree->Branch("muMother_id_MultiLepCalc",&muMother_id_MultiLepCalc);
  outputTree->Branch("muNumberOfMothers_MultiLepCalc",&muNumberOfMothers_MultiLepCalc);
  outputTree->Branch("MT_lepMet",&MT_lepMet,"MT_lepMet/F");
  outputTree->Branch("MT_lepMetmod",&MT_lepMetmod,"MT_lepMetmod/F");
  outputTree->Branch("minDPhi_MetJet",&minDPhi_MetJet,"minDPhi_MetJet/F");

  outputTree->Branch("recLeptonicTopPt",&recLeptonicTopPt,"recLeptonicTopPt/F");
  outputTree->Branch("recLeptonicTopEta",&recLeptonicTopEta,"recLeptonicTopEta/F");
  outputTree->Branch("recLeptonicTopPhi",&recLeptonicTopPhi,"recLeptonicTopPhi/F");
  outputTree->Branch("recLeptonicTopMass",&recLeptonicTopMass,"recLeptonicTopMass/F");
  outputTree->Branch("recLeptonicTopJetIdx", &recLeptonicTopJetIdx, "recLeptonicTopJetIdx/I");

  // AK4
  outputTree->Branch("theJetPt_JetSubCalc",&theJetPt_JetSubCalc);
  outputTree->Branch("theJetEta_JetSubCalc",&theJetEta_JetSubCalc);
  outputTree->Branch("theJetPhi_JetSubCalc",&theJetPhi_JetSubCalc);
  outputTree->Branch("theJetEnergy_JetSubCalc",&theJetEnergy_JetSubCalc);
  outputTree->Branch("theJetDeepFlavB_JetSubCalc", &theJetDeepFlavB_JetSubCalc);
  outputTree->Branch("theJetIndex_JetSubCalc_PtOrdered", &theJetIndex_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetPt_JetSubCalc_PtOrdered",&theJetPt_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetEta_JetSubCalc_PtOrdered",&theJetEta_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetPhi_JetSubCalc_PtOrdered",&theJetPhi_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetEnergy_JetSubCalc_PtOrdered",&theJetEnergy_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetDeepFlavB_JetSubCalc_PtOrdered",&theJetDeepFlavB_JetSubCalc_PtOrdered);
  outputTree->Branch("AK4JetDeepCSVb_MultiLepCalc_PtOrdered",&AK4JetDeepCSVb_MultiLepCalc_PtOrdered);
  outputTree->Branch("AK4JetDeepCSVbb_MultiLepCalc_PtOrdered",&AK4JetDeepCSVbb_MultiLepCalc_PtOrdered);
  outputTree->Branch("AK4JetDeepCSVc_MultiLepCalc_PtOrdered",&AK4JetDeepCSVc_MultiLepCalc_PtOrdered);
  outputTree->Branch("AK4JetDeepCSVudsg_MultiLepCalc_PtOrdered",&AK4JetDeepCSVudsg_MultiLepCalc_PtOrdered);
  outputTree->Branch("AK4JetDeepFlavb_MultiLepCalc_PtOrdered", &AK4JetDeepFlavb_MultiLepCalc_PtOrdered);
  outputTree->Branch("AK4JetDeepFlavbb_MultiLepCalc_PtOrdered", &AK4JetDeepFlavbb_MultiLepCalc_PtOrdered);
  outputTree->Branch("AK4JetDeepFlavc_MultiLepCalc_PtOrdered", &AK4JetDeepFlavc_MultiLepCalc_PtOrdered);
  outputTree->Branch("AK4JetDeepFlavg_MultiLepCalc_PtOrdered", &AK4JetDeepFlavg_MultiLepCalc_PtOrdered);
  outputTree->Branch("AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered", &AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered); 
  outputTree->Branch("AK4JetDeepFlavuds_MultiLepCalc_PtOrdered", &AK4JetDeepFlavuds_MultiLepCalc_PtOrdered);

  outputTree->Branch("AK4JetBTag_MultiLepCalc_PtOrdered",&AK4JetBTag_MultiLepCalc_PtOrdered);
  outputTree->Branch("AK4JetDeepCSVb_MultiLepCalc",&AK4JetDeepCSVb_MultiLepCalc);
  outputTree->Branch("AK4JetDeepCSVbb_MultiLepCalc",&AK4JetDeepCSVbb_MultiLepCalc);
  outputTree->Branch("AK4JetDeepCSVc_MultiLepCalc",&AK4JetDeepCSVc_MultiLepCalc);
  outputTree->Branch("AK4JetDeepCSVudsg_MultiLepCalc",&AK4JetDeepCSVudsg_MultiLepCalc);
  outputTree->Branch("AK4JetDeepFlavb_MultiLepCalc", &AK4JetDeepFlavb_MultiLepCalc);
  outputTree->Branch("AK4JetDeepFlavbb_MultiLepCalc", &AK4JetDeepFlavbb_MultiLepCalc);
  outputTree->Branch("AK4JetDeepFlavc_MultiLepCalc", &AK4JetDeepFlavc_MultiLepCalc);
  outputTree->Branch("AK4JetDeepFlavg_MultiLepCalc", &AK4JetDeepFlavg_MultiLepCalc);
  outputTree->Branch("AK4JetDeepFlavlepb_MultiLepCalc", &AK4JetDeepFlavlepb_MultiLepCalc);
  outputTree->Branch("AK4JetDeepFlavuds_MultiLepCalc", &AK4JetDeepFlavuds_MultiLepCalc);

  outputTree->Branch("theJetHFlav_JetSubCalc_PtOrdered",&theJetHFlav_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetPFlav_JetSubCalc_PtOrdered",&theJetPFlav_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetBTag_JetSubCalc_PtOrdered",&theJetBTag_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetEtaAverage_JetSubCalc",&theJetEtaAverage_JetSubCalc,"theJetEtaAverage_JetSubCalc/F");
  outputTree->Branch("theJetEtaPtWeighted_JetSubCalc",&theJetEtaPtWeighted_JetSubCalc,"theJetEtaPtWeighted_JetSubCalc/F");
  outputTree->Branch("theJetEtaAverageNotBJet_JetSubCalc",&theJetEtaAverageNotBJet_JetSubCalc,"theJetEtaAverageNotBJet_JetSubCalc/F");
  outputTree->Branch("theJetEta_JetNotBJetMaxPt_JetSubCalc",&theJetEta_JetNotBJetMaxPt_JetSubCalc,"theJetEta_JetNotBJetMaxPt_JetSubCalc/F");
  outputTree->Branch("AK4HTpMETpLepPt",&AK4HTpMETpLepPt,"AK4HTpMETpLepPt/F");
  outputTree->Branch("AK4HT",&AK4HT,"AK4HT/F");
  outputTree->Branch("NJets_JetSubCalc",&NJets_JetSubCalc,"NJets_JetSubCalc/I");
  outputTree->Branch("NJetsPU_JetSubCalc",&NJetsPU_JetSubCalc,"NJetsPU_JetSubCalc/I");
  outputTree->Branch("NJetsForward_JetSubCalc",&NJetsForward_JetSubCalc,"NJetsForward_JetSubCalc/I");
  outputTree->Branch("NJetsCSV_MultiLepCalc",&NJetsCSV_MultiLepCalc,"NJetsCSV_MultiLepCalc/I");
  outputTree->Branch("NJetsCSVwithSF_MultiLepCalc",&NJetsCSVwithSF_MultiLepCalc,"NJetsCSVwithSF_MultiLepCalc/I");
  outputTree->Branch("NJetsCSVwithSF_MultiLepCalc_bSFup",&NJetsCSVwithSF_MultiLepCalc_bSFup,"NJetsCSVwithSF_MultiLepCalc_bSFup/I");
  outputTree->Branch("NJetsCSVwithSF_MultiLepCalc_bSFdn",&NJetsCSVwithSF_MultiLepCalc_bSFdn,"NJetsCSVwithSF_MultiLepCalc_bSFdn/I");
  outputTree->Branch("NJetsCSVwithSF_MultiLepCalc_lSFup",&NJetsCSVwithSF_MultiLepCalc_lSFup,"NJetsCSVwithSF_MultiLepCalc_lSFup/I");
  outputTree->Branch("NJetsCSVwithSF_MultiLepCalc_lSFdn",&NJetsCSVwithSF_MultiLepCalc_lSFdn,"NJetsCSVwithSF_MultiLepCalc_lSFdn/I");
  outputTree->Branch("NJetsCSV_JetSubCalc",&NJetsCSV_JetSubCalc,"NJetsCSV_JetSubCalc/I");
  outputTree->Branch("NJetsCSVwithSF_JetSubCalc",&NJetsCSVwithSF_JetSubCalc,"NJetsCSVwithSF_JetSubCalc/I");
  outputTree->Branch("NJetsCSVwithSF_JetSubCalc_bSFup",&NJetsCSVwithSF_JetSubCalc_bSFup,"NJetsCSVwithSF_JetSubCalc_bSFup/I");
  outputTree->Branch("NJetsCSVwithSF_JetSubCalc_bSFdn",&NJetsCSVwithSF_JetSubCalc_bSFdn,"NJetsCSVwithSF_JetSubCalc_bSFdn/I");
  outputTree->Branch("NJetsCSVwithSF_JetSubCalc_lSFup",&NJetsCSVwithSF_JetSubCalc_lSFup,"NJetsCSVwithSF_JetSubCalc_lSFup/I");
  outputTree->Branch("NJetsCSVwithSF_JetSubCalc_lSFdn",&NJetsCSVwithSF_JetSubCalc_lSFdn,"NJetsCSVwithSF_JetSubCalc_lSFdn/I");
  outputTree->Branch("deltaR_lepMinMlb",&deltaR_lepMinMlb,"deltaR_lepMinMlb/F");
  outputTree->Branch("deltaR_lepMinMlb_bSFup",&deltaR_lepMinMlb_bSFup,"deltaR_lepMinMlb_bSFup/F");
  outputTree->Branch("deltaR_lepMinMlb_bSFdn",&deltaR_lepMinMlb_bSFdn,"deltaR_lepMinMlb_bSFdn/F");
  outputTree->Branch("deltaR_lepMinMlb_lSFup",&deltaR_lepMinMlb_lSFup,"deltaR_lepMinMlb_lSFup/F");
  outputTree->Branch("deltaR_lepMinMlb_lSFdn",&deltaR_lepMinMlb_lSFdn,"deltaR_lepMinMlb_lSFdn/F");
  outputTree->Branch("deltaR_lepMinMlj",&deltaR_lepMinMlj,"deltaR_lepMinMlj/F");
  outputTree->Branch("minMleppBjet",&minMleppBjet,"minMleppBjet/F");
  outputTree->Branch("minMleppBjet_bSFup",&minMleppBjet_bSFup,"minMleppBjet_bSFup/F");
  outputTree->Branch("minMleppBjet_bSFdn",&minMleppBjet_bSFdn,"minMleppBjet_bSFdn/F");
  outputTree->Branch("minMleppBjet_lSFup",&minMleppBjet_lSFup,"minMleppBjet_lSFup/F");
  outputTree->Branch("minMleppBjet_lSFdn",&minMleppBjet_lSFdn,"minMleppBjet_lSFdn/F");
  outputTree->Branch("minMleppJet",&minMleppJet,"mixnMleppJet/F");
  outputTree->Branch("minDR_lepJet",&minDR_lepJet,"minDR_lepJet/F");
  outputTree->Branch("ptRel_lepJet",&ptRel_lepJet,"ptRel_lepJet/F");
  outputTree->Branch("minDR_jetJets",&minDR_jetJets);
  outputTree->Branch("deltaR_lepJets",&deltaR_lepJets);
  outputTree->Branch("deltaR_lepBJets",&deltaR_lepBJets);
  outputTree->Branch("deltaR_lepBJets_bSFup",&deltaR_lepBJets_bSFup);
  outputTree->Branch("deltaR_lepBJets_bSFdn",&deltaR_lepBJets_bSFdn);
  outputTree->Branch("deltaR_lepBJets_lSFup",&deltaR_lepBJets_lSFup);
  outputTree->Branch("deltaR_lepBJets_lSFdn",&deltaR_lepBJets_lSFdn);

  // AK4 gen
  outputTree->Branch("genPt_MultiLepCalc",&genPt_MultiLepCalc);
  outputTree->Branch("genEta_MultiLepCalc",&genEta_MultiLepCalc);
  outputTree->Branch("genPhi_MultiLepCalc",&genPhi_MultiLepCalc);
  outputTree->Branch("genEnergy_MultiLepCalc",&genEnergy_MultiLepCalc);
  outputTree->Branch("genStatus_MultiLepCalc",&genStatus_MultiLepCalc);
  outputTree->Branch("genID_MultiLepCalc",&genID_MultiLepCalc);
  outputTree->Branch("genJetPt_MultiLepCalc",&genJetPt_MultiLepCalc);                  
  outputTree->Branch("genJetEta_MultiLepCalc",&genJetEta_MultiLepCalc);                     
  outputTree->Branch("genJetPhi_MultiLepCalc",&genJetPhi_MultiLepCalc);                  
  outputTree->Branch("genJetEnergy_MultiLepCalc",&genJetEnergy_MultiLepCalc);  
  if(isTT){                
  outputTree->Branch("genJetPtNoClean_MultiLepCalc",&genJetPtNoClean_MultiLepCalc);                  
  outputTree->Branch("genJetEtaNoClean_MultiLepCalc",&genJetEtaNoClean_MultiLepCalc);                     
  outputTree->Branch("genJetPhiNoClean_MultiLepCalc",&genJetPhiNoClean_MultiLepCalc);                  
  outputTree->Branch("genJetEnergyNoClean_MultiLepCalc",&genJetEnergyNoClean_MultiLepCalc); 
  }                 
  outputTree->Branch("genIndex_MultiLepCalc",&genIndex_MultiLepCalc);
  outputTree->Branch("genMotherID_MultiLepCalc",&genMotherID_MultiLepCalc);
  outputTree->Branch("genMotherIndex_MultiLepCalc",&genMotherIndex_MultiLepCalc);

  // jet truth
  outputTree->Branch("HadronicVHtID_JetSubCalc",&HadronicVHtID_JetSubCalc);
  outputTree->Branch("HadronicVHtPt_JetSubCalc",&HadronicVHtPt_JetSubCalc);
  outputTree->Branch("HadronicVHtEta_JetSubCalc",&HadronicVHtEta_JetSubCalc);
  outputTree->Branch("HadronicVHtPhi_JetSubCalc",&HadronicVHtPhi_JetSubCalc);
  outputTree->Branch("HadronicVHtEnergy_JetSubCalc",&HadronicVHtEnergy_JetSubCalc);
  outputTree->Branch("theJetAK8Wmatch_JetSubCalc_PtOrdered",&theJetAK8Wmatch_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8Tmatch_JetSubCalc_PtOrdered",&theJetAK8Tmatch_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8Zmatch_JetSubCalc_PtOrdered",&theJetAK8Zmatch_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8Hmatch_JetSubCalc_PtOrdered",&theJetAK8Hmatch_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8MatchedPt_JetSubCalc_PtOrdered",&theJetAK8MatchedPt_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8Truth_JetSubCalc_PtOrdered",&theJetAK8Truth_JetSubCalc_PtOrdered);

  // AK8
  outputTree->Branch("NJetsAK8_JetSubCalc",&NJetsAK8_JetSubCalc,"NJetsAK8_JetSubCalc/I");
  outputTree->Branch("theJetAK8Pt_JetSubCalc_PtOrdered",&theJetAK8Pt_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8Eta_JetSubCalc_PtOrdered",&theJetAK8Eta_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8Phi_JetSubCalc_PtOrdered",&theJetAK8Phi_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8Mass_JetSubCalc_PtOrdered",&theJetAK8Mass_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8Energy_JetSubCalc_PtOrdered",&theJetAK8Energy_JetSubCalc_PtOrdered);
  outputTree->Branch("minDR_leadAK8otherAK8",&minDR_leadAK8otherAK8,"minDR_leadAK8otherAK8/F");
  outputTree->Branch("minDR_lepAK8",&minDR_lepAK8,"minDR_lepAK8/F");
  outputTree->Branch("ptRel_lepAK8",&ptRel_lepAK8,"ptRel_lepAK8/F");
  outputTree->Branch("deltaR_lepAK8s",&deltaR_lepAK8s);

  // mass + tau tagging
  outputTree->Branch("maxProb_JetSubCalc_PtOrdered",&maxProb_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered",&theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered",&theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8SoftDropRaw_JetSubCalc_PtOrdered",&theJetAK8SoftDropRaw_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8SoftDropCorr_JetSubCalc_PtOrdered",&theJetAK8SoftDropCorr_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8DoubleB_JetSubCalc_PtOrdered",&theJetAK8DoubleB_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8SoftDrop_JetSubCalc_PtOrdered",&theJetAK8SoftDrop_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered",&theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered);
  outputTree->Branch("theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered",&theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered);
  outputTree->Branch("theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered",&theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered);
  outputTree->Branch("theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered",&theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered);
  outputTree->Branch("theJetAK8NjettinessTau1_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau1_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8NjettinessTau2_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau2_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8NjettinessTau3_JetSubCalc_PtOrdered",&theJetAK8NjettinessTau3_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8CHSTau1_JetSubCalc_PtOrdered",&theJetAK8CHSTau1_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8CHSTau2_JetSubCalc_PtOrdered",&theJetAK8CHSTau2_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8CHSTau3_JetSubCalc_PtOrdered",&theJetAK8CHSTau3_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered",&theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8SDSubjetSize_JetSubCalc_PtOrdered",&theJetAK8SDSubjetSize_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered",&theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered",&theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered);
  outputTree->Branch("theJetAK8Indx_Wtagged",&theJetAK8Indx_Wtagged);
  outputTree->Branch("NJetsWtagged",&NJetsWtagged,"NJetsWtagged/I");
  outputTree->Branch("NJetsWtagged_shifts",&NJetsWtagged_shifts);
  outputTree->Branch("NJetsTtagged",&NJetsTtagged,"NJetsTtagged/I");
  outputTree->Branch("NJetsTtagged_shifts",&NJetsTtagged_shifts);

  //HOT tagger
  outputTree->Branch("topJet1Index_HOTTaggerCalc",&topJet1Index_HOTTaggerCalc);
  outputTree->Branch("topJet2Index_HOTTaggerCalc",&topJet2Index_HOTTaggerCalc);
  outputTree->Branch("topJet3Index_HOTTaggerCalc",&topJet3Index_HOTTaggerCalc);
  outputTree->Branch("topNAK4_HOTTaggerCalc",&topNAK4_HOTTaggerCalc,"topNAK4_HOTTaggerCalc/I");
  outputTree->Branch("topNtops_HOTTaggerCalc",&topNtops_HOTTaggerCalc,"topNtops_HOTTaggerCalc/I");
  //    outputTree->Branch("topBestGenEnergy_HOTTaggerCalc",&topBestGenEnergy_HOTTaggerCalc);
  //    outputTree->Branch("topBestGenEta_HOTTaggerCalc",&topBestGenEta_HOTTaggerCalc);
  //    outputTree->Branch("topBestGenPhi_HOTTaggerCalc",&topBestGenPhi_HOTTaggerCalc);
  //    outputTree->Branch("topBestGenPt_HOTTaggerCalc",&topBestGenPt_HOTTaggerCalc);
  outputTree->Branch("topDRmax_HOTTaggerCalc",&topDRmax_HOTTaggerCalc);
  outputTree->Branch("topDThetaMax_HOTTaggerCalc",&topDThetaMax_HOTTaggerCalc);
  outputTree->Branch("topDThetaMin_HOTTaggerCalc",&topDThetaMin_HOTTaggerCalc);
  outputTree->Branch("topDiscriminator_HOTTaggerCalc",&topDiscriminator_HOTTaggerCalc);
  outputTree->Branch("topEta_HOTTaggerCalc",&topEta_HOTTaggerCalc);
  outputTree->Branch("topMass_HOTTaggerCalc",&topMass_HOTTaggerCalc);
  outputTree->Branch("topNconstituents_HOTTaggerCalc",&topNconstituents_HOTTaggerCalc);
  outputTree->Branch("topPhi_HOTTaggerCalc",&topPhi_HOTTaggerCalc);
  outputTree->Branch("topPt_HOTTaggerCalc",&topPt_HOTTaggerCalc);
  outputTree->Branch("topType_HOTTaggerCalc",&topType_HOTTaggerCalc);
  outputTree->Branch("NresolvedTops1pFakeNoSF",&NresolvedTops1pFakeNoSF,"NresolvedTops1pFakeNoSF/I");
  outputTree->Branch("NresolvedTops2pFakeNoSF",&NresolvedTops2pFakeNoSF,"NresolvedTops2pFakeNoSF/I");
  outputTree->Branch("NresolvedTops5pFakeNoSF",&NresolvedTops5pFakeNoSF,"NresolvedTops5pFakeNoSF/I");
  outputTree->Branch("NresolvedTops10pFakeNoSF",&NresolvedTops10pFakeNoSF,"NresolvedTops10pFakeNoSF/I");
  outputTree->Branch("NresolvedTops1pFake",&NresolvedTops1pFake,"NresolvedTops1pFake/I");
  outputTree->Branch("NresolvedTops2pFake",&NresolvedTops2pFake,"NresolvedTops2pFake/I");
  outputTree->Branch("NresolvedTops5pFake",&NresolvedTops5pFake,"NresolvedTops5pFake/I");
  outputTree->Branch("NresolvedTops10pFake",&NresolvedTops10pFake,"NresolvedTops10pFake/I");
  outputTree->Branch("NresolvedTops1pFake_shifts",&NresolvedTops1pFake_shifts);
  outputTree->Branch("NresolvedTops2pFake_shifts",&NresolvedTops2pFake_shifts);
  outputTree->Branch("NresolvedTops5pFake_shifts",&NresolvedTops5pFake_shifts);
  outputTree->Branch("NresolvedTops10pFake_shifts",&NresolvedTops10pFake_shifts);

  outputTree->Branch("isHTgt500Njetge9",&isHTgt500Njetge9,"isHTgt500Njetge9/I");
  outputTree->Branch("BJetLeadPt",&BJetLeadPt,"BJetLeadPt/F");
  outputTree->Branch("BJetLeadPt_bSFup",&BJetLeadPt_bSFup,"BJetLeadPt_bSFup/F");
  outputTree->Branch("BJetLeadPt_bSFdn",&BJetLeadPt_bSFdn,"BJetLeadPt_bSFdn/F");
  outputTree->Branch("BJetLeadPt_lSFup",&BJetLeadPt_lSFup,"BJetLeadPt_lSFup/F");
  outputTree->Branch("BJetLeadPt_lSFdn",&BJetLeadPt_lSFdn,"BJetLeadPt_lSFdn/F");
  outputTree->Branch("WJetLeadPt",&WJetLeadPt,"WJetLeadPt/F");
  outputTree->Branch("TJetLeadPt",&TJetLeadPt,"TJetLeadPt/F"); 

  outputTree->Branch("genTtbarIdCategory_TTbarMassCalc",&genTtbarIdCategory_TTbarMassCalc);    
  outputTree->Branch("genTtbarId_TTbarMassCalc",&genTtbarId_TTbarMassCalc);    
  
  // ----------------------------------------------------------------------------
  // Define and initialize objects / cuts / efficiencies
  // ----------------------------------------------------------------------------

  // basic cuts
  float metCut=20;
  float htCut=350;
  int   nAK8jetsCut=0;
  float lepPtCut=20.0;
  float elEtaCut=2.5;
  float muEtaCut=2.4;
  int   njetsCut=4;
  int   nbjetsCut=0;       // events with # of b-tags <nbjetsCut (incl. btag shifts) are removed!
  int   nbjetsCut_shift=2; // syst shift samples aren't used to calculate weights, so can exclude these events for pre-selection 
  float jetPtCut=30;
  float jetEtaCut=2.4;
  float ak8EtaCut=2.4;
  float ak8PtCut=200;

  // counters
  int npass_trigger   = 0;
  int npass_met       = 0;
  int npass_ht        = 0;
  int npass_Njets     = 0;
  int npass_nAK8jets  = 0;
  int npass_lepPt     = 0;
  int npass_ElEta     = 0;
  int npass_MuEta     = 0;
  int npass_all       = 0;
  int Nelectrons      = 0;
  int Nmuons          = 0;
  int NrelIsoFail     = 0;

  // Lorentz vectors
  TLorentzVector jet_lv;
  TLorentzVector kjet_lv;
  TLorentzVector bjet_lv;
  TLorentzVector wjet1_lv;
  TLorentzVector tjet1_lv;
  TLorentzVector lepton_lv;
  TLorentzVector ak8_lv;
  TLorentzVector jetPU_lv;
  TLorentzVector genJetPU_lv;
  TLorentzVector jet_jec;
  TLorentzVector MET_corr_p4;

  // Polynominals for WJets HT scaling
  TF1 *poly2 = new TF1("poly2","max([6],[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x + [5]*x*x*x*x*x)",100,5000);
  poly2->SetParameter(0,    0.998174);  
  poly2->SetParameter(1, 8.40861e-05); 
  poly2->SetParameter(2,-6.63274e-07);
  poly2->SetParameter(3, 4.09272e-10); 
  poly2->SetParameter(4,-9.50233e-14); 
  poly2->SetParameter(5, 7.59648e-18); 
  poly2->SetParameter(6,0.402806);

  TF1 *poly2U = new TF1("poly2U","max([6],[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x + [5]*x*x*x*x*x)",100,5000);
  poly2U->SetParameter(0,    0.998164);  
  poly2U->SetParameter(1, 8.51652e-05); 
  poly2U->SetParameter(2,-6.62919e-07);
  poly2U->SetParameter(3,  4.1205e-10); 
  poly2U->SetParameter(4,-9.57795e-14); 
  poly2U->SetParameter(5, 7.67371e-18); 
  poly2U->SetParameter(6,0.454456);

  TF1 *poly2D = new TF1("poly2D","max([6],[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x + [5]*x*x*x*x*x)",100,5000);
  poly2D->SetParameter(0,    0.998183);  
  poly2D->SetParameter(1, 8.30069e-05); 
  poly2D->SetParameter(2,-6.63629e-07);
  poly2D->SetParameter(3, 4.06495e-10); 
  poly2D->SetParameter(4,-9.42671e-14); 
  poly2D->SetParameter(5, 7.51924e-18); 
  poly2D->SetParameter(6,0.351156);
   

  // medium WP
  float btagWPdjet = 0.3040; 
  float btagWPdcsv = 0.4506; 
  if( Year == "2016" ){
    btagWPdjet = 0.2489; 
    btagWPdcsv = 0.5847; 
  }
  if( Year == "2016APV" ){
     btagWPdjet = 0.2598; 
     btagWPdcsv = 0.6001; 
  }
  if( Year == "2018" ){
    btagWPdjet = 0.2783;
    btagWPdcsv = 0.4168;
  }
  
  
  
  // ----------------------------------------------------------------------------
  // RUN THE EVENT LOOP
  // ----------------------------------------------------------------------------

  cout << "RUN CONFIG: YEAR = " << Year << endl;
  cout << "Era = " << Era << endl;
  cout << "isMC = " << isMC << ", isSig = " << isSig << ", SigMass = " << SigMass << endl;
  cout << "isHad =" << isHad << ", isSE =" << isSE << ", isSM =" << isSM << endl;
  cout << "isTTTT = " << isTTTT << ", isXX = " << isXX << ", isTpTp = " << isTpTp << ", isBpBp = " << isBpBp << endl;
  cout << "For W's: isTT = " << isTT << ", isSTt = " << isSTt << ", isSTtW = " << isSTtW << endl;
  cout << "For jets & PDF: isTOP = " << isTOP << ", isMadgraphBkg = " << isMadgraphBkg << endl;
  cout << "For HOTTagger Efficiencies: isTTV = " << isTTV << ", isTTHbb = " << isTTHbb << ", isTTHnonbb = " << isTTHnonbb << ", isTTTX = " << isTTTX << endl;
  cout << "isTTVV = " << isTTVV << ", isST = " << isST << ", isTTToSemiLeptonHT500Njet9 = " << isTTToSemiLeptonHT500Njet9 << endl;
  cout << "Pileup sample key: " << sample << std::endl;
  cout << "b-tagging working points: " << btagWPdjet << "(DeepJet)" << btagWPdcsv << "(DeepCSV)" << std::endl;
  cout << "isTTincMtt0to700: " << isTTincMtt0to700 << endl;
  cout << "isTTincMtt0to1000: " << isTTincMtt0to1000 << endl;
  cout << "isTTincMtt700to1000: " << isTTincMtt700to1000 << endl;
  cout << "isTTincMtt1000toInf: " << isTTincMtt1000toInf << endl;
  cout << "isTTSemilepIncHT0Njet0: " << isTTSemilepIncHT0Njet0 << endl;
  cout << "isTTSemilepIncHT500Njet9: " << isTTSemilepIncHT500Njet9 << endl;
  cout << "outTTLF: " << outTTLF << endl;
  cout << "outTTCC: " << outTTCC << endl;
  cout << "outTTBB: " << outTTBB << endl;
  cout << "outTT1B: " << outTT1B << endl;
  cout << "outTT2B: " << outTT2B << endl;

  Long64_t nentries = inputTree->GetEntriesFast();

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = inputTree->GetEntry(jentry);   nbytes += nb;
    if (Cut(ientry) != 1) continue;

    if(jentry > 100 && debug == 1) break;

    if(jentry % 1000 == 0 ) std::cout << ">> Completed " << jentry << " out of " << nentries << " events" <<std::endl;

    // ----------------------------------------------------------------------------
    // Filter input file by mass or decay
    // ----------------------------------------------------------------------------

    if(isTTincMtt0to700 && ttbarMass_TTbarMassCalc >= 700.) continue;
    if(isTTincMtt0to1000 && ttbarMass_TTbarMassCalc >= 1000.) continue;
    if(isTTincMtt700to1000 && (ttbarMass_TTbarMassCalc < 700. || ttbarMass_TTbarMassCalc >= 1000.)) continue;
    if(isTTincMtt1000toInf && ttbarMass_TTbarMassCalc < 1000.) continue;

    // ----------------------------------------------------------------------------
    // Assign bool depending on gen level HT and Jet multiplicity for ttbar sample stitching
    // ----------------------------------------------------------------------------
    // HT calculated from jets with pT>30 and |eta|<2.4 > 500 GeV
    // Jet multiplicity (jet pT>30) >= 9
    isHTgt500Njetge9 = 0;
    if(isTT){
      double genHT = 0;
      int Ngenjet = 0;
      for(unsigned int ijet=0; ijet < genJetPtNoClean_MultiLepCalc->size(); ijet++){
        if(genJetPtNoClean_MultiLepCalc->at(ijet) > 30) Ngenjet+=1;
        if(genJetPtNoClean_MultiLepCalc->at(ijet) > 30 && fabs(genJetEtaNoClean_MultiLepCalc->at(ijet)) < 2.4) genHT+=genJetPtNoClean_MultiLepCalc->at(ijet);
      }
      if(genHT>500 && Ngenjet>=9) {isHTgt500Njetge9 = 1;}
    }

    if( isTTSemilepIncHT0Njet0   && isHTgt500Njetge9==1 ) continue;
    if( isTTSemilepIncHT500Njet9 && isHTgt500Njetge9==0 ) continue;
      
//       if( outTTLF && genTtbarIdCategory_TTbarMassCalc->at(0)!=0 ) continue;
//       if( outTTCC && genTtbarIdCategory_TTbarMassCalc->at(0)!=1 ) continue;
//       //if( outTTBB && (genTtbarIdCategory_TTbarMassCalc->at(0)==0 || genTtbarIdCategory_TTbarMassCalc->at(0)==1) ) continue;
//       if( outTT1B && genTtbarIdCategory_TTbarMassCalc->at(0)!=2 ) continue;
//       if( outTTBB && genTtbarIdCategory_TTbarMassCalc->at(0)!=3 ) continue;
//       if( outTT2B && genTtbarIdCategory_TTbarMassCalc->at(0)!=4 ) continue;

// https://twiki.cern.ch/twiki/bin/view/CMSPublic/GenHFHadronMatcher#Event_categorization_example_1
// Each event enters one of the following categories in the given order, i.e. it enters the first category where it fulfills the criterion. The categorisation scheme used is:
// xxx51: tt+b (one additional b jet containing a single b hadron)
// xxx52: tt+2b (one additional b jet containing at least 2 b hadrons)
// xxx53, xxx54, xxx55: tt+bb (at least two additional b jets, independent of the number of b hadrons in each)
// xxx41, xxx42, xxx43, xxx44, xxx45: tt+cc (at least one additional c jet, independent of the number of c hadrons in each)
// xxx00: tt+LF (no additional b/c jets)
// The three digits xxx at the beginning of the ID are not relevant in this classification scheme, each x can take values 0, 1, 2 depending on the number of b jets from top, of b jets from W (of the top decay) and of c jets from W (of the top decay).
    int ttCategory = genTtbarId_TTbarMassCalc->at(0)%100;
    bool ttCategoryExist = false;
    if( (ttCategory>50 && ttCategory<56) || (ttCategory>40 && ttCategory<46) || ttCategory==0 ) ttCategoryExist = true;
    if(isTT && !ttCategoryExist) std::cout<<"WARNING! Event does not have defined ttbar category!!!"<<std::endl;
    if( outTT1B && ttCategory != 51 ) continue;
    if( outTT2B && ttCategory != 52 ) continue;
    if( outTTBB && !(ttCategory>=53 && ttCategory<=55) ) continue;
    if( outTTCC && !(ttCategory>=41 && ttCategory<=45) ) continue;
    if( outTTLF && ttCategory != 0 ) continue;

    // ----------------------------------------------------------------------------
    // Assign as electron or muon event
    // ----------------------------------------------------------------------------
    // **** If we had saveLooseLeps == True in TTsinglelep_MC_cfg.py then this needs work!
    // **** Choose an electron and muon ID for "tight" and find events with only 1 tight el or mu by that definition
    isElectron = 0;
    isMuon = 0;
    if(elPt_MultiLepCalc->size()==0 && muPt_MultiLepCalc->size()==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}
    if(elPt_MultiLepCalc->size()>0 && muPt_MultiLepCalc->size()>0) std::cout << "got el and mu, something wrong" << std::endl;
    if(elPt_MultiLepCalc->size()>1 || muPt_MultiLepCalc->size()>1) std::cout << "got more than one el or mu, something wrong" << std::endl;
    if(elPt_MultiLepCalc->size()>0 && muPt_MultiLepCalc->size()==0) {isElectron = 1; isMuon = 0;}
    if(elPt_MultiLepCalc->size()==0 && muPt_MultiLepCalc->size()>0) {isElectron = 0; isMuon = 1;}
    if(isElectron==0 && isMuon==0){std::cout << "got no leptons, something wrong" << std::endl; continue;}
      
//       if(isMuon == 1) {
//       	if(muRelIso_MultiLepCalc->at(0) > 0.15) {
//       	  NrelIsoFail++;
//       	  //std::cout << "muRelIso > 0.15, skipping the event ..." << std::endl; 
//       	  continue;
//       	  }
//       	}

    if(isSM && isElectron == 1) continue;
    if(isSE && isMuon == 1) continue;

    double leppt = 0;
    double lepeta = 0;
    if(isElectron){leppt = elPt_MultiLepCalc->at(0); lepeta = elEta_MultiLepCalc->at(0);}
    if(isMuon){leppt = muPt_MultiLepCalc->at(0); lepeta = muEta_MultiLepCalc->at(0);}

    // ----------------------------------------------------------------------------
    // Pileup weight calculation
    // ----------------------------------------------------------------------------

    pileupWeight = 1.0;
    pileupWeightUp = 1.0;
    pileupWeightDown = 1.0;

    if(isMC){
      if(nTrueInteractions_MultiLepCalc > 99) nTrueInteractions_MultiLepCalc = 99;
      if(nTrueInteractions_MultiLepCalc < 0) nTrueInteractions_MultiLepCalc = 0;
      hardcodedConditions.GetPileupWeight(nTrueInteractions_MultiLepCalc, &pileupWeight, &pileupWeightUp, &pileupWeightDown, Year);
    }

     
    // PU Jet ID weights are determined later based on AK4 jet properties
    pileupJetIDWeight = 1.0;
    pileupJetIDWeightUp = 1.0;
    pileupJetIDWeightDown = 1.0;
    pileupJetIDWeight_tag = 1.0;
    pileupJetIDWeightUp_tag = 1.0;
    pileupJetIDWeightDown_tag = 1.0;

    btagCSVRenormWeight = 1.0;

    std::string sampleType = "";
    if (isTTTT) sampleType = "tttt";
    else if (outTTLF) sampleType = "ttjj";
    else if (outTTCC) sampleType = "ttcc";
    else if (outTTBB) sampleType = "ttbb";
    else if (outTT1B) sampleType = "tt1b";
    else if (outTT2B) sampleType = "tt2b";
    else if (isST) sampleType = "T";
    else if (isTTV || isTTHbb || isTTHnonbb) sampleType = "TTV";
    else if (isTTTX || isTTVV) sampleType = "TTXY";
    else if (isVV) sampleType = "VV";
    else if (sample.find("WJetsToLNu_") != std::string::npos) sampleType = "WJets";
    else if (sample.find("DYJetsToLL_") != std::string::npos) sampleType = "ZJets";
    else if (sample.find("QCD_") != std::string::npos) sampleType = "qcd";

    // ----------------------------------------------------------------------------
    // ttHF weight calculation
    // ----------------------------------------------------------------------------
    tthfWeight = hardcodedConditions.GetTtHfSF(isTT, outTTBB, outTT2B||outTT1B||outTTCC||outTTLF);

    // ----------------------------------------------------------------------------
    // Generator-level HT correction
    // ----------------------------------------------------------------------------      

    HTSF_Pol = 1;
    HTSF_PolUp = 1;
    HTSF_PolDn = 1;

    if(isMadgraphBkg){
      // Piece-wise splice with a flat line. Uncertainty from upper/lower error bar fits
      HTSF_Pol = poly2->Eval(HTfromHEPUEP_MultiLepCalc);
      HTSF_PolUp = poly2U->Eval(HTfromHEPUEP_MultiLepCalc);
      HTSF_PolDn = poly2D->Eval(HTfromHEPUEP_MultiLepCalc);
    }

    // ----------------------------------------------------------------------------
    // Lepton 4-vectors, calculate MT and electron trigger presel value
    // ----------------------------------------------------------------------------

    // Set lepton 4-vectors
    double lepM;
    double lepphi;
    if (isMuon){ 
      lepM = 0.105658367;
      lepphi = muPhi_MultiLepCalc->at(0);
      lepton_lv.SetPtEtaPhiM(muPt_MultiLepCalc->at(0),muEta_MultiLepCalc->at(0),muPhi_MultiLepCalc->at(0),lepM);
    }
    else{
      lepM = 0.00051099891;
      lepphi = elPhi_MultiLepCalc->at(0);
      lepton_lv.SetPtEtaPhiM(elPt_MultiLepCalc->at(0),elEta_MultiLepCalc->at(0),elPhi_MultiLepCalc->at(0),lepM);
    }      

    // ----------------------------------------------------------------------------
    // Loop over AK4 jets for calculations and pt ordering pair
    // ----------------------------------------------------------------------------

    NJets_JetSubCalc = 0;
    NJetsPU_JetSubCalc = 0;
    NJetsForward_JetSubCalc = 0;
    
    theJetEtaAverage_JetSubCalc = 0;
    theJetEtaPtWeighted_JetSubCalc = 0;
    theJetEtaAverageNotBJet_JetSubCalc = 0;
    theJetEta_JetNotBJetMaxPt_JetSubCalc = 0;

    double jetEtaSum = 0;
    double jetEtaPtWeightedSum = 0;
    double jetEtaSumNotBJet = 0; 
    double NJetsNotBJet = 0;

    AK4HT = 0;
    vector<pair<double,int>> jetptindpair;
    vector<double> jetPUIDsf;
    vector<double> jetPUIDsfUp;
    vector<double> jetPUIDsfDn;
    vector<double> jetPUIDEff;
    vector<int>    jetPUIDTag;
    vector<int>    jetPUIDTag_tag;
    btagCSVWeight = 1.0;
    btagCSVWeight_HFup = 1.0;
    btagCSVWeight_HFdn = 1.0;
    btagCSVWeight_LFup = 1.0;
    btagCSVWeight_LFdn = 1.0;
 
    btagDeepJetWeight = 1.0;
    btagDeepJetWeight_HFup = 1.0;
    btagDeepJetWeight_HFdn = 1.0;
    btagDeepJetWeight_LFup = 1.0;
    btagDeepJetWeight_LFdn = 1.0;
    btagDeepJetWeight_jesup = 1.0;
    btagDeepJetWeight_jesdn = 1.0;
    btagDeepJetWeight_hfstats1up = 1.0;
    btagDeepJetWeight_hfstats1dn = 1.0;
    btagDeepJetWeight_hfstats2up = 1.0;
    btagDeepJetWeight_hfstats2dn = 1.0;
    btagDeepJetWeight_cferr1up = 1.0;
    btagDeepJetWeight_cferr1dn = 1.0;
    btagDeepJetWeight_cferr2up = 1.0;
    btagDeepJetWeight_cferr2dn = 1.0;
    btagDeepJetWeight_lfstats1up = 1.0;
    btagDeepJetWeight_lfstats1dn = 1.0;
    btagDeepJetWeight_lfstats2up = 1.0;
    btagDeepJetWeight_lfstats2dn = 1.0;
    
    double MET_corr_px = corr_met_MultiLepCalc * cos( corr_met_phi_MultiLepCalc );
    double MET_corr_py = corr_met_MultiLepCalc * sin( corr_met_phi_MultiLepCalc );

    // looping through jets now
    if( debug == 1 ) cout << "[DEBUG] Looping through jets" << endl;
    for( unsigned int ijet=0; ijet < theJetPt_JetSubCalc->size(); ijet++){
      // For MC reduced JEC shifts, propagate the uncertainty to each jet before other calculations
      if( isMC && !( Syst == "nominal" || Syst == "JECup" || Syst == "JECdown" || Syst == "JERup" || Syst == "JERdown") ){
        jet_lv.SetPtEtaPhiE( theJetPt_JetSubCalc->at(ijet), theJetEta_JetSubCalc->at(ijet), theJetPhi_JetSubCalc->at(ijet), theJetEnergy_JetSubCalc->at(ijet) );
        jet_jec = jet_lv;
        jecUnc->setJetEta( theJetEta_JetSubCalc->at(ijet) );
        jecUnc->setJetPt( theJetPt_JetSubCalc->at(ijet) );
        double shift = 1.0; // multiplicative factor to the jet energy
        if( shiftUp ){
          try{
            shift = jecUnc->getUncertainty(true);
          }
          catch(...){
            std::cout << "[Warning] Exception thrown by JetCorrectionUncertainty. Possibly trying to correct a jet energy outside range. Skipping correction." << std::endl;
            shift = 0.0;
          }
          shift = 1.0 + shift;
        }
        else{
          try{
            shift = jecUnc->getUncertainty(false);
          }
          catch(...){
            std::cout << "[Warning] Exception thrown by JetCorrectionUncertainty. Possibly trying to correct a jet energy outside range. Skipping correction." << std::endl;
            shift = 0.0;
          }
          shift = 1.0 - shift;
        }
          
        jet_jec = jet_lv * shift;
        // the MET components are treated separately
        MET_corr_px += ( jet_lv - jet_jec ).Px();
        MET_corr_py += ( jet_lv - jet_jec ).Py();
        theJetPt_JetSubCalc->at(ijet) = jet_jec.Pt();
        theJetEta_JetSubCalc->at(ijet) = jet_jec.Eta();
        theJetPhi_JetSubCalc->at(ijet) = jet_jec.Phi();
        theJetEnergy_JetSubCalc->at(ijet) = jet_jec.Energy();
      }
      
      // ----------------------------------------------------------------------------
      // Basic cuts
      // ----------------------------------------------------------------------------

      double ijetPt = theJetPt_JetSubCalc->at(ijet);
      double ijetEta = theJetEta_JetSubCalc->at(ijet);
      
      if( ijetPt < jetPtCut || fabs(ijetEta) > jetEtaCut ) continue;
      
      jetEtaSum+=fabs(ijetEta);
      jetEtaPtWeightedSum+=ijetPt*fabs(ijetEta);

      double ijetPhi = theJetPhi_JetSubCalc->at(ijet);
      double ijetEng = theJetEnergy_JetSubCalc->at(ijet);
      bool ijetPUIDTight = theJetPileupJetTight_JetSubCalc->at(ijet);

      // Jet PU ID event re-weighting information 
      if( debug == 1 ) cout << "[DEBUG] Running pileup SF correction" << endl;
      if(isMC){
        double jetPUIDsf_ = 1.0;
        double jetPUIDsfUp_ = 1.0;
        double jetPUIDsfDn_ = 1.0;
        double jetPUIDEff_ = 1.0;
        hardcodedConditions.GetJetPileupIDSF( ijetPt, ijetEta, &jetPUIDsf_, &jetPUIDsfUp_, &jetPUIDsfDn_, Year );
        hardcodedConditions.GetJetPileupIDEff( ijetPt, ijetEta, &jetPUIDEff_, Year );
        if( ijetPt < 50. ){
          // determine if the reco jet is geometrically matched to a gen jet for PU truth
          jetPU_lv.SetPtEtaPhiM( ijetPt, ijetEta, ijetPhi, ijetEng );
          bool isPU = true;
          for( unsigned int jjet = 0; jjet < genJetPt_MultiLepCalc->size(); jjet++ ){
            genJetPU_lv.SetPtEtaPhiE( genJetPtNoClean_MultiLepCalc->at(jjet), genJetEtaNoClean_MultiLepCalc->at(jjet), genJetPhiNoClean_MultiLepCalc->at(jjet), genJetEnergyNoClean_MultiLepCalc->at(jjet) );
            if( jetPU_lv.DeltaR( genJetPU_lv ) < 0.4 ){
              isPU = false;
              continue; // only need to confirm one reco to gen match
            }
          }
          
          if( isPU == false ){
            if( ijetPUIDTight == false ){ 
              jetPUIDTag.push_back( 0 ); // only apply SF to hard jets that aren't PU tagged
              jetPUIDTag_tag.push_back( 1 ); // in case it's intended to consider real tagged jets as (1-Eff*SF) and not Eff*SF
              jetPUIDsf.push_back( jetPUIDsf_ );
              jetPUIDsfUp.push_back( jetPUIDsfUp_ );
              jetPUIDsfDn.push_back( jetPUIDsfDn_ );
              jetPUIDEff.push_back( jetPUIDEff_ );
            }
          }
        }
      }

      // exclude jets tagged as PU
      if( ijetPUIDTight == true && ijetPt < 50. ){
        NJetsPU_JetSubCalc+=1;
        continue;
      }

      // ----------------------------------------------------------------------------
      // B TAGGING fix
      // ----------------------------------------------------------------------------
      if( debug == 1 ) cout << "[DEBUG] B-tagging fix" << endl;
      if(isMC){
        // First fix b tagging for DeepFlv
        double btagSF = 1.0;
        double btagSFerr = 0.0;
        double btagEff = 1.0;

        // Set the initial tagged/untagged state
        bool istagged = theJetDeepFlavB_JetSubCalc->at(ijet) > btagWPdjet;
        double ijetPt = theJetPt_JetSubCalc->at(ijet);
        double ijetEta= theJetEta_JetSubCalc->at(ijet);
        int ijetHFlv  = theJetHFlav_JetSubCalc->at(ijet);

        // Get btag SF and uncertainty
        hardcodedConditions.GetBtaggingSF(ijetPt, ijetEta, &btagSF, &btagSFerr, "DeepJetMEDIUM", ijetHFlv, Year);
        // Get btag efficiency
        hardcodedConditions.GetBtaggingEff(ijetPt, &btagEff, "DeepJetMEDIUM", ijetHFlv, Year);

        // Apply scale factors
        theJetBTag_JetSubCalc->at(ijet) = applySF(istagged,btagSF,btagEff);
        if(ijetHFlv == 5 || ijetHFlv == 4){
          theJetBTag_bSFup_JetSubCalc->at(ijet) = applySF(istagged,btagSF+btagSFerr,btagEff);
          theJetBTag_bSFdn_JetSubCalc->at(ijet) = applySF(istagged,btagSF-btagSFerr,btagEff);
          theJetBTag_lSFup_JetSubCalc->at(ijet) = applySF(istagged,btagSF,btagEff);
          theJetBTag_lSFdn_JetSubCalc->at(ijet) = applySF(istagged,btagSF,btagEff);
        }
        else{
          theJetBTag_bSFup_JetSubCalc->at(ijet) = applySF(istagged,btagSF,btagEff);
          theJetBTag_bSFdn_JetSubCalc->at(ijet) = applySF(istagged,btagSF,btagEff);
          theJetBTag_lSFup_JetSubCalc->at(ijet) = applySF(istagged,btagSF+btagSFerr,btagEff);
          theJetBTag_lSFdn_JetSubCalc->at(ijet) = applySF(istagged,btagSF-btagSFerr,btagEff);
        }

        // Second fix b tagging for DeepCSV

        // Set the initial tagged/untagged state
        istagged = AK4JetDeepCSVb_MultiLepCalc->at(ijet) + AK4JetDeepCSVbb_MultiLepCalc->at(ijet) > btagWPdcsv;

        // Get btag SF and uncertainty
        hardcodedConditions.GetBtaggingSF(ijetPt, ijetEta, &btagSF, &btagSFerr, "DeepCSVMEDIUM", ijetHFlv, Year);
        // Get btag efficiency
        hardcodedConditions.GetBtaggingEff(ijetPt, &btagEff, "DeepCSVMEDIUM", ijetHFlv, Year);

        // Apply scale factors
        AK4JetBTag_MultiLepCalc->at(ijet) = applySF(istagged,btagSF,btagEff);
        if(ijetHFlv == 5 || ijetHFlv == 4){
          AK4JetBTag_bSFup_MultiLepCalc->at(ijet) = applySF(istagged,btagSF+btagSFerr,btagEff);
          AK4JetBTag_bSFdn_MultiLepCalc->at(ijet) = applySF(istagged,btagSF-btagSFerr,btagEff);
          AK4JetBTag_lSFup_MultiLepCalc->at(ijet) = applySF(istagged,btagSF,btagEff);
          AK4JetBTag_lSFdn_MultiLepCalc->at(ijet) = applySF(istagged,btagSF,btagEff);
        }
        else{
          AK4JetBTag_bSFup_MultiLepCalc->at(ijet) = applySF(istagged,btagSF,btagEff);
          AK4JetBTag_bSFdn_MultiLepCalc->at(ijet) = applySF(istagged,btagSF,btagEff);
          AK4JetBTag_lSFup_MultiLepCalc->at(ijet) = applySF(istagged,btagSF+btagSFerr,btagEff);
          AK4JetBTag_lSFdn_MultiLepCalc->at(ijet) = applySF(istagged,btagSF-btagSFerr,btagEff);
        }

        // csv reshaping
        double csv = AK4JetDeepCSVb_MultiLepCalc->at(ijet) + AK4JetDeepCSVbb_MultiLepCalc->at(ijet);
        double deepjet = AK4JetDeepFlavb_MultiLepCalc->at(ijet)+AK4JetDeepFlavbb_MultiLepCalc->at(ijet)+AK4JetDeepFlavlepb_MultiLepCalc->at(ijet);
        double jptForBtag(ijetPt>1000. ? 999. : ijetPt), jetaForBtag(fabs(ijetEta));
        float csvWgt(1.0), csvWgt_hfup(1.0), csvWgt_hfdn(1.0), csvWgt_lfup(1.0), csvWgt_lfdn(1.0);
        float djetWgt(1.0), djetWgt_hfup(1.0), djetWgt_hfdn(1.0), djetWgt_lfup(1.0), djetWgt_lfdn(1.0), djetWgt_jesup(1.0), djetWgt_jesdn(1.0), 
        djetWgt_hfstats1up(1.0), djetWgt_hfstats1dn(1.0), djetWgt_hfstats2up(1.0), djetWgt_hfstats2dn(1.0), djetWgt_cferr1up(1.0), djetWgt_cferr1dn(1.0), 
        djetWgt_cferr2up(1.0), djetWgt_cferr2dn(1.0), djetWgt_lfstats1up(1.0), djetWgt_lfstats1dn(1.0), djetWgt_lfstats2up(1.0), djetWgt_lfstats2dn(1.0);
        
        // necessary to run through all the combinations to accomodate for the reduced sources in jec but not in btag
        string csv_prefix = "up_";
        auto csv_flav = BTagEntryForLJMet::FLAV_UDSG;
        if( !shiftUp ) csv_prefix = "down_";
        if( abs(ijetHFlv) == 5 ) csv_flav = BTagEntryForLJMet::FLAV_B;
        
        if( debug == 1 ) cout << "[DEBUG] Evaluating deepJet weight with reduced JES source" << endl;

        if( debug == 1 ){
          djetWgt = reader_dj.eval_auto_bounds( "central", csv_flav, jetaForBtag, jptForBtag, deepjet );
        }
        else if( bSyst == "Absolute" ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesAbsolute", csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "Absolute_" + bYear ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesAbsolute_" + bYear, csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "HF" ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesHF", csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "HF_" + bYear ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesHF_" + bYear, csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "BBEC1" ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesBBEC1", csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "BBEC1_" + bYear ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesBBEC1_" + bYear, csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "EC2" ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesEC2", csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "EC2_" + bYear ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesEC2_" + bYear, csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "FlavorQCD" ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesFlavorQCD", csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "FlavorPureQuark" ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesFlavorQCD", csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "FlavorPureGluon" ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesFlavorQCD", csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "FlavorPureCharm" ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesFlavorQCD", csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "FlavorPureBottom" ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesFlavorQCD", csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "RelativeBal" ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesRelativeBal", csv_flav, jetaForBtag, jptForBtag, deepjet );
        else if( bSyst == "RelativeSample_" + bYear ) djetWgt = reader_dj.eval_auto_bounds( csv_prefix + "jesRelativeSample_" + bYear, csv_flav, jetaForBtag, jptForBtag, deepjet );
        else{
          if( jentry == 0 && ijet == 0 ) cout << "[INFO] Defaulting to central deepJet weight for: " << bSyst << endl;
          djetWgt = reader_dj.eval_auto_bounds( "central", csv_flav, jetaForBtag, jptForBtag, deepjet);
        }
        
        if( debug == 1 ) cout << "[DEBUG] Loading btag systematics" << endl;
        if (abs(ijetHFlv) == 5 && debug == 0 ) { 
          csvWgt = reader.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, csv);
          csvWgt_hfup = reader.eval_auto_bounds("up_hf", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, csv);
          csvWgt_hfdn = reader.eval_auto_bounds("down_hf", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, csv);
          csvWgt_lfup = reader.eval_auto_bounds("up_lf", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, csv);
          csvWgt_lfdn = reader.eval_auto_bounds("down_lf", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, csv);           

          djetWgt_hfup = reader_dj.eval_auto_bounds( "up_hf", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_hfdn = reader_dj.eval_auto_bounds( "down_hf", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfup = reader_dj.eval_auto_bounds( "up_lf", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfdn = reader_dj.eval_auto_bounds( "down_lf", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet);
          djetWgt_jesup = reader_dj.eval_auto_bounds( "up_jes", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_jesdn = reader_dj.eval_auto_bounds( "down_jes", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_hfstats1up = reader_dj.eval_auto_bounds( "up_hfstats1", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_hfstats1dn = reader_dj.eval_auto_bounds( "down_hfstats1", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet);
          djetWgt_hfstats2up = reader_dj.eval_auto_bounds( "up_hfstats2", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_hfstats2dn = reader_dj.eval_auto_bounds( "down_hfstats2", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet);
          djetWgt_lfstats1up = reader_dj.eval_auto_bounds( "up_lfstats1", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfstats1dn = reader_dj.eval_auto_bounds( "down_lfstats1", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfstats2up = reader_dj.eval_auto_bounds( "up_lfstats2", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfstats2dn = reader_dj.eval_auto_bounds( "down_lfstats2", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet);
          
          // no cferr for b-tagged jets so use nominal
          djetWgt_cferr1up = reader_dj.eval_auto_bounds( "central", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet);
          djetWgt_cferr1dn = reader_dj.eval_auto_bounds( "central", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet);
          djetWgt_cferr2up = reader_dj.eval_auto_bounds( "central", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet);
          djetWgt_cferr2dn = reader_dj.eval_auto_bounds( "central", BTagEntryForLJMet::FLAV_B, jetaForBtag, jptForBtag, deepjet);     
        }
        else if (abs(ijetHFlv) ==4 && debug == 0 ) {
          csvWgt = reader.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, csv);

          djetWgt = reader_dj.eval_auto_bounds( "central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet);
          
          // no heavy or light flavor systs for c-tagged jets so use nominal
          djetWgt_hfup = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_hfdn = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfup = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfdn = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet);
          djetWgt_jesup = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_jesdn = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_hfstats1up = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_hfstats1dn = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet);
          djetWgt_hfstats2up = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_hfstats2dn = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet);
          djetWgt_lfstats1up = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfstats1dn = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfstats2up = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfstats2dn = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet);

          djetWgt_cferr1up = reader_dj.eval_auto_bounds("up_cferr1", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet);
          djetWgt_cferr1dn = reader_dj.eval_auto_bounds("down_cferr1", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet);
          djetWgt_cferr2up = reader_dj.eval_auto_bounds("up_cferr2", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet);
          djetWgt_cferr2dn = reader_dj.eval_auto_bounds("down_cferr2", BTagEntryForLJMet::FLAV_C, jetaForBtag, jptForBtag, deepjet);
        }
        else if( debug == 0 ){
          csvWgt = reader.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, csv);
          csvWgt_hfup = reader.eval_auto_bounds("up_hf", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, csv);
          csvWgt_hfdn = reader.eval_auto_bounds("down_hf", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, csv);
          csvWgt_lfup = reader.eval_auto_bounds("up_lf", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, csv);
          csvWgt_lfdn = reader.eval_auto_bounds("down_lf", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, csv);
          
          djetWgt_hfup = reader_dj.eval_auto_bounds("up_hf", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet);
          djetWgt_hfdn = reader_dj.eval_auto_bounds("down_hf", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet);
          djetWgt_lfup = reader_dj.eval_auto_bounds("up_lf", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet);
          djetWgt_lfdn = reader_dj.eval_auto_bounds("down_lf", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet);
          djetWgt_jesup      = reader_dj.eval_auto_bounds("up_jes", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_jesdn      = reader_dj.eval_auto_bounds("down_jes", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_hfstats1up = reader_dj.eval_auto_bounds("up_hfstats1", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_hfstats1dn = reader_dj.eval_auto_bounds("down_hfstats1", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet);
          djetWgt_hfstats2up = reader_dj.eval_auto_bounds("up_hfstats2", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_hfstats2dn = reader_dj.eval_auto_bounds("down_hfstats2", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet);
          djetWgt_lfstats1up = reader_dj.eval_auto_bounds("up_lfstats1", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfstats1dn = reader_dj.eval_auto_bounds("down_lfstats1", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfstats2up = reader_dj.eval_auto_bounds("up_lfstats2", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet); 
          djetWgt_lfstats2dn = reader_dj.eval_auto_bounds("down_lfstats2", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet); 

          djetWgt_cferr1up = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet);
          djetWgt_cferr1dn = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet);
          djetWgt_cferr2up = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet);
          djetWgt_cferr2dn = reader_dj.eval_auto_bounds("central", BTagEntryForLJMet::FLAV_UDSG, jetaForBtag, jptForBtag, deepjet);
        }	 

        if (csvWgt != 0) btagCSVWeight *= csvWgt;
        if (csvWgt_hfup != 0) btagCSVWeight_HFup *= csvWgt_hfup;
        if (csvWgt_hfdn != 0) btagCSVWeight_HFdn *= csvWgt_hfdn;
        if (csvWgt_lfup != 0) btagCSVWeight_LFup *= csvWgt_lfup;
        if (csvWgt_lfdn != 0) btagCSVWeight_LFdn *= csvWgt_lfdn;

        if (djetWgt !=0) btagDeepJetWeight *= djetWgt;
        if (djetWgt_hfup != 0) btagDeepJetWeight_HFup *= djetWgt_hfup;
        if (djetWgt_hfdn != 0) btagDeepJetWeight_HFdn *= djetWgt_hfdn;
        if (djetWgt_lfup != 0) btagDeepJetWeight_LFup *= djetWgt_lfup;
        if (djetWgt_lfdn != 0) btagDeepJetWeight_LFdn *= djetWgt_lfdn;
        if (djetWgt_jesup     != 0)   btagDeepJetWeight_jesup       *=  djetWgt_jesup;       
        if (djetWgt_jesdn     != 0)   btagDeepJetWeight_jesdn       *=  djetWgt_jesdn;      
        if (djetWgt_hfstats1up!= 0)   btagDeepJetWeight_hfstats1up  *=  djetWgt_hfstats1up; 
        if (djetWgt_hfstats1dn!= 0)   btagDeepJetWeight_hfstats1dn  *=  djetWgt_hfstats1dn; 
        if (djetWgt_hfstats2up!= 0)   btagDeepJetWeight_hfstats2up  *=  djetWgt_hfstats2up; 
        if (djetWgt_hfstats2dn!= 0)   btagDeepJetWeight_hfstats2dn  *=  djetWgt_hfstats2dn; 
        if (djetWgt_lfstats1up!= 0)   btagDeepJetWeight_lfstats1up  *=  djetWgt_lfstats1up; 
        if (djetWgt_lfstats1dn!= 0)   btagDeepJetWeight_lfstats1dn  *=  djetWgt_lfstats1dn; 
        if (djetWgt_lfstats2up!= 0)   btagDeepJetWeight_lfstats2up  *=  djetWgt_lfstats2up; 
        if (djetWgt_lfstats2dn!= 0)   btagDeepJetWeight_lfstats2dn  *=  djetWgt_lfstats2dn; 

        if (djetWgt_cferr1up!= 0)   btagDeepJetWeight_cferr1up  *=  djetWgt_cferr1up;  
        if (djetWgt_cferr1dn!= 0)   btagDeepJetWeight_cferr1dn  *=  djetWgt_cferr1dn;
        if (djetWgt_cferr2up!= 0)   btagDeepJetWeight_cferr2up  *=  djetWgt_cferr2up;
        if (djetWgt_cferr2dn!= 0)   btagDeepJetWeight_cferr2dn  *=  djetWgt_cferr2dn;   
      }

      else{
      // In Data, AK4JetBTag_MultiLepCalc variable is still using DeepJet,
      // so we need to change it to DeepCSV
        AK4JetBTag_MultiLepCalc->at(ijet) = AK4JetDeepCSVb_MultiLepCalc->at(ijet) + AK4JetDeepCSVbb_MultiLepCalc->at(ijet) > btagWPdcsv;
      }	  	  	
      // ----------------------------------------------------------------------------
      // Counts and pt ordering pair
      // ----------------------------------------------------------------------------

      jetptindpair.push_back(std::make_pair(theJetPt_JetSubCalc->at(ijet),ijet));
      NJets_JetSubCalc+=1;
      if( fabs(ijetEta) > 2.4 ) NJetsForward_JetSubCalc+=1;
      AK4HT += theJetPt_JetSubCalc->at(ijet);
    }
    if( debug == 1 ) cout << "[DEBUG] Done looping through jets" << endl;
    
    theJetEtaAverage_JetSubCalc = jetEtaSum / NJets_JetSubCalc;
    theJetEtaPtWeighted_JetSubCalc = jetEtaPtWeightedSum / AK4HT;
    
    // Correct MET for JEC
    if( debug == 1 ) cout << "[DEBUG] Correcting MET" << endl;
    
    if( isMC && !( Syst == "nominal" || Syst == "JECup" || Syst == "JECdown" || Syst == "JERup" || Syst == "JERdown" ) ) {
      MET_corr_p4.SetPxPyPzE( MET_corr_px, MET_corr_py, 0, sqrt( MET_corr_px * MET_corr_px + MET_corr_py * MET_corr_py ) ); 
      corr_met_MultiLepCalc = MET_corr_p4.Pt();
      corr_met_phi_MultiLepCalc = MET_corr_p4.Phi();
    }
    
    MT_lepMet = sqrt( 2 * leppt * corr_met_MultiLepCalc * (1 - cos( lepphi - corr_met_phi_MultiLepCalc ) ) );

    if(isMC){
      pileupJetIDWeight     = compute_SFWeight( jetPUIDsf, jetPUIDEff, jetPUIDTag );
      pileupJetIDWeightUp   = compute_SFWeight( jetPUIDsfUp, jetPUIDEff, jetPUIDTag );
      pileupJetIDWeightDown = compute_SFWeight( jetPUIDsfDn, jetPUIDEff, jetPUIDTag ); 
      pileupJetIDWeight_tag     = compute_SFWeight( jetPUIDsf, jetPUIDEff, jetPUIDTag_tag );
      pileupJetIDWeightUp_tag   = compute_SFWeight( jetPUIDsfUp, jetPUIDEff, jetPUIDTag_tag );
      pileupJetIDWeightDown_tag = compute_SFWeight( jetPUIDsfDn, jetPUIDEff, jetPUIDTag_tag );
    }

    if (isMC) {
      btagCSVRenormWeight = hardcodedConditions.GetCSVRenormSF(Year, isElectron, NJets_JetSubCalc, sampleType);  
    }	

    // ----------------------------------------------------------------------------
    // nJets weight calculation
    // ----------------------------------------------------------------------------
    njetsWeight = hardcodedConditions.GetNjetSF(NJets_JetSubCalc, Year, "nominal", isTT);
    njetsWeightUp = hardcodedConditions.GetNjetSF(NJets_JetSubCalc, Year, "up", isTT);
    njetsWeightDown = hardcodedConditions.GetNjetSF(NJets_JetSubCalc, Year, "down", isTT);

    //cout << " csv wgt " << btagCSVWeight << endl; // debug -wz


    // ----------------------------------------------------------------------------
    // Assign Lepton scale factor or efficiency weights, save trigger pass/fail
    // ----------------------------------------------------------------------------

    // Triggers Initialised to ZERO
    HLT_Ele15_IsoVVVL_PFHT450 = 0;
    HLT_Ele28_eta2p1_WPTight_Gsf_HT150 = 0;
    HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned = 0;
    HLT_Mu15_IsoVVVL_PFHT450 = 0;
    HLT_PFHT400_SixJet30_DoubleBTagCSV_p056 = 0;
    HLT_Ele32_WPTight_Gsf = 0;
    HLT_Ele35_WPTight_Gsf = 0;
    HLT_IsoMu24 = 0;
    HLT_IsoMu24_eta2p1 = 0;
    HLT_IsoMu27 = 0;
    HLT_PFHT380_SixJet32_DoubleBTagCSV_p075 = 0; // only data for 17B
    HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2 = 0; // only MC for 17B
    HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2 = 0;
    HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94 = 0; // in 2018

    DataPastTriggerX = 0;
    MCPastTriggerX = 0;
    DataPastTrigger = 0;
    MCPastTrigger = 0;
    DataLepPastTrigger = 0;
    MCLepPastTrigger = 0;
    DataHadPastTrigger = 0;
    MCHadPastTrigger = 0;
    EGammaGsfSF = 1.0;
    EGammaGsfSF_up = 1.0;
    EGammaGsfSF_down = 1.0;
    lepIdSF = 1.0;
    lepIdSF_up = 1.0;
    lepIdSF_down = 1.0;
    triggerSF = 1.0;
    triggerHadSF = 1.0;
    triggerXSF = 1.0;
    //triggerVlqXSF = 1.0;
    isoSF = 1.0;
    std::vector<std::string> eltriggersX;
    std::vector<std::string> mutriggersX;
    if( Year == "2016APV" ){ 
      eltriggersX = { "Ele15_IsoVVVL_PFHT400", "Ele32_eta2p1_WPTight_Gsf" };
      mutriggersX = { "Mu15_IsoVVVL_PFHT400", "Mu50", "IsoMu24", "IsoTkMu24" };
    }
    else if( Year == "2016" ){ 
      eltriggersX = { "Ele15_IsoVVVL_PFHT400", "Ele32_eta2p1_WPTight_Gsf" };
      mutriggersX = { "Mu15_IsoVVVL_PFHT400", "Mu50", "IsoMu24", "IsoTkMu24" };
    }
    else if( Year == "2017" ){
      eltriggersX = { "Ele15_IsoVVVL_PFHT450", "Ele35_WPTight_Gsf" };
      mutriggersX = { "Mu15_IsoVVVL_PFHT450", "Mu50", "IsoMu27" };
    }
    else if( Year == "2018" ){
      eltriggersX = { "Ele15_IsoVVVL_PFHT450", "Ele35_WPTight_Gsf"};
      mutriggersX = { "Mu15_IsoVVVL_PFHT450", "Mu50", "IsoMu24" };
    }
    std::string eltrigger;
    std::string mutrigger;
    std::string mutrigger2;
    std::string hadtrigger;
    std::vector<std::string> eltriggers;
    std::vector<std::string> mutriggers;
    std::vector<std::string> hadtriggers;
    std::map<TString, std::vector<std::string>> mctriggers;
    mctriggers = {
      {"17B", {"Ele35_WPTight_Gsf", "IsoMu24_eta2p1" , "PFHT380_SixPFJet32_DoublePFBTagCSV_2p2" }},
      {"17C",{"Ele35_WPTight_Gsf", "IsoMu27" , "PFHT380_SixPFJet32_DoublePFBTagCSV_2p2" }},
      {"17DEF",{"Ele32_WPTight_Gsf", "IsoMu27" , "PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2" }},
      {"18",{"Ele32_WPTight_Gsf", "IsoMu24" , "PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94" }}
    };

    std::map<TString, std::vector<std::string>> datatriggers;
    datatriggers = {
      {"17B", {"Ele35_WPTight_Gsf", "IsoMu24_eta2p1" , "PFHT380_SixJet32_DoubleBTagCSV_p075" }},
      {"17C",{"Ele35_WPTight_Gsf", "IsoMu27" , "PFHT380_SixPFJet32_DoublePFBTagCSV_2p2" }},
      {"17DEF",{"Ele32_WPTight_Gsf", "IsoMu27" , "PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2" }},
      {"18AB", {"Ele32_WPTight_Gsf", "IsoMu24" , "PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2" }},
      {"18CD",{"Ele32_WPTight_Gsf", "IsoMu24" , "PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94" }}
    };
  
    if ( !isMC && !( Year == "2016APV" ) && !( Year == "2016" ) ){
      eltrigger = datatriggers.at(Era).at(0);
      mutrigger = datatriggers.at(Era).at(1); 
      hadtrigger = datatriggers.at(Era).at(2);
    }
    else{
      if ( Year == "2016APV" ){
        eltrigger = "Ele32_eta2p1_WPTight_Gsf";
        mutrigger = "IsoMu24";
        mutrigger2 = "IsoTkMu24";
      }
      if ( Year == "2016" ){
        eltrigger = "Ele32_eta2p1_WPTight_Gsf";
        mutrigger = "IsoMu24";
        mutrigger2 = "IsoTkMu24";
      }
      else if ( Year == "2017" ){
        TRandom3 r;
        //TRandom3 *r = new TRandom3();
        float randLumi = r.Uniform(1.);
        //Double_t randLumi = r->Rndm();
        TString Era17;
        float eraBupperLumi = (4.823/41.557); // probably want to double check these values
        float eraCupperLumi = (14.487/41.557);
        if(randLumi>=0 && randLumi<= eraBupperLumi) Era17="17B";
        else if(randLumi>eraBupperLumi && randLumi<=eraCupperLumi) Era17="17C";
        else Era17="17DEF";
        eltrigger = mctriggers.at(Era17).at(0);
        mutrigger =  mctriggers.at(Era17).at(1);
        hadtrigger = mctriggers.at(Era17).at(2);
      }
      else if ( Year == "2018"){
        eltrigger = mctriggers.at("18").at(0);
        mutrigger =  mctriggers.at("18").at(1);
        hadtrigger = mctriggers.at("18").at(2);
      }
    }

    if(isMC){
      for(unsigned int itrig=0; itrig < vsSelMCTriggersHad_MultiLepCalc->size(); itrig++){
        if(vsSelMCTriggersHad_MultiLepCalc->at(itrig).find(hadtrigger) != std::string::npos && viSelMCTriggersHad_MultiLepCalc->at(itrig) > 0) MCHadPastTrigger = 1;
        if(vsSelMCTriggersHad_MultiLepCalc->at(itrig).find("HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2") != std::string::npos && viSelMCTriggersHad_MultiLepCalc->at(itrig) > 0) HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2 = 1;
        if(vsSelMCTriggersHad_MultiLepCalc->at(itrig).find("HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2") != std::string::npos && viSelMCTriggersHad_MultiLepCalc->at(itrig) > 0) HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2 = 1;
        if(vsSelMCTriggersHad_MultiLepCalc->at(itrig).find("HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94") != std::string::npos && viSelMCTriggersHad_MultiLepCalc->at(itrig) > 0) HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94 = 1;
        if(vsSelMCTriggersHad_MultiLepCalc->at(itrig).find("HLT_PFHT400_SixJet30_DoubleBTagCSV_p056") != std::string::npos && viSelMCTriggersHad_MultiLepCalc->at(itrig) > 0) HLT_PFHT400_SixJet30_DoubleBTagCSV_p056 = 1;
      }
      if(isElectron){
        for(unsigned int itrig=0; itrig < vsSelMCTriggersEl_MultiLepCalc->size(); itrig++){
          if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(eltrigger) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCLepPastTrigger = 1;
          if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele15_IsoVVVL_PFHT350") != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele15_IsoVVVL_PFHT350 = 1;
          if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele15_IsoVVVL_PFHT400") != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele15_IsoVVVL_PFHT400 = 1;
          if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele15_IsoVVVL_PFHT450") != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele15_IsoVVVL_PFHT450 = 1;
          if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele28_eta2p1_WPTight_Gsf_HT150") != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele28_eta2p1_WPTight_Gsf_HT150 = 1;
          if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned") != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned = 1;
          if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele32_WPTight_Gsf") != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele32_WPTight_Gsf = 1;
          if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele35_WPTight_Gsf") != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele35_WPTight_Gsf = 1;
          for(unsigned int jtrig=0; jtrig < eltriggersX.size(); jtrig++){
            if(vsSelMCTriggersEl_MultiLepCalc->at(itrig).find(eltriggersX.at(jtrig)) != std::string::npos && viSelMCTriggersEl_MultiLepCalc->at(itrig) > 0) MCPastTriggerX = 1;
          }
        }
        
        EGammaGsfSF      = hardcodedConditions.GetEGammaGsfSF( leppt, lepeta, Year, "nominal" );
        EGammaGsfSF_up   = hardcodedConditions.GetEGammaGsfSF( leppt, lepeta, Year, "up" );
        EGammaGsfSF_down = hardcodedConditions.GetEGammaGsfSF( leppt, lepeta, Year, "down" );
        lepIdSF      = hardcodedConditions.GetElectronIdSF( leppt, lepeta, Year, "nominal" );
        lepIdSF_up   = hardcodedConditions.GetElectronIdSF( leppt, lepeta, Year, "up" );
        lepIdSF_down = hardcodedConditions.GetElectronIdSF( leppt, lepeta, Year, "down" ); 
        isoSF = hardcodedConditions.GetElectronIsoSF( leppt, lepeta, Year );
        if( Year == "2016APV" || Year == "2016" ){ // there are no centrally maintained 2016preVFP and 2016postVFP UL SF, so use the SF separately
          triggerSF = hardcodedConditions.GetElectronTriggerSF( leppt, lepeta, Year );
          triggerXSF = hardcodedConditions.GetElectronTriggerXSF( leppt, lepeta, Year );
        }
        else if( MCLepPastTrigger == 1 && MCPastTriggerX == 1 ){ // defaults to using the single-object trigger if available
          triggerSF = hardcodedConditions.GetElectronTriggerSF( leppt, lepeta, Year );
          triggerXSF = 1.0; 
        }
        else if( MCLepPastTrigger == 0 && MCPastTriggerX == 1 ){ 
          triggerSF = 1.0;
          triggerXSF = hardcodedConditions.GetElectronTriggerXSF( leppt, lepeta, Year );
        }
        else{ 
          triggerSF = hardcodedConditions.GetElectronTriggerSF(leppt, lepeta, Year);
          triggerXSF = hardcodedConditions.GetElectronTriggerXSF(leppt, lepeta, Year);
        }
        
        //triggerHadSF = hardcodedConditions.GetIsEHadronTriggerSF(NJets_JetSubCalc, AK4HT, Year);
        //triggerVlqXSF = hardcodedConditions.GetElectronTriggerVlqXSF(leppt, lepeta, Year);
      }
      if(isMuon){
        for(unsigned int itrig=0; itrig < vsSelMCTriggersMu_MultiLepCalc->size(); itrig++){
          if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(mutrigger) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCLepPastTrigger = 1;
          if(Year == "2016APV" || Year == "2016" ){
            if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(mutrigger2) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCLepPastTrigger = 1;
          }
          if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find("HLT_IsoMu24") != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) HLT_IsoMu24 = 1;
          if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find("HLT_IsoMu24_eta2p1") != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) HLT_IsoMu24_eta2p1 = 1;
          if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find("HLT_IsoMu27") != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) HLT_IsoMu27 = 1;
          if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find("HLT_Mu15_IsoVVVL_PFHT350") != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) HLT_Mu15_IsoVVVL_PFHT350 = 1;
          if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find("HLT_Mu15_IsoVVVL_PFHT400") != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) HLT_Mu15_IsoVVVL_PFHT400 = 1;
          if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find("HLT_Mu15_IsoVVVL_PFHT450") != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) HLT_Mu15_IsoVVVL_PFHT450 = 1;
          for(unsigned int jtrig=0; jtrig < mutriggersX.size(); jtrig++){
            if(vsSelMCTriggersMu_MultiLepCalc->at(itrig).find(mutriggersX.at(jtrig)) != std::string::npos && viSelMCTriggersMu_MultiLepCalc->at(itrig) > 0) MCPastTriggerX = 1;
          }
        }
        lepIdSF = hardcodedConditions.GetMuonIdSF(leppt, lepeta, Year, "nominal");
        lepIdSF_up = hardcodedConditions.GetMuonIdSF( leppt, lepeta, Year, "up" );
        lepIdSF_down = hardcodedConditions.GetMuonIdSF( leppt, lepeta, Year, "down" );
        isoSF = hardcodedConditions.GetMuonIsoSF(leppt, lepeta, Year);
        
        if( Year == "2016APV" || Year == "2016" ){ // there are no centrally maintained 2016preVFP and 2016postVFP UL SF, so use the SF separately
          triggerSF = hardcodedConditions.GetMuonTriggerSF( leppt, lepeta, Year );
          triggerXSF = hardcodedConditions.GetMuonTriggerXSF( leppt, lepeta, Year );
        }
        if( MCLepPastTrigger == 1 && MCPastTriggerX == 1 ){ // defaults to using the single-object trigger if available
          triggerSF = hardcodedConditions.GetMuonTriggerSF( leppt, lepeta, Year );
          triggerXSF = 1.0; 
        }
        else if( MCLepPastTrigger == 0 && MCPastTriggerX == 1 ){ 
          triggerSF = 1.0;
          triggerXSF = hardcodedConditions.GetMuonTriggerXSF( leppt, lepeta, Year );
        }
        else{ 
          triggerSF = hardcodedConditions.GetMuonTriggerSF(leppt, lepeta, Year);
          triggerXSF = hardcodedConditions.GetMuonTriggerXSF(leppt, lepeta, Year);
        }
        
        //triggerHadSF = hardcodedConditions.GetIsMHadronTriggerSF(NJets_JetSubCalc, AK4HT, Year);
        //triggerVlqXSF = hardcodedConditions.GetMuonTriggerVlqXSF(leppt, lepeta, Year);
      }
      if (MCLepPastTrigger == 1 || MCHadPastTrigger == 1){ // for hadLep strategy
        MCPastTrigger = 1;
      }

      DataPastTrigger = 1;
      DataPastTriggerX = 1;
      DataLepPastTrigger = 1;
      DataHadPastTrigger = 1;
    } 
    else{ //Data triggers check
      for(unsigned int itrig=0; itrig < vsSelTriggersHad_MultiLepCalc->size(); itrig++){
        if(vsSelTriggersHad_MultiLepCalc->at(itrig).find(hadtrigger) != std::string::npos && viSelTriggersHad_MultiLepCalc->at(itrig) > 0) DataHadPastTrigger = 1;
        if(vsSelTriggersHad_MultiLepCalc->at(itrig).find("HLT_PFHT380_SixJet32_DoubleBTagCSV_p075") != std::string::npos && viSelTriggersHad_MultiLepCalc->at(itrig) > 0) HLT_PFHT380_SixJet32_DoubleBTagCSV_p075 = 1;
        if(vsSelTriggersHad_MultiLepCalc->at(itrig).find("HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2") != std::string::npos && viSelTriggersHad_MultiLepCalc->at(itrig) > 0) HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2 = 1;
        if(vsSelTriggersHad_MultiLepCalc->at(itrig).find("HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2") != std::string::npos && viSelTriggersHad_MultiLepCalc->at(itrig) > 0) HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2 = 1;
        if(vsSelTriggersHad_MultiLepCalc->at(itrig).find("HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94") != std::string::npos && viSelTriggersHad_MultiLepCalc->at(itrig) > 0) HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94 = 1;
        if(vsSelTriggersHad_MultiLepCalc->at(itrig).find("HLT_PFHT400_SixJet30_DoubleBTagCSV_p056") != std::string::npos && viSelTriggersHad_MultiLepCalc->at(itrig) > 0) HLT_PFHT400_SixJet30_DoubleBTagCSV_p056 = 1;
      }
      if(isElectron){
        //if(isSE){
        for(unsigned int itrig=0; itrig < vsSelTriggersEl_MultiLepCalc->size(); itrig++){
          if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(eltrigger) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataLepPastTrigger = 1;
          if(vsSelTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele15_IsoVVVL_PFHT350") != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele15_IsoVVVL_PFHT350 = 1;
          if(vsSelTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele15_IsoVVVL_PFHT400") != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele15_IsoVVVL_PFHT400 = 1;
          if(vsSelTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele15_IsoVVVL_PFHT450") != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele15_IsoVVVL_PFHT450 = 1;
          if(vsSelTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele28_eta2p1_WPTight_Gsf_HT150") != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele28_eta2p1_WPTight_Gsf_HT150 = 1;
          if(vsSelTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned") != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned = 1;
          if(vsSelTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele32_WPTight_Gsf") != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele32_WPTight_Gsf = 1;
          if(vsSelTriggersEl_MultiLepCalc->at(itrig).find("HLT_Ele35_WPTight_Gsf") != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) HLT_Ele35_WPTight_Gsf = 1;
          for(unsigned int jtrig=0; jtrig < eltriggersX.size(); jtrig++){
            if(vsSelTriggersEl_MultiLepCalc->at(itrig).find(eltriggersX.at(jtrig)) != std::string::npos && viSelTriggersEl_MultiLepCalc->at(itrig) > 0) DataPastTriggerX = 1;
          }
        }
        if (DataLepPastTrigger == 1 || DataHadPastTrigger == 1){
          DataPastTrigger = 1;
        }
      }
      if(isMuon) {
        for(unsigned int itrig=0; itrig < vsSelTriggersMu_MultiLepCalc->size(); itrig++){
          if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(mutrigger) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataLepPastTrigger = 1;
          if( Year == "2016APV" || Year == "2016" ){
            if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(mutrigger2) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataLepPastTrigger = 1;
          }
          if(vsSelTriggersMu_MultiLepCalc->at(itrig).find("HLT_IsoMu24") != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) HLT_IsoMu24 = 1;
          if(vsSelTriggersMu_MultiLepCalc->at(itrig).find("HLT_IsoMu24_eta2p1") != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) HLT_IsoMu24_eta2p1 = 1;
          if(vsSelTriggersMu_MultiLepCalc->at(itrig).find("HLT_IsoMu27") != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) HLT_IsoMu27 = 1;
          if(vsSelTriggersMu_MultiLepCalc->at(itrig).find("HLT_Mu15_IsoVVVL_PFHT350") != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) HLT_Mu15_IsoVVVL_PFHT350 = 1;
          if(vsSelTriggersMu_MultiLepCalc->at(itrig).find("HLT_Mu15_IsoVVVL_PFHT400") != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) HLT_Mu15_IsoVVVL_PFHT400 = 1;
          if(vsSelTriggersMu_MultiLepCalc->at(itrig).find("HLT_Mu15_IsoVVVL_PFHT450") != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) HLT_Mu15_IsoVVVL_PFHT450 = 1;
          for(unsigned int jtrig=0; jtrig < mutriggersX.size(); jtrig++){
            if(vsSelTriggersMu_MultiLepCalc->at(itrig).find(mutriggersX.at(jtrig)) != std::string::npos && viSelTriggersMu_MultiLepCalc->at(itrig) > 0) DataPastTriggerX = 1;
          }
        }
        if (DataLepPastTrigger == 1 || DataHadPastTrigger == 1){ 
          DataPastTrigger = 1; 
        }
      }
      MCPastTrigger = 1;
      MCPastTriggerX = 1;
      MCLepPastTrigger = 1;
      MCHadPastTrigger = 1;
    }
    if( debug == 1 ) cout << "[DEBUG] Done with triggers" << endl;
  

    if(isMC && MCPastTriggerX) npass_trigger+=1;
    if(!isMC && DataPastTriggerX) npass_trigger+=1;

    // ----------------------------------------------------------------------------
    // Loop over AK8 jets for calculations and pt ordering pair
    // ----------------------------------------------------------------------------

    NJetsAK8_JetSubCalc = 0;
    vector<pair<double,int>> jetak8ptindpair;      
    for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc->size(); ijet++){
      // ----------------------------------------------------------------------------                                  
      // Basic cuts                                                                                                    
      // ----------------------------------------------------------------------------                                  

      if(fabs(theJetAK8Eta_JetSubCalc->at(ijet)) > ak8EtaCut) continue;
      if(theJetAK8Pt_JetSubCalc->at(ijet) < ak8PtCut) continue;
      if(theJetAK8NjettinessTau1_JetSubCalc->at(ijet)==0) continue;
      if(theJetAK8NjettinessTau2_JetSubCalc->at(ijet)==0) continue;

      // ----------------------------------------------------------------------------                                  
      // Counter and pt ordering pair                                                                                  
      // ----------------------------------------------------------------------------                                  

      NJetsAK8_JetSubCalc += 1;
      jetak8ptindpair.push_back(std::make_pair(theJetAK8Pt_JetSubCalc->at(ijet),ijet));

    }

    // ----------------------------------------------------------------------------
    // Apply kinematic cuts
    // ----------------------------------------------------------------------------
                
    int isPastHTCut = 0;
    if(AK4HT >= htCut){npass_ht+=1;isPastHTCut=1;}

    int isPastNAK8JetsCut = 0;
    if(NJetsAK8_JetSubCalc >= nAK8jetsCut){npass_nAK8jets+=1;isPastNAK8JetsCut=1;}

    int isPastMETcut = 0;
    if(corr_met_MultiLepCalc > metCut){npass_met+=1;isPastMETcut=1;}

    int isPastLepPtCut = 0;
    if(leppt > lepPtCut){npass_lepPt+=1;isPastLepPtCut=1;}

    int isPastElEtaCut = 0;
    int isPastMuEtaCut = 0;
    if(isElectron && fabs(lepeta) < elEtaCut){npass_ElEta+=1;isPastElEtaCut=1;}
    if(isMuon && fabs(lepeta) < muEtaCut){npass_MuEta+=1;isPastMuEtaCut=1;}
    if(isElectron){Nelectrons+=1;}
    if(isMuon){Nmuons+=1;}

    int isPastNjetsCut = 0;
    if(NJets_JetSubCalc >= njetsCut){npass_Njets+=1;isPastNjetsCut=1;}

    // ----------------------------------------------------------------------------
    // Skip failing events
    // ----------------------------------------------------------------------------
          
    if(!(isPastMETcut && isPastHTCut && isPastNAK8JetsCut && isPastNjetsCut && isPastLepPtCut && (isPastElEtaCut || isPastMuEtaCut))) continue;
    npass_all+=1;
    if( debug == 1 ) std::cout << "[DEBUG] Event passed" << std::endl;
    if( debug == 1 ) std::cout << "NJetsPU / NJets = " << NJetsPU_JetSubCalc << " / " << NJets_JetSubCalc << std::endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////// ONLY ON SELECTED EVENTS ////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////      

    AK4HTpMETpLepPt = AK4HT + corr_met_MultiLepCalc + leppt; //ST

    // ----------------------------------------------------------------------------
    // Combine lepton variables into one set
    // ----------------------------------------------------------------------------

    if(isElectron){
      leptonPt_MultiLepCalc = leppt;
      leptonEta_MultiLepCalc = lepeta;
      leptonCharge_MultiLepCalc = elCharge_MultiLepCalc->at(0);
      leptonPhi_MultiLepCalc = elPhi_MultiLepCalc->at(0);
      leptonEnergy_MultiLepCalc = elEnergy_MultiLepCalc->at(0);
      leptonMiniIso_MultiLepCalc = elMiniIso_MultiLepCalc->at(0);
      leptonRelIso_MultiLepCalc = elRelIso_MultiLepCalc->at(0);
      leptonMVAValue_MultiLepCalc = -99.9; //elMVAValue_MultiLepCalc->at(0);
    }
    if(isMuon){
      if( debug == 1 ) cout << "[DEBUG] Lepton is muon" << endl;
      leptonPt_MultiLepCalc = leppt;
      leptonEta_MultiLepCalc = lepeta;
      leptonCharge_MultiLepCalc = muCharge_MultiLepCalc->at(0);
      leptonPhi_MultiLepCalc = muPhi_MultiLepCalc->at(0);
      leptonEnergy_MultiLepCalc = muEnergy_MultiLepCalc->at(0);
      leptonMiniIso_MultiLepCalc = muMiniIso_MultiLepCalc->at(0);
      leptonRelIso_MultiLepCalc = muRelIso_MultiLepCalc->at(0);
      leptonMVAValue_MultiLepCalc = -99.9;
    }
     
    // ----------------------------------------------------------------------------
    // Apply pt ordering to AK4 vectors
    // ----------------------------------------------------------------------------

    std::sort(jetptindpair.begin(), jetptindpair.end(), comparepair);
    theJetIndex_JetSubCalc_PtOrdered.clear();
    theJetPt_JetSubCalc_PtOrdered.clear();
    theJetEta_JetSubCalc_PtOrdered.clear();
    theJetPhi_JetSubCalc_PtOrdered.clear();
    theJetEnergy_JetSubCalc_PtOrdered.clear();
    theJetDeepFlavB_JetSubCalc_PtOrdered.clear();
    AK4JetDeepCSVb_MultiLepCalc_PtOrdered.clear();
    AK4JetDeepCSVbb_MultiLepCalc_PtOrdered.clear();
    AK4JetDeepCSVc_MultiLepCalc_PtOrdered.clear();
    AK4JetDeepCSVudsg_MultiLepCalc_PtOrdered.clear();
    AK4JetDeepFlavb_MultiLepCalc_PtOrdered.clear();
    AK4JetDeepFlavbb_MultiLepCalc_PtOrdered.clear();
    AK4JetDeepFlavc_MultiLepCalc_PtOrdered.clear();
    AK4JetDeepFlavg_MultiLepCalc_PtOrdered.clear();
    AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered.clear();
    AK4JetDeepFlavuds_MultiLepCalc_PtOrdered.clear();

    theJetHFlav_JetSubCalc_PtOrdered.clear();
    theJetPFlav_JetSubCalc_PtOrdered.clear();
    theJetBTag_JetSubCalc_PtOrdered.clear();
    theJetBTag_bSFup_JetSubCalc_PtOrdered.clear();
    theJetBTag_bSFdn_JetSubCalc_PtOrdered.clear();
    theJetBTag_lSFup_JetSubCalc_PtOrdered.clear();
    theJetBTag_lSFdn_JetSubCalc_PtOrdered.clear();
    AK4JetBTag_MultiLepCalc_PtOrdered.clear();
    AK4JetBTag_bSFup_MultiLepCalc_PtOrdered.clear();
    AK4JetBTag_bSFdn_MultiLepCalc_PtOrdered.clear();
    AK4JetBTag_lSFup_MultiLepCalc_PtOrdered.clear();
    AK4JetBTag_lSFdn_MultiLepCalc_PtOrdered.clear();

    if( debug == 1 ) cout << "[DEBUG] Apply pT ordering to AK4 vectors" << endl;
    for(unsigned int ijet=0; ijet < jetptindpair.size(); ijet++){
      
      theJetIndex_JetSubCalc_PtOrdered.push_back(jetptindpair[ijet].second);
      theJetPt_JetSubCalc_PtOrdered.push_back(theJetPt_JetSubCalc->at(jetptindpair[ijet].second));
      theJetEta_JetSubCalc_PtOrdered.push_back(theJetEta_JetSubCalc->at(jetptindpair[ijet].second));
      theJetPhi_JetSubCalc_PtOrdered.push_back(theJetPhi_JetSubCalc->at(jetptindpair[ijet].second));
      theJetEnergy_JetSubCalc_PtOrdered.push_back(theJetEnergy_JetSubCalc->at(jetptindpair[ijet].second));
      theJetDeepFlavB_JetSubCalc_PtOrdered.push_back(theJetDeepFlavB_JetSubCalc->at(jetptindpair[ijet].second));
      AK4JetDeepCSVb_MultiLepCalc_PtOrdered.push_back(AK4JetDeepCSVb_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetDeepCSVbb_MultiLepCalc_PtOrdered.push_back(AK4JetDeepCSVbb_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetDeepCSVc_MultiLepCalc_PtOrdered.push_back(AK4JetDeepCSVc_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetDeepCSVudsg_MultiLepCalc_PtOrdered.push_back(AK4JetDeepCSVudsg_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetDeepFlavb_MultiLepCalc_PtOrdered.push_back(AK4JetDeepFlavb_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetDeepFlavbb_MultiLepCalc_PtOrdered.push_back(AK4JetDeepFlavbb_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetDeepFlavc_MultiLepCalc_PtOrdered.push_back(AK4JetDeepFlavc_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetDeepFlavg_MultiLepCalc_PtOrdered.push_back(AK4JetDeepFlavg_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered.push_back(AK4JetDeepFlavlepb_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetDeepFlavuds_MultiLepCalc_PtOrdered.push_back(AK4JetDeepFlavuds_MultiLepCalc->at(jetptindpair[ijet].second));

      theJetHFlav_JetSubCalc_PtOrdered.push_back(theJetHFlav_JetSubCalc->at(jetptindpair[ijet].second));
      theJetPFlav_JetSubCalc_PtOrdered.push_back(theJetPFlav_JetSubCalc->at(jetptindpair[ijet].second));
      theJetBTag_JetSubCalc_PtOrdered.push_back(theJetBTag_JetSubCalc->at(jetptindpair[ijet].second));
      theJetBTag_bSFup_JetSubCalc_PtOrdered.push_back(theJetBTag_bSFup_JetSubCalc->at(jetptindpair[ijet].second));
      theJetBTag_bSFdn_JetSubCalc_PtOrdered.push_back(theJetBTag_bSFdn_JetSubCalc->at(jetptindpair[ijet].second));
      theJetBTag_lSFup_JetSubCalc_PtOrdered.push_back(theJetBTag_lSFup_JetSubCalc->at(jetptindpair[ijet].second));
      theJetBTag_lSFdn_JetSubCalc_PtOrdered.push_back(theJetBTag_lSFdn_JetSubCalc->at(jetptindpair[ijet].second));
      AK4JetBTag_MultiLepCalc_PtOrdered.push_back(AK4JetBTag_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetBTag_bSFup_MultiLepCalc_PtOrdered.push_back(AK4JetBTag_bSFup_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetBTag_bSFdn_MultiLepCalc_PtOrdered.push_back(AK4JetBTag_bSFdn_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetBTag_lSFup_MultiLepCalc_PtOrdered.push_back(AK4JetBTag_lSFup_MultiLepCalc->at(jetptindpair[ijet].second));
      AK4JetBTag_lSFdn_MultiLepCalc_PtOrdered.push_back(AK4JetBTag_lSFdn_MultiLepCalc->at(jetptindpair[ijet].second));
    }

    // ----------------------------------------------------------------------------
    // AK4 Jet - lepton associations
    // ----------------------------------------------------------------------------

    BJetLeadPt = -99;
    BJetLeadPt_bSFup = -99;
    BJetLeadPt_bSFdn = -99;
    BJetLeadPt_lSFup = -99;
    BJetLeadPt_lSFdn = -99;
    minMleppBjet = 1e8;
    minMleppBjet_bSFup = 1e8;
    minMleppBjet_bSFdn = 1e8;
    minMleppBjet_lSFup = 1e8;
    minMleppBjet_lSFdn = 1e8;
    minMleppJet = 1e8;      
    minDPhi_MetJet = 1e8;
    minDR_lepJet = 1e8;
    ptRel_lepJet = -99;
    minDR_jetJets.clear();
    deltaR_lepJets.clear();
    deltaR_lepBJets.clear();
    deltaR_lepBJets_bSFup.clear();
    deltaR_lepBJets_bSFdn.clear();
    deltaR_lepBJets_lSFup.clear();
    deltaR_lepBJets_lSFdn.clear();
    deltaR_lepMinMlb = 1e8;
    deltaR_lepMinMlb_bSFup = 1e8;
    deltaR_lepMinMlb_bSFdn = 1e8;
    deltaR_lepMinMlb_lSFup = 1e8;
    deltaR_lepMinMlb_lSFdn = 1e8;
    deltaR_lepMinMlj = 1e8;
    NJetsCSV_MultiLepCalc = 0;
    NJetsCSVwithSF_MultiLepCalc = 0;
    NJetsCSVwithSF_MultiLepCalc_bSFup = 0;
    NJetsCSVwithSF_MultiLepCalc_bSFdn = 0;
    NJetsCSVwithSF_MultiLepCalc_lSFup = 0;
    NJetsCSVwithSF_MultiLepCalc_lSFdn = 0;
    NJetsCSV_JetSubCalc = 0;
    NJetsCSVwithSF_JetSubCalc = 0;
    NJetsCSVwithSF_JetSubCalc_bSFup = 0;
    NJetsCSVwithSF_JetSubCalc_bSFdn = 0;
    NJetsCSVwithSF_JetSubCalc_lSFup = 0;
    NJetsCSVwithSF_JetSubCalc_lSFdn = 0;
    TLorentzVector nu;
    nu.SetPtEtaPhiE(corr_met_MultiLepCalc,0,corr_met_phi_MultiLepCalc,corr_met_MultiLepCalc);
        
  //       for(unsigned int ijet=0; ijet < AK4JetDeepCSVb_MultiLepCalc->size(); ijet++){
  //       	if(AK4JetDeepCSVb_MultiLepCalc->at(ijet) + AK4JetDeepCSVbb_MultiLepCalc->at(ijet) > btagWPdcsv){
  //       		NJetsCSV_MultiLepCalc += 1;
  //       		}
  //       	}
    if( debug == 1 ){ cout << "[DEBUG] PtOrdered Begin" << endl; }

    double maxJetPt_NotBJet = 0;

    for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
      jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(ijet),theJetEta_JetSubCalc_PtOrdered.at(ijet),theJetPhi_JetSubCalc_PtOrdered.at(ijet),theJetEnergy_JetSubCalc_PtOrdered.at(ijet));
      if((lepton_lv + jet_lv).M() < minMleppJet) {
        minMleppJet = fabs((lepton_lv + jet_lv).M());
        deltaR_lepMinMlj = jet_lv.DeltaR(lepton_lv);
      }

      deltaR_lepJets.push_back(lepton_lv.DeltaR(jet_lv));

      if(AK4JetDeepCSVb_MultiLepCalc_PtOrdered.at(ijet) + AK4JetDeepCSVbb_MultiLepCalc_PtOrdered.at(ijet) > btagWPdcsv){
        NJetsCSV_MultiLepCalc += 1;
      }
      if(AK4JetBTag_MultiLepCalc_PtOrdered.at(ijet) == 1){
        NJetsCSVwithSF_MultiLepCalc += 1;
        if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt) BJetLeadPt = theJetPt_JetSubCalc_PtOrdered.at(ijet);
        deltaR_lepBJets.push_back(lepton_lv.DeltaR(jet_lv));

        if((lepton_lv + jet_lv).M() < minMleppBjet) {
          minMleppBjet = fabs( (lepton_lv + jet_lv).M() );
          deltaR_lepMinMlb = jet_lv.DeltaR(lepton_lv);
        }
      }
      if(AK4JetBTag_bSFup_MultiLepCalc_PtOrdered.at(ijet) == 1){
        NJetsCSVwithSF_MultiLepCalc_bSFup += 1;
        if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt_bSFup) BJetLeadPt_bSFup = theJetPt_JetSubCalc_PtOrdered.at(ijet);
        deltaR_lepBJets_bSFup.push_back(lepton_lv.DeltaR(jet_lv));

        if((lepton_lv + jet_lv).M() < minMleppBjet_bSFup) {
          minMleppBjet_bSFup = fabs( (lepton_lv + jet_lv).M() );
          deltaR_lepMinMlb_bSFup = jet_lv.DeltaR(lepton_lv);
        }
      }
      if(AK4JetBTag_bSFdn_MultiLepCalc_PtOrdered.at(ijet) == 1){
        NJetsCSVwithSF_MultiLepCalc_bSFdn += 1;
        if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt_bSFdn) BJetLeadPt_bSFdn = theJetPt_JetSubCalc_PtOrdered.at(ijet);
        deltaR_lepBJets_bSFdn.push_back(lepton_lv.DeltaR(jet_lv));

        if((lepton_lv + jet_lv).M() < minMleppBjet_bSFdn) {
          minMleppBjet_bSFdn = fabs( (lepton_lv + jet_lv).M() );
          deltaR_lepMinMlb_bSFdn = jet_lv.DeltaR(lepton_lv);
        }
      }
      if(AK4JetBTag_lSFup_MultiLepCalc_PtOrdered.at(ijet) == 1){
        NJetsCSVwithSF_MultiLepCalc_lSFup += 1;
        if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt_lSFup) BJetLeadPt_lSFup = theJetPt_JetSubCalc_PtOrdered.at(ijet);
        deltaR_lepBJets_lSFup.push_back(lepton_lv.DeltaR(jet_lv));

        if((lepton_lv + jet_lv).M() < minMleppBjet_lSFup) {
          minMleppBjet_lSFup = fabs( (lepton_lv + jet_lv).M() );
          deltaR_lepMinMlb_lSFup = jet_lv.DeltaR(lepton_lv);
        }
      }
      if(AK4JetBTag_lSFdn_MultiLepCalc_PtOrdered.at(ijet) == 1){
        NJetsCSVwithSF_MultiLepCalc_lSFdn += 1;
        if(theJetPt_JetSubCalc_PtOrdered.at(ijet) > BJetLeadPt_lSFdn) BJetLeadPt_lSFdn = theJetPt_JetSubCalc_PtOrdered.at(ijet);
        deltaR_lepBJets_lSFdn.push_back(lepton_lv.DeltaR(jet_lv));

        if((lepton_lv + jet_lv).M() < minMleppBjet_lSFdn) {
          minMleppBjet_lSFdn = fabs( (lepton_lv + jet_lv).M() );
          deltaR_lepMinMlb_lSFdn = jet_lv.DeltaR(lepton_lv);
        }
      }

      if(theJetDeepFlavB_JetSubCalc_PtOrdered.at(ijet) > btagWPdjet){
        NJetsCSV_JetSubCalc += 1;
      }
      else{
        jetEtaSumNotBJet += fabs(theJetEta_JetSubCalc_PtOrdered.at(ijet));
        NJetsNotBJet += 1;
        if( theJetPt_JetSubCalc_PtOrdered.at(ijet) > maxJetPt_NotBJet ){
          theJetEta_JetNotBJetMaxPt_JetSubCalc = theJetEta_JetSubCalc_PtOrdered.at(ijet);
        }
      }
      if(theJetBTag_JetSubCalc_PtOrdered.at(ijet) == 1){
        NJetsCSVwithSF_JetSubCalc += 1;	  
      }
      if(theJetBTag_bSFup_JetSubCalc_PtOrdered.at(ijet) == 1){
        NJetsCSVwithSF_JetSubCalc_bSFup += 1;
      }
      if(theJetBTag_bSFdn_JetSubCalc_PtOrdered.at(ijet) == 1){
        NJetsCSVwithSF_JetSubCalc_bSFdn += 1;
      }
      if(theJetBTag_lSFup_JetSubCalc_PtOrdered.at(ijet) == 1){
        NJetsCSVwithSF_JetSubCalc_lSFup += 1;
      }
      if(theJetBTag_lSFdn_JetSubCalc_PtOrdered.at(ijet) == 1){
        NJetsCSVwithSF_JetSubCalc_lSFdn += 1;
      }

      if(jet_lv.DeltaPhi(nu) < minDPhi_MetJet) minDPhi_MetJet = jet_lv.DeltaPhi(nu);	  

      if(deltaR_lepJets[ijet] < minDR_lepJet) {
        minDR_lepJet = deltaR_lepJets[ijet];
        ptRel_lepJet = lepton_lv.P()*(jet_lv.Vect().Cross(lepton_lv.Vect()).Mag()/jet_lv.P()/lepton_lv.P());
      }

      minDR_jetJet = 1e8;
      for(unsigned int kjet=0; kjet < theJetPt_JetSubCalc_PtOrdered.size(); kjet++){
        if(ijet == kjet){continue;}
        kjet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(kjet),theJetEta_JetSubCalc_PtOrdered.at(kjet),theJetPhi_JetSubCalc_PtOrdered.at(kjet),theJetEnergy_JetSubCalc_PtOrdered.at(kjet));
        deltaR_jetJets = jet_lv.DeltaR(kjet_lv);
        if(deltaR_jetJets < minDR_jetJet) {
          minDR_jetJet = deltaR_jetJets;
        }
      }
      minDR_jetJets.push_back(minDR_jetJet);

    }
    
    if( NJetsNotBJet > 0 ){
      theJetEtaAverageNotBJet_JetSubCalc = jetEtaSumNotBJet / NJetsNotBJet;
    } else {
      theJetEtaAverageNotBJet_JetSubCalc = -1; // reports absolute value, so negative indicates non-existence
    }

    // ----------------------------------------------------------------------------
    // Skip events that fail # of btag requirement
    // ----------------------------------------------------------------------------  
    int nbjetsCut_apply = nbjetsCut;
    if( bSyst != "nominal" ){
      nbjetsCut_apply = nbjetsCut_shift;
    }
    if(NJetsCSVwithSF_MultiLepCalc<nbjetsCut_apply && 
       NJetsCSVwithSF_MultiLepCalc_bSFup<nbjetsCut_apply && 
       NJetsCSVwithSF_MultiLepCalc_bSFdn<nbjetsCut_apply && 
       NJetsCSVwithSF_MultiLepCalc_lSFup<nbjetsCut_apply && 
       NJetsCSVwithSF_MultiLepCalc_lSFdn<nbjetsCut_apply && 
       NJetsCSVwithSF_JetSubCalc<nbjetsCut_apply && 
       NJetsCSVwithSF_JetSubCalc_bSFup<nbjetsCut_apply && 
       NJetsCSVwithSF_JetSubCalc_bSFdn<nbjetsCut_apply && 
       NJetsCSVwithSF_JetSubCalc_lSFup<nbjetsCut_apply && 
       NJetsCSVwithSF_JetSubCalc_lSFdn<nbjetsCut_apply) continue;

    // ----------------------------------------------------------------------------
    // 13TeV Top pT reweighting -- TTbarMassCalc top vectors are the wrong tops....
    // ----------------------------------------------------------------------------
    
    genTopPt = -999;
    genAntiTopPt = -999;
    topPtWeight13TeV = 1.0;
        
    if( debug == 1 ){ cout << "[DEBUG] Top pT Reweighting" << endl; }

    if(isTT){
      int top1index = -1;
      int top2index = -1;
      for(unsigned int itop=0; itop < allTopsStatus_TTbarMassCalc->size(); itop++){
        if(allTopsStatus_TTbarMassCalc->at(itop) != 62) continue;
        if(top1index < 0){
          top1index = itop;
          continue;
        }
        if(top2index < 0){
          top2index = itop;
          continue;
        }
      }

      float SFtop1 = TMath::Exp(0.0615-0.0005*allTopsPt_TTbarMassCalc->at(top1index));
      float SFtop2 = TMath::Exp(0.0615-0.0005*allTopsPt_TTbarMassCalc->at(top2index));
      topPtWeight13TeV = TMath::Sqrt(SFtop1*SFtop2);

      if(allTopsID_TTbarMassCalc->at(top1index) == 6){
        genTopPt = allTopsPt_TTbarMassCalc->at(top1index);
        genAntiTopPt = allTopsPt_TTbarMassCalc->at(top2index);
      }
      else{
        genAntiTopPt = allTopsPt_TTbarMassCalc->at(top1index);
        genTopPt = allTopsPt_TTbarMassCalc->at(top2index);
      }
    }

    // ----------------------------------------------------------------------------
    // W --> l nu with mass constraint
    // ----------------------------------------------------------------------------

    if( debug == 1 ){ cout << "[DEBUG] W to l nu with mass constraint" << endl; }
    double metpx = corr_met_MultiLepCalc*cos(corr_met_phi_MultiLepCalc);
    double metpy = corr_met_MultiLepCalc*sin(corr_met_phi_MultiLepCalc);
    double metpt = corr_met_MultiLepCalc;

    double Dtmp = (MW*MW)-(lepM*lepM)+2*((lepton_lv.Px())*(metpx)+(lepton_lv.Py())*(metpy));
    double Atmp = 4.0*((lepton_lv.Energy())*(lepton_lv.Energy())-(lepton_lv.Pz())*(lepton_lv.Pz()));
    double Btmp = -4.0*Dtmp*(lepton_lv.Pz());
    double Ctmp = 4.0*(lepton_lv.Energy())*(lepton_lv.Energy())*(metpt)*(metpt)-Dtmp*Dtmp;
    
    double nuPz_1;
    double nuPz_2;
    
    double DETtmp = Btmp*Btmp-4.0*Atmp*Ctmp;
    
    TLorentzVector Wlv_1, Wlv_2, Wlv, lvTop;
    if(DETtmp >= 0) {
      nuPz_1 = (-Btmp+TMath::Sqrt(DETtmp))/(2.0*Atmp);
      nuPz_2 = (-Btmp-TMath::Sqrt(DETtmp))/(2.0*Atmp);
      TLorentzVector Nulv_1(metpx,metpy,nuPz_1,TMath::Sqrt((metpt)*(metpt)+(nuPz_1)*(nuPz_1)));
      TLorentzVector Nulv_2(metpx,metpy,nuPz_2,TMath::Sqrt((metpt)*(metpt)+(nuPz_2)*(nuPz_2)));
      Wlv_1 = Nulv_1+lepton_lv;
      Wlv_2 = Nulv_2+lepton_lv;
    }
    if(DETtmp < 0) {
      nuPz_1 = (-Btmp)/(2.0*Atmp);
      nuPz_2 = (-Btmp)/(2.0*Atmp);
      double alpha = (lepton_lv.Px())*(metpx)/(metpt)+(lepton_lv.Py())*(metpy)/(metpt);
      double Delta = (MW*MW)-(lepM*lepM);
      Atmp = 4.0*((lepton_lv.Pz())*(lepton_lv.Pz())-(lepton_lv.Energy())*(lepton_lv.Energy())+(alpha*alpha));
      Btmp = 4.0*alpha*Delta;
      Ctmp = Delta*Delta;
      DETtmp = Btmp*Btmp-4.0*Atmp*Ctmp;
      double pTnu_1 = (-Btmp+TMath::Sqrt(DETtmp))/(2.0*Atmp);
      double pTnu_2 = (-Btmp-TMath::Sqrt(DETtmp))/(2.0*Atmp);
      TLorentzVector Nulv_1(metpx*(pTnu_1)/(metpt),metpy*(pTnu_1)/(metpt),nuPz_1,TMath::Sqrt((pTnu_1)*(pTnu_1)+(nuPz_1)*(nuPz_1)));
      TLorentzVector Nulv_2(metpx*(pTnu_2)/(metpt),metpy*(pTnu_2)/(metpt),nuPz_2,TMath::Sqrt((pTnu_2)*(pTnu_2)+(nuPz_2)*(nuPz_2)));
      Wlv_1 = Nulv_1+lepton_lv;
      Wlv_2 = Nulv_2+lepton_lv;
      if (fabs(Wlv_1.M()-MW) < fabs(Wlv_2.M()-MW)) Wlv_2 = Wlv_1;
      else Wlv_1 = Wlv_2;
    }
        
    // ----------------------------------------------------------------------------
    // top --> W b --> l nu b using W from above
    // ----------------------------------------------------------------------------

    double dMTOP = 1e8;
    unsigned int topIndex = 0;
    bool firstW = true;
    double MTop_1, MTop_2;
    for(unsigned int ijet=0; ijet < theJetPt_JetSubCalc_PtOrdered.size(); ijet++){
      jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(ijet),theJetEta_JetSubCalc_PtOrdered.at(ijet),theJetPhi_JetSubCalc_PtOrdered.at(ijet),theJetEnergy_JetSubCalc_PtOrdered.at(ijet));
      MTop_1 = (jet_lv + Wlv_1).M();
      MTop_2 = (jet_lv + Wlv_2).M();
      if(fabs(MTop_1 - MTOP) < dMTOP) {
        if(fabs(MTop_1 - MTOP) < fabs(MTop_2 - MTOP)) {
          firstW = true;
          topIndex = ijet;
          dMTOP = fabs(MTop_1 - MTOP);
        }
        else {
          firstW = false;
          topIndex = ijet;
          dMTOP = fabs(MTop_2 - MTOP);
        }
      }
      else if(fabs(MTop_2 - MTOP) < dMTOP) {
        firstW = false;
        topIndex = ijet;
        dMTOP = fabs(MTop_2 - MTOP);
      }
    }

    if(firstW) {Wlv = Wlv_1;}
    else{Wlv = Wlv_2;}

    jet_lv.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered.at(topIndex),theJetEta_JetSubCalc_PtOrdered.at(topIndex),theJetPhi_JetSubCalc_PtOrdered.at(topIndex),theJetEnergy_JetSubCalc_PtOrdered.at(topIndex));
    lvTop = jet_lv + Wlv; //Top LV

    recLeptonicTopPt = lvTop.Pt();
    recLeptonicTopEta = lvTop.Eta();
    recLeptonicTopPhi = lvTop.Phi();
    recLeptonicTopMass = lvTop.M();
    recLeptonicTopJetIdx = topIndex;

    // ----------------------------------------------------------------------------
    // Apply pt ordering to AK8 vectors 
    // ----------------------------------------------------------------------------

    //Pt ordering for AK8
    std::sort(jetak8ptindpair.begin(), jetak8ptindpair.end(), comparepair);

    maxProb_JetSubCalc_PtOrdered.clear();
    theJetAK8DoubleB_JetSubCalc_PtOrdered.clear();
    theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.clear();
    theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered.clear();
    theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.clear();
    theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.clear();
    theJetAK8Pt_JetSubCalc_PtOrdered.clear();
    theJetAK8Eta_JetSubCalc_PtOrdered.clear();
    theJetAK8Phi_JetSubCalc_PtOrdered.clear();
    theJetAK8Energy_JetSubCalc_PtOrdered.clear();
    theJetAK8Mass_JetSubCalc_PtOrdered.clear();
    theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered.clear();
    theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered.clear();
    theJetAK8SoftDropRaw_JetSubCalc_PtOrdered.clear();
    theJetAK8SoftDropCorr_JetSubCalc_PtOrdered.clear();
    theJetAK8SoftDrop_JetSubCalc_PtOrdered.clear();
    theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered.clear();
    theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered.clear();
    theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered.clear();
    theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered.clear();
    theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.clear();
    theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.clear();
    theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.clear();
    theJetAK8CHSTau1_JetSubCalc_PtOrdered.clear();
    theJetAK8CHSTau2_JetSubCalc_PtOrdered.clear();
    theJetAK8CHSTau3_JetSubCalc_PtOrdered.clear();
    theJetAK8Indx_Wtagged.clear();
    if( debug == 1 ){ cout << "[DEBUG] Pt ordering for AK8 jets" << endl; }
    for(unsigned int ijet=0; ijet < jetak8ptindpair.size(); ijet++){
      maxProb_JetSubCalc_PtOrdered.push_back(maxProb_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8DoubleB_JetSubCalc_PtOrdered.push_back(theJetAK8DoubleB_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetIndex_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetSize_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered.push_back(theJetAK8SDSubjetNDeepCSVL_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8Pt_JetSubCalc_PtOrdered.push_back(theJetAK8Pt_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8Eta_JetSubCalc_PtOrdered.push_back(theJetAK8Eta_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8Phi_JetSubCalc_PtOrdered.push_back(theJetAK8Phi_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8Energy_JetSubCalc_PtOrdered.push_back(theJetAK8Energy_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8Mass_JetSubCalc_PtOrdered.push_back(theJetAK8Mass_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8SoftDropRaw_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDropRaw_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8SoftDropCorr_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDropCorr_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8SoftDrop_JetSubCalc_PtOrdered.push_back(theJetAK8SoftDrop_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered.push_back(theJetAK8SoftDrop_JMRup_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered.push_back(theJetAK8SoftDrop_JMRdn_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered.push_back(theJetAK8SoftDrop_JMSup_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered.push_back(theJetAK8SoftDrop_JMSdn_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau1_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau2_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.push_back(theJetAK8NjettinessTau3_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8CHSTau1_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau1_JetSubCalc->at(jetak8ptindpair[ijet].second));      	
      theJetAK8CHSTau2_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau2_JetSubCalc->at(jetak8ptindpair[ijet].second));
      theJetAK8CHSTau3_JetSubCalc_PtOrdered.push_back(theJetAK8CHSTau3_JetSubCalc->at(jetak8ptindpair[ijet].second));
    }

    // ----------------------------------------------------------------------------
    // AK8 Jet - lepton associations, Top and W taggging
    // ----------------------------------------------------------------------------

    NJetsWtagged = 0;
    NJetsTtagged = 0;
    deltaR_lepAK8s.clear();
    minDR_lepAK8 = 1000;
    minDR_leadAK8otherAK8 = 1000;
    if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 1) minDR_lepAK8 = -99.0;      
    if(theJetAK8Pt_JetSubCalc_PtOrdered.size() < 2) minDR_leadAK8otherAK8 = -99.0;
    WJetLeadPt = -99.0;
    TJetLeadPt = -99.0;

    theJetAK8Wmatch_JetSubCalc_PtOrdered.clear();
    theJetAK8Tmatch_JetSubCalc_PtOrdered.clear();
    theJetAK8MatchedPt_JetSubCalc_PtOrdered.clear();
    theJetAK8Truth_JetSubCalc_PtOrdered.clear();
    NJetsWtagged_shifts.clear();
    NJetsTtagged_shifts.clear();

    wjet1_lv.SetPtEtaPhiM(0,0,0,0);
    tjet1_lv.SetPtEtaPhiM(0,0,0,0);
    ak8_lv.SetPtEtaPhiM(0,0,0,0);
    TLorentzVector leadak8;
    leadak8.SetPtEtaPhiM(0,0,0,0);

    for(int i = 0; i < 8; i++){
      NJetsWtagged_shifts.push_back(0);
      NJetsTtagged_shifts.push_back(0);
    }

    if( debug == 1 ){ cout << "[DEBUG] AK8 jet-lepton associations" << endl; }
    for(unsigned int ijet=0; ijet < theJetAK8Pt_JetSubCalc_PtOrdered.size(); ijet++){

      // ----------------------------------------------------------------------------
      // AK8 - lepton and AK8 -- AK8 associations
      // ----------------------------------------------------------------------------
    
      ak8_lv.SetPtEtaPhiE(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet),theJetAK8Eta_JetSubCalc_PtOrdered.at(ijet),theJetAK8Phi_JetSubCalc_PtOrdered.at(ijet),theJetAK8Energy_JetSubCalc_PtOrdered.at(ijet));
      if(ijet == 0) leadak8 = ak8_lv;

      deltaR_lepAK8s.push_back(lepton_lv.DeltaR(ak8_lv));
      if(lepton_lv.DeltaR(ak8_lv) < minDR_lepAK8){
        minDR_lepAK8 = lepton_lv.DeltaR(ak8_lv);
        ptRel_lepAK8 = lepton_lv.P()*(ak8_lv.Vect().Cross(lepton_lv.Vect()).Mag()/ak8_lv.P()/lepton_lv.P());
      }
    
      if(ijet > 0){
        float tempdr = leadak8.DeltaR(ak8_lv);
        if(tempdr < minDR_leadAK8otherAK8){
          minDR_leadAK8otherAK8 = tempdr;
        }
      }

      // ----------------------------------------------------------------------------
      // W & top tagging on MC
      // ----------------------------------------------------------------------------
    
      float tau21WP = 0.45; //WP from https://twiki.cern.ch/twiki/bin/viewauth/CMS/JetTopTagging#13_TeV_Working_Points_and_Scale
      float tau32WP = 0.80; //WP5 from https://twiki.cern.ch/twiki/bin/viewauth/CMS/JetTopTagging#13_TeV_Working_Points_and_Scale

      float tau21 = theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.at(ijet)/theJetAK8NjettinessTau1_JetSubCalc_PtOrdered.at(ijet);
      float tau32 = theJetAK8NjettinessTau3_JetSubCalc_PtOrdered.at(ijet)/theJetAK8NjettinessTau2_JetSubCalc_PtOrdered.at(ijet);

      float massSD = theJetAK8SoftDropCorr_JetSubCalc_PtOrdered.at(ijet);
      float massSD_JMSup = theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered.at(ijet);
      float massSD_JMSdn = theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered.at(ijet);
      float massSD_JMRup = theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered.at(ijet);
      float massSD_JMRdn = theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered.at(ijet);

      // ------------------------------------------------------------------------------------------------------------------
      // MC Calculation first
      // ------------------------------------------------------------------------------------------------------------------

      if(isMC){
      
        // ------------------------------------------------------------------------------------------------------------------
        // TRUTH MATCHING
        // ------------------------------------------------------------------------------------------------------------------
        float minDR = 1000;
        float matchedPt= -99;
        int matchedID = 0;
        bool isWmatched = false;
        bool isHmatched = false;
        bool isZmatched = false;
        bool isTmatched = false;
        bool isJmatched = false;
        bool isBmatched = false;
        TLorentzVector trueW,d1,d2,d3;

        for(unsigned int iW = 0; iW < HadronicVHtPt_JetSubCalc->size(); iW++){
          trueW.SetPtEtaPhiE(HadronicVHtPt_JetSubCalc->at(iW),HadronicVHtEta_JetSubCalc->at(iW),HadronicVHtPhi_JetSubCalc->at(iW),HadronicVHtEnergy_JetSubCalc->at(iW));

          if(ak8_lv.DeltaR(trueW) < minDR){
            minDR = ak8_lv.DeltaR(trueW);
            matchedPt = HadronicVHtPt_JetSubCalc->at(iW);
            matchedID = abs(HadronicVHtID_JetSubCalc->at(iW));	      
            d1.SetPtEtaPhiE(HadronicVHtD0Pt_JetSubCalc->at(iW),HadronicVHtD0Eta_JetSubCalc->at(iW),HadronicVHtD0Phi_JetSubCalc->at(iW),HadronicVHtD0E_JetSubCalc->at(iW));
            d2.SetPtEtaPhiE(HadronicVHtD1Pt_JetSubCalc->at(iW),HadronicVHtD1Eta_JetSubCalc->at(iW),HadronicVHtD1Phi_JetSubCalc->at(iW),HadronicVHtD1E_JetSubCalc->at(iW));
            d3.SetPtEtaPhiE(HadronicVHtD2Pt_JetSubCalc->at(iW),HadronicVHtD2Eta_JetSubCalc->at(iW),HadronicVHtD2Phi_JetSubCalc->at(iW),HadronicVHtD2E_JetSubCalc->at(iW));
          }
        }	 
      
        bool WallDsInJet = false;
        bool TallDsInJet = false;
        if(matchedID != 6 && ak8_lv.DeltaR(d1) < 0.8 && ak8_lv.DeltaR(d2) < 0.8) WallDsInJet = true;
        if(matchedID == 6 && ak8_lv.DeltaR(d1) < 0.8 && ak8_lv.DeltaR(d2) < 0.8 && ak8_lv.DeltaR(d3) < 0.8) TallDsInJet = true;
        if(minDR < 0.8 && matchedID == 24 && WallDsInJet) isWmatched = true;
        if(minDR < 0.8 && matchedID == 25 && WallDsInJet) isHmatched = true;
        if(minDR < 0.8 && matchedID == 23 && WallDsInJet) isZmatched = true;
        if(minDR < 0.8 && matchedID == 6 && TallDsInJet) isTmatched = true;

        theJetAK8Wmatch_JetSubCalc_PtOrdered.push_back(isWmatched);
        theJetAK8Hmatch_JetSubCalc_PtOrdered.push_back(isHmatched);
        theJetAK8Zmatch_JetSubCalc_PtOrdered.push_back(isZmatched);
        theJetAK8Tmatch_JetSubCalc_PtOrdered.push_back(isTmatched);
        if(isWmatched || isZmatched || isHmatched || isTmatched) theJetAK8MatchedPt_JetSubCalc_PtOrdered.push_back(matchedPt);
        else theJetAK8MatchedPt_JetSubCalc_PtOrdered.push_back(-99.0);

        if (not (isWmatched && matchedPt > 200) && not (isZmatched && matchedPt > 200) && not (isTmatched && matchedPt > 400) && not (isHmatched && matchedPt > 300)) {
          int firstsub = theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered.at(ijet);
          int nsubs = theJetAK8SDSubjetSize_JetSubCalc_PtOrdered.at(ijet);
          for(int isub = firstsub; isub < firstsub + nsubs; isub++){
            if( theJetAK8SDSubjetHFlav_JetSubCalc->at(isub) == 5 ) isBmatched = true;
          }
          if ( not isBmatched ) isJmatched = true;
        }

        if(isJmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(0);
        if(isTmatched && matchedPt > 400) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(1);
        if(isHmatched && matchedPt > 300) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(2);
        if(isZmatched && matchedPt > 200) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(3);
        if(isWmatched && matchedPt > 200) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(4);
        if(isBmatched) theJetAK8Truth_JetSubCalc_PtOrdered.push_back(5);

        // ------------------------------------------------------------------------------------------------------------------
        // TOP TAGGING -- needs to be updated
        // ------------------------------------------------------------------------------------------------------------------
        double tau32SF = 1.0;
        double tau32SFup = 1.0;
        double tau32SFdn = 1.0;
        double tau32eff = 1.0;
        if( isTmatched && matchedPt >= 400 ){	    
          hardcodedConditions.GetTtaggingSF(matchedPt, &tau32SF, &tau32SFup, &tau32SFdn, Year);
          // Use matched T to find the efficiency -- EWK/QCD will almost never pass here (use ttbar eff when they do)
          if(isTTTT) {hardcodedConditions.GetTtaggingEff(matchedPt, &tau32eff, Year, "tttt");}
          else if(isXX) {hardcodedConditions.GetTtaggingEff(matchedPt, &tau32eff, Year, "x53x53",SigMass);}		
          else if(isTT) {hardcodedConditions.GetTtaggingEff(matchedPt, &tau32eff, Year, "ttbar");}
          else {hardcodedConditions.GetTtaggingEff(matchedPt, &tau32eff, Year, "singletop");}
        }
      
        // Set the initial tagged/untagged state
        bool isTtagged = (massSD > 105) && (massSD < 210) && (tau32 < tau32WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
        bool isTtagged_JMSup = (massSD_JMSup > 105) && (massSD_JMSup < 210) && (tau32 < tau32WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
        bool isTtagged_JMSdn = (massSD_JMSdn > 105) && (massSD_JMSdn < 210) && (tau32 < tau32WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
        bool isTtagged_JMRup = (massSD_JMRup > 105) && (massSD_JMRup < 210) && (tau32 < tau32WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);
        bool isTtagged_JMRdn = (massSD_JMRdn > 105) && (massSD_JMRdn < 210) && (tau32 < tau32WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);

        // IF THE JET IS NOT TRUTH-MATCHED, THESE IFS WILL DO NOTHING, SF == 1
        int tag_top = applySF(isTtagged,tau32SF,tau32eff);
        int tag_top_tau32up = applySF(isTtagged,tau32SFup,tau32eff);
        int tag_top_tau32dn = applySF(isTtagged,tau32SFdn,tau32eff);
        int tag_top_JMSup = applySF(isTtagged_JMSup,tau32SF,tau32eff);
        int tag_top_JMSdn = applySF(isTtagged_JMSdn,tau32SF,tau32eff);
        int tag_top_JMRup = applySF(isTtagged_JMRup,tau32SF,tau32eff);
        int tag_top_JMRdn = applySF(isTtagged_JMRdn,tau32SF,tau32eff);
   
        // Now increase the tag count in the right variable	  
        NJetsTtagged += tag_top;
        NJetsTtagged_shifts[0] += tag_top_tau32up;
        NJetsTtagged_shifts[1] += tag_top_tau32dn;
        NJetsTtagged_shifts[2] += tag_top_JMSup;
        NJetsTtagged_shifts[3] += tag_top_JMSdn;
        NJetsTtagged_shifts[4] += tag_top_JMRup;
        NJetsTtagged_shifts[5] += tag_top_JMRdn;
      
        if(tag_top && theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) > TJetLeadPt){ TJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet); }

        // ------------------------------------------------------------------------------------------------------------------
        // W TAGGING
        // ------------------------------------------------------------------------------------------------------------------

        double tau21SF = 1.0;
        double tau21SFup = 1.0;
        double tau21SFdn = 1.0;
        double tau21ptSFup = 1.0;
        double tau21ptSFdn = 1.0;
        double tau21eff = 1.0;
        if(isWmatched && matchedPt >= 175 && massSD > 65 && massSD < 105 && theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200){	    
          hardcodedConditions.GetWtaggingSF(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet), &tau21SF, &tau21SFup, &tau21SFdn, &tau21ptSFup, &tau21ptSFdn, Year);
          // Use matched W to find the efficiency -- EWK/QCD will almost never pass here (use ttbar eff when they do)
          if(isXX) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "x53x53",SigMass);}
          else if(isTpTp) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "TpTp",SigMass);}
          else if(isBpBp) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "BpBp",SigMass);}
          else if(isTTTT) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "tttt");}
          else if(isTT) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "ttbar");}
          else if(isSTt) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "singletopt");}
          else if(isSTtW) {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "singletoptW");}
          else {hardcodedConditions.GetWtaggingEff(matchedPt, &tau21eff, Year, "WV");}
        }
      
        // Set the initial tagged/untagged state
        bool isWtagged = (massSD > 65) && (massSD < 105) && (tau21 < tau21WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
        bool isWtagged_JMSup = (massSD_JMSup > 65) && (massSD_JMSup < 105) && (tau21 < tau21WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
        bool isWtagged_JMSdn = (massSD_JMSdn > 65) && (massSD_JMSdn < 105) && (tau21 < tau21WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
        bool isWtagged_JMRup = (massSD_JMRup > 65) && (massSD_JMRup < 105) && (tau21 < tau21WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
        bool isWtagged_JMRdn = (massSD_JMRdn > 65) && (massSD_JMRdn < 105) && (tau21 < tau21WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
        if(isWtagged) { theJetAK8Indx_Wtagged.push_back(ijet); }
   
        // IF THE JET IS NOT TRUTH-MATCHED, THESE IFS WILL DO NOTHING, SF == 1
        int tag_W = applySF(isWtagged,tau21SF,tau21eff);
        int tag_W_tau21up = applySF(isWtagged,tau21SFup,tau21eff);
        int tag_W_tau21dn = applySF(isWtagged,tau21SFdn,tau21eff);
        int tag_W_JMSup = applySF(isWtagged_JMSup,tau21SF,tau21eff);
        int tag_W_JMSdn = applySF(isWtagged_JMSdn,tau21SF,tau21eff);
        int tag_W_JMRup = applySF(isWtagged_JMRup,tau21SF,tau21eff);
        int tag_W_JMRdn = applySF(isWtagged_JMRdn,tau21SF,tau21eff);
        int tag_W_tau21ptup = applySF(isWtagged,tau21ptSFup,tau21eff);
        int tag_W_tau21ptdn = applySF(isWtagged,tau21ptSFdn,tau21eff);

        // Now increase the tag count in the right variable	  
        NJetsWtagged += tag_W;
        NJetsWtagged_shifts[0] += tag_W_tau21up;
        NJetsWtagged_shifts[1] += tag_W_tau21dn;
        NJetsWtagged_shifts[2] += tag_W_JMSup;
        NJetsWtagged_shifts[3] += tag_W_JMSdn;
        NJetsWtagged_shifts[4] += tag_W_JMRup;
        NJetsWtagged_shifts[5] += tag_W_JMRdn;
        NJetsWtagged_shifts[6] += tag_W_tau21ptup;
        NJetsWtagged_shifts[7] += tag_W_tau21ptdn;

        if(tag_W && theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) > WJetLeadPt){ WJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet); }
      } //end of isMC
      // ------------------------------------------------------------------------------------------------------------------
      // DATA Calculation second
      // ------------------------------------------------------------------------------------------------------------------
      else{
        theJetAK8Wmatch_JetSubCalc_PtOrdered.push_back(0);
        theJetAK8Tmatch_JetSubCalc_PtOrdered.push_back(0);

        bool isWtagged = (massSD > 65)  && (massSD < 105) && (tau21 < tau21WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 200);
        bool isTtagged = (massSD > 105) && (massSD < 210) && (tau32 < tau32WP) && (theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) >= 400);

        NJetsWtagged += isWtagged;
        NJetsTtagged += isTtagged;

        if(isWtagged){
          theJetAK8Indx_Wtagged.push_back(ijet);
          if(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) > WJetLeadPt) { WJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet); }
        }
        else if(isTtagged){
          if(theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet) > TJetLeadPt) { TJetLeadPt = theJetAK8Pt_JetSubCalc_PtOrdered.at(ijet); }
        }
      }
    }

    // ----------------------------------------------------------------------------
    // HOT TAGGER -- SCALE FACTORS TO BE ADDED!!!
    // !!!! THIS SHOULD BE UPDATED WHEN FWLJMET NTUPLES ARE AVAILABLE WITH UPDATED HOTTAGGERCALC; i.e., WITH getBestGenTopMatch !!!!!!!
    // ----------------------------------------------------------------------------
    if( debug == 1 ){ cout << "[DEBUG] HOT Tagger Start" << endl; }
    NresolvedTops1pFakeNoSF = 0;
    NresolvedTops2pFakeNoSF = 0;
    NresolvedTops5pFakeNoSF = 0;
    NresolvedTops10pFakeNoSF = 0;
    NresolvedTops1pFake = 0;
    NresolvedTops2pFake = 0;
    NresolvedTops5pFake = 0;
    NresolvedTops10pFake = 0;
    NresolvedTops1pFake_shifts.clear();
    NresolvedTops2pFake_shifts.clear();
    NresolvedTops5pFake_shifts.clear();
    NresolvedTops10pFake_shifts.clear();
    for(int i = 0; i < 6; i++){
      NresolvedTops1pFake_shifts.push_back(0);
      NresolvedTops2pFake_shifts.push_back(0);
      NresolvedTops5pFake_shifts.push_back(0);
      NresolvedTops10pFake_shifts.push_back(0);
    }

    unsigned int idjet1,idjet2,idjet3;
    TLorentzVector resolvedTop,resolvedTopD1,resolvedTopD2,resolvedTopD3;
    TLorentzVector trueTop,trueTopD1,trueTopD2,trueTopD3;
    std::vector<float> minDRtopDs;
    minDRtopDs.clear();
    for(int i = 0; i < 3; i++){ minDRtopDs.push_back(0); }
    for(unsigned int itop=0; itop < topDiscriminator_HOTTaggerCalc->size(); itop++){
      if(isMC){

        // ------------------------------------------------------------------------------------------------------------------
        // TRUTH MATCHING
        // ------------------------------------------------------------------------------------------------------------------
        float minDRtop = 1000;
        float minDRtopD1 = 1000;
        float minDRtopD2 = 1000;
        float minDRtopD3 = 1000;
        idjet1 = topJet1Index_HOTTaggerCalc->at(itop);
        idjet2 = topJet2Index_HOTTaggerCalc->at(itop);
        idjet3 = topJet3Index_HOTTaggerCalc->at(itop);
        resolvedTop.SetPtEtaPhiM(topPt_HOTTaggerCalc->at(itop),topEta_HOTTaggerCalc->at(itop),topPhi_HOTTaggerCalc->at(itop),topMass_HOTTaggerCalc->at(itop));
        resolvedTopD1.SetPtEtaPhiE(theJetPt_JetSubCalc->at(idjet1),theJetEta_JetSubCalc->at(idjet1),theJetPhi_JetSubCalc->at(idjet1),theJetEnergy_JetSubCalc->at(idjet1));
        resolvedTopD2.SetPtEtaPhiE(theJetPt_JetSubCalc->at(idjet2),theJetEta_JetSubCalc->at(idjet2),theJetPhi_JetSubCalc->at(idjet2),theJetEnergy_JetSubCalc->at(idjet2));
        resolvedTopD3.SetPtEtaPhiE(theJetPt_JetSubCalc->at(idjet3),theJetEta_JetSubCalc->at(idjet3),theJetPhi_JetSubCalc->at(idjet3),theJetEnergy_JetSubCalc->at(idjet3));
        //cout<<"DEBUGGING: "<<topPt_TTbarMassCalc->size()<<" "<<topbPt_TTbarMassCalc->size()<<" "<<topWPt_TTbarMassCalc->size()<<endl;
        for(unsigned int igtop=0; igtop < topPt_TTbarMassCalc->size(); igtop++){
          if(2*igtop>=topWPt_TTbarMassCalc->size()) continue; // DEBUGGING TEMPORARY EDITION
          if(abs(topWID_TTbarMassCalc->at(2*igtop))>5) continue; // select hadronically decaying tops
          trueTop.SetPtEtaPhiE(topPt_TTbarMassCalc->at(igtop),topEta_TTbarMassCalc->at(igtop),topPhi_TTbarMassCalc->at(igtop),topEnergy_TTbarMassCalc->at(igtop));
          if(resolvedTop.DeltaR(trueTop) < minDRtop){
            minDRtop = resolvedTop.DeltaR(trueTop);
            trueTopD1.SetPtEtaPhiE(topbPt_TTbarMassCalc->at(igtop),topbEta_TTbarMassCalc->at(igtop),topbPhi_TTbarMassCalc->at(igtop),topbEnergy_TTbarMassCalc->at(igtop));
            trueTopD2.SetPtEtaPhiE(topWPt_TTbarMassCalc->at(2*igtop),topWEta_TTbarMassCalc->at(2*igtop),topWPhi_TTbarMassCalc->at(2*igtop),topWEnergy_TTbarMassCalc->at(2*igtop));
            trueTopD3.SetPtEtaPhiE(topWPt_TTbarMassCalc->at(2*igtop+1),topWEta_TTbarMassCalc->at(2*igtop+1),topWPhi_TTbarMassCalc->at(2*igtop+1),topWEnergy_TTbarMassCalc->at(2*igtop+1));

            minDRtopDs[0] = resolvedTopD1.DeltaR(trueTopD1);
            minDRtopDs[1] = resolvedTopD1.DeltaR(trueTopD2);
            minDRtopDs[2] = resolvedTopD1.DeltaR(trueTopD3);
            std::sort(minDRtopDs.begin(), minDRtopDs.end(), comparefloat);
            minDRtopD1 = minDRtopDs.at(0);
            minDRtopDs[0] = resolvedTopD2.DeltaR(trueTopD1);
            minDRtopDs[1] = resolvedTopD2.DeltaR(trueTopD2);
            minDRtopDs[2] = resolvedTopD2.DeltaR(trueTopD3);
            std::sort(minDRtopDs.begin(), minDRtopDs.end(), comparefloat);
            minDRtopD2 = minDRtopDs.at(0);
            minDRtopDs[0] = resolvedTopD3.DeltaR(trueTopD1);
            minDRtopDs[1] = resolvedTopD3.DeltaR(trueTopD2);
            minDRtopDs[2] = resolvedTopD3.DeltaR(trueTopD3);
            std::sort(minDRtopDs.begin(), minDRtopDs.end(), comparefloat);
            minDRtopD3 = minDRtopDs.at(0);
          }
        }

        double TopTagSF1p = 1.0;
        double TopTagSF2p = 1.0;
        double TopTagSF5p = 1.0;
        double TopTagSF10p = 1.0;
        double TopTagSF1pStat = 0.0;
        double TopTagSF2pStat = 0.0;
        double TopTagSF5pStat = 0.0;
        double TopTagSF10pStat = 0.0;
        double TopTagSF1pCSpur = 0.0;
        double TopTagSF2pCSpur = 0.0;
        double TopTagSF5pCSpur = 0.0;
        double TopTagSF10pCSpur = 0.0;
        double TopTagSF1pClosure = 0.0;
        double TopTagSF2pClosure = 0.0;
        double TopTagSF5pClosure = 0.0;
        double TopTagSF10pClosure = 0.0;
        int NdaughterMatch = (minDRtopD1 < 0.4) + (minDRtopD2 < 0.4) + (minDRtopD3 < 0.4);
        bool isGenMatched = ( (minDRtop < 0.6) && (NdaughterMatch > 1) ); //Requires >=2 daughters matching, in line with the calculated efficiencies. Changing this to =3 daughters matching requires updating the efficiencies!
        hardcodedConditions.GetHOTtaggingSF(topPt_HOTTaggerCalc->at(itop), topNAK4_HOTTaggerCalc, &TopTagSF1p, &TopTagSF1pStat, &TopTagSF1pCSpur, &TopTagSF1pClosure, Year, isGenMatched, "1pfake");
        hardcodedConditions.GetHOTtaggingSF(topPt_HOTTaggerCalc->at(itop), topNAK4_HOTTaggerCalc, &TopTagSF2p, &TopTagSF2pStat, &TopTagSF2pCSpur, &TopTagSF2pClosure, Year, isGenMatched, "2pfake");
        hardcodedConditions.GetHOTtaggingSF(topPt_HOTTaggerCalc->at(itop), topNAK4_HOTTaggerCalc, &TopTagSF5p, &TopTagSF5pStat, &TopTagSF5pCSpur, &TopTagSF5pClosure, Year, isGenMatched, "5pfake");
        hardcodedConditions.GetHOTtaggingSF(topPt_HOTTaggerCalc->at(itop), topNAK4_HOTTaggerCalc, &TopTagSF10p,&TopTagSF10pStat,&TopTagSF10pCSpur,&TopTagSF10pClosure,Year, isGenMatched, "10pfake");
        double TopTagEff1p = 1.0;
        double TopTagEff2p = 1.0;
        double TopTagEff5p = 1.0;
        double TopTagEff10p = 1.0;

        std::string sample_hot;
        if(isTTTT) sample_hot = "tttt";
        else if(isST) sample_hot = "singletop";
        else if(isTTVV) sample_hot = "TTVV";
        else if(isTTTX) sample_hot = "TTTX";
        else if(isTT) sample_hot = "ttbar";
        else if(isTTToSemiLeptonHT500Njet9) sample_hot = "ttbarHT500Njet9";
        else if(isTTV) sample_hot = "ttVjets";
        else if(isTTHnonbb) sample_hot = "ttHToNonbb";
        else if(isTTHbb) sample_hot = "ttHTobb";

        hardcodedConditions.GetHOTtaggingEff(topPt_HOTTaggerCalc->at(itop), &TopTagEff1p, Year, sample_hot, isGenMatched, "1pfake");
        hardcodedConditions.GetHOTtaggingEff(topPt_HOTTaggerCalc->at(itop), &TopTagEff2p, Year, sample_hot, isGenMatched, "2pfake");
        hardcodedConditions.GetHOTtaggingEff(topPt_HOTTaggerCalc->at(itop), &TopTagEff5p, Year, sample_hot, isGenMatched, "5pfake");
        hardcodedConditions.GetHOTtaggingEff(topPt_HOTTaggerCalc->at(itop), &TopTagEff10p,Year, sample_hot, isGenMatched, "10pfake");
        bool isTtagged1p = topDiscriminator_HOTTaggerCalc->at(itop) > 0.95;
        bool isTtagged2p = topDiscriminator_HOTTaggerCalc->at(itop) > 0.92;
        bool isTtagged5p = topDiscriminator_HOTTaggerCalc->at(itop) > 0.85;
        bool isTtagged10p= topDiscriminator_HOTTaggerCalc->at(itop) > 0.75;
        NresolvedTops1pFakeNoSF += isTtagged1p;
        NresolvedTops2pFakeNoSF += isTtagged2p;
        NresolvedTops5pFakeNoSF += isTtagged5p;
        NresolvedTops10pFakeNoSF += isTtagged10p;
        int tag_top_1p = applySF(isTtagged1p,TopTagSF1p,TopTagEff1p);
        int tag_top_2p = applySF(isTtagged2p,TopTagSF2p,TopTagEff2p);
        int tag_top_5p = applySF(isTtagged5p,TopTagSF5p,TopTagEff5p);
        int tag_top_10p = applySF(isTtagged10p,TopTagSF10p,TopTagEff10p);

        int tag_top_1p_statup = applySF(isTtagged1p,TopTagSF1p+TopTagSF1pStat,TopTagEff1p);
        int tag_top_1p_statdn = applySF(isTtagged1p,TopTagSF1p-TopTagSF1pStat,TopTagEff1p);
        int tag_top_2p_statup = applySF(isTtagged2p,TopTagSF2p+TopTagSF2pStat,TopTagEff2p);
        int tag_top_2p_statdn = applySF(isTtagged2p,TopTagSF2p-TopTagSF2pStat,TopTagEff2p);
        int tag_top_5p_statup = applySF(isTtagged5p,TopTagSF5p+TopTagSF5pStat,TopTagEff5p);
        int tag_top_5p_statdn = applySF(isTtagged5p,TopTagSF5p-TopTagSF5pStat,TopTagEff5p);
        int tag_top_10p_statup = applySF(isTtagged10p,TopTagSF10p+TopTagSF10pStat,TopTagEff10p);
        int tag_top_10p_statdn = applySF(isTtagged10p,TopTagSF10p-TopTagSF10pStat,TopTagEff10p);

        int tag_top_1p_cspurup = applySF(isTtagged1p,TopTagSF1p+TopTagSF1pCSpur,TopTagEff1p);
        int tag_top_1p_cspurdn = applySF(isTtagged1p,TopTagSF1p-TopTagSF1pCSpur,TopTagEff1p);
        int tag_top_2p_cspurup = applySF(isTtagged2p,TopTagSF2p+TopTagSF2pCSpur,TopTagEff2p);
        int tag_top_2p_cspurdn = applySF(isTtagged2p,TopTagSF2p-TopTagSF2pCSpur,TopTagEff2p);
        int tag_top_5p_cspurup = applySF(isTtagged5p,TopTagSF5p+TopTagSF5pCSpur,TopTagEff5p);
        int tag_top_5p_cspurdn = applySF(isTtagged5p,TopTagSF5p-TopTagSF5pCSpur,TopTagEff5p);
        int tag_top_10p_cspurup = applySF(isTtagged10p,TopTagSF10p+TopTagSF10pCSpur,TopTagEff10p);
        int tag_top_10p_cspurdn = applySF(isTtagged10p,TopTagSF10p-TopTagSF10pCSpur,TopTagEff10p);

        int tag_top_1p_closureup = tag_top_1p;
        int tag_top_1p_closuredn = tag_top_1p;
        int tag_top_2p_closureup = tag_top_2p;
        int tag_top_2p_closuredn = tag_top_2p;
        int tag_top_5p_closureup = tag_top_5p;
        int tag_top_5p_closuredn = tag_top_5p;
        int tag_top_10p_closureup = tag_top_10p;
        int tag_top_10p_closuredn = tag_top_10p;
        if(!isGenMatched){ //Closure uncertainty is applied to fake tops only
          tag_top_1p_closureup = applySF(isTtagged1p,TopTagSF1p+TopTagSF1pClosure,TopTagEff1p);
          tag_top_1p_closuredn = applySF(isTtagged1p,TopTagSF1p-TopTagSF1pClosure,TopTagEff1p);
          tag_top_2p_closureup = applySF(isTtagged2p,TopTagSF2p+TopTagSF2pClosure,TopTagEff2p);
          tag_top_2p_closuredn = applySF(isTtagged2p,TopTagSF2p-TopTagSF2pClosure,TopTagEff2p);
          tag_top_5p_closureup = applySF(isTtagged5p,TopTagSF5p+TopTagSF5pClosure,TopTagEff5p);
          tag_top_5p_closuredn = applySF(isTtagged5p,TopTagSF5p-TopTagSF5pClosure,TopTagEff5p);
          tag_top_10p_closureup = applySF(isTtagged10p,TopTagSF10p+TopTagSF10pClosure,TopTagEff10p);
          tag_top_10p_closuredn = applySF(isTtagged10p,TopTagSF10p-TopTagSF10pClosure,TopTagEff10p);
        }

        NresolvedTops1pFake += tag_top_1p;
        NresolvedTops2pFake += tag_top_2p;
        NresolvedTops5pFake += tag_top_5p;
        NresolvedTops10pFake += tag_top_10p;
        NresolvedTops1pFake_shifts[0] += tag_top_1p_statup;
        NresolvedTops1pFake_shifts[1] += tag_top_1p_statdn;
        NresolvedTops2pFake_shifts[0] += tag_top_2p_statup;
        NresolvedTops2pFake_shifts[1] += tag_top_2p_statdn;
        NresolvedTops5pFake_shifts[0] += tag_top_5p_statup;
        NresolvedTops5pFake_shifts[1] += tag_top_5p_statdn;
        NresolvedTops10pFake_shifts[0] += tag_top_10p_statup;
        NresolvedTops10pFake_shifts[1] += tag_top_10p_statdn;
        NresolvedTops1pFake_shifts[2] += tag_top_1p_cspurup;
        NresolvedTops1pFake_shifts[3] += tag_top_1p_cspurdn;
        NresolvedTops2pFake_shifts[2] += tag_top_2p_cspurup;
        NresolvedTops2pFake_shifts[3] += tag_top_2p_cspurdn;
        NresolvedTops5pFake_shifts[2] += tag_top_5p_cspurup;
        NresolvedTops5pFake_shifts[3] += tag_top_5p_cspurdn;
        NresolvedTops10pFake_shifts[2] += tag_top_10p_cspurup;
        NresolvedTops10pFake_shifts[3] += tag_top_10p_cspurdn;
        NresolvedTops1pFake_shifts[4] += tag_top_1p_closureup;
        NresolvedTops1pFake_shifts[5] += tag_top_1p_closuredn;
        NresolvedTops2pFake_shifts[4] += tag_top_2p_closureup;
        NresolvedTops2pFake_shifts[5] += tag_top_2p_closuredn;
        NresolvedTops5pFake_shifts[4] += tag_top_5p_closureup;
        NresolvedTops5pFake_shifts[5] += tag_top_5p_closuredn;
        NresolvedTops10pFake_shifts[4] += tag_top_10p_closureup;
        NresolvedTops10pFake_shifts[5] += tag_top_10p_closuredn;
      }  
      else{ // Data
        if(topDiscriminator_HOTTaggerCalc->at(itop) > 0.75) NresolvedTops10pFake+=1;
        if(topDiscriminator_HOTTaggerCalc->at(itop) > 0.85) NresolvedTops5pFake+=1;
        if(topDiscriminator_HOTTaggerCalc->at(itop) > 0.92) NresolvedTops2pFake+=1;
        if(topDiscriminator_HOTTaggerCalc->at(itop) > 0.95) NresolvedTops1pFake+=1;
      }
    }

    // ----------------------------------------------------------------------------
    // PDF and Matrix Element energy scale weights
    // ----------------------------------------------------------------------------

    std::vector<double> renorm;
    std::vector<double> pdf;
    renormWeights.clear();
    renormPSWeights.clear();
    pdfWeights.clear();
    pdfNewWeights.clear();
    pdfNewNominalWeight = 1.0;

    //PSWEIGHTS
    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/TopModGen
    //https://github.com/cms-sw/cmssw/commits/master/Configuration/Generator/python/PSweightsPythia/PythiaPSweightsSettings_cfi.py
    // 2 = isrRedHi isr:muRfac=0.707, 3 = fsrRedHi fsr:muRfac=0.707, 4 = isrRedLo isr:muRfac=1.414, 5 = fsrRedLo fsr:muRfac=1.414, 
    // 6 = isrDefHi isr:muRfac=0.5, 7 = fsrDefHi fsr:muRfac=0.5,  8 = isrDefLo isr:muRfac=2.0,   9 = fsrDefLo fsr:muRfac=2.0, 
    // 10 = isrConHi isr:muRfac=0.25, 11 = fsrConHi fsr:muRfac=0.25, 12 = isrConLo isr:muRfac=4.0, 13 = fsrConLo fsr:muRfac=4.0
    // additional IDs from 14 to 45 corresponding to decorrelated PS variations in case ISR/FSR uncertainty is tightly constrained
    double the_ps_weight=1.0;
    if ( evtWeightsMC_MultiLepCalc->size() >= 14 ) for(auto & i: {6,7,8,9}) {
      the_ps_weight = evtWeightsMC_MultiLepCalc->at(i)/evtWeightsMC_MultiLepCalc->at(0);
      if (fabs(the_ps_weight)>100)
        renormPSWeights.push_back(1.0);
      else
        renormPSWeights.push_back(the_ps_weight);
    }
    else renormPSWeights={1,1,1,1};
    if ( evtWeightsMC_MultiLepCalc->size() >= 45 ) for( int i = 14; i < 46; i++ ){
      the_ps_weight = evtWeightsMC_MultiLepCalc->at(i)/evtWeightsMC_MultiLepCalc->at(0);
      if ( fabs( the_ps_weight ) > 100 ) renormPSWeights.push_back(1.0);
      else renormPSWeights.push_back( the_ps_weight );
    } else for( int i = 14; i < 46; i++ ){
      renormPSWeights.push_back(1.0);
    }


    //std::cout<<"yes 2"<<std::endl;
    //ME-PS
    if( debug == 1 ){ cout << "[DEBUG] Adding theory weights" << endl; }
    if(isSig && !isSig && !isTTTT){
      pdfNewNominalWeight = NewPDFweights_MultiLepCalc->at(0);
      // SEEMS TO APPLY TO ALL B2G MG+PYTHIA SIGNALS. NNLO 4-FLAVOR PDF
      for(unsigned int i = 0; i < LHEweightids_MultiLepCalc->size(); i++){
        if(i > 0 && i < 101) pdfNewWeights.push_back(NewPDFweights_MultiLepCalc->at(i));
        if(LHEweightids_MultiLepCalc->at(i) > 1 && LHEweightids_MultiLepCalc->at(i) < 10){
          if(LHEweightids_MultiLepCalc->at(i) == 6 || LHEweightids_MultiLepCalc->at(i) == 8) continue;
          renormWeights.push_back(LHEweights_MultiLepCalc->at(i));
        }
        if(LHEweightids_MultiLepCalc->at(i) > 474 && LHEweightids_MultiLepCalc->at(i) < 575){
          pdfWeights.push_back(LHEweights_MultiLepCalc->at(i));
        }
      }
    }
    else if(isTTTT){
      for(unsigned int i = 0; i < LHEweightids_MultiLepCalc->size(); i++){
        if(LHEweightids_MultiLepCalc->at(i) > 1001 && LHEweightids_MultiLepCalc->at(i) < 1010){
          if(LHEweightids_MultiLepCalc->at(i) == 1006 || LHEweightids_MultiLepCalc->at(i) == 1008) continue;
          renorm.push_back(LHEweights_MultiLepCalc->at(i));
          renormWeights.push_back(LHEweights_MultiLepCalc->at(i));
        }
        if(LHEweightids_MultiLepCalc->at(i) > 1009 && LHEweightids_MultiLepCalc->at(i) < 1111){
          pdf.push_back(LHEweights_MultiLepCalc->at(i));
          pdfWeights.push_back(LHEweights_MultiLepCalc->at(i));
        }
        if(LHEweightids_MultiLepCalc->at(i) == 1111 || LHEweightids_MultiLepCalc->at(i) == 1112){
          alphaSWeights.push_back(LHEweights_MultiLepCalc->at(i));
        }
      }
    }
    else if(isMadgraphBkg){
      // SEEMS TO APPLY TO OTHER MG+PYTHIA BACKGROUNDS. LEADING ORDER 5-FLAVOR PDF
      for(unsigned int i = 0; i < LHEweightids_MultiLepCalc->size(); i++){
        if(LHEweightids_MultiLepCalc->at(i) > 1 && LHEweightids_MultiLepCalc->at(i) < 10){
          if(LHEweightids_MultiLepCalc->at(i) == 6 || LHEweightids_MultiLepCalc->at(i) == 8) continue;
          renorm.push_back(LHEweights_MultiLepCalc->at(i));
          renormWeights.push_back(LHEweights_MultiLepCalc->at(i));
        }
        if(LHEweightids_MultiLepCalc->at(i) > 10 && LHEweightids_MultiLepCalc->at(i) < 111){
          pdf.push_back(LHEweights_MultiLepCalc->at(i));
          pdfWeights.push_back(LHEweights_MultiLepCalc->at(i));
        }
        if(LHEweightids_MultiLepCalc->at(i) == 111 || LHEweightids_MultiLepCalc->at(i) == 112){
          alphaSWeights.push_back(LHEweights_MultiLepCalc->at(i));
        }
      }
    }
    else{
      // SEEMS TO APPLY TO ALL POWHEG AND MC@NLO BACKGROUNDS. NLO PDFs
      for(unsigned int i = 0; i < LHEweightids_MultiLepCalc->size(); i++){
        if(LHEweightids_MultiLepCalc->at(i) > 1001 && LHEweightids_MultiLepCalc->at(i) < 1010){
          if(LHEweightids_MultiLepCalc->at(i) == 1006 || LHEweightids_MultiLepCalc->at(i) == 1008) continue;
          renorm.push_back(LHEweights_MultiLepCalc->at(i));
          renormWeights.push_back(LHEweights_MultiLepCalc->at(i));
        }
        if(LHEweightids_MultiLepCalc->at(i) > 2000 && LHEweightids_MultiLepCalc->at(i) < 2101){
          pdf.push_back(LHEweights_MultiLepCalc->at(i));
          pdfWeights.push_back(LHEweights_MultiLepCalc->at(i));
        }
        if(LHEweightids_MultiLepCalc->at(i) == 2101 || LHEweightids_MultiLepCalc->at(i) == 2102){
          alphaSWeights.push_back(LHEweights_MultiLepCalc->at(i));
        }
      }
    }
    if(renormWeights.size() == 0){
      if(isVV){
        renormWeights.push_back(0.85);
        renormWeights.push_back(1.15);
        renormWeights.push_back(0.85);
        renormWeights.push_back(0.85);
        renormWeights.push_back(1.15);
        renormWeights.push_back(1.15);
      } else {
        for(int irn = 0; irn < 6; irn++){
          renormWeights.push_back(1.0);
        }
      }
    }
    if(pdfWeights.size() == 0){
      for(int ipdf = 0; ipdf < 100; ipdf++){
        pdfWeights.push_back(1.0);
      }
    }

    // ----------------------------------------------------------------------------
    // DONE!! Write the tree
    // ----------------------------------------------------------------------------
    if( debug == 1 ) std::cout << "[DEBUG] Filling tree" << std::endl;
    outputTree->Fill();
  }
  std::cout<<"Nelectrons      = "<<Nelectrons<<" / "<<nentries<<std::endl;
  std::cout<<"Npassed_ElEta   = "<<npass_ElEta<<" / "<<nentries<<std::endl;
  std::cout<<"Nmuons          = "<<Nmuons<<" / "<<nentries<<std::endl;
  std::cout<<"NrelIsoFail     = "<<NrelIsoFail<<" / "<<nentries<<std::endl;
  std::cout<<"Npassed_MuEta   = "<<npass_MuEta<<" / "<<nentries<<std::endl;
  std::cout<<"Npassed_nAK8Jets= "<<npass_nAK8jets<<" / "<<nentries<<std::endl;
  std::cout<<"Npassed_Trigger = "<<npass_trigger<<" / "<<nentries<<std::endl;
  std::cout<<"Npassed_MET     = "<<npass_met<<" / "<<nentries<<std::endl;
  std::cout<<"Npassed_lepPt   = "<<npass_lepPt<<" / "<<nentries<<std::endl;
  std::cout<<"Npassed_HT      = "<<npass_ht<<" / "<<nentries<<std::endl;
  std::cout<<"npass_Njets     = "<<npass_Njets<<" / "<<nentries<<std::endl;
  std::cout<<"Npassed_ALL     = "<<npass_all<<" / "<<nentries<<std::endl;

  outputTree->Write();
  delete outputTree;
  delete poly2;
  delete poly2U;
  delete poly2D;

}
