#define step2_cxx
#include "step2.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <fstream>
#include <iostream>	// std::cout
#include <algorithm>	// std::sort
#include <TRandom.h>
#include <TRandom3.h>
#include <sstream>
#include <string>
#include <vector>
#include "TMath.h"
#include <cmath>
#include <TMatrixD.h>
#include <TVectorT.h>
#include "TROOT.h"
#include "Davismt2.h"
#include "S2HardcodedConditions.h"
#include <bits/stdc++.h> 

using namespace std;

const double MTOP  = 173.5;
const double MW    = 80.4;
TLorentzVector Wlv;


void Trijet(
vector<TLorentzVector> &v_trijet, 
vector<double> &v_DCSV_trijet, 
vector<TLorentzVector> &v_allJets, 
vector<double> &v_DCSV_allJets,

vector<TLorentzVector>& v_GD_Trijets,                    
vector<TLorentzVector>& v_GD_jets,                     
vector<double>& v_GD_DCSV_jets,                          

vector<TLorentzVector>& v_BD_Trijets,                   
vector<TLorentzVector>& v_BD_jets,                       
vector<double>& v_BD_DCSV_jets,                            

vector<double>* topPt_TTbarMassCalc,

vector<int>* topWID_TTbarMassCalc,
vector<double>* topWPt_TTbarMassCalc,
vector<double>* topWEta_TTbarMassCalc,
vector<double>* topWPhi_TTbarMassCalc,
vector<double>* topWEnergy_TTbarMassCalc,

vector<double>* topbPt_TTbarMassCalc,
vector<double>* topbEta_TTbarMassCalc,
vector<double>* topbPhi_TTbarMassCalc,
vector<double>* topbEnergy_TTbarMassCalc, 

int& num_GD_trijet,
int& num_BD_trijet
){
    std::string bitmask(3,1);
    bitmask.resize(v_allJets.size(),0);
    std::vector<double> v_deltalR; 

    TLorentzVector tempGenTop;
    TLorentzVector tempGenTopWd1, tempGenTopWd2;    
    TLorentzVector tempGenTopb;
    int idx_minDR = -10;
           
    do {
        v_trijet.clear();
        v_DCSV_trijet.clear();

        for(unsigned int njet = 0; njet < v_allJets.size(); ++njet){
            if(bitmask[njet]) {
                v_trijet.push_back(v_allJets[njet]);
                v_DCSV_trijet.push_back(v_DCSV_allJets[njet]);
            } 
        }
        bitset<9> tempbit9set;        
        std::vector<bitset<9>> v_bit9set;
        std::vector<Double_t> v_flipDeltaR;

        v_bit9set.clear();
        v_flipDeltaR.clear();
        
        int matchedTopIdx = 0;        
        for(unsigned int njet = 0; njet < 3; ++njet){
            v_deltalR.clear();
            tempbit9set.reset();                
            for(unsigned int nTop = 0; nTop < topPt_TTbarMassCalc->size(); nTop++){
                if(abs(topWID_TTbarMassCalc->at(nTop*2)) > 6 || abs(topWID_TTbarMassCalc->at(nTop*2+1)) > 6){ 
                    continue; 
                }
                tempGenTopWd1.SetPtEtaPhiE(topWPt_TTbarMassCalc->at(nTop*2),topWEta_TTbarMassCalc->at(nTop*2),topWPhi_TTbarMassCalc->at(nTop*2),topWEnergy_TTbarMassCalc->at(nTop*2));	
                tempGenTopWd2.SetPtEtaPhiE(topWPt_TTbarMassCalc->at(nTop*2+1),topWEta_TTbarMassCalc->at(nTop*2+1),topWPhi_TTbarMassCalc->at(nTop*2+1),topWEnergy_TTbarMassCalc->at(nTop*2+1));	        
                tempGenTopb.SetPtEtaPhiE(topbPt_TTbarMassCalc->at(nTop),topbEta_TTbarMassCalc->at(nTop),topbPhi_TTbarMassCalc->at(nTop),topbEnergy_TTbarMassCalc->at(nTop));
                v_deltalR.push_back(v_trijet[njet].DeltaR(tempGenTopWd1));                                                            
                v_deltalR.push_back(v_trijet[njet].DeltaR(tempGenTopWd2));                                                            
                v_deltalR.push_back(v_trijet[njet].DeltaR(tempGenTopb));
            }
            idx_minDR = std::distance(v_deltalR.begin(), std::min_element(v_deltalR.begin(), v_deltalR.end()));
            if(v_deltalR[idx_minDR]<0.5){
                tempbit9set.flip(idx_minDR);
            }
            v_flipDeltaR.push_back(v_deltalR[idx_minDR]);
            v_bit9set.push_back(tempbit9set);
        }
        bitset<9> bit9set;        
        bit9set = (v_bit9set[0]|v_bit9set[1])|v_bit9set[2];             ///////////////// a complete bitset for a trijet /////////////////                 
        if(bit9set.test(0)*bit9set.test(1)*bit9set.test(2) || bit9set.test(3)*bit9set.test(4)*bit9set.test(5) || bit9set.test(6)*bit9set.test(7)*bit9set.test(8)){
            v_GD_Trijets.push_back(v_trijet[0]+v_trijet[1]+v_trijet[2]);
            v_GD_jets.push_back(v_trijet[0]);
            v_GD_jets.push_back(v_trijet[1]);
            v_GD_jets.push_back(v_trijet[2]);
            v_GD_DCSV_jets.push_back(v_DCSV_trijet[0]);                        
            v_GD_DCSV_jets.push_back(v_DCSV_trijet[1]);                        
            v_GD_DCSV_jets.push_back(v_DCSV_trijet[2]);                                                
            num_GD_trijet++;
        }
        else {
            num_BD_trijet++;
            v_BD_Trijets.push_back(v_trijet[0]+v_trijet[1]+v_trijet[2]);
            v_BD_jets.push_back(v_trijet[0]);
            v_BD_jets.push_back(v_trijet[1]);
            v_BD_jets.push_back(v_trijet[2]);
            v_BD_DCSV_jets.push_back(v_DCSV_trijet[0]);                        
            v_BD_DCSV_jets.push_back(v_DCSV_trijet[1]);                        
            v_BD_DCSV_jets.push_back(v_DCSV_trijet[2]);                                                                
        }
    } while(std::prev_permutation(bitmask.begin(), bitmask.end()));       
}


TMatrixD SpheAplaTensor(const vector<TLorentzVector> allJets){
      TMatrixD MomentumTensor(3,3); 
      Double_t p2_sum=0.0;
      for(unsigned int njet = 0; njet < allJets.size(); ++njet){
        MomentumTensor(0, 0) += allJets[njet].Px()*allJets[njet].Px();
        MomentumTensor(0, 1) += allJets[njet].Px()*allJets[njet].Py();
        MomentumTensor(0, 2) += allJets[njet].Px()*allJets[njet].Pz();
        MomentumTensor(1, 0) += allJets[njet].Py()*allJets[njet].Px();
        MomentumTensor(1, 1) += allJets[njet].Py()*allJets[njet].Py();
        MomentumTensor(1, 2) += allJets[njet].Py()*allJets[njet].Pz();
        MomentumTensor(2, 0) += allJets[njet].Pz()*allJets[njet].Px();
        MomentumTensor(2, 1) += allJets[njet].Pz()*allJets[njet].Py();
        MomentumTensor(2, 2) += allJets[njet].Pz()*allJets[njet].Pz();
        p2_sum += allJets[njet].Px()*allJets[njet].Px()+allJets[njet].Py()*allJets[njet].Py()+allJets[njet].Pz()*allJets[njet].Pz();
      }
      if (p2_sum != 0){
          MomentumTensor(0, 0) /= p2_sum;
          MomentumTensor(0, 1) /= p2_sum;
          MomentumTensor(0, 2) /= p2_sum;
          MomentumTensor(1, 0) /= p2_sum;
          MomentumTensor(1, 1) /= p2_sum;
          MomentumTensor(1, 2) /= p2_sum;
          MomentumTensor(2, 0) /= p2_sum;
          MomentumTensor(2, 1) /= p2_sum;
          MomentumTensor(2, 2) /= p2_sum;
      }
      TVectorD *_pv = new TVectorD(3);
      return MomentumTensor;
}

bool compareFunc(const pair<TLorentzVector, double> &a, const pair<TLorentzVector, double> &b){
    return (a.second > b.second);
}

float mt2( const TLorentzVector visa,  const TLorentzVector visb,  const TLorentzVector metVec)
{

    Davismt2 davismt2;
    const double mn = 0.; // neutrino mass
    // Format: M, px, py
    double visaVector[3] = { visa.M() , visa.Px(), visa.Py() };
    double visbVector[3] = { visb.M(), visb.Px(), visb.Py() };
    double metVector[3] = { mn, metVec.Px(), metVec.Py() };

    davismt2.set_momenta(visaVector,visbVector,metVector);
    davismt2.set_mn(mn);

    return davismt2.get_mt2();

}

