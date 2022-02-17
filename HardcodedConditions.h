// COMMENT
#ifndef HardcodedConditions_h
#define HardcodedConditions_h

#include <iostream>
#include <vector>
#include <algorithm>
 
class HardcodedConditions{
    
public:
    
    HardcodedConditions();
    ~HardcodedConditions();

    void GetPileupWeight(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn, std::string year = "2017", std::string sample = "");
    
    double GetEGammaGsfSF(double pt, double eta, std::string year = "2017");
    double GetElectronIdSF(double pt, double eta, std::string year = "2017");
    double GetElectronIsoSF(double pt, double eta, std::string year = "2017");
    double GetElectronTriggerSF(double pt, double eta, std::string year = "2017");
    double GetIsEHadronTriggerSF(double njets, double ht, std::string year = "2017");
    double GetElectronTriggerXSF(double pt, double eta, std::string year = "2017");
    //double GetElectronTriggerVlqXSF(double pt, double eta, std::string year = "2017");
    double GetMuonIdSF(double pt, double eta, std::string year = "2017");
    double GetMuonIsoSF(double pt, double eta, std::string year = "2017");
    double GetMuonTriggerSF(double pt, double eta, std::string year = "2017");
    double GetIsMHadronTriggerSF(double njets, double ht, std::string year = "2017");
    double GetMuonTriggerXSF(double pt, double eta, std::string year = "2017");
    //double GetMuonTriggerVlqXSF(double pt, double eta, std::string year = "2017");
    float GetNjetSF(int njet, std::string year, std::string variation, bool isTT);
    float GetTtHfSF(bool isTT, bool isTTHF, bool isTTLF);
    float GetCSVRenormSF(std::string year, int isE, int njet, std::string sampleType);

