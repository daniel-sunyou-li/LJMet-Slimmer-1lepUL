//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Nov  3 14:28:48 2019 by ROOT version 6.12/07
// from TTree ljmet/ljmet
// found on file: /mnt/hadoop/store/group/bruxljm/FWLJMET102X_1lep2017_4t_081019_step1hadds/nominal/TTTT_TuneCP5_13TeV-amcatnlo-pythia8_hadd.root
//////////////////////////////////////////////////////////

#ifndef step2_h
#define step2_h

#include <iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "TLorentzVector.h"
#include "Davismt2.h"
#include "S2HardcodedConditions.h"

class step2 {
public :
   //!pointer to the analyzed TTree or TChain
   TTree          *inputTree;   //!pointer to the analyzed TTree or TChain
   TFile          *inputFile, *outputFile;
   Int_t           fCurrent; //!current Tree number in a TChain

   //Load Scale Factors
   S2HardcodedConditions hardcodedConditions;
  
// Fixed size dimensions of array or collections stored in the TTree if any.
   Int_t           isTraining;
   Bool_t          isTTbar;
   Bool_t          isTTTT;   
   Float_t         xsecEff; //this is the weight actually!! so (Lumi * xsec)/nEvents, but keeping the naming the same to be consistent with TMVA setup

   Bool_t          isST = false;
   Bool_t          isSTs = false;
   Bool_t          isSTt = false;
   Bool_t          isSTtw = false; 
   Bool_t          isTTBB = false;
   Bool_t          isTT2B = false; 
   Bool_t          isTT1B = false; 
   Bool_t          isTTCC = false; 
   Bool_t          isTTLF = false; 
   Bool_t          isWJets = false;
   Bool_t          isCHM200 = false;  
   Bool_t          isCHM220 = false;
   Bool_t          isCHM250 = false;
   Bool_t          isCHM300 = false;
   Bool_t          isCHM350 = false;
   Bool_t          isCHM400 = false;
   Bool_t          isCHM500 = false;
   Bool_t          isCHM600 = false;
   Bool_t          isCHM700 = false;
   Bool_t          isCHM800 = false;
   Bool_t          isCHM1000= false;
   Bool_t          isCHM1250= false;
   Bool_t          isCHM1500= false;
   Bool_t          isCHM1750= false;
   Bool_t          isCHM2000= false;
   Bool_t          isCHM2500= false;
   Bool_t          isCHM3000= false;






  
   TString         sample_ = "";
   std::string     sample = "";
  
   Float_t         btagDeepJet2DWeight;
   Float_t         btagDeepJet2DWeight_Pt120; 
   Float_t         btagDeepJet2DWeight_HTnj;
   Float_t         btagDeepJet2DWeight_HTnj_HFup;
   Float_t         btagDeepJet2DWeight_HTnj_HFdn;
   Float_t         btagDeepJet2DWeight_HTnj_LFup;
   Float_t         btagDeepJet2DWeight_HTnj_LFdn;
   Float_t         btagDeepJet2DWeight_HTnj_jesup;
   Float_t         btagDeepJet2DWeight_HTnj_jesdn;
   Float_t         btagDeepJet2DWeight_HTnj_hfstats1up;
   Float_t         btagDeepJet2DWeight_HTnj_hfstats1dn;
   Float_t         btagDeepJet2DWeight_HTnj_hfstats2up;
   Float_t         btagDeepJet2DWeight_HTnj_hfstats2dn;
   Float_t         btagDeepJet2DWeight_HTnj_cferr1up;
   Float_t         btagDeepJet2DWeight_HTnj_cferr1dn;
   Float_t         btagDeepJet2DWeight_HTnj_cferr2up;
   Float_t         btagDeepJet2DWeight_HTnj_cferr2dn;
   Float_t         btagDeepJet2DWeight_HTnj_lfstats1up;
   Float_t         btagDeepJet2DWeight_HTnj_lfstats1dn;
   Float_t         btagDeepJet2DWeight_HTnj_lfstats2up;
   Float_t         btagDeepJet2DWeight_HTnj_lfstats2dn;
   Float_t         tmp_minMleppBjet;
   vector<double>  GD_DR_Tridijet;
   vector<double>  BD_DR_Tridijet;   
   vector<double>  GD_Ttrijet_TopMass;
   vector<double>  BD_Ttrijet_TopMass;
   vector<double>  GD_Mass_minDR_dijet;
   vector<double>  BD_Mass_minDR_dijet;
   vector<double>  GD_pTrat;
   vector<double>  BD_pTrat;
   vector<double>  GD_DR_Trijet_jetNotdijet;
   vector<double>  BD_DR_Trijet_jetNotdijet;  
   vector<double>  deltaPhi_METjets;
   Float_t         nGD_trijet;
   Float_t         is_genMissingDaughter;
   Float_t         is_genFourTopsOnelepton;
      
   //Additional Variables from the charged higgs analysis
   Float_t         minBBdr;
   Float_t         deltaR_minBB;
   Float_t         aveBBdr;
   Float_t         deltaEta_maxBB; 
   Float_t         FW_momentum_2;
   Float_t         centrality;
   Float_t         aveCSVpt;
   Float_t         mass_maxJJJpt;
   Float_t         maxJJJpt; 
   Float_t         lepDR_minBBdr;
   Float_t         HT_pt40;
   Float_t         HT_bjets;
   Float_t         HT_ratio;        
   Float_t         HT_2m;
   Float_t         firstcsvb_bb;        
   Float_t         secondcsvb_bb;        
   Float_t         thirdcsvb_bb;        
   Float_t         fourthcsvb_bb;  
   Float_t 	   thirdcsvb_bb_BTagBHad;
   Float_t         thirdcsvb_bb_BTagNBHad;
   Float_t         thirdcsvb_bb_NBTagBHad;
   Float_t         thirdcsvb_bb_NBTagNBHad;
   Float_t         PtFifthJet;
   Float_t         deltaR_lepJetInMinMljet;      
   Float_t         deltaPhi_lepJetInMinMljet;         
   Float_t         deltaR_lepbJetInMinMlb;
   Float_t         deltaPhi_lepbJetInMinMlb;
   Float_t         MT2bb; 
   Float_t         pt3HT;
   Float_t         pt4HT;   
   Float_t         pTjet5_6;
   Float_t         invM_jet34;
   Float_t         invM_jet35;   
   Float_t         invM_jet36;
   Float_t         invM_jet45;         
   Float_t         invM_jet46;         
   Float_t         invM_jet56;            
   Float_t         mean_csv;
   Float_t         csvJet1;
   Float_t         csvJet2;
   Float_t         csvJet3;
   Float_t         csvJet4;
   Float_t         pT_3rdcsvJet;
   Float_t         pT_4thcsvJet;      
   Float_t         MHRE;
   Float_t         HTx;
   Float_t         Sphericity;
   Float_t         Aplanarity;
   Float_t         secondJetPt;
   Float_t         fifthJetPt;
   Float_t         sixthJetPt;     
   Float_t         deltaR_lepbJetNotInMinMlb;
   vector<double>  GD_DCSV_jetNotdijet;
   vector<double>  BD_DCSV_jetNotdijet;   
      
   Float_t         mass_minBBdr;   
   Float_t         mass_minLLdr;
   Float_t         mass_maxBBpt;
   Float_t         mass_maxBBmass;
   Float_t         theJetLeadPt;
   Float_t         mass_lepJets0;
   Float_t         mass_lepJets1;
   Float_t         mass_lepJets2;
   Float_t         deltaR_lepBJets0;
   Float_t         deltaR_lepBJets1;   
   Float_t         minDR_lepBJet;
   Float_t         mass_lepBJet0;
   Float_t         mass_lepBB_minBBdr;
   Float_t         mass_lepJJ_minJJdr;
   Float_t         mass_lepBJet_mindr;
   Float_t         deltaR_lepBJet_maxpt;
   Float_t         deltaPhi_maxBB;
   Float_t         hemiout;
   Float_t         corr_met;
   Float_t         deltaPhi_lepMET;
   Float_t         min_deltaPhi_METjets;
   Float_t         aveCSV;
   Float_t         deltaPhi_j1j2;
   Float_t         alphaT;
   Float_t         FW_momentum_0;
   Float_t         FW_momentum_1;
   Float_t         FW_momentum_3;
   Float_t         FW_momentum_4;
   Float_t         FW_momentum_5;
   Float_t         FW_momentum_6;

   Float_t         HT_woBESTjet;
   Float_t         MT_woBESTjet;
   Float_t         PT_woBESTjet;      
   Float_t         M_woBESTjet;            
   Float_t         M_allJet_W;
   Float_t         ratio_HTdHT4leadjets;
   Float_t         W_PtdM;
   Float_t	   BDTtrijet2;
   Float_t         BDTtrijet1;
   Float_t         BDTtrijet3;
   Float_t         BDTtrijet4;
   
   Float_t	   HOTGoodTrijet1_mass;
   Float_t	   HOTGoodTrijet1_dijetmass;
   Float_t         HOTGoodTrijet1_pTratio;
   Float_t         HOTGoodTrijet1_dRtridijet;
   Float_t         HOTGoodTrijet1_dRtrijetJetnotdijet;
   Float_t         HOTGoodTrijet1_csvJetnotdijet;
   Float_t         HOTGoodTrijet2_mass;
   Float_t         HOTGoodTrijet2_dijetmass;
   Float_t         HOTGoodTrijet2_pTratio;
   Float_t         HOTGoodTrijet2_dRtridijet;
   Float_t         HOTGoodTrijet2_dRtrijetJetnotdijet;
   Float_t         HOTGoodTrijet2_csvJetnotdijet;
   Float_t         HOTGoodTrijet3_mass;
   Float_t         HOTGoodTrijet3_dijetmass;
   Float_t         HOTGoodTrijet3_pTratio;
   Float_t         HOTGoodTrijet3_dRtridijet;
   Float_t         HOTGoodTrijet3_dRtrijetJetnotdijet;
   Float_t         HOTGoodTrijet3_csvJetnotdijet;
   Float_t         HOTGoodTrijet4_mass;
   Float_t         HOTGoodTrijet4_dijetmass;
   Float_t         HOTGoodTrijet4_pTratio;
   Float_t         HOTGoodTrijet4_dRtridijet;
   Float_t         HOTGoodTrijet4_dRtrijetJetnotdijet;
   Float_t         HOTGoodTrijet4_csvJetnotdijet;
   Float_t         HOTBadTrijet1_mass;
   Float_t         HOTBadTrijet1_dijetmass;
   Float_t         HOTBadTrijet1_pTratio;
   Float_t         HOTBadTrijet1_dRtridijet;
   Float_t         HOTBadTrijet1_dRtrijetJetnotdijet;
   Float_t         HOTBadTrijet1_csvJetnotdijet;
   Float_t         HOTBadTrijet2_mass;
   Float_t         HOTBadTrijet2_dijetmass;
   Float_t         HOTBadTrijet2_pTratio;
   Float_t         HOTBadTrijet2_dRtridijet;
   Float_t         HOTBadTrijet2_dRtrijetJetnotdijet;
   Float_t         HOTBadTrijet2_csvJetnotdijet;
   Float_t         HOTBadTrijet3_mass;
   Float_t         HOTBadTrijet3_dijetmass;
   Float_t         HOTBadTrijet3_pTratio;
   Float_t         HOTBadTrijet3_dRtridijet;
   Float_t         HOTBadTrijet3_dRtrijetJetnotdijet;
   Float_t         HOTBadTrijet3_csvJetnotdijet;
   Float_t         HOTBadTrijet4_mass;
   Float_t         HOTBadTrijet4_dijetmass;
   Float_t         HOTBadTrijet4_pTratio;
   Float_t         HOTBadTrijet4_dRtridijet;
   Float_t         HOTBadTrijet4_dRtrijetJetnotdijet;
   Float_t         HOTBadTrijet4_csvJetnotdijet;
 