TLorentzVector bestJet( const double corr_met_phi, 
                        const double corr_met, 
                        const double lepMass, 
                        const TLorentzVector lepVector, 
                        const vector<double>* theJetPt_PtOrdered,
                        const vector<double>* theJetEta_PtOrdered,
                        const vector<double>* theJetPhi_PtOrdered,
                        const vector<double>* theJetEnergy_PtOrdered                                                
                        ){
      double metpx = corr_met*cos(corr_met_phi);
      double metpy = corr_met*sin(corr_met_phi);
      double metpt = corr_met;

      double Dtmp = (MW*MW)-(lepMass*lepMass)+2*((lepVector.Px())*(metpx)+(lepVector.Py())*(metpy));
      double Atmp = 4.0*((lepVector.Energy())*(lepVector.Energy())-(lepVector.Pz())*(lepVector.Pz()));
      double Btmp = -4.0*Dtmp*(lepVector.Pz());
      double Ctmp = 4.0*(lepVector.Energy())*(lepVector.Energy())*(metpt)*(metpt)-Dtmp*Dtmp;
      
      double nuPz_1;
      double nuPz_2;
      
      double DETtmp = Btmp*Btmp-4.0*Atmp*Ctmp;
      
      TLorentzVector Wlv_1, Wlv_2, lvTop, lvXTF;
      if(DETtmp >= 0) {
        nuPz_1 = (-Btmp+TMath::Sqrt(DETtmp))/(2.0*Atmp);
        nuPz_2 = (-Btmp-TMath::Sqrt(DETtmp))/(2.0*Atmp);
        TLorentzVector Nulv_1(metpx,metpy,nuPz_1,TMath::Sqrt((metpt)*(metpt)+(nuPz_1)*(nuPz_1)));
        TLorentzVector Nulv_2(metpx,metpy,nuPz_2,TMath::Sqrt((metpt)*(metpt)+(nuPz_2)*(nuPz_2)));
        Wlv_1 = Nulv_1+lepVector;
        Wlv_2 = Nulv_2+lepVector;
      }
      if(DETtmp < 0) {
        nuPz_1 = (-Btmp)/(2.0*Atmp);
        nuPz_2 = (-Btmp)/(2.0*Atmp);
        double alpha = (lepVector.Px())*(metpx)/(metpt)+(lepVector.Py())*(metpy)/(metpt);
        double Delta = (MW*MW)-(lepMass*lepMass);
        Atmp = 4.0*((lepVector.Pz())*(lepVector.Pz())-(lepVector.Energy())*(lepVector.Energy())+(alpha*alpha));
        Btmp = 4.0*alpha*Delta;
        Ctmp = Delta*Delta;
        DETtmp = Btmp*Btmp-4.0*Atmp*Ctmp;
        double pTnu_1 = (-Btmp+TMath::Sqrt(DETtmp))/(2.0*Atmp);
        double pTnu_2 = (-Btmp-TMath::Sqrt(DETtmp))/(2.0*Atmp);
        TLorentzVector Nulv_1(metpx*(pTnu_1)/(metpt),metpy*(pTnu_1)/(metpt),nuPz_1,TMath::Sqrt((pTnu_1)*(pTnu_1)+(nuPz_1)*(nuPz_1)));
        TLorentzVector Nulv_2(metpx*(pTnu_2)/(metpt),metpy*(pTnu_2)/(metpt),nuPz_2,TMath::Sqrt((pTnu_2)*(pTnu_2)+(nuPz_2)*(nuPz_2)));
        Wlv_1 = Nulv_1+lepVector;
        Wlv_2 = Nulv_2+lepVector;
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
      TLorentzVector jet_lv;
      for(unsigned int ijet=0; ijet < theJetPt_PtOrdered->size(); ijet++){
        jet_lv.SetPtEtaPhiE(theJetPt_PtOrdered->at(ijet),theJetEta_PtOrdered->at(ijet),theJetPhi_PtOrdered->at(ijet),theJetEnergy_PtOrdered->at(ijet));
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
      jet_lv.SetPtEtaPhiE(theJetPt_PtOrdered->at(topIndex),theJetEta_PtOrdered->at(topIndex),theJetPhi_PtOrdered->at(topIndex),theJetEnergy_PtOrdered->at(topIndex));
      return jet_lv;
}


void step2::Loop()
{   
   if (inputTree == 0) return;
   outputFile->cd();
//    gROOT->SetBatch(kTRUE);   
    TTree *outputTree = inputTree->CloneTree(); //Copy of Input Tree
//    TTree *outputTree = new TTree("ljmet","ljmet"); //No Copy of Input Tree   

   TBranch *b_btagDeepJet2DWeight   = outputTree->Branch("btagDeepJet2DWeight", &btagDeepJet2DWeight, "btagDeepJet2DWeight/F");
   TBranch *b_btagDeepJet2DWeight_Pt120 = outputTree->Branch("btagDeepJet2DWeight_Pt120", &btagDeepJet2DWeight_Pt120, "btagDeepJet2DWeight_Pt120/F");
   TBranch *b_btagDeepJet2DWeight_HTnj   = outputTree->Branch("btagDeepJet2DWeight_HTnj", &btagDeepJet2DWeight_HTnj, "btagDeepJet2DWeight_HTnj/F");
   TBranch *b_btagDeepJet2DWeight_HTnj_HFup         = outputTree->Branch("btagDeepJet2DWeight_HTnj_HFup",         &btagDeepJet2DWeight_HTnj_HFup,         "btagDeepJet2DWeight_HTnj_HFup/F");         
   TBranch *b_btagDeepJet2DWeight_HTnj_HFdn         = outputTree->Branch("btagDeepJet2DWeight_HTnj_HFdn",         &btagDeepJet2DWeight_HTnj_HFdn,         "btagDeepJet2DWeight_HTnj_HFdn/F");         
   TBranch *b_btagDeepJet2DWeight_HTnj_LFup         = outputTree->Branch("btagDeepJet2DWeight_HTnj_LFup",         &btagDeepJet2DWeight_HTnj_LFup,         "btagDeepJet2DWeight_HTnj_LFup/F");         
   TBranch *b_btagDeepJet2DWeight_HTnj_LFdn         = outputTree->Branch("btagDeepJet2DWeight_HTnj_LFdn",         &btagDeepJet2DWeight_HTnj_LFdn,         "btagDeepJet2DWeight_HTnj_LFdn/F");         
   TBranch *b_btagDeepJet2DWeight_HTnj_jesup        = outputTree->Branch("btagDeepJet2DWeight_HTnj_jesup",        &btagDeepJet2DWeight_HTnj_jesup,        "btagDeepJet2DWeight_HTnj_jesup/F");        
   TBranch *b_btagDeepJet2DWeight_HTnj_jesdn        = outputTree->Branch("btagDeepJet2DWeight_HTnj_jesdn",        &btagDeepJet2DWeight_HTnj_jesdn,        "btagDeepJet2DWeight_HTnj_jesdn/F");        
   TBranch *b_btagDeepJet2DWeight_HTnj_hfstats1up   = outputTree->Branch("btagDeepJet2DWeight_HTnj_hfstats1up",   &btagDeepJet2DWeight_HTnj_hfstats1up,   "btagDeepJet2DWeight_HTnj_hfstats1up/F");   
   TBranch *b_btagDeepJet2DWeight_HTnj_hfstats1dn   = outputTree->Branch("btagDeepJet2DWeight_HTnj_hfstats1dn",   &btagDeepJet2DWeight_HTnj_hfstats1dn,   "btagDeepJet2DWeight_HTnj_hfstats1dn/F");   
   TBranch *b_btagDeepJet2DWeight_HTnj_hfstats2up   = outputTree->Branch("btagDeepJet2DWeight_HTnj_hfstats2up",   &btagDeepJet2DWeight_HTnj_hfstats2up,   "btagDeepJet2DWeight_HTnj_hfstats2up/F");   
   TBranch *b_btagDeepJet2DWeight_HTnj_hfstats2dn   = outputTree->Branch("btagDeepJet2DWeight_HTnj_hfstats2dn",   &btagDeepJet2DWeight_HTnj_hfstats2dn,   "btagDeepJet2DWeight_HTnj_hfstats2dn/F");   
   TBranch *b_btagDeepJet2DWeight_HTnj_cferr1up     = outputTree->Branch("btagDeepJet2DWeight_HTnj_cferr1up",     &btagDeepJet2DWeight_HTnj_cferr1up,     "btagDeepJet2DWeight_HTnj_cferr1up/F");     
   TBranch *b_btagDeepJet2DWeight_HTnj_cferr1dn     = outputTree->Branch("btagDeepJet2DWeight_HTnj_cferr1dn",     &btagDeepJet2DWeight_HTnj_cferr1dn,     "btagDeepJet2DWeight_HTnj_cferr1dn/F");     
   TBranch *b_btagDeepJet2DWeight_HTnj_cferr2up     = outputTree->Branch("btagDeepJet2DWeight_HTnj_cferr2up",     &btagDeepJet2DWeight_HTnj_cferr2up,     "btagDeepJet2DWeight_HTnj_cferr2up/F");     
   TBranch *b_btagDeepJet2DWeight_HTnj_cferr2dn     = outputTree->Branch("btagDeepJet2DWeight_HTnj_cferr2dn",     &btagDeepJet2DWeight_HTnj_cferr2dn,     "btagDeepJet2DWeight_HTnj_cferr2dn/F");     
   TBranch *b_btagDeepJet2DWeight_HTnj_lfstats1up   = outputTree->Branch("btagDeepJet2DWeight_HTnj_lfstats1up",   &btagDeepJet2DWeight_HTnj_lfstats1up,   "btagDeepJet2DWeight_HTnj_lfstats1up/F");   
   TBranch *b_btagDeepJet2DWeight_HTnj_lfstats1dn   = outputTree->Branch("btagDeepJet2DWeight_HTnj_lfstats1dn",   &btagDeepJet2DWeight_HTnj_lfstats1dn,   "btagDeepJet2DWeight_HTnj_lfstats1dn/F");   
   TBranch *b_btagDeepJet2DWeight_HTnj_lfstats2up   = outputTree->Branch("btagDeepJet2DWeight_HTnj_lfstats2up",   &btagDeepJet2DWeight_HTnj_lfstats2up,   "btagDeepJet2DWeight_HTnj_lfstats2up/F");   
   TBranch *b_btagDeepJet2DWeight_HTnj_lfstats2dn   = outputTree->Branch("btagDeepJet2DWeight_HTnj_lfstats2dn",   &btagDeepJet2DWeight_HTnj_lfstats2dn,   "btagDeepJet2DWeight_HTnj_lfstats2dn/F");   
   TBranch *b_isTraining            = outputTree->Branch("isTraining",&isTraining,"isTraining/I");
   TBranch *b_xsecEff               = outputTree->Branch("xsecEff",&xsecEff,"xsecEff/F");
   TBranch *b_deltaR_minBB          = outputTree->Branch("deltaR_minBB",&deltaR_minBB,"deltaR_minBB/F");
   TBranch *b_aveBBdr               = outputTree->Branch("aveBBdr",&aveBBdr,"aveBBdr/F");
   TBranch *b_deltaEta_maxBB        = outputTree->Branch("deltaEta_maxBB",&deltaEta_maxBB,"deltaEta_maxBB/F");  
   TBranch *b_FW_momentum_2         = outputTree->Branch("FW_momentum_2",&FW_momentum_2,"FW_momentum_2/F");
   TBranch *b_centrality            = outputTree->Branch("centrality",&centrality,"centrality/F");
   TBranch *b_aveCSVpt              = outputTree->Branch("aveCSVpt",&aveCSVpt,"aveCSVpt/F");
   TBranch *b_mass_maxJJJpt         = outputTree->Branch("mass_maxJJJpt",&mass_maxJJJpt,"mass_maxJJJpt/F");
   TBranch *b_maxJJJpt              = outputTree->Branch("maxJJJpt",&maxJJJpt,"maxJJJpt/F");
   TBranch *b_lepDR_minBBdr         = outputTree->Branch("lepDR_minBBdr",&lepDR_minBBdr,"lepDR_minBBdr/F"); 
   TBranch *b_HT_pt40               = outputTree->Branch("HT_pt40", &HT_pt40, "HT_pt40/F"); 
   TBranch *b_HT_bjets              = outputTree->Branch("HT_bjets",&HT_bjets,"HT_bjets/F");     
   TBranch *b_HT_ratio              = outputTree->Branch("HT_ratio",&HT_ratio,"HT_ratio/F");        
   TBranch *b_HT_2m                 = outputTree->Branch("HT_2m",&HT_2m,"HT_2m/F");        

   TBranch *b_firstcsvb_bb          = outputTree->Branch("firstcsvb_bb",&firstcsvb_bb,"firstcsvb_bb/F");        
   TBranch *b_secondcsvb_bb         = outputTree->Branch("secondcsvb_bb",&secondcsvb_bb,"secondcsvb_bb/F");        
   TBranch *b_thirdcsvb_bb          = outputTree->Branch("thirdcsvb_bb",&thirdcsvb_bb,"thirdcsvb_bb/F");        
   TBranch *b_fourthcsvb_bb         = outputTree->Branch("fourthcsvb_bb",&fourthcsvb_bb,"fourthcsvb_bb/F");
   TBranch *b_thirdcsvb_bb_BTagBHad          = outputTree->Branch("thirdcsvb_bb_BTagBHad",&thirdcsvb_bb_BTagBHad,"thirdcsvb_bb_BTagBHad/F");
   TBranch *b_thirdcsvb_bb_BTagNBHad          = outputTree->Branch("thirdcsvb_bb_BTagNBHad",&thirdcsvb_bb_BTagNBHad,"thirdcsvb_bb_BTagNBHad/F");
   TBranch *b_thirdcsvb_bb_NBTagBHad          = outputTree->Branch("thirdcsvb_bb_NBTagBHad",&thirdcsvb_bb_NBTagBHad,"thirdcsvb_bb_NBTagBHad/F");
   TBranch *b_thirdcsvb_bb_NBTagNBHad          = outputTree->Branch("thirdcsvb_bb_NBTagNBHad",&thirdcsvb_bb_NBTagNBHad,"thirdcsvb_bb_NBTagNBHad/F");

   TBranch *b_secondJetPt           = outputTree->Branch("secondJetPt",&secondJetPt,"secondJetPt/F");        
   TBranch *b_fifthJetPt            = outputTree->Branch("fifthJetPt",&fifthJetPt,"fifthJetPt/F");        
   TBranch *b_sixthJetPt            = outputTree->Branch("sixthJetPt",&sixthJetPt,"sixthJetPt/F");

   TBranch *b_csvJet1               = outputTree->Branch("csvJet1",&csvJet1,"csvJet1/F");
   TBranch *b_csvJet2               = outputTree->Branch("csvJet2",&csvJet2,"csvJet2/F");
   TBranch *b_csvJet3               = outputTree->Branch("csvJet3",&csvJet3,"csvJet3/F");
   TBranch *b_csvJet4               = outputTree->Branch("csvJet4",&csvJet4,"csvJet4/F");

   TBranch *b_MHRE                  = outputTree->Branch("MHRE",&MHRE,"MHRE/F");              
   TBranch *b_HTx                   = outputTree->Branch("HTx",&HTx,"HTx/F");                 
   
   TBranch *b_nGD_trijet            = outputTree->Branch("nGD_trijet",&nGD_trijet,"nGD_trijet/F");
   TBranch *b_is_genMissingDaughter    = outputTree->Branch("is_genMissingDaughter",&is_genMissingDaughter,"is_genMissingDaughter/F");
   TBranch *b_is_genFourTopsOnelepton  = outputTree->Branch("is_genFourTopsOnelepton",&is_genFourTopsOnelepton,"is_genFourTopsOnelepton/F");      
   
   TBranch *b_GD_DCSV_jetNotdijet   = outputTree->Branch("GD_DCSV_jetNotdijet",&GD_DCSV_jetNotdijet);
   TBranch *b_BD_DCSV_jetNotdijet   = outputTree->Branch("BD_DCSV_jetNotdijet",&BD_DCSV_jetNotdijet);
   TBranch *b_GD_DR_Tridijet        = outputTree->Branch("GD_DR_Tridijet",&GD_DR_Tridijet);
   TBranch *b_BD_DR_Tridijet        = outputTree->Branch("BD_DR_Tridijet",&BD_DR_Tridijet);      
   TBranch *b_GD_Ttrijet_TopMass    = outputTree->Branch("GD_Ttrijet_TopMass",&GD_Ttrijet_TopMass);
   TBranch *b_BD_Ttrijet_TopMass    = outputTree->Branch("BD_Ttrijet_TopMass",&BD_Ttrijet_TopMass);   
   TBranch *b_GD_Mass_minDR_dijet   = outputTree->Branch("GD_Mass_minDR_dijet",&GD_Mass_minDR_dijet);      
   TBranch *b_BD_Mass_minDR_dijet   = outputTree->Branch("BD_Mass_minDR_dijet",&BD_Mass_minDR_dijet);         
   TBranch *b_minMleppJetnew           = outputTree->Branch("minMleppJetnew",&minMleppJet,"minMleppJetnew/F");   
   TBranch *b_mass_lepJets0         = outputTree->Branch("mass_lepJets0",&mass_lepJets0,"mass_lepJets0/F");
   TBranch *b_mass_lepJets1         = outputTree->Branch("mass_lepJets1",&mass_lepJets1,"mass_lepJets1/F");
   TBranch *b_mass_lepJets2         = outputTree->Branch("mass_lepJets2",&mass_lepJets2,"mass_lepJets2/F");      
   TBranch *b_mass_minBBdr          = outputTree->Branch("mass_minBBdr",&mass_minBBdr,"mass_minBBdr/F");
   TBranch *b_mass_minLLdr          = outputTree->Branch("mass_minLLdr",&mass_minLLdr,"mass_minLLdr/F");
   TBranch *b_mass_maxBBpt          = outputTree->Branch("mass_maxBBpt",&mass_maxBBpt,"mass_maxBBpt/F");
   TBranch *b_mass_maxBBmass        = outputTree->Branch("mass_maxBBmass",&mass_maxBBmass,"mass_maxBBmass/F");
   TBranch *b_theJetLeadPt          = outputTree->Branch("theJetLeadPt",&theJetLeadPt,"theJetLeadPt/F");
   TBranch *b_deltaR_lepBJets0      = outputTree->Branch("deltaR_lepBJets0",&deltaR_lepBJets0,"deltaR_lepBJets0/F");
   TBranch *b_deltaR_lepBJets1      = outputTree->Branch("deltaR_lepBJets1",&deltaR_lepBJets1,"deltaR_lepBJets1/F");   
   TBranch *b_minDR_lepBJet         = outputTree->Branch("minDR_lepBJet",&minDR_lepBJet,"minDR_lepBJet/F");
   TBranch *b_minBBdr               = outputTree->Branch("minBBdr",&minBBdr,"minBBdr/F");
   TBranch *b_mass_lepBJet0         = outputTree->Branch("mass_lepBJet0",&mass_lepBJet0,"mass_lepBJet0/F");
   TBranch *b_mass_lepBB_minBBdr    = outputTree->Branch("mass_lepBB_minBBdr",&mass_lepBB_minBBdr,"mass_lepBB_minBBdr/F");
   TBranch *b_mass_lepJJ_minJJdr    = outputTree->Branch("mass_lepJJ_minJJdr",&mass_lepJJ_minJJdr,"mass_lepJJ_minJJdr/F");
   TBranch *b_mass_lepBJet_mindr    = outputTree->Branch("mass_lepBJet_mindr",&mass_lepBJet_mindr,"mass_lepBJet_mindr/F");
   TBranch *b_deltaR_lepBJet_maxpt  = outputTree->Branch("deltaR_lepBJet_maxpt",&deltaR_lepBJet_maxpt,"deltaR_lepBJet_maxpt/F");
   TBranch *b_deltaPhi_maxBB        = outputTree->Branch("deltaPhi_maxBB",&deltaPhi_maxBB,"deltaPhi_maxBB/F");
   TBranch *b_hemiout               = outputTree->Branch("hemiout",&hemiout,"hemiout/F");
   TBranch *b_corr_met              = outputTree->Branch("corr_met",&corr_met,"corr_met/F");
   TBranch *b_deltaPhi_lepMET       = outputTree->Branch("deltaPhi_lepMET",&deltaPhi_lepMET,"deltaPhi_lepMET/F");
   TBranch *b_min_deltaPhi_METjets  = outputTree->Branch("min_deltaPhi_METjets",&min_deltaPhi_METjets,"min_deltaPhi_METjets/F");
   TBranch *b_deltaPhi_METjets      = outputTree->Branch("deltaPhi_METjets",&deltaPhi_METjets);
   TBranch *b_aveCSV                = outputTree->Branch("aveCSV",&aveCSV,"aveCSV/F");
   TBranch *b_deltaPhi_j1j2         = outputTree->Branch("deltaPhi_j1j2",&deltaPhi_j1j2,"deltaPhi_j1j2/F");
   TBranch *b_alphaT                = outputTree->Branch("alphaT",&alphaT,"alphaT/F");
   TBranch *b_PtFifthJet            = outputTree->Branch("PtFifthJet",&PtFifthJet,"PtFifthJet/F");
   TBranch *b_FW_momentum_0         = outputTree->Branch("FW_momentum_0",&FW_momentum_0,"FW_momentum_0/F");
   TBranch *b_FW_momentum_1         = outputTree->Branch("FW_momentum_1",&FW_momentum_1,"FW_momentum_1/F");
   TBranch *b_FW_momentum_3         = outputTree->Branch("FW_momentum_3",&FW_momentum_3,"FW_momentum_3/F");
   TBranch *b_FW_momentum_4         = outputTree->Branch("FW_momentum_4",&FW_momentum_4,"FW_momentum_4/F");
   TBranch *b_FW_momentum_5         = outputTree->Branch("FW_momentum_5",&FW_momentum_5,"FW_momentum_5/F");
   TBranch *b_FW_momentum_6         = outputTree->Branch("FW_momentum_6",&FW_momentum_6,"FW_momentum_6/F");
   TBranch *b_MT2bb                 = outputTree->Branch("MT2bb",&MT2bb,"MT2bb/F");
   TBranch *b_GD_pTrat              = outputTree->Branch("GD_pTrat",&GD_pTrat);
   TBranch *b_BD_pTrat              = outputTree->Branch("BD_pTrat",&BD_pTrat);
   TBranch *b_GD_DR_Trijet_jetNotdijet       = outputTree->Branch("GD_DR_Trijet_jetNotdijet",&GD_DR_Trijet_jetNotdijet);
   TBranch *b_BD_DR_Trijet_jetNotdijet       = outputTree->Branch("BD_DR_Trijet_jetNotdijet",&BD_DR_Trijet_jetNotdijet);
   TBranch *b_deltaR_lepJetInMinMljet        = outputTree->Branch("deltaR_lepJetInMinMljet",&deltaR_lepJetInMinMljet,"deltaR_lepJetInMinMljet/F");
   TBranch *b_deltaPhi_lepJetInMinMljet      = outputTree->Branch("deltaPhi_lepJetInMinMljet",&deltaPhi_lepJetInMinMljet,"deltaPhi_lepJetInMinMljet/F");
   TBranch *b_deltaR_lepbJetInMinMlb         = outputTree->Branch("deltaR_lepbJetInMinMlb",&deltaR_lepbJetInMinMlb,"deltaR_lepbJetInMinMlb/F");
   TBranch *b_deltaR_lepbJetNotInMinMlb      = outputTree->Branch("deltaR_lepbJetNotInMinMlb",&deltaR_lepbJetNotInMinMlb,"deltaR_lepbJetNotInMinMlb/F");   
   TBranch *b_deltaPhi_lepbJetInMinMlb       = outputTree->Branch("deltaPhi_lepbJetInMinMlb",&deltaPhi_lepbJetInMinMlb,"deltaPhi_lepbJetInMinMlb/F");

   TBranch *b_HT_woBESTjet              = outputTree->Branch("HT_woBESTjet",&HT_woBESTjet,"HT_woBESTjet/F");
   TBranch *b_MT_woBESTjet              = outputTree->Branch("MT_woBESTjet",&MT_woBESTjet,"MT_woBESTjet/F");
   TBranch *b_PT_woBESTjet              = outputTree->Branch("PT_woBESTjet",&PT_woBESTjet,"PT_woBESTjet/F");
   TBranch *b_M_woBESTjet               = outputTree->Branch("M_woBESTjet",&M_woBESTjet,"M_woBESTjet/F");      
   TBranch *b_M_allJet_W                = outputTree->Branch("M_allJet_W",&M_allJet_W,"M_allJet_W/F");      
   TBranch *b_W_PtdM                    = outputTree->Branch("W_PtdM",&W_PtdM,"W_PtdM/F");         
   TBranch *b_ratio_HTdHT4leadjets      = outputTree->Branch("ratio_HTdHT4leadjets",&ratio_HTdHT4leadjets,"ratio_HTdHT4leadjets/F");      
   TBranch *b_pTjet5_6                  = outputTree->Branch("pTjet5_6",&pTjet5_6,"pTjet5_6/F");         
   TBranch *b_pt3HT                     = outputTree->Branch("pt3HT",&pt3HT,"pt3HT/F");         
   TBranch *b_pt4HT                     = outputTree->Branch("pt4HT",&pt4HT,"pt4HT/F");            
   TBranch *b_mean_csv                  = outputTree->Branch("mean_csv",&mean_csv,"mean_csv/F");               

   TBranch *b_pT_3rdcsvJet              = outputTree->Branch("pT_3rdcsvJet",&pT_3rdcsvJet,"pT_3rdcsvJet/F");         
   TBranch *b_pT_4thcsvJet              = outputTree->Branch("pT_4thcsvJet",&pT_4thcsvJet,"pT_4thcsvJet/F");            

   TBranch *b_invM_jet34                = outputTree->Branch("invM_jet34",&invM_jet34,"invM_jet34/F");            
   TBranch *b_invM_jet35                = outputTree->Branch("invM_jet35",&invM_jet35,"invM_jet35/F");            
   TBranch *b_invM_jet36                = outputTree->Branch("invM_jet36",&invM_jet36,"invM_jet36/F");               
   TBranch *b_invM_jet45                = outputTree->Branch("invM_jet45",&invM_jet45,"invM_jet45/F");            
   TBranch *b_invM_jet46                = outputTree->Branch("invM_jet46",&invM_jet46,"invM_jet46/F");            
   TBranch *b_invM_jet56                = outputTree->Branch("invM_jet56",&invM_jet56,"invM_jet56/F");                        

   TBranch *b_Sphericity                = outputTree->Branch("Sphericity",&Sphericity,"Sphericity/F");                        
   TBranch *b_Aplanarity                = outputTree->Branch("Aplanarity",&Aplanarity,"Aplanarity/F");                              
   TBranch *b_BDTtrijet2                = outputTree->Branch("BDTtrijet2",&BDTtrijet2,"BDTtrijet2/F");
   TBranch *b_BDTtrijet1                = outputTree->Branch("BDTtrijet1",&BDTtrijet1,"BDTtrijet1/F");
   TBranch *b_BDTtrijet3                = outputTree->Branch("BDTtrijet3",&BDTtrijet3,"BDTtrijet3/F");
   TBranch *b_BDTtrijet4                = outputTree->Branch("BDTtrijet4",&BDTtrijet4,"BDTtrijet4/F");

   TBranch *b_HOTGoodTrijet1_mass       = outputTree->Branch("HOTGoodTrijet1_mass",&HOTGoodTrijet1_mass,"HOTGoodTrijet1_mass/F");
   TBranch *b_HOTGoodTrijet1_dijetmass  = outputTree->Branch("HOTGoodTrijet1_dijetmass",&HOTGoodTrijet1_dijetmass,"HOTGoodTrijet1_dijetmass/F");
   TBranch *b_HOTGoodTrijet1_pTratio    = outputTree->Branch("HOTGoodTrijet1_pTratio",&HOTGoodTrijet1_pTratio,"HOTGoodTrijet1_pTratio/F");
   TBranch *b_HOTGoodTrijet1_dRtridijet = outputTree->Branch("HOTGoodTrijet1_dRtridijet",&HOTGoodTrijet1_dRtridijet,"HOTGoodTrijet1_dRtridijet/F");
   TBranch *b_HOTGoodTrijet1_dRtrijetJetnotdijet = outputTree->Branch("HOTGoodTrijet1_dRtrijetJetnotdijet",&HOTGoodTrijet1_dRtrijetJetnotdijet,"HOTGoodTrijet1_dRtrijetJetnotdijet/F");
   TBranch *b_HOTGoodTrijet1_csvJetnotdijet = outputTree->Branch("HOTGoodTrijet1_csvJetnotdijet",&HOTGoodTrijet1_csvJetnotdijet,"HOTGoodTrijet1_csvJetnotdijet/F");
   TBranch *b_HOTGoodTrijet2_mass       = outputTree->Branch("HOTGoodTrijet2_mass",&HOTGoodTrijet2_mass,"HOTGoodTrijet2_mass/F");
   TBranch *b_HOTGoodTrijet2_dijetmass  = outputTree->Branch("HOTGoodTrijet2_dijetmass",&HOTGoodTrijet2_dijetmass,"HOTGoodTrijet2_dijetmass/F");
   TBranch *b_HOTGoodTrijet2_pTratio    = outputTree->Branch("HOTGoodTrijet2_pTratio",&HOTGoodTrijet2_pTratio,"HOTGoodTrijet2_pTratio/F");
   TBranch *b_HOTGoodTrijet2_dRtridijet = outputTree->Branch("HOTGoodTrijet2_dRtridijet",&HOTGoodTrijet2_dRtridijet,"HOTGoodTrijet2_dRtridijet/F");
   TBranch *b_HOTGoodTrijet2_dRtrijetJetnotdijet = outputTree->Branch("HOTGoodTrijet2_dRtrijetJetnotdijet",&HOTGoodTrijet2_dRtrijetJetnotdijet,"HOTGoodTrijet2_dRtrijetJetnotdijet/F");
   TBranch *b_HOTGoodTrijet2_csvJetnotdijet = outputTree->Branch("HOTGoodTrijet2_csvJetnotdijet",&HOTGoodTrijet2_csvJetnotdijet,"HOTGoodTrijet2_csvJetnotdijet/F");
   TBranch *b_HOTGoodTrijet3_mass       = outputTree->Branch("HOTGoodTrijet3_mass",&HOTGoodTrijet3_mass,"HOTGoodTrijet3_mass/F");
   TBranch *b_HOTGoodTrijet3_dijetmass  = outputTree->Branch("HOTGoodTrijet3_dijetmass",&HOTGoodTrijet3_dijetmass,"HOTGoodTrijet3_dijetmass/F");
   TBranch *b_HOTGoodTrijet3_pTratio    = outputTree->Branch("HOTGoodTrijet3_pTratio",&HOTGoodTrijet3_pTratio,"HOTGoodTrijet3_pTratio/F");
   TBranch *b_HOTGoodTrijet3_dRtridijet = outputTree->Branch("HOTGoodTrijet3_dRtridijet",&HOTGoodTrijet3_dRtridijet,"HOTGoodTrijet3_dRtridijet/F");
   TBranch *b_HOTGoodTrijet3_dRtrijetJetnotdijet = outputTree->Branch("HOTGoodTrijet3_dRtrijetJetnotdijet",&HOTGoodTrijet3_dRtrijetJetnotdijet,"HOTGoodTrijet3_dRtrijetJetnotdijet/F");
   TBranch *b_HOTGoodTrijet3_csvJetnotdijet = outputTree->Branch("HOTGoodTrijet3_csvJetnotdijet",&HOTGoodTrijet3_csvJetnotdijet,"HOTGoodTrijet3_csvJetnotdijet/F");
   TBranch *b_HOTGoodTrijet4_mass       = outputTree->Branch("HOTGoodTrijet4_mass",&HOTGoodTrijet4_mass,"HOTGoodTrijet4_mass/F");
   TBranch *b_HOTGoodTrijet4_dijetmass  = outputTree->Branch("HOTGoodTrijet4_dijetmass",&HOTGoodTrijet4_dijetmass,"HOTGoodTrijet4_dijetmass/F");
   TBranch *b_HOTGoodTrijet4_pTratio    = outputTree->Branch("HOTGoodTrijet4_pTratio",&HOTGoodTrijet4_pTratio,"HOTGoodTrijet4_pTratio/F");
   TBranch *b_HOTGoodTrijet4_dRtridijet = outputTree->Branch("HOTGoodTrijet4_dRtridijet",&HOTGoodTrijet4_dRtridijet,"HOTGoodTrijet4_dRtridijet/F");
   TBranch *b_HOTGoodTrijet4_dRtrijetJetnotdijet = outputTree->Branch("HOTGoodTrijet4_dRtrijetJetnotdijet",&HOTGoodTrijet4_dRtrijetJetnotdijet,"HOTGoodTrijet4_dRtrijetJetnotdijet/F");
   TBranch *b_HOTGoodTrijet4_csvJetnotdijet = outputTree->Branch("HOTGoodTrijet4_csvJetnotdijet",&HOTGoodTrijet4_csvJetnotdijet,"HOTGoodTrijet4_csvJetnotdijet/F");

   TBranch *b_HOTBadTrijet1_mass       = outputTree->Branch("HOTBadTrijet1_mass",&HOTBadTrijet1_mass,"HOTBadTrijet1_mass/F");
   TBranch *b_HOTBadTrijet1_dijetmass  = outputTree->Branch("HOTBadTrijet1_dijetmass",&HOTBadTrijet1_dijetmass,"HOTBadTrijet1_dijetmass/F");
   TBranch *b_HOTBadTrijet1_pTratio    = outputTree->Branch("HOTBadTrijet1_pTratio",&HOTBadTrijet1_pTratio,"HOTBadTrijet1_pTratio/F");
   TBranch *b_HOTBadTrijet1_dRtridijet = outputTree->Branch("HOTBadTrijet1_dRtridijet",&HOTBadTrijet1_dRtridijet,"HOTBadTrijet1_dRtridijet/F");
   TBranch *b_HOTBadTrijet1_dRtrijetJetnotdijet = outputTree->Branch("HOTBadTrijet1_dRtrijetJetnotdijet",&HOTBadTrijet1_dRtrijetJetnotdijet,"HOTBadTrijet1_dRtrijetJetnotdijet/F");
   TBranch *b_HOTBadTrijet1_csvJetnotdijet = outputTree->Branch("HOTBadTrijet1_csvJetnotdijet",&HOTBadTrijet1_csvJetnotdijet,"HOTBadTrijet1_csvJetnotdijet/F");
   TBranch *b_HOTBadTrijet2_mass       = outputTree->Branch("HOTBadTrijet2_mass",&HOTBadTrijet2_mass,"HOTBadTrijet2_mass/F");
   TBranch *b_HOTBadTrijet2_dijetmass  = outputTree->Branch("HOTBadTrijet2_dijetmass",&HOTBadTrijet2_dijetmass,"HOTBadTrijet2_dijetmass/F");
   TBranch *b_HOTBadTrijet2_pTratio    = outputTree->Branch("HOTBadTrijet2_pTratio",&HOTBadTrijet2_pTratio,"HOTBadTrijet2_pTratio/F");
   TBranch *b_HOTBadTrijet2_dRtridijet = outputTree->Branch("HOTBadTrijet2_dRtridijet",&HOTBadTrijet2_dRtridijet,"HOTBadTrijet2_dRtridijet/F");
   TBranch *b_HOTBadTrijet2_dRtrijetJetnotdijet = outputTree->Branch("HOTBadTrijet2_dRtrijetJetnotdijet",&HOTBadTrijet2_dRtrijetJetnotdijet,"HOTBadTrijet2_dRtrijetJetnotdijet/F");
   TBranch *b_HOTBadTrijet2_csvJetnotdijet = outputTree->Branch("HOTBadTrijet2_csvJetnotdijet",&HOTBadTrijet2_csvJetnotdijet,"HOTBadTrijet2_csvJetnotdijet/F");
   TBranch *b_HOTBadTrijet3_mass       = outputTree->Branch("HOTBadTrijet3_mass",&HOTBadTrijet3_mass,"HOTBadTrijet3_mass/F");
   TBranch *b_HOTBadTrijet3_dijetmass  = outputTree->Branch("HOTBadTrijet3_dijetmass",&HOTBadTrijet3_dijetmass,"HOTBadTrijet3_dijetmass/F");
   TBranch *b_HOTBadTrijet3_pTratio    = outputTree->Branch("HOTBadTrijet3_pTratio",&HOTBadTrijet3_pTratio,"HOTBadTrijet3_pTratio/F");
   TBranch *b_HOTBadTrijet3_dRtridijet = outputTree->Branch("HOTBadTrijet3_dRtridijet",&HOTBadTrijet3_dRtridijet,"HOTBadTrijet3_dRtridijet/F");
   TBranch *b_HOTBadTrijet3_dRtrijetJetnotdijet = outputTree->Branch("HOTBadTrijet3_dRtrijetJetnotdijet",&HOTBadTrijet3_dRtrijetJetnotdijet,"HOTBadTrijet3_dRtrijetJetnotdijet/F");
   TBranch *b_HOTBadTrijet3_csvJetnotdijet = outputTree->Branch("HOTBadTrijet3_csvJetnotdijet",&HOTBadTrijet3_csvJetnotdijet,"HOTBadTrijet3_csvJetnotdijet/F");
   TBranch *b_HOTBadTrijet4_mass       = outputTree->Branch("HOTBadTrijet4_mass",&HOTBadTrijet4_mass,"HOTBadTrijet4_mass/F");
   TBranch *b_HOTBadTrijet4_dijetmass  = outputTree->Branch("HOTBadTrijet4_dijetmass",&HOTBadTrijet4_dijetmass,"HOTBadTrijet4_dijetmass/F");
   TBranch *b_HOTBadTrijet4_pTratio    = outputTree->Branch("HOTBadTrijet4_pTratio",&HOTBadTrijet4_pTratio,"HOTBadTrijet4_pTratio/F");
   TBranch *b_HOTBadTrijet4_dRtridijet = outputTree->Branch("HOTBadTrijet4_dRtridijet",&HOTBadTrijet4_dRtridijet,"HOTBadTrijet4_dRtridijet/F");
   TBranch *b_HOTBadTrijet4_dRtrijetJetnotdijet = outputTree->Branch("HOTBadTrijet4_dRtrijetJetnotdijet",&HOTBadTrijet4_dRtrijetJetnotdijet,"HOTBadTrijet4_dRtrijetJetnotdijet/F");
   TBranch *b_HOTBadTrijet4_csvJetnotdijet = outputTree->Branch("HOTBadTrijet4_csvJetnotdijet",&HOTBadTrijet4_csvJetnotdijet,"HOTBadTrijet4_csvJetnotdijet/F");

   TBranch *b_NJets_JetSubCalc_float 		= outputTree->Branch("NJets_JetSubCalc_float",&NJets_JetSubCalc_float,"NJets_JetSubCalc_float/F");
   TBranch *b_NJetsCSVwithSF_MultiLepCalc_float = outputTree->Branch("NJetsCSVwithSF_MultiLepCalc_float",&NJetsCSVwithSF_MultiLepCalc_float,"NJetsCSV_MultiLepCalc_float/F");
   TBranch *b_NresolvedTops1pFake_float 	= outputTree->Branch("NresolvedTops1pFake_float",&NresolvedTops1pFake_float,"NresolvedTops1pFake_float/F");
   TBranch *b_NJetsTtagged_float  		= outputTree->Branch("NJetsTtagged_float",&NJetsTtagged_float,"NJetsTtagged_float/F");
   TBranch *b_NJetsWtagged_float  		= outputTree->Branch("NJetsWtagged_float",&NJetsWtagged_float,"NJetsWtagged_float/F");
   TBranch *b_BestTop_Discriminator             = outputTree->Branch("BestTop_Discriminator", &BestTop_Discriminator, "BestTop_Discriminator/F");
   TBranch *b_BestTop_Pt                        = outputTree->Branch("BestTop_Pt", &BestTop_Pt, "BestTop_Pt/F");
   TBranch *b_BestTop_Phi                       = outputTree->Branch("BestTop_Phi", &BestTop_Phi, "BestTop_Phi/F");
   TBranch *b_BestTop_Eta                       = outputTree->Branch("BestTop_Eta", &BestTop_Eta, "BestTop_Eta/F");
   TBranch *b_BestTop_Mass                      = outputTree->Branch("BestTop_Mass", &BestTop_Mass, "BestTop_Mass/F");

   TBranch *b_NoTop_Jet1_CSV                    = outputTree->Branch("NoTop_Jet1_CSV", &NoTop_Jet1_CSV, "NoTop_Jet1_CSV/F");
   TBranch *b_NoTop_Jet1_Pt                     = outputTree->Branch("NoTop_Jet1_Pt", &NoTop_Jet1_Pt, "NoTop_Jet1_Pt/F");
   TBranch *b_NoTop_Jet1_Phi                    = outputTree->Branch("NoTop_Jet1_Phi", &NoTop_Jet1_Phi, "NoTop_Jet1_Phi/F");
   TBranch *b_NoTop_Jet1_Eta                    = outputTree->Branch("NoTop_Jet1_Eta", &NoTop_Jet1_Eta, "NoTop_Jet1_Eta/F");
   TBranch *b_NoTop_Jet1_Energy                   = outputTree->Branch("NoTop_Jet1_Energy", &NoTop_Jet1_Energy, "NoTop_Jet1_Energy/F");

   TBranch *b_NoTop_Jet2_CSV                    = outputTree->Branch("NoTop_Jet2_CSV", &NoTop_Jet2_CSV, "NoTop_Jet2_CSV/F");
   TBranch *b_NoTop_Jet2_Pt                     = outputTree->Branch("NoTop_Jet2_Pt", &NoTop_Jet2_Pt, "NoTop_Jet2_Pt/F");
   TBranch *b_NoTop_Jet2_Phi                    = outputTree->Branch("NoTop_Jet2_Phi", &NoTop_Jet2_Phi, "NoTop_Jet2_Phi/F");
   TBranch *b_NoTop_Jet2_Eta                    = outputTree->Branch("NoTop_Jet2_Eta", &NoTop_Jet2_Eta, "NoTop_Jet2_Eta/F");
   TBranch *b_NoTop_Jet2_Energy                 = outputTree->Branch("NoTop_Jet2_Energy", &NoTop_Jet2_Energy, "NoTop_Jet2_Energy/F");

   TBranch *b_recLeptonicTopJetCSV              = outputTree->Branch("recLeptonicTopJetCSV", &recLeptonicTopJetCSV, "recLeptonicTopJetCSV/F"); 
   TBranch *b_recLeptonicTopJetPt               = outputTree->Branch("recLeptonicTopJetPt", &recLeptonicTopJetPt, "recLeptonicTopJetPt/F");

   TBranch *b_LeptonicTB1_M                     = outputTree->Branch("LeptonicTB1_M", &LeptonicTB1_M, "LeptonicTB1_M/F");
   TBranch *b_LeptonicTB2_M                     = outputTree->Branch("LeptonicTB2_M", &LeptonicTB2_M, "LeptonicTB2_M/F");
   
   TBranch *b_LeptonicTB1_Pt                      = outputTree->Branch("LeptonicTB1_Pt", &LeptonicTB1_Pt, "LeptonicTB1_Pt/F");
   TBranch *b_LeptonicTB2_Pt                      = outputTree->Branch("LeptonicTB2_Pt", &LeptonicTB2_Pt, "LeptonicTB2_Pt/F");

   TBranch *b_LeptonicTB1_Eta                     = outputTree->Branch("LeptonicTB1_Eta", &LeptonicTB1_Eta, "LeptonicTB1_Eta/F");
   TBranch *b_LeptonicTB2_Eta                     = outputTree->Branch("LeptonicTB2_Eta", &LeptonicTB2_Eta, "LeptonicTB2_Eta/F");
   
   TBranch *b_HadronicTB1_M                       = outputTree->Branch("HadronicTB1_M", &HadronicTB1_M, "HadronicTB1_M/F");
   TBranch *b_HadronicTB2_M                       = outputTree->Branch("HadronicTB2_M", &HadronicTB2_M, "HadronicTB2_M/F");

   TBranch *b_HadronicTB1_Pt                      = outputTree->Branch("HadronicTB1_Pt", &HadronicTB1_Pt, "HadronicTB1_Pt/F");
   TBranch *b_HadronicTB2_Pt                      = outputTree->Branch("HadronicTB2_Pt", &HadronicTB2_Pt, "HadronicTB2_Pt/F");

   TBranch *b_HadronicTB1_Eta                     = outputTree->Branch("HadronicTB1_Eta", &HadronicTB1_Eta, "HadronicTB1_Eta/F");
   TBranch *b_HadronicTB2_Eta                     = outputTree->Branch("HadronicTB2_Eta", &HadronicTB2_Eta, "HadronicTB2_Eta/F");


   Long64_t nentries = inputTree->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   TLorentzVector bjet1, bjet2, jet1, jet2, jet3, lep, met, jetTmp, BestTOPjet1, BestTOPjet2, BestTOPjet3, BADTOPjet1, BADTOPjet2, BADTOPjet3, BestGenTop, BestGenTopW1, BestGenTopW2, BestGenTopb;   
   bool bool_TopMassCut = 0;
   int allLeptonicWcount = 0;
   int allMatchingCount = 0;   
   float topdiscriminator = 0.95;
  

   std::string sampleType = "";
   if(isTTBB)      sampleType = "ttbb";
   if(isTT2B)      sampleType = "tt2b";
   if(isTT1B)      sampleType = "tt1b";
   if(isTTCC)      sampleType = "ttcc";
   if(isTTLF)      sampleType = "ttjj";
   if(isSTs)       sampleType = "STs";
   if(isSTt)       sampleType = "STt";
   if(isSTtw)      sampleType = "STtw";
   if(isWJets)     sampleType = "WJets";
   if(isQCD)       sampleType = "QCD";
   if(isDYM)       sampleType = "DYM";
   if(isEWK)       sampleType = "EWK";
   if(isTTHB)      sampleType = "ttHTobb";
   if(isTTHnonB)   sampleType = "ttHToNonbb";
   if(isTTHH)      sampleType = "TTHH";
   if(isTTXY)      sampleType = "TTXY";
   if(isTTTW)      sampleType = "TTTW";
   if(isTTTJ)      sampleType = "TTTJ";
   if(isTTTT)      sampleType = "TTTT";
   if(isCHM200 )   sampleType = "CHM200";   
   if(isCHM220 )   sampleType = "CHM220"; 
   if(isCHM250 )   sampleType = "CHM250"; 
   if(isCHM300 )   sampleType = "CHM300"; 
   if(isCHM350 )   sampleType = "CHM350"; 
   if(isCHM400 )   sampleType = "CHM400"; 
   if(isCHM500 )   sampleType = "CHM500"; 
   if(isCHM600 )   sampleType = "CHM600"; 
   if(isCHM700 )   sampleType = "CHM700"; 
   if(isCHM800 )   sampleType = "CHM800"; 
   if(isCHM1000)   sampleType = "CHM1000"; 
   if(isCHM1250)   sampleType = "CHM1250";
   if(isCHM1500)   sampleType = "CHM1500";
   if(isCHM1750)   sampleType = "CHM1750";
   if(isCHM2000)   sampleType = "CHM2000";
   if(isCHM2500)   sampleType = "CHM2500";
   if(isCHM3000)   sampleType = "CHM3000";
   if(isHT500)     sampleType = "HT500" + sampleType;

   std::cout<<sampleType<<std::endl;
         
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = inputTree->GetEntry(jentry);   nbytes += nb;
     if (Cut(ientry) != 1) continue;
     //if (jentry > 5000 ) break;  // debug
     if( jentry % 1000 == 0 ) std::cout << "Completed " << jentry << " out of " << nentries << " events" <<std::endl;      

     std::vector<TLorentzVector> GoodRecoJet1;         
     std::vector<TLorentzVector> GoodRecoJet2;         
     std::vector<TLorentzVector> GoodRecoJet3;                   
     TRandom3 myseed;
     myseed.SetSeed(static_cast<int>(leptonPhi_MultiLepCalc*1e5));
     double coin = myseed.Rndm();
     if( coin < 0.60 ) isTraining = 1;                              // BDT TRAINING
     else if( ( coin >= 0.60 ) && ( coin < 0.80 ) ) isTraining = 2; // BDT TESTING
     else isTraining = 3;                                           // BDT APPLICATION
     minBBdr = 1e9;
     minMleppJet = 1e9;     
     tmp_minMleppBjet = 1e9;          
     aveCSVpt = 0;
     firstcsvb_bb = 0;
     secondcsvb_bb = 0;
     thirdcsvb_bb = 0;
     fourthcsvb_bb = 0;
     MT2bb = 0;      
     deltaR_minBB = 20.;
     aveBBdr = 0;      
     deltaEta_maxBB = 10;                  
     lepDR_minBBdr = -1;
     mass_maxJJJpt = -1;     
     maxJJJpt = 0; 
     FW_momentum_0=0; FW_momentum_1=0; FW_momentum_2=0; FW_momentum_3=0; FW_momentum_4=0; FW_momentum_5=0; FW_momentum_6=0;
     centrality = -1;     
     HT_pt40 = 0; 
     HT_bjets = 0;
     HT_ratio = -1; //for ratio of HT(j1,2,3,4)/HT(other jets)     
     HT_2m = -10;
     theJetLeadPt = -1000; 
     mass_lepJets0 = -1;             
     mass_lepJets1 = -1;                          
     mass_lepJets2 = -1;  
     MHRE = -100;     
     HTx = 0;                             
     Sphericity = -1;
     Aplanarity	= -1; 
     BDTtrijet2 = -1.; BDTtrijet1 = -1.; BDTtrijet3 = -1.; BDTtrijet4 = -1.;

     BestTop_Discriminator = -10;
     BestTop_Pt = -10;
     BestTop_Phi = -10;
     BestTop_Eta = -10;
     BestTop_Mass = -10;

     int BestTop_jet1idx = -1;
     int BestTop_jet2idx = -1;
     int BestTop_jet3idx = -1;

    
   
     NoTop_Jet1_CSV  = -10;
     NoTop_Jet1_Pt   = -10;
     NoTop_Jet1_Phi  = -10;
     NoTop_Jet1_Eta  = -10;
     NoTop_Jet1_Energy = -10;
 
     NoTop_Jet2_CSV  = -10;
     NoTop_Jet2_Pt   = -10;
     NoTop_Jet2_Phi  = -10;
     NoTop_Jet2_Eta  = -10;
     NoTop_Jet2_Energy = -10;
     recLeptonicTopJetCSV = -10;
     recLeptonicTopJetPt  = -10;

     LeptonicTB1_M = -10;
     LeptonicTB2_M = -10;
     LeptonicTB1_Pt = -10;
     LeptonicTB2_Pt = -10;
     LeptonicTB1_Eta = -100;
     LeptonicTB2_Eta = -100;
     HadronicTB1_M = -10;
     HadronicTB2_M = -10;
     HadronicTB1_Pt = -10;
     HadronicTB2_Pt = -10;
     HadronicTB1_Eta = -100;
     HadronicTB2_Eta = -100;

      
     NJets_JetSubCalc_float = (float) NJets_JetSubCalc;
     NJetsCSVwithSF_MultiLepCalc_float = (float) NJetsCSVwithSF_MultiLepCalc;
     NresolvedTops1pFake_float = (float) NresolvedTops1pFake;
     NJetsTtagged_float = (float) NJetsTtagged;
     NJetsWtagged_float = (float) NJetsWtagged;
//     thirdcsvb_bb_BTagBHad = 0; thirdcsvb_bb_BTagNBHad = 0; thirdcsvb_bb_NBTagBHad= 0; thirdcsvb_bb_NBTagNBHad = 0;
 
     int njetscsv = 0;      
     double maxBBdeta = 0;
     double totalJetPt = 0; //this is mainly HT
     double totalJetE  = 0; 
     double HT_4jets = 0; //for ratio of HT(j1,2,3,4)/HT(other jets)     
     double HT_other = 0; //for ratio of HT(j1,2,3,4)/HT(other jets)          
     double npairs = 0;     
     double BjetSecondPt = 0;
     int num_GD_trijet = 0;
     int num_BD_trijet = 0;    


    int nljets = 0; 
    int nhjets = 0;
    int nljets_pt120 = 0; 
    int nhjets_pt120 = 0;
    
    for(unsigned int ijet = 0; ijet<theJetPt_JetSubCalc_PtOrdered->size(); ijet++){
        if(theJetPt_JetSubCalc_PtOrdered->at(ijet)>40 && theJetPt_JetSubCalc_PtOrdered->at(ijet)<100) nljets+=1;
        if(theJetPt_JetSubCalc_PtOrdered->at(ijet)>=100) nhjets+=1;

        if(theJetPt_JetSubCalc_PtOrdered->at(ijet)>40 && theJetPt_JetSubCalc_PtOrdered->at(ijet)<120) nljets_pt120+=1;
        if(theJetPt_JetSubCalc_PtOrdered->at(ijet)>=120) nhjets_pt120+=1;
    } 
    
     
    //btagDeepJet2DWeight = hardcodedConditions.GetDeepJetRenorm2DSF(nljets, nhjets, sampleType);   
    //btagDeepJet2DWeight_Pt120 = hardcodedConditions.GetDeepJetRenorm2DSF_Pt120(nljets_pt120, nhjets_pt120, sampleType);  
    btagDeepJet2DWeight_HTnj                = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "");
    btagDeepJet2DWeight_HTnj_HFup           = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_HFup");
    btagDeepJet2DWeight_HTnj_HFdn           = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_HFdn");
    btagDeepJet2DWeight_HTnj_LFup           = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_LFup");
    btagDeepJet2DWeight_HTnj_LFdn           = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_LFdn");
    btagDeepJet2DWeight_HTnj_jesup          = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_jesup");
    btagDeepJet2DWeight_HTnj_jesdn          = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_jesdn");
    btagDeepJet2DWeight_HTnj_hfstats1up     = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_hfstats1up");
    btagDeepJet2DWeight_HTnj_hfstats1dn     = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_hfstats1dn");
    btagDeepJet2DWeight_HTnj_hfstats2up     = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_hfstats2up");
    btagDeepJet2DWeight_HTnj_hfstats2dn     = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_hfstats2dn");
    btagDeepJet2DWeight_HTnj_cferr1up       = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_cferr1up");
    btagDeepJet2DWeight_HTnj_cferr1dn       = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_cferr1dn");
    btagDeepJet2DWeight_HTnj_cferr2up       = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_cferr2up");
    btagDeepJet2DWeight_HTnj_cferr2dn       = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_cferr2dn");
    btagDeepJet2DWeight_HTnj_lfstats1up     = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_lfstats1up");
    btagDeepJet2DWeight_HTnj_lfstats1dn     = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_lfstats1dn");
    btagDeepJet2DWeight_HTnj_lfstats2up     = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_lfstats2up");
    btagDeepJet2DWeight_HTnj_lfstats2dn     = hardcodedConditions.GetDeepJetRenorm2DSF_HTnj(AK4HT, NJets_JetSubCalc, sampleType, "_lfstats2dn");
   // std::cout<<nljets<<","<<nhjets<<","<<btagDeepJet2DWeight_Pt120<<std::endl; 
//////////////////////////////////////////////////////////////////
// build BB PAIR variables, aveCSVpt, HT_bjets, HT_ratio, HT_2m //
//////////////////////////////////////////////////////////////////

     HT_4jets = theJetPt_JetSubCalc_PtOrdered->at(0)+theJetPt_JetSubCalc_PtOrdered->at(1)+theJetPt_JetSubCalc_PtOrdered->at(2)+theJetPt_JetSubCalc_PtOrdered->at(3);
     for(unsigned int ijet = 4; ijet < theJetPt_JetSubCalc_PtOrdered->size(); ijet++){
         HT_other += theJetPt_JetSubCalc_PtOrdered->at(ijet);
     }
     if (NJets_JetSubCalc >= 4){  // was >
         HT_ratio = HT_4jets/HT_other;
         ratio_HTdHT4leadjets = AK4HT/HT_4jets;
     }

     corr_met = (float) corr_met_MultiLepCalc;
     theJetLeadPt = theJetPt_JetSubCalc_PtOrdered->at(0);
     
     double maxBBdphi = 0;
     double maxBBpt = 0; 
     double maxLBpt = 0; 
     double maxBBmass = 0;
     double minLLdr = 1e9;

     bjet1.SetPtEtaPhiE(0,0,0,0);
     bjet2.SetPtEtaPhiE(0,0,0,0);
     jet1.SetPtEtaPhiE(0,0,0,0);
     jet2.SetPtEtaPhiE(0,0,0,0);
     jet3.SetPtEtaPhiE(0,0,0,0);

     double lepM;
     double metM=0;
     if(isMuon) lepM = 0.105658367;
     else lepM = 0.00051099891;
     lep.SetPtEtaPhiM(leptonPt_MultiLepCalc,leptonEta_MultiLepCalc,leptonPhi_MultiLepCalc,lepM);
     met.SetPtEtaPhiM(corr_met_MultiLepCalc,0,corr_met_phi_MultiLepCalc,metM);
     mass_minBBdr = -1;
     mass_minLLdr = -1;
     mass_maxBBpt = -1;
     mass_maxBBmass = -1;
     minDR_lepBJet = 20.;
     mass_lepBB_minBBdr = -1;
     mass_lepJJ_minJJdr = -1;
     mass_lepBJet0 = -1;
     deltaR_lepBJets0 = -1;
     deltaR_lepBJets1 = -1;     
     mass_lepBJet_mindr = -1;
     deltaR_lepBJet_maxpt = -1;
     deltaR_lepJetInMinMljet = -99;
     deltaPhi_lepJetInMinMljet = -99;
     deltaR_lepbJetInMinMlb = -10.;
     deltaPhi_lepbJetInMinMlb = -10.;
     deltaR_lepbJetNotInMinMlb = -99;
     deltaPhi_maxBB = 1e9;
     hemiout = -1;
     deltaPhi_METjets.clear();
     min_deltaPhi_METjets = 1e9;
     aveCSV = -1;
     csvJet1 = 0;
     csvJet2 = 0;
     csvJet3 = 0;
     csvJet4 = 0;
     mean_csv = 0;
     pT_3rdcsvJet = 0;
     pT_4thcsvJet = 0;
     W_PtdM = -1;
     pt3HT = -10;
     pt4HT = -10;     
     pTjet5_6 = -10;
     invM_jet34 = -10;
     invM_jet35 = -10;     
     invM_jet36 = -10;          
     invM_jet45 = -10;               
     invM_jet46 = -10;                    
     invM_jet56 = -10;                         
     secondJetPt = -1;
     fifthJetPt = -1;
     sixthJetPt = -1;
     
     float totalPtCSV = 0;
     double deltaPhifromMET_ = TVector2::Phi_mpi_pi(leptonPhi_MultiLepCalc - corr_met_phi_MultiLepCalc);
     deltaPhi_lepMET = deltaPhifromMET_;
     if(abs(deltaPhifromMET_)>TMath::Pi()/2){hemiout+=leptonPt_MultiLepCalc;}

     std::vector<float> v_CSVb_bb;
     std::vector<TLorentzVector> v_allJets;
     std::vector<TLorentzVector> v_trijet;
     std::vector<double> v_DCSV_allJets;          
//     std::vector<pair<double, int>> v_DCSV_jettype_allJets;
     std::vector<double> v_DCSV_trijet;     
     std::vector<TLorentzVector> v_BADtrijet;  
     std::vector<std::pair<TLorentzVector, double>> v_pair_jet_CSV;

     v_pair_jet_CSV.clear();          
     v_trijet.clear();   
     v_BADtrijet.clear();        

     GD_DR_Tridijet.clear();
     BD_DR_Tridijet.clear();

     GD_Mass_minDR_dijet.clear();
     BD_Mass_minDR_dijet.clear();

     GD_Ttrijet_TopMass.clear();
     BD_Ttrijet_TopMass.clear();

     GD_DR_Trijet_jetNotdijet.clear();
     BD_DR_Trijet_jetNotdijet.clear();
     

     unsigned int tmpJetInd = 0;
     TLorentzVector bestJetinWjet;

     int jettype(0);
     for(unsigned int ijet = 0; ijet < theJetPt_JetSubCalc_PtOrdered->size(); ijet++){
        if( theJetPt_JetSubCalc_PtOrdered->at(ijet)>40) HT_pt40+=theJetPt_JetSubCalc_PtOrdered->at(ijet);
//	cout << " event # " << jentry << " ijet " << ijet << endl;
        if ( (theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040) && (theJetHFlav_JetSubCalc_PtOrdered->at(ijet)==5)  ) 
	//if (  (theJetBTag_JetSubCalc_PtOrdered->at(ijet)==1) && (theJetHFlav_JetSubCalc_PtOrdered->at(ijet)==5)  ) // for study of csv related values -wz, 2020 May
	   jettype = 1;
         else if ( (theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040) && (theJetHFlav_JetSubCalc_PtOrdered->at(ijet) !=5) )
	//else if (  (theJetBTag_JetSubCalc_PtOrdered->at(ijet)==1) && (theJetHFlav_JetSubCalc_PtOrdered->at(ijet) !=5) )
	   jettype = 2;
        else if ( (theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)<0.3040) && (theJetHFlav_JetSubCalc_PtOrdered->at(ijet) ==5) ) 
	//else if (  (theJetBTag_JetSubCalc_PtOrdered->at(ijet)!=1) && (theJetHFlav_JetSubCalc_PtOrdered->at(ijet) ==5) ) 
	   jettype = 3;
        else if ( (theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)<0.3040)  && (theJetHFlav_JetSubCalc_PtOrdered->at(ijet) !=5) ) 
        //else if (  (theJetBTag_JetSubCalc_PtOrdered->at(ijet)!=1) && (theJetHFlav_JetSubCalc_PtOrdered->at(ijet) !=5) ) 
           jettype = 4;

//		if(theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet) > 0.4941){
        if(theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040){
 	//if(theJetBTag_JetSubCalc_PtOrdered->at(ijet) == 1) {
	   //changed to > in line above because we want jets that pass the csv cut 
	   njetscsv+=1;
	   totalPtCSV += theJetPt_JetSubCalc_PtOrdered->at(ijet);
//	   aveCSV += theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet); 
//	   aveCSVpt += (theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet))*theJetPt_JetSubCalc_PtOrdered->at(ijet);
	   aveCSV += AK4JetDeepFlavb_MultiLepCalc_PtOrdered->at(ijet)+ AK4JetDeepFlavbb_MultiLepCalc_PtOrdered->at(ijet)+AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered->at(ijet);
	   aveCSVpt += (AK4JetDeepFlavb_MultiLepCalc_PtOrdered->at(ijet)+ AK4JetDeepFlavbb_MultiLepCalc_PtOrdered->at(ijet)+AK4JetDeepFlavlepb_MultiLepCalc_PtOrdered->at(ijet))*theJetPt_JetSubCalc_PtOrdered->at(ijet);

//	   aveCSVpt += theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)*theJetPt_JetSubCalc_PtOrdered->at(ijet);
	}
	if (ijet==1){
            secondJetPt = theJetPt_JetSubCalc_PtOrdered->at(ijet);
        }
	if (ijet==4){        
            fifthJetPt = theJetPt_JetSubCalc_PtOrdered->at(ijet);
        }
       	if (ijet==5){
            sixthJetPt = theJetPt_JetSubCalc_PtOrdered->at(ijet);
        }
        		
        TLorentzVector jetTmp, bjetTmp;   		
	jetTmp.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(ijet),theJetEta_JetSubCalc_PtOrdered->at(ijet),theJetPhi_JetSubCalc_PtOrdered->at(ijet),theJetEnergy_JetSubCalc_PtOrdered->at(ijet));	
