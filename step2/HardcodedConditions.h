#ifndef HardcodedConditions_h
#define HardcodedConditions_h

#include <iostream>
#include <vector>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH2.h>
#include <algorithm>

typedef std::map<std::string, TH2F*> SFmap;

class HardcodedConditions{
    
public:

  HardcodedConditions();
  HardcodedConditions( Int_t Year );
  ~HardcodedConditions();

  float GetDeepJetRenorm2DSF_HTnj(float HT, int njets, std::string sampleType, std::string sysType );
  float GetCrossSectionEfficiency( TString inputFileName, int Year );
  float GetBTagWP( int Year, std::string tagger );

  TFile *tfile_HTNJ_SF;

  SFmap hscale_tttw;
  SFmap hscale_tttj;
  SFmap hscale_tttt;
  SFmap hscale_ttjj;
  SFmap hscale_ttbb;
  SFmap hscale_ttcc;
  SFmap hscale_tt2b;
  SFmap hscale_tt1b;
  SFmap hscale_HT500Njet9_ttjj;
  SFmap hscale_HT500Njet9_ttbb;
  SFmap hscale_HT500Njet9_ttcc;
  SFmap hscale_HT500Njet9_tt2b;
  SFmap hscale_HT500Njet9_tt1b;
  SFmap hscale_STs;
  SFmap hscale_STt;
  SFmap hscale_STtw;
  SFmap hscale_WJets;
};

#endif
