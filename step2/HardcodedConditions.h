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

  SFmap hscale_TTTX;
  SFmap hscale_TTNOBB;
  SFmap hscale_TTBB;
  SFmap hscale_TTNOBBHT500;
  SFmap hscale_TTBBHT500;
  SFmap hscale_ST;
  SFmap hscale_QCD;
  SFmap hscale_TTH;
  SFmap hscale_TTXY;
  SFmap hscale_EWK;
};

#endif