    void GetBtaggingSF(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM", int jetHFlav = 5, std::string year = "2017");
    void GetBtaggingEff(double pt, double *eff, std::string tagger="CSVM", int jetHFlav = 5, std::string year = "2017");
    void GetHOTtaggingSF(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string year = "2017", bool isGenMatched=true, std::string workingpoint = "1pfake");
    void GetHOTtaggingEff(double pt, double *eff, std::string year = "2017", std::string sample = "ttbar", bool isGenMatched=true, std::string workingpoint = "1pfake", int massIndex=-1);
    void GetTtaggingSF(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn, std::string year = "2017");
    void GetTtaggingEff(double pt, double *eff, std::string year = "2017", std::string sample = "ttbar", int massIndex=-1);
    void GetWtaggingSF(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn, std::string year = "2017");
    void GetWtaggingEff(double pt, double *eff, std::string year = "2017", std::string sample = "ttbar", int massIndex=-1);

private:

    void GetPileupWeight2016APV(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn, std::string sample = "");
    void GetPileupWeight2016(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn, std::string sample = "");
    void GetPileupWeight2017(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn, std::string sample = "");
    void GetPileupWeight2018(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn, std::string sample = "");
    
    double GetEGammaGsfSF2016APV(double pt, double eta);
    double GetEGammaGsfSF2016(double pt, double eta);
    double GetEGammaGsfSF2017(double pt, double eta);
    double GetEGammaGsfSF2018(double pt, double eta);

    double GetElectronIdSF2016APV(double pt, double eta);
    double GetElectronIdSF2016(double pt, double eta);
    double GetElectronIdSF2017(double pt, double eta);
    double GetElectronIdSF2018(double pt, double eta);

    double GetElectronIsoSF2016APV(double pt, double eta);
    double GetElectronIsoSF2016(double pt, double eta);
    double GetElectronIsoSF2017(double pt, double eta);
    double GetElectronIsoSF2018(double pt, double eta);

    double GetElectronTriggerSF2016APV(double pt, double eta);
    double GetElectronTriggerSF2016(double pt, double eta);
    double GetElectronTriggerSF2017(double pt, double eta);
    double GetElectronTriggerSF2018(double pt, double eta);

    double GetIsEHadronTriggerSF2016APV(double njets, double ht);
    double GetIsEHadronTriggerSF2016(double njets, double ht);
    double GetIsEHadronTriggerSF2017(double njets, double ht);
    double GetIsEHadronTriggerSF2018(double njets, double ht);

    double GetElectronTriggerXSF2016APV(double pt, double eta);
    double GetElectronTriggerXSF2016(double pt, double eta);
    double GetElectronTriggerXSF2017(double pt, double eta);
    double GetElectronTriggerXSF2018(double pt, double eta);

    //double GetElectronTriggerVlqXSF2016APV(double pt, double eta);
    //double GetElectronTriggerVlqXSF2016(double pt, double eta);
    //double GetElectronTriggerVlqXSF2017(double pt, double eta);
    //double GetElectronTriggerVlqXSF2018(double pt, double eta);

    double GetMuonIdSF2016APV(double pt, double eta);
    double GetMuonIdSF2016(double pt, double eta);
    double GetMuonIdSF2017(double pt, double eta);
    double GetMuonIdSF2018(double pt, double eta);

    double GetMuonIsoSF2016APV(double pt, double eta);
    double GetMuonIsoSF2016(double pt, double eta);
    double GetMuonIsoSF2017(double pt, double eta);
    double GetMuonIsoSF2018(double pt, double eta);

    double GetIsMHadronTriggerSF2016APV(double njets, double ht);
    double GetIsMHadronTriggerSF2016(double njets, double ht);
    double GetIsMHadronTriggerSF2017(double njets, double ht);
    double GetIsMHadronTriggerSF2018(double njets, double ht);

    double GetMuonTriggerSF2016APV(double pt, double eta);
    double GetMuonTriggerSF2016(double pt, double eta);
    double GetMuonTriggerSF2017(double pt, double eta);
    double GetMuonTriggerSF2018(double pt, double eta);

    double GetMuonTriggerXSF2016APV(double pt, double eta);
    double GetMuonTriggerXSF2016(double pt, double eta);
    double GetMuonTriggerXSF2017(double pt, double eta);
    double GetMuonTriggerXSF2018(double pt, double eta);

    //double GetMuonTriggerVlqXSF2016APV(double pt, double eta);
    //double GetMuonTriggerVlqXSF2016(double pt, double eta);
    //double GetMuonTriggerVlqXSF2017(double pt, double eta);
    //double GetMuonTriggerVlqXSF2018(double pt, double eta);

    void GetBtaggingSF2016APV(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM");
    void GetCtaggingSF2016APV(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM");
    void GetLtaggingSF2016APV(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM");
    void GetBtaggingSF2016(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM");
    void GetCtaggingSF2016(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM");
    void GetLtaggingSF2016(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM");
    void GetBtaggingSF2017(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM");
    void GetCtaggingSF2017(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM");
    void GetLtaggingSF2017(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM");
    void GetBtaggingSF2018(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM");
    void GetCtaggingSF2018(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM");
    void GetLtaggingSF2018(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger="CSVM");
    void GetBtaggingEff2016APV(double pt, double *eff, std::string tagger="CSVM");
    void GetCtaggingEff2016APV(double pt, double *eff, std::string tagger="CSVM");
    void GetLtaggingEff2016APV(double pt, double *eff, std::string tagger="CSVM");
    void GetBtaggingEff2016(double pt, double *eff, std::string tagger="CSVM");
    void GetCtaggingEff2016(double pt, double *eff, std::string tagger="CSVM");
    void GetLtaggingEff2016(double pt, double *eff, std::string tagger="CSVM");
    void GetBtaggingEff2017(double pt, double *eff, std::string tagger="CSVM");
    void GetCtaggingEff2017(double pt, double *eff, std::string tagger="CSVM");
    void GetLtaggingEff2017(double pt, double *eff, std::string tagger="CSVM");
    void GetBtaggingEff2018(double pt, double *eff, std::string tagger="CSVM");
    void GetCtaggingEff2018(double pt, double *eff, std::string tagger="CSVM");
    void GetLtaggingEff2018(double pt, double *eff, std::string tagger="CSVM");

    void GetHOTtaggingSF2016APV(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint = "1pfake");
    void GetHOTtaggingSF2016(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint = "1pfake");
    void GetHOTtaggingSF2017(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint = "1pfake");
    void GetHOTtaggingSF2018(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint = "1pfake");
    void GetHOTtaggingEff2016APV(double pt, double *eff, std::string sample = "ttbar", std::string workingpoint = "1pfake", int massIndex=-1);
    void GetHOTtaggingEff2016(double pt, double *eff, std::string sample = "ttbar", std::string workingpoint = "1pfake", int massIndex=-1);
    void GetHOTtaggingEff2017(double pt, double *eff, std::string sample = "ttbar", std::string workingpoint = "1pfake", int massIndex=-1);
    void GetHOTtaggingEff2018(double pt, double *eff, std::string sample = "ttbar", std::string workingpoint = "1pfake", int massIndex=-1);

    void GetHOTmistagSF2016APV(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint = "1pfake");
    void GetHOTmistagSF2016(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint = "1pfake");
    void GetHOTmistagSF2017(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint = "1pfake");
    void GetHOTmistagSF2018(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint = "1pfake");
    void GetHOTmistagEff2016APV(double pt, double *eff, std::string sample = "ttbar", std::string workingpoint = "1pfake", int massIndex=-1);
    void GetHOTmistagEff2016(double pt, double *eff, std::string sample = "ttbar", std::string workingpoint = "1pfake", int massIndex=-1);
    void GetHOTmistagEff2017(double pt, double *eff, std::string sample = "ttbar", std::string workingpoint = "1pfake", int massIndex=-1);
    void GetHOTmistagEff2018(double pt, double *eff, std::string sample = "ttbar", std::string workingpoint = "1pfake", int massIndex=-1);

    void GetTtaggingSF2016APV(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn);
    void GetTtaggingSF2016(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn);
    void GetTtaggingSF2017(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn);
    void GetTtaggingSF2018(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn);
    void GetTtaggingEff2016APV(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);
    void GetTtaggingEff2016(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);
    void GetTtaggingEff2017(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);
    void GetTtaggingEff2018(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);

    void GetWtaggingSF2016APV(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn);
    void GetWtaggingSF2016(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn);
    void GetWtaggingSF2017(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn);
    void GetWtaggingSF2018(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn);
    void GetWtaggingEff2016APV(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);
    void GetWtaggingEff2016(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);
    void GetWtaggingEff2017(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);
    void GetWtaggingEff2018(double pt, double *eff, std::string sample = "ttbar", int massIndex=-1);

    typedef std::vector< double > FVec;
    typedef std::vector< int > IVec;
    FVec ptMins, hotEffs1p, hotEffs2p, hotEffs5p, hotEffs10p, hotEffs, hotCSpurUncs, hotClosureUncs;
    FVec tSFs, tSFsUp, tSFsDn;
    IVec njetMins;
    inline int findBin(double pt, FVec ptRange){
        return (std::upper_bound(ptRange.begin(), ptRange.end(), pt)-ptRange.begin())-1;
    }   
    inline int findBin(int njet, IVec njetRange){
        return (std::upper_bound(njetRange.begin(), njetRange.end(), njet)-njetRange.begin())-1;
    }    
};


#endif