   // Declaration of leaf types
   Long64_t        event_CommonCalc;
   Int_t           run_CommonCalc;
   Int_t           lumi_CommonCalc;
   Int_t           nTrueInteractions_MultiLepCalc;
   Int_t           isElectron;
   Int_t           isMuon;
   Int_t           MCPastTrigger;
   Int_t           DataPastTrigger;
   Int_t           MCPastTriggerX;
   Int_t           DataPastTriggerX;
   Int_t           MCLepPastTrigger;
   Int_t           DataLepPastTrigger;
   Int_t           MCHadPastTrigger;
   Int_t           DataHadPastTrigger;
   Double_t        L1NonPrefiringProb_CommonCalc;
   Double_t        L1NonPrefiringProbUp_CommonCalc;
   Double_t        L1NonPrefiringProbDown_CommonCalc;
   Double_t        MCWeight_MultiLepCalc;
   vector<double>  *renormWeights;
   vector<double>  *pdfWeights;
   vector<double>  *pdfNewWeights;
   Float_t         pdfNewNominalWeight;
   Float_t         pileupWeight;
   Float_t         pileupWeightUp;
   Float_t         pileupWeightDown;
   Float_t         HTSF_Pol;
   Float_t         HTSF_PolUp;
   Float_t         HTSF_PolDn;
   Float_t         topPtWeight13TeV;
   Float_t         EGammaGsfSF;
   Float_t         lepIdSF;
   Float_t         triggerSF;
   Float_t         isoSF;
   Double_t        ttbarMass_TTbarMassCalc;
   Float_t         genTopPt;
   Float_t         genAntiTopPt;
   Double_t        corr_met_MultiLepCalc;
   Double_t        corr_met_phi_MultiLepCalc;
   Double_t        corr_metmod_MultiLepCalc;
   Double_t        corr_metmod_phi_MultiLepCalc;
   Float_t         leptonPt_MultiLepCalc;
   Float_t         leptonEta_MultiLepCalc;
   Float_t         leptonPhi_MultiLepCalc;
   Float_t         leptonEnergy_MultiLepCalc;
   Float_t         leptonMVAValue_MultiLepCalc;
   Float_t         leptonMiniIso_MultiLepCalc;
   Float_t         leptonRelIso_MultiLepCalc;
   Float_t         triggerXSF;

//////////////ADD IN STEP1///////////////////
   vector<int>     *elMother_id_MultiLepCalc;
   vector<int>     *elNumberOfMothers_MultiLepCalc;
   vector<int>     *muMother_id_MultiLepCalc;
   vector<int>     *muNumberOfMothers_MultiLepCalc;  
   
   vector<double>  *topPt_TTbarMassCalc;
   vector<double>  *topEta_TTbarMassCalc;
   vector<double>  *topPhi_TTbarMassCalc;
   vector<double>  *topEnergy_TTbarMassCalc;         

   vector<int>  *topWID_TTbarMassCalc;
   vector<double>  *topWPt_TTbarMassCalc;
   vector<double>  *topWEta_TTbarMassCalc;
   vector<double>  *topWPhi_TTbarMassCalc;
   vector<double>  *topWEnergy_TTbarMassCalc;

   vector<int>  *topbID_TTbarMassCalc;
   vector<double>  *topbPt_TTbarMassCalc;
   vector<double>  *topbEta_TTbarMassCalc;
   vector<double>  *topbPhi_TTbarMassCalc;
   vector<double>  *topbEnergy_TTbarMassCalc; 
 //////////////ADD IN STEP1///////////////////
   
   Float_t         MT_lepMet;
   Float_t         MT_lepMetmod;
   Float_t         minDPhi_MetJet;


   Float_t         recLeptonicTopPt;
   Float_t         recLeptonicTopEta;
   Float_t         recLeptonicTopPhi;
   Float_t         recLeptonicTopMass;
   Int_t           recLeptonicTopJetIdx;
   Float_t         recLeptonicTopJetCSV;
   Float_t         recLeptonicTopJetPt;


   vector<double>  *theJetPt_JetSubCalc;
   vector<double>  *theJetEta_JetSubCalc;
   vector<double>  *theJetPhi_JetSubCalc;
   vector<double>  *theJetEnergy_JetSubCalc;
   vector<double>  *theJetDeepFlavB_JetSubCalc;
   vector<int>     *AK4JetBTag_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepCSVb_MultiLepCalc;
   vector<double>  *AK4JetDeepCSVbb_MultiLepCalc;
   vector<double>  *AK4JetDeepCSVc_MultiLepCalc;
   vector<double>  *AK4JetDeepCSVudsg_MultiLepCalc;
   vector<int>     *theJetIndex_JetSubCalc_PtOrdered;
   vector<double>  *theJetPt_JetSubCalc_PtOrdered;
   vector<double>  *theJetEta_JetSubCalc_PtOrdered;
   vector<double>  *theJetPhi_JetSubCalc_PtOrdered;
   vector<double>  *theJetEnergy_JetSubCalc_PtOrdered;
   vector<double>  *theJetDeepFlavB_JetSubCalc_PtOrdered;
//   vector<double>  *theJetDeepCSVb_JetSubCalc_PtOrdered;
//   vector<double>  *theJetDeepCSVbb_JetSubCalc_PtOrdered;
//   vector<double>  *theJetDeepCSVc_JetSubCalc_PtOrdered;
//   vector<double>  *theJetDeepCSVudsg_JetSubCalc_PtOrdered;
   vector<double>  *AK4JetDeepCSVb_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepCSVbb_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepCSVc_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepCSVudsg_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepFlavb_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepFlavbb_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepFlavc_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepFlavg_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered;
   vector<double>  *AK4JetDeepFlavuds_MultiLepCalc_PtOrdered;

   vector<int>     *theJetHFlav_JetSubCalc_PtOrdered;
   vector<int>     *theJetPFlav_JetSubCalc_PtOrdered;
   vector<int>     *theJetBTag_JetSubCalc_PtOrdered;
   Float_t         AK4HTpMETpLepPt;
   Float_t         AK4HT;
   Int_t           NJets_JetSubCalc;
   Float_t         NJets_JetSubCalc_float;
   Int_t           NJetsCSV_JetSubCalc;
   Int_t           NJetsCSVwithSF_JetSubCalc;
   Int_t           NJetsCSVwithSF_JetSubCalc_bSFup;
   Int_t           NJetsCSVwithSF_JetSubCalc_bSFdn;
   Int_t           NJetsCSVwithSF_JetSubCalc_lSFup;
   Int_t           NJetsCSVwithSF_JetSubCalc_lSFdn;
   Float_t         deltaR_lepMinMlb;
   Float_t         deltaR_lepMinMlb_bSFup;
   Float_t         deltaR_lepMinMlb_bSFdn;
   Float_t         deltaR_lepMinMlb_lSFup;
   Float_t         deltaR_lepMinMlb_lSFdn;
   Float_t         deltaR_lepMinMlj;
   Float_t         minMleppBjet;
   Float_t         minMleppBjet_bSFup;
   Float_t         minMleppBjet_bSFdn;
   Float_t         minMleppBjet_lSFup;
   Float_t         minMleppBjet_lSFdn;
   Float_t         minMleppJet;
   Float_t         minDR_lepJet;
   Float_t         ptRel_lepJet;
   vector<double>  *deltaR_lepJets;
   vector<double>  *deltaR_lepBJets;
   vector<double>  *deltaR_lepBJets_bSFup;
   vector<double>  *deltaR_lepBJets_bSFdn;
   vector<double>  *deltaR_lepBJets_lSFup;
   vector<double>  *deltaR_lepBJets_lSFdn;
   vector<double>  *genPt_MultiLepCalc;
   vector<double>  *genEta_MultiLepCalc;
   vector<double>  *genPhi_MultiLepCalc;
   vector<double>  *genEnergy_MultiLepCalc;
   vector<int>     *genStatus_MultiLepCalc;
   vector<int>     *genID_MultiLepCalc;
   vector<double>  *genJetPt_MultiLepCalc;
   vector<double>  *genJetEta_MultiLepCalc;
   vector<double>  *genJetPhi_MultiLepCalc;
   vector<double>  *genJetEnergy_MultiLepCalc;
   vector<int>     *genIndex_MultiLepCalc;
   vector<int>     *genMotherID_MultiLepCalc;
   vector<int>     *genMotherIndex_MultiLepCalc;
   vector<int>     *HadronicVHtID_JetSubCalc;
   vector<double>  *HadronicVHtPt_JetSubCalc;
   vector<double>  *HadronicVHtEta_JetSubCalc;
   vector<double>  *HadronicVHtPhi_JetSubCalc;
   vector<double>  *HadronicVHtEnergy_JetSubCalc;
   vector<int>     *theJetAK8Wmatch_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8Tmatch_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8Zmatch_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8Hmatch_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8MatchedPt_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8Truth_JetSubCalc_PtOrdered;
   Int_t           NJetsAK8_JetSubCalc;
   vector<double>  *theJetAK8Pt_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8Eta_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8Phi_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8Mass_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8Energy_JetSubCalc_PtOrdered;
   Float_t         minDR_leadAK8otherAK8;
   Float_t         minDR_lepAK8;
   Float_t         ptRel_lepAK8;
   vector<double>  *deltaR_lepAK8s;
   vector<int>     *maxProb_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8SoftDropRaw_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8SoftDropCorr_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8DoubleB_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8SoftDrop_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered;
   vector<double>  *theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered;
   vector<double>  *theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered;
   vector<double>  *theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered;
   vector<double>  *theJetAK8NjettinessTau1_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8NjettinessTau2_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8NjettinessTau3_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8CHSTau1_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8CHSTau2_JetSubCalc_PtOrdered;
   vector<double>  *theJetAK8CHSTau3_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8SDSubjetSize_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered;
   vector<int>     *theJetAK8Indx_Wtagged;
   Int_t           NJetsWtagged;
   Float_t 	   NJetsWtagged_float;
   vector<int>     *NJetsWtagged_shifts;
   Int_t           NJetsTtagged;
   Float_t 	   NJetsTtagged_float;
   vector<int>     *NJetsTtagged_shifts;
   vector<int>     *topJet1Index_HOTTaggerCalc;
   vector<int>     *topJet2Index_HOTTaggerCalc;
   vector<int>     *topJet3Index_HOTTaggerCalc;
   Int_t           topNAK4_HOTTaggerCalc;
   Int_t           topNtops_HOTTaggerCalc;
   vector<double>  *topDRmax_HOTTaggerCalc;
   vector<double>  *topDThetaMax_HOTTaggerCalc;
   vector<double>  *topDThetaMin_HOTTaggerCalc;
   vector<double>  *topDiscriminator_HOTTaggerCalc;
   vector<double>  *topEta_HOTTaggerCalc;
   vector<double>  *topMass_HOTTaggerCalc;
   vector<double>  *topNconstituents_HOTTaggerCalc;
   vector<double>  *topPhi_HOTTaggerCalc;
   vector<double>  *topPt_HOTTaggerCalc;
   vector<double>  *topType_HOTTaggerCalc;
   Int_t           NresolvedTops1pFake;
   Float_t 	   NresolvedTops1pFake_float;
   Int_t           NresolvedTops2pFake;
   Int_t           NresolvedTops5pFake;
   Int_t           NresolvedTops10pFake;
   Int_t           isHTgt500Njetge9;
   Float_t         BJetLeadPt;
   Float_t         BJetLeadPt_bSFup;
   Float_t         BJetLeadPt_bSFdn;
   Float_t         BJetLeadPt_lSFup;
   Float_t         BJetLeadPt_lSFdn;
   Float_t         WJetLeadPt;
   Float_t         TJetLeadPt;
   vector<int>     *genTtbarIdCategory_TTbarMassCalc;
   vector<double>  *renormPSWeights;
   vector<double>  *topMass_TTbarMassCalc;
   vector<int>     *topID_TTbarMassCalc;
   //vector<double>  *theJetDeepFlavB_JetSubCalc_PtOrdered;
   Int_t           NresolvedTops1pFakeNoSF;
   Int_t           NresolvedTops2pFakeNoSF;
   Int_t           NresolvedTops5pFakeNoSF;
   Int_t           NresolvedTops10pFakeNoSF;
   vector<int>     *NresolvedTops1pFake_shifts;
   vector<int>     *NresolvedTops2pFake_shifts;
   vector<int>     *NresolvedTops5pFake_shifts;
   vector<int>     *NresolvedTops10pFake_shifts;
//   vector<double>  *genJetPtNoClean_MultiLepCalc;
//   vector<double>  *genJetEtaNoClean_MultiLepCalc;
//   vector<double>  *genJetPhiNoClean_MultiLepCalc;
//   vector<double>  *genJetEnergyNoClean_MultiLepCalc;
   Int_t           NJetsCSV_MultiLepCalc;
   Int_t           NJetsCSVwithSF_MultiLepCalc;
   Float_t 	   NJetsCSVwithSF_MultiLepCalc_float;
   Int_t           NJetsCSVwithSF_MultiLepCalc_bSFup;
   Int_t           NJetsCSVwithSF_MultiLepCalc_bSFdn;
   Int_t           NJetsCSVwithSF_MultiLepCalc_lSFup;
   Int_t           NJetsCSVwithSF_MultiLepCalc_lSFdn;