//        v_pair_jet_CSV.push_back(make_pair(jetTmp, theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet)));
        v_pair_jet_CSV.push_back(make_pair(jetTmp, theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)) );
//	v_pair_jet_CSV.push_back(make_pair(jetTmp, theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet) ));       
 
        if((lep + jetTmp).M() < minMleppJet) {
          minMleppJet = fabs((lep + jetTmp).M());
          deltaR_lepJetInMinMljet  = jetTmp.DeltaR(lep);
          deltaPhi_lepJetInMinMljet = jetTmp.DeltaPhi(lep);
        }		
//		if(theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet) > 0.4941){       
        if(theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040){ 
	//if(theJetBTag_JetSubCalc_PtOrdered->at(ijet) == 1) {
          if((lep + jetTmp).M() < tmp_minMleppBjet) {
            tmp_minMleppBjet = fabs((lep + jetTmp).M() );
            deltaR_lepbJetInMinMlb = jetTmp.DeltaR(lep);
            deltaPhi_lepbJetInMinMlb = jetTmp.DeltaPhi(lep);
            tmpJetInd = ijet;
          }        
        }

        bool stop = 0;
        if (tmpJetInd==0){
          bjetTmp.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(tmpJetInd),theJetEta_JetSubCalc_PtOrdered->at(tmpJetInd),theJetPhi_JetSubCalc_PtOrdered->at(tmpJetInd),theJetEnergy_JetSubCalc_PtOrdered->at(tmpJetInd)); 
          for(unsigned int ijet = 1; ijet < theJetPt_JetSubCalc_PtOrdered->size(); ijet++){        
//          if((theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet) > 0.4941) && stop == 0 ){
            if((theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040) && stop ==0){
	    //if((theJetBTag_JetSubCalc_PtOrdered->at(ijet) == 1) && stop == 0 ){
              stop = 1;
              bjetTmp.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(ijet),theJetEta_JetSubCalc_PtOrdered->at(ijet),theJetPhi_JetSubCalc_PtOrdered->at(ijet),theJetEnergy_JetSubCalc_PtOrdered->at(ijet)); 
              deltaR_lepbJetNotInMinMlb = bjetTmp.DeltaR(lep);        
            }
          }     
        }
        if (tmpJetInd>0){        
          stop = 0;
          for(unsigned int ijet = 0; ijet < tmpJetInd; ijet++){        
//                if((theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet) > 0.4941) && stop == 0 ){
            if((theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040) && stop ==0){
           // if((theJetBTag_JetSubCalc_PtOrdered->at(ijet) == 1) && stop == 0 ){
              stop = 1;
              bjetTmp.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(ijet),theJetEta_JetSubCalc_PtOrdered->at(ijet),theJetPhi_JetSubCalc_PtOrdered->at(ijet),theJetEnergy_JetSubCalc_PtOrdered->at(ijet)); 
              deltaR_lepbJetNotInMinMlb = bjetTmp.DeltaR(lep);        
            }
          }
          if (stop == 0){
            for(unsigned int ijet = tmpJetInd+1; ijet < theJetPt_JetSubCalc_PtOrdered->size(); ijet++){        
//                    if((theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet) > 0.4941) && stop == 0 ){
             if((theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040) && stop ==0){
	   //   if((theJetBTag_JetSubCalc_PtOrdered->at(ijet) == 1) && stop == 0 ){	
                stop = 1;
                bjetTmp.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(ijet),theJetEta_JetSubCalc_PtOrdered->at(ijet),theJetPhi_JetSubCalc_PtOrdered->at(ijet),theJetEnergy_JetSubCalc_PtOrdered->at(ijet)); 
                deltaR_lepbJetNotInMinMlb = bjetTmp.DeltaR(lep);        
              }
            }                
          }
        }     

        v_allJets.push_back(jetTmp);
