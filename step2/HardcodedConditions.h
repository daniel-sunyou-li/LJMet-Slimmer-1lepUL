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
  HardcodedConditions( std::string Year );
  ~HardcodedConditions();

  float GetDeepJetRenorm2DSF_HTnj(float HT, int njets, std::string sampleType, std::string sysType );
  float GetCrossSectionEfficiency( TString inputFileName, std::string Year );
  float GetBTagWP( std::string Year, std::string tagger );

  TFile *tfile_HTNJ_SF;

  SFmap hscale_tttw;
  SFmap hscale_tttj;
  SFmap hscale_tttt;
  SFmap hscale_ttjj;
  SFmap hscale_ttbb;
  SFmap hscale_ttcc;
  SFmap hscale_tt2b;
  SFmap hscale_tt1b;
  SFmap hscale_HT500ttjj;
  SFmap hscale_HT500ttbb;
  SFmap hscale_HT500ttcc;
  SFmap hscale_HT500tt2b;
  SFmap hscale_HT500tt1b;
  SFmap hscale_STs;
  SFmap hscale_STt;
  SFmap hscale_STtW;
  SFmap hscale_WJets;
  SFmap hscale_QCD;
  SFmap hscale_DYM;
  SFmap hscale_TTHBB;
  SFmap hscale_TTHnonBB;
  SFmap hscale_TTHH;
  SFmap hscale_TTXY;
  SFmap hscale_EWK;
};

#endif