   Float_t        BestTop_Discriminator;
   Float_t        BestTop_Pt;
   Float_t        BestTop_Phi;
   Float_t        BestTop_Eta;
   Float_t        BestTop_Mass;
  
   Float_t        NoTop_Jet1_CSV;
   Float_t        NoTop_Jet1_Pt;
   Float_t        NoTop_Jet1_Phi;
   Float_t        NoTop_Jet1_Eta;
   Float_t        NoTop_Jet1_Energy;
   
   Float_t        NoTop_Jet2_CSV;
   Float_t        NoTop_Jet2_Pt;
   Float_t        NoTop_Jet2_Phi;
   Float_t        NoTop_Jet2_Eta;
   Float_t        NoTop_Jet2_Energy;                 

   Float_t        LeptonicTB1_M;
   Float_t        LeptonicTB2_M;
   
   Float_t        LeptonicTB1_Pt;
   Float_t        LeptonicTB2_Pt;

   Float_t        LeptonicTB1_Eta;
   Float_t        LeptonicTB2_Eta;

   Float_t        HadronicTB1_M;
   Float_t        HadronicTB2_M;
  
   Float_t        HadronicTB1_Pt;
   Float_t        HadronicTB2_Pt; 
 
   Float_t        HadronicTB1_Eta;
   Float_t        HadronicTB2_Eta;


   // List of branches
   TBranch        *b_event_CommonCalc;   //!
   TBranch        *b_run_CommonCalc;   //!
   TBranch        *b_lumi_CommonCalc;   //!
   TBranch        *b_nTrueInteractions_MultiLepCalc;   //!
   TBranch        *b_isElectron;   //!
   TBranch        *b_isMuon;   //!
   TBranch        *b_MCPastTrigger;   //!
   TBranch        *b_DataPastTrigger;   //!
   TBranch        *b_L1NonPrefiringProb_CommonCalc;   //!
   TBranch        *b_L1NonPrefiringProbUp_CommonCalc;   //!
   TBranch        *b_L1NonPrefiringProbDown_CommonCalc;   //!
   TBranch        *b_MCWeight_MultiLepCalc;   //!
   TBranch        *b_renormWeights;   //!
   TBranch        *b_pdfWeights;   //!
   TBranch        *b_pdfNewWeights;   //!
   TBranch        *b_pdfNewNominalWeight;   //!
   TBranch        *b_pileupWeight;   //!
   TBranch        *b_pileupWeightUp;   //!
   TBranch        *b_pileupWeightDown;   //!
   TBranch        *b_HTSF_Pol;   //!
   TBranch        *b_HTSF_PolUp;   //!
   TBranch        *b_HTSF_PolDn;   //!
   TBranch        *b_topPtWeight13TeV;   //!
   TBranch        *b_EGammaGsfSF;   //!
   TBranch        *b_lepIdSF;   //!
   TBranch        *b_triggerSF;   //!
   TBranch        *b_isoSF;   //!
   TBranch        *b_ttbarMass_TTbarMassCalc;   //!
   TBranch        *b_genTopPt;   //!
   TBranch        *b_genAntiTopPt;   //!
   TBranch        *b_corr_met_MultiLepCalc;   //!
   TBranch        *b_corr_met_phi_MultiLepCalc;   //!
   TBranch        *b_corr_metmod_MultiLepCalc;   //!
   TBranch        *b_corr_metmod_phi_MultiLepCalc;   //!
   TBranch        *b_leptonPt_MultiLepCalc;   //!
   TBranch        *b_leptonEta_MultiLepCalc;   //!
   TBranch        *b_leptonPhi_MultiLepCalc;   //!
   TBranch        *b_leptonEnergy_MultiLepCalc;   //!
   TBranch        *b_leptonMVAValue_MultiLepCalc;   //!
   TBranch        *b_leptonMiniIso_MultiLepCalc;   //!
   TBranch        *b_leptonRelIso_MultiLepCalc;   //!
   TBranch        *b_MT_lepMet;   //!
   TBranch        *b_MT_lepMetmod;   //!
   TBranch        *b_minDPhi_MetJet;   //!
   TBranch        *b_theJetIndex_JetSubCalc_PtOrdered;
   TBranch        *b_theJetPt_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetEta_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetPhi_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetEnergy_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetDeepFlavB_JetSubCalc_PtOrdered; 
//   TBranch        *b_theJetDeepCSVb_JetSubCalc_PtOrdered;   //!
//   TBranch        *b_theJetDeepCSVbb_JetSubCalc_PtOrdered;   //!
//   TBranch        *b_theJetDeepCSVc_JetSubCalc_PtOrdered;   //!
//   TBranch        *b_theJetDeepCSVudsg_JetSubCalc_PtOrdered;   //!
   TBranch        *b_AK4JetDeepCSVb_MultiLepCalc_PtOrdered;   //! 
   TBranch        *b_AK4JetDeepCSVbb_MultiLepCalc_PtOrdered;  //!
   TBranch        *b_AK4JetDeepCSVc_MultiLepCalc_PtOrdered;   //!
   TBranch        *b_AK4JetDeepCSVudsg_MultiLepCalc_PtOrdered;  //!
   TBranch        *b_AK4JetDeepFlavb_MultiLepCalc_PtOrdered;
   TBranch        *b_AK4JetDeepFlavbb_MultiLepCalc_PtOrdered;
   TBranch        *b_AK4JetDeepFlavc_MultiLepCalc_PtOrdered;
   TBranch        *b_AK4JetDeepFlavg_MultiLepCalc_PtOrdered;
   TBranch        *b_AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered;
   TBranch        *b_AK4JetDeepFlavuds_MultiLepCalc_PtOrdered;
   TBranch        *b_theJetHFlav_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetPFlav_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetBTag_JetSubCalc_PtOrdered;   //!
   TBranch        *b_AK4HTpMETpLepPt;   //!
   TBranch        *b_AK4HT;   //!
   TBranch        *b_NJets_JetSubCalc;   //!
   TBranch        *b_NJetsCSV_JetSubCalc;   //!
   TBranch        *b_NJetsCSVwithSF_JetSubCalc;   //!
   TBranch        *b_NJetsCSVwithSF_JetSubCalc_bSFup;   //!
   TBranch        *b_NJetsCSVwithSF_JetSubCalc_bSFdn;   //!
   TBranch        *b_NJetsCSVwithSF_JetSubCalc_lSFup;   //!
   TBranch        *b_NJetsCSVwithSF_JetSubCalc_lSFdn;   //!
   TBranch        *b_deltaR_lepMinMlb;   //!
   TBranch        *b_deltaR_lepMinMlb_bSFup;   //!
   TBranch        *b_deltaR_lepMinMlb_bSFdn;   //!
   TBranch        *b_deltaR_lepMinMlb_lSFup;   //!
   TBranch        *b_deltaR_lepMinMlb_lSFdn;   //!
   TBranch        *b_deltaR_lepMinMlj;   //!
   TBranch        *b_minMleppBjet;   //!
   TBranch        *b_minMleppBjet_bSFup;   //!
   TBranch        *b_minMleppBjet_bSFdn;   //!
   TBranch        *b_minMleppBjet_lSFup;   //!
   TBranch        *b_minMleppBjet_lSFdn;   //!
   TBranch        *b_minMleppJet;   //!
   TBranch        *b_minDR_lepJet;   //!
   TBranch        *b_ptRel_lepJet;   //!
   TBranch        *b_deltaR_lepJets;   //!
   TBranch        *b_deltaR_lepBJets;   //!
   TBranch        *b_deltaR_lepBJets_bSFup;   //!
   TBranch        *b_deltaR_lepBJets_bSFdn;   //!
   TBranch        *b_deltaR_lepBJets_lSFup;   //!
   TBranch        *b_deltaR_lepBJets_lSFdn;   //!
   TBranch        *b_genPt_MultiLepCalc;   //!
   TBranch        *b_genEta_MultiLepCalc;   //!
   TBranch        *b_genPhi_MultiLepCalc;   //!
   TBranch        *b_genEnergy_MultiLepCalc;   //!
   TBranch        *b_genStatus_MultiLepCalc;   //!
   TBranch        *b_genID_MultiLepCalc;   //!
   TBranch        *b_genJetPt_MultiLepCalc;   //!
   TBranch        *b_genJetEta_MultiLepCalc;   //!
   TBranch        *b_genJetPhi_MultiLepCalc;   //!
   TBranch        *b_genJetEnergy_MultiLepCalc;   //!
   TBranch        *b_genIndex_MultiLepCalc;   //!
   TBranch        *b_genMotherID_MultiLepCalc;   //!
   TBranch        *b_genMotherIndex_MultiLepCalc;   //!
   TBranch        *b_HadronicVHtID_JetSubCalc;   //!
   TBranch        *b_HadronicVHtPt_JetSubCalc;   //!
   TBranch        *b_HadronicVHtEta_JetSubCalc;   //!
   TBranch        *b_HadronicVHtPhi_JetSubCalc;   //!
   TBranch        *b_HadronicVHtEnergy_JetSubCalc;   //!
   TBranch        *b_theJetAK8Wmatch_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Tmatch_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Zmatch_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Hmatch_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8MatchedPt_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Truth_JetSubCalc_PtOrdered;   //!
   TBranch        *b_NJetsAK8_JetSubCalc;   //!
   TBranch        *b_theJetAK8Pt_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Eta_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Phi_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Mass_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Energy_JetSubCalc_PtOrdered;   //!
   TBranch        *b_minDR_leadAK8otherAK8;   //!
   TBranch        *b_minDR_lepAK8;   //!
   TBranch        *b_ptRel_lepAK8;   //!
   TBranch        *b_deltaR_lepAK8s;   //!
   TBranch        *b_maxProb_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SoftDropRaw_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SoftDropCorr_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8DoubleB_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SoftDrop_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered;   //!
   TBranch        *b_theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered;   //!
   TBranch        *b_theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered;   //!
   TBranch        *b_theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered;   //!
   TBranch        *b_theJetAK8NjettinessTau1_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8NjettinessTau2_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8NjettinessTau3_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8CHSTau1_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8CHSTau2_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8CHSTau3_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SDSubjetSize_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered;   //!
   TBranch        *b_theJetAK8Indx_Wtagged;   //!
   TBranch        *b_NJetsWtagged;   //!
   TBranch        *b_NJetsWtagged_shifts;   //!
   TBranch        *b_NJetsTtagged;   //!
   TBranch        *b_NJetsTtagged_shifts;   //!
   TBranch        *b_topJet1Index_HOTTaggerCalc;   //!
   TBranch        *b_topJet2Index_HOTTaggerCalc;   //!
   TBranch        *b_topJet3Index_HOTTaggerCalc;   //!
   TBranch        *b_topNAK4_HOTTaggerCalc;   //!
   TBranch        *b_topNtops_HOTTaggerCalc;   //!
   TBranch        *b_topDRmax_HOTTaggerCalc;   //!
   TBranch        *b_topDThetaMax_HOTTaggerCalc;   //!
   TBranch        *b_topDThetaMin_HOTTaggerCalc;   //!
   TBranch        *b_topDiscriminator_HOTTaggerCalc;   //!
   TBranch        *b_topEta_HOTTaggerCalc;   //!
   TBranch        *b_topMass_HOTTaggerCalc;   //!
   TBranch        *b_topNconstituents_HOTTaggerCalc;   //!
   TBranch        *b_topPhi_HOTTaggerCalc;   //!
   TBranch        *b_topPt_HOTTaggerCalc;   //!
   TBranch        *b_topType_HOTTaggerCalc;   //!
   TBranch        *b_NresolvedTops1pFake;   //!
   TBranch        *b_NresolvedTops2pFake;   //!
   TBranch        *b_NresolvedTops5pFake;   //!
   TBranch        *b_NresolvedTops10pFake;   //!
   TBranch        *b_isHTgt500Njetge9;   //!
   TBranch        *b_BJetLeadPt;   //!
   TBranch        *b_BJetLeadPt_bSFup;   //!
   TBranch        *b_BJetLeadPt_bSFdn;   //!
   TBranch        *b_BJetLeadPt_lSFup;   //!
   TBranch        *b_BJetLeadPt_lSFdn;   //!
   TBranch        *b_WJetLeadPt;   //!
   TBranch        *b_TJetLeadPt;   //!
   TBranch        *b_genTtbarIdCategory_TTbarMassCalc;   //!
   TBranch        *b_renormPSWeights;   //!
   TBranch        *b_topEnergy_TTbarMassCalc;   //!
   TBranch        *b_topEta_TTbarMassCalc;   //!
   TBranch        *b_topMass_TTbarMassCalc;   //!
   TBranch        *b_topPhi_TTbarMassCalc;   //!
   TBranch        *b_topPt_TTbarMassCalc;   //!
   TBranch        *b_topID_TTbarMassCalc;   //!
   TBranch        *b_topWEnergy_TTbarMassCalc;   //!
   TBranch        *b_topWEta_TTbarMassCalc;   //!
   TBranch        *b_topWPhi_TTbarMassCalc;   //!
   TBranch        *b_topWPt_TTbarMassCalc;   //!
   TBranch        *b_topWID_TTbarMassCalc;   //!
   TBranch        *b_topbEnergy_TTbarMassCalc;   //!
   TBranch        *b_topbEta_TTbarMassCalc;   //!
   TBranch        *b_topbPhi_TTbarMassCalc;   //!
   TBranch        *b_topbPt_TTbarMassCalc;   //!
   TBranch        *b_topbID_TTbarMassCalc;   //!
   TBranch        *b_elMother_id_MultiLepCalc;   //!
   TBranch        *b_elNumberOfMothers_MultiLepCalc;   //!
   TBranch        *b_muMother_id_MultiLepCalc;   //!
   TBranch        *b_muNumberOfMothers_MultiLepCalc;   //!
   //TBranch        *b_theJetDeepFlavB_JetSubCalc_PtOrdered;   //!
   TBranch        *b_NresolvedTops1pFakeNoSF;   //!
   TBranch        *b_NresolvedTops2pFakeNoSF;   //!
   TBranch        *b_NresolvedTops5pFakeNoSF;   //!
   TBranch        *b_NresolvedTops10pFakeNoSF;   //!
   TBranch        *b_NresolvedTops1pFake_shifts;   //!
   TBranch        *b_NresolvedTops2pFake_shifts;   //!
   TBranch        *b_NresolvedTops5pFake_shifts;   //!
   TBranch        *b_NresolvedTops10pFake_shifts;   //!
//   TBranch        *b_genJetPtNoClean_MultiLepCalc;   //!
//   TBranch        *b_genJetEtaNoClean_MultiLepCalc;   //!
//   TBranch        *b_genJetPhiNoClean_MultiLepCalc;   //!
//   TBranch        *b_genJetEnergyNoClean_MultiLepCalc;   //!
   TBranch        *b_NJetsCSV_MultiLepCalc;   //!
   TBranch        *b_NJetsCSVwithSF_MultiLepCalc;   //!
   TBranch        *b_NJetsCSVwithSF_MultiLepCalc_bSFup;   //!
   TBranch        *b_NJetsCSVwithSF_MultiLepCalc_bSFdn;   //!
   TBranch        *b_NJetsCSVwithSF_MultiLepCalc_lSFup;   //!
   TBranch        *b_NJetsCSVwithSF_MultiLepCalc_lSFdn;   //!