//        v_DCSV_allJets.push_back(theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet));
//	    csvJet1 = theJetDeepCSVb_JetSubCalc_PtOrdered->at(0)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(0);
//	    csvJet2 = theJetDeepCSVb_JetSubCalc_PtOrdered->at(1)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(1);
//	    csvJet3 = theJetDeepCSVb_JetSubCalc_PtOrdered->at(2)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(2);
//	    csvJet4 = theJetDeepCSVb_JetSubCalc_PtOrdered->at(3)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(3);	    

	v_DCSV_allJets.push_back(theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet));
//	v_DCSV_jettype_allJets.push_back(make_pair(AK4JetDeepCSVb_MultiLepCalc_PtOrdered->at(ijet)+AK4JetDeepCSVbb_MultiLepCalc_PtOrdered->at(ijet), jettype) );	
	if (ijet==0) {
	    csvJet1 = theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet); 
	}
	else if (ijet==1) {
            csvJet2 = theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet); 
	}
	else if (ijet==2) {
            csvJet3 = theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet); 
	}
	else if (ijet==3) {
            csvJet4 = theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet); 
	}


//	v_DCSV_allJets.push_back(theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet));
//	  csvJet1 = theJetDeepFlavB_JetSubCalc_PtOrdered->at(0);
//          csvJet2 = theJetDeepFlavB_JetSubCalc_PtOrdered->at(1);
//          csvJet3 = theJetDeepFlavB_JetSubCalc_PtOrdered->at(2);
//          csvJet4 = theJetDeepFlavB_JetSubCalc_PtOrdered->at(3);	  
        	    
	totalJetPt+=theJetPt_JetSubCalc_PtOrdered->at(ijet);
	totalJetE+=theJetEnergy_JetSubCalc_PtOrdered->at(ijet);
	deltaPhifromMET_ = TVector2::Phi_mpi_pi(theJetPhi_JetSubCalc_PtOrdered->at(ijet) - corr_met_phi_MultiLepCalc);
	deltaPhi_METjets.push_back(deltaPhifromMET_);
	if(min_deltaPhi_METjets>fabs(deltaPhifromMET_)){min_deltaPhi_METjets=fabs(deltaPhifromMET_);}
	if(abs(deltaPhifromMET_)>TMath::Pi()/2){hemiout+=theJetPt_JetSubCalc_PtOrdered->at(ijet);}				
	
//		if(!(theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet) > 0.4941)) continue; //without b-tag SFs
        if(!(theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040)) continue;
	//if(!(theJetBTag_JetSubCalc_PtOrdered->at(ijet) == 1) ) continue;
	
	bjet1.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(ijet),theJetEta_JetSubCalc_PtOrdered->at(ijet),theJetPhi_JetSubCalc_PtOrdered->at(ijet),theJetEnergy_JetSubCalc_PtOrdered->at(ijet));	
	HT_bjets+=theJetPt_JetSubCalc_PtOrdered->at(ijet);
	if (theJetPt_JetSubCalc_PtOrdered->at(ijet) < BJetLeadPt-0.001 && theJetPt_JetSubCalc_PtOrdered->at(ijet) >= BjetSecondPt) BjetSecondPt = theJetPt_JetSubCalc_PtOrdered->at(ijet);
		//different float precision between theJetPt_JetSubCalc_PtOrdered->at(ijet) and BJetLeadPt
		//require at least 0.001 between them to avoid double counting the leading bjet pt

	double lbdr_ = (bjet1).DeltaR(lep);
	double masslb = (lep+bjet1).M();
	double ptlb = (lep+bjet1).Pt();
	if(lbdr_<minDR_lepBJet){
	  minDR_lepBJet=lbdr_;
	  mass_lepBJet_mindr=masslb;
	}
	if(mass_lepBJet0<0){
	  mass_lepBJet0 = masslb;
	  deltaR_lepBJets0 = lbdr_;
	  BJetLeadPt = theJetPt_JetSubCalc_PtOrdered->at(ijet);
	}
	if(ptlb>maxLBpt){
	  maxLBpt = ptlb;
	  deltaR_lepBJet_maxpt = lbdr_;
	}
		        
	for(unsigned int jjet = ijet + 1; jjet < theJetPt_JetSubCalc_PtOrdered->size(); jjet++){
	  if(jjet >= theJetPt_JetSubCalc_PtOrdered->size()) continue;
//		  if(!(theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet) > 0.4941)) continue; //without b-tag SFs	 
          if(!(theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040) ) continue; 
	//  if(!(theJetBTag_JetSubCalc_PtOrdered->at(jjet) == 1) ) continue;
	  bjet2.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(jjet),theJetEta_JetSubCalc_PtOrdered->at(jjet),theJetPhi_JetSubCalc_PtOrdered->at(jjet),theJetEnergy_JetSubCalc_PtOrdered->at(jjet));		  
          MT2bb = mt2(bjet1,bjet2,met);
          deltaR_lepBJets1 = (bjet2).DeltaR(lep);		  
	  npairs += 1.0;
	  double pairmass = (bjet1+bjet2).M();
	  double pairmasslep = (lep+bjet1+bjet2).M();
	  double pairdr = (bjet1).DeltaR(bjet2);
	  double pairdphi = (bjet1).DeltaPhi(bjet2);
	  double pairdeta = bjet1.Eta() - bjet2.Eta();
	  double pairpt = (bjet1+bjet2).Pt();
	  aveBBdr += (bjet1).DeltaR(bjet2);
	  if(pairmass > maxBBmass){
	    maxBBmass = pairmass;	    
	    mass_maxBBmass = pairmass;
	  }
	  if(pairdr < minBBdr){
	    minBBdr = pairdr;
	    mass_minBBdr = pairmass;
	    lepDR_minBBdr = (bjet1+bjet2).DeltaR(lep);
	    mass_lepBB_minBBdr = pairmasslep;
	    deltaR_minBB = pairdr; 
	  }
	  if(fabs(pairdphi) > maxBBdphi){
	    maxBBdphi = fabs(pairdphi);
	    deltaPhi_maxBB = pairdphi;
	  }		  
	  if(fabs(pairdeta) > maxBBdeta){
	    maxBBdeta = fabs(pairdeta);
	    deltaEta_maxBB = pairdeta;
	  }
	  if(pairpt > maxBBpt){
	    maxBBpt = pairpt;
       	    mass_maxBBpt = pairmass;
	  }		  
	}
     }  // jet loop     
     

//     cout << " End of jet loop ";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////HT without the best jet where best jet is the one used in leptonic top reconstruction//////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      bestJetinWjet = bestJet( corr_met_phi_MultiLepCalc, corr_met_MultiLepCalc, lepM, lep, 
                               theJetPt_JetSubCalc_PtOrdered, theJetEta_JetSubCalc_PtOrdered, theJetPhi_JetSubCalc_PtOrdered, theJetEnergy_JetSubCalc_PtOrdered);
      TLorentzVector totalJetVectSum;

      HT_woBESTjet = -100;
      MT_woBESTjet = -100;
      PT_woBESTjet = -100;
      M_woBESTjet = -100;
      M_allJet_W = -100;
      for(unsigned int njet = 0; njet < v_allJets.size(); ++njet){
         totalJetVectSum += v_allJets[njet];
      }
      M_allJet_W = (totalJetVectSum + Wlv).M();
      HT_woBESTjet = AK4HT - bestJetinWjet.Pt();
      MT_woBESTjet = (totalJetVectSum-bestJetinWjet).Mt();
      PT_woBESTjet = (totalJetVectSum-bestJetinWjet).Pt();
      M_woBESTjet = (totalJetVectSum-bestJetinWjet).M();      


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// trijet selection ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
     bool mom_W = false;
     bool WfromTop = false;
     bool WnotFromTop = false;
     if (isElectron==1 && elNumberOfMothers_MultiLepCalc->size()>0 ){
//        for(int ind = 0; ind < elNumberOfMothers_MultiLepCalc->at(0); ind++){
	for(unsigned int ind = 0; ind < elMother_id_MultiLepCalc->size(); ind++) {	
            if(abs(elMother_id_MultiLepCalc->at(ind))==24) {mom_W=true;}
            if(abs(elMother_id_MultiLepCalc->at(ind))==6 && mom_W) {WfromTop=true;}            
        }
      }  

     if (isMuon==1 && muNumberOfMothers_MultiLepCalc->size()>0 ){
  //      for(int ind = 0; ind < muNumberOfMothers_MultiLepCalc->at(0); ind++){
	for(unsigned int ind = 0; ind < muMother_id_MultiLepCalc->size(); ind++) {
            if(abs(muMother_id_MultiLepCalc->at(ind))==24) {mom_W=true;}
            if(abs(muMother_id_MultiLepCalc->at(ind))==6 && mom_W) {WfromTop=true;}            
        }
	 }

     std::string bitmask(3,1);
     bitmask.resize(v_allJets.size(),0);
     double tempTtrijetMass = 0;
     double Mag_Trijet = 1e9;         
     double ScalarSumpT_Trijet = 1e9;
     double DCSV_BestTOPjet1 = 0;
     double DCSV_BestTOPjet2 = 0;
     double DCSV_BestTOPjet3 = 0;  
     double trijetVectSumPt = 0;  
     GD_DCSV_jetNotdijet.clear();
     GD_pTrat.clear();
     nGD_trijet = -10;             
    TLorentzVector genLepton;
    int genLeptonCounter=0;

    is_genMissingDaughter = false;
    is_genFourTopsOnelepton = false;
    
    std::vector<TLorentzVector> genTops;
    std::vector<double> v_minDR_GenRecoTop;
        
    if(topPt_TTbarMassCalc->size()*2 != topWPt_TTbarMassCalc->size()){
        is_genMissingDaughter = true;
    }

    int genleptonCount = 0;
    for(unsigned int nTop = 0; nTop < (topWID_TTbarMassCalc->size()); nTop++){
        if(abs(topWID_TTbarMassCalc->at(nTop)) == 11 || abs(topWID_TTbarMassCalc->at(nTop)) == 13 || abs(topWID_TTbarMassCalc->at(nTop)) == 15){ 
            genleptonCount++;
        }
    }
    int num_genJets_passCuts = 0;
    TLorentzVector tempGenWd1, tempGenWd2;    
    TLorentzVector tempGenb;
    
    unsigned int nGenTop = 0;
    if(isTTbar) nGenTop = 2;
    if(isTTTW || isTTTJ) nGenTop = 3;
    if(isTTTT) nGenTop = 4;
    if (topPt_TTbarMassCalc->size() == nGenTop && genleptonCount == 1 && !is_genMissingDaughter){
        allLeptonicWcount++;
        is_genFourTopsOnelepton = true;
        for(unsigned int nTop = 0; nTop < topPt_TTbarMassCalc->size(); nTop++){
            if(abs(topWID_TTbarMassCalc->at(nTop*2)) > 6 || abs(topWID_TTbarMassCalc->at(nTop*2+1)) > 6){ 
                continue; 
            }
            tempGenWd1.SetPtEtaPhiE(topWPt_TTbarMassCalc->at(nTop*2),topWEta_TTbarMassCalc->at(nTop*2),topWPhi_TTbarMassCalc->at(nTop*2),topWEnergy_TTbarMassCalc->at(nTop*2));	
            tempGenWd2.SetPtEtaPhiE(topWPt_TTbarMassCalc->at(nTop*2+1),topWEta_TTbarMassCalc->at(nTop*2+1),topWPhi_TTbarMassCalc->at(nTop*2+1),topWEnergy_TTbarMassCalc->at(nTop*2+1));	        
            tempGenb.SetPtEtaPhiE(topbPt_TTbarMassCalc->at(nTop),topbEta_TTbarMassCalc->at(nTop),topbPhi_TTbarMassCalc->at(nTop),topbEnergy_TTbarMassCalc->at(nTop));
            if((tempGenWd1.Pt()>30 && tempGenWd2.Pt()>30 && tempGenb.Pt()>30) && (tempGenWd1.Eta()<2.4 && tempGenWd2.Eta()<2.4 && tempGenb.Eta()<2.4)){num_genJets_passCuts++;}
        }        
    }