   TBranch        *b_recLeptonicTopPt;
   TBranch        *b_recLeptonicTopEta;
   TBranch        *b_recLeptonicTopPhi;
   TBranch        *b_recLeptonicTopMass;
   TBranch        *b_recLeptonicTopJetIdx;

   TBranch        *b_theJetPt_JetSubCalc;   //!
   TBranch        *b_theJetEta_JetSubCalc;   //!
   TBranch        *b_theJetPhi_JetSubCalc;   //!
   TBranch        *b_theJetEnergy_JetSubCalc;   //!
   TBranch        *b_theJetDeepFlavB_JetSubCalc;
   TBranch        *b_AK4JetBTag_MultiLepCalc_PtOrdered;   //!
   TBranch        *b_AK4JetDeepCSVb_MultiLepCalc;   //!
   TBranch        *b_AK4JetDeepCSVbb_MultiLepCalc;   //!
   TBranch        *b_AK4JetDeepCSVc_MultiLepCalc;   //!
   TBranch        *b_AK4JetDeepCSVudsg_MultiLepCalc;   //!
   TBranch        *b_MCPastTriggerX;   //!
   TBranch        *b_DataPastTriggerX;   //!
   TBranch        *b_MCLepPastTrigger;   //!
   TBranch        *b_DataLepPastTrigger;   //!
   TBranch        *b_MCHadPastTrigger;   //!
   TBranch        *b_DataHadPastTrigger;   //!
   TBranch        *b_triggerXSF;   //!

   //TBranch        *b_BestTop_Discriminator;
   //TBranch        *b_BestTop_Pt;
   //TBranch        *b_BestTop_Phi;
   //TBranch        *b_BestTop_Eta;
   //TBranch        *b_BestTop_Mass;

   //TBranch        *b_NoTop_Jet1_CSV;
   //TBranch        *b_NoTop_Jet1_Pt;
   //TBranch        *b_NoTop_Jet1_Phi;
   //TBranch        *b_NoTop_Jet1_Eta;
   //TBranch        *b_NoTop_Jet1_Mass;

   //TBranch        *b_NoTop_Jet2_CSV;
   //TBranch        *b_NoTop_Jet2_Pt;
   //TBranch        *b_NoTop_Jet2_Phi;
   //TBranch        *b_NoTop_Jet2_Eta;
   //TBranch        *b_NoTop_Jet2_Mass;         