//    std::cout<<"is_genMissingDaughter : "<<is_genMissingDaughter<<std::endl;
//    std::cout<<"is_genFourTopsOnelepton : "<<is_genFourTopsOnelepton<<std::endl;    
//    std::cout<<"num_genJets_passCuts : "<<num_genJets_passCuts<<std::endl;        
//    std::cout<<"WfromTop : "<<WfromTop<<std::endl;            
    if (!is_genMissingDaughter && is_genFourTopsOnelepton && num_genJets_passCuts>0 && (WfromTop)){
        TLorentzVector tempGenTop;
        TLorentzVector tempGenTopWd1, tempGenTopWd2;    
        TLorentzVector tempGenTopb;

        int idx_minDR = -10;
        std::vector<double> v_deltalR;        
        std::vector<TLorentzVector> v_GD_Trijets;                    
        std::vector<TLorentzVector> v_GD_jets;                        
        std::vector<double> v_GD_DCSV_jets;                            

        std::vector<TLorentzVector> v_BD_Trijets;                    
        std::vector<TLorentzVector> v_BD_jets;                        
        std::vector<double> v_BD_DCSV_jets;                            
        
        Trijet(
            v_trijet, 
            v_DCSV_trijet, 
            v_allJets, 
            v_DCSV_allJets,

            v_GD_Trijets,                    
            v_GD_jets,                     
            v_GD_DCSV_jets,                          

            v_BD_Trijets,                   
            v_BD_jets,                       
            v_BD_DCSV_jets,                            

            topPt_TTbarMassCalc,

            topWID_TTbarMassCalc,
            topWPt_TTbarMassCalc,
            topWEta_TTbarMassCalc,
            topWPhi_TTbarMassCalc,
            topWEnergy_TTbarMassCalc,

            topbPt_TTbarMassCalc,
            topbEta_TTbarMassCalc,
            topbPhi_TTbarMassCalc,
            topbEnergy_TTbarMassCalc, 
            num_GD_trijet,
            num_BD_trijet
        );  

        nGD_trijet = num_GD_trijet;

        double tempMinDR = 10000;
        int tempBestTrijetIdx = -10;
        if(v_GD_Trijets.size()>0){
            for(unsigned int idx = 0; idx<v_GD_Trijets.size(); idx++){
                for(unsigned int nTop = 0; nTop < topPt_TTbarMassCalc->size(); nTop++){
                    if(abs(topWID_TTbarMassCalc->at(nTop*2)) > 6 || abs(topWID_TTbarMassCalc->at(nTop*2+1)) > 6){
                        continue; 
                    }
                    tempGenTop.SetPtEtaPhiE(topPt_TTbarMassCalc->at(nTop),topEta_TTbarMassCalc->at(nTop),topPhi_TTbarMassCalc->at(nTop),topEnergy_TTbarMassCalc->at(nTop));
                    if(v_GD_Trijets[idx].DeltaR(tempGenTop)<tempMinDR){
                        tempMinDR = v_GD_Trijets[idx].DeltaR(tempGenTop);
                        tempBestTrijetIdx = idx;
                    }
                }
            }
            if(num_genJets_passCuts == 2 and v_GD_Trijets.size()==1){
                TLorentzVector testGenWd1, testGenWd2;
                TLorentzVector testGenb;                
                for(unsigned int nTop = 0; nTop < topPt_TTbarMassCalc->size(); nTop++){
                    if(abs(topWID_TTbarMassCalc->at(nTop*2)) > 6 || abs(topWID_TTbarMassCalc->at(nTop*2+1)) > 6){ 
                        continue; 
                    }
                    testGenWd1.SetPtEtaPhiE(topWPt_TTbarMassCalc->at(nTop*2),topWEta_TTbarMassCalc->at(nTop*2),topWPhi_TTbarMassCalc->at(nTop*2),topWEnergy_TTbarMassCalc->at(nTop*2));	
                    testGenWd2.SetPtEtaPhiE(topWPt_TTbarMassCalc->at(nTop*2+1),topWEta_TTbarMassCalc->at(nTop*2+1),topWPhi_TTbarMassCalc->at(nTop*2+1),topWEnergy_TTbarMassCalc->at(nTop*2+1));	        
                    testGenb.SetPtEtaPhiE(topbPt_TTbarMassCalc->at(nTop),topbEta_TTbarMassCalc->at(nTop),topbPhi_TTbarMassCalc->at(nTop),topbEnergy_TTbarMassCalc->at(nTop));
                }
            }
            BestTOPjet1 = v_GD_jets[tempBestTrijetIdx*3];
            BestTOPjet2 = v_GD_jets[tempBestTrijetIdx*3+1];
            BestTOPjet3 = v_GD_jets[tempBestTrijetIdx*3+2];
            DCSV_BestTOPjet1= v_GD_DCSV_jets[tempBestTrijetIdx*3];
            DCSV_BestTOPjet2= v_GD_DCSV_jets[tempBestTrijetIdx*3+1];
            DCSV_BestTOPjet3= v_GD_DCSV_jets[tempBestTrijetIdx*3+2];
        
            Mag_Trijet = (BestTOPjet1+BestTOPjet2+BestTOPjet3).Mag();
            trijetVectSumPt = TMath::Sqrt(pow((BestTOPjet1+BestTOPjet2+BestTOPjet3).Px(),2)+pow((BestTOPjet1+BestTOPjet2+BestTOPjet3).Py(),2));
            ScalarSumpT_Trijet = (BestTOPjet1.Pt()+BestTOPjet2.Pt()+BestTOPjet3.Pt());  
            GD_pTrat.push_back(trijetVectSumPt/ScalarSumpT_Trijet);                                            
            GD_Ttrijet_TopMass.push_back((BestTOPjet1+BestTOPjet2+BestTOPjet3).M());
            double v_dr[3];
            TLorentzVector dijet, jetNotdijet;     
            v_dr[0] = BestTOPjet1.DeltaR(BestTOPjet2);
            v_dr[1] = BestTOPjet1.DeltaR(BestTOPjet3);
            v_dr[2] = BestTOPjet2.DeltaR(BestTOPjet3); 
            int idx_minDR_jetCombo = std::min_element(v_dr, v_dr+3) - v_dr;
            if(idx_minDR_jetCombo==0){
             dijet = BestTOPjet1+BestTOPjet2;
             jetNotdijet = BestTOPjet3;
             GD_DCSV_jetNotdijet.push_back(DCSV_BestTOPjet3);
            }
            else if (idx_minDR_jetCombo==1){                                     
             dijet = BestTOPjet1+BestTOPjet3;
             jetNotdijet = BestTOPjet2;
             GD_DCSV_jetNotdijet.push_back(DCSV_BestTOPjet2);         
            }
            else if (idx_minDR_jetCombo==2){
             dijet = BestTOPjet2+BestTOPjet3;     
             jetNotdijet = BestTOPjet1;
             GD_DCSV_jetNotdijet.push_back(DCSV_BestTOPjet1);         
            }
            GD_Mass_minDR_dijet.push_back(dijet.M());
            GD_DR_Tridijet.push_back((BestTOPjet1+BestTOPjet2+BestTOPjet3).DeltaR(dijet));
            GD_DR_Trijet_jetNotdijet.push_back((BestTOPjet1+BestTOPjet2+BestTOPjet3).DeltaR(jetNotdijet));
            TLorentzVector totalSumJetVect, totalSumJetVect_noTrijet;
            for(unsigned int njet = 0; njet < v_allJets.size(); ++njet){
            totalSumJetVect += v_allJets[njet];
            }
            totalSumJetVect_noTrijet = totalSumJetVect-BestTOPjet1-BestTOPjet2-BestTOPjet3;
            MHRE = totalSumJetVect_noTrijet.M();
            HTx = AK4HT-BestTOPjet1.Pt()-BestTOPjet2.Pt()-BestTOPjet3.Pt();
        }
        else{
            GD_pTrat.clear();
            GD_Ttrijet_TopMass.clear();
            GD_DCSV_jetNotdijet.clear();
            GD_Mass_minDR_dijet.clear();           
            GD_DR_Tridijet.clear();
            GD_DR_Trijet_jetNotdijet.clear();
            MHRE = -10;
            HTx = -10;            
        }

        double DCSV_BADTOPjet1=0;
        double DCSV_BADTOPjet2=0;
        double DCSV_BADTOPjet3=0;
        trijetVectSumPt = 0;     
        BD_pTrat.clear();
        BD_DCSV_jetNotdijet.clear();
        for (unsigned int idx = 0; idx < v_BD_Trijets.size(); idx++){
            BADTOPjet1     = v_BD_jets[idx*3];
            BADTOPjet2     = v_BD_jets[idx*3+1];                
            BADTOPjet3     = v_BD_jets[idx*3+2];                            
            DCSV_BADTOPjet1     = v_BD_DCSV_jets[idx*3];
            DCSV_BADTOPjet2     = v_BD_DCSV_jets[idx*3+1];                
            DCSV_BADTOPjet3     = v_BD_DCSV_jets[idx*3+2];     
            BD_Ttrijet_TopMass.push_back((BADTOPjet1+BADTOPjet2+BADTOPjet3).M());        
            double v_BADdr[3];
            TLorentzVector BAD_dijet, jetNotdijet;     
            v_BADdr[0] = BADTOPjet1.DeltaR(BADTOPjet2);
            v_BADdr[1] = BADTOPjet2.DeltaR(BADTOPjet3);
            v_BADdr[2] = BADTOPjet2.DeltaR(BADTOPjet3); 

            int idx_minDR_jetCombo = std::min_element(v_BADdr, v_BADdr+3) - v_BADdr;
            if(idx_minDR_jetCombo==0){
                BAD_dijet = BADTOPjet1+BADTOPjet2;
                jetNotdijet = BADTOPjet3;
                BD_DCSV_jetNotdijet.push_back(DCSV_BADTOPjet3);
            }
            else if (idx_minDR_jetCombo==1){                                     
                BAD_dijet = BADTOPjet1+BADTOPjet3;
                jetNotdijet = BADTOPjet2;
                BD_DCSV_jetNotdijet.push_back(DCSV_BADTOPjet2);
            } 
            else if (idx_minDR_jetCombo==2){ 
                BAD_dijet = BADTOPjet2+BADTOPjet3;     
                jetNotdijet = BADTOPjet1;
                BD_DCSV_jetNotdijet.push_back(DCSV_BADTOPjet1);
            }
            BD_Mass_minDR_dijet.push_back(BAD_dijet.M());
            trijetVectSumPt = TMath::Sqrt(pow((BADTOPjet1+BADTOPjet2+BADTOPjet3).Px(),2)+pow((BADTOPjet1+BADTOPjet2+BADTOPjet3).Py(),2));
            ScalarSumpT_Trijet = (BADTOPjet1.Pt()+BADTOPjet2.Pt()+BADTOPjet3.Pt());
            BD_pTrat.push_back(trijetVectSumPt/ScalarSumpT_Trijet);
            BD_DR_Tridijet.push_back((BADTOPjet1+BADTOPjet2+BADTOPjet3).DeltaR(BAD_dijet));                                                                            
            BD_DR_Trijet_jetNotdijet.push_back((BADTOPjet1+BADTOPjet2+BADTOPjet3).DeltaR(jetNotdijet));
        }
    }
    else{
        GD_pTrat.clear();
        GD_Ttrijet_TopMass.clear();
        GD_DCSV_jetNotdijet.clear();
        GD_Mass_minDR_dijet.clear();           
        GD_DR_Tridijet.clear();
        GD_DR_Trijet_jetNotdijet.clear();    
        num_GD_trijet = -10;
        num_BD_trijet = -10;            
        MHRE = -10;
        HTx = -10;            
    }

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
     std::sort(v_DCSV_allJets.rbegin(), v_DCSV_allJets.rend());
     firstcsvb_bb = v_DCSV_allJets.at(0);
     secondcsvb_bb = v_DCSV_allJets.at(1);
     thirdcsvb_bb = v_DCSV_allJets.at(2);
     fourthcsvb_bb = v_DCSV_allJets.at(3);

//     std::sort(v_DCSV_jettype_allJets.rbegin(), v_DCSV_jettype_allJets.rend());
//     if (v_DCSV_jettype_allJets[2].second ==1) {
//       thirdcsvb_bb_BTagBHad = v_DCSV_jettype_allJets[2].first;
//     }
//     if (v_DCSV_jettype_allJets[2].second ==2) {
//       thirdcsvb_bb_BTagNBHad = v_DCSV_jettype_allJets[2].first;
//     }
//     if (v_DCSV_jettype_allJets[2].second ==3) {
//       thirdcsvb_bb_NBTagBHad = v_DCSV_jettype_allJets[2].first;
//     }
//     if (v_DCSV_jettype_allJets[2].second ==4) {
//       thirdcsvb_bb_NBTagNBHad = v_DCSV_jettype_allJets[2].first;
//     }

     if (BJetLeadPt>0) HT_2m = AK4HT - (BJetLeadPt+BjetSecondPt);
     else{HT_2m=-100;}

//////////////////////////////////////////
// build centrality //
//////////////////////////////////////////

      if(npairs!=0){aveBBdr = (aveBBdr+1)/npairs;}
      if(njetscsv!=0){
      	aveCSV = (aveCSV+1)/njetscsv;
      	aveCSVpt = (aveCSVpt+1)/totalPtCSV;
      	}
      else{aveCSV = coin; aveCSVpt = coin;}

      if(totalJetE!=0) {
        centrality = totalJetPt/totalJetE;
        
      }	  
      double diff_temppairmass = 1e9;
      TLorentzVector jet1_W, jet2_W;
      // FIND LIGHT PAIRS
	  for(unsigned int ijet = 0; ijet < theJetPt_JetSubCalc_PtOrdered->size(); ijet++){
//		if((theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet) > 0.4941)) continue; //without b-tag SFs
                if(theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040) continue;
		//if(theJetBTag_JetSubCalc_PtOrdered->at(ijet) == 1 ) continue;
		jet1.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(ijet),theJetEta_JetSubCalc_PtOrdered->at(ijet),theJetPhi_JetSubCalc_PtOrdered->at(ijet),theJetEnergy_JetSubCalc_PtOrdered->at(ijet));

		for(unsigned int jjet = ijet + 1; jjet < theJetPt_JetSubCalc_PtOrdered->size(); jjet++){
		  if(jjet >= theJetPt_JetSubCalc_PtOrdered->size()) continue;
//		  if((theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet) > 0.4941)) continue; //without b-tag SFs
                  if(theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040) continue;
	          //if(theJetBTag_JetSubCalc_PtOrdered->at(jjet) == 1 ) continue; 
		  jet2.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(jjet),theJetEta_JetSubCalc_PtOrdered->at(jjet),theJetPhi_JetSubCalc_PtOrdered->at(jjet),theJetEnergy_JetSubCalc_PtOrdered->at(jjet));

		  double pairdr = (jet1).DeltaR(jet2);
		  double pairmass = (jet1+jet2).M();
		  double pairmasslep = (lep+jet1+jet2).M();
		  if(pairdr < minLLdr){
			minLLdr = pairdr;
			mass_minLLdr = pairmass;
			mass_lepJJ_minJJdr = pairmasslep;
		  }
		  if(fabs(pairmass-MW)<diff_temppairmass){
			diff_temppairmass = pairmass;
			jet1_W = jet1;
			jet2_W = jet2;			
		  }
		}
	  }
	  W_PtdM = (jet1_W+jet2_W).Pt()/(jet1_W+jet2_W).M();

      sort(v_pair_jet_CSV.begin(), v_pair_jet_CSV.end(), compareFunc);  
      invM_jet34 = (v_pair_jet_CSV[2].first+v_pair_jet_CSV[3].first).M();
      pT_3rdcsvJet = v_pair_jet_CSV[2].first.Pt();
      pT_4thcsvJet = v_pair_jet_CSV[3].first.Pt();
      
      double totalCSV = 0;
      for (unsigned int ind = 0; ind < v_pair_jet_CSV.size(); ind++){
        if (v_pair_jet_CSV[ind].second>0){
          totalCSV += v_pair_jet_CSV[ind].second;
        }
      }
      mean_csv = totalCSV/NJets_JetSubCalc;

      if (NJets_JetSubCalc > 5){
          invM_jet35 = (v_pair_jet_CSV[2].first+v_pair_jet_CSV[4].first).M();
          invM_jet45 = (v_pair_jet_CSV[3].first+v_pair_jet_CSV[4].first).M();      
      }
      
      if (NJets_JetSubCalc > 6){
          pTjet5_6 = theJetPt_JetSubCalc_PtOrdered->at(4)+theJetPt_JetSubCalc_PtOrdered->at(5);
          invM_jet36 = (v_pair_jet_CSV[2].first+v_pair_jet_CSV[5].first).M();
          invM_jet46 = (v_pair_jet_CSV[3].first+v_pair_jet_CSV[5].first).M();
          invM_jet56 = (v_pair_jet_CSV[4].first+v_pair_jet_CSV[5].first).M();                                      
      }      
      
	  jet1.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(0),theJetEta_JetSubCalc_PtOrdered->at(0),theJetPhi_JetSubCalc_PtOrdered->at(0),theJetEnergy_JetSubCalc_PtOrdered->at(0));
	  jet2.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(1),theJetEta_JetSubCalc_PtOrdered->at(1),theJetPhi_JetSubCalc_PtOrdered->at(1),theJetEnergy_JetSubCalc_PtOrdered->at(1));
	  jet3.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(2),theJetEta_JetSubCalc_PtOrdered->at(2),theJetPhi_JetSubCalc_PtOrdered->at(2),theJetEnergy_JetSubCalc_PtOrdered->at(2));	  
	  
	  pt3HT = theJetPt_JetSubCalc_PtOrdered->at(2)/AK4HT;
	  pt4HT = theJetPt_JetSubCalc_PtOrdered->at(3)/AK4HT;
	  	  
      deltaPhi_j1j2 = (jet1).DeltaPhi(jet2);
      alphaT = TMath::Sqrt( (theJetPt_JetSubCalc_PtOrdered->at(1)/theJetPt_JetSubCalc_PtOrdered->at(0)) / (2.0*(1.0-TMath::Cos(deltaPhi_j1j2))) );
      mass_lepJets0 = (lep+jet1).M();
      mass_lepJets1 = (lep+jet2).M();
      mass_lepJets2 = (lep+jet3).M();