   step2(TString inputFileName, TString outputFileName);
   virtual ~step2();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef step2_cxx
step2::step2(TString inputFileName, TString outputFileName)// : inputTree(0), inputFile(0), outputFile(0) 
{   //weight branches to be used in the BDT training, xsecEff is the weight

   // TT bkg divided into TTToSemiLep, TTToHadronic, TT high mass appear below


   //Initialize SFs
   hardcodedConditions = S2HardcodedConditions();
   //TTToSemiLep
   if (inputFileName.Contains("TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt0to700")) xsecEff = 0.137784841012;
   else if (inputFileName.Contains("TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt1000toInf")) xsecEff = 0.0309363357165;
   else if (inputFileName.Contains("TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt700to1000")) xsecEff = 0.0514566653858;

   else if (inputFileName.Contains("TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_HT0Njet0")) xsecEff = 0.138647459815; 
   else if (inputFileName.Contains("TTToSemiLepton_HT500Njet9_TuneCP5_PSweights_13TeV-powheg-pythia8")) xsecEff = 0.00930297719566;
   else if (inputFileName.Contains("TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0")) xsecEff = 0.217217486269; // 2018
   else if (inputFileName.Contains("TTToSemiLepton_HT500Njet9_TuneCP5_13TeV-powheg-pythia8")) xsecEff = 0.0138805494029; // 2018
 
   //TTToHadronic
   else if (inputFileName.Contains("TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt0to700")) xsecEff =  0.121490806141;
   else if (inputFileName.Contains("TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt1000toInf")) xsecEff = 0.030031985381;
   else if (inputFileName.Contains("TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt700to1000")) xsecEff = 0.0490022856079;
   else if (inputFileName.Contains("TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8")) xsecEff = 0.122285168091;
   else if (inputFileName.Contains("TTToHadronic_TuneCP5_13TeV-powheg-pythia8")) xsecEff = 0.172212015144; // 2018 

   //TTTo2l2nu
   else if (inputFileName.Contains("TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt0to700")) xsecEff = 0.0525799344238;
   else if (inputFileName.Contains("TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt1000toInf")) xsecEff = 0.0226832371713;
   else if (inputFileName.Contains("TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8_Mtt700to1000")) xsecEff = 0.0320566270444;
   else if (inputFileName.Contains("TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8")) xsecEff =  0.0529890846128;
   else if (inputFileName.Contains("TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8")) xsecEff = 0.0821029333006; // 2018
   //TT high mass 
   else if (inputFileName.Contains("TT_Mtt-1000toInf_TuneCP5_PSweights_13TeV-powheg-pythia8")) xsecEff = 0.0294081434678;
   else if (inputFileName.Contains("TT_Mtt-700to1000_TuneCP5_13TeV-powheg-pythia8")) xsecEff = 0.0473629131251;
   
   //TTTT signal below
   
   else if (inputFileName.Contains("TTTT_TuneCP5_PSweights_13TeV-amcatnlo-pythia8")) xsecEff = 0.000586330715183; 
   else if (inputFileName.Contains("TTTT_TuneCP5_13TeV-amcatnlo-pythia8")) xsecEff = 0.000815849917354; // 2018
   //For everything else, just have this branch be dummy at the moment, 1 will do nothing
   else xsecEff = 1.0;
   isTTbar = false;
   isTTTT = false;
   if (inputFileName.Contains("TT_")) isTTbar = true;      
   else if (inputFileName.Contains("TTTo")) isTTbar = true;      
   else if (inputFileName.Contains("TTTT")) isTTTT = true;        

   isST = (inputFileName.Contains("ST_t-channel") || inputFileName.Contains("ST_tW") || inputFileName.Contains("ST_s-channel"));
   isSTs = inputFileName.Contains("ST_s-channel");
   isSTt = inputFileName.Contains("ST_t-channel");
   isSTtw = inputFileName.Contains("ST_tW");
   isTTBB = inputFileName.Contains("_ttbb");
   isTT2B = inputFileName.Contains("_tt2b");
   isTT1B = inputFileName.Contains("_tt1b");
   isTTCC = inputFileName.Contains("_ttcc");
   isTTLF = inputFileName.Contains("_ttjj");
   isCHM200 = (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-200"));  
   isCHM220 = (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-220"));
   isCHM250 = (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-250"));
   isCHM300 = (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-300"));
   isCHM350 = (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-350"));
   isCHM400 = (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-400"));
   isCHM500 = (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-500"));
   isCHM600 = (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-600"));
   isCHM700 = (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-700"));
   isCHM800 = (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-800"));
   isCHM1000= (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-1000"));
   isCHM1250= (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-1250"));
   isCHM1500= (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-1500"));
   isCHM1750= (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-1750"));
   isCHM2000= (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-2000"));
   isCHM2500= (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-2500"));
   isCHM3000= (inputFileName.Contains("ChargedHiggs") && inputFileName.Contains("M-3000"));


   
   //isWJets = inputFileName.BeginsWith("WJetsToLNu");

  sample_ = inputFileName;
  Int_t slash = sample_.Last('/');
  sample_.Remove(0,slash+1);
  Int_t uscore = sample_.Last('_');
  Int_t thelength = sample_.Length();
  sample_.Remove(uscore,thelength);
  isWJets = sample_.BeginsWith("WJetsToLNu");
  sample = (std::string)sample_;   

    
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
//    if (tree == 0) {
//       TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("TTTT_TuneCP5_13TeV-amcatnlo-pythia8_hadd.root");
//       if (!f || !f->IsOpen()) {
//          f = new TFile("TTTT_TuneCP5_13TeV-amcatnlo-pythia8_hadd.root");
//       }
//       f->GetObject("ljmet",tree);
// 
//    } 

//   inputFile=new TFile(inputFileName);
  if(!(inputFile=TFile::Open(inputFileName))){
    std::cout<<"WARNING! File doesn't exist! Exiting" << std::endl;
    exit(1);
   }

   inputTree = (TTree*)inputFile->Get("ljmet");  
   inputTree->SetBranchStatus("*",1);   
   Init(inputTree);
   outputFile = new TFile(outputFileName,"RECREATE");   
}

step2::~step2()
{
   if (!inputTree) return;
   delete inputTree->GetCurrentFile();
}

Int_t step2::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!inputTree) return 0;
   return inputTree->GetEntry(entry);
}
Long64_t step2::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!inputTree) return -5;
   Long64_t centry = inputTree->LoadTree(entry);
   if (centry < 0) return centry;
   if (inputTree->GetTreeNumber() != fCurrent) {
      fCurrent = inputTree->GetTreeNumber();
      Notify();
   }
   return centry;
}

void step2::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).


   // Set object pointer
   renormWeights = 0;
   pdfWeights = 0;
   pdfNewWeights = 0;
   theJetIndex_JetSubCalc_PtOrdered = 0;
   theJetPt_JetSubCalc_PtOrdered = 0;
   theJetEta_JetSubCalc_PtOrdered = 0;
   theJetPhi_JetSubCalc_PtOrdered = 0;
   theJetEnergy_JetSubCalc_PtOrdered = 0;
   theJetDeepFlavB_JetSubCalc_PtOrdered = 0;
//   theJetDeepCSVb_JetSubCalc_PtOrdered = 0;
//   theJetDeepCSVbb_JetSubCalc_PtOrdered = 0;
//   theJetDeepCSVc_JetSubCalc_PtOrdered = 0;
//   theJetDeepCSVudsg_JetSubCalc_PtOrdered = 0;
   AK4JetDeepCSVb_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepCSVbb_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepCSVc_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepCSVudsg_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepFlavb_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepFlavbb_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepFlavc_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepFlavg_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepFlavuds_MultiLepCalc_PtOrdered = 0;
  
   theJetHFlav_JetSubCalc_PtOrdered = 0;
   theJetPFlav_JetSubCalc_PtOrdered = 0;
   theJetBTag_JetSubCalc_PtOrdered = 0;
   deltaR_lepJets = 0;
   deltaR_lepBJets = 0;
   deltaR_lepBJets_bSFup = 0;
   deltaR_lepBJets_bSFdn = 0;
   deltaR_lepBJets_lSFup = 0;
   deltaR_lepBJets_lSFdn = 0;
   genPt_MultiLepCalc = 0;
   genEta_MultiLepCalc = 0;
   genPhi_MultiLepCalc = 0;
   genEnergy_MultiLepCalc = 0;
   genStatus_MultiLepCalc = 0;
   genID_MultiLepCalc = 0;
   genJetPt_MultiLepCalc = 0;
   genJetEta_MultiLepCalc = 0;
   genJetPhi_MultiLepCalc = 0;
   genJetEnergy_MultiLepCalc = 0;
   genIndex_MultiLepCalc = 0;
   genMotherID_MultiLepCalc = 0;
   genMotherIndex_MultiLepCalc = 0;
   HadronicVHtID_JetSubCalc = 0;
   HadronicVHtPt_JetSubCalc = 0;
   HadronicVHtEta_JetSubCalc = 0;
   HadronicVHtPhi_JetSubCalc = 0;
   HadronicVHtEnergy_JetSubCalc = 0;
   theJetAK8Wmatch_JetSubCalc_PtOrdered = 0;
   theJetAK8Tmatch_JetSubCalc_PtOrdered = 0;
   theJetAK8Zmatch_JetSubCalc_PtOrdered = 0;
   theJetAK8Hmatch_JetSubCalc_PtOrdered = 0;
   theJetAK8MatchedPt_JetSubCalc_PtOrdered = 0;
   theJetAK8Truth_JetSubCalc_PtOrdered = 0;
   theJetAK8Pt_JetSubCalc_PtOrdered = 0;
   theJetAK8Eta_JetSubCalc_PtOrdered = 0;
   theJetAK8Phi_JetSubCalc_PtOrdered = 0;
   theJetAK8Mass_JetSubCalc_PtOrdered = 0;
   theJetAK8Energy_JetSubCalc_PtOrdered = 0;
   deltaR_lepAK8s = 0;
   maxProb_JetSubCalc_PtOrdered = 0;
   theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered = 0;
   theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered = 0;
   theJetAK8SoftDropRaw_JetSubCalc_PtOrdered = 0;
   theJetAK8SoftDropCorr_JetSubCalc_PtOrdered = 0;
   theJetAK8DoubleB_JetSubCalc_PtOrdered = 0;
   theJetAK8SoftDrop_JetSubCalc_PtOrdered = 0;
   theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered = 0;
   theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered = 0;
   theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered = 0;
   theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered = 0;
   theJetAK8NjettinessTau1_JetSubCalc_PtOrdered = 0;
   theJetAK8NjettinessTau2_JetSubCalc_PtOrdered = 0;
   theJetAK8NjettinessTau3_JetSubCalc_PtOrdered = 0;
   theJetAK8CHSTau1_JetSubCalc_PtOrdered = 0;
   theJetAK8CHSTau2_JetSubCalc_PtOrdered = 0;
   theJetAK8CHSTau3_JetSubCalc_PtOrdered = 0;
   theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered = 0;
   theJetAK8SDSubjetSize_JetSubCalc_PtOrdered = 0;
   theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered = 0;
   theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered = 0;
   theJetAK8Indx_Wtagged = 0;
   NJetsWtagged_shifts = 0;
   NJetsTtagged_shifts = 0;
   topJet1Index_HOTTaggerCalc = 0;
   topJet2Index_HOTTaggerCalc = 0;
   topJet3Index_HOTTaggerCalc = 0;
   topDRmax_HOTTaggerCalc = 0;
   topDThetaMax_HOTTaggerCalc = 0;
   topDThetaMin_HOTTaggerCalc = 0;
   topDiscriminator_HOTTaggerCalc = 0;
   topEta_HOTTaggerCalc = 0;
   topMass_HOTTaggerCalc = 0;
   topNconstituents_HOTTaggerCalc = 0;
   topPhi_HOTTaggerCalc = 0;
   topPt_HOTTaggerCalc = 0;
   topType_HOTTaggerCalc = 0;
   genTtbarIdCategory_TTbarMassCalc = 0;
   topEnergy_TTbarMassCalc = 0;
   topEta_TTbarMassCalc = 0;
   topMass_TTbarMassCalc = 0;
   topPhi_TTbarMassCalc = 0;
   topPt_TTbarMassCalc = 0;
   topID_TTbarMassCalc = 0;
   topWEnergy_TTbarMassCalc = 0;
   topWEta_TTbarMassCalc = 0;
   topWPhi_TTbarMassCalc = 0;
   topWPt_TTbarMassCalc = 0;
   topWID_TTbarMassCalc = 0;
   topbEnergy_TTbarMassCalc = 0;
   topbEta_TTbarMassCalc = 0;
   topbPhi_TTbarMassCalc = 0;
   topbPt_TTbarMassCalc = 0;
   topbID_TTbarMassCalc = 0;
   elMother_id_MultiLepCalc = 0;
   elNumberOfMothers_MultiLepCalc = 0;
   muMother_id_MultiLepCalc = 0;
   muNumberOfMothers_MultiLepCalc = 0;
   NresolvedTops1pFake_shifts = 0;
   NresolvedTops2pFake_shifts = 0;
   NresolvedTops5pFake_shifts = 0;
   NresolvedTops10pFake_shifts = 0;
   renormPSWeights = 0;
//   genJetPtNoClean_MultiLepCalc = 0;
//   genJetEtaNoClean_MultiLepCalc = 0;
//   genJetPhiNoClean_MultiLepCalc = 0;
//   genJetEnergyNoClean_MultiLepCalc = 0;
   
   recLeptonicTopPt = 0;
   recLeptonicTopEta = 0;
   recLeptonicTopPhi = 0;
   recLeptonicTopMass = 0;
   recLeptonicTopJetIdx = 0;


   theJetPt_JetSubCalc = 0;
   theJetEta_JetSubCalc = 0;
   theJetPhi_JetSubCalc = 0;
   theJetEnergy_JetSubCalc = 0;
   theJetDeepFlavB_JetSubCalc = 0;
   AK4JetBTag_MultiLepCalc_PtOrdered = 0;
   AK4JetDeepCSVb_MultiLepCalc = 0;
   AK4JetDeepCSVbb_MultiLepCalc = 0;
   AK4JetDeepCSVc_MultiLepCalc = 0;
   AK4JetDeepCSVudsg_MultiLepCalc = 0;


   // Set branch addresses and branch pointers
   if (!tree) return;
   inputTree = tree;
   fCurrent = -1;
   // inputTree->SetMakeClass(1);  // ? why

   inputTree->SetBranchAddress("event_CommonCalc", &event_CommonCalc, &b_event_CommonCalc);
   inputTree->SetBranchAddress("run_CommonCalc", &run_CommonCalc, &b_run_CommonCalc);
   inputTree->SetBranchAddress("lumi_CommonCalc", &lumi_CommonCalc, &b_lumi_CommonCalc);
   inputTree->SetBranchAddress("nTrueInteractions_MultiLepCalc", &nTrueInteractions_MultiLepCalc, &b_nTrueInteractions_MultiLepCalc);
   inputTree->SetBranchAddress("isElectron", &isElectron, &b_isElectron);
   inputTree->SetBranchAddress("isMuon", &isMuon, &b_isMuon);
   inputTree->SetBranchAddress("MCPastTrigger", &MCPastTrigger, &b_MCPastTrigger);
   inputTree->SetBranchAddress("DataPastTrigger", &DataPastTrigger, &b_DataPastTrigger);
   inputTree->SetBranchAddress("L1NonPrefiringProb_CommonCalc", &L1NonPrefiringProb_CommonCalc, &b_L1NonPrefiringProb_CommonCalc);
   inputTree->SetBranchAddress("L1NonPrefiringProbUp_CommonCalc", &L1NonPrefiringProbUp_CommonCalc, &b_L1NonPrefiringProbUp_CommonCalc);
   inputTree->SetBranchAddress("L1NonPrefiringProbDown_CommonCalc", &L1NonPrefiringProbDown_CommonCalc, &b_L1NonPrefiringProbDown_CommonCalc);
   inputTree->SetBranchAddress("MCWeight_MultiLepCalc", &MCWeight_MultiLepCalc, &b_MCWeight_MultiLepCalc);
   inputTree->SetBranchAddress("renormWeights", &renormWeights, &b_renormWeights);
   inputTree->SetBranchAddress("pdfWeights", &pdfWeights, &b_pdfWeights);
   inputTree->SetBranchAddress("pdfNewWeights", &pdfNewWeights, &b_pdfNewWeights);
   inputTree->SetBranchAddress("pdfNewNominalWeight", &pdfNewNominalWeight, &b_pdfNewNominalWeight);
   inputTree->SetBranchAddress("pileupWeight", &pileupWeight, &b_pileupWeight);
   inputTree->SetBranchAddress("pileupWeightUp", &pileupWeightUp, &b_pileupWeightUp);
   inputTree->SetBranchAddress("pileupWeightDown", &pileupWeightDown, &b_pileupWeightDown);
   inputTree->SetBranchAddress("HTSF_Pol", &HTSF_Pol, &b_HTSF_Pol);
   inputTree->SetBranchAddress("HTSF_PolUp", &HTSF_PolUp, &b_HTSF_PolUp);
   inputTree->SetBranchAddress("HTSF_PolDn", &HTSF_PolDn, &b_HTSF_PolDn);
   inputTree->SetBranchAddress("topPtWeight13TeV", &topPtWeight13TeV, &b_topPtWeight13TeV);
   inputTree->SetBranchAddress("EGammaGsfSF", &EGammaGsfSF, &b_EGammaGsfSF);
   inputTree->SetBranchAddress("lepIdSF", &lepIdSF, &b_lepIdSF);
   inputTree->SetBranchAddress("triggerSF", &triggerSF, &b_triggerSF);
   inputTree->SetBranchAddress("isoSF", &isoSF, &b_isoSF);
   inputTree->SetBranchAddress("ttbarMass_TTbarMassCalc", &ttbarMass_TTbarMassCalc, &b_ttbarMass_TTbarMassCalc);
   inputTree->SetBranchAddress("genTopPt", &genTopPt, &b_genTopPt);
   inputTree->SetBranchAddress("genAntiTopPt", &genAntiTopPt, &b_genAntiTopPt);
   inputTree->SetBranchAddress("corr_met_MultiLepCalc", &corr_met_MultiLepCalc, &b_corr_met_MultiLepCalc);
   inputTree->SetBranchAddress("corr_met_phi_MultiLepCalc", &corr_met_phi_MultiLepCalc, &b_corr_met_phi_MultiLepCalc);
   inputTree->SetBranchAddress("corr_metmod_MultiLepCalc", &corr_metmod_MultiLepCalc, &b_corr_metmod_MultiLepCalc);
   inputTree->SetBranchAddress("corr_metmod_phi_MultiLepCalc", &corr_metmod_phi_MultiLepCalc, &b_corr_metmod_phi_MultiLepCalc);
   inputTree->SetBranchAddress("leptonPt_MultiLepCalc", &leptonPt_MultiLepCalc, &b_leptonPt_MultiLepCalc);
   inputTree->SetBranchAddress("leptonEta_MultiLepCalc", &leptonEta_MultiLepCalc, &b_leptonEta_MultiLepCalc);
   inputTree->SetBranchAddress("leptonPhi_MultiLepCalc", &leptonPhi_MultiLepCalc, &b_leptonPhi_MultiLepCalc);
   inputTree->SetBranchAddress("leptonEnergy_MultiLepCalc", &leptonEnergy_MultiLepCalc, &b_leptonEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("leptonMVAValue_MultiLepCalc", &leptonMVAValue_MultiLepCalc, &b_leptonMVAValue_MultiLepCalc);
   inputTree->SetBranchAddress("leptonMiniIso_MultiLepCalc", &leptonMiniIso_MultiLepCalc, &b_leptonMiniIso_MultiLepCalc);
   inputTree->SetBranchAddress("leptonRelIso_MultiLepCalc", &leptonRelIso_MultiLepCalc, &b_leptonRelIso_MultiLepCalc);
   inputTree->SetBranchAddress("MT_lepMet", &MT_lepMet, &b_MT_lepMet);
   inputTree->SetBranchAddress("MT_lepMetmod", &MT_lepMetmod, &b_MT_lepMetmod);
   inputTree->SetBranchAddress("minDPhi_MetJet", &minDPhi_MetJet, &b_minDPhi_MetJet);
   inputTree->SetBranchAddress("theJetIndex_JetSubCalc_PtOrdered", &theJetIndex_JetSubCalc_PtOrdered, &b_theJetIndex_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetPt_JetSubCalc_PtOrdered", &theJetPt_JetSubCalc_PtOrdered, &b_theJetPt_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetEta_JetSubCalc_PtOrdered", &theJetEta_JetSubCalc_PtOrdered, &b_theJetEta_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetPhi_JetSubCalc_PtOrdered", &theJetPhi_JetSubCalc_PtOrdered, &b_theJetPhi_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetEnergy_JetSubCalc_PtOrdered", &theJetEnergy_JetSubCalc_PtOrdered, &b_theJetEnergy_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetDeepFlavB_JetSubCalc_PtOrdered", &theJetDeepFlavB_JetSubCalc_PtOrdered, &b_theJetDeepFlavB_JetSubCalc_PtOrdered);
//   inputTree->SetBranchAddress("theJetDeepCSVb_JetSubCalc_PtOrdered", &theJetDeepCSVb_JetSubCalc_PtOrdered, &b_theJetDeepCSVb_JetSubCalc_PtOrdered);
//   inputTree->SetBranchAddress("theJetDeepCSVbb_JetSubCalc_PtOrdered", &theJetDeepCSVbb_JetSubCalc_PtOrdered, &b_theJetDeepCSVbb_JetSubCalc_PtOrdered);
//   inputTree->SetBranchAddress("theJetDeepCSVc_JetSubCalc_PtOrdered", &theJetDeepCSVc_JetSubCalc_PtOrdered, &b_theJetDeepCSVc_JetSubCalc_PtOrdered);
//   inputTree->SetBranchAddress("theJetDeepCSVudsg_JetSubCalc_PtOrdered", &theJetDeepCSVudsg_JetSubCalc_PtOrdered, &b_theJetDeepCSVudsg_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepCSVb_MultiLepCalc_PtOrdered", &AK4JetDeepCSVb_MultiLepCalc_PtOrdered, &b_AK4JetDeepCSVb_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepCSVbb_MultiLepCalc_PtOrdered", &AK4JetDeepCSVbb_MultiLepCalc_PtOrdered, &b_AK4JetDeepCSVbb_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepCSVc_MultiLepCalc_PtOrdered", &AK4JetDeepCSVc_MultiLepCalc_PtOrdered, &b_AK4JetDeepCSVc_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepCSVudsg_MultiLepCalc_PtOrdered", &AK4JetDeepCSVudsg_MultiLepCalc_PtOrdered, &b_AK4JetDeepCSVudsg_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepFlavb_MultiLepCalc_PtOrdered", &AK4JetDeepFlavb_MultiLepCalc_PtOrdered, &b_AK4JetDeepFlavb_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepFlavbb_MultiLepCalc_PtOrdered", &AK4JetDeepFlavbb_MultiLepCalc_PtOrdered, &b_AK4JetDeepFlavbb_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepFlavc_MultiLepCalc_PtOrdered", &AK4JetDeepFlavc_MultiLepCalc_PtOrdered, &b_AK4JetDeepFlavc_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepFlavg_MultiLepCalc_PtOrdered", &AK4JetDeepFlavg_MultiLepCalc_PtOrdered, &b_AK4JetDeepFlavg_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered", &AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered, &b_AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepFlavuds_MultiLepCalc_PtOrdered", &AK4JetDeepFlavuds_MultiLepCalc_PtOrdered, &b_AK4JetDeepFlavuds_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetHFlav_JetSubCalc_PtOrdered", &theJetHFlav_JetSubCalc_PtOrdered, &b_theJetHFlav_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetPFlav_JetSubCalc_PtOrdered", &theJetPFlav_JetSubCalc_PtOrdered, &b_theJetPFlav_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetBTag_JetSubCalc_PtOrdered", &theJetBTag_JetSubCalc_PtOrdered, &b_theJetBTag_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4HTpMETpLepPt", &AK4HTpMETpLepPt, &b_AK4HTpMETpLepPt);
   inputTree->SetBranchAddress("AK4HT", &AK4HT, &b_AK4HT);
   inputTree->SetBranchAddress("NJets_JetSubCalc", &NJets_JetSubCalc, &b_NJets_JetSubCalc);
   inputTree->SetBranchAddress("NJetsCSV_JetSubCalc", &NJetsCSV_JetSubCalc, &b_NJetsCSV_JetSubCalc);
   inputTree->SetBranchAddress("NJetsCSVwithSF_JetSubCalc", &NJetsCSVwithSF_JetSubCalc, &b_NJetsCSVwithSF_JetSubCalc);
   inputTree->SetBranchAddress("NJetsCSVwithSF_JetSubCalc_bSFup", &NJetsCSVwithSF_JetSubCalc_bSFup, &b_NJetsCSVwithSF_JetSubCalc_bSFup);
   inputTree->SetBranchAddress("NJetsCSVwithSF_JetSubCalc_bSFdn", &NJetsCSVwithSF_JetSubCalc_bSFdn, &b_NJetsCSVwithSF_JetSubCalc_bSFdn);
   inputTree->SetBranchAddress("NJetsCSVwithSF_JetSubCalc_lSFup", &NJetsCSVwithSF_JetSubCalc_lSFup, &b_NJetsCSVwithSF_JetSubCalc_lSFup);
   inputTree->SetBranchAddress("NJetsCSVwithSF_JetSubCalc_lSFdn", &NJetsCSVwithSF_JetSubCalc_lSFdn, &b_NJetsCSVwithSF_JetSubCalc_lSFdn);
   inputTree->SetBranchAddress("deltaR_lepMinMlb", &deltaR_lepMinMlb, &b_deltaR_lepMinMlb);
   inputTree->SetBranchAddress("deltaR_lepMinMlb_bSFup", &deltaR_lepMinMlb_bSFup, &b_deltaR_lepMinMlb_bSFup);
   inputTree->SetBranchAddress("deltaR_lepMinMlb_bSFdn", &deltaR_lepMinMlb_bSFdn, &b_deltaR_lepMinMlb_bSFdn);
   inputTree->SetBranchAddress("deltaR_lepMinMlb_lSFup", &deltaR_lepMinMlb_lSFup, &b_deltaR_lepMinMlb_lSFup);
   inputTree->SetBranchAddress("deltaR_lepMinMlb_lSFdn", &deltaR_lepMinMlb_lSFdn, &b_deltaR_lepMinMlb_lSFdn);
   inputTree->SetBranchAddress("deltaR_lepMinMlj", &deltaR_lepMinMlj, &b_deltaR_lepMinMlj);
   inputTree->SetBranchAddress("minMleppBjet", &minMleppBjet, &b_minMleppBjet);
   inputTree->SetBranchAddress("minMleppBjet_bSFup", &minMleppBjet_bSFup, &b_minMleppBjet_bSFup);
   inputTree->SetBranchAddress("minMleppBjet_bSFdn", &minMleppBjet_bSFdn, &b_minMleppBjet_bSFdn);
   inputTree->SetBranchAddress("minMleppBjet_lSFup", &minMleppBjet_lSFup, &b_minMleppBjet_lSFup);
   inputTree->SetBranchAddress("minMleppBjet_lSFdn", &minMleppBjet_lSFdn, &b_minMleppBjet_lSFdn);
   inputTree->SetBranchAddress("minMleppJet", &minMleppJet, &b_minMleppJet);
   inputTree->SetBranchAddress("minDR_lepJet", &minDR_lepJet, &b_minDR_lepJet);
   inputTree->SetBranchAddress("ptRel_lepJet", &ptRel_lepJet, &b_ptRel_lepJet);
   inputTree->SetBranchAddress("deltaR_lepJets", &deltaR_lepJets, &b_deltaR_lepJets);
   inputTree->SetBranchAddress("deltaR_lepBJets", &deltaR_lepBJets, &b_deltaR_lepBJets);
   inputTree->SetBranchAddress("deltaR_lepBJets_bSFup", &deltaR_lepBJets_bSFup, &b_deltaR_lepBJets_bSFup);
   inputTree->SetBranchAddress("deltaR_lepBJets_bSFdn", &deltaR_lepBJets_bSFdn, &b_deltaR_lepBJets_bSFdn);
   inputTree->SetBranchAddress("deltaR_lepBJets_lSFup", &deltaR_lepBJets_lSFup, &b_deltaR_lepBJets_lSFup);
   inputTree->SetBranchAddress("deltaR_lepBJets_lSFdn", &deltaR_lepBJets_lSFdn, &b_deltaR_lepBJets_lSFdn);
   inputTree->SetBranchAddress("genPt_MultiLepCalc", &genPt_MultiLepCalc, &b_genPt_MultiLepCalc);
   inputTree->SetBranchAddress("genEta_MultiLepCalc", &genEta_MultiLepCalc, &b_genEta_MultiLepCalc);
   inputTree->SetBranchAddress("genPhi_MultiLepCalc", &genPhi_MultiLepCalc, &b_genPhi_MultiLepCalc);
   inputTree->SetBranchAddress("genEnergy_MultiLepCalc", &genEnergy_MultiLepCalc, &b_genEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("genStatus_MultiLepCalc", &genStatus_MultiLepCalc, &b_genStatus_MultiLepCalc);
   inputTree->SetBranchAddress("genID_MultiLepCalc", &genID_MultiLepCalc, &b_genID_MultiLepCalc);
   inputTree->SetBranchAddress("genJetPt_MultiLepCalc", &genJetPt_MultiLepCalc, &b_genJetPt_MultiLepCalc);
   inputTree->SetBranchAddress("genJetEta_MultiLepCalc", &genJetEta_MultiLepCalc, &b_genJetEta_MultiLepCalc);
   inputTree->SetBranchAddress("genJetPhi_MultiLepCalc", &genJetPhi_MultiLepCalc, &b_genJetPhi_MultiLepCalc);
   inputTree->SetBranchAddress("genJetEnergy_MultiLepCalc", &genJetEnergy_MultiLepCalc, &b_genJetEnergy_MultiLepCalc);
   inputTree->SetBranchAddress("genIndex_MultiLepCalc", &genIndex_MultiLepCalc, &b_genIndex_MultiLepCalc);
   inputTree->SetBranchAddress("genMotherID_MultiLepCalc", &genMotherID_MultiLepCalc, &b_genMotherID_MultiLepCalc);
   inputTree->SetBranchAddress("genMotherIndex_MultiLepCalc", &genMotherIndex_MultiLepCalc, &b_genMotherIndex_MultiLepCalc);
   inputTree->SetBranchAddress("HadronicVHtID_JetSubCalc", &HadronicVHtID_JetSubCalc, &b_HadronicVHtID_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtPt_JetSubCalc", &HadronicVHtPt_JetSubCalc, &b_HadronicVHtPt_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtEta_JetSubCalc", &HadronicVHtEta_JetSubCalc, &b_HadronicVHtEta_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtPhi_JetSubCalc", &HadronicVHtPhi_JetSubCalc, &b_HadronicVHtPhi_JetSubCalc);
   inputTree->SetBranchAddress("HadronicVHtEnergy_JetSubCalc", &HadronicVHtEnergy_JetSubCalc, &b_HadronicVHtEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Wmatch_JetSubCalc_PtOrdered", &theJetAK8Wmatch_JetSubCalc_PtOrdered, &b_theJetAK8Wmatch_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Tmatch_JetSubCalc_PtOrdered", &theJetAK8Tmatch_JetSubCalc_PtOrdered, &b_theJetAK8Tmatch_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Zmatch_JetSubCalc_PtOrdered", &theJetAK8Zmatch_JetSubCalc_PtOrdered, &b_theJetAK8Zmatch_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Hmatch_JetSubCalc_PtOrdered", &theJetAK8Hmatch_JetSubCalc_PtOrdered, &b_theJetAK8Hmatch_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8MatchedPt_JetSubCalc_PtOrdered", &theJetAK8MatchedPt_JetSubCalc_PtOrdered, &b_theJetAK8MatchedPt_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Truth_JetSubCalc_PtOrdered", &theJetAK8Truth_JetSubCalc_PtOrdered, &b_theJetAK8Truth_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("NJetsAK8_JetSubCalc", &NJetsAK8_JetSubCalc, &b_NJetsAK8_JetSubCalc);
   inputTree->SetBranchAddress("theJetAK8Pt_JetSubCalc_PtOrdered", &theJetAK8Pt_JetSubCalc_PtOrdered, &b_theJetAK8Pt_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Eta_JetSubCalc_PtOrdered", &theJetAK8Eta_JetSubCalc_PtOrdered, &b_theJetAK8Eta_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Phi_JetSubCalc_PtOrdered", &theJetAK8Phi_JetSubCalc_PtOrdered, &b_theJetAK8Phi_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Mass_JetSubCalc_PtOrdered", &theJetAK8Mass_JetSubCalc_PtOrdered, &b_theJetAK8Mass_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Energy_JetSubCalc_PtOrdered", &theJetAK8Energy_JetSubCalc_PtOrdered, &b_theJetAK8Energy_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("minDR_leadAK8otherAK8", &minDR_leadAK8otherAK8, &b_minDR_leadAK8otherAK8);
   inputTree->SetBranchAddress("minDR_lepAK8", &minDR_lepAK8, &b_minDR_lepAK8);
   inputTree->SetBranchAddress("ptRel_lepAK8", &ptRel_lepAK8, &b_ptRel_lepAK8);
   inputTree->SetBranchAddress("deltaR_lepAK8s", &deltaR_lepAK8s, &b_deltaR_lepAK8s);
   inputTree->SetBranchAddress("maxProb_JetSubCalc_PtOrdered", &maxProb_JetSubCalc_PtOrdered, &b_maxProb_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered", &theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered, &b_theJetAK8CHSPrunedMass_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered", &theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered, &b_theJetAK8CHSSoftDropMass_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SoftDropRaw_JetSubCalc_PtOrdered", &theJetAK8SoftDropRaw_JetSubCalc_PtOrdered, &b_theJetAK8SoftDropRaw_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SoftDropCorr_JetSubCalc_PtOrdered", &theJetAK8SoftDropCorr_JetSubCalc_PtOrdered, &b_theJetAK8SoftDropCorr_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8DoubleB_JetSubCalc_PtOrdered", &theJetAK8DoubleB_JetSubCalc_PtOrdered, &b_theJetAK8DoubleB_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SoftDrop_JetSubCalc_PtOrdered", &theJetAK8SoftDrop_JetSubCalc_PtOrdered, &b_theJetAK8SoftDrop_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered", &theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered, &b_theJetAK8SoftDrop_JetSubCalc_JMRup_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered", &theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered, &b_theJetAK8SoftDrop_JetSubCalc_JMRdn_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered", &theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered, &b_theJetAK8SoftDrop_JetSubCalc_JMSup_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered", &theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered, &b_theJetAK8SoftDrop_JetSubCalc_JMSdn_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8NjettinessTau1_JetSubCalc_PtOrdered", &theJetAK8NjettinessTau1_JetSubCalc_PtOrdered, &b_theJetAK8NjettinessTau1_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8NjettinessTau2_JetSubCalc_PtOrdered", &theJetAK8NjettinessTau2_JetSubCalc_PtOrdered, &b_theJetAK8NjettinessTau2_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8NjettinessTau3_JetSubCalc_PtOrdered", &theJetAK8NjettinessTau3_JetSubCalc_PtOrdered, &b_theJetAK8NjettinessTau3_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8CHSTau1_JetSubCalc_PtOrdered", &theJetAK8CHSTau1_JetSubCalc_PtOrdered, &b_theJetAK8CHSTau1_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8CHSTau2_JetSubCalc_PtOrdered", &theJetAK8CHSTau2_JetSubCalc_PtOrdered, &b_theJetAK8CHSTau2_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8CHSTau3_JetSubCalc_PtOrdered", &theJetAK8CHSTau3_JetSubCalc_PtOrdered, &b_theJetAK8CHSTau3_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered", &theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered, &b_theJetAK8SDSubjetIndex_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SDSubjetSize_JetSubCalc_PtOrdered", &theJetAK8SDSubjetSize_JetSubCalc_PtOrdered, &b_theJetAK8SDSubjetSize_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered", &theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered, &b_theJetAK8SDSubjetNDeepCSVMSF_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered", &theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered, &b_theJetAK8SDSubjetNDeepCSVL_JetSubCalc_PtOrdered);
   inputTree->SetBranchAddress("theJetAK8Indx_Wtagged", &theJetAK8Indx_Wtagged, &b_theJetAK8Indx_Wtagged);
   inputTree->SetBranchAddress("NJetsWtagged", &NJetsWtagged, &b_NJetsWtagged);
   inputTree->SetBranchAddress("NJetsWtagged_shifts", &NJetsWtagged_shifts, &b_NJetsWtagged_shifts);
   inputTree->SetBranchAddress("NJetsTtagged", &NJetsTtagged, &b_NJetsTtagged);
   inputTree->SetBranchAddress("NJetsTtagged_shifts", &NJetsTtagged_shifts, &b_NJetsTtagged_shifts);
   inputTree->SetBranchAddress("topJet1Index_HOTTaggerCalc", &topJet1Index_HOTTaggerCalc, &b_topJet1Index_HOTTaggerCalc);
   inputTree->SetBranchAddress("topJet2Index_HOTTaggerCalc", &topJet2Index_HOTTaggerCalc, &b_topJet2Index_HOTTaggerCalc);
   inputTree->SetBranchAddress("topJet3Index_HOTTaggerCalc", &topJet3Index_HOTTaggerCalc, &b_topJet3Index_HOTTaggerCalc);
   inputTree->SetBranchAddress("topNAK4_HOTTaggerCalc", &topNAK4_HOTTaggerCalc, &b_topNAK4_HOTTaggerCalc);
   inputTree->SetBranchAddress("topNtops_HOTTaggerCalc", &topNtops_HOTTaggerCalc, &b_topNtops_HOTTaggerCalc);
   inputTree->SetBranchAddress("topDRmax_HOTTaggerCalc", &topDRmax_HOTTaggerCalc, &b_topDRmax_HOTTaggerCalc);
   inputTree->SetBranchAddress("topDThetaMax_HOTTaggerCalc", &topDThetaMax_HOTTaggerCalc, &b_topDThetaMax_HOTTaggerCalc);
   inputTree->SetBranchAddress("topDThetaMin_HOTTaggerCalc", &topDThetaMin_HOTTaggerCalc, &b_topDThetaMin_HOTTaggerCalc);
   inputTree->SetBranchAddress("topDiscriminator_HOTTaggerCalc", &topDiscriminator_HOTTaggerCalc, &b_topDiscriminator_HOTTaggerCalc);
   inputTree->SetBranchAddress("topEta_HOTTaggerCalc", &topEta_HOTTaggerCalc, &b_topEta_HOTTaggerCalc);
   inputTree->SetBranchAddress("topMass_HOTTaggerCalc", &topMass_HOTTaggerCalc, &b_topMass_HOTTaggerCalc);
   inputTree->SetBranchAddress("topNconstituents_HOTTaggerCalc", &topNconstituents_HOTTaggerCalc, &b_topNconstituents_HOTTaggerCalc);
   inputTree->SetBranchAddress("topPhi_HOTTaggerCalc", &topPhi_HOTTaggerCalc, &b_topPhi_HOTTaggerCalc);
   inputTree->SetBranchAddress("topPt_HOTTaggerCalc", &topPt_HOTTaggerCalc, &b_topPt_HOTTaggerCalc);
   inputTree->SetBranchAddress("topType_HOTTaggerCalc", &topType_HOTTaggerCalc, &b_topType_HOTTaggerCalc);
   inputTree->SetBranchAddress("NresolvedTops1pFake", &NresolvedTops1pFake, &b_NresolvedTops1pFake);
   inputTree->SetBranchAddress("NresolvedTops2pFake", &NresolvedTops2pFake, &b_NresolvedTops2pFake);
   inputTree->SetBranchAddress("NresolvedTops5pFake", &NresolvedTops5pFake, &b_NresolvedTops5pFake);
   inputTree->SetBranchAddress("NresolvedTops10pFake", &NresolvedTops10pFake, &b_NresolvedTops10pFake);
   inputTree->SetBranchAddress("isHTgt500Njetge9", &isHTgt500Njetge9, &b_isHTgt500Njetge9);
   inputTree->SetBranchAddress("BJetLeadPt", &BJetLeadPt, &b_BJetLeadPt);
   inputTree->SetBranchAddress("BJetLeadPt_bSFup", &BJetLeadPt_bSFup, &b_BJetLeadPt_bSFup);
   inputTree->SetBranchAddress("BJetLeadPt_bSFdn", &BJetLeadPt_bSFdn, &b_BJetLeadPt_bSFdn);
   inputTree->SetBranchAddress("BJetLeadPt_lSFup", &BJetLeadPt_lSFup, &b_BJetLeadPt_lSFup);
   inputTree->SetBranchAddress("BJetLeadPt_lSFdn", &BJetLeadPt_lSFdn, &b_BJetLeadPt_lSFdn);
   inputTree->SetBranchAddress("WJetLeadPt", &WJetLeadPt, &b_WJetLeadPt);
   inputTree->SetBranchAddress("TJetLeadPt", &TJetLeadPt, &b_TJetLeadPt);
   inputTree->SetBranchAddress("genTtbarIdCategory_TTbarMassCalc", &genTtbarIdCategory_TTbarMassCalc, &b_genTtbarIdCategory_TTbarMassCalc);
   inputTree->SetBranchAddress("renormPSWeights", &renormPSWeights, &b_renormPSWeights);
   inputTree->SetBranchAddress("topEnergy_TTbarMassCalc", &topEnergy_TTbarMassCalc, &b_topEnergy_TTbarMassCalc);
   inputTree->SetBranchAddress("topEta_TTbarMassCalc", &topEta_TTbarMassCalc, &b_topEta_TTbarMassCalc);
   inputTree->SetBranchAddress("topMass_TTbarMassCalc", &topMass_TTbarMassCalc, &b_topMass_TTbarMassCalc);
   inputTree->SetBranchAddress("topPhi_TTbarMassCalc", &topPhi_TTbarMassCalc, &b_topPhi_TTbarMassCalc);
   inputTree->SetBranchAddress("topPt_TTbarMassCalc", &topPt_TTbarMassCalc, &b_topPt_TTbarMassCalc);
   inputTree->SetBranchAddress("topID_TTbarMassCalc", &topID_TTbarMassCalc, &b_topID_TTbarMassCalc);
   inputTree->SetBranchAddress("topWEnergy_TTbarMassCalc", &topWEnergy_TTbarMassCalc, &b_topWEnergy_TTbarMassCalc);
   inputTree->SetBranchAddress("topWEta_TTbarMassCalc", &topWEta_TTbarMassCalc, &b_topWEta_TTbarMassCalc);
   inputTree->SetBranchAddress("topWPhi_TTbarMassCalc", &topWPhi_TTbarMassCalc, &b_topWPhi_TTbarMassCalc);
   inputTree->SetBranchAddress("topWPt_TTbarMassCalc", &topWPt_TTbarMassCalc, &b_topWPt_TTbarMassCalc);
   inputTree->SetBranchAddress("topWID_TTbarMassCalc", &topWID_TTbarMassCalc, &b_topWID_TTbarMassCalc);
   inputTree->SetBranchAddress("topbEnergy_TTbarMassCalc", &topbEnergy_TTbarMassCalc, &b_topbEnergy_TTbarMassCalc);
   inputTree->SetBranchAddress("topbEta_TTbarMassCalc", &topbEta_TTbarMassCalc, &b_topbEta_TTbarMassCalc);
   inputTree->SetBranchAddress("topbPhi_TTbarMassCalc", &topbPhi_TTbarMassCalc, &b_topbPhi_TTbarMassCalc);
   inputTree->SetBranchAddress("topbPt_TTbarMassCalc", &topbPt_TTbarMassCalc, &b_topbPt_TTbarMassCalc);
   inputTree->SetBranchAddress("topbID_TTbarMassCalc", &topbID_TTbarMassCalc, &b_topbID_TTbarMassCalc);
   inputTree->SetBranchAddress("elMother_id_MultiLepCalc", &elMother_id_MultiLepCalc, &b_elMother_id_MultiLepCalc);
   inputTree->SetBranchAddress("elNumberOfMothers_MultiLepCalc", &elNumberOfMothers_MultiLepCalc, &b_elNumberOfMothers_MultiLepCalc);
   inputTree->SetBranchAddress("muMother_id_MultiLepCalc", &muMother_id_MultiLepCalc, &b_muMother_id_MultiLepCalc);
   inputTree->SetBranchAddress("muNumberOfMothers_MultiLepCalc", &muNumberOfMothers_MultiLepCalc, &b_muNumberOfMothers_MultiLepCalc);
   inputTree->SetBranchAddress("NresolvedTops1pFakeNoSF", &NresolvedTops1pFakeNoSF, &b_NresolvedTops1pFakeNoSF);
   inputTree->SetBranchAddress("NresolvedTops2pFakeNoSF", &NresolvedTops2pFakeNoSF, &b_NresolvedTops2pFakeNoSF);
   inputTree->SetBranchAddress("NresolvedTops5pFakeNoSF", &NresolvedTops5pFakeNoSF, &b_NresolvedTops5pFakeNoSF);
   inputTree->SetBranchAddress("NresolvedTops10pFakeNoSF", &NresolvedTops10pFakeNoSF, &b_NresolvedTops10pFakeNoSF);
   inputTree->SetBranchAddress("NresolvedTops1pFake_shifts", &NresolvedTops1pFake_shifts, &b_NresolvedTops1pFake_shifts);
   inputTree->SetBranchAddress("NresolvedTops2pFake_shifts", &NresolvedTops2pFake_shifts, &b_NresolvedTops2pFake_shifts);
   inputTree->SetBranchAddress("NresolvedTops5pFake_shifts", &NresolvedTops5pFake_shifts, &b_NresolvedTops5pFake_shifts);
   inputTree->SetBranchAddress("NresolvedTops10pFake_shifts", &NresolvedTops10pFake_shifts, &b_NresolvedTops10pFake_shifts);
//   inputTree->SetBranchAddress("genJetPtNoClean_MultiLepCalc", &genJetPtNoClean_MultiLepCalc, &b_genJetPtNoClean_MultiLepCalc);
//   inputTree->SetBranchAddress("genJetEtaNoClean_MultiLepCalc", &genJetEtaNoClean_MultiLepCalc, &b_genJetEtaNoClean_MultiLepCalc);
//   inputTree->SetBranchAddress("genJetPhiNoClean_MultiLepCalc", &genJetPhiNoClean_MultiLepCalc, &b_genJetPhiNoClean_MultiLepCalc);
//   inputTree->SetBranchAddress("genJetEnergyNoClean_MultiLepCalc", &genJetEnergyNoClean_MultiLepCalc, &b_genJetEnergyNoClean_MultiLepCalc);
   inputTree->SetBranchAddress("NJetsCSV_MultiLepCalc", &NJetsCSV_MultiLepCalc, &b_NJetsCSV_MultiLepCalc);
   inputTree->SetBranchAddress("NJetsCSVwithSF_MultiLepCalc", &NJetsCSVwithSF_MultiLepCalc, &b_NJetsCSVwithSF_MultiLepCalc);
   inputTree->SetBranchAddress("NJetsCSVwithSF_MultiLepCalc_bSFup", &NJetsCSVwithSF_MultiLepCalc_bSFup, &b_NJetsCSVwithSF_MultiLepCalc_bSFup);
   inputTree->SetBranchAddress("NJetsCSVwithSF_MultiLepCalc_bSFdn", &NJetsCSVwithSF_MultiLepCalc_bSFdn, &b_NJetsCSVwithSF_MultiLepCalc_bSFdn);
   inputTree->SetBranchAddress("NJetsCSVwithSF_MultiLepCalc_lSFup", &NJetsCSVwithSF_MultiLepCalc_lSFup, &b_NJetsCSVwithSF_MultiLepCalc_lSFup);
   inputTree->SetBranchAddress("NJetsCSVwithSF_MultiLepCalc_lSFdn", &NJetsCSVwithSF_MultiLepCalc_lSFdn, &b_NJetsCSVwithSF_MultiLepCalc_lSFdn);
   inputTree->SetBranchAddress("recLeptonicTopPt", &recLeptonicTopPt, &b_recLeptonicTopPt);
   inputTree->SetBranchAddress("recLeptonicTopEta", &recLeptonicTopEta, &b_recLeptonicTopEta);
   inputTree->SetBranchAddress("recLeptonicTopPhi", &recLeptonicTopPhi, &b_recLeptonicTopPhi);
   inputTree->SetBranchAddress("recLeptonicTopMass", &recLeptonicTopMass, &b_recLeptonicTopMass);
   inputTree->SetBranchAddress("recLeptonicTopJetIdx", &recLeptonicTopJetIdx, &b_recLeptonicTopJetIdx);
   inputTree->SetBranchAddress("theJetPt_JetSubCalc", &theJetPt_JetSubCalc, &b_theJetPt_JetSubCalc);
   inputTree->SetBranchAddress("theJetEta_JetSubCalc", &theJetEta_JetSubCalc, &b_theJetEta_JetSubCalc);
   inputTree->SetBranchAddress("theJetPhi_JetSubCalc", &theJetPhi_JetSubCalc, &b_theJetPhi_JetSubCalc);
   inputTree->SetBranchAddress("theJetEnergy_JetSubCalc", &theJetEnergy_JetSubCalc, &b_theJetEnergy_JetSubCalc);
   inputTree->SetBranchAddress("theJetDeepFlavB_JetSubCalc", &theJetDeepFlavB_JetSubCalc, &b_theJetDeepFlavB_JetSubCalc);
   inputTree->SetBranchAddress("AK4JetBTag_MultiLepCalc_PtOrdered", &AK4JetBTag_MultiLepCalc_PtOrdered, &b_AK4JetBTag_MultiLepCalc_PtOrdered);
   inputTree->SetBranchAddress("AK4JetDeepCSVb_MultiLepCalc", &AK4JetDeepCSVb_MultiLepCalc, &b_AK4JetDeepCSVb_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetDeepCSVbb_MultiLepCalc", &AK4JetDeepCSVbb_MultiLepCalc, &b_AK4JetDeepCSVbb_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetDeepCSVc_MultiLepCalc", &AK4JetDeepCSVc_MultiLepCalc, &b_AK4JetDeepCSVc_MultiLepCalc);
   inputTree->SetBranchAddress("AK4JetDeepCSVudsg_MultiLepCalc", &AK4JetDeepCSVudsg_MultiLepCalc, &b_AK4JetDeepCSVudsg_MultiLepCalc);
   inputTree->SetBranchAddress("MCPastTriggerX", &MCPastTriggerX, &b_MCPastTriggerX);
   inputTree->SetBranchAddress("DataPastTriggerX", &DataPastTriggerX, &b_DataPastTriggerX);
   inputTree->SetBranchAddress("MCLepPastTrigger", &MCLepPastTrigger, &b_MCLepPastTrigger);
   inputTree->SetBranchAddress("DataLepPastTrigger", &DataLepPastTrigger, &b_DataLepPastTrigger);
   inputTree->SetBranchAddress("MCHadPastTrigger", &MCHadPastTrigger, &b_MCHadPastTrigger);
   inputTree->SetBranchAddress("DataHadPastTrigger", &DataHadPastTrigger, &b_DataHadPastTrigger);
   inputTree->SetBranchAddress("triggerXSF", &triggerXSF, &b_triggerXSF);


   Notify();
}

Bool_t step2::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void step2::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!inputTree) return;
   inputTree->Show(entry);
}
Int_t step2::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef step2_cxx