/////////////////////////
// build JJJ variables //
/////////////////////////
      for(unsigned int ijet = 0; ijet < theJetPt_JetSubCalc_PtOrdered->size(); ijet++){
		jet1.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(ijet),theJetEta_JetSubCalc_PtOrdered->at(ijet),theJetPhi_JetSubCalc_PtOrdered->at(ijet),theJetEnergy_JetSubCalc_PtOrdered->at(ijet));
		for(unsigned int jjet = ijet + 1; jjet < theJetPt_JetSubCalc_PtOrdered->size(); jjet++){
		  if(jjet >= theJetPt_JetSubCalc_PtOrdered->size()) continue;
		  jet2.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(jjet),theJetEta_JetSubCalc_PtOrdered->at(jjet),theJetPhi_JetSubCalc_PtOrdered->at(jjet),theJetEnergy_JetSubCalc_PtOrdered->at(jjet));
		  for(unsigned int kjet = jjet + 1; kjet < theJetPt_JetSubCalc_PtOrdered->size(); kjet++){
			if(kjet >= theJetPt_JetSubCalc_PtOrdered->size()) continue;	  
			jet3.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(kjet),theJetEta_JetSubCalc_PtOrdered->at(kjet),theJetPhi_JetSubCalc_PtOrdered->at(kjet),theJetEnergy_JetSubCalc_PtOrdered->at(kjet));
			double trippt = (jet1+jet2+jet3).Pt();
			if(trippt > maxJJJpt){
			  maxJJJpt = trippt;
			  mass_maxJJJpt = (jet1+jet2+jet3).M();
			}
		  }
		}
      }

      PtFifthJet = -1;
      int fifthJetInd = 0;
      for(unsigned int ijet = 0; ijet < theJetPt_JetSubCalc_PtOrdered->size(); ijet++){
//		    if(theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet) > 0.4941){     
                    if(theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040) { 
		    //if(theJetBTag_JetSubCalc_PtOrdered->at(ijet) == 1 ) {
      		fifthJetInd+=1;
      		if(fifthJetInd==5){PtFifthJet=theJetPt_JetSubCalc_PtOrdered->at(ijet);}
      		if(fifthJetInd>=5) break;
      		}
      }
      if(fifthJetInd<5){
		for(unsigned int ijet = 0; ijet < theJetPt_JetSubCalc_PtOrdered->size(); ijet++){
//	    	if(theJetDeepCSVb_JetSubCalc_PtOrdered->at(ijet)+theJetDeepCSVbb_JetSubCalc_PtOrdered->at(ijet) < 0.4941){       
                if(!(theJetDeepFlavB_JetSubCalc_PtOrdered->at(ijet)>0.3040) ){ 
		//if(!(theJetBTag_JetSubCalc_PtOrdered->at(ijet) == 1) ) {
			fifthJetInd+=1;
			if(fifthJetInd==5){PtFifthJet=theJetPt_JetSubCalc_PtOrdered->at(ijet);}
			}
		   }
		}      	
	 
/////////////////////////
// Fox-Wolfram moments //
/////////////////////////      
      TLorentzVector jetI, jetJ;
      double HT_alljets = 0;
      for(unsigned int ijet = 0; ijet < theJetPt_JetSubCalc_PtOrdered->size(); ijet++){
		jetI.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(ijet),theJetEta_JetSubCalc_PtOrdered->at(ijet),theJetPhi_JetSubCalc_PtOrdered->at(ijet),theJetEnergy_JetSubCalc_PtOrdered->at(ijet));
		HT_alljets += jetI.Et();
	  }
	  for(unsigned int ijet = 0; ijet < theJetPt_JetSubCalc_PtOrdered->size(); ijet++){
		jetI.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(ijet),theJetEta_JetSubCalc_PtOrdered->at(ijet),theJetPhi_JetSubCalc_PtOrdered->at(ijet),theJetEnergy_JetSubCalc_PtOrdered->at(ijet));
		for(unsigned int jjet = 0; jjet < theJetPt_JetSubCalc_PtOrdered->size(); jjet++){
		  jetJ.SetPtEtaPhiE(theJetPt_JetSubCalc_PtOrdered->at(jjet),theJetEta_JetSubCalc_PtOrdered->at(jjet),theJetPhi_JetSubCalc_PtOrdered->at(jjet),theJetEnergy_JetSubCalc_PtOrdered->at(jjet));
		  double ET_ij_over_ETSum2 = jetI.Et()*jetJ.Et()/pow(HT_alljets,2);
		  double cosTheta_ij = (jetI.Px()*jetJ.Px() + jetI.Py()*jetJ.Py() + jetI.Pz()*jetJ.Pz())/(jetI.Rho()*jetJ.Rho());
		  FW_momentum_0 += ET_ij_over_ETSum2;
		  FW_momentum_1 += ET_ij_over_ETSum2 * cosTheta_ij;
		  FW_momentum_2 += ET_ij_over_ETSum2 * 0.5   * (  3*std::pow(cosTheta_ij,2)- 1);
		  FW_momentum_3 += ET_ij_over_ETSum2 * 0.5   * (  5*std::pow(cosTheta_ij,3)-  3*cosTheta_ij);
		  FW_momentum_4 += ET_ij_over_ETSum2 * 0.125 * ( 35*std::pow(cosTheta_ij,4)- 30*std::pow(cosTheta_ij,2)+3);
		  FW_momentum_5 += ET_ij_over_ETSum2 * 0.125 * ( 63*std::pow(cosTheta_ij,5)- 70*std::pow(cosTheta_ij,3)+15*cosTheta_ij);
		  FW_momentum_6 += ET_ij_over_ETSum2 * 0.0625* (231*std::pow(cosTheta_ij,6)-315*std::pow(cosTheta_ij,4)+105*std::pow(cosTheta_ij,2)-5);
		}
	  }

//////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Sphericity Aplanarity//////////////////////////////
//////////////////////////////////////////////////////////////////////////////////           
      TMatrixD M_Tensor = SpheAplaTensor(v_allJets);
      TVectorD *_pv = new TVectorD(3);      
      M_Tensor.EigenVectors(*_pv);
	  Sphericity = 1.5 * ( (*_pv)[2] + (*_pv)[1] );
	  Aplanarity = 1.5 * ( (*_pv)[2] );	  
//////////////////////////////////////////////////////////////////////////////////     	  

//////////////////////////////////////////////////////////////////////////////////
////////////////// BDT trijet_i (leading 4) built from HOTTaggerCalc ///////////////
     
     if (topDiscriminator_HOTTaggerCalc->size() > 0){
	 float topBDT1(-1.), topBDT2(-1.), topBDT3(-1.), topBDT4(-1.);

	  for (unsigned int itop=0; itop < topDiscriminator_HOTTaggerCalc->size(); itop++) {

	    if (topDiscriminator_HOTTaggerCalc->at(itop) > topBDT1) {
                topBDT4 = topBDT3;
                topBDT3 = topBDT2;
        	topBDT2 = topBDT1;
        	topBDT1 = topDiscriminator_HOTTaggerCalc->at(itop);
            }
	    else if (topDiscriminator_HOTTaggerCalc->at(itop) > topBDT2) {
                topBDT4 = topBDT3;
                topBDT3 = topBDT2;
        	topBDT2 = topDiscriminator_HOTTaggerCalc->at(itop);
            }
            else if (topDiscriminator_HOTTaggerCalc->at(itop) > topBDT3) {
                topBDT4 = topBDT3;
                topBDT3 = topDiscriminator_HOTTaggerCalc->at(itop);
            }
            else if (topDiscriminator_HOTTaggerCalc->at(itop) > topBDT4) {
                topBDT4 = topDiscriminator_HOTTaggerCalc->at(itop);
            }

	  }
 
	  BDTtrijet2 = topBDT2; 
	  BDTtrijet1 = topBDT1;
	  BDTtrijet3 = topBDT3;
	  BDTtrijet4 = topBDT4;	
     }
//////////////////////////////////////////////////////////////////////////////////

////////////////////////////// trijet built from HOT /////////////////////////////

     int n_HOTGood(0), n_HOTBad(0);

     HOTGoodTrijet1_mass = 0.;
     HOTGoodTrijet1_dijetmass = 0.;
     HOTGoodTrijet1_pTratio = 0.;
     HOTGoodTrijet1_dRtridijet = 0.;
     HOTGoodTrijet1_dRtrijetJetnotdijet = 0.;
     HOTGoodTrijet1_csvJetnotdijet = 0.;
     HOTGoodTrijet2_mass = 0.;
     HOTGoodTrijet2_dijetmass = 0.;
     HOTGoodTrijet2_pTratio = 0.;
     HOTGoodTrijet2_dRtridijet = 0.;
     HOTGoodTrijet2_dRtrijetJetnotdijet = 0.;
     HOTGoodTrijet2_csvJetnotdijet = 0.;
     HOTGoodTrijet3_mass = 0.;
     HOTGoodTrijet3_dijetmass = 0.;
     HOTGoodTrijet3_pTratio = 0.;
     HOTGoodTrijet3_dRtridijet = 0.;
     HOTGoodTrijet3_dRtrijetJetnotdijet = 0.;
     HOTGoodTrijet3_csvJetnotdijet = 0.;
     HOTGoodTrijet4_mass = 0.;
     HOTGoodTrijet4_dijetmass = 0.;
     HOTGoodTrijet4_pTratio = 0.;
     HOTGoodTrijet4_dRtridijet = 0.;
     HOTGoodTrijet4_dRtrijetJetnotdijet = 0.;
     HOTGoodTrijet4_csvJetnotdijet = 0.;

     HOTBadTrijet1_mass = 0.;
     HOTBadTrijet1_dijetmass = 0.;
     HOTBadTrijet1_pTratio = 0.;
     HOTBadTrijet1_dRtridijet = 0.;
     HOTBadTrijet1_dRtrijetJetnotdijet = 0.;
     HOTBadTrijet1_csvJetnotdijet = 0.;
     HOTBadTrijet2_mass = 0.;
     HOTBadTrijet2_dijetmass = 0.;
     HOTBadTrijet2_pTratio = 0.;
     HOTBadTrijet2_dRtridijet = 0.;
     HOTBadTrijet2_dRtrijetJetnotdijet = 0.;
     HOTBadTrijet2_csvJetnotdijet = 0.;
     HOTBadTrijet3_mass = 0.;
     HOTBadTrijet3_dijetmass = 0.;
     HOTBadTrijet3_pTratio = 0.;
     HOTBadTrijet3_dRtridijet = 0.;
     HOTBadTrijet3_dRtrijetJetnotdijet = 0.;
     HOTBadTrijet3_csvJetnotdijet = 0.;
     HOTBadTrijet4_mass = 0.;
     HOTBadTrijet4_dijetmass = 0.;
     HOTBadTrijet4_pTratio = 0.;
     HOTBadTrijet4_dRtridijet = 0.;
     HOTBadTrijet4_dRtrijetJetnotdijet = 0.;
     HOTBadTrijet4_csvJetnotdijet = 0.;

      
     for (unsigned int itop=0; itop < topDiscriminator_HOTTaggerCalc->size(); itop++) {

       float v_dR[3];
       unsigned int idjet1,idjet2,idjet3;	    
       TLorentzVector dijet, jetnotdijet;     
       TLorentzVector resolvedTopD1,resolvedTopD2,resolvedTopD3;
       float trijetmass(0.), dijetmass(0.), trijet_pTratio(0.), dRtridijet(0.), dRtrijetJetnotdijet(0.), csvJetnotdijet(0.);

       idjet1 = topJet1Index_HOTTaggerCalc->at(itop);
       idjet2 = topJet2Index_HOTTaggerCalc->at(itop);
       idjet3 = topJet3Index_HOTTaggerCalc->at(itop);

       //Find Best Top
       if(topDiscriminator_HOTTaggerCalc->at(itop)>BestTop_Discriminator){
           BestTop_Discriminator = topDiscriminator_HOTTaggerCalc->at(itop);
           BestTop_Pt = topPt_HOTTaggerCalc->at(itop);
           BestTop_Phi = topPhi_HOTTaggerCalc->at(itop);
           BestTop_Eta = topEta_HOTTaggerCalc->at(itop);
           BestTop_Mass = topMass_HOTTaggerCalc->at(itop);

           BestTop_jet1idx = topJet1Index_HOTTaggerCalc->at(itop);
           BestTop_jet2idx = topJet2Index_HOTTaggerCalc->at(itop);
           BestTop_jet3idx = topJet3Index_HOTTaggerCalc->at(itop); 
       }
       

       resolvedTopD1.SetPtEtaPhiE(theJetPt_JetSubCalc->at(idjet1),theJetEta_JetSubCalc->at(idjet1),theJetPhi_JetSubCalc->at(idjet1),theJetEnergy_JetSubCalc->at(idjet1));
       resolvedTopD2.SetPtEtaPhiE(theJetPt_JetSubCalc->at(idjet2),theJetEta_JetSubCalc->at(idjet2),theJetPhi_JetSubCalc->at(idjet2),theJetEnergy_JetSubCalc->at(idjet2));
       resolvedTopD3.SetPtEtaPhiE(theJetPt_JetSubCalc->at(idjet3),theJetEta_JetSubCalc->at(idjet3),theJetPhi_JetSubCalc->at(idjet3),theJetEnergy_JetSubCalc->at(idjet3));
       v_dR[0] = resolvedTopD1.DeltaR(resolvedTopD2);
       v_dR[1] = resolvedTopD1.DeltaR(resolvedTopD3);
       v_dR[2] = resolvedTopD2.DeltaR(resolvedTopD3); 

       int idx_minDR_jetCombo = std::min_element(v_dR, v_dR+3) - v_dR;
       if(idx_minDR_jetCombo==0){
           dijet = resolvedTopD1+resolvedTopD2;
           jetnotdijet = resolvedTopD3;
           csvJetnotdijet = theJetDeepFlavB_JetSubCalc->at(idjet3); 
       }
       else if (idx_minDR_jetCombo==1){                                     
           dijet = resolvedTopD1+resolvedTopD3;
           jetnotdijet = resolvedTopD2;
           csvJetnotdijet = theJetDeepFlavB_JetSubCalc->at(idjet2); 
       }
       else if (idx_minDR_jetCombo==2){
           dijet = resolvedTopD2+resolvedTopD3;     
           jetnotdijet = resolvedTopD1;
           csvJetnotdijet = theJetDeepFlavB_JetSubCalc->at(idjet1); 
       } 
       trijetmass = (resolvedTopD1+resolvedTopD2+resolvedTopD3).M();
       dijetmass = dijet.M();
       trijet_pTratio =  (resolvedTopD1+resolvedTopD2+resolvedTopD3).Pt()/(resolvedTopD1.Pt()+resolvedTopD2.Pt()+resolvedTopD3.Pt());
       dRtridijet = dijet.DeltaR(resolvedTopD1+resolvedTopD2+resolvedTopD3);
       dRtrijetJetnotdijet = jetnotdijet.DeltaR(resolvedTopD1+resolvedTopD2+resolvedTopD3);

       if ( topDiscriminator_HOTTaggerCalc->at(itop) > topdiscriminator ) {
           n_HOTGood += 1;
           if ( n_HOTGood == 1 ) {
             HOTGoodTrijet1_mass = trijetmass;
     	     HOTGoodTrijet1_dijetmass = dijetmass;
     	     HOTGoodTrijet1_pTratio = trijet_pTratio;
     	     HOTGoodTrijet1_dRtridijet = dRtridijet;
     	     HOTGoodTrijet1_dRtrijetJetnotdijet = dRtrijetJetnotdijet;
     	     HOTGoodTrijet1_csvJetnotdijet = csvJetnotdijet;
           } 
	   else if (n_HOTGood == 2) {
             HOTGoodTrijet2_mass = trijetmass;
             HOTGoodTrijet2_dijetmass = dijetmass;
             HOTGoodTrijet2_pTratio = trijet_pTratio;
             HOTGoodTrijet2_dRtridijet = dRtridijet;
             HOTGoodTrijet2_dRtrijetJetnotdijet = dRtrijetJetnotdijet;
             HOTGoodTrijet2_csvJetnotdijet = csvJetnotdijet;
	   }
           else if (n_HOTGood == 3) {
             HOTGoodTrijet3_mass = trijetmass;
             HOTGoodTrijet3_dijetmass = dijetmass;
             HOTGoodTrijet3_pTratio = trijet_pTratio;
             HOTGoodTrijet3_dRtridijet = dRtridijet;
             HOTGoodTrijet3_dRtrijetJetnotdijet = dRtrijetJetnotdijet;
             HOTGoodTrijet3_csvJetnotdijet = csvJetnotdijet;
           }
           else if (n_HOTGood == 4) {
             HOTGoodTrijet4_mass = trijetmass;
             HOTGoodTrijet4_dijetmass = dijetmass;
             HOTGoodTrijet4_pTratio = trijet_pTratio;
             HOTGoodTrijet4_dRtridijet = dRtridijet;
             HOTGoodTrijet4_dRtrijetJetnotdijet = dRtrijetJetnotdijet;
             HOTGoodTrijet4_csvJetnotdijet = csvJetnotdijet;
           }
       } // end Good

       else {  
	   n_HOTBad += 1;
           if ( n_HOTBad == 1 ) {
             HOTBadTrijet1_mass = trijetmass;
             HOTBadTrijet1_dijetmass = dijetmass;
             HOTBadTrijet1_pTratio = trijet_pTratio;
             HOTBadTrijet1_dRtridijet = dRtridijet;
             HOTBadTrijet1_dRtrijetJetnotdijet = dRtrijetJetnotdijet;
             HOTBadTrijet1_csvJetnotdijet = csvJetnotdijet;
           }
           else if ( n_HOTBad == 2 ) {
             HOTBadTrijet2_mass = trijetmass;
             HOTBadTrijet2_dijetmass = dijetmass;
             HOTBadTrijet2_pTratio = trijet_pTratio;
             HOTBadTrijet2_dRtridijet = dRtridijet;
             HOTBadTrijet2_dRtrijetJetnotdijet = dRtrijetJetnotdijet;
             HOTBadTrijet2_csvJetnotdijet = csvJetnotdijet;
           }
          else if ( n_HOTBad == 3 ) {
             HOTBadTrijet3_mass = trijetmass;
             HOTBadTrijet3_dijetmass = dijetmass;
             HOTBadTrijet3_pTratio = trijet_pTratio;
             HOTBadTrijet3_dRtridijet = dRtridijet;
             HOTBadTrijet3_dRtrijetJetnotdijet = dRtrijetJetnotdijet;
             HOTBadTrijet3_csvJetnotdijet = csvJetnotdijet;
           }
          else if ( n_HOTBad == 4 ) {
             HOTBadTrijet4_mass = trijetmass;
             HOTBadTrijet4_dijetmass = dijetmass;
             HOTBadTrijet4_pTratio = trijet_pTratio;
             HOTBadTrijet4_dRtridijet = dRtridijet;
             HOTBadTrijet4_dRtrijetJetnotdijet = dRtrijetJetnotdijet;
             HOTBadTrijet4_csvJetnotdijet = csvJetnotdijet;
           }
       }  // end Bad


     }  // end of top loop


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////Find the jets with the highest CSVs while not belonging to the tops////////////////////////////
    //

    TLorentzVector lptTB1, lptTB2, hadTB1, hadTB2, lptT, hadT, B1, B2;
    unsigned int lepTopJetIdx = (unsigned int)(recLeptonicTopJetIdx);
    recLeptonicTopJetCSV = float(theJetDeepFlavB_JetSubCalc->at(lepTopJetIdx));
    recLeptonicTopJetPt  = theJetPt_JetSubCalc->at(lepTopJetIdx);

    
    for(unsigned int ijet = 0; ijet < theJetPt_JetSubCalc->size(); ijet++){
    int int_idx = int(ijet);

    if( (int_idx==recLeptonicTopJetIdx)||(int_idx==BestTop_jet1idx)||(int_idx==BestTop_jet2idx)||(int_idx==BestTop_jet3idx)) continue;
        float curr_CSV = float(theJetDeepFlavB_JetSubCalc->at(ijet));
        if(curr_CSV > NoTop_Jet1_CSV){

            if(NoTop_Jet1_CSV!=-10){
                NoTop_Jet2_CSV = NoTop_Jet1_CSV;
                NoTop_Jet2_Pt  = NoTop_Jet1_Pt;
                NoTop_Jet2_Eta = NoTop_Jet1_Eta;
                NoTop_Jet2_Phi = NoTop_Jet1_Phi;
                NoTop_Jet2_Energy = NoTop_Jet1_Energy; 

            }

            NoTop_Jet1_CSV = curr_CSV;
            NoTop_Jet1_Pt  = theJetPt_JetSubCalc->at(ijet);
            NoTop_Jet1_Eta = theJetEta_JetSubCalc->at(ijet);
            NoTop_Jet1_Phi = theJetPhi_JetSubCalc->at(ijet);
            NoTop_Jet1_Energy = theJetEnergy_JetSubCalc->at(ijet);
        }

        if(curr_CSV<NoTop_Jet1_CSV && curr_CSV>NoTop_Jet2_CSV){
            NoTop_Jet2_CSV = curr_CSV;
            NoTop_Jet2_Pt  = theJetPt_JetSubCalc->at(ijet);
            NoTop_Jet2_Eta = theJetEta_JetSubCalc->at(ijet);
            NoTop_Jet2_Phi = theJetPhi_JetSubCalc->at(ijet);
            NoTop_Jet2_Energy = theJetEnergy_JetSubCalc->at(ijet);

        }

        
     

    }
    
    B1.SetPtEtaPhiE(NoTop_Jet1_Pt, NoTop_Jet1_Eta, NoTop_Jet1_Phi, NoTop_Jet1_Energy);
    B2.SetPtEtaPhiE(NoTop_Jet2_Pt, NoTop_Jet2_Eta, NoTop_Jet2_Phi, NoTop_Jet2_Energy);
   
    lptT.SetPtEtaPhiM(recLeptonicTopPt, recLeptonicTopEta, recLeptonicTopPhi, recLeptonicTopMass);
    hadT.SetPtEtaPhiM(BestTop_Pt, BestTop_Eta, BestTop_Phi, BestTop_Mass);

    lptTB1 = lptT+B1;
    lptTB2 = lptT+B2;
    hadTB1 = hadT+B1;
    hadTB2 = hadT+B2;

    LeptonicTB1_M = lptTB1.M();
    LeptonicTB2_M = lptTB2.M();

    LeptonicTB1_Pt = lptTB1.Pt();
    LeptonicTB2_Pt = lptTB2.Pt();

    LeptonicTB1_Eta = lptTB1.Eta();
    LeptonicTB2_Eta = lptTB2.Eta();

    HadronicTB1_M = hadTB1.M();
    HadronicTB2_M = hadTB2.M();
    
    HadronicTB1_Pt = hadTB1.Pt();
    HadronicTB2_Pt = hadTB2.Pt(); 

    HadronicTB1_Eta = hadTB1.Eta();
    HadronicTB2_Eta = hadTB2.Eta();
    


/////////////////////////////////////////////////////////////////////////////////

      b_btagDeepJet2DWeight->Fill();	 
      b_btagDeepJet2DWeight_Pt120->Fill();
      b_btagDeepJet2DWeight_HTnj->Fill();
      b_btagDeepJet2DWeight_HTnj_HFup->Fill();       
      b_btagDeepJet2DWeight_HTnj_HFdn->Fill();      
      b_btagDeepJet2DWeight_HTnj_LFup->Fill();      
      b_btagDeepJet2DWeight_HTnj_LFdn->Fill();      
      b_btagDeepJet2DWeight_HTnj_jesup->Fill();     
      b_btagDeepJet2DWeight_HTnj_jesdn->Fill();     
      b_btagDeepJet2DWeight_HTnj_hfstats1up->Fill();
      b_btagDeepJet2DWeight_HTnj_hfstats1dn->Fill();
      b_btagDeepJet2DWeight_HTnj_hfstats2up->Fill();
      b_btagDeepJet2DWeight_HTnj_hfstats2dn->Fill();
      b_btagDeepJet2DWeight_HTnj_cferr1up->Fill();  
      b_btagDeepJet2DWeight_HTnj_cferr1dn->Fill();  
      b_btagDeepJet2DWeight_HTnj_cferr2up->Fill();  
      b_btagDeepJet2DWeight_HTnj_cferr2dn->Fill();  
      b_btagDeepJet2DWeight_HTnj_lfstats1up->Fill();
      b_btagDeepJet2DWeight_HTnj_lfstats1dn->Fill();
      b_btagDeepJet2DWeight_HTnj_lfstats2up->Fill();
      b_btagDeepJet2DWeight_HTnj_lfstats2dn->Fill();
      b_isTraining->Fill();
      b_xsecEff->Fill();
      b_deltaR_minBB->Fill();
      b_aveBBdr->Fill();
      b_deltaEta_maxBB->Fill();
      b_FW_momentum_2->Fill();
      b_centrality->Fill();
      b_aveCSVpt->Fill();
      b_mass_maxJJJpt->Fill();
      b_maxJJJpt->Fill();
      b_lepDR_minBBdr->Fill();
      b_HT_pt40->Fill();
      b_HT_bjets->Fill();
      b_HT_ratio->Fill();
      b_HT_2m->Fill();
      b_firstcsvb_bb->Fill();
      b_secondcsvb_bb->Fill();
      b_thirdcsvb_bb->Fill();
      b_fourthcsvb_bb->Fill();
      b_PtFifthJet->Fill();
      b_MHRE->Fill();
      b_HTx->Fill();
      b_mass_lepJets0->Fill();
      b_mass_lepJets1->Fill();
      b_mass_lepJets2->Fill();	  	  
      b_mass_minBBdr->Fill();
      b_mass_minLLdr->Fill();
      b_mass_maxBBpt->Fill();
      b_mass_maxBBmass->Fill();
      b_theJetLeadPt->Fill();
      b_deltaR_lepBJets0->Fill();
      b_deltaR_lepBJets1->Fill();	  
      b_minDR_lepBJet->Fill();
      b_minBBdr->Fill();
      b_mass_lepBJet0->Fill();
      b_mass_lepBB_minBBdr->Fill();
      b_mass_lepJJ_minJJdr->Fill();
      b_mass_lepBJet_mindr->Fill();
      b_deltaR_lepBJet_maxpt->Fill();
      b_deltaPhi_maxBB->Fill();
      b_corr_met->Fill();
      b_deltaPhi_lepMET->Fill();
      b_min_deltaPhi_METjets->Fill();
      b_deltaPhi_METjets->Fill();
      b_aveCSV->Fill();
      b_deltaPhi_j1j2->Fill();
      b_alphaT->Fill();
      b_FW_momentum_0->Fill();
      b_FW_momentum_1->Fill();
      b_FW_momentum_3->Fill();
      b_FW_momentum_4->Fill();
      b_FW_momentum_5->Fill();
      b_FW_momentum_6->Fill();
      b_csvJet1->Fill();
      b_csvJet2->Fill();
      b_csvJet3->Fill();
      b_csvJet4->Fill();      
      b_GD_pTrat->Fill();
      b_BD_pTrat->Fill();	  
      b_GD_DR_Tridijet->Fill();
      b_BD_DR_Tridijet->Fill();
      b_GD_Ttrijet_TopMass->Fill();
      b_BD_Ttrijet_TopMass->Fill();
      b_GD_DCSV_jetNotdijet->Fill();
      b_BD_DCSV_jetNotdijet->Fill();      
      b_GD_Mass_minDR_dijet->Fill();	  
      b_BD_Mass_minDR_dijet->Fill();	  	  
      b_GD_DR_Trijet_jetNotdijet->Fill();
      b_BD_DR_Trijet_jetNotdijet->Fill();
      b_deltaR_lepbJetNotInMinMlb->Fill();
      b_deltaR_lepJetInMinMljet->Fill();
      b_deltaPhi_lepJetInMinMljet->Fill();	  
      b_deltaR_lepbJetInMinMlb->Fill();
      b_deltaPhi_lepbJetInMinMlb->Fill();	  
      b_HT_woBESTjet->Fill();	  
      b_MT_woBESTjet->Fill();	  
      b_PT_woBESTjet->Fill();	  
      b_M_woBESTjet->Fill();
      b_M_allJet_W->Fill();
      b_ratio_HTdHT4leadjets->Fill();
      b_W_PtdM->Fill();	 
      b_pTjet5_6->Fill(); 
      b_mean_csv->Fill();
      b_invM_jet34->Fill(); 
      b_invM_jet35->Fill(); 
      b_invM_jet36->Fill(); 
      b_invM_jet45->Fill(); 
      b_invM_jet46->Fill(); 
      b_invM_jet56->Fill(); 
      b_Sphericity->Fill(); 
      b_Aplanarity->Fill(); 
      b_pT_3rdcsvJet->Fill(); //added 31 March 2019
      b_pT_4thcsvJet->Fill(); //added 31 March 2019
      b_pt3HT->Fill();       // added 31 March 2019
      b_pt4HT->Fill();      // added 31 March 2019
      b_MT2bb->Fill();     // added 31 March 2019
      b_minMleppJetnew->Fill(); //added 31 March 2019 //this is minimum lep jet mass for any jet, not specifically light
      b_nGD_trijet->Fill();
      b_is_genMissingDaughter->Fill();
      b_is_genFourTopsOnelepton->Fill();      
      b_secondJetPt->Fill(); 
      b_fifthJetPt->Fill(); 
      b_sixthJetPt->Fill(); 
      b_hemiout->Fill();

      b_BDTtrijet2->Fill();	     
      b_BDTtrijet1->Fill();
      b_BDTtrijet3->Fill();
      b_BDTtrijet4->Fill();   
      b_HOTGoodTrijet1_mass->Fill();
      b_HOTGoodTrijet1_dijetmass->Fill();
      b_HOTGoodTrijet1_pTratio->Fill();
      b_HOTGoodTrijet1_dRtridijet->Fill();
      b_HOTGoodTrijet1_dRtrijetJetnotdijet->Fill();
      b_HOTGoodTrijet1_csvJetnotdijet->Fill();
      b_HOTGoodTrijet2_mass->Fill();
      b_HOTGoodTrijet2_dijetmass->Fill();
      b_HOTGoodTrijet2_pTratio->Fill();
      b_HOTGoodTrijet2_dRtridijet->Fill();
      b_HOTGoodTrijet2_dRtrijetJetnotdijet->Fill();
      b_HOTGoodTrijet2_csvJetnotdijet->Fill();
      b_HOTGoodTrijet3_mass->Fill();
      b_HOTGoodTrijet3_dijetmass->Fill();
      b_HOTGoodTrijet3_pTratio->Fill();
      b_HOTGoodTrijet3_dRtridijet->Fill();
      b_HOTGoodTrijet3_dRtrijetJetnotdijet->Fill();
      b_HOTGoodTrijet3_csvJetnotdijet->Fill();
      b_HOTGoodTrijet4_mass->Fill();
      b_HOTGoodTrijet4_dijetmass->Fill();
      b_HOTGoodTrijet4_pTratio->Fill();
      b_HOTGoodTrijet4_dRtridijet->Fill();
      b_HOTGoodTrijet4_dRtrijetJetnotdijet->Fill();
      b_HOTGoodTrijet4_csvJetnotdijet->Fill();
      b_HOTBadTrijet1_mass->Fill();
      b_HOTBadTrijet1_dijetmass->Fill();
      b_HOTBadTrijet1_pTratio->Fill();
      b_HOTBadTrijet1_dRtridijet->Fill();
      b_HOTBadTrijet1_dRtrijetJetnotdijet->Fill();
      b_HOTBadTrijet1_csvJetnotdijet->Fill();
      b_HOTBadTrijet2_mass->Fill();
      b_HOTBadTrijet2_dijetmass->Fill();
      b_HOTBadTrijet2_pTratio->Fill();
      b_HOTBadTrijet2_dRtridijet->Fill();
      b_HOTBadTrijet2_dRtrijetJetnotdijet->Fill();
      b_HOTBadTrijet2_csvJetnotdijet->Fill();
      b_HOTBadTrijet3_mass->Fill();
      b_HOTBadTrijet3_dijetmass->Fill();
      b_HOTBadTrijet3_pTratio->Fill();
      b_HOTBadTrijet3_dRtridijet->Fill();
      b_HOTBadTrijet3_dRtrijetJetnotdijet->Fill();
      b_HOTBadTrijet3_csvJetnotdijet->Fill();
      b_HOTBadTrijet4_mass->Fill();
      b_HOTBadTrijet4_dijetmass->Fill();
      b_HOTBadTrijet4_pTratio->Fill();
      b_HOTBadTrijet4_dRtridijet->Fill();
      b_HOTBadTrijet4_dRtrijetJetnotdijet->Fill();
      b_HOTBadTrijet4_csvJetnotdijet->Fill();
      b_NJets_JetSubCalc_float->Fill();
      b_NJetsCSVwithSF_MultiLepCalc_float->Fill();
      b_NresolvedTops1pFake_float->Fill();
      b_NJetsTtagged_float->Fill();
      b_NJetsWtagged_float->Fill();         

      // for csv study
      b_thirdcsvb_bb_BTagBHad->Fill();
      b_thirdcsvb_bb_BTagNBHad->Fill();
      b_thirdcsvb_bb_NBTagBHad->Fill();
      b_thirdcsvb_bb_NBTagNBHad->Fill();

      b_BestTop_Discriminator->Fill();
      b_BestTop_Pt->Fill();
      b_BestTop_Phi->Fill();
      b_BestTop_Eta->Fill();
      b_BestTop_Mass->Fill();

      b_NoTop_Jet1_CSV->Fill();
      b_NoTop_Jet1_Pt->Fill();
      b_NoTop_Jet1_Phi->Fill();
      b_NoTop_Jet1_Eta->Fill();
      b_NoTop_Jet1_Energy->Fill();

      b_NoTop_Jet2_CSV->Fill();
      b_NoTop_Jet2_Pt->Fill();
      b_NoTop_Jet2_Phi->Fill();
      b_NoTop_Jet2_Eta->Fill();
      b_NoTop_Jet2_Energy->Fill();     

      b_recLeptonicTopJetCSV->Fill();
      b_recLeptonicTopJetPt->Fill();

      b_LeptonicTB1_M->Fill();
      b_LeptonicTB2_M->Fill();
   
      b_LeptonicTB1_Pt->Fill();
      b_LeptonicTB2_Pt->Fill();

      b_LeptonicTB1_Eta->Fill();
      b_LeptonicTB2_Eta->Fill();

      b_HadronicTB1_M->Fill();
      b_HadronicTB2_M->Fill();

      b_HadronicTB1_Pt->Fill();
      b_HadronicTB2_Pt->Fill();

      b_HadronicTB1_Eta->Fill();
      b_HadronicTB2_Eta->Fill(); 
   }

std::cout<<"DONE "<<nentries<<std::endl;   
outputTree->Write();
outputFile->Close();
//outputFile->Write();
//delete outputFile;
delete inputFile;
}
