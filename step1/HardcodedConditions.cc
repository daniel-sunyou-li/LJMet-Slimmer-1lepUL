// -*- C++ -*-
//
// Helper class, provides jet tagging eff, scale factors, etc.
// 
// Inspired from BtagHardcodedConditions in LJMET
// 
// by
//
// Sinan Sagir, November 2019
//

#include <cmath>
#include <math.h>
#include <TMath.h>
#include "HardcodedConditions.h"
#include <unordered_map>

using namespace std;

HardcodedConditions::HardcodedConditions() {
}

HardcodedConditions::~HardcodedConditions() {
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|           B TAGGING SCALE FACTOR SECTION            |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetBtaggingSF(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger, int jetHFlav, std::string year)
{
  // SF (and unc) applied on a jet-by-jet basis
  *btagsf   = 1.000;
  *btagsfunc = 0.000;
  if( year=="2016APV" ){
  	if      (jetHFlav==5) GetBtaggingSF2016APV(pt, eta, btagsf, btagsfunc, tagger);
  	else if (jetHFlav==4) GetCtaggingSF2016APV(pt, eta, btagsf, btagsfunc, tagger);
  	else                  GetLtaggingSF2016APV(pt, eta, btagsf, btagsfunc, tagger);
  	}
  else if(year=="2016"){
  	if      (jetHFlav==5) GetBtaggingSF2016(pt, eta, btagsf, btagsfunc, tagger);
  	else if (jetHFlav==4) GetCtaggingSF2016(pt, eta, btagsf, btagsfunc, tagger);
  	else                  GetLtaggingSF2016(pt, eta, btagsf, btagsfunc, tagger);
  	}
  else if(year=="2017"){
  	if      (jetHFlav==5) GetBtaggingSF2017(pt, eta, btagsf, btagsfunc, tagger);
  	else if (jetHFlav==4) GetCtaggingSF2017(pt, eta, btagsf, btagsfunc, tagger);
  	else                  GetLtaggingSF2017(pt, eta, btagsf, btagsfunc, tagger);
  	}
  else if(year=="2018"){
  	if      (jetHFlav==5) GetBtaggingSF2018(pt, eta, btagsf, btagsfunc, tagger);
  	else if (jetHFlav==4) GetCtaggingSF2018(pt, eta, btagsf, btagsfunc, tagger);
  	else                  GetLtaggingSF2018(pt, eta, btagsf, btagsfunc, tagger);
  	}
  else{ std::cerr << "Year " << year << " not coded into HardcodedConditions::GetBtaggingSF! Aborting ..." << std::endl; std::abort();}
} //end GetBtaggingSF

// not updated
void HardcodedConditions::GetBtaggingSF2016APV(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger){
	if( tagger == "DeepCSVMEDIUM"){ 
      *btagsf = 1.0;
      *btagsfunc = 0.0;
  }
  else if( tagger == "DeepJetMEDIUM") { 
    *btagsf = 1.0;
    *btagsfunc = 0.0;
  }
}

// not updated
void HardcodedConditions::GetBtaggingSF2016(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger){
	if( tagger == "DeepCSVMEDIUM"){ 
      *btagsf = 1.0;
      *btagsfunc = 0.0;
  }
  else if( tagger == "DeepJetMEDIUM") { 
    *btagsf = 1.0;
    *btagsfunc = 0.0;
  }
}

// not updated
void HardcodedConditions::GetCtaggingSF2016APV(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger){
	if( tagger == "DeepCSVMEDIUM"){ 
      *btagsf = 1.0;
      *btagsfunc = 0.0;
  }
  else if( tagger == "DeepJetMEDIUM") { 
    *btagsf = 1.0;
    *btagsfunc = 0.0;
  }
}

// not updated
void HardcodedConditions::GetCtaggingSF2016(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger){
	if( tagger == "DeepCSVMEDIUM"){ 
      *btagsf = 1.0;
      *btagsfunc = 0.0;
  }
  else if( tagger == "DeepJetMEDIUM") { 
    *btagsf = 1.0;
    *btagsfunc = 0.0;
  }
}


// not updated
void HardcodedConditions::GetLtaggingSF2016APV(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger){
	if( tagger == "DeepCSVMEDIUM"){ 
      *btagsf = 1.0;
      *btagsfunc = 0.0;
  }
  else if( tagger == "DeepJetMEDIUM") { 
    *btagsf = 1.0;
    *btagsfunc = 0.0;
  }
}

// not updated
void HardcodedConditions::GetLtaggingSF2016(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger){
	if( tagger == "DeepCSVMEDIUM"){ 
      *btagsf = 1.0;
      *btagsfunc = 0.0;
  }
  else if( tagger == "DeepJetMEDIUM") { 
    *btagsf = 1.0;
    *btagsfunc = 0.0;
  }
}

// not updated
void HardcodedConditions::GetBtaggingSF2017(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger){
	if( tagger == "DeepCSVMEDIUM"){ 
      *btagsf = 1.0;
      *btagsfunc = 0.0;
  }
  else if( tagger == "DeepJetMEDIUM") { 
    *btagsf = 1.0;
    *btagsfunc = 0.0;
  }
}

// not updated
void HardcodedConditions::GetCtaggingSF2017(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger){
	if( tagger == "DeepCSVMEDIUM"){ 
      *btagsf = 1.0;
      *btagsfunc = 0.0;
  }
  else if( tagger == "DeepJetMEDIUM") { 
    *btagsf = 1.0;
    *btagsfunc = 0.0;
  }
}

// not updated
void HardcodedConditions::GetLtaggingSF2017(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger){
	if( tagger == "DeepCSVMEDIUM"){ 
      *btagsf = 1.0;
      *btagsfunc = 0.0;
  }
  else if( tagger == "DeepJetMEDIUM") { 
    *btagsf = 1.0;
    *btagsfunc = 0.0;
  }
}

// not updated
void HardcodedConditions::GetBtaggingSF2018(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger){
	if( tagger == "DeepCSVMEDIUM"){ 
      *btagsf = 1.0;
      *btagsfunc = 0.0;
  }
  else if( tagger == "DeepJetMEDIUM") { 
    *btagsf = 1.0;
    *btagsfunc = 0.0;
  }
}

// not updated
void HardcodedConditions::GetCtaggingSF2018(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger){
	if( tagger == "DeepCSVMEDIUM"){ 
      *btagsf = 1.0;
      *btagsfunc = 0.0;
  }
  else if( tagger == "DeepJetMEDIUM") { 
    *btagsf = 1.0;
    *btagsfunc = 0.0;
  }
}

// not updated
void HardcodedConditions::GetLtaggingSF2018(double pt, double eta, double *btagsf, double *btagsfunc, std::string tagger){
	if( tagger == "DeepCSVMEDIUM"){ 
      *btagsf = 1.0;
      *btagsfunc = 0.0;
  }
  else if( tagger == "DeepJetMEDIUM") { 
    *btagsf = 1.0;
    *btagsfunc = 0.0;
  }
}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|            B TAGGING EFFICIENCY SECTION            |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetBtaggingEff(double pt, double *eff, std::string tagger, int jetHFlav, std::string year)
{
  // The main getter for GetBtaggingEff Efficiencies
  // Used in determining the number of jets to (un-)tag for jet-by-jet SF
  *eff = 1.000;
  if(year=="2016APV"){
  	if      (jetHFlav==5) GetBtaggingEff2016APV(pt, eff, tagger);
  	else if (jetHFlav==4) GetCtaggingEff2016APV(pt, eff, tagger);
  	else                  GetLtaggingEff2016APV(pt, eff, tagger);
  	}
  else if(year=="2016"){
  	if      (jetHFlav==5) GetBtaggingEff2016(pt, eff, tagger);
  	else if (jetHFlav==4) GetCtaggingEff2016(pt, eff, tagger);
  	else                  GetLtaggingEff2016(pt, eff, tagger);
  	}
  else if(year=="2017"){
  	if      (jetHFlav==5) GetBtaggingEff2017(pt, eff, tagger);
  	else if (jetHFlav==4) GetCtaggingEff2017(pt, eff, tagger);
  	else                  GetLtaggingEff2017(pt, eff, tagger);
  	}
  else if(year=="2018"){
  	if      (jetHFlav==5) GetBtaggingEff2018(pt, eff, tagger);
  	else if (jetHFlav==4) GetCtaggingEff2018(pt, eff, tagger);
  	else                  GetLtaggingEff2018(pt, eff, tagger);
  	}
  else{ std::cerr << "Year " << year << " not coded into HardcodedConditions::GetBtaggingEff! Aborting ..." << std::endl; std::abort();}
}//end GetBtaggingEff

// not updated
void HardcodedConditions::GetBtaggingEff2016APV(double pt, double *eff, std::string tagger){
  *eff = 1.0;
}

// not updated
void HardcodedConditions::GetBtaggingEff2016(double pt, double *eff, std::string tagger){
  *eff = 1.0;
}
void HardcodedConditions::GetCtaggingEff2016APV(double pt, double *eff, std::string tagger){
  *eff = 1.0;
}

void HardcodedConditions::GetCtaggingEff2016(double pt, double *eff, std::string tagger)
{
  *eff = 1.0;
}

void HardcodedConditions::GetLtaggingEff2016APV(double pt, double *eff, std::string tagger)
{
  *eff = 1.0;
}

void HardcodedConditions::GetLtaggingEff2016(double pt, double *eff, std::string tagger)
{
  *eff = 1.0;
}

void HardcodedConditions::GetBtaggingEff2017(double pt, double *eff, std::string tagger)
{
  *eff = 1.0;
}

void HardcodedConditions::GetCtaggingEff2017(double pt, double *eff, std::string tagger)
{
  *eff = 1.0;
}

void HardcodedConditions::GetLtaggingEff2017(double pt, double *eff, std::string tagger)
{
  *eff = 1.0;
}

void HardcodedConditions::GetBtaggingEff2018(double pt, double *eff, std::string tagger)
{
  *eff = 1.0;
}

void HardcodedConditions::GetCtaggingEff2018(double pt, double *eff, std::string tagger)
{
  *eff = 1.0;
}

void HardcodedConditions::GetLtaggingEff2018(double pt, double *eff, std::string tagger)
{
  *eff = 1.0;
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|           HOT TAGGER SCALE FACTOR SECTION           |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetHOTtaggingSF(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string year, bool isGenMatched, std::string workingpoint)
{
  //The main getter for GetHOTtaggingSF Scale Factors
  *hotsf   = 1.000;
  *hotstatunc = 0.000;
  *hotcspurunc = 0.000;
  *hotclosureunc = 0.000;
  if(isGenMatched){
  	if      (year=="2016APV") GetHOTtaggingSF2016APV(pt, njet, hotsf, hotstatunc, hotcspurunc, hotclosureunc, workingpoint);
    else if (year=="2016") GetHOTtaggingSF2016(pt, njet, hotsf, hotstatunc, hotcspurunc, hotclosureunc, workingpoint);
  	else if (year=="2017") GetHOTtaggingSF2017(pt, njet, hotsf, hotstatunc, hotcspurunc, hotclosureunc, workingpoint);
  	else if (year=="2018") GetHOTtaggingSF2018(pt, njet, hotsf, hotstatunc, hotcspurunc, hotclosureunc, workingpoint);
  	}
  else{
  	if      (year=="2016APV") GetHOTmistagSF2016APV(pt, njet, hotsf, hotstatunc, hotcspurunc, hotclosureunc, workingpoint);
  	else if (year=="2016") GetHOTmistagSF2016(pt, njet, hotsf, hotstatunc, hotcspurunc, hotclosureunc, workingpoint);
  	else if (year=="2017") GetHOTmistagSF2017(pt, njet, hotsf, hotstatunc, hotcspurunc, hotclosureunc, workingpoint);
  	else if (year=="2018") GetHOTmistagSF2018(pt, njet, hotsf, hotstatunc, hotcspurunc, hotclosureunc, workingpoint);
  	}
}//end GetHOTtaggingSF


void HardcodedConditions::GetHOTtaggingSF2016APV(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint)
{
	// VALUES from https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSYHOTGroup
	ptMins = {0,150,250,300,350,400,450,500,600};
	njetMins = {4,5,6,7,8,9,10};
	if (workingpoint=="1pfake"){
		*hotsf = 1.0234;
		*hotstatunc = 0.0193;
		hotCSpurUncs = {0.0356,0.0011,0.0015,0.002,0.0025,0.0051,0.0077,0.0037,0.0487};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.3032,0.0464,0.0461,0.0515,0.0808,0.1396,0.1744};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="2pfake"){
		*hotsf = 1.0470;
		*hotstatunc = 0.0176;
		hotCSpurUncs = {0.0376,0.0007,0.0017,0.002,0.003,0.0042,0.0065,0.0033,0.046};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0282,0.0282,0.084,0.0561,0.0619,0.0903,0.1053};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="5pfake"){
		*hotsf = 1.0055;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else if (workingpoint=="10pfake"){
		*hotsf = 1.0093;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingSF2016! Aborting ..." << std::endl; std::abort();}
}

void HardcodedConditions::GetHOTtaggingSF2016(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint)
{
	// VALUES from https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSYHOTGroup
	ptMins = {0,150,250,300,350,400,450,500,600};
	njetMins = {4,5,6,7,8,9,10};
	if (workingpoint=="1pfake"){
		*hotsf = 1.0234;
		*hotstatunc = 0.0193;
		hotCSpurUncs = {0.0356,0.0011,0.0015,0.002,0.0025,0.0051,0.0077,0.0037,0.0487};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.3032,0.0464,0.0461,0.0515,0.0808,0.1396,0.1744};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="2pfake"){
		*hotsf = 1.0470;
		*hotstatunc = 0.0176;
		hotCSpurUncs = {0.0376,0.0007,0.0017,0.002,0.003,0.0042,0.0065,0.0033,0.046};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0282,0.0282,0.084,0.0561,0.0619,0.0903,0.1053};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="5pfake"){
		*hotsf = 1.0055;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else if (workingpoint=="10pfake"){
		*hotsf = 1.0093;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingSF2016! Aborting ..." << std::endl; std::abort();}
}

void HardcodedConditions::GetHOTmistagSF2016APV(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint)
{
	// VALUES from https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSYHOTGroup
	ptMins = {0,150,250,300,350,400,450,500,600};
	njetMins = {4,5,6,7,8,9,10};
	if (workingpoint=="1pfake"){
		*hotsf = 0.9071;
		*hotstatunc = 0.0070;
		hotCSpurUncs = {0.0278,0.0311,0.0342,0.0376,0.0403,0.0405,0.0375,0.0439,0.0648};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0531,0.0821,0.0154,0.0779,0.211,0.2536,0.2935};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="2pfake"){
		*hotsf = 0.9126;
		*hotstatunc = 0.0053;
		hotCSpurUncs = {0.0168,0.0199,0.0231,0.0262,0.0286,0.0289,0.0268,0.0313,0.0467};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0306,0.0555,0.0047,0.0758,0.1999,0.2308,0.3003};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="5pfake"){
		*hotsf = 0.9298;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else if (workingpoint=="10pfake"){
		*hotsf = 0.9194;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTmistagSF2016! Aborting ..." << std::endl; std::abort();}
}

void HardcodedConditions::GetHOTmistagSF2016(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint)
{
	// VALUES from https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSYHOTGroup
	ptMins = {0,150,250,300,350,400,450,500,600};
	njetMins = {4,5,6,7,8,9,10};
	if (workingpoint=="1pfake"){
		*hotsf = 0.9071;
		*hotstatunc = 0.0070;
		hotCSpurUncs = {0.0278,0.0311,0.0342,0.0376,0.0403,0.0405,0.0375,0.0439,0.0648};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0531,0.0821,0.0154,0.0779,0.211,0.2536,0.2935};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="2pfake"){
		*hotsf = 0.9126;
		*hotstatunc = 0.0053;
		hotCSpurUncs = {0.0168,0.0199,0.0231,0.0262,0.0286,0.0289,0.0268,0.0313,0.0467};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0306,0.0555,0.0047,0.0758,0.1999,0.2308,0.3003};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="5pfake"){
		*hotsf = 0.9298;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else if (workingpoint=="10pfake"){
		*hotsf = 0.9194;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTmistagSF2016! Aborting ..." << std::endl; std::abort();}
}

void HardcodedConditions::GetHOTtaggingSF2017(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint)
{
	// VALUES from https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSYHOTGroup
	ptMins = {0,150,250,300,350,400,450,500,600};
	njetMins = {4,5,6,7,8,9,10};
	if (workingpoint=="1pfake"){
		*hotsf = 0.9570;
		*hotstatunc = 0.0237;
		hotCSpurUncs = {0.0825,0.0256,0.0276,0.0075,0.0244,0.0265,0.0343,0.0652,0.0095};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0412,0.0412,0.0865,0.082,0.0375,0.1117,0.0808};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="2pfake"){
		*hotsf = 0.9604;
		*hotstatunc = 0.0219;
		hotCSpurUncs = {0.0463,0.026,0.0208,0.0104,0.0247,0.0253,0.0328,0.0486,0.0036};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0558,0.0558,0.0322,0.0203,0.0548,0.0403,0.0924};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="5pfake"){
		*hotsf = 0.9874;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else if (workingpoint=="10pfake"){
		*hotsf = 1.0067;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingSF2017! Aborting ..." << std::endl; std::abort();}
}

void HardcodedConditions::GetHOTmistagSF2017(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint)
{
	// VALUES from https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSYHOTGroup
	ptMins = {0,150,250,300,350,400,450,500,600};
	njetMins = {4,5,6,7,8,9,10};
	if (workingpoint=="1pfake"){
		*hotsf = 0.9921;
		*hotstatunc = 0.0099;
		hotCSpurUncs = {0.0303,0.0367,0.0406,0.0431,0.0499,0.0548,0.0623,0.0594,0.0571};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0369,0.0377,0.0384,0.0986,0.1768,0.2546,0.257};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="2pfake"){
		*hotsf = 1.0140;
		*hotstatunc = 0.0074;
		hotCSpurUncs = {0.0189,0.0236,0.0276,0.0309,0.0355,0.0396,0.0459,0.0448,0.0427};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0875,0.0309,0.064,0.1179,0.1828,0.2453,0.2146};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="5pfake"){
		*hotsf = 1.0119;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else if (workingpoint=="10pfake"){
		*hotsf = 1.0012;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTmistagSF2017! Aborting ..." << std::endl; std::abort();}
}

void HardcodedConditions::GetHOTtaggingSF2018(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint)
{
	// VALUES from https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSYHOTGroup
	ptMins = {0,150,250,300,350,400,450,500,600};
	njetMins = {4,5,6,7,8,9,10};
	if (workingpoint=="1pfake"){
		*hotsf = 0.9359;
		*hotstatunc = 0.0239;
		hotCSpurUncs = {0.0641,0.1004,0.0416,0.0583,0.0695,0.0457,0.0255,0.0553,0.03};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0693,0.0693,0.1077,0.1884,0.1159,0.2002,0.0862};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="2pfake"){
		*hotsf = 0.9483;
		*hotstatunc = 0.0222;
		hotCSpurUncs = {0.0644,0.0445,0.0437,0.0466,0.0694,0.0415,0.0269,0.0544,0.0133};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0342,0.0342,0.0356,0.0222,0.1118,0.0935,0.1934};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="5pfake"){
		*hotsf = 0.9769;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else if (workingpoint=="10pfake"){
		*hotsf = 0.9922;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingSF2018! Aborting ..." << std::endl; std::abort();}
}

void HardcodedConditions::GetHOTmistagSF2018(double pt, int njet, double *hotsf, double *hotstatunc, double *hotcspurunc, double *hotclosureunc, std::string workingpoint)
{
	// VALUES from https://twiki.cern.ch/twiki/bin/viewauth/CMS/SUSYHOTGroup
	ptMins = {0,150,250,300,350,400,450,500,600};
	njetMins = {4,5,6,7,8,9,10};
	if (workingpoint=="1pfake"){
		*hotsf = 0.9036;
		*hotstatunc = 0.0128;
		hotCSpurUncs = {0.0544,0.0523,0.0568,0.0608,0.0667,0.0769,0.0784,0.0732,0.0714};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.0774,0.0179,0.0762,0.1097,0.254,0.3018,0.4417};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="2pfake"){
		*hotsf = 0.9532;
		*hotstatunc = 0.0096;
		hotCSpurUncs = {0.032,0.0348,0.0413,0.0439,0.0486,0.0569,0.0586,0.0553,0.0543};
		int bin = findBin(pt, ptMins);
		*hotcspurunc = hotCSpurUncs[bin];
		hotClosureUncs = {0.111,0.0466,0.1185,0.1579,0.3102,0.3314,0.4543};
		bin = findBin(njet, njetMins);
		*hotclosureunc = hotClosureUncs[bin];
		}
	else if (workingpoint=="5pfake"){
		*hotsf = 0.9753;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else if (workingpoint=="10pfake"){
		*hotsf = 0.9703;
		*hotstatunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotcspurunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		*hotclosureunc = 0.0; //NOT PROVIDED in TWIKI, NOV 2019
		}
	else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTmistagSF2018! Aborting ..." << std::endl; std::abort();}
}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|            HOT TAGGER EFFICIENCY SECTION            |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetHOTtaggingEff(double pt, double *eff, std::string year, std::string sample, bool isGenMatched, std::string workingpoint, int massIndex)
{
  //The main getter for GetHOTtaggingEff Efficiencies
  *eff = 1.000;
  if(isGenMatched){
    if      (year=="2016APV") GetHOTtaggingEff2016APV(pt, eff, sample, workingpoint, massIndex);
    else if (year=="2016") GetHOTtaggingEff2016(pt, eff, sample, workingpoint, massIndex);
    else if (year=="2017") GetHOTtaggingEff2017(pt, eff, sample, workingpoint, massIndex);
    else if (year=="2018") GetHOTtaggingEff2018(pt, eff, sample, workingpoint, massIndex);
  }
  else{
    if      (year=="2016APV") GetHOTmistagEff2016APV(pt, eff, sample, workingpoint, massIndex);
    else if (year=="2016") GetHOTmistagEff2016(pt, eff, sample, workingpoint, massIndex);
    else if (year=="2017") GetHOTmistagEff2017(pt, eff, sample, workingpoint, massIndex);
    else if (year=="2018") GetHOTmistagEff2018(pt, eff, sample, workingpoint, massIndex);
  }
}//end GetHOTtaggingEff

void HardcodedConditions::GetHOTtaggingEff2016APV(double pt, double *eff, std::string sample, std::string workingpoint, int massIndex)
{
	if(sample=="singletop"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.205348668416,0.314370717634,0.409574468085,0.44616639478,0.499124343257,0.472885032538,0.375634517766};
		hotEffs2p = {0.33733459885,0.435088351965,0.522606382979,0.551386623165,0.583187390543,0.58568329718,0.472081218274};
		hotEffs5p = {0.52297470828,0.592679408583,0.65469858156,0.677814029364,0.709281961471,0.720173535792,0.583756345178};
		hotEffs10p= {0.664787002401,0.717634331049,0.754875886525,0.783849918434,0.791593695271,0.798264642082,0.654822335025};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="TTVV"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.305842391304,0.399267399267,0.477281055332,0.493034055728,0.537331701346,0.531803542673,0.418008784773};
		hotEffs2p = {0.464266304348,0.535256410256,0.587761084646,0.609907120743,0.645042839657,0.625603864734,0.513909224012};
		hotEffs5p = {0.650815217391,0.6903998779,0.725357273727,0.731682146543,0.74949000408,0.739935587762,0.635431918009};
		hotEffs10p= {0.768614130435,0.791361416361,0.813484792964,0.818885448916,0.825785393717,0.815217391304,0.714494875549};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="TTTX"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.306924101198,0.39515630792,0.47762962963,0.52101910828,0.53066850448,0.537334263782,0.394946808511};
		hotEffs2p = {0.466932978251,0.531199802298,0.59762962963,0.635668789809,0.644383184011,0.630146545708,0.496010638298};
		hotEffs5p = {0.648024855748,0.684047942667,0.733037037037,0.750318471338,0.762232942798,0.738311235171,0.644946808511};
		hotEffs10p= {0.770972037284,0.785617200049,0.815111111111,0.832696390658,0.840799448656,0.813677599442,0.716755319149};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttbarHT500Njet9"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.407909294843,0.487360654607,0.554943124203,0.585792903693,0.607100158595,0.624351331646,0.610264067903,0.570180155956,0.529164477141,0.417211703959};
		hotEffs2p = {0.568257255093,0.618534948399,0.665471923536,0.685199131064,0.698426253507,0.708109962688,0.696007544797,0.66415703146,0.621650026274,0.499139414802};
		hotEffs5p = {0.736228265173,0.755602546717,0.781532684758,0.791745112238,0.799609613273,0.804949178711,0.792675259352,0.767410594246,0.723068838676,0.618244406196};
		hotEffs10p= {0.834972644315,0.840545199623,0.854462214994,0.860637219406,0.867268512871,0.87095252391,0.857041810751,0.837859639688,0.800840777719,0.702925989673};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttbar"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.252959824309,0.361397414942,0.459087366036,0.504119254456,0.534357717034,0.550922369278,0.535451420581,0.492177755604,0.438544880534,0.298526640397};
		hotEffs2p = {0.39900220362,0.493794233602,0.574189819563,0.608677624155,0.631207830733,0.641467233281,0.624997572486,0.58401339938,0.523498600847,0.380589343841};
		hotEffs5p = {0.588466684642,0.652158801147,0.707418016666,0.730327047958,0.745084736246,0.749944084098,0.732041248325,0.69227753822,0.632991318074,0.48338187425};
		hotEffs10p= {0.721765531851,0.763493052893,0.801389053122,0.815564800087,0.823962905082,0.823869769432,0.80799331948,0.771996721428,0.718160292746,0.574610244989};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttVjets"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.25058416855,0.337887212073,0.411016797393,0.443887827299,0.467403702729,0.474528168015,0.454567022539,0.411171171171,0.368152866242,0.247029393371};
		hotEffs2p = {0.395882818686,0.471008737093,0.528383653881,0.553943087332,0.570150039484,0.56903646942,0.539264531435,0.495135135135,0.452229299363,0.330206378987};
		hotEffs5p = {0.582893999961,0.633783425999,0.669388632212,0.683313536126,0.691936474511,0.690506598553,0.664294187426,0.607207207207,0.579617834395,0.430268918074};
		hotEffs10p= {0.715350597686,0.747603918454,0.769958096057,0.777668749677,0.780994998684,0.78288633461,0.749466192171,0.707747747748,0.675796178344,0.522826766729};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttHToNonbb"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.283254772173,0.370313194136,0.441448382126,0.485894673548,0.5044754744,0.51778614773,0.402069297401};
		hotEffs2p = {0.438354561562,0.511728120835,0.561922187982,0.595279851681,0.607948442535,0.61581920904,0.491578440808};
		hotEffs5p = {0.629559054592,0.672112394491,0.70531587057,0.721250688981,0.727980665951,0.726197949362,0.615736284889};
		hotEffs10p= {0.756560692675,0.781452687694,0.800783256292,0.809640727564,0.808628714644,0.80989746809,0.700433108758};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttHTobb"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.306951814618,0.400615427169,0.481797844214,0.522922404017,0.541345583877,0.54735152488,0.417312661499};
		hotEffs2p = {0.468254179889,0.544082564049,0.607585926378,0.636886440953,0.652934202727,0.639200998752,0.502153316107};
		hotEffs5p = {0.662009013093,0.708830342634,0.748525523693,0.759274258869,0.766597510373,0.752452291778,0.617571059432};
		hotEffs10p= {0.786299032026,0.81291705563,0.833384177344,0.84318807711,0.838470657973,0.820581416087,0.699827734711};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="tttt"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.311329828161,0.390131583914,0.447922957643,0.479768786127,0.503408790045,0.50556497774,0.495245245245,0.459487179487,0.408713227038,0.294583883752};
		hotEffs2p = {0.462714798666,0.528502298755,0.5714845344,0.594583600942,0.609445326979,0.607536569854,0.591257924591,0.557307692308,0.505501908826,0.386393659181};
		hotEffs5p = {0.646111182354,0.686146320104,0.71145025708,0.72575465639,0.731135822081,0.725991096036,0.708375041708,0.674871794872,0.632158095666,0.503302509908};
		hotEffs10p= {0.763352782765,0.788031374799,0.80355831225,0.811025476343,0.811854646545,0.807504769981,0.787287287287,0.762564102564,0.719514933753,0.594671950683};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else{ std::cerr << "The sample " << sample << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}

}

void HardcodedConditions::GetHOTtaggingEff2016(double pt, double *eff, std::string sample, std::string workingpoint, int massIndex)
{
	if(sample=="singletop"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.205348668416,0.314370717634,0.409574468085,0.44616639478,0.499124343257,0.472885032538,0.375634517766};
		hotEffs2p = {0.33733459885,0.435088351965,0.522606382979,0.551386623165,0.583187390543,0.58568329718,0.472081218274};
		hotEffs5p = {0.52297470828,0.592679408583,0.65469858156,0.677814029364,0.709281961471,0.720173535792,0.583756345178};
		hotEffs10p= {0.664787002401,0.717634331049,0.754875886525,0.783849918434,0.791593695271,0.798264642082,0.654822335025};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="TTVV"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.305842391304,0.399267399267,0.477281055332,0.493034055728,0.537331701346,0.531803542673,0.418008784773};
		hotEffs2p = {0.464266304348,0.535256410256,0.587761084646,0.609907120743,0.645042839657,0.625603864734,0.513909224012};
		hotEffs5p = {0.650815217391,0.6903998779,0.725357273727,0.731682146543,0.74949000408,0.739935587762,0.635431918009};
		hotEffs10p= {0.768614130435,0.791361416361,0.813484792964,0.818885448916,0.825785393717,0.815217391304,0.714494875549};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="TTTX"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.306924101198,0.39515630792,0.47762962963,0.52101910828,0.53066850448,0.537334263782,0.394946808511};
		hotEffs2p = {0.466932978251,0.531199802298,0.59762962963,0.635668789809,0.644383184011,0.630146545708,0.496010638298};
		hotEffs5p = {0.648024855748,0.684047942667,0.733037037037,0.750318471338,0.762232942798,0.738311235171,0.644946808511};
		hotEffs10p= {0.770972037284,0.785617200049,0.815111111111,0.832696390658,0.840799448656,0.813677599442,0.716755319149};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttbarHT500Njet9"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.407909294843,0.487360654607,0.554943124203,0.585792903693,0.607100158595,0.624351331646,0.610264067903,0.570180155956,0.529164477141,0.417211703959};
		hotEffs2p = {0.568257255093,0.618534948399,0.665471923536,0.685199131064,0.698426253507,0.708109962688,0.696007544797,0.66415703146,0.621650026274,0.499139414802};
		hotEffs5p = {0.736228265173,0.755602546717,0.781532684758,0.791745112238,0.799609613273,0.804949178711,0.792675259352,0.767410594246,0.723068838676,0.618244406196};
		hotEffs10p= {0.834972644315,0.840545199623,0.854462214994,0.860637219406,0.867268512871,0.87095252391,0.857041810751,0.837859639688,0.800840777719,0.702925989673};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttbar"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.252959824309,0.361397414942,0.459087366036,0.504119254456,0.534357717034,0.550922369278,0.535451420581,0.492177755604,0.438544880534,0.298526640397};
		hotEffs2p = {0.39900220362,0.493794233602,0.574189819563,0.608677624155,0.631207830733,0.641467233281,0.624997572486,0.58401339938,0.523498600847,0.380589343841};
		hotEffs5p = {0.588466684642,0.652158801147,0.707418016666,0.730327047958,0.745084736246,0.749944084098,0.732041248325,0.69227753822,0.632991318074,0.48338187425};
		hotEffs10p= {0.721765531851,0.763493052893,0.801389053122,0.815564800087,0.823962905082,0.823869769432,0.80799331948,0.771996721428,0.718160292746,0.574610244989};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttVjets"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.25058416855,0.337887212073,0.411016797393,0.443887827299,0.467403702729,0.474528168015,0.454567022539,0.411171171171,0.368152866242,0.247029393371};
		hotEffs2p = {0.395882818686,0.471008737093,0.528383653881,0.553943087332,0.570150039484,0.56903646942,0.539264531435,0.495135135135,0.452229299363,0.330206378987};
		hotEffs5p = {0.582893999961,0.633783425999,0.669388632212,0.683313536126,0.691936474511,0.690506598553,0.664294187426,0.607207207207,0.579617834395,0.430268918074};
		hotEffs10p= {0.715350597686,0.747603918454,0.769958096057,0.777668749677,0.780994998684,0.78288633461,0.749466192171,0.707747747748,0.675796178344,0.522826766729};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttHToNonbb"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.283254772173,0.370313194136,0.441448382126,0.485894673548,0.5044754744,0.51778614773,0.402069297401};
		hotEffs2p = {0.438354561562,0.511728120835,0.561922187982,0.595279851681,0.607948442535,0.61581920904,0.491578440808};
		hotEffs5p = {0.629559054592,0.672112394491,0.70531587057,0.721250688981,0.727980665951,0.726197949362,0.615736284889};
		hotEffs10p= {0.756560692675,0.781452687694,0.800783256292,0.809640727564,0.808628714644,0.80989746809,0.700433108758};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttHTobb"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.306951814618,0.400615427169,0.481797844214,0.522922404017,0.541345583877,0.54735152488,0.417312661499};
		hotEffs2p = {0.468254179889,0.544082564049,0.607585926378,0.636886440953,0.652934202727,0.639200998752,0.502153316107};
		hotEffs5p = {0.662009013093,0.708830342634,0.748525523693,0.759274258869,0.766597510373,0.752452291778,0.617571059432};
		hotEffs10p= {0.786299032026,0.81291705563,0.833384177344,0.84318807711,0.838470657973,0.820581416087,0.699827734711};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="tttt"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.311329828161,0.390131583914,0.447922957643,0.479768786127,0.503408790045,0.50556497774,0.495245245245,0.459487179487,0.408713227038,0.294583883752};
		hotEffs2p = {0.462714798666,0.528502298755,0.5714845344,0.594583600942,0.609445326979,0.607536569854,0.591257924591,0.557307692308,0.505501908826,0.386393659181};
		hotEffs5p = {0.646111182354,0.686146320104,0.71145025708,0.72575465639,0.731135822081,0.725991096036,0.708375041708,0.674871794872,0.632158095666,0.503302509908};
		hotEffs10p= {0.763352782765,0.788031374799,0.80355831225,0.811025476343,0.811854646545,0.807504769981,0.787287287287,0.762564102564,0.719514933753,0.594671950683};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else{ std::cerr << "The sample " << sample << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}

}


void HardcodedConditions::GetHOTmistagEff2016APV(double pt, double *eff, std::string sample, std::string workingpoint, int massIndex)
{
	// VALUES from Slide 20 in https://indico.cern.ch/event/828647/contributions/3468595/attachments/1863710/3063888/ResolvedTopTagger_HOT2.pdf
	ptMins = {0,150,250,300,350,400,450,500,600};
	hotEffs = {0.0015,0.005,0.0095,0.0135,0.0155,0.016,0.0145,0.0115,0.005};
	int bin = findBin(pt, ptMins);
	*eff = hotEffs[bin];
}

void HardcodedConditions::GetHOTmistagEff2016(double pt, double *eff, std::string sample, std::string workingpoint, int massIndex)
{
	// VALUES from Slide 20 in https://indico.cern.ch/event/828647/contributions/3468595/attachments/1863710/3063888/ResolvedTopTagger_HOT2.pdf
	ptMins = {0,150,250,300,350,400,450,500,600};
	hotEffs = {0.0015,0.005,0.0095,0.0135,0.0155,0.016,0.0145,0.0115,0.005};
	int bin = findBin(pt, ptMins);
	*eff = hotEffs[bin];
}

void HardcodedConditions::GetHOTtaggingEff2017(double pt, double *eff, std::string sample, std::string workingpoint, int massIndex)
{
	if(sample=="singletop"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.238703480146,0.344134347664,0.434589800443,0.475746268657,0.518656716418,0.507683863886,0.394703656999};
		hotEffs2p = {0.368731908044,0.464867471993,0.537324464154,0.574419568823,0.607794361526,0.594401756312,0.471626733922};
		hotEffs5p = {0.54382958838,0.612588516432,0.670467743638,0.697968490879,0.713515754561,0.708562019759,0.566204287516};
		hotEffs10p= {0.671183976531,0.722995637209,0.76665610812,0.781301824212,0.790215588723,0.783754116356,0.645649432535};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="TTVV"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.349224166392,0.427451708767,0.499334221039,0.520619877049,0.558111860373,0.56627719581,0.438589981447};
		hotEffs2p = {0.499438758666,0.557317979198,0.607723035952,0.62487192623,0.656287187624,0.656124093473,0.525788497217};
		hotEffs5p = {0.664443710796,0.702674591382,0.731025299601,0.737320696721,0.755850852836,0.757655116841,0.640074211503};
		hotEffs10p= {0.770287223506,0.797288261516,0.814824678207,0.815573770492,0.83141610472,0.818291700242,0.714285714286};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="TTTX"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.354968471407,0.433300637567,0.507690054197,0.538025210084,0.567065073041,0.558911384003,0.447599729547};
		hotEffs2p = {0.501304631442,0.561611083865,0.623553537425,0.64243697479,0.666002656042,0.647195486226,0.540229885057};
		hotEffs5p = {0.670580560992,0.705983325159,0.748498608466,0.754201680672,0.762284196547,0.74709591769,0.651115618661};
		hotEffs10p= {0.775277234181,0.798369298676,0.826717445437,0.829411764706,0.831673306773,0.814802522403,0.73968897904};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttbar"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.269151562867,0.371040944242,0.46093357409,0.500559342772,0.529478935766,0.537946286717,0.52057549505,0.472972972973,0.420305878017,0.276479750779};
		hotEffs2p = {0.409420532838,0.495800937276,0.567888124784,0.597745149449,0.618724849018,0.621770021734,0.604450288779,0.557548928239,0.499907868067,0.350689808634};
		hotEffs5p = {0.587507414481,0.64446661573,0.694030504437,0.714070966614,0.728097654509,0.725256428181,0.705548679868,0.662488350419,0.602634973282,0.453604806409};
		hotEffs10p= {0.713205263769,0.750500206068,0.784037803988,0.797203286139,0.805845103535,0.799979663688,0.782152433993,0.742684063374,0.683618942325,0.537939474855};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttbarHT500Njet9"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.420852331885,0.49926498383,0.564610559123,0.591745991624,0.615611535924,0.626310934991,0.615721617224,0.574397250711,0.528376963351,0.407833470282};
		hotEffs2p = {0.581325769815,0.630417434401,0.675020226295,0.692950658632,0.706585025036,0.712875345882,0.700431843785,0.666809858777,0.621465968586,0.492467817036};
		hotEffs5p = {0.747017077753,0.765742585467,0.789658484483,0.799216420697,0.808368590614,0.809209852082,0.796689197647,0.77076733072,0.732251308901,0.610928512736};
		hotEffs10p= {0.842857541777,0.848382142668,0.861767718434,0.866446835523,0.873704537515,0.874150240836,0.861622230567,0.839392149493,0.810261780105,0.699808271706};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttVjets"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.288452231149,0.373458612278,0.449154067675,0.486258527123,0.509460431655,0.520363614616,0.49159748937,0.45743846998,0.393109061313,0.249461786868};
		hotEffs2p = {0.428064401639,0.49869671282,0.558195344372,0.587842991958,0.599064748201,0.607439746427,0.576331241142,0.543815645085,0.476125881715,0.318622174381};
		hotEffs5p = {0.602006904785,0.646202087487,0.685520158387,0.704814419284,0.709748201439,0.713952514802,0.685260174124,0.654021006427,0.591427021161,0.414962325081};
		hotEffs10p= {0.722776110735,0.751445312065,0.777447804176,0.790576030338,0.789928057554,0.796064828659,0.766045758251,0.734127606208,0.675529028757,0.497039827772};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttHToNonbb"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.322708874232,0.407453342783,0.475704187558,0.514392259134,0.539779313898,0.537583014691,0.427537922987};
		hotEffs2p = {0.470150457177,0.537347249962,0.586948188356,0.615564600648,0.633978790091,0.623717045683,0.508518086348};
		hotEffs5p = {0.646441760333,0.68446513326,0.715626293758,0.730337078652,0.742089219012,0.731183336687,0.613302217036};
		hotEffs10p= {0.760219960975,0.78353521036,0.802904150758,0.811450437495,0.817397277919,0.804789696116,0.697549591599};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttHTobb"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.349631239811,0.446789663388,0.523204501703,0.554238073182,0.572679367653,0.573949497904,0.453166226913};
		hotEffs2p = {0.50534896359,0.580202415134,0.635213978972,0.658452987494,0.667936765302,0.659744564688,0.539797713281};
		hotEffs5p = {0.683611520845,0.726871932718,0.756759958537,0.771607225567,0.771139035266,0.762796139222,0.647317502199};
		hotEffs10p= {0.794689853272,0.818254016739,0.835628609507,0.843584993052,0.841183623835,0.830067271132,0.728671943712};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="tttt"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.352514194404,0.430878952682,0.49099243151,0.515815708562,0.532235793946,0.536272793993,0.516997674003,0.493587033122,0.429605416764,0.316731141199};
		hotEffs2p = {0.495189202054,0.558040511935,0.602814198913,0.620469579801,0.627792529651,0.625134082312,0.605832886026,0.580408738548,0.519495680598,0.392408123791};
		hotEffs5p = {0.65894332438,0.700410329892,0.727498845184,0.733369048728,0.739281288724,0.730028792412,0.712918232242,0.68245243129,0.623161335512,0.488636363636};
		hotEffs10p= {0.767653758542,0.793288175335,0.809952741357,0.811702226777,0.812143742255,0.805961723028,0.787618536411,0.76067653277,0.704646275975,0.575435203095};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else{ std::cerr << "The sample " << sample << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
}

void HardcodedConditions::GetHOTmistagEff2017(double pt, double *eff, std::string sample, std::string workingpoint, int massIndex)
{
	// VALUES from Slide 24 in https://indico.cern.ch/event/828647/contributions/3468595/attachments/1863710/3063888/ResolvedTopTagger_HOT2.pdf
	ptMins = {0,150,250,300,350,400,450,500,600};
	hotEffs = {0.001,0.004,0.008,0.0115,0.013,0.013,0.0125,0.0085,0.0035};
	int bin = findBin(pt, ptMins);
	*eff = hotEffs[bin];
}

void HardcodedConditions::GetHOTtaggingEff2018(double pt, double *eff, std::string sample, std::string workingpoint, int massIndex)
{
	if(sample=="singletop"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.212296119533,0.315031032999,0.406236058097,0.45123586894,0.482085987261,0.467056323061,0.377334993773};
		hotEffs2p = {0.339097202454,0.433202236834,0.510682595549,0.548380915884,0.587579617834,0.550743889479,0.452054794521};
		hotEffs5p = {0.507791822372,0.580153219034,0.640608734447,0.665453151945,0.700835987261,0.664984059511,0.564757160648};
		hotEffs10p= {0.639292830797,0.693213707778,0.738611014723,0.760682123012,0.78523089172,0.751062699256,0.658779576588};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="TTVV"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.306757547592,0.388706280631,0.457114122887,0.484619395203,0.519713261649,0.516032171582,0.406852649317};
		hotEffs2p = {0.446968914593,0.510106875037,0.567166323452,0.588373305527,0.611954459203,0.603217158177,0.492229919491};
		hotEffs5p = {0.6178181693,0.655854508237,0.693022364829,0.711222627737,0.720851781573,0.70981233244,0.600074892342};
		hotEffs10p= {0.729319425798,0.756411518098,0.784588860687,0.796532846715,0.798545224541,0.788632707775,0.680022467703};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="TTTX"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.320480258601,0.40133316564,0.479001825928,0.507153534059,0.526281208936,0.531127712558,0.443624161074};
		hotEffs2p = {0.460978988686,0.5288642938,0.592818015825,0.609438394192,0.624835742444,0.624332977588,0.518791946309};
		hotEffs5p = {0.626876010159,0.670230159728,0.720328667072,0.730728165706,0.727003942181,0.731412308787,0.61610738255};
		hotEffs10p= {0.742438235973,0.76895987926,0.798843578819,0.806747811232,0.799605781866,0.797936677339,0.695302013423};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttbar"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.239645560484,0.339776636222,0.431088672755,0.472410045883,0.500610192316,0.508911240515,0.495590310442,0.453230420467,0.390272209327,0.257381258023};
		hotEffs2p = {0.373344786383,0.461458384312,0.53720713172,0.569649038075,0.590771367252,0.595406152579,0.577404750706,0.537323905651,0.469086305128,0.332092426187};
		hotEffs5p = {0.550542735949,0.611085074492,0.664600193036,0.688434087311,0.70022023033,0.701194047409,0.683060912512,0.642953527285,0.574382781177,0.424133504493};
		hotEffs10p= {0.680216158719,0.720677490343,0.759026901279,0.774571359575,0.783206385277,0.78032174578,0.762582314205,0.724564149619,0.668917493142,0.512836970475};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttbarHT500Njet9"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.382883189333,0.463774763516,0.530534334919,0.564121055076,0.585513888459,0.595023744476,0.582740745664,0.55169669755,0.508245382586,0.387973402718};
		hotEffs2p = {0.541805565004,0.59518344389,0.641367700136,0.664696751167,0.679590004026,0.685399438934,0.671130457899,0.642983004604,0.600043975374,0.476293726511};
		hotEffs5p = {0.711693822709,0.735689977202,0.762616536367,0.775344073142,0.786775255731,0.785309594969,0.771549146009,0.747967941795,0.712401055409,0.592223185892};
		hotEffs10p= {0.814625994966,0.824408134231,0.841727352727,0.848803383284,0.856109167105,0.856488017749,0.843523625972,0.820042062184,0.791886543536,0.68545822492};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttVjets"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.248203555141,0.336000706936,0.410729173126,0.448669593355,0.469720348827,0.480485326639,0.454306244307,0.427374526706,0.360325061675,0.238377129656};
		hotEffs2p = {0.381978758931,0.457716400911,0.519888105721,0.549423937014,0.563393956206,0.568047337278,0.544023884222,0.50938532184,0.447395153098,0.309558186543};
		hotEffs5p = {0.556277269744,0.607370787841,0.652259589216,0.670757847441,0.677837687893,0.681130834977,0.655399251088,0.614919842101,0.557248585111,0.41264799307};
		hotEffs10p= {0.682254559552,0.716801017202,0.748003610382,0.762206558256,0.764697723608,0.764837726376,0.739904867928,0.700072504632,0.650848933391,0.498123014727};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttHToNonbb"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.287911917634,0.372938377432,0.444955418438,0.479304265453,0.503111984651,0.511731658956,0.394968553459};
		hotEffs2p = {0.431923831824,0.500676886208,0.555987494003,0.58108570376,0.599653703964,0.601454064772,0.477106918239};
		hotEffs5p = {0.609810268241,0.652403090058,0.68518304081,0.701576191353,0.709906874444,0.712161269002,0.58679245283};
		hotEffs10p= {0.730054061499,0.755174579034,0.776794428545,0.787464147567,0.793766671346,0.791749283983,0.669685534591};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="ttHTobb"){
		ptMins = {0,150,250,300,350,400,500};
		hotEffs1p = {0.318843650941,0.416048224125,0.492033415169,0.52523214609,0.546462416046,0.548041732671,0.441785091};
		hotEffs2p = {0.473585688679,0.549666357685,0.602642895981,0.62854038954,0.641043334253,0.637242584804,0.526427324857};
		hotEffs5p = {0.653722197204,0.69979676318,0.728575900875,0.744988489692,0.750805041862,0.741628885126,0.631388681127};
		hotEffs10p= {0.771326145886,0.796325616475,0.812805852598,0.82023227542,0.823902842948,0.814606434697,0.71540762902};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else if(sample=="tttt"){
		ptMins = {0,150,250,300,350,400,450,500,550,600};
		hotEffs1p = {0.320831918231,0.3982520778,0.461573343186,0.482859420675,0.502006407014,0.500831411254,0.495233142659,0.45651048408,0.412305671119,0.289095332891};
		hotEffs2p = {0.463894684068,0.525030962526,0.572251519936,0.588138896271,0.601315123925,0.594861342059,0.585283411336,0.549055138493,0.501423253777,0.371156823712};
		hotEffs5p = {0.631604483043,0.670621042055,0.698431359377,0.708920187793,0.715528578655,0.704446709221,0.693534408043,0.660367589956,0.616816290782,0.47401017474};
		hotEffs10p= {0.743712904113,0.767403276186,0.785529542172,0.792209230224,0.794267408531,0.784959502226,0.770150806032,0.746311157132,0.695423691701,0.555629285556};
		int bin = findBin(pt, ptMins);
		if(workingpoint=="1pfake"){*eff = hotEffs1p[bin];}
		else if(workingpoint=="2pfake"){*eff = hotEffs2p[bin];}
		else if(workingpoint=="5pfake"){*eff = hotEffs5p[bin];}
		else if(workingpoint=="10pfake"){*eff = hotEffs10p[bin];}
		else{ std::cerr << "Working Point " << workingpoint << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
		}
	else{ std::cerr << "The sample " << sample << " not coded into HardcodedConditions::GetHOTtaggingEff2017! Aborting ..." << std::endl; std::abort();}
}

void HardcodedConditions::GetHOTmistagEff2018(double pt, double *eff, std::string sample, std::string workingpoint, int massIndex)
{
	// VALUES from Slide 28 in https://indico.cern.ch/event/828647/contributions/3468595/attachments/1863710/3063888/ResolvedTopTagger_HOT2.pdf
	ptMins = {0,150,250,300,350,400,450,500,600};
	hotEffs = {0.001,0.003,0.007,0.009,0.0115,0.012,0.0095,0.008,0.0025};
	int bin = findBin(pt, ptMins);
	*eff = hotEffs[bin];
}
      


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|           T TAGGING SCALE FACTOR SECTION            |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetTtaggingSF(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn, std::string year)
{
  //The main getter for GetTtaggingSF Scale Factors
  *tau32sf   = 1.000;
  *tau32sfup = 1.000;
  *tau32sfdn = 1.000;
  if      (year=="2016APV") GetTtaggingSF2016APV(pt, tau32sf, tau32sfup, tau32sfdn);
  else if (year=="2016") GetTtaggingSF2016(pt, tau32sf, tau32sfup, tau32sfdn);
  else if (year=="2017") GetTtaggingSF2017(pt, tau32sf, tau32sfup, tau32sfdn);
  else if (year=="2018") GetTtaggingSF2018(pt, tau32sf, tau32sfup, tau32sfdn);
}//end GetTtaggingSF

// Needs to be updated
void HardcodedConditions::GetTtaggingSF2016APV(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn) {
  *tau32sf   = 1.0;
  *tau32sfup = 1.0;
  *tau32sfdn = 1.0;
}

// Needs to be updated
void HardcodedConditions::GetTtaggingSF2016(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn){
  *tau32sf   = 1.0;
  *tau32sfup = 1.0;
  *tau32sfdn = 1.0;
}

void HardcodedConditions::GetTtaggingSF2017(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn) {
// Will be replaced by RunIISummer20UL version
  if ( pt < 400.0 ) {
    *tau32sf   = 1.10981;
    *tau32sfup = 1.14199;
    *tau32sfdn = 1.07812; }
  else {
    *tau32sf   = 1.13264;
    *tau32sfup = 1.18365;
    *tau32sfdn = 1.08415; }
}

void HardcodedConditions::GetTtaggingSF2018(double pt, double *tau32sf, double *tau32sfup, double *tau32sfdn) {
// will be replaced by RunIISummer20UL version
if ( pt < 400.0 ) {
  *tau32sf   = 1.13869;
  *tau32sfup = 1.17326;
  *tau32sfdn = 1.10527; }
else {
  *tau32sf   = 1.12333;
  *tau32sfup = 1.16340;
  *tau32sfdn = 1.08492; }
}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|            T TAGGING EFFICIENCY SECTION             |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetTtaggingEff(double pt, double *eff, std::string year, std::string sample, int massIndex)
{
  //The main getter for GetTtaggingEff Efficiencies
  *eff = 1.000;
  if      (year=="2016APV") GetTtaggingEff2016APV(pt, eff, sample, massIndex);
  else if (year=="2016") GetTtaggingEff2016(pt, eff, sample, massIndex);
  else if (year=="2017") GetTtaggingEff2017(pt, eff, sample, massIndex);
  else if (year=="2018") GetTtaggingEff2018(pt, eff, sample, massIndex);
}//end GetTtaggingEff

void HardcodedConditions::GetTtaggingEff2016APV(double pt, double *eff, std::string sample, int massIndex){
  *eff = 1.0;
}

void HardcodedConditions::GetTtaggingEff2016(double pt, double *eff, std::string sample, int massIndex){
  *eff = 1.0;
}

void HardcodedConditions::GetTtaggingEff2017(double pt, double *eff, std::string sample, int massIndex){
  *eff = 1.0; 
}

void HardcodedConditions::GetTtaggingEff2018(double pt, double *eff, std::string sample, int massIndex){
  *eff = 1.0;
}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|           W TAGGING SCALE FACTOR SECTION            |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetWtaggingSF(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn, std::string year){
  //The main getter for GetWtaggingSF Scale Factors
  *tau21sf   = 1.000;
  *tau21sfup = 1.000;
  *tau21sfdn = 1.000;
  *tau21ptsfup = 1.000;
  *tau21ptsfdn = 1.000;
  if      (year=="2016APV") GetWtaggingSF2016APV(pt, tau21sf, tau21sfup, tau21sfdn, tau21ptsfup, tau21ptsfdn);
  else if (year=="2016") GetWtaggingSF2017(pt, tau21sf, tau21sfup, tau21sfdn, tau21ptsfup, tau21ptsfdn);
  else if (year=="2017") GetWtaggingSF2017(pt, tau21sf, tau21sfup, tau21sfdn, tau21ptsfup, tau21ptsfdn);
  else if (year=="2018") GetWtaggingSF2018(pt, tau21sf, tau21sfup, tau21sfdn, tau21ptsfup, tau21ptsfdn);
}//end GetWtaggingSF

// haven't been updated yet
void HardcodedConditions::GetWtaggingSF2016APV(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn){
  *tau21sf = 1.0;
  *tau21sfup = 1.0;
  *tau21sfdn = 1.0;
  *tau21ptsfup = 1.0;
  *tau21ptsfdn = 1.0;
}

void HardcodedConditions::GetWtaggingSF2016(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn){
  *tau21sf = 1.0;
  *tau21sfup = 1.0;
  *tau21sfdn = 1.0;
  *tau21ptsfup = 1.0;
  *tau21ptsfdn = 1.0;
}

void HardcodedConditions::GetWtaggingSF2017(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn){
  *tau21sf = 1.0;
  *tau21sfup = 1.0;
  *tau21sfdn = 1.0;
  *tau21ptsfup = 1.0;
  *tau21ptsfdn = 1.0;
}

void HardcodedConditions::GetWtaggingSF2018(double pt, double *tau21sf, double *tau21sfup, double *tau21sfdn, double *tau21ptsfup, double *tau21ptsfdn){
  *tau21sf = 1.0;
  *tau21sfup = 1.0;
  *tau21sfdn = 1.0;
  *tau21ptsfup = 1.0;
  *tau21ptsfdn = 1.0;
}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|            W TAGGING EFFICIENCY SECTION             |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetWtaggingEff(double pt, double *eff, std::string year, std::string sample, int massIndex)
{
  //The main getter for GetTtaggingEff Efficiencies
  *eff = 1.000;
  if      (year=="2016") GetWtaggingEff2016APV(pt, eff, sample, massIndex);
  else if (year=="2016") GetWtaggingEff2017(pt, eff, sample, massIndex);
  else if (year=="2017") GetWtaggingEff2017(pt, eff, sample, massIndex);
  else if (year=="2018") GetWtaggingEff2018(pt, eff, sample, massIndex);
}//end GetTtaggingEff

// not updated for UL yet
void HardcodedConditions::GetWtaggingEff2016APV(double pt, double *eff, std::string sample, int massIndex){
  *eff = 1.000;
}

void HardcodedConditions::GetWtaggingEff2016(double pt, double *eff, std::string sample, int massIndex){
  *eff = 1.000;
}

void HardcodedConditions::GetWtaggingEff2017(double pt, double *eff, std::string sample, int massIndex){
  *eff = 1.0;
}

void HardcodedConditions::GetWtaggingEff2018(double pt, double *eff, std::string sample, int massIndex){
  *eff = 1.0;
}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|           EGammaGsf SCALE FACTOR SECTION            |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/
// Derived using correctionlib tool and using the RecoAbove20 key

double HardcodedConditions::GetEGammaGsfSF(double pt, double eta, std::string year, std::string shift)
{
  //The main getter for EGammaGsf Scale Factors
  if      (year=="2016APV") return GetEGammaGsfSF2016APV(pt, eta, shift);
  else if (year=="2016") return GetEGammaGsfSF2016(pt, eta, shift);
  else if (year=="2017") return GetEGammaGsfSF2017(pt, eta, shift);
  else if (year=="2018") return GetEGammaGsfSF2018(pt, eta, shift);
  else return 0.;
}

double HardcodedConditions::GetEGammaGsfSF2016APV(double pt, double eta, std::string shift){
  if ( shift == "up" ){
    if ( pt < 45.0 ) {
      if ( eta < -2.0 ) return 1.00017;
      else if ( eta < -1.566 ) return 0.99588;
      else if ( eta < -1.444 ) return 0.97537;
      else if ( eta < -1.0 ) return 0.98784;
      else if ( eta < -0.5 ) return 0.98206;
      else if ( eta < 0.0 ) return 0.97784;
      else if ( eta < 0.5 ) return 0.98918;
      else if ( eta < 1.0 ) return 0.99032;
      else if ( eta < 1.444 ) return 0.99196;
      else if ( eta < 1.566 ) return 0.98933;
      else if ( eta < 2.0 ) return 0.99695;
      else return 1.00338; }
    else if ( pt < 75.0 ) {
      if ( eta < -2.0 ) return 0.99765;
      else if ( eta < -1.566 ) return 0.99495;
      else if ( eta < -1.444 ) return 0.96835;
      else if ( eta < -1.0 ) return 0.98883;
      else if ( eta < -0.5 ) return 0.98472;
      else if ( eta < 0.0 ) return 0.98346;
      else if ( eta < 0.5 ) return 0.99165;
      else if ( eta < 1.0 ) return 0.99088;
      else if ( eta < 1.444 ) return 0.99088;
      else if ( eta < 1.566 ) return 0.98132;
      else if ( eta < 2.0 ) return 0.99294;
      else return 0.99860; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 1.00244;
      else if ( eta < -1.566 ) return 1.00733;
      else if ( eta < -1.444 ) return 1.04290;
      else if ( eta < -1.0 ) return 0.99212;
      else if ( eta < -0.5 ) return 0.99145;
      else if ( eta < 0.0 ) return 0.99497;
      else if ( eta < 0.5 ) return 0.99497;
      else if ( eta < 1.0 ) return 0.99145;
      else if ( eta < 1.444 ) return 0.99212;
      else if ( eta < 1.566 ) return 1.04290;
      else if ( eta < 2.0 ) return 1.00733;
      else return 1.00244; }
    else {
      if ( eta < -2.0 ) return 1.02715;
      else if ( eta < -1.566 ) return 1.02500;
      else if ( eta < -1.444 ) return 1.04118;
      else if ( eta < -1.0 ) return 0.98579;
      else if ( eta < -0.5 ) return 0.99163;
      else if ( eta < 0.0 ) return 0.99674;
      else if ( eta < 0.5 ) return 0.99674;
      else if ( eta < 1.0 ) return 0.99163;
      else if ( eta < 1.444 ) return 0.98579;
      else if ( eta < 1.566 ) return 1.04118;
      else if ( eta < 2.0 ) return 1.02500;
      else return 1.02715; }
  }
  else if ( shift == "down" ){
    if ( pt < 45.0 ) {
      if ( eta < -2.0 ) return 0.99342;
      else if ( eta < -1.566 ) return 0.98957;
      else if ( eta < -1.444 ) return 0.93983;
      else if ( eta < -1.0 ) return 0.98336;
      else if ( eta < -0.5 ) return 0.97683;
      else if ( eta < 0.0 ) return 0.97268;
      else if ( eta < 0.5 ) return 0.98402;
      else if ( eta < 1.0 ) return 0.98509;
      else if ( eta < 1.444 ) return 0.98748;
      else if ( eta < 1.566 ) return 0.95379;
      else if ( eta < 2.0 ) return 0.99065;
      else return 0.99662; }
    else if ( pt < 75.0 ) {
      if ( eta < -2.0 ) return 0.98553;
      else if ( eta < -1.566 ) return 0.99058;
      else if ( eta < -1.444 ) return 0.95598;
      else if ( eta < -1.0 ) return 0.98462;
      else if ( eta < -0.5 ) return 0.97851;
      else if ( eta < 0.0 ) return 0.97560;
      else if ( eta < 0.5 ) return 0.98379;
      else if ( eta < 1.0 ) return 0.98468;
      else if ( eta < 1.444 ) return 0.98667;
      else if ( eta < 1.566 ) return 0.96895;
      else if ( eta < 2.0 ) return 0.98858;
      else return 0.98648; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.97431;
      else if ( eta < -1.566 ) return 0.96193;
      else if ( eta < -1.444 ) return 0.98136;
      else if ( eta < -1.0 ) return 0.97344;
      else if ( eta < -0.5 ) return 0.96176;
      else if ( eta < 0.0 ) return 0.98052;
      else if ( eta < 0.5 ) return 0.98052;
      else if ( eta < 1.0 ) return 0.96176;
      else if ( eta < 1.444 ) return 0.97344;
      else if ( eta < 1.566 ) return 0.98136;
      else if ( eta < 2.0 ) return 0.96193;
      else return 0.97431; }
    else {
      if ( eta < -2.0 ) return 0.99202;
      else if ( eta < -1.566 ) return 1.00775;
      else if ( eta < -1.444 ) return 0.98758;
      else if ( eta < -1.0 ) return 0.97385;
      else if ( eta < -0.5 ) return 0.97809;
      else if ( eta < 0.0 ) return 0.98300;
      else if ( eta < 0.5 ) return 0.98300;
      else if ( eta < 1.0 ) return 0.97809;
      else if ( eta < 1.444 ) return 0.97385;
      else if ( eta < 1.566 ) return 0.98758;
      else if ( eta < 2.0 ) return 1.00775;
      else return 0.99202; }
  }
  else {
    if ( pt < 45.0 ) {
      if ( eta < -2.0 ) return 0.99679;
      else if ( eta < -1.566 ) return 0.99272;
      else if ( eta < -1.444 ) return 0.95760;
      else if ( eta < -1.0 ) return 0.98560;
      else if ( eta < -0.5 ) return 0.97945;
      else if ( eta < 0.0 ) return 0.97526;
      else if ( eta < 0.5 ) return 0.98660;
      else if ( eta < 1.0 ) return 0.98770;
      else if ( eta < 1.444 ) return 0.98972;
      else if ( eta < 1.566 ) return 0.97156;
      else if ( eta < 2.0 ) return 0.99380;
      else return 1.00000; }
    else if ( pt < 75.0 ) {
      if ( eta < -2.0 ) return 0.99159;
      else if ( eta < -1.566 ) return 0.99277;
      else if ( eta < -1.444 ) return 0.96216;
      else if ( eta < -1.0 ) return 0.98672;
      else if ( eta < -0.5 ) return 0.98161;
      else if ( eta < 0.0 ) return 0.97953;
      else if ( eta < 0.5 ) return 0.98772;
      else if ( eta < 1.0 ) return 0.98778;
      else if ( eta < 1.444 ) return 0.98878;
      else if ( eta < 1.566 ) return 0.97514;
      else if ( eta < 2.0 ) return 0.99076;
      else return 0.99254; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.98837;
      else if ( eta < -1.566 ) return 0.98463;
      else if ( eta < -1.444 ) return 1.01213;
      else if ( eta < -1.0 ) return 0.98278;
      else if ( eta < -0.5 ) return 0.97660;
      else if ( eta < 0.0 ) return 0.98774;
      else if ( eta < 0.5 ) return 0.98774;
      else if ( eta < 1.0 ) return 0.97660;
      else if ( eta < 1.444 ) return 0.98278;
      else if ( eta < 1.566 ) return 1.01213;
      else if ( eta < 2.0 ) return 0.98463;
      else return 0.98837; }
    else {
      if ( eta < -2.0 ) return 1.00958;
      else if ( eta < -1.566 ) return 1.01638;
      else if ( eta < -1.444 ) return 1.01438;
      else if ( eta < -1.0 ) return 0.97982;
      else if ( eta < -0.5 ) return 0.98486;
      else if ( eta < 0.0 ) return 0.98987;
      else if ( eta < 0.5 ) return 0.98987;
      else if ( eta < 1.0 ) return 0.98486;
      else if ( eta < 1.444 ) return 0.97982;
      else if ( eta < 1.566 ) return 1.01438;
      else if ( eta < 2.0 ) return 1.01638;
      else return 1.00958; }
  }
}

double HardcodedConditions::GetEGammaGsfSF2016( double pt, double eta, std::string shift ){
  if ( shift == "up" ){
    if ( pt < 45.0 ) {
      if ( eta < -2.0 ) return 1.03893;
      else if ( eta < -1.566 ) return 0.99622;
      else if ( eta < -1.444 ) return 1.01559;
      else if ( eta < -1.0 ) return 0.99026;
      else if ( eta < -0.5 ) return 0.98744;
      else if ( eta < 0.0 ) return 0.98583;
      else if ( eta < 0.5 ) return 0.98583;
      else if ( eta < 1.0 ) return 0.98747;
      else if ( eta < 1.444 ) return 0.98722;
      else if ( eta < 1.566 ) return 1.00252;
      else if ( eta < 2.0 ) return 0.99213;
      else return 0.99499; }
    else if ( pt < 75.0 ) {
      if ( eta < -2.0 ) return 1.02392;
      else if ( eta < -1.566 ) return 0.99142;
      else if ( eta < -1.444 ) return 0.96347;
      else if ( eta < -1.0 ) return 0.98835;
      else if ( eta < -0.5 ) return 0.98788;
      else if ( eta < 0.0 ) return 0.98751;
      else if ( eta < 0.5 ) return 0.98649;
      else if ( eta < 1.0 ) return 0.98889;
      else if ( eta < 1.444 ) return 0.98734;
      else if ( eta < 1.566 ) return 0.96284;
      else if ( eta < 2.0 ) return 0.99047;
      else return 0.99504; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 1.01866;
      else if ( eta < -1.566 ) return 0.99459;
      else if ( eta < -1.444 ) return 1.01381;
      else if ( eta < -1.0 ) return 0.99209;
      else if ( eta < -0.5 ) return 0.99505;
      else if ( eta < 0.0 ) return 0.99087;
      else if ( eta < 0.5 ) return 0.99087;
      else if ( eta < 1.0 ) return 0.99505;
      else if ( eta < 1.444 ) return 0.99209;
      else if ( eta < 1.566 ) return 1.01381;
      else if ( eta < 2.0 ) return 0.99459;
      else return 1.01866; }
    else {
      if ( eta < -2.0 ) return 1.02845;
      else if ( eta < -1.566 ) return 1.00730;
      else if ( eta < -1.444 ) return 1.03123;
      else if ( eta < -1.0 ) return 1.00019;
      else if ( eta < -0.5 ) return 0.99722;
      else if ( eta < 0.0 ) return 0.99372;
      else if ( eta < 0.5 ) return 0.99372;
      else if ( eta < 1.0 ) return 0.99722;
      else if ( eta < 1.444 ) return 1.00019;
      else if ( eta < 1.566 ) return 1.03123;
      else if ( eta < 2.0 ) return 1.00730;
      else return 1.02845; }
  }
  else if ( shift == "down" ){
    if ( pt < 45.0 ) {
      if ( eta < -2.0 ) return 1.03179;
      else if ( eta < -1.566 ) return 0.98917;
      else if ( eta < -1.444 ) return 0.96333;
      else if ( eta < -1.0 ) return 0.98502;
      else if ( eta < -0.5 ) return 0.98390;
      else if ( eta < 0.0 ) return 0.98135;
      else if ( eta < 0.5 ) return 0.98135;
      else if ( eta < 1.0 ) return 0.98393;
      else if ( eta < 1.444 ) return 0.98198;
      else if ( eta < 1.566 ) return 0.95025;
      else if ( eta < 2.0 ) return 0.98507;
      else return 0.98785; }
    else if ( pt < 75.0 ) {
      if ( eta < -2.0 ) return 1.01703;
      else if ( eta < -1.566 ) return 0.98784;
      else if ( eta < -1.444 ) return 0.95583;
      else if ( eta < -1.0 ) return 0.98512;
      else if ( eta < -0.5 ) return 0.98369;
      else if ( eta < 0.0 ) return 0.98398;
      else if ( eta < 0.5 ) return 0.98296;
      else if ( eta < 1.0 ) return 0.98471;
      else if ( eta < 1.444 ) return 0.98412;
      else if ( eta < 1.566 ) return 0.95509;
      else if ( eta < 2.0 ) return 0.98689;
      else return 0.98814; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.98134;
      else if ( eta < -1.566 ) return 0.95197;
      else if ( eta < -1.444 ) return 0.96870;
      else if ( eta < -1.0 ) return 0.97140;
      else if ( eta < -0.5 ) return 0.95835;
      else if ( eta < 0.0 ) return 0.96247;
      else if ( eta < 0.5 ) return 0.96247;
      else if ( eta < 1.0 ) return 0.95835;
      else if ( eta < 1.444 ) return 0.97140;
      else if ( eta < 1.566 ) return 0.96870;
      else if ( eta < 2.0 ) return 0.95197;
      else return 0.98134; }
    else {
      if ( eta < -2.0 ) return 0.99260;
      else if ( eta < -1.566 ) return 0.98657;
      else if ( eta < -1.444 ) return 0.96656;
      else if ( eta < -1.0 ) return 0.98368;
      else if ( eta < -0.5 ) return 0.98463;
      else if ( eta < 0.0 ) return 0.98002;
      else if ( eta < 0.5 ) return 0.98002;
      else if ( eta < 1.0 ) return 0.98463;
      else if ( eta < 1.444 ) return 0.98368;
      else if ( eta < 1.566 ) return 0.96656;
      else if ( eta < 2.0 ) return 0.98657;
      else return 0.99260; }
  }
  else {
    if ( pt < 45.0 ) {
      if ( eta < -2.0 ) return 1.03536;
      else if ( eta < -1.566 ) return 0.99269;
      else if ( eta < -1.444 ) return 0.98946;
      else if ( eta < -1.0 ) return 0.98764;
      else if ( eta < -0.5 ) return 0.98567;
      else if ( eta < 0.0 ) return 0.98359;
      else if ( eta < 0.5 ) return 0.98359;
      else if ( eta < 1.0 ) return 0.98570;
      else if ( eta < 1.444 ) return 0.98460;
      else if ( eta < 1.566 ) return 0.97639;
      else if ( eta < 2.0 ) return 0.98860;
      else return 0.99142; }
    else if ( pt < 75.0 ) {
      if ( eta < -2.0 ) return 1.02047;
      else if ( eta < -1.566 ) return 0.98963;
      else if ( eta < -1.444 ) return 0.95965;
      else if ( eta < -1.0 ) return 0.98673;
      else if ( eta < -0.5 ) return 0.98579;
      else if ( eta < 0.0 ) return 0.98574;
      else if ( eta < 0.5 ) return 0.98473;
      else if ( eta < 1.0 ) return 0.98680;
      else if ( eta < 1.444 ) return 0.98573;
      else if ( eta < 1.566 ) return 0.95896;
      else if ( eta < 2.0 ) return 0.98868;
      else return 0.99159; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 1.00000;
      else if ( eta < -1.566 ) return 0.97328;
      else if ( eta < -1.444 ) return 0.99126;
      else if ( eta < -1.0 ) return 0.98174;
      else if ( eta < -0.5 ) return 0.97670;
      else if ( eta < 0.0 ) return 0.97667;
      else if ( eta < 0.5 ) return 0.97667;
      else if ( eta < 1.0 ) return 0.97670;
      else if ( eta < 1.444 ) return 0.98174;
      else if ( eta < 1.566 ) return 0.99126;
      else if ( eta < 2.0 ) return 0.97328;
      else return 1.00000; }
    else {
      if ( eta < -2.0 ) return 1.01053;
      else if ( eta < -1.566 ) return 0.99694;
      else if ( eta < -1.444 ) return 0.99890;
      else if ( eta < -1.0 ) return 0.99194;
      else if ( eta < -0.5 ) return 0.99093;
      else if ( eta < 0.0 ) return 0.98687;
      else if ( eta < 0.5 ) return 0.98687;
      else if ( eta < 1.0 ) return 0.99093;
      else if ( eta < 1.444 ) return 0.99194;
      else if ( eta < 1.566 ) return 0.99890;
      else if ( eta < 2.0 ) return 0.99694;
      else return 1.01053; }
  }
}
double HardcodedConditions::GetEGammaGsfSF2017(double pt, double eta, std::string shift){
  if ( shift == "up" ){
    if ( pt < 45.0 ) {
      if ( eta < -2.0 ) return 0.98597;
      else if ( eta < -1.566 ) return 0.99242;
      else if ( eta < -1.444 ) return 0.96379;
      else if ( eta < -1.0 ) return 0.98441;
      else if ( eta < -0.5 ) return 0.98939;
      else if ( eta < 0.0 ) return 0.99018;
      else if ( eta < 0.5 ) return 0.99117;
      else if ( eta < 1.0 ) return 0.99446;
      else if ( eta < 1.444 ) return 0.98628;
      else if ( eta < 1.566 ) return 1.01637;
      else if ( eta < 2.0 ) return 0.99342;
      else return 0.99116; }
    else if ( pt < 75.0 ) {
      if ( eta < -2.0 ) return 0.98705;
      else if ( eta < -1.566 ) return 0.99062;
      else if ( eta < -1.444 ) return 0.96929;
      else if ( eta < -1.0 ) return 0.98650;
      else if ( eta < -0.5 ) return 0.99362;
      else if ( eta < 0.0 ) return 0.99233;
      else if ( eta < 0.5 ) return 0.99334;
      else if ( eta < 1.0 ) return 0.99866;
      else if ( eta < 1.444 ) return 0.98736;
      else if ( eta < 1.566 ) return 0.99363;
      else if ( eta < 2.0 ) return 0.99366;
      else return 0.99016; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.99667;
      else if ( eta < -1.566 ) return 1.01696;
      else if ( eta < -1.444 ) return 1.05513;
      else if ( eta < -1.0 ) return 1.00014;
      else if ( eta < -0.5 ) return 1.00607;
      else if ( eta < 0.0 ) return 0.99372;
      else if ( eta < 0.5 ) return 0.99372;
      else if ( eta < 1.0 ) return 1.00607;
      else if ( eta < 1.444 ) return 1.00014;
      else if ( eta < 1.566 ) return 1.05513;
      else if ( eta < 2.0 ) return 1.01696;
      else return 0.99667; }
    else {
      if ( eta < -2.0 ) return 0.99076;
      else if ( eta < -1.566 ) return 0.99555;
      else if ( eta < -1.444 ) return 1.09356;
      else if ( eta < -1.0 ) return 0.99576;
      else if ( eta < -0.5 ) return 0.99990;
      else if ( eta < 0.0 ) return 1.00620;
      else if ( eta < 0.5 ) return 1.00620;
      else if ( eta < 1.0 ) return 0.99990;
      else if ( eta < 1.444 ) return 0.99576;
      else if ( eta < 1.566 ) return 1.09356;
      else if ( eta < 2.0 ) return 0.99555;
      else return 0.99076; }
  }
  else if ( shift == "down" ) {
    if ( pt < 45.0 ) {
      if ( eta < -2.0 ) return 0.97695;
      else if ( eta < -1.566 ) return 0.98088;
      else if ( eta < -1.444 ) return 0.88850;
      else if ( eta < -1.0 ) return 0.97629;
      else if ( eta < -0.5 ) return 0.98394;
      else if ( eta < 0.0 ) return 0.98513;
      else if ( eta < 0.5 ) return 0.98612;
      else if ( eta < 1.0 ) return 0.98901;
      else if ( eta < 1.444 ) return 0.97816;
      else if ( eta < 1.566 ) return 0.94108;
      else if ( eta < 2.0 ) return 0.98189;
      else return 0.98214; }
    else if ( pt < 75.0 ) {
      if ( eta < -2.0 ) return 0.98020;
      else if ( eta < -1.566 ) return 0.98285;
      else if ( eta < -1.444 ) return 0.94552;
      else if ( eta < -1.0 ) return 0.97866;
      else if ( eta < -0.5 ) return 0.98398;
      else if ( eta < 0.0 ) return 0.98517;
      else if ( eta < 0.5 ) return 0.98617;
      else if ( eta < 1.0 ) return 0.98902;
      else if ( eta < 1.444 ) return 0.97952;
      else if ( eta < 1.566 ) return 0.96985;
      else if ( eta < 2.0 ) return 0.98589;
      else return 0.98331; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.95620;
      else if ( eta < -1.566 ) return 0.99123;
      else if ( eta < -1.444 ) return 0.99296;
      else if ( eta < -1.0 ) return 0.97739;
      else if ( eta < -0.5 ) return 0.99189;
      else if ( eta < 0.0 ) return 0.97573;
      else if ( eta < 0.5 ) return 0.97573;
      else if ( eta < 1.0 ) return 0.99189;
      else if ( eta < 1.444 ) return 0.97739;
      else if ( eta < 1.566 ) return 0.99296;
      else if ( eta < 2.0 ) return 0.99123;
      else return 0.95620; }
    else {
      if ( eta < -2.0 ) return 0.96690;
      else if ( eta < -1.566 ) return 0.98011;
      else if ( eta < -1.444 ) return 1.00576;
      else if ( eta < -1.0 ) return 0.98174;
      else if ( eta < -0.5 ) return 0.98997;
      else if ( eta < 0.0 ) return 0.99583;
      else if ( eta < 0.5 ) return 0.99583;
      else if ( eta < 1.0 ) return 0.98997;
      else if ( eta < 1.444 ) return 0.98174;
      else if ( eta < 1.566 ) return 1.00576;
      else if ( eta < 2.0 ) return 0.98011;
      else return 0.96690; }
  }
  else {
    if ( pt < 45.0 ) {
      if ( eta < -2.0 ) return 0.98146;
      else if ( eta < -1.566 ) return 0.98665;
      else if ( eta < -1.444 ) return 0.92614;
      else if ( eta < -1.0 ) return 0.98035;
      else if ( eta < -0.5 ) return 0.98667;
      else if ( eta < 0.0 ) return 0.98765;
      else if ( eta < 0.5 ) return 0.98865;
      else if ( eta < 1.0 ) return 0.99174;
      else if ( eta < 1.444 ) return 0.98222;
      else if ( eta < 1.566 ) return 0.97872;
      else if ( eta < 2.0 ) return 0.98765;
      else return 0.98665; }
    else if ( pt < 75.0 ) {
      if ( eta < -2.0 ) return 0.98362;
      else if ( eta < -1.566 ) return 0.98673;
      else if ( eta < -1.444 ) return 0.95740;
      else if ( eta < -1.0 ) return 0.98258;
      else if ( eta < -0.5 ) return 0.98880;
      else if ( eta < 0.0 ) return 0.98875;
      else if ( eta < 0.5 ) return 0.98975;
      else if ( eta < 1.0 ) return 0.99384;
      else if ( eta < 1.444 ) return 0.98344;
      else if ( eta < 1.566 ) return 0.98174;
      else if ( eta < 2.0 ) return 0.98978;
      else return 0.98673; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.97643;
      else if ( eta < -1.566 ) return 1.00409;
      else if ( eta < -1.444 ) return 1.02404;
      else if ( eta < -1.0 ) return 0.98876;
      else if ( eta < -0.5 ) return 0.99898;
      else if ( eta < 0.0 ) return 0.98473;
      else if ( eta < 0.5 ) return 0.98473;
      else if ( eta < 1.0 ) return 0.99898;
      else if ( eta < 1.444 ) return 0.98876;
      else if ( eta < 1.566 ) return 1.02404;
      else if ( eta < 2.0 ) return 1.00409;
      else return 0.97643; }
    else {
      if ( eta < -2.0 ) return 0.97883;
      else if ( eta < -1.566 ) return 0.98783;
      else if ( eta < -1.444 ) return 1.04966;
      else if ( eta < -1.0 ) return 0.98875;
      else if ( eta < -0.5 ) return 0.99493;
      else if ( eta < 0.0 ) return 1.00102;
      else if ( eta < 0.5 ) return 1.00102;
      else if ( eta < 1.0 ) return 0.99493;
      else if ( eta < 1.444 ) return 0.98875;
      else if ( eta < 1.566 ) return 1.04966;
      else if ( eta < 2.0 ) return 0.98783;
      else return 0.97883; }
  }
}

double HardcodedConditions::GetEGammaGsfSF2018(double pt, double eta, std::string shift){
  if ( shift == "up" ){
    if ( pt < 45.0 ) {
      if ( eta < -2.0 ) return 0.98713;
      else if ( eta < -1.566 ) return 0.99212;
      else if ( eta < -1.444 ) return 0.98010;
      else if ( eta < -1.0 ) return 0.98555;
      else if ( eta < -0.5 ) return 0.99234;
      else if ( eta < 0.0 ) return 0.99038;
      else if ( eta < 0.5 ) return 0.99027;
      else if ( eta < 1.0 ) return 0.99118;
      else if ( eta < 1.444 ) return 0.98227;
      else if ( eta < 1.566 ) return 0.99168;
      else if ( eta < 2.0 ) return 0.99110;
      else return 0.99027; }
    else if ( pt < 75.0 ) {
      if ( eta < -2.0 ) return 0.99204;
      else if ( eta < -1.566 ) return 0.99270;
      else if ( eta < -1.444 ) return 0.97466;
      else if ( eta < -1.0 ) return 0.98908;
      else if ( eta < -0.5 ) return 0.99395;
      else if ( eta < 0.0 ) return 0.99394;
      else if ( eta < 0.5 ) return 0.99175;
      else if ( eta < 1.0 ) return 0.99483;
      else if ( eta < 1.444 ) return 0.98585;
      else if ( eta < 1.566 ) return 0.98294;
      else if ( eta < 2.0 ) return 0.99270;
      else return 0.99412; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 1.00544;
      else if ( eta < -1.566 ) return 0.99867;
      else if ( eta < -1.444 ) return 1.05291;
      else if ( eta < -1.0 ) return 1.00608;
      else if ( eta < -0.5 ) return 0.99775;
      else if ( eta < 0.0 ) return 0.99372;
      else if ( eta < 0.5 ) return 0.99372;
      else if ( eta < 1.0 ) return 0.99775;
      else if ( eta < 1.444 ) return 1.00608;
      else if ( eta < 1.566 ) return 1.05291;
      else if ( eta < 2.0 ) return 0.99867;
      else return 1.00544; }
    else {
      if ( eta < -2.0 ) return 1.00646;
      else if ( eta < -1.566 ) return 1.01418;
      else if ( eta < -1.444 ) return 1.05453;
      else if ( eta < -1.0 ) return 1.00139;
      else if ( eta < -0.5 ) return 1.00122;
      else if ( eta < 0.0 ) return 1.00230;
      else if ( eta < 0.5 ) return 1.00230;
      else if ( eta < 1.0 ) return 1.00122;
      else if ( eta < 1.444 ) return 1.00139;
      else if ( eta < 1.566 ) return 1.05453;
      else if ( eta < 2.0 ) return 1.01418;
      else return 1.00646; }
  }
  else if ( shift == "down" ){
    if ( pt < 45.0 ) {
      if ( eta < -2.0 ) return 0.97995;
      else if ( eta < -1.566 ) return 0.98532;
      else if ( eta < -1.444 ) return 0.97078;
      else if ( eta < -1.0 ) return 0.97922;
      else if ( eta < -0.5 ) return 0.98503;
      else if ( eta < 0.0 ) return 0.98276;
      else if ( eta < 0.5 ) return 0.98265;
      else if ( eta < 1.0 ) return 0.98387;
      else if ( eta < 1.444 ) return 0.97594;
      else if ( eta < 1.566 ) return 0.98235;
      else if ( eta < 2.0 ) return 0.98431;
      else return 0.98309; }
    else if ( pt < 75.0 ) {
      if ( eta < -2.0 ) return 0.98138;
      else if ( eta < -1.566 ) return 0.98487;
      else if ( eta < -1.444 ) return 0.95718;
      else if ( eta < -1.0 ) return 0.97800;
      else if ( eta < -0.5 ) return 0.98153;
      else if ( eta < 0.0 ) return 0.98145;
      else if ( eta < 0.5 ) return 0.97926;
      else if ( eta < 1.0 ) return 0.98240;
      else if ( eta < 1.444 ) return 0.97477;
      else if ( eta < 1.566 ) return 0.96545;
      else if ( eta < 2.0 ) return 0.98487;
      else return 0.98346; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.98842;
      else if ( eta < -1.566 ) return 0.98914;
      else if ( eta < -1.444 ) return 1.01478;
      else if ( eta < -1.0 ) return 0.98978;
      else if ( eta < -0.5 ) return 0.98171;
      else if ( eta < 0.0 ) return 0.98579;
      else if ( eta < 0.5 ) return 0.98579;
      else if ( eta < 1.0 ) return 0.98171;
      else if ( eta < 1.444 ) return 0.98978;
      else if ( eta < 1.566 ) return 1.01478;
      else if ( eta < 2.0 ) return 0.98914;
      else return 0.98842; }
    else {
      if ( eta < -2.0 ) return 0.99151;
      else if ( eta < -1.566 ) return 1.00007;
      else if ( eta < -1.444 ) return 1.00708;
      else if ( eta < -1.0 ) return 0.98627;
      else if ( eta < -0.5 ) return 0.99060;
      else if ( eta < 0.0 ) return 0.98951;
      else if ( eta < 0.5 ) return 0.98951;
      else if ( eta < 1.0 ) return 0.99060;
      else if ( eta < 1.444 ) return 0.98627;
      else if ( eta < 1.566 ) return 1.00708;
      else if ( eta < 2.0 ) return 1.00007;
      else return 0.99151; }
  }
  else {
    if ( pt < 45.0 ) {
      if ( eta < -2.0 ) return 0.98354;
      else if ( eta < -1.566 ) return 0.98872;
      else if ( eta < -1.444 ) return 0.97544;
      else if ( eta < -1.0 ) return 0.98238;
      else if ( eta < -0.5 ) return 0.98868;
      else if ( eta < 0.0 ) return 0.98657;
      else if ( eta < 0.5 ) return 0.98646;
      else if ( eta < 1.0 ) return 0.98753;
      else if ( eta < 1.444 ) return 0.97910;
      else if ( eta < 1.566 ) return 0.98701;
      else if ( eta < 2.0 ) return 0.98770;
      else return 0.98668; }
    else if ( pt < 75.0 ) {
      if ( eta < -2.0 ) return 0.98671;
      else if ( eta < -1.566 ) return 0.98879;
      else if ( eta < -1.444 ) return 0.96592;
      else if ( eta < -1.0 ) return 0.98354;
      else if ( eta < -0.5 ) return 0.98774;
      else if ( eta < 0.0 ) return 0.98769;
      else if ( eta < 0.5 ) return 0.98551;
      else if ( eta < 1.0 ) return 0.98861;
      else if ( eta < 1.444 ) return 0.98031;
      else if ( eta < 1.566 ) return 0.97419;
      else if ( eta < 2.0 ) return 0.98879;
      else return 0.98879; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.99693;
      else if ( eta < -1.566 ) return 0.99390;
      else if ( eta < -1.444 ) return 1.03384;
      else if ( eta < -1.0 ) return 0.99793;
      else if ( eta < -0.5 ) return 0.98973;
      else if ( eta < 0.0 ) return 0.98975;
      else if ( eta < 0.5 ) return 0.98975;
      else if ( eta < 1.0 ) return 0.98973;
      else if ( eta < 1.444 ) return 0.99793;
      else if ( eta < 1.566 ) return 1.03384;
      else if ( eta < 2.0 ) return 0.99390;
      else return 0.99693; }
    else {
      if ( eta < -2.0 ) return 0.99898;
      else if ( eta < -1.566 ) return 1.00713;
      else if ( eta < -1.444 ) return 1.03080;
      else if ( eta < -1.0 ) return 0.99383;
      else if ( eta < -0.5 ) return 0.99591;
      else if ( eta < 0.0 ) return 0.99591;
      else if ( eta < 0.5 ) return 0.99591;
      else if ( eta < 1.0 ) return 0.99591;
      else if ( eta < 1.444 ) return 0.99383;
      else if ( eta < 1.566 ) return 1.03080;
      else if ( eta < 2.0 ) return 1.00713;
      else return 0.99898; }
  }
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|          ELECTRON ID SCALE FACTOR SECTION           |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/
// derived using correctionlib tool with the wp90noiso key
double HardcodedConditions::GetElectronIdSF(double pt, double eta, std::string year, std::string shift)
{
  if      (year=="2016APV") return GetElectronIdSF2016APV(pt, eta, shift);
  else if (year=="2016") return GetElectronIdSF2016(pt, eta, shift);
  else if (year=="2017") return GetElectronIdSF2017(pt, eta, shift);
  else if (year=="2018") return GetElectronIdSF2018(pt, eta, shift);
  else return 0.;
}
double HardcodedConditions::GetElectronIdSF2016APV(double pt, double eta, std::string shift){
  if ( shift == "up" ){
    if ( pt < 20.0 ) {
      if ( eta < -2.0 ) return 1.03931;
      else if ( eta < -1.566 ) return 1.03014;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 1.02578;
      else if ( eta < 0.0 ) return 0.98096;
      else if ( eta < 0.8 ) return 0.99616;
      else if ( eta < 1.444 ) return 1.04392;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 1.02486;
      else return 1.06473; }
    else if ( pt < 35.0 ) {
      if ( eta < -2.0 ) return 1.00735;
      else if ( eta < -1.566 ) return 0.98737;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.97968;
      else if ( eta < 0.0 ) return 0.97034;
      else if ( eta < 0.8 ) return 0.98737;
      else if ( eta < 1.444 ) return 0.99307;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.97742;
      else return 1.00597; }
    else if ( pt < 50.0 ) {
      if ( eta < -2.0 ) return 0.99868;
      else if ( eta < -1.566 ) return 0.98797;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.98190;
      else if ( eta < 0.0 ) return 0.96992;
      else if ( eta < 0.8 ) return 0.97926;
      else if ( eta < 1.444 ) return 0.98768;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.98685;
      else return 0.99863; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 1.00592;
      else if ( eta < -1.566 ) return 0.99238;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.98291;
      else if ( eta < 0.0 ) return 0.97403;
      else if ( eta < 0.8 ) return 0.98670;
      else if ( eta < 1.444 ) return 0.98754;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.99573;
      else return 1.00353; }
    else {
      if ( eta < -2.0 ) return 1.04034;
      else if ( eta < -1.566 ) return 1.01202;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 1.00176;
      else if ( eta < 0.0 ) return 0.98247;
      else if ( eta < 0.8 ) return 0.99834;
      else if ( eta < 1.444 ) return 1.00524;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.99685;
      else return 1.02679; }
  }
  else if ( shift == "down" ){
    if ( pt < 20.0 ) {
      if ( eta < -2.0 ) return 1.00720;
      else if ( eta < -1.566 ) return 0.99358;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.97928;
      else if ( eta < 0.0 ) return 0.92937;
      else if ( eta < 0.8 ) return 0.94458;
      else if ( eta < 1.444 ) return 0.99726;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.98830;
      else return 1.03262; }
    else if ( pt < 35.0 ) {
      if ( eta < -2.0 ) return 0.98000;
      else if ( eta < -1.566 ) return 0.96554;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.95905;
      else if ( eta < 0.0 ) return 0.95042;
      else if ( eta < 0.8 ) return 0.96745;
      else if ( eta < 1.444 ) return 0.97244;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.95559;
      else return 0.97862; }
    else if ( pt < 50.0 ) {
      if ( eta < -2.0 ) return 0.99183;
      else if ( eta < -1.566 ) return 0.98197;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.97648;
      else if ( eta < 0.0 ) return 0.96379;
      else if ( eta < 0.8 ) return 0.97313;
      else if ( eta < 1.444 ) return 0.98226;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.98085;
      else return 0.99178; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.98939;
      else if ( eta < -1.566 ) return 0.98751;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.97805;
      else if ( eta < 0.0 ) return 0.95559;
      else if ( eta < 0.8 ) return 0.96826;
      else if ( eta < 1.444 ) return 0.98268;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.99085;
      else return 0.98700; }
    else {
      if ( eta < -2.0 ) return 0.98882;
      else if ( eta < -1.566 ) return 0.99235;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.98214;
      else if ( eta < 0.0 ) return 0.96764;
      else if ( eta < 0.8 ) return 0.98350;
      else if ( eta < 1.444 ) return 0.98562;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.97718;
      else return 0.97559; }
  }
  else {
    if ( pt < 20.0 ) {
      if ( eta < -2.0 ) return 1.02326;
      else if ( eta < -1.566 ) return 1.01186;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 1.00253;
      else if ( eta < 0.0 ) return 0.95517;
      else if ( eta < 0.8 ) return 0.97037;
      else if ( eta < 1.444 ) return 1.02059;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 1.00658;
      else return 1.04868; }
    else if ( pt < 35.0 ) {
      if ( eta < -2.0 ) return 0.99368;
      else if ( eta < -1.566 ) return 0.97646;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.96936;
      else if ( eta < 0.0 ) return 0.96038;
      else if ( eta < 0.8 ) return 0.97741;
      else if ( eta < 1.444 ) return 0.98276;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.96650;
      else return 0.99230; }
    else if ( pt < 50.0 ) {
      if ( eta < -2.0 ) return 0.99526;
      else if ( eta < -1.566 ) return 0.98497;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.97919;
      else if ( eta < 0.0 ) return 0.96686;
      else if ( eta < 0.8 ) return 0.97619;
      else if ( eta < 1.444 ) return 0.98497;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.98385;
      else return 0.99520; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.99766;
      else if ( eta < -1.566 ) return 0.98994;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.98048;
      else if ( eta < 0.0 ) return 0.96481;
      else if ( eta < 0.8 ) return 0.97748;
      else if ( eta < 1.444 ) return 0.98511;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.99329;
      else return 0.99527; }
    else {
      if ( eta < -2.0 ) return 1.01458;
      else if ( eta < -1.566 ) return 1.00219;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.99195;
      else if ( eta < 0.0 ) return 0.97506;
      else if ( eta < 0.8 ) return 0.99092;
      else if ( eta < 1.444 ) return 0.99543;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.98701;
      else return 1.00119; }
  }
}

double HardcodedConditions::GetElectronIdSF2016(double pt, double eta, std::string shift){
  if ( shift == "up" ){
    if ( pt < 20.0 ) {
      if ( eta < -2.0 ) return 1.03625;
      else if ( eta < -1.566 ) return 1.01368;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.99967;
      else if ( eta < 0.0 ) return 0.99005;
      else if ( eta < 0.8 ) return 0.99139;
      else if ( eta < 1.444 ) return 1.00203;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 1.00742;
      else return 1.00058; }
    else if ( pt < 35.0 ) {
      if ( eta < -2.0 ) return 1.00685;
      else if ( eta < -1.566 ) return 0.96413;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.97355;
      else if ( eta < 0.0 ) return 0.98007;
      else if ( eta < 0.8 ) return 0.99875;
      else if ( eta < 1.444 ) return 0.97597;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.95363;
      else return 0.96940; }
    else if ( pt < 50.0 ) {
      if ( eta < -2.0 ) return 1.00325;
      else if ( eta < -1.566 ) return 0.97073;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.97275;
      else if ( eta < 0.0 ) return 0.98087;
      else if ( eta < 0.8 ) return 0.99530;
      else if ( eta < 1.444 ) return 0.98063;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.96422;
      else return 0.97145; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 1.00405;
      else if ( eta < -1.566 ) return 0.98522;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.98331;
      else if ( eta < 0.0 ) return 0.98783;
      else if ( eta < 0.8 ) return 1.00216;
      else if ( eta < 1.444 ) return 0.99338;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.97333;
      else return 0.98419; }
    else {
      if ( eta < -2.0 ) return 1.09534;
      else if ( eta < -1.566 ) return 1.01827;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 1.03312;
      else if ( eta < 0.0 ) return 1.01027;
      else if ( eta < 0.8 ) return 1.02250;
      else if ( eta < 1.444 ) return 1.01039;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 1.00083;
      else return 1.03101; }
  }
  else if ( shift == "down" ){
    if ( pt < 20.0 ) {
      if ( eta < -2.0 ) return 1.00548;
      else if ( eta < -1.566 ) return 0.95786;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.96259;
      else if ( eta < 0.0 ) return 0.95616;
      else if ( eta < 0.8 ) return 0.95751;
      else if ( eta < 1.444 ) return 0.96531;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.95160;
      else return 0.96981; }
    else if ( pt < 35.0 ) {
      if ( eta < -2.0 ) return 0.98033;
      else if ( eta < -1.566 ) return 0.94307;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.95148;
      else if ( eta < 0.0 ) return 0.95904;
      else if ( eta < 0.8 ) return 0.97772;
      else if ( eta < 1.444 ) return 0.95390;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.93257;
      else return 0.94288; }
    else if ( pt < 50.0 ) {
      if ( eta < -2.0 ) return 0.99675;
      else if ( eta < -1.566 ) return 0.96527;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.96582;
      else if ( eta < 0.0 ) return 0.97454;
      else if ( eta < 0.8 ) return 0.98897;
      else if ( eta < 1.444 ) return 0.97370;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.95877;
      else return 0.96494; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.99123;
      else if ( eta < -1.566 ) return 0.97708;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.96032;
      else if ( eta < 0.0 ) return 0.97235;
      else if ( eta < 0.8 ) return 0.98668;
      else if ( eta < 1.444 ) return 0.97038;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.96499;
      else return 0.97137; }
    else {
      if ( eta < -2.0 ) return 1.04267;
      else if ( eta < -1.566 ) return 0.98826;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 1.01234;
      else if ( eta < 0.0 ) return 0.99639;
      else if ( eta < 0.8 ) return 1.00903;
      else if ( eta < 1.444 ) return 0.98961;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.97112;
      else return 0.97829; }
  }
  else {
    if ( pt < 20.0 ) {
      if ( eta < -2.0 ) return 1.02086;
      else if ( eta < -1.566 ) return 0.98577;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.98113;
      else if ( eta < 0.0 ) return 0.97311;
      else if ( eta < 0.8 ) return 0.97445;
      else if ( eta < 1.444 ) return 0.98367;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.97951;
      else return 0.98520; }
    else if ( pt < 35.0 ) {
      if ( eta < -2.0 ) return 0.99359;
      else if ( eta < -1.566 ) return 0.95360;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.96252;
      else if ( eta < 0.0 ) return 0.96956;
      else if ( eta < 0.8 ) return 0.98824;
      else if ( eta < 1.444 ) return 0.96493;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.94310;
      else return 0.95614; }
    else if ( pt < 50.0 ) {
      if ( eta < -2.0 ) return 1.00000;
      else if ( eta < -1.566 ) return 0.96800;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.96928;
      else if ( eta < 0.0 ) return 0.97770;
      else if ( eta < 0.8 ) return 0.99213;
      else if ( eta < 1.444 ) return 0.97717;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.96149;
      else return 0.96820; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.99764;
      else if ( eta < -1.566 ) return 0.98115;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.97182;
      else if ( eta < 0.0 ) return 0.98009;
      else if ( eta < 0.8 ) return 0.99442;
      else if ( eta < 1.444 ) return 0.98188;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.96916;
      else return 0.97778; }
    else {
      if ( eta < -2.0 ) return 1.06901;
      else if ( eta < -1.566 ) return 1.00327;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 1.02273;
      else if ( eta < 0.0 ) return 1.00333;
      else if ( eta < 0.8 ) return 1.01577;
      else if ( eta < 1.444 ) return 1.00000;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.98598;
      else return 1.00465; }
  }
}
		
double HardcodedConditions::GetElectronIdSF2017(double pt, double eta, std::string shift){
  if ( shift == "up" ){
    if ( pt < 20.0 ) {
      if ( eta < -2.0 ) return 1.00931;
      else if ( eta < -1.566 ) return 0.99385;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 1.00553;
      else if ( eta < 0.0 ) return 0.99899;
      else if ( eta < 0.8 ) return 0.99544;
      else if ( eta < 1.444 ) return 1.00908;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.99023;
      else return 1.02070; }
    else if ( pt < 35.0 ) {
      if ( eta < -2.0 ) return 0.96935;
      else if ( eta < -1.566 ) return 0.94691;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.97658;
      else if ( eta < 0.0 ) return 0.97682;
      else if ( eta < 0.8 ) return 0.98051;
      else if ( eta < 1.444 ) return 0.98088;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.94988;
      else return 0.97022; }
    else if ( pt < 50.0 ) {
      if ( eta < -2.0 ) return 0.97576;
      else if ( eta < -1.566 ) return 0.97168;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.97744;
      else if ( eta < 0.0 ) return 0.97893;
      else if ( eta < 0.8 ) return 0.98123;
      else if ( eta < 1.444 ) return 0.97957;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.97375;
      else return 0.97123; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.97794;
      else if ( eta < -1.566 ) return 0.98089;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.97815;
      else if ( eta < 0.0 ) return 0.97745;
      else if ( eta < 0.8 ) return 0.97970;
      else if ( eta < 1.444 ) return 0.98242;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.98708;
      else return 0.97998; }
    else {
      if ( eta < -2.0 ) return 0.99712;
      else if ( eta < -1.566 ) return 0.99564;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 1.01283;
      else if ( eta < 0.0 ) return 0.99310;
      else if ( eta < 0.8 ) return 0.99852;
      else if ( eta < 1.444 ) return 0.99318;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.99253;
      else return 1.00726; }
  }
  else if ( shift == "down" ){
    if ( pt < 20.0 ) {
      if ( eta < -2.0 ) return 0.98071;
      else if ( eta < -1.566 ) return 0.92868;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.96764;
      else if ( eta < 0.0 ) return 0.96155;
      else if ( eta < 0.8 ) return 0.95799;
      else if ( eta < 1.444 ) return 0.97109;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.92506;
      else return 0.99186; }
    else if ( pt < 35.0 ) {
      if ( eta < -2.0 ) return 0.94760;
      else if ( eta < -1.566 ) return 0.93492;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.95357;
      else if ( eta < 0.0 ) return 0.95806;
      else if ( eta < 0.8 ) return 0.96175;
      else if ( eta < 1.444 ) return 0.95787;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.93789;
      else return 0.94848; }
    else if ( pt < 50.0 ) {
      if ( eta < -2.0 ) return 0.96935;
      else if ( eta < -1.566 ) return 0.96428;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.97168;
      else if ( eta < 0.0 ) return 0.97261;
      else if ( eta < 0.8 ) return 0.97491;
      else if ( eta < 1.444 ) return 0.97381;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.96635;
      else return 0.96482; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.95909;
      else if ( eta < -1.566 ) return 0.97294;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.96726;
      else if ( eta < 0.0 ) return 0.97260;
      else if ( eta < 0.8 ) return 0.97485;
      else if ( eta < 1.444 ) return 0.97153;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.97913;
      else return 0.96113; }
    else {
      if ( eta < -2.0 ) return 0.95642;
      else if ( eta < -1.566 ) return 0.96291;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.99379;
      else if ( eta < 0.0 ) return 0.97873;
      else if ( eta < 0.8 ) return 0.98416;
      else if ( eta < 1.444 ) return 0.97414;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.95980;
      else return 0.96601; }
  }
  else {
    if ( pt < 20.0 ) {
      if ( eta < -2.0 ) return 0.99501;
      else if ( eta < -1.566 ) return 0.96127;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.98659;
      else if ( eta < 0.0 ) return 0.98027;
      else if ( eta < 0.8 ) return 0.97672;
      else if ( eta < 1.444 ) return 0.99009;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.95765;
      else return 1.00628; }
    else if ( pt < 35.0 ) {
      if ( eta < -2.0 ) return 0.95848;
      else if ( eta < -1.566 ) return 0.94091;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.96508;
      else if ( eta < 0.0 ) return 0.96744;
      else if ( eta < 0.8 ) return 0.97113;
      else if ( eta < 1.444 ) return 0.96938;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.94388;
      else return 0.95935; }
    else if ( pt < 50.0 ) {
      if ( eta < -2.0 ) return 0.97256;
      else if ( eta < -1.566 ) return 0.96798;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.97456;
      else if ( eta < 0.0 ) return 0.97577;
      else if ( eta < 0.8 ) return 0.97807;
      else if ( eta < 1.444 ) return 0.97669;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.97005;
      else return 0.96803; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.96851;
      else if ( eta < -1.566 ) return 0.97692;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.97271;
      else if ( eta < 0.0 ) return 0.97503;
      else if ( eta < 0.8 ) return 0.97727;
      else if ( eta < 1.444 ) return 0.97697;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.98310;
      else return 0.97056; }
    else {
      if ( eta < -2.0 ) return 0.97677;
      else if ( eta < -1.566 ) return 0.97927;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 1.00331;
      else if ( eta < 0.0 ) return 0.98592;
      else if ( eta < 0.8 ) return 0.99134;
      else if ( eta < 1.444 ) return 0.98366;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.97617;
      else return 0.98664; }
  }
}

double HardcodedConditions::GetElectronIdSF2018(double pt, double eta, std::string shift){
  if ( shift == "up" ){
    if ( pt < 20.0 ) {
      if ( eta < -2.0 ) return 1.00699;
      else if ( eta < -1.566 ) return 0.98947;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 1.00533;
      else if ( eta < 0.0 ) return 0.97441;
      else if ( eta < 0.8 ) return 0.99214;
      else if ( eta < 1.444 ) return 1.00523;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.99996;
      else return 0.97890; }
    else if ( pt < 35.0 ) {
      if ( eta < -2.0 ) return 0.97178;
      else if ( eta < -1.566 ) return 0.95986;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.95613;
      else if ( eta < 0.0 ) return 0.97431;
      else if ( eta < 0.8 ) return 0.98137;
      else if ( eta < 1.444 ) return 0.95808;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.95399;
      else return 0.95758; }
    else if ( pt < 50.0 ) {
      if ( eta < -2.0 ) return 0.97576;
      else if ( eta < -1.566 ) return 0.96937;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.97052;
      else if ( eta < 0.0 ) return 0.97480;
      else if ( eta < 0.8 ) return 0.97808;
      else if ( eta < 1.444 ) return 0.97142;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.96721;
      else return 0.96463; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.97502;
      else if ( eta < -1.566 ) return 0.97700;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.97512;
      else if ( eta < 0.0 ) return 0.97959;
      else if ( eta < 0.8 ) return 0.98065;
      else if ( eta < 1.444 ) return 0.97494;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.97386;
      else return 0.96724; }
    else {
      if ( eta < -2.0 ) return 1.01362;
      else if ( eta < -1.566 ) return 0.99927;
      else if ( eta < -1.444 ) return 2.00000;
      else if ( eta < -0.8 ) return 0.99917;
      else if ( eta < 0.0 ) return 0.98729;
      else if ( eta < 0.8 ) return 0.99267;
      else if ( eta < 1.444 ) return 0.99585;
      else if ( eta < 1.566 ) return 2.00000;
      else if ( eta < 2.0 ) return 0.99192;
      else return 0.98137; }
  }
  else if ( shift == "down" ){
    if ( pt < 20.0 ) {
      if ( eta < -2.0 ) return 0.97255;
      else if ( eta < -1.566 ) return 0.95438;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.96217;
      else if ( eta < 0.0 ) return 0.95254;
      else if ( eta < 0.8 ) return 0.97027;
      else if ( eta < 1.444 ) return 0.96207;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.96487;
      else return 0.94447; }
    else if ( pt < 35.0 ) {
      if ( eta < -2.0 ) return 0.94654;
      else if ( eta < -1.566 ) return 0.94014;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.94563;
      else if ( eta < 0.0 ) return 0.95576;
      else if ( eta < 0.8 ) return 0.96282;
      else if ( eta < 1.444 ) return 0.94758;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.93428;
      else return 0.93235; }
    else if ( pt < 50.0 ) {
      if ( eta < -2.0 ) return 0.96924;
      else if ( eta < -1.566 ) return 0.96474;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.96532;
      else if ( eta < 0.0 ) return 0.97013;
      else if ( eta < 0.8 ) return 0.97341;
      else if ( eta < 1.444 ) return 0.96622;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.96258;
      else return 0.95811; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.96615;
      else if ( eta < -1.566 ) return 0.97268;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.96136;
      else if ( eta < 0.0 ) return 0.96818;
      else if ( eta < 0.8 ) return 0.96924;
      else if ( eta < 1.444 ) return 0.96118;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.96954;
      else return 0.95837; }
    else {
      if ( eta < -2.0 ) return 0.98192;
      else if ( eta < -1.566 ) return 0.98398;
      else if ( eta < -1.444 ) return 0.00000;
      else if ( eta < -0.8 ) return 0.98334;
      else if ( eta < 0.0 ) return 0.97391;
      else if ( eta < 0.8 ) return 0.97929;
      else if ( eta < 1.444 ) return 0.98003;
      else if ( eta < 1.566 ) return 0.00000;
      else if ( eta < 2.0 ) return 0.97663;
      else return 0.94989; }
  }
  else {
    if ( pt < 20.0 ) {
      if ( eta < -2.0 ) return 0.98977;
      else if ( eta < -1.566 ) return 0.97193;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.98375;
      else if ( eta < 0.0 ) return 0.96348;
      else if ( eta < 0.8 ) return 0.98120;
      else if ( eta < 1.444 ) return 0.98365;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.98242;
      else return 0.96169; }
    else if ( pt < 35.0 ) {
      if ( eta < -2.0 ) return 0.95916;
      else if ( eta < -1.566 ) return 0.95000;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.95088;
      else if ( eta < 0.0 ) return 0.96503;
      else if ( eta < 0.8 ) return 0.97209;
      else if ( eta < 1.444 ) return 0.95283;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.94413;
      else return 0.94496; }
    else if ( pt < 50.0 ) {
      if ( eta < -2.0 ) return 0.97250;
      else if ( eta < -1.566 ) return 0.96706;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.96792;
      else if ( eta < 0.0 ) return 0.97247;
      else if ( eta < 0.8 ) return 0.97574;
      else if ( eta < 1.444 ) return 0.96882;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.96489;
      else return 0.96137; }
    else if ( pt < 100.0 ) {
      if ( eta < -2.0 ) return 0.97059;
      else if ( eta < -1.566 ) return 0.97484;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.96824;
      else if ( eta < 0.0 ) return 0.97388;
      else if ( eta < 0.8 ) return 0.97495;
      else if ( eta < 1.444 ) return 0.96806;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.97170;
      else return 0.96280; }
    else {
      if ( eta < -2.0 ) return 0.99777;
      else if ( eta < -1.566 ) return 0.99162;
      else if ( eta < -1.444 ) return 1.00000;
      else if ( eta < -0.8 ) return 0.99126;
      else if ( eta < 0.0 ) return 0.98060;
      else if ( eta < 0.8 ) return 0.98598;
      else if ( eta < 1.444 ) return 0.98794;
      else if ( eta < 1.566 ) return 1.00000;
      else if ( eta < 2.0 ) return 0.98428;
      else return 0.96563; }
  }
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|          ELECTRON ISO SCALE FACTOR SECTION          |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

// miniIsolation SF calculated using EGamma TnP
double HardcodedConditions::GetElectronIsoSF(double pt, double eta, std::string year)
{
  //The main getter for Electron Iso Scale Factors
  if      (year=="2016APV") return GetElectronIsoSF2016APV(pt, eta);
  else if (year=="2016") return GetElectronIsoSF2016(pt, eta);
  else if (year=="2017") return GetElectronIsoSF2017(pt, eta);
  else if (year=="2018") return GetElectronIsoSF2018(pt, eta);
  else return 0.;
}

double HardcodedConditions::GetElectronIsoSF2016APV(double pt, double eta){
  if( pt < 20 ){
    if( eta < -2.0 ) return 1.016;
    else if( eta < -1.5660 ) return 1.024;
    else if( eta < -1.4442 ) return 1.046;
    else if( eta < -0.8000 ) return 1.005;
    else if( eta <  0.0000 ) return 0.997;
    else if( eta <  0.8000 ) return 0.999;
    else if( eta <  1.4442 ) return 1.016;
    else if( eta <  1.5660 ) return 1.093;
    else if( eta <  2.0000 ) return 1.019;
    else return 1.023;
  }
  else if( pt < 35 ){
    if( eta < -2.0 ) return 1.013;
    else if( eta < -1.5660 ) return 1.010;
    else if( eta < -1.4442 ) return 1.063;
    else if( eta < -0.8000 ) return 1.004;
    else if( eta <  0.0000 ) return 1.001;
    else if( eta <  0.8000 ) return 1.003;
    else if( eta <  1.4442 ) return 1.005;
    else if( eta <  1.5660 ) return 1.058;
    else if( eta <  2.0000 ) return 1.011;
    else return 1.010;
  }
  else if( pt < 50 ){
    if( eta < -2.0 ) return 1.005;
    else if( eta < -1.5660 ) return 1.003;
    else if( eta < -1.4442 ) return 1.013;
    else if( eta < -0.8000 ) return 1.001;
    else if( eta <  0.0000 ) return 0.998;
    else if( eta <  0.8000 ) return 1.000;
    else if( eta <  1.4442 ) return 1.000;
    else if( eta <  1.5660 ) return 1.008;
    else if( eta <  2.0000 ) return 1.002;
    else return 1.004;
  }
  else if( pt < 100 ){
    if( eta < -2.0 ) return 1.002;
    else if( eta < -1.5660 ) return 1.001;
    else if( eta < -1.4442 ) return 1.013;
    else if( eta < -0.8000 ) return 1.001;
    else if( eta <  0.0000 ) return 0.999;
    else if( eta <  0.8000 ) return 1.000;
    else if( eta <  1.4442 ) return 0.999;
    else if( eta <  1.5660 ) return 1.002;
    else if( eta <  2.0000 ) return 1.001;
    else return 1.004;
  }
  else if( pt < 200 ){
    if( eta < -2.0 ) return 1.002;
    else if( eta < -1.5660 ) return 1.000;
    else if( eta < -1.4442 ) return 1.018;
    else if( eta < -0.8000 ) return 1.000;
    else if( eta <  0.0000 ) return 1.000;
    else if( eta <  0.8000 ) return 1.000;
    else if( eta <  1.4442 ) return 1.000;
    else if( eta <  1.5660 ) return 1.028;
    else if( eta <  2.0000 ) return 1.000;
    else return 0.999;
  }
  else {
    if( eta < -2.0 ) return 0.993;
    else if( eta < -1.5660 ) return 0.998;
    else if( eta < -1.4442 ) return 0.989;
    else if( eta < -0.8000 ) return 1.004;
    else if( eta <  0.0000 ) return 0.999;
    else if( eta <  0.8000 ) return 1.004;
    else if( eta <  1.4442 ) return 1.005;
    else if( eta <  1.5660 ) return 1.027;
    else if( eta <  2.0000 ) return 0.993;
    else return 0.994;
  }
}

double HardcodedConditions::GetElectronIsoSF2016(double pt, double eta){
  if( pt < 20 ){
    if( eta < -2.0 ) return 1.008;
    else if( eta < -1.5660 ) return 1.006;
    else if( eta < -1.4442 ) return 1.074;
    else if( eta < -0.8000 ) return 0.993;
    else if( eta <  0.0000 ) return 0.982;
    else if( eta <  0.8000 ) return 0.990;
    else if( eta <  1.4442 ) return 0.992;
    else if( eta <  1.5660 ) return 0.999;
    else if( eta <  2.0000 ) return 1.008;
    else return 1.015;
  }
  else if( pt < 35 ){
    if( eta < -2.0 ) return 1.008;
    else if( eta < -1.5660 ) return 1.006; 
    else if( eta < -1.4442 ) return 1.054;
    else if( eta < -0.8000 ) return 1.001;
    else if( eta <  0.0000 ) return 0.997;
    else if( eta <  0.8000 ) return 0.997;
    else if( eta <  1.4442 ) return 1.001;
    else if( eta <  1.5660 ) return 1.045;
    else if( eta <  2.0000 ) return 1.007;
    else return 1.007;
  }
  else if( pt < 50 ){
    if( eta < -2.0 ) return 1.003;
    else if( eta < -1.5660 ) return 1.003; 
    else if( eta < -1.4442 ) return 1.020;
    else if( eta < -0.8000 ) return 1.000;
    else if( eta <  0.0000 ) return 0.997;
    else if( eta <  0.8000 ) return 0.998;
    else if( eta <  1.4442 ) return 1.000;
    else if( eta <  1.5660 ) return 1.010;
    else if( eta <  2.0000 ) return 1.002;
    else return 1.002;
  }
  else if( pt < 100 ){
    if( eta < -2.0 ) return 1.001;
    else if( eta < -1.5660 ) return 1.002; 
    else if( eta < -1.4442 ) return 1.021;
    else if( eta < -0.8000 ) return 0.999;
    else if( eta <  0.0000 ) return 0.998;
    else if( eta <  0.8000 ) return 0.999;
    else if( eta <  1.4442 ) return 1.000;
    else if( eta <  1.5660 ) return 1.007;
    else if( eta <  2.0000 ) return 1.000;
    else return 1.002;
  }
  else if( pt < 200 ){
    if( eta < -2.0 ) return 1.000;
    else if( eta < -1.5660 ) return 1.002; 
    else if( eta < -1.4442 ) return 0.984;
    else if( eta < -0.8000 ) return 0.999;
    else if( eta <  0.0000 ) return 1.002;
    else if( eta <  0.8000 ) return 0.996;
    else if( eta <  1.4442 ) return 1.000;
    else if( eta <  1.5660 ) return 1.025;
    else if( eta <  2.0000 ) return 0.999;
    else return 1.000;
  }
  else {
    if( eta < -2.0 ) return 0.991;
    else if( eta < -1.5660 ) return 0.998; 
    else if( eta < -1.4442 ) return 0.990;
    else if( eta < -0.8000 ) return 0.996;
    else if( eta <  0.0000 ) return 0.998;
    else if( eta <  0.8000 ) return 0.999;
    else if( eta <  1.4442 ) return 1.000;
    else if( eta <  1.5660 ) return 0.991;
    else if( eta <  2.0000 ) return 0.997;
    else return 0.989;
  }
}

double HardcodedConditions::GetElectronIsoSF2017(double pt, double eta){
  if( pt < 20 ){
    if( eta < -2.0 ) return 1.015;
    else if( eta < -1.5660 ) return 1.021;
    else if( eta < -1.4442 ) return 1.031;
    else if( eta < -0.8000 ) return 1.006;
    else if( eta <  0.0000 ) return 0.998;
    else if( eta <  0.8000 ) return 1.000;
    else if( eta <  1.4442 ) return 1.013;
    else if( eta <  1.5660 ) return 0.951;
    else if( eta <  2.0000 ) return 1.005;
    else return 1.028;
  }
  else if( pt < 35 ){
    if( eta < -2.0 ) return 1.012;
    else if( eta < -1.5660 ) return 1.011;
    else if( eta < -1.4442 ) return 1.033;
    else if( eta < -0.8000 ) return 1.004;
    else if( eta <  0.0000 ) return 0.998;
    else if( eta <  0.8000 ) return 1.002;
    else if( eta <  1.4442 ) return 1.004;
    else if( eta <  1.5660 ) return 1.033;
    else if( eta <  2.0000 ) return 1.007;
    else return 1.014;
  }
  else if( pt < 50 ){
    if( eta < -2.0 ) return 1.004;
    else if( eta < -1.5660 ) return 1.004;
    else if( eta < -1.4442 ) return 1.012;
    else if( eta < -0.8000 ) return 1.000;
    else if( eta <  0.0000 ) return 0.999;
    else if( eta <  0.8000 ) return 1.001;
    else if( eta <  1.4442 ) return 1.001;
    else if( eta <  1.5660 ) return 1.009;
    else if( eta <  2.0000 ) return 1.003;
    else return 1.006;
  }
  else if( pt < 100 ){
    if( eta < -2.0 ) return 1.002;
    else if( eta < -1.5660 ) return 1.003;
    else if( eta < -1.4442 ) return 1.011;
    else if( eta < -0.8000 ) return 0.999;
    else if( eta <  0.0000 ) return 0.998;
    else if( eta <  0.8000 ) return 1.002;
    else if( eta <  1.4442 ) return 1.000;
    else if( eta <  1.5660 ) return 1.014;
    else if( eta <  2.0000 ) return 1.000;
    else return 1.003;
  }
  else if( pt < 200 ){
    if( eta < -2.0 ) return 1.002;
    else if( eta < -1.5660 ) return 1.000;
    else if( eta < -1.4442 ) return 1.008;
    else if( eta < -0.8000 ) return 1.001;
    else if( eta <  0.0000 ) return 1.004;
    else if( eta <  0.8000 ) return 1.005;
    else if( eta <  1.4442 ) return 1.003;
    else if( eta <  1.5660 ) return 1.018;
    else if( eta <  2.0000 ) return 0.999;
    else return 1.001;
  }
  else {
    if( eta < -2.0 ) return 0.998;
    else if( eta < -1.5660 ) return 1.003;
    else if( eta < -1.4442 ) return 1.014;
    else if( eta < -0.8000 ) return 1.005;
    else if( eta <  0.0000 ) return 1.002;
    else if( eta <  0.8000 ) return 1.000;
    else if( eta <  1.4442 ) return 1.001;
    else if( eta <  1.5660 ) return 0.986;
    else if( eta <  2.0000 ) return 0.999;
    else return 1.009;
  }
}

double HardcodedConditions::GetElectronIsoSF2018(double pt, double eta){
  if( pt < 20 ){
    if( eta < -2.0 ) return 0.998;
    else if( eta < -1.5660 ) return 1.021;
    else if( eta < -1.4442 ) return 1.073;
    else if( eta < -0.8000 ) return 0.987;
    else if( eta <  0.0000 ) return 0.993;
    else if( eta <  0.8000 ) return 0.997;
    else if( eta <  1.4442 ) return 0.992;
    else if( eta <  1.5660 ) return 1.036;
    else if( eta <  2.0000 ) return 1.009;
    else return 1.009;
  }
  else if( pt < 35 ){
    if( eta < -2.0 ) return 1.003;
    else if( eta < -1.5660 ) return 1.005;
    else if( eta < -1.4442 ) return 1.052;
    else if( eta < -0.8000 ) return 0.997;
    else if( eta <  0.0000 ) return 0.998;
    else if( eta <  0.8000 ) return 1.000;
    else if( eta <  1.4442 ) return 0.997;
    else if( eta <  1.5660 ) return 1.048;
    else if( eta <  2.0000 ) return 1.005;
    else return 1.002;
  }
  else if( pt < 50 ){
    if( eta < -2.0 ) return 1.001;
    else if( eta < -1.5660 ) return 1.002;
    else if( eta < -1.4442 ) return 1.031;
    else if( eta < -0.8000 ) return 0.997;
    else if( eta <  0.0000 ) return 0.998;
    else if( eta <  0.8000 ) return 0.999;
    else if( eta <  1.4442 ) return 0.998;
    else if( eta <  1.5660 ) return 1.023;
    else if( eta <  2.0000 ) return 1.001;
    else return 1.001;
  }
  else if( pt < 100 ){
    if( eta < -2.0 ) return 1.003;
    else if( eta < -1.5660 ) return 1.000;
    else if( eta < -1.4442 ) return 1.047;
    else if( eta < -0.8000 ) return 0.998;
    else if( eta <  0.0000 ) return 0.999;
    else if( eta <  0.8000 ) return 0.999;
    else if( eta <  1.4442 ) return 0.998;
    else if( eta <  1.5660 ) return 1.035;
    else if( eta <  2.0000 ) return 1.000;
    else return 1.001;
  }
  else if( pt < 200 ){
    if( eta < -2.0 ) return 1.000;
    else if( eta < -1.5660 ) return 1.000;
    else if( eta < -1.4442 ) return 1.013;
    else if( eta < -0.8000 ) return 1.000;
    else if( eta <  0.0000 ) return 1.001;
    else if( eta <  0.8000 ) return 1.001;
    else if( eta <  1.4442 ) return 1.000;
    else if( eta <  1.5660 ) return 0.996;
    else if( eta <  2.0000 ) return 0.999;
    else return 1.002;
  }
  else {
    if( eta < -2.0 ) return 0.997;
    else if( eta < -1.5660 ) return 1.004;
    else if( eta < -1.4442 ) return 1.011;
    else if( eta < -0.8000 ) return 0.998;
    else if( eta <  0.0000 ) return 0.998;
    else if( eta <  0.8000 ) return 1.002;
    else if( eta <  1.4442 ) return 1.003;
    else if( eta <  1.5660 ) return 1.016;
    else if( eta <  2.0000 ) return 1.000;
    else return 0.996;
  }
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|        ELECTRON TRIGGER SCALE FACTOR SECTION        |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetElectronTriggerSF(double pt, double eta, std::string year)
{
  //The main getter for Electron Trigger Scale Factors
  if      (year=="2016APV") return GetElectronTriggerSF2016APV(pt, eta);
  else if (year=="2016") return GetElectronTriggerSF2016(pt, eta);
  else if (year=="2017") return GetElectronTriggerSF2017(pt, eta);
  else if (year=="2018") return GetElectronTriggerSF2018(pt, eta);
  else return 1.0;
}//end GetElectronTriggerSF

// using cut-and-count method from triggerX/triggerX_SF.py for 2016APV
// https://github.com/TopBrussels/TopTreeAnalysisBase/blob/CMSSW_80X/Calibrations/LeptonSF/ElectronSF/SF_HLT_Ele32_eta2p1.root
double HardcodedConditions::GetElectronTriggerSF2016APV(double pt, double eta){
  if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.58314;
    else if ( fabs(eta) < 1.4442 ) return 2.06786;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.01020;
    else return 0.38932; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.19383;
    else if ( fabs(eta) < 1.4442 ) return 1.12618;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.95816;
    else return 0.78417; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.23217;
    else if ( fabs(eta) < 1.4442 ) return 1.14523;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.04984;
    else return 0.81113; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.24198;
    else if ( fabs(eta) < 1.4442 ) return 1.17750;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.99915;
    else return 0.82839; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.21713;
    else if ( fabs(eta) < 1.4442 ) return 1.15302;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97647;
    else return 0.90637; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.22371;
    else if ( fabs(eta) < 1.4442 ) return 1.15888;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.96555;
    else return 0.91517; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.20704;
    else if ( fabs(eta) < 1.4442 ) return 1.14614;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.88450;
    else return 0.83138; }
  else {
    if ( fabs(eta) < 0.8000 ) return 1.18790;
    else if ( fabs(eta) < 1.4442 ) return 1.10756;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.77335;
    else return 0.62373; }  
}

// using EOY SF for HLT_ele32_eta2p1_WPTight_Gsf_v* approved by KIT for Run 2016
// https://github.com/TopBrussels/TopTreeAnalysisBase/blob/CMSSW_80X/Calibrations/LeptonSF/ElectronSF/SF_HLT_Ele32_eta2p1.root
double HardcodedConditions::GetElectronTriggerSF2016(double pt, double eta){
  double triggerSFHLT;
  if (eta < -1.8){
    if     (pt < 32 ){triggerSFHLT = 0.394531250000;}
    else if(pt < 34 ){triggerSFHLT = 0.721804499626;}
    else if(pt < 36 ){triggerSFHLT = 0.914093971252;}
    else if(pt < 38 ){triggerSFHLT = 0.936031341553;}
    else if(pt < 40 ){triggerSFHLT = 0.942965805531;}
    else if(pt < 42 ){triggerSFHLT = 0.950310587883;}
    else if(pt < 44 ){triggerSFHLT = 0.948529422283;}
    else if(pt < 46 ){triggerSFHLT = 0.947051763535;}
    else if(pt < 48 ){triggerSFHLT = 0.945107400417;}
    else if(pt < 50 ){triggerSFHLT = 0.936018943787;}
    else if(pt < 52 ){triggerSFHLT = 0.961813867092;}
    else if(pt < 54 ){triggerSFHLT = 0.935483872890;}
    else if(pt < 56 ){triggerSFHLT = 0.940023064613;}
    else if(pt < 60 ){triggerSFHLT = 0.954171538353;}
    else if(pt < 65 ){triggerSFHLT = 0.968347012997;}
    else if(pt < 70 ){triggerSFHLT = 0.916943550110;}
    else if(pt < 80 ){triggerSFHLT = 0.928730487823;}
    else if(pt < 90 ){triggerSFHLT = 0.922222197056;}
    else if(pt < 100){triggerSFHLT = 0.925081431866;}
    else if(pt < 120){triggerSFHLT = 0.937701404095;}
    else if(pt < 200){triggerSFHLT = 0.939427316189;}
    else             {triggerSFHLT = 0.918580353260;}
  }
  else if (eta < -1.566){
    if     (pt < 32 ){triggerSFHLT = 0.687804877758;}
    else if(pt < 34 ){triggerSFHLT = 0.827639758587;}
    else if(pt < 36 ){triggerSFHLT = 0.916438341141;}
    else if(pt < 38 ){triggerSFHLT = 0.922470450401;}
    else if(pt < 40 ){triggerSFHLT = 0.919293820858;}
    else if(pt < 42 ){triggerSFHLT = 0.925558328629;}
    else if(pt < 44 ){triggerSFHLT = 0.927710831165;}
    else if(pt < 46 ){triggerSFHLT = 0.933253884315;}
    else if(pt < 48 ){triggerSFHLT = 0.949820816517;}
    else if(pt < 50 ){triggerSFHLT = 0.937278091908;}
    else if(pt < 52 ){triggerSFHLT = 0.942216992378;}
    else if(pt < 54 ){triggerSFHLT = 0.945497632027;}
    else if(pt < 56 ){triggerSFHLT = 0.932242989540;}
    else if(pt < 60 ){triggerSFHLT = 0.936562836170;}
    else if(pt < 65 ){triggerSFHLT = 0.908988773823;}
    else if(pt < 70 ){triggerSFHLT = 0.935972034931;}
    else if(pt < 80 ){triggerSFHLT = 0.937923252583;}
    else if(pt < 90 ){triggerSFHLT = 0.914939999580;}
    else if(pt < 100){triggerSFHLT = 0.908096253872;}
    else if(pt < 120){triggerSFHLT = 0.943584084511;}
    else if(pt < 200){triggerSFHLT = 0.925438582897;}
    else             {triggerSFHLT = 1.011376619339;}
  }
  else if (eta < -1.442){
    if     (pt < 32 ){triggerSFHLT = 0.971014499664;}
    else if(pt < 34 ){triggerSFHLT = 0.883445918560;}
    else if(pt < 36 ){triggerSFHLT = 0.929945051670;}
    else if(pt < 38 ){triggerSFHLT = 0.960422158241;}
    else if(pt < 40 ){triggerSFHLT = 0.970284223557;}
    else if(pt < 42 ){triggerSFHLT = 0.978616356850;}
    else if(pt < 44 ){triggerSFHLT = 0.980295538902;}
    else if(pt < 46 ){triggerSFHLT = 0.990255773067;}
    else if(pt < 48 ){triggerSFHLT = 0.964705884457;}
    else if(pt < 50 ){triggerSFHLT = 0.962352931499;}
    else if(pt < 52 ){triggerSFHLT = 0.965842187405;}
    else if(pt < 54 ){triggerSFHLT = 1.013496875763;}
    else if(pt < 56 ){triggerSFHLT = 0.995169103146;}
    else if(pt < 60 ){triggerSFHLT = 0.974820137024;}
    else if(pt < 65 ){triggerSFHLT = 0.995073914528;}
    else if(pt < 70 ){triggerSFHLT = 0.953917026520;}
    else if(pt < 80 ){triggerSFHLT = 1.048750042915;}
    else if(pt < 90 ){triggerSFHLT = 0.981351971626;}
    else if(pt < 100){triggerSFHLT = 0.998864948750;}
    else if(pt < 120){triggerSFHLT = 0.937290012836;}
    else if(pt < 200){triggerSFHLT = 0.970132768154;}
    else             {triggerSFHLT = 1.139416933060;}
  }
  else if (eta < -1.1){
    if     (pt < 32 ){triggerSFHLT = 0.525862097740;}
    else if(pt < 34 ){triggerSFHLT = 0.781931459904;}
    else if(pt < 36 ){triggerSFHLT = 0.919653892517;}
    else if(pt < 38 ){triggerSFHLT = 0.949519217014;}
    else if(pt < 40 ){triggerSFHLT = 0.956521749496;}
    else if(pt < 42 ){triggerSFHLT = 0.971131622791;}
    else if(pt < 44 ){triggerSFHLT = 0.976109206676;}
    else if(pt < 46 ){triggerSFHLT = 0.976510047913;}
    else if(pt < 48 ){triggerSFHLT = 0.982142865658;}
    else if(pt < 50 ){triggerSFHLT = 0.981153011322;}
    else if(pt < 52 ){triggerSFHLT = 0.979097902775;}
    else if(pt < 54 ){triggerSFHLT = 0.976112902164;}
    else if(pt < 56 ){triggerSFHLT = 0.976034879684;}
    else if(pt < 60 ){triggerSFHLT = 0.965665221214;}
    else if(pt < 65 ){triggerSFHLT = 0.974248945713;}
    else if(pt < 70 ){triggerSFHLT = 0.972310960293;}
    else if(pt < 80 ){triggerSFHLT = 0.972860097885;}
    else if(pt < 90 ){triggerSFHLT = 0.970164597034;}
    else if(pt < 100){triggerSFHLT = 0.984326004982;}
    else if(pt < 120){triggerSFHLT = 0.971428573132;}
    else if(pt < 200){triggerSFHLT = 0.985567033291;}
    else             {triggerSFHLT = 0.984504103661;}
  }
  else if (eta < -0.8){
    if     (pt < 32 ){triggerSFHLT = 0.752212405205;}
    else if(pt < 34 ){triggerSFHLT = 0.908309459686;}
    else if(pt < 36 ){triggerSFHLT = 0.981176495552;}
    else if(pt < 38 ){triggerSFHLT = 0.990794003010;}
    else if(pt < 40 ){triggerSFHLT = 0.996598660946;}
    else if(pt < 42 ){triggerSFHLT = 1.001122355461;}
    else if(pt < 44 ){triggerSFHLT = 1.004459261894;}
    else if(pt < 46 ){triggerSFHLT = 0.998896241188;}
    else if(pt < 48 ){triggerSFHLT = 1.000000000000;}
    else if(pt < 50 ){triggerSFHLT = 0.998911857605;}
    else if(pt < 52 ){triggerSFHLT = 0.993506491184;}
    else if(pt < 54 ){triggerSFHLT = 1.001086950302;}
    else if(pt < 56 ){triggerSFHLT = 0.994640946388;}
    else if(pt < 60 ){triggerSFHLT = 0.986199557781;}
    else if(pt < 65 ){triggerSFHLT = 0.990425527096;}
    else if(pt < 70 ){triggerSFHLT = 1.006417155266;}
    else if(pt < 80 ){triggerSFHLT = 0.979274630547;}
    else if(pt < 90 ){triggerSFHLT = 0.995833337307;}
    else if(pt < 100){triggerSFHLT = 1.006302475929;}
    else if(pt < 120){triggerSFHLT = 0.989680111408;}
    else if(pt < 200){triggerSFHLT = 0.978615045547;}
    else             {triggerSFHLT = 0.967578530312;}
  }
  else if (eta < -0.6){
    if     (pt < 32 ){triggerSFHLT = 0.981308400631;}
    else if(pt < 34 ){triggerSFHLT = 0.964589238167;}
    else if(pt < 36 ){triggerSFHLT = 1.007168412209;}
    else if(pt < 38 ){triggerSFHLT = 1.001162767410;}
    else if(pt < 40 ){triggerSFHLT = 1.015046238899;}
    else if(pt < 42 ){triggerSFHLT = 1.009039521217;}
    else if(pt < 44 ){triggerSFHLT = 1.015748023987;}
    else if(pt < 46 ){triggerSFHLT = 1.013333320618;}
    else if(pt < 48 ){triggerSFHLT = 1.012101173401;}
    else if(pt < 50 ){triggerSFHLT = 1.013172388077;}
    else if(pt < 52 ){triggerSFHLT = 1.001084566116;}
    else if(pt < 54 ){triggerSFHLT = 1.010952949524;}
    else if(pt < 56 ){triggerSFHLT = 1.000000000000;}
    else if(pt < 60 ){triggerSFHLT = 1.000000000000;}
    else if(pt < 65 ){triggerSFHLT = 1.009667038918;}
    else if(pt < 70 ){triggerSFHLT = 0.998936176300;}
    else if(pt < 80 ){triggerSFHLT = 0.992693126202;}
    else if(pt < 90 ){triggerSFHLT = 0.985507249832;}
    else if(pt < 100){triggerSFHLT = 0.987590491772;}
    else if(pt < 120){triggerSFHLT = 0.987654328346;}
    else if(pt < 200){triggerSFHLT = 0.976673424244;}
    else             {triggerSFHLT = 0.996878266335;}
  }
  else if (eta < -0.3){
    if     (pt < 32 ){triggerSFHLT = 1.000000000000;}
    else if(pt < 34 ){triggerSFHLT = 0.954802274704;}
    else if(pt < 36 ){triggerSFHLT = 0.983030319214;}
    else if(pt < 38 ){triggerSFHLT = 0.998805284500;}
    else if(pt < 40 ){triggerSFHLT = 1.004716992378;}
    else if(pt < 42 ){triggerSFHLT = 1.009237885475;}
    else if(pt < 44 ){triggerSFHLT = 1.011428594589;}
    else if(pt < 46 ){triggerSFHLT = 1.011312246323;}
    else if(pt < 48 ){triggerSFHLT = 1.011223316193;}
    else if(pt < 50 ){triggerSFHLT = 1.000000000000;}
    else if(pt < 52 ){triggerSFHLT = 1.003314971924;}
    else if(pt < 54 ){triggerSFHLT = 1.007683873177;}
    else if(pt < 56 ){triggerSFHLT = 0.998910665512;}
    else if(pt < 60 ){triggerSFHLT = 0.990291237831;}
    else if(pt < 65 ){triggerSFHLT = 0.989316225052;}
    else if(pt < 70 ){triggerSFHLT = 1.004305720329;}
    else if(pt < 80 ){triggerSFHLT = 0.990516304970;}
    else if(pt < 90 ){triggerSFHLT = 0.995824635029;}
    else if(pt < 100){triggerSFHLT = 0.987616121769;}
    else if(pt < 120){triggerSFHLT = 1.002094268799;}
    else if(pt < 200){triggerSFHLT = 0.979633390903;}
    else             {triggerSFHLT = 1.009384751320;}
  }
  else if (eta < 0.0){
    if     (pt < 32 ){triggerSFHLT = 1.105882406235;}
    else if(pt < 34 ){triggerSFHLT = 0.889664828777;}
    else if(pt < 36 ){triggerSFHLT = 0.960509538651;}
    else if(pt < 38 ){triggerSFHLT = 0.964285731316;}
    else if(pt < 40 ){triggerSFHLT = 0.984088122845;}
    else if(pt < 42 ){triggerSFHLT = 0.988081037998;}
    else if(pt < 44 ){triggerSFHLT = 0.998816549778;}
    else if(pt < 46 ){triggerSFHLT = 0.995354235172;}
    else if(pt < 48 ){triggerSFHLT = 0.995397031307;}
    else if(pt < 50 ){triggerSFHLT = 1.000000000000;}
    else if(pt < 52 ){triggerSFHLT = 0.998862326145;}
    else if(pt < 54 ){triggerSFHLT = 0.994394600391;}
    else if(pt < 56 ){triggerSFHLT = 1.000000000000;}
    else if(pt < 60 ){triggerSFHLT = 0.996662974358;}
    else if(pt < 65 ){triggerSFHLT = 0.984782636166;}
    else if(pt < 70 ){triggerSFHLT = 0.987012982368;}
    else if(pt < 80 ){triggerSFHLT = 1.003239750862;}
    else if(pt < 90 ){triggerSFHLT = 0.997879087925;}
    else if(pt < 100){triggerSFHLT = 1.018104314804;}
    else if(pt < 120){triggerSFHLT = 0.993717253208;}
    else if(pt < 200){triggerSFHLT = 1.005219221115;}
    else             {triggerSFHLT = 0.968559861183;}
  }
  else if (eta < 0.3){
    if     (pt < 32 ){triggerSFHLT = 1.032967090607;}
    else if(pt < 34 ){triggerSFHLT = 0.883561670780;}
    else if(pt < 36 ){triggerSFHLT = 0.948427677155;}
    else if(pt < 38 ){triggerSFHLT = 0.959558844566;}
    else if(pt < 40 ){triggerSFHLT = 0.975728154182;}
    else if(pt < 42 ){triggerSFHLT = 0.990419149399;}
    else if(pt < 44 ){triggerSFHLT = 0.991755008698;}
    else if(pt < 46 ){triggerSFHLT = 0.990729987621;}
    else if(pt < 48 ){triggerSFHLT = 0.995391726494;}
    else if(pt < 50 ){triggerSFHLT = 0.991999983788;}
    else if(pt < 52 ){triggerSFHLT = 1.002280473709;}
    else if(pt < 54 ){triggerSFHLT = 0.989910304546;}
    else if(pt < 56 ){triggerSFHLT = 0.997745215893;}
    else if(pt < 60 ){triggerSFHLT = 1.001119852066;}
    else if(pt < 65 ){triggerSFHLT = 0.987912058830;}
    else if(pt < 70 ){triggerSFHLT = 0.993435442448;}
    else if(pt < 80 ){triggerSFHLT = 0.991397857666;}
    else if(pt < 90 ){triggerSFHLT = 0.983122348785;}
    else if(pt < 100){triggerSFHLT = 1.005307912827;}
    else if(pt < 120){triggerSFHLT = 0.986344516277;}
    else if(pt < 200){triggerSFHLT = 0.986584126949;}
    else             {triggerSFHLT = 0.965412020683;}
  }
  else if (eta < 0.6){
    if     (pt < 32 ){triggerSFHLT = 0.717391312122;}
    else if(pt < 34 ){triggerSFHLT = 0.891711235046;}
    else if(pt < 36 ){triggerSFHLT = 0.977080821991;}
    else if(pt < 38 ){triggerSFHLT = 0.988151669502;}
    else if(pt < 40 ){triggerSFHLT = 0.994165718555;}
    else if(pt < 42 ){triggerSFHLT = 1.000000000000;}
    else if(pt < 44 ){triggerSFHLT = 1.006872892380;}
    else if(pt < 46 ){triggerSFHLT = 0.998871326447;}
    else if(pt < 48 ){triggerSFHLT = 0.996644318104;}
    else if(pt < 50 ){triggerSFHLT = 0.988974630833;}
    else if(pt < 52 ){triggerSFHLT = 0.994511544704;}
    else if(pt < 54 ){triggerSFHLT = 1.002212405205;}
    else if(pt < 56 ){triggerSFHLT = 0.984815597534;}
    else if(pt < 60 ){triggerSFHLT = 0.990301728249;}
    else if(pt < 65 ){triggerSFHLT = 0.976694941521;}
    else if(pt < 70 ){triggerSFHLT = 0.987165749073;}
    else if(pt < 80 ){triggerSFHLT = 0.986199557781;}
    else if(pt < 90 ){triggerSFHLT = 0.977107167244;}
    else if(pt < 100){triggerSFHLT = 0.975051999092;}
    else if(pt < 120){triggerSFHLT = 0.971074402332;}
    else if(pt < 200){triggerSFHLT = 0.981519520283;}
    else             {triggerSFHLT = 0.981651365757;}
  }
  else if (eta < 0.8){
    if     (pt < 32 ){triggerSFHLT = 0.573248386383;}
    else if(pt < 34 ){triggerSFHLT = 0.887566149235;}
    else if(pt < 36 ){triggerSFHLT = 0.989424228668;}
    else if(pt < 38 ){triggerSFHLT = 0.995354235172;}
    else if(pt < 40 ){triggerSFHLT = 1.002290964127;}
    else if(pt < 42 ){triggerSFHLT = 1.017123341560;}
    else if(pt < 44 ){triggerSFHLT = 1.011198163033;}
    else if(pt < 46 ){triggerSFHLT = 1.006651878357;}
    else if(pt < 48 ){triggerSFHLT = 1.007700800896;}
    else if(pt < 50 ){triggerSFHLT = 1.002181053162;}
    else if(pt < 52 ){triggerSFHLT = 1.000000000000;}
    else if(pt < 54 ){triggerSFHLT = 1.003260850906;}
    else if(pt < 56 ){triggerSFHLT = 0.985074639320;}
    else if(pt < 60 ){triggerSFHLT = 1.001073002815;}
    else if(pt < 65 ){triggerSFHLT = 0.998937308788;}
    else if(pt < 70 ){triggerSFHLT = 0.981269538403;}
    else if(pt < 80 ){triggerSFHLT = 0.982419848442;}
    else if(pt < 90 ){triggerSFHLT = 0.986415863037;}
    else if(pt < 100){triggerSFHLT = 1.003144621849;}
    else if(pt < 120){triggerSFHLT = 0.991684019566;}
    else if(pt < 200){triggerSFHLT = 0.991778016090;}
    else             {triggerSFHLT = 0.985507249832;}
  }
  else if (eta < 1.1){
    if     (pt < 32 ){triggerSFHLT = 0.421686738729;}
    else if(pt < 34 ){triggerSFHLT = 0.835820913315;}
    else if(pt < 36 ){triggerSFHLT = 0.984669804573;}
    else if(pt < 38 ){triggerSFHLT = 0.990836203098;}
    else if(pt < 40 ){triggerSFHLT = 1.001133799553;}
    else if(pt < 42 ){triggerSFHLT = 1.004494428635;}
    else if(pt < 44 ){triggerSFHLT = 1.008918642998;}
    else if(pt < 46 ){triggerSFHLT = 1.005512714386;}
    else if(pt < 48 ){triggerSFHLT = 1.002185821533;}
    else if(pt < 50 ){triggerSFHLT = 0.998915374279;}
    else if(pt < 52 ){triggerSFHLT = 0.998916566372;}
    else if(pt < 54 ){triggerSFHLT = 0.998923599720;}
    else if(pt < 56 ){triggerSFHLT = 1.003236293793;}
    else if(pt < 60 ){triggerSFHLT = 1.000000000000;}
    else if(pt < 65 ){triggerSFHLT = 0.980000019073;}
    else if(pt < 70 ){triggerSFHLT = 1.000000000000;}
    else if(pt < 80 ){triggerSFHLT = 0.980310857296;}
    else if(pt < 90 ){triggerSFHLT = 0.990683257580;}
    else if(pt < 100){triggerSFHLT = 0.985641002655;}
    else if(pt < 120){triggerSFHLT = 0.998968005180;}
    else if(pt < 200){triggerSFHLT = 0.976767659187;}
    else             {triggerSFHLT = 0.982653081417;}
  }
  else if (eta < 1.442){
    if     (pt < 32 ){triggerSFHLT = 0.331125825644;}
    else if(pt < 34 ){triggerSFHLT = 0.722466945648;}
    else if(pt < 36 ){triggerSFHLT = 0.921085059643;}
    else if(pt < 38 ){triggerSFHLT = 0.942720770836;}
    else if(pt < 40 ){triggerSFHLT = 0.952102780342;}
    else if(pt < 42 ){triggerSFHLT = 0.964367806911;}
    else if(pt < 44 ){triggerSFHLT = 0.967305541039;}
    else if(pt < 46 ){triggerSFHLT = 0.974358975887;}
    else if(pt < 48 ){triggerSFHLT = 0.973509907722;}
    else if(pt < 50 ){triggerSFHLT = 0.983425438404;}
    else if(pt < 52 ){triggerSFHLT = 0.973827719688;}
    else if(pt < 54 ){triggerSFHLT = 0.971769809723;}
    else if(pt < 56 ){triggerSFHLT = 0.989130437374;}
    else if(pt < 60 ){triggerSFHLT = 0.975321888924;}
    else if(pt < 65 ){triggerSFHLT = 0.974386334419;}
    else if(pt < 70 ){triggerSFHLT = 0.984042525291;}
    else if(pt < 80 ){triggerSFHLT = 1.004305720329;}
    else if(pt < 90 ){triggerSFHLT = 0.985324919224;}
    else if(pt < 100){triggerSFHLT = 1.024731159210;}
    else if(pt < 120){triggerSFHLT = 0.972533047199;}
    else if(pt < 200){triggerSFHLT = 0.984583735466;}
    else             {triggerSFHLT = 0.967741906643;}
  }
  else if (eta < 1.566){
    if     (pt < 32 ){triggerSFHLT = 0.574297189713;}
    else if(pt < 34 ){triggerSFHLT = 0.796638667583;}
    else if(pt < 36 ){triggerSFHLT = 0.947887301445;}
    else if(pt < 38 ){triggerSFHLT = 0.962716400623;}
    else if(pt < 40 ){triggerSFHLT = 0.975292563438;}
    else if(pt < 42 ){triggerSFHLT = 0.981132090092;}
    else if(pt < 44 ){triggerSFHLT = 0.970588207245;}
    else if(pt < 46 ){triggerSFHLT = 0.998774528503;}
    else if(pt < 48 ){triggerSFHLT = 0.987804889679;}
    else if(pt < 50 ){triggerSFHLT = 0.976019203663;}
    else if(pt < 52 ){triggerSFHLT = 1.000000000000;}
    else if(pt < 54 ){triggerSFHLT = 0.998763918877;}
    else if(pt < 56 ){triggerSFHLT = 0.954815685749;}
    else if(pt < 60 ){triggerSFHLT = 1.017676711082;}
    else if(pt < 65 ){triggerSFHLT = 0.956212997437;}
    else if(pt < 70 ){triggerSFHLT = 0.901766002178;}
    else if(pt < 80 ){triggerSFHLT = 0.997536957264;}
    else if(pt < 90 ){triggerSFHLT = 0.926719307899;}
    else if(pt < 100){triggerSFHLT = 0.960496604443;}
    else if(pt < 120){triggerSFHLT = 0.963045895100;}
    else if(pt < 200){triggerSFHLT = 1.023529410362;}
    else             {triggerSFHLT = 0.929039299488;}
  }
  else if (eta < 1.8){
    if     (pt < 32 ){triggerSFHLT = 0.478260874748;}
    else if(pt < 34 ){triggerSFHLT = 0.773437500000;}
    else if(pt < 36 ){triggerSFHLT = 0.895161271095;}
    else if(pt < 38 ){triggerSFHLT = 0.934926986694;}
    else if(pt < 40 ){triggerSFHLT = 0.923857867718;}
    else if(pt < 42 ){triggerSFHLT = 0.941323339939;}
    else if(pt < 44 ){triggerSFHLT = 0.941463410854;}
    else if(pt < 46 ){triggerSFHLT = 0.948379337788;}
    else if(pt < 48 ){triggerSFHLT = 0.956886231899;}
    else if(pt < 50 ){triggerSFHLT = 0.942555665970;}
    else if(pt < 52 ){triggerSFHLT = 0.949999988079;}
    else if(pt < 54 ){triggerSFHLT = 0.942129611969;}
    else if(pt < 56 ){triggerSFHLT = 0.954869329929;}
    else if(pt < 60 ){triggerSFHLT = 0.956521749496;}
    else if(pt < 65 ){triggerSFHLT = 0.980722904205;}
    else if(pt < 70 ){triggerSFHLT = 0.920045018196;}
    else if(pt < 80 ){triggerSFHLT = 0.938956737518;}
    else if(pt < 90 ){triggerSFHLT = 0.901287555695;}
    else if(pt < 100){triggerSFHLT = 0.940516293049;}
    else if(pt < 120){triggerSFHLT = 0.934282600880;}
    else if(pt < 200){triggerSFHLT = 0.924754619598;}
    else             {triggerSFHLT = 0.946819603443;}
  }
  else {
    if     (pt < 32 ){triggerSFHLT = 0.272727280855;}
    else if(pt < 34 ){triggerSFHLT = 0.656934320927;}
    else if(pt < 36 ){triggerSFHLT = 0.875324666500;}
    else if(pt < 38 ){triggerSFHLT = 0.924066901207;}
    else if(pt < 40 ){triggerSFHLT = 0.926616907120;}
    else if(pt < 42 ){triggerSFHLT = 0.930402934551;}
    else if(pt < 44 ){triggerSFHLT = 0.938405811787;}
    else if(pt < 46 ){triggerSFHLT = 0.939285695553;}
    else if(pt < 48 ){triggerSFHLT = 0.944378674030;}
    else if(pt < 50 ){triggerSFHLT = 0.940281033516;}
    else if(pt < 52 ){triggerSFHLT = 0.944900333881;}
    else if(pt < 54 ){triggerSFHLT = 0.928571403027;}
    else if(pt < 56 ){triggerSFHLT = 0.940420567989;}
    else if(pt < 60 ){triggerSFHLT = 0.921768724918;}
    else if(pt < 65 ){triggerSFHLT = 0.957568824291;}
    else if(pt < 70 ){triggerSFHLT = 0.924191772938;}
    else if(pt < 80 ){triggerSFHLT = 0.932810723782;}
    else if(pt < 90 ){triggerSFHLT = 0.902465164661;}
    else if(pt < 100){triggerSFHLT = 0.922657966614;}
    else if(pt < 120){triggerSFHLT = 0.945945918560;}
    else if(pt < 200){triggerSFHLT = 0.939393937588;}
    else             {triggerSFHLT = 0.935235977173;}
  }
  return triggerSFHLT;
}

double HardcodedConditions::GetElectronTriggerSF2017(double pt, double eta){
  // Trigger Scale Factors, SF2017B_Bkg_LepPtEta_EOR.png & SF2017CDEF_Bkg_LepPtEta_EOR.png
  float sf_B;
  float sf_C;
  float sf_DEF;
  float lumi_B = 4.823;
  float lumi_C = 9.664;
  float lumi_DEF = 27.07;

  if( fabs(eta) < 0.8 ){
    if(      pt < 35.0  ){ sf_B = 1.0;           sf_C = 1.0;            sf_DEF = 0.910508894879; }
    else if( pt < 40.0  ){ sf_B = 1.19235377821; sf_C = 0.961432584122; sf_DEF = 0.953531146324; }
    else if( pt < 45.0  ){ sf_B = 1.15582596391; sf_C = 0.957629044796; sf_DEF = 0.969037828674; }
    else if( pt < 50.0  ){ sf_B = 1.14242389742; sf_C = 0.952084569431; sf_DEF = 0.972670135935; }
    else if( pt < 60.0  ){ sf_B = 1.13798058665; sf_C = 0.972836208578; sf_DEF = 0.97354484058; }
    else if( pt < 100.0 ){ sf_B = 1.11927898325; sf_C = 0.97878084945;  sf_DEF = 0.978742705794; }
    else if( pt < 200.0 ){ sf_B = 1.08208421955; sf_C = 0.97205414899;  sf_DEF = 0.976656543342; }
    else{                  sf_B = 1.05681427994; sf_C = 0.988668281842; sf_DEF = 0.980285171661; }                 
  }
  else if( fabs(eta) < 1.4442 ){
    if(      pt < 35.0  ){ sf_B = 1.0;           sf_C = 1.0;            sf_DEF = 0.751761888491; }
    else if( pt < 40.0  ){ sf_B = 1.15822014397; sf_C = 0.860499625902; sf_DEF = 0.919657299703; }
    else if( pt < 45.0  ){ sf_B = 1.21616929374; sf_C = 0.954195822579; sf_DEF = 0.9416298044; }
    else if( pt < 50.0  ){ sf_B = 1.17221728706; sf_C = 0.95883629846;  sf_DEF = 0.967038221562; }
    else if( pt < 60.0  ){ sf_B = 1.19498750549; sf_C = 0.954662162504; sf_DEF = 0.975886529118; }
    else if( pt < 100.0 ){ sf_B = 1.14500756907; sf_C = 0.973404630486; sf_DEF = 0.981893775663; }
    else if( pt < 200.0 ){ sf_B = 1.08473672928; sf_C = 0.982716650785; sf_DEF = 0.978950786067; }
    else{                  sf_B = 1.04804436988; sf_C = 0.962029353635; sf_DEF = 0.979265291494; }         
  }
  else if( fabs(eta) < 2.0 ){
    if(      pt < 35.0  ){ sf_B = 1.0;            sf_C = 1.0;            sf_DEF = 0.61359340781; }
    else if( pt < 40.0  ){ sf_B = 0.979837673172; sf_C = 0.834393494481; sf_DEF = 0.865218488115; }
    else if( pt < 45.0  ){ sf_B = 1.09592474113;  sf_C = 0.934846351249; sf_DEF = 0.92564191376; }
    else if( pt < 50.0  ){ sf_B = 1.14329944654;  sf_C = 0.962071721753; sf_DEF = 0.910259293332; }
    else if( pt < 60.0  ){ sf_B = 1.12458617216;  sf_C = 0.939378108547; sf_DEF = 0.951179859384; }
    else if( pt < 100.0 ){ sf_B = 1.12172511077;  sf_C = 0.987642127321; sf_DEF = 0.968589861037; }
    else if( pt < 200.0 ){ sf_B = 1.09052141074;  sf_C = 0.985970344843; sf_DEF = 0.967442726925; }
    else{                  sf_B = 1.08883369326;  sf_C = 0.893843409369; sf_DEF = 0.958624277634; }  
  }
  else{
    if(      pt < 35.0  ){ sf_B = 1.0;            sf_C = 1.0;            sf_DEF = 1.34938101512; }
    else if( pt < 40.0  ){ sf_B = 0.852743087035; sf_C = 0.682868604737; sf_DEF = 0.809342108762; }
    else if( pt < 45.0  ){ sf_B = 1.1679917664;   sf_C = 1.0519398793;   sf_DEF = 0.929952818205; }
    else if( pt < 50.0  ){ sf_B = 1.19320302369;  sf_C = 0.983854619602; sf_DEF = 0.996331036879; }
    else if( pt < 60.0  ){ sf_B = 1.08557256937;  sf_C = 0.996753585332; sf_DEF = 0.926442474712; }
    else if( pt < 100.0 ){ sf_B = 1.18448651178;  sf_C = 1.02919877827;  sf_DEF = 1.03147014466; }
    else if( pt < 200.0 ){ sf_B = 1.06393762562;  sf_C = 1.01898572985;  sf_DEF = 0.976709670734; }
    else{                  sf_B = 1.07201980973;  sf_C = 1.06465564707;  sf_DEF = 0.958190082361; }        
  }
  return ( 4.823 * sf_B + 9.664 * sf_C + 27.07 * sf_DEF ) / 41.557;
}

double HardcodedConditions::GetElectronTriggerSF2018( double pt, double eta ){
  if( fabs(eta) < 0.8 ){
    if( pt < 35 )         return 0.913692057441;
    else if( pt <  40.0 ) return 0.971695502732;
    else if( pt <  45.0 ) return 0.973472902604;
    else if( pt <  50.0 ) return 0.975870251002;
    else if( pt <  60.0 ) return 0.972260692149;
    else if( pt < 100.0 ) return 0.978462954775;
    else if( pt < 200.0 ) return 0.982340801275;
    else                  return 0.988277803553;
  }
  else if( fabs(eta) < 1.4442 ){
    if( pt < 35 )         return 0.79130810157;
    else if( pt <  40.0 ) return 0.95794335208;
    else if( pt <  45.0 ) return 0.98584588097;
    else if( pt <  50.0 ) return 0.986921685202;
    else if( pt <  60.0 ) return 1.01257881296;
    else if( pt < 100.0 ) return 0.985749736854;
    else if( pt < 200.0 ) return 0.993225266785;
    else                  return 1.0017169042;
  }
  else if( fabs(eta) < 2.0 ){
    if( pt < 35 )         return 0.784488053273;
    else if( pt <  40.0 ) return 0.923642602884;
    else if( pt <  45.0 ) return 0.949818783052;
    else if( pt <  50.0 ) return 0.994631635079;
    else if( pt <  60.0 ) return 0.971684494245;
    else if( pt < 100.0 ) return 0.975080347642;
    else if( pt < 200.0 ) return 0.945571234252;
    else                  return 0.917539801421;
  }
  else{
    if( pt < 35 )         return 0.771792545521;
    else if( pt <  40.0 ) return 0.877438998912;
    else if( pt <  45.0 ) return 1.05068262187;
    else if( pt <  50.0 ) return 0.963750775537;
    else if( pt <  60.0 ) return 0.944876225901;
    else if( pt < 100.0 ) return 0.954494360964;
    else if( pt < 200.0 ) return 0.940644961626;
    else                  return 0.795593538315;
  }
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|         HADRON TRIGGER SCALE FACTOR SECTION         |\  | |/|
 | `---' |               (For Electron Channel)                | `---' |
 |       |                                                     |       |
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetIsEHadronTriggerSF(double njets, double ht, std::string year){
  if      (year=="2016APV") return GetIsEHadronTriggerSF2016APV(njets, ht);
  else if (year=="2016") return GetIsEHadronTriggerSF2016(njets, ht);
  else if (year=="2017") return GetIsEHadronTriggerSF2017(njets, ht);
  else if (year=="2018") return GetIsEHadronTriggerSF2018(njets, ht);
  else return 0.;
}

double HardcodedConditions::GetIsEHadronTriggerSF2016APV(double njets, double ht){
  return 1.000; 
}

double HardcodedConditions::GetIsEHadronTriggerSF2016(double njets, double ht){
  return 1.000; 
}

double HardcodedConditions::GetIsEHadronTriggerSF2017(double njets, double ht){
  return 1.000; 
}

double HardcodedConditions::GetIsEHadronTriggerSF2018(double njets, double ht){
  return 1.000; 
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|      ELECTRON X-TRIGGER SCALE FACTOR SECTION        |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       |
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetElectronTriggerXSF(double ht, double pt, double eta, std::string year){
  if      (year=="2016APV") return GetElectronTriggerXSF2016APV(ht, pt, eta);
  else if (year=="2016") return GetElectronTriggerXSF2016(ht, pt, eta);
  else if (year=="2017") return GetElectronTriggerXSF2017(ht, pt, eta);
  else if (year=="2018") return GetElectronTriggerXSF2018(ht, pt, eta);
  else return 0. ;
}

double HardcodedConditions::GetElectronTriggerXSF2016APV(double ht, double pt, double eta){
if ( ht < 400.0 ) {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.97442;
    else if ( fabs(eta) < 1.4442 ) return 1.01635;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.03495;
    else return 0.97493; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.93493;
    else if ( fabs(eta) < 1.4442 ) return 0.96573;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.99483;
    else return 0.89809; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98881;
    else if ( fabs(eta) < 1.4442 ) return 1.00730;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.96774;
    else return 0.87647; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00224;
    else if ( fabs(eta) < 1.4442 ) return 1.00792;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97299;
    else return 0.94874; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01936;
    else if ( fabs(eta) < 1.4442 ) return 0.99867;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00559;
    else return 0.90529; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01590;
    else if ( fabs(eta) < 1.4442 ) return 1.01310;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.01689;
    else return 0.90480; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00506;
    else if ( fabs(eta) < 1.4442 ) return 0.99318;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00266;
    else return 0.88503; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99751;
    else if ( fabs(eta) < 1.4442 ) return 1.00437;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.96210;
    else return 0.92040; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99726;
    else if ( fabs(eta) < 1.4442 ) return 0.99310;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97224;
    else return 0.90835; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99090;
    else if ( fabs(eta) < 1.4442 ) return 0.96343;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.92264;
    else return 0.89092; }
  else {
    if ( fabs(eta) < 0.8000 ) return 0.97097;
    else if ( fabs(eta) < 1.4442 ) return 0.96649;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.86253;
    else return 0.90865; }
else if ( ht < 500.0 ) {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.91781;
    else if ( fabs(eta) < 1.4442 ) return 0.95743;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00770;
    else return 0.99855; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.92032;
    else if ( fabs(eta) < 1.4442 ) return 0.93480;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97981;
    else return 0.97156; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.95774;
    else if ( fabs(eta) < 1.4442 ) return 0.96635;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.99135;
    else return 0.95297; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01037;
    else if ( fabs(eta) < 1.4442 ) return 1.00518;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.01799;
    else return 0.96855; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00876;
    else if ( fabs(eta) < 1.4442 ) return 1.00984;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.03025;
    else return 0.94382; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01401;
    else if ( fabs(eta) < 1.4442 ) return 1.00909;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.01145;
    else return 0.96379; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00187;
    else if ( fabs(eta) < 1.4442 ) return 0.98647;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00988;
    else return 0.93091; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00044;
    else if ( fabs(eta) < 1.4442 ) return 0.98811;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97177;
    else return 0.93597; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99446;
    else if ( fabs(eta) < 1.4442 ) return 0.97641;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.95770;
    else return 0.90730; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99412;
    else if ( fabs(eta) < 1.4442 ) return 0.96845;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.92548;
    else return 0.89953; }
  else {
    if ( fabs(eta) < 0.8000 ) return 0.98815;
    else if ( fabs(eta) < 1.4442 ) return 0.97160;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.86405;
    else return 0.90856; }
else if ( ht < 1000.0 ) {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.94632;
    else if ( fabs(eta) < 1.4442 ) return 0.98734;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.05291;
    else return 1.01983; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.91740;
    else if ( fabs(eta) < 1.4442 ) return 0.92947;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.99646;
    else return 0.94090; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.95877;
    else if ( fabs(eta) < 1.4442 ) return 0.97490;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.99552;
    else return 0.98075; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01062;
    else if ( fabs(eta) < 1.4442 ) return 1.03015;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.07989;
    else return 0.96381; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01902;
    else if ( fabs(eta) < 1.4442 ) return 1.01286;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.04352;
    else return 0.98165; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01165;
    else if ( fabs(eta) < 1.4442 ) return 1.02152;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.02257;
    else return 0.97401; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99462;
    else if ( fabs(eta) < 1.4442 ) return 0.98477;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.99868;
    else return 0.96660; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98745;
    else if ( fabs(eta) < 1.4442 ) return 0.99305;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97833;
    else return 0.94802; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98572;
    else if ( fabs(eta) < 1.4442 ) return 0.97307;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.95172;
    else return 0.93307; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98434;
    else if ( fabs(eta) < 1.4442 ) return 0.96911;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.93184;
    else return 0.89748; }
  else {
    if ( fabs(eta) < 0.8000 ) return 0.98962;
    else if ( fabs(eta) < 1.4442 ) return 0.96750;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.92469;
    else return 0.87404; }
else if ( ht < 2000.0 ) {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.94998;
    else if ( fabs(eta) < 1.4442 ) return 0.95510;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.41532;
    else return 1.14341; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.97759;
    else if ( fabs(eta) < 1.4442 ) return 0.90095;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.10440;
    else return 0.96561; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00859;
    else if ( fabs(eta) < 1.4442 ) return 0.97950;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.98182;
    else return 1.00214; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01939;
    else if ( fabs(eta) < 1.4442 ) return 1.00760;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.10035;
    else return 0.98132; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00813;
    else if ( fabs(eta) < 1.4442 ) return 1.04994;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.04097;
    else return 0.90342; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.02403;
    else if ( fabs(eta) < 1.4442 ) return 1.04722;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.04775;
    else return 0.95027; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98227;
    else if ( fabs(eta) < 1.4442 ) return 0.99097;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.10077;
    else return 0.94494; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98123;
    else if ( fabs(eta) < 1.4442 ) return 0.99744;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.94938;
    else return 0.88021; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99653;
    else if ( fabs(eta) < 1.4442 ) return 0.98526;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.98134;
    else return 0.86272; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99027;
    else if ( fabs(eta) < 1.4442 ) return 0.97311;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97496;
    else return 0.90323; }
  else {
    if ( fabs(eta) < 0.8000 ) return 0.97325;
    else if ( fabs(eta) < 1.4442 ) return 0.94990;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.96784;
    else return 1.16825; }
else {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.50000;
    else if ( fabs(eta) < 1.4442 ) return 1.75000;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 3.00000;
    else return 1.00000; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.08333;
    else if ( fabs(eta) < 1.4442 ) return 0.63492;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return inf;
    else return 0.60000; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.07143;
    else if ( fabs(eta) < 1.4442 ) return 0.75000;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return inf;
    else return 1.00000; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00000;
    else if ( fabs(eta) < 1.4442 ) return 0.88889;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return inf;
    else return 1.00000; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.25000;
    else if ( fabs(eta) < 1.4442 ) return 1.12500;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 2.00000;
    else return inf; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.15714;
    else if ( fabs(eta) < 1.4442 ) return 1.00000;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00000;
    else return 1.00000; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00000;
    else if ( fabs(eta) < 1.4442 ) return 0.90000;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00000;
    else return inf; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.94118;
    else if ( fabs(eta) < 1.4442 ) return 1.13333;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.57143;
    else return inf; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01684;
    else if ( fabs(eta) < 1.4442 ) return 0.87719;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.01587;
    else return 1.00000; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.95353;
    else if ( fabs(eta) < 1.4442 ) return 1.00265;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.83333;
    else return 0.85714; }
  else {
    if ( fabs(eta) < 0.8000 ) return 0.99615;
    else if ( fabs(eta) < 1.4442 ) return 0.87097;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00000;
    else return 1.00000; }
}

double HardcodedConditions::GetElectronTriggerXSF2016(double ht, double pt, double eta){
  if ( ht < 400.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.32022;
      else if ( fabs(eta) < 1.4442 ) return 1.34059;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.50133;
      else return 1.37390; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.14278;
      else if ( fabs(eta) < 1.4442 ) return 1.17385;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.25220;
      else return 1.22035; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.06625;
      else if ( fabs(eta) < 1.4442 ) return 1.10789;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.14764;
      else return 1.10383; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05400;
      else if ( fabs(eta) < 1.4442 ) return 1.07335;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.11230;
      else return 1.07930; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.04419;
      else if ( fabs(eta) < 1.4442 ) return 1.04390;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.08564;
      else return 1.03983; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03824;
      else if ( fabs(eta) < 1.4442 ) return 1.04691;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.06593;
      else return 1.02652; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02373;
      else if ( fabs(eta) < 1.4442 ) return 1.02305;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.02250;
      else return 1.02992; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02499;
      else if ( fabs(eta) < 1.4442 ) return 1.01751;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.99517;
      else return 0.98041; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00938;
      else if ( fabs(eta) < 1.4442 ) return 1.00362;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.97773;
      else return 0.98189; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.98765;
      else if ( fabs(eta) < 1.4442 ) return 0.96558;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.84148;
      else return 0.85251; }
    else {
      if ( fabs(eta) < 0.8000 ) return 0.95093;
      else if ( fabs(eta) < 1.4442 ) return 0.91756;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.63243;
      else return 0.66111; }
  else if ( ht < 500.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.09130;
      else if ( fabs(eta) < 1.4442 ) return 1.13014;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.22449;
      else return 1.20874; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.07357;
      else if ( fabs(eta) < 1.4442 ) return 1.10238;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.14459;
      else return 1.13005; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.06401;
      else if ( fabs(eta) < 1.4442 ) return 1.07640;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.11831;
      else return 1.10757; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05358;
      else if ( fabs(eta) < 1.4442 ) return 1.06188;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.08870;
      else return 1.10119; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.04174;
      else if ( fabs(eta) < 1.4442 ) return 1.05166;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.07863;
      else return 1.08582; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03420;
      else if ( fabs(eta) < 1.4442 ) return 1.03903;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.06819;
      else return 1.07378; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02221;
      else if ( fabs(eta) < 1.4442 ) return 1.01803;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.99513;
      else return 1.00939; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01560;
      else if ( fabs(eta) < 1.4442 ) return 1.01108;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.98316;
      else return 0.96955; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00547;
      else if ( fabs(eta) < 1.4442 ) return 1.00357;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.95929;
      else return 0.95538; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99229;
      else if ( fabs(eta) < 1.4442 ) return 0.97439;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.83933;
      else return 0.87798; }
    else {
      if ( fabs(eta) < 0.8000 ) return 0.97462;
      else if ( fabs(eta) < 1.4442 ) return 0.93004;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.66000;
      else return 0.63268; }
  else if ( ht < 1000.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.10189;
      else if ( fabs(eta) < 1.4442 ) return 1.14020;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.25855;
      else return 1.19455; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.07480;
      else if ( fabs(eta) < 1.4442 ) return 1.09648;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.17892;
      else return 1.15347; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.06608;
      else if ( fabs(eta) < 1.4442 ) return 1.07368;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.13022;
      else return 1.08849; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05970;
      else if ( fabs(eta) < 1.4442 ) return 1.07790;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.11217;
      else return 1.10780; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05311;
      else if ( fabs(eta) < 1.4442 ) return 1.05877;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.09685;
      else return 1.08670; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02462;
      else if ( fabs(eta) < 1.4442 ) return 1.03171;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.06528;
      else return 1.08150; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01292;
      else if ( fabs(eta) < 1.4442 ) return 1.01559;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.97155;
      else return 0.99382; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00971;
      else if ( fabs(eta) < 1.4442 ) return 1.00766;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.95589;
      else return 0.94692; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00247;
      else if ( fabs(eta) < 1.4442 ) return 0.99854;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.94779;
      else return 0.93892; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.98890;
      else if ( fabs(eta) < 1.4442 ) return 0.97659;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.88233;
      else return 0.85798; }
    else {
      if ( fabs(eta) < 0.8000 ) return 0.97216;
      else if ( fabs(eta) < 1.4442 ) return 0.93414;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.68956;
      else return 0.63139; }
  else if ( ht < 2000.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.14570;
      else if ( fabs(eta) < 1.4442 ) return 1.21177;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.31776;
      else return 1.16855; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.07446;
      else if ( fabs(eta) < 1.4442 ) return 1.10659;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.14467;
      else return 1.13535; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.06492;
      else if ( fabs(eta) < 1.4442 ) return 1.04640;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.09131;
      else return 1.11306; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.06573;
      else if ( fabs(eta) < 1.4442 ) return 1.07180;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.15068;
      else return 1.14573; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05784;
      else if ( fabs(eta) < 1.4442 ) return 1.03448;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.02083;
      else return 1.04335; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01660;
      else if ( fabs(eta) < 1.4442 ) return 1.07568;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.04164;
      else return 0.96949; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99415;
      else if ( fabs(eta) < 1.4442 ) return 1.00113;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.92392;
      else return 0.95956; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99000;
      else if ( fabs(eta) < 1.4442 ) return 0.99861;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.92800;
      else return 0.92989; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.96943;
      else if ( fabs(eta) < 1.4442 ) return 0.99066;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.96493;
      else return 0.88250; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.98001;
      else if ( fabs(eta) < 1.4442 ) return 0.98074;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.87694;
      else return 0.85815; }
    else {
      if ( fabs(eta) < 0.8000 ) return 0.98181;
      else if ( fabs(eta) < 1.4442 ) return 0.96699;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.76461;
      else return 0.86624; }
  else {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.06250;
      else if ( fabs(eta) < 1.4442 ) return 1.33333;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.66667;
      else return 0.50000; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.25000;
      else if ( fabs(eta) < 1.4442 ) return 1.28571;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.33333;
      else return 2.00000; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.14286;
      else if ( fabs(eta) < 1.4442 ) return 1.11111;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.14286;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return inf; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.06667;
      else if ( fabs(eta) < 1.4442 ) return 1.10000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return inf; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.85375;
      else if ( fabs(eta) < 1.4442 ) return 0.76923;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.77778;
      else return 1.00000; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.11429;
      else if ( fabs(eta) < 1.4442 ) return 1.11111;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01299;
      else if ( fabs(eta) < 1.4442 ) return 1.02778;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.88889;
      else return 1.00000; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99628;
      else if ( fabs(eta) < 1.4442 ) return 0.89808;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.66667;
      else return 1.00000; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.03830;
      else if ( fabs(eta) < 1.4442 ) return 0.86762;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.73333;
      else return 1.00000; }
}

double HardcodedConditions::GetElectronTriggerXSF2017(double ht, double pt, double eta){
  double scaleCDEF = 38.783 / 43.841; 
if ( ht < 400.0 ) {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 2.49119 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 2.84488 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 2.95812 * scaleCDEF;
    else return 3.40630 * scaleCDEF; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.29424 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.68968 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.56621 * scaleCDEF;
    else return 1.99238 * scaleCDEF; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.36113 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.40840 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.61402 * scaleCDEF;
    else return 0.50079 * scaleCDEF; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.91018;
    else if ( fabs(eta) < 1.4442 ) return 0.83497;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.91954;
    else return 0.86626; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.04376;
    else if ( fabs(eta) < 1.4442 ) return 1.04254;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.01014;
    else return 1.05228; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.03916;
    else if ( fabs(eta) < 1.4442 ) return 1.04653;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.03918;
    else return 1.05778; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.02424;
    else if ( fabs(eta) < 1.4442 ) return 1.01729;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.01177;
    else return 1.03245; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01566;
    else if ( fabs(eta) < 1.4442 ) return 1.01037;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.99521;
    else return 0.99017; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00310;
    else if ( fabs(eta) < 1.4442 ) return 0.99317;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.95953;
    else return 0.97774; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99650;
    else if ( fabs(eta) < 1.4442 ) return 0.97686;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.86541;
    else return 0.85180; }
  else {
    if ( fabs(eta) < 0.8000 ) return 0.99711;
    else if ( fabs(eta) < 1.4442 ) return 0.97510;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.79570;
    else return 0.74124; }
else if ( ht < 500.0 ) {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.20453 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.26016 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.29438 * scaleCDEF;
    else return 1.43774 * scaleCDEF; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.10510 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.18469 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.20147 * scaleCDEF;
    else return 1.34622 * scaleCDEF; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.72515 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.81376 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.84222 * scaleCDEF;
    else return 0.97946 * scaleCDEF; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.95211;
    else if ( fabs(eta) < 1.4442 ) return 0.92023;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.94082;
    else return 0.92336; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.03743;
    else if ( fabs(eta) < 1.4442 ) return 1.04079;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.03491;
    else return 1.05685; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.03392;
    else if ( fabs(eta) < 1.4442 ) return 1.04412;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.03906;
    else return 1.06167; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01985;
    else if ( fabs(eta) < 1.4442 ) return 1.02159;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.99449;
    else return 0.99193; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01427;
    else if ( fabs(eta) < 1.4442 ) return 1.00950;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.98198;
    else return 0.98090; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01084;
    else if ( fabs(eta) < 1.4442 ) return 1.01008;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97455;
    else return 0.98979; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00377;
    else if ( fabs(eta) < 1.4442 ) return 0.99496;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.91741;
    else return 0.89790; }
  else {
    if ( fabs(eta) < 0.8000 ) return 1.00340;
    else if ( fabs(eta) < 1.4442 ) return 0.98346;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.80370;
    else return 0.77724; }
else if ( ht < 1000.0 ) {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.07154 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.10677 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.12230 * scaleCDEF;
    else return 1.23772 * scaleCDEF; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.04435 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.08214 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.10046 * scaleCDEF;
    else return 1.18381 * scaleCDEF; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.97389 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.00532 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00960 * scaleCDEF;
      else return 1.08944 * scaleCDEF; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03190;
      else if ( fabs(eta) < 1.4442 ) return 1.03791;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.02035;
      else return 1.03669; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.04218;
      else if ( fabs(eta) < 1.4442 ) return 1.05625;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.04263;
      else return 1.07300; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.04167;
      else if ( fabs(eta) < 1.4442 ) return 1.05551;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.04191;
      else return 1.05906; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02871;
      else if ( fabs(eta) < 1.4442 ) return 1.02638;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.01300;
      else return 1.03762; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01836;
      else if ( fabs(eta) < 1.4442 ) return 1.02291;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.98832;
      else return 1.01591; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02181;
      else if ( fabs(eta) < 1.4442 ) return 1.01472;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.98591;
      else return 1.00951; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01384;
      else if ( fabs(eta) < 1.4442 ) return 1.00294;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.94452;
      else return 0.93174; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.00779;
      else if ( fabs(eta) < 1.4442 ) return 0.98724;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.83381;
      else return 0.78791; }
  else if ( ht < 2000.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.09413 * scaleCDEF;
      else if ( fabs(eta) < 1.4442 ) return 1.15423 * scaleCDEF;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.16940 * scaleCDEF;
      else return 1.31431 * scaleCDEF; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.06852 * scaleCDEF;
      else if ( fabs(eta) < 1.4442 ) return 1.10614 * scaleCDEF;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.10697 * scaleCDEF;
      else return 1.22471 * scaleCDEF; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.98997 * scaleCDEF;
      else if ( fabs(eta) < 1.4442 ) return 1.01903 * scaleCDEF;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.02268 * scaleCDEF;
      else return 1.11193 * scaleCDEF; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.04973;
      else if ( fabs(eta) < 1.4442 ) return 1.04808;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.05218;
      else return 1.02717; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03846;
      else if ( fabs(eta) < 1.4442 ) return 1.06303;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.10091;
      else return 1.06324; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05633;
      else if ( fabs(eta) < 1.4442 ) return 1.06989;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.08123;
      else return 1.09286; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02972;
      else if ( fabs(eta) < 1.4442 ) return 1.02963;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.02026;
      else return 1.06799; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02943;
      else if ( fabs(eta) < 1.4442 ) return 1.03727;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.03207;
      else return 1.00578; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03396;
      else if ( fabs(eta) < 1.4442 ) return 1.03519;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.02854;
      else return 0.99465; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02719;
      else if ( fabs(eta) < 1.4442 ) return 1.01550;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.02729;
      else return 0.95662; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.02119;
      else if ( fabs(eta) < 1.4442 ) return 0.99561;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.87261;
      else return 0.85366; }
  else {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.17105 * scaleCDEF;
      else if ( fabs(eta) < 1.4442 ) return 1.10811 * scaleCDEF;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.21429 * scaleCDEF;
      else return 1.20000 * scaleCDEF; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.17081 * scaleCDEF;
      else if ( fabs(eta) < 1.4442 ) return 1.17111 * scaleCDEF;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.50000 * scaleCDEF;
      else return 1.40000 * scaleCDEF; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03085 * scaleCDEF;
      else if ( fabs(eta) < 1.4442 ) return 0.98182 * scaleCDEF;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000 * scaleCDEF;
      else return 1.00000 * scaleCDEF; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.06173;
      else if ( fabs(eta) < 1.4442 ) return 1.12821;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.99346;
      else return 2.25000; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.06780;
      else if ( fabs(eta) < 1.4442 ) return 1.13514;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.20000; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01205;
      else if ( fabs(eta) < 1.4442 ) return 1.05778;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.81250;
      else return 1.00000; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.04545;
      else if ( fabs(eta) < 1.4442 ) return 1.08696;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.20000;
      else return 1.00000; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.13534;
      else if ( fabs(eta) < 1.4442 ) return 0.97403;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.08782;
      else if ( fabs(eta) < 1.4442 ) return 1.03497;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.05263;
      else return 1.14286; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03458;
      else if ( fabs(eta) < 1.4442 ) return 1.04817;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.08167;
      else return 1.33333; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.06982;
      else if ( fabs(eta) < 1.4442 ) return 1.03636;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.99750;
      else return 1.00000; }
}

double HardcodedConditions::GetElectronTriggerXSF2018(double ht, double pt, double eta){
  if ( ht < 400.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.76380;
      else if ( fabs(eta) < 1.4442 ) return 2.09052;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 2.15072;
      else return 2.47325; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.69997;
      else if ( fabs(eta) < 1.4442 ) return 0.87505;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.80363;
      else return 1.47947; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.50502;
      else if ( fabs(eta) < 1.4442 ) return 0.56079;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.62466;
      else return 0.85435; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99384;
      else if ( fabs(eta) < 1.4442 ) return 0.99101;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.24559;
      else return 1.38539; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02951;
      else if ( fabs(eta) < 1.4442 ) return 1.02837;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.04372;
      else return 1.06684; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02110;
      else if ( fabs(eta) < 1.4442 ) return 1.02557;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.03760;
      else return 1.04705; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00773;
      else if ( fabs(eta) < 1.4442 ) return 1.00764;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.99564;
      else return 0.98887; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99619;
      else if ( fabs(eta) < 1.4442 ) return 1.00103;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.96543;
      else return 0.96042; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99227;
      else if ( fabs(eta) < 1.4442 ) return 0.99052;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.94897;
      else return 0.93015; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99007;
      else if ( fabs(eta) < 1.4442 ) return 0.97111;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.84431;
      else return 0.84182; }
    else {
      if ( fabs(eta) < 0.8000 ) return 0.99666;
      else if ( fabs(eta) < 1.4442 ) return 0.98366;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.82130;
      else return 0.77469; }
  else if ( ht < 500.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.13869;
      else if ( fabs(eta) < 1.4442 ) return 1.19606;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.23219;
      else return 1.37435; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.96555;
      else if ( fabs(eta) < 1.4442 ) return 1.03266;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00314;
      else return 1.19791; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.71441;
      else if ( fabs(eta) < 1.4442 ) return 0.77382;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.75325;
      else return 0.88927; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.97737;
      else if ( fabs(eta) < 1.4442 ) return 0.96581;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.04691;
      else return 1.05291; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02825;
      else if ( fabs(eta) < 1.4442 ) return 1.03206;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.04247;
      else return 1.06294; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02265;
      else if ( fabs(eta) < 1.4442 ) return 1.03573;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.03587;
      else return 1.03932; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00899;
      else if ( fabs(eta) < 1.4442 ) return 1.00837;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.97927;
      else return 0.98886; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99991;
      else if ( fabs(eta) < 1.4442 ) return 1.00179;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.96661;
      else return 0.96556; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00161;
      else if ( fabs(eta) < 1.4442 ) return 0.99955;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.96209;
      else return 0.95772; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99878;
      else if ( fabs(eta) < 1.4442 ) return 0.99030;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.90648;
      else return 0.89398; }
    else {
      if ( fabs(eta) < 0.8000 ) return 0.99645;
      else if ( fabs(eta) < 1.4442 ) return 0.97891;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.81703;
      else return 0.78639; }
  else if ( ht < 1000.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05777;
      else if ( fabs(eta) < 1.4442 ) return 1.09300;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.12614;
      else return 1.24038; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05107;
      else if ( fabs(eta) < 1.4442 ) return 1.07306;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.09313;
      else return 1.17288; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03456;
      else if ( fabs(eta) < 1.4442 ) return 1.04706;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.04534;
      else return 1.11653; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03046;
      else if ( fabs(eta) < 1.4442 ) return 1.04841;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.06080;
      else return 1.10124; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03002;
      else if ( fabs(eta) < 1.4442 ) return 1.04305;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.04980;
      else return 1.07858; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02730;
      else if ( fabs(eta) < 1.4442 ) return 1.03975;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.03819;
      else return 1.05628; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01447;
      else if ( fabs(eta) < 1.4442 ) return 1.01697;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.99753;
      else return 1.00407; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01078;
      else if ( fabs(eta) < 1.4442 ) return 1.01128;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.97579;
      else return 0.99743; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00823;
      else if ( fabs(eta) < 1.4442 ) return 1.00319;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.97022;
      else return 0.96907; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99876;
      else if ( fabs(eta) < 1.4442 ) return 0.99534;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.92548;
      else return 0.91904; }
    else {
      if ( fabs(eta) < 0.8000 ) return 0.99351;
      else if ( fabs(eta) < 1.4442 ) return 0.98095;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.85639;
      else return 0.80574; }
  else if ( ht < 2000.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.07824;
      else if ( fabs(eta) < 1.4442 ) return 1.11128;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.12844;
      else return 1.25489; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05526;
      else if ( fabs(eta) < 1.4442 ) return 1.07105;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.11939;
      else return 1.18197; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05964;
      else if ( fabs(eta) < 1.4442 ) return 1.05255;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.09303;
      else return 1.17335; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.04844;
      else if ( fabs(eta) < 1.4442 ) return 1.06453;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.05290;
      else return 1.11675; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03840;
      else if ( fabs(eta) < 1.4442 ) return 1.04995;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.05376;
      else return 1.07432; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03527;
      else if ( fabs(eta) < 1.4442 ) return 1.05264;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.03520;
      else return 1.05164; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01247;
      else if ( fabs(eta) < 1.4442 ) return 1.02605;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.97513;
      else return 0.99118; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02434;
      else if ( fabs(eta) < 1.4442 ) return 1.00477;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00006;
      else return 1.03162; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01417;
      else if ( fabs(eta) < 1.4442 ) return 1.01462;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.99284;
      else return 0.99372; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00274;
      else if ( fabs(eta) < 1.4442 ) return 1.01431;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.95827;
      else return 0.94524; }
    else {
      if ( fabs(eta) < 0.8000 ) return 0.99762;
      else if ( fabs(eta) < 1.4442 ) return 0.98731;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.89087;
      else return 0.86342; }
  else {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.09140;
      else if ( fabs(eta) < 1.4442 ) return 0.88571;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.03125;
      else return 1.36111; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.06000;
      else if ( fabs(eta) < 1.4442 ) return 1.10714;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.97222;
      else return 1.03704; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.09259;
      else if ( fabs(eta) < 1.4442 ) return 0.94444;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.14286;
      else return 1.00000; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.95833;
      else if ( fabs(eta) < 1.4442 ) return 1.02632;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.05000;
      else return 1.08889; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03195;
      else if ( fabs(eta) < 1.4442 ) return 1.08108;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.18681;
      else return 1.00000; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02388;
      else if ( fabs(eta) < 1.4442 ) return 1.01250;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.88889;
      else return 1.00000; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.04371;
      else if ( fabs(eta) < 1.4442 ) return 1.05357;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.11538;
      else return 0.86364; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99106;
      else if ( fabs(eta) < 1.4442 ) return 1.12071;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.83333;
      else return 0.88889; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02498;
      else if ( fabs(eta) < 1.4442 ) return 1.04918;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.98596;
      else return 0.96356; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02498;
      else if ( fabs(eta) < 1.4442 ) return 1.01474;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.04097;
      else return 0.99048; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.04618;
      else if ( fabs(eta) < 1.4442 ) return 0.95253;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.99605;
      else return 1.00000; }
}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|            MUON ID SCALE FACTOR SECTION             |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetMuonIdSF(double pt, double eta, std::string year, std::string shift){
  if      (year=="2016APV") return GetMuonIdSF2016APV(pt, eta, shift);
  else if (year=="2016") return GetMuonIdSF2017(pt, eta, shift);
  else if (year=="2017") return GetMuonIdSF2017(pt, eta, shift);
  else if (year=="2018") return GetMuonIdSF2018(pt, eta, shift);
  else return 0.;
}

double HardcodedConditions::GetMuonIdSF2016APV(double pt, double eta, std::string shift){
  if ( shift == "up" ){
    if ( pt < 20.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98911;
      else if ( fabs(eta) < 1.2 ) return 0.98401;
      else if ( fabs(eta) < 2.1 ) return 0.99062;
      else return 0.97894; }
    else if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99216;
      else if ( fabs(eta) < 1.2 ) return 0.98170;
      else if ( fabs(eta) < 2.1 ) return 0.99093;
      else return 0.97788; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99304;
      else if ( fabs(eta) < 1.2 ) return 0.98429;
      else if ( fabs(eta) < 2.1 ) return 0.99316;
      else return 0.98115; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99324;
      else if ( fabs(eta) < 1.2 ) return 0.98629;
      else if ( fabs(eta) < 2.1 ) return 0.99566;
      else return 0.98141; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99447;
      else if ( fabs(eta) < 1.2 ) return 0.98756;
      else if ( fabs(eta) < 2.1 ) return 0.99880;
      else return 0.98282; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98940;
      else if ( fabs(eta) < 1.2 ) return 0.98218;
      else if ( fabs(eta) < 2.1 ) return 0.99288;
      else return 0.97842; }
    else {
      if ( fabs(eta) < 0.9 ) return 0.98704;
      else if ( fabs(eta) < 1.2 ) return 0.98107;
      else if ( fabs(eta) < 2.1 ) return 0.99120;
      else return 0.97934; }
  }
  else if ( shift == "down" ){
    if ( pt < 20.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98640;
      else if ( fabs(eta) < 1.2 ) return 0.98059;
      else if ( fabs(eta) < 2.1 ) return 0.98784;
      else return 0.97107; }
    else if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98867;
      else if ( fabs(eta) < 1.2 ) return 0.97907;
      else if ( fabs(eta) < 2.1 ) return 0.98837;
      else return 0.97319; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98510;
      else if ( fabs(eta) < 1.2 ) return 0.97377;
      else if ( fabs(eta) < 2.1 ) return 0.98590;
      else return 0.97049; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98245;
      else if ( fabs(eta) < 1.2 ) return 0.97575;
      else if ( fabs(eta) < 2.1 ) return 0.98536;
      else return 0.96983; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98163;
      else if ( fabs(eta) < 1.2 ) return 0.97220;
      else if ( fabs(eta) < 2.1 ) return 0.98303;
      else return 0.96511; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98479;
      else if ( fabs(eta) < 1.2 ) return 0.97771;
      else if ( fabs(eta) < 2.1 ) return 0.98694;
      else return 0.96790; }
    else {
      if ( fabs(eta) < 0.9 ) return 0.98581;
      else if ( fabs(eta) < 1.2 ) return 0.97718;
      else if ( fabs(eta) < 2.1 ) return 0.98789;
      else return 0.95301; }
  }
  else {
    if ( pt < 20.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98775;
      else if ( fabs(eta) < 1.2 ) return 0.98230;
      else if ( fabs(eta) < 2.1 ) return 0.98923;
      else return 0.97500; }
    else if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99042;
      else if ( fabs(eta) < 1.2 ) return 0.98039;
      else if ( fabs(eta) < 2.1 ) return 0.98965;
      else return 0.97554; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98907;
      else if ( fabs(eta) < 1.2 ) return 0.97903;
      else if ( fabs(eta) < 2.1 ) return 0.98953;
      else return 0.97582; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98784;
      else if ( fabs(eta) < 1.2 ) return 0.98102;
      else if ( fabs(eta) < 2.1 ) return 0.99051;
      else return 0.97562; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98805;
      else if ( fabs(eta) < 1.2 ) return 0.97988;
      else if ( fabs(eta) < 2.1 ) return 0.99091;
      else return 0.97397; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98710;
      else if ( fabs(eta) < 1.2 ) return 0.97994;
      else if ( fabs(eta) < 2.1 ) return 0.98991;
      else return 0.97316; }
    else {
      if ( fabs(eta) < 0.9 ) return 0.98642;
      else if ( fabs(eta) < 1.2 ) return 0.97912;
      else if ( fabs(eta) < 2.1 ) return 0.98955;
      else return 0.96618; }	 
  }
}

double HardcodedConditions::GetMuonIdSF2016( double pt, double eta, std::string shift ){
  if ( shift == "up" ) {
    if ( pt < 20.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99425;
      else if ( fabs(eta) < 1.2 ) return 0.98408;
      else if ( fabs(eta) < 2.1 ) return 0.99544;
      else return 0.98279; }
    else if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99075;
      else if ( fabs(eta) < 1.2 ) return 0.98154;
      else if ( fabs(eta) < 2.1 ) return 0.99359;
      else return 0.98093; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99115;
      else if ( fabs(eta) < 1.2 ) return 0.98625;
      else if ( fabs(eta) < 2.1 ) return 0.99530;
      else return 0.98163; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98948;
      else if ( fabs(eta) < 1.2 ) return 0.98270;
      else if ( fabs(eta) < 2.1 ) return 0.99442;
      else return 0.98068; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98982;
      else if ( fabs(eta) < 1.2 ) return 0.98249;
      else if ( fabs(eta) < 2.1 ) return 0.99458;
      else return 0.98054; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98835;
      else if ( fabs(eta) < 1.2 ) return 0.98205;
      else if ( fabs(eta) < 2.1 ) return 0.99364;
      else return 0.97918; }
    else {
      if ( fabs(eta) < 0.9 ) return 0.98713;
      else if ( fabs(eta) < 1.2 ) return 0.98063;
      else if ( fabs(eta) < 2.1 ) return 0.99372;
      else return 0.98151; }
  }
  else if ( shift == "down" ) {
    if ( pt < 20.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98461;
      else if ( fabs(eta) < 1.2 ) return 0.97390;
      else if ( fabs(eta) < 2.1 ) return 0.98481;
      else return 0.96874; }
    else if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98450;
      else if ( fabs(eta) < 1.2 ) return 0.97162;
      else if ( fabs(eta) < 2.1 ) return 0.98531;
      else return 0.96968; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98469;
      else if ( fabs(eta) < 1.2 ) return 0.97677;
      else if ( fabs(eta) < 2.1 ) return 0.98664;
      else return 0.97057; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98351;
      else if ( fabs(eta) < 1.2 ) return 0.97474;
      else if ( fabs(eta) < 2.1 ) return 0.98658;
      else return 0.97119; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98363;
      else if ( fabs(eta) < 1.2 ) return 0.97600;
      else if ( fabs(eta) < 2.1 ) return 0.98846;
      else return 0.97229; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98199;
      else if ( fabs(eta) < 1.2 ) return 0.97601;
      else if ( fabs(eta) < 2.1 ) return 0.98761;
      else return 0.96484; }
    else {
      if ( fabs(eta) < 0.9 ) return 0.98213;
      else if ( fabs(eta) < 1.2 ) return 0.97602;
      else if ( fabs(eta) < 2.1 ) return 0.98727;
      else return 0.95759; }
  }
  else {
    if ( pt < 20.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98943;
      else if ( fabs(eta) < 1.2 ) return 0.97899;
      else if ( fabs(eta) < 2.1 ) return 0.99012;
      else return 0.97577; }
    else if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98763;
      else if ( fabs(eta) < 1.2 ) return 0.97658;
      else if ( fabs(eta) < 2.1 ) return 0.98945;
      else return 0.97531; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98792;
      else if ( fabs(eta) < 1.2 ) return 0.98151;
      else if ( fabs(eta) < 2.1 ) return 0.99097;
      else return 0.97610; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98650;
      else if ( fabs(eta) < 1.2 ) return 0.97872;
      else if ( fabs(eta) < 2.1 ) return 0.99050;
      else return 0.97594; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98673;
      else if ( fabs(eta) < 1.2 ) return 0.97925;
      else if ( fabs(eta) < 2.1 ) return 0.99152;
      else return 0.97642; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98517;
      else if ( fabs(eta) < 1.2 ) return 0.97903;
      else if ( fabs(eta) < 2.1 ) return 0.99063;
      else return 0.97201; }
    else {
      if ( fabs(eta) < 0.9 ) return 0.98463;
      else if ( fabs(eta) < 1.2 ) return 0.97832;
      else if ( fabs(eta) < 2.1 ) return 0.99049;
      else return 0.96955; } 
  }
}

double HardcodedConditions::GetMuonIdSF2017(double pt, double eta, std::string shift){
  if ( shift == "up" ){
    if ( pt < 20.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99016;
      else if ( fabs(eta) < 1.2 ) return 0.98611;
      else if ( fabs(eta) < 2.1 ) return 0.99158;
      else return 0.97473; }
    else if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99115;
      else if ( fabs(eta) < 1.2 ) return 0.98358;
      else if ( fabs(eta) < 2.1 ) return 0.99010;
      else return 0.97615; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98984;
      else if ( fabs(eta) < 1.2 ) return 0.98235;
      else if ( fabs(eta) < 2.1 ) return 0.99128;
      else return 0.97715; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98927;
      else if ( fabs(eta) < 1.2 ) return 0.98344;
      else if ( fabs(eta) < 2.1 ) return 0.99110;
      else return 0.97616; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98875;
      else if ( fabs(eta) < 1.2 ) return 0.98351;
      else if ( fabs(eta) < 2.1 ) return 0.99161;
      else return 0.97628; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98905;
      else if ( fabs(eta) < 1.2 ) return 0.98337;
      else if ( fabs(eta) < 2.1 ) return 0.99140;
      else return 0.97465; }
    else {
      if ( fabs(eta) < 0.9 ) return 0.98806;
      else if ( fabs(eta) < 1.2 ) return 0.98455;
      else if ( fabs(eta) < 2.1 ) return 0.99186;
      else return 0.97564; }
  }
  else if ( shift == "down" ) {
    if ( pt < 20.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98779;
      else if ( fabs(eta) < 1.2 ) return 0.98162;
      else if ( fabs(eta) < 2.1 ) return 0.98787;
      else return 0.97118; }
    else if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98918;
      else if ( fabs(eta) < 1.2 ) return 0.98054;
      else if ( fabs(eta) < 2.1 ) return 0.98873;
      else return 0.97197; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98906;
      else if ( fabs(eta) < 1.2 ) return 0.98090;
      else if ( fabs(eta) < 2.1 ) return 0.99034;
      else return 0.97491; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98885;
      else if ( fabs(eta) < 1.2 ) return 0.98192;
      else if ( fabs(eta) < 2.1 ) return 0.99073;
      else return 0.97451; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98839;
      else if ( fabs(eta) < 1.2 ) return 0.98291;
      else if ( fabs(eta) < 2.1 ) return 0.99111;
      else return 0.97424; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98730;
      else if ( fabs(eta) < 1.2 ) return 0.98143;
      else if ( fabs(eta) < 2.1 ) return 0.98885;
      else return 0.96607; }
    else {
      if ( fabs(eta) < 0.9 ) return 0.98627;
      else if ( fabs(eta) < 1.2 ) return 0.98085;
      else if ( fabs(eta) < 2.1 ) return 0.98685;
      else return 0.95988; }
  }
  else {
    if ( pt < 20.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98897;
      else if ( fabs(eta) < 1.2 ) return 0.98387;
      else if ( fabs(eta) < 2.1 ) return 0.98973;
      else return 0.97296; }
    else if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99016;
      else if ( fabs(eta) < 1.2 ) return 0.98206;
      else if ( fabs(eta) < 2.1 ) return 0.98942;
      else return 0.97406; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98945;
      else if ( fabs(eta) < 1.2 ) return 0.98163;
      else if ( fabs(eta) < 2.1 ) return 0.99081;
      else return 0.97603; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98906;
      else if ( fabs(eta) < 1.2 ) return 0.98268;
      else if ( fabs(eta) < 2.1 ) return 0.99092;
      else return 0.97534; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98857;
      else if ( fabs(eta) < 1.2 ) return 0.98321;
      else if ( fabs(eta) < 2.1 ) return 0.99136;
      else return 0.97526; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.98817;
      else if ( fabs(eta) < 1.2 ) return 0.98240;
      else if ( fabs(eta) < 2.1 ) return 0.99013;
      else return 0.97036; }
    else {
      if ( fabs(eta) < 0.9 ) return 0.98716;
      else if ( fabs(eta) < 1.2 ) return 0.98270;
      else if ( fabs(eta) < 2.1 ) return 0.98935;
      else return 0.96776; }
  }
}

double HardcodedConditions::GetMuonIdSF2018(double pt, double eta, std::string shift){
  if ( shift == "up" ) {
    if ( pt < 20.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99276;
      else if ( fabs(eta) < 1.2 ) return 0.98563;
      else if ( fabs(eta) < 2.1 ) return 0.99095;
      else return 0.97787; }
    else if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99388;
      else if ( fabs(eta) < 1.2 ) return 0.98420;
      else if ( fabs(eta) < 2.1 ) return 0.99066;
      else return 0.97438; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99296;
      else if ( fabs(eta) < 1.2 ) return 0.98418;
      else if ( fabs(eta) < 2.1 ) return 0.99027;
      else return 0.97376; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99250;
      else if ( fabs(eta) < 1.2 ) return 0.98463;
      else if ( fabs(eta) < 2.1 ) return 0.99033;
      else return 0.97247; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99224;
      else if ( fabs(eta) < 1.2 ) return 0.98437;
      else if ( fabs(eta) < 2.1 ) return 0.99071;
      else return 0.97334; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99244;
      else if ( fabs(eta) < 1.2 ) return 0.98409;
      else if ( fabs(eta) < 2.1 ) return 0.99080;
      else return 0.97171; }
    else {
      if ( fabs(eta) < 0.9 ) return 0.99150;
      else if ( fabs(eta) < 1.2 ) return 0.98308;
      else if ( fabs(eta) < 2.1 ) return 0.98983;
      else return 0.97194; }
  }
  else if ( shift == "down" ) {
    if ( pt < 20.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99042;
      else if ( fabs(eta) < 1.2 ) return 0.98302;
      else if ( fabs(eta) < 2.1 ) return 0.98909;
      else return 0.97208; }
    else if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99290;
      else if ( fabs(eta) < 1.2 ) return 0.98218;
      else if ( fabs(eta) < 2.1 ) return 0.98933;
      else return 0.97040; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99205;
      else if ( fabs(eta) < 1.2 ) return 0.98197;
      else if ( fabs(eta) < 2.1 ) return 0.98936;
      else return 0.97235; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99216;
      else if ( fabs(eta) < 1.2 ) return 0.98410;
      else if ( fabs(eta) < 2.1 ) return 0.98966;
      else return 0.97113; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99165;
      else if ( fabs(eta) < 1.2 ) return 0.98362;
      else if ( fabs(eta) < 2.1 ) return 0.99007;
      else return 0.97121; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99058;
      else if ( fabs(eta) < 1.2 ) return 0.98225;
      else if ( fabs(eta) < 2.1 ) return 0.98868;
      else return 0.96489; }
    else {
      if ( fabs(eta) < 0.9 ) return 0.99052;
      else if ( fabs(eta) < 1.2 ) return 0.98160;
      else if ( fabs(eta) < 2.1 ) return 0.98750;
      else return 0.96003; }
  }
  else {
    if ( pt < 20.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99159;
      else if ( fabs(eta) < 1.2 ) return 0.98433;
      else if ( fabs(eta) < 2.1 ) return 0.99002;
      else return 0.97497; }
    else if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99339;
      else if ( fabs(eta) < 1.2 ) return 0.98319;
      else if ( fabs(eta) < 2.1 ) return 0.99000;
      else return 0.97239; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99251;
      else if ( fabs(eta) < 1.2 ) return 0.98308;
      else if ( fabs(eta) < 2.1 ) return 0.98982;
      else return 0.97306; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99233;
      else if ( fabs(eta) < 1.2 ) return 0.98436;
      else if ( fabs(eta) < 2.1 ) return 0.99000;
      else return 0.97180; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99195;
      else if ( fabs(eta) < 1.2 ) return 0.98399;
      else if ( fabs(eta) < 2.1 ) return 0.99039;
      else return 0.97227; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.9 ) return 0.99151;
      else if ( fabs(eta) < 1.2 ) return 0.98317;
      else if ( fabs(eta) < 2.1 ) return 0.98974;
      else return 0.96830; }
    else {
      if ( fabs(eta) < 0.9 ) return 0.99101;
      else if ( fabs(eta) < 1.2 ) return 0.98234;
      else if ( fabs(eta) < 2.1 ) return 0.98867;
      else return 0.96598; }
  }
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|            MUON ISO SCALE FACTOR SECTION            |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetMuonIsoSF(double pt, double eta, std::string year)
{
  //The main getter for Muon Iso Scale Factors
  if      (year=="2016APV") return GetMuonIsoSF2016APV(pt, eta);
  else if (year=="2016") return GetMuonIsoSF2017(pt, eta);
  else if (year=="2017") return GetMuonIsoSF2017(pt, eta);
  else if (year=="2018") return GetMuonIsoSF2018(pt, eta);
  else return 0.;
} //end GetMuonIsoSF

double HardcodedConditions::GetMuonIsoSF2016APV(double pt, double eta){
  if( pt < 30 ){
    if( fabs(eta) < 0.9 ) return 0.991;
    else if( fabs(eta) < 1.2 ) return 0.996;
    else if( fabs(eta) < 2.1 ) return 0.995;
    else return 0.995;
  }
  else if( pt < 40 ){
    if( fabs(eta) < 0.9 ) return 0.997;
    else if( fabs(eta) < 1.2 ) return 0.999;
    else if( fabs(eta) < 2.1 ) return 0.999;
    else return 1.001;
  }
  else if( pt < 50 ){
    if( fabs(eta) < 0.9 ) return 0.998;
    else if( fabs(eta) < 1.2 ) return 0.998;
    else if( fabs(eta) < 2.1 ) return 0.999;
    else return 1.000;
  }
  else if( pt < 60 ){
    if( fabs(eta) < 0.9 ) return 0.999;
    else if( fabs(eta) < 1.2 ) return 0.999;
    else if( fabs(eta) < 2.1 ) return 1.000;
    else return 1.000;
  }
  else {
    if( fabs(eta) < 0.9 ) return 0.999;
    else if( fabs(eta) < 1.2 ) return 1.000;
    else if( fabs(eta) < 2.1 ) return 1.000;
    else return 0.999;
  }
}
  
double HardcodedConditions::GetMuonIsoSF2016(double pt, double eta){
  if( pt < 30 ){
    if( fabs(eta) < 0.9 ) return 0.985;
    else if( fabs(eta) < 1.2 ) return 0.990;
    else if( fabs(eta) < 2.1 ) return 0.993;
    else return 1.000;
  }
  else if( pt < 40 ){
    if( fabs(eta) < 0.9 ) return 0.995;
    else if( fabs(eta) < 1.2 ) return 0.997;
    else if( fabs(eta) < 2.1 ) return 0.999;
    else return 1.000;
  }
  else if( pt < 50 ){
    if( fabs(eta) < 0.9 ) return 0.997;
    else if( fabs(eta) < 1.2 ) return 0.998;
    else if( fabs(eta) < 2.1 ) return 0.998;
    else return 1.000;
  }
  else if( pt < 60 ){
    if( fabs(eta) < 0.9 ) return 0.998;
    else if( fabs(eta) < 1.2 ) return 0.998;
    else if( fabs(eta) < 2.1 ) return 0.998;
    else return 1.001;
  }
  else {
    if( fabs(eta) < 0.9 ) return 1.000;
    else if( fabs(eta) < 1.2 ) return 0.999;
    else if( fabs(eta) < 2.1 ) return 1.000;
    else return 1.001;
  }
}

double HardcodedConditions::GetMuonIsoSF2017(double pt, double eta){
  if( pt < 30 ){
    if( fabs(eta) < 0.9 ) return 0.992;
    else if( fabs(eta) < 1.2 ) return 0.991;
    else if( fabs(eta) < 2.1 ) return 1.001;
    else return 1.004;
  }
  else if( pt < 40 ){
    if( fabs(eta) < 0.9 ) return 0.996;
    else if( fabs(eta) < 1.2 ) return 0.998;
    else if( fabs(eta) < 2.1 ) return 1.001;
    else return 1.002;
  }
  else if( pt < 50 ){
    if( fabs(eta) < 0.9 ) return 0.998;
    else if( fabs(eta) < 1.2 ) return 0.998;
    else if( fabs(eta) < 2.1 ) return 1.000;
    else return 1.001;
  }
  else if( pt < 60 ){
    if( fabs(eta) < 0.9 ) return 0.998;
    else if( fabs(eta) < 1.2 ) return 0.999;
    else if( fabs(eta) < 2.1 ) return 0.999;
    else return 1.000;
  }
  else {
    if( fabs(eta) < 0.9 ) return 0.999;
    else if( fabs(eta) < 1.2 ) return 1.000;
    else if( fabs(eta) < 2.1 ) return 1.000;
    else return 1.000;
  }
}

double HardcodedConditions::GetMuonIsoSF2018(double pt, double eta){
  if( pt < 30 ){
    if( fabs(eta) < 0.9 ) return 0.990;
    else if( fabs(eta) < 1.2 ) return 0.982;
    else if( fabs(eta) < 2.1 ) return 0.998;
    else return 1.001;
  }
  else if( pt < 40 ){
    if( fabs(eta) < 0.9 ) return 0.996;
    else if( fabs(eta) < 1.2 ) return 0.994;
    else if( fabs(eta) < 2.1 ) return 0.999;
    else return 1.001;
  }
  else if( pt < 50 ){
    if( fabs(eta) < 0.9 ) return 0.997;
    else if( fabs(eta) < 1.2 ) return 0.996;
    else if( fabs(eta) < 2.1 ) return 0.999;
    else return 1.001;
  }
  else if( pt < 60 ){
    if( fabs(eta) < 0.9 ) return 0.998;
    else if( fabs(eta) < 1.2 ) return 0.998;
    else if( fabs(eta) < 2.1 ) return 0.999;
    else return 1.001;
  }
  else{
    if( fabs(eta) < 0.9 ) return 0.999;
    else if( fabs(eta) < 1.2 ) return 0.999;
    else if( fabs(eta) < 2.1 ) return 0.999;
    else return 1.003;
  }
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|          MUON TRIGGER SCALE FACTOR SECTION          |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/
// https://gitlab.cern.ch/cms-nanoAOD/jsonpog-integration/-/tree/master/POG/MUO
// using correctionlib to extract SF
double HardcodedConditions::GetMuonTriggerSF(double pt, double eta, std::string year){
  //The main getter for Muon Trigger Scale Factors
  if      (year=="2016APV") return GetMuonTriggerSF2016APV(pt, eta);
  else if (year=="2016") return GetMuonTriggerSF2016(pt, eta);
  else if (year=="2017") return GetMuonTriggerSF2017(pt, eta);
  else if (year=="2018") return GetMuonTriggerSF2018(pt, eta);
  else return 0.;
}//end GetMuonTriggerSF

// using MUON JSON UL SF with WP: NUM_IsoMu24_or_IsoTkMu24_DEN_CutBasedIdTight_and_PFIsoTight
double HardcodedConditions::GetMuonTriggerSF2016APV(double pt, double eta){
  if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.96304;
    else if ( fabs(eta) < 1.2 ) return 0.95867;
    else if ( fabs(eta) < 2.1 ) return 0.98648;
    else return 0.92194; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97151;
    else if ( fabs(eta) < 1.2 ) return 0.96745;
    else if ( fabs(eta) < 2.1 ) return 0.99701;
    else return 0.95287; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97505;
    else if ( fabs(eta) < 1.2 ) return 0.97089;
    else if ( fabs(eta) < 2.1 ) return 1.00065;
    else return 0.96409; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97619;
    else if ( fabs(eta) < 1.2 ) return 0.97171;
    else if ( fabs(eta) < 2.1 ) return 1.00216;
    else return 0.96804; }
  else if ( pt < 120.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97734;
    else if ( fabs(eta) < 1.2 ) return 0.96963;
    else if ( fabs(eta) < 2.1 ) return 0.99902;
    else return 0.97116; }
  else {
    if ( fabs(eta) < 0.9 ) return 0.97600;
    else if ( fabs(eta) < 1.2 ) return 0.96280;
    else if ( fabs(eta) < 2.1 ) return 1.00112;
    else return 0.95996; }
}

// using MUON JSON UL SF with WP: NUM_IsoMu24_or_IsoTkMu24_DEN_CutBasedIdTight_and_PFIsoTight
double HardcodedConditions::GetMuonTriggerSF2016(double pt, double eta){
  if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.94981;
    else if ( fabs(eta) < 1.2 ) return 0.94617;
    else if ( fabs(eta) < 2.1 ) return 0.98561;
    else return 0.90565; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.95993;
    else if ( fabs(eta) < 1.2 ) return 0.95966;
    else if ( fabs(eta) < 2.1 ) return 0.99415;
    else return 0.94966; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.96273;
    else if ( fabs(eta) < 1.2 ) return 0.96311;
    else if ( fabs(eta) < 2.1 ) return 0.99637;
    else return 0.96072; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.96474;
    else if ( fabs(eta) < 1.2 ) return 0.96335;
    else if ( fabs(eta) < 2.1 ) return 0.99502;
    else return 0.95925; }
  else if ( pt < 120.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.96407;
    else if ( fabs(eta) < 1.2 ) return 0.96285;
    else if ( fabs(eta) < 2.1 ) return 0.98877;
    else return 0.96697; }
  else {
    if ( fabs(eta) < 0.9 ) return 0.96328;
    else if ( fabs(eta) < 1.2 ) return 0.95071;
    else if ( fabs(eta) < 2.1 ) return 0.98591;
    else return 0.96208; }
}

// using MUON JSON UL SF with WP: NUM_IsoMu27_DEN_CutBasedIdTight_and_PFIsoTight
double HardcodedConditions::GetMuonTriggerSF2017(double pt, double eta){
  if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97173;
    else if ( fabs(eta) < 1.2 ) return 0.95179;
    else if ( fabs(eta) < 2.1 ) return 1.00589;
    else return 0.86627; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97484;
    else if ( fabs(eta) < 1.2 ) return 0.95464;
    else if ( fabs(eta) < 2.1 ) return 1.01759;
    else return 0.93978; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97441;
    else if ( fabs(eta) < 1.2 ) return 0.95416;
    else if ( fabs(eta) < 2.1 ) return 1.01677;
    else return 0.98320; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97321;
    else if ( fabs(eta) < 1.2 ) return 0.95311;
    else if ( fabs(eta) < 2.1 ) return 1.01198;
    else return 1.00329; }
  else if ( pt < 120.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97238;
    else if ( fabs(eta) < 1.2 ) return 0.94726;
    else if ( fabs(eta) < 2.1 ) return 1.00865;
    else return 1.00746; }
  else {
    if ( fabs(eta) < 0.9 ) return 0.96768;
    else if ( fabs(eta) < 1.2 ) return 0.93446;
    else if ( fabs(eta) < 2.1 ) return 1.00028;
    else return 1.03201; }
}

// using MUON JSON UL SF with WP: NUM_IsoMu24_DEN_CutBasedIdTight_and_PFIsoTight
double HardcodedConditions::GetMuonTriggerSF2018(double pt, double eta){
  if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97309;
    else if ( fabs(eta) < 1.2 ) return 0.95852;
    else if ( fabs(eta) < 2.1 ) return 1.00619;
    else return 0.97231; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97912;
    else if ( fabs(eta) < 1.2 ) return 0.97097;
    else if ( fabs(eta) < 2.1 ) return 1.00731;
    else return 0.99586; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97978;
    else if ( fabs(eta) < 1.2 ) return 0.97359;
    else if ( fabs(eta) < 2.1 ) return 1.00545;
    else return 1.00743; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97939;
    else if ( fabs(eta) < 1.2 ) return 0.97318;
    else if ( fabs(eta) < 2.1 ) return 1.00363;
    else return 1.00544; }
  else if ( pt < 120.0 ) {
    if ( fabs(eta) < 0.9 ) return 0.97904;
    else if ( fabs(eta) < 1.2 ) return 0.96896;
    else if ( fabs(eta) < 2.1 ) return 1.00097;
    else return 1.00952; }
  else {
    if ( fabs(eta) < 0.9 ) return 0.97782;
    else if ( fabs(eta) < 1.2 ) return 0.96836;
    else if ( fabs(eta) < 2.1 ) return 1.00110;
    else return 1.01257; }
}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|         HADRON TRIGGER SCALE FACTOR SECTION         |\  | |/|
 | `---' |                  (For Muon Channel)                 | `---' |
 |       |                                                     |       |
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetIsMHadronTriggerSF(double njets, double ht, std::string year){
  if      (year=="2016APV") return GetIsMHadronTriggerSF2016APV(njets, ht);
  else if (year=="2016") return GetIsMHadronTriggerSF2017(njets, ht);
  else if (year=="2017") return GetIsMHadronTriggerSF2017(njets, ht);
  else if (year=="2018") return GetIsMHadronTriggerSF2018(njets, ht);
  else return 0.;
}

double HardcodedConditions::GetIsMHadronTriggerSF2016APV(double njets, double ht){
  return 1.0;
}

double HardcodedConditions::GetIsMHadronTriggerSF2016(double njets, double ht){
  return 1.0;
}

double HardcodedConditions::GetIsMHadronTriggerSF2017(double njets, double ht){
  return 1.0;
}

double HardcodedConditions::GetIsMHadronTriggerSF2018(double njets, double ht){
  return 1.0;
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|         MUON X-TRIGGER SCALE FACTOR SECTION         |\  | |/|
 | `---' |                    (from Nikos)                     | `---' |
 |       |                                                     |       |
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

double HardcodedConditions::GetMuonTriggerXSF(double ht, double pt, double eta, std::string year){
  if      (year=="2016APV") return GetMuonTriggerXSF2016APV(ht, pt, eta);
  else if (year=="2016") return GetMuonTriggerXSF2016(ht, pt, eta);
  else if (year=="2017") return GetMuonTriggerXSF2017(ht, pt, eta);
  else if (year=="2018") return GetMuonTriggerXSF2018(ht, pt, eta);
  else return 0. ;
}

double HardcodedConditions::GetMuonTriggerXSF2016APV(double ht, double pt, double eta){
if ( ht < 400.0 ) {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.17929;
    else if ( fabs(eta) < 1.4442 ) return 1.18746;
    else if ( fabs(eta) < 1.5660 ) return 1.16135;
    else if ( fabs(eta) < 2.0000 ) return 1.21261;
    else return 1.16675; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99748;
    else if ( fabs(eta) < 1.4442 ) return 0.98843;
    else if ( fabs(eta) < 1.5660 ) return 0.99938;
    else if ( fabs(eta) < 2.0000 ) return 0.97847;
    else return 0.98717; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99710;
    else if ( fabs(eta) < 1.4442 ) return 0.98576;
    else if ( fabs(eta) < 1.5660 ) return 0.97813;
    else if ( fabs(eta) < 2.0000 ) return 0.98136;
    else return 0.98910; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99597;
    else if ( fabs(eta) < 1.4442 ) return 0.99011;
    else if ( fabs(eta) < 1.5660 ) return 0.98932;
    else if ( fabs(eta) < 2.0000 ) return 0.98000;
    else return 0.98302; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99154;
    else if ( fabs(eta) < 1.4442 ) return 0.98657;
    else if ( fabs(eta) < 1.5660 ) return 1.00086;
    else if ( fabs(eta) < 2.0000 ) return 0.96684;
    else return 0.95657; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99615;
    else if ( fabs(eta) < 1.4442 ) return 1.00008;
    else if ( fabs(eta) < 1.5660 ) return 0.99121;
    else if ( fabs(eta) < 2.0000 ) return 0.98410;
    else return 0.97373; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00060;
    else if ( fabs(eta) < 1.4442 ) return 1.00180;
    else if ( fabs(eta) < 1.5660 ) return 1.00927;
    else if ( fabs(eta) < 2.0000 ) return 0.99691;
    else return 0.99131; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00337;
    else if ( fabs(eta) < 1.4442 ) return 0.99856;
    else if ( fabs(eta) < 1.5660 ) return 1.00020;
    else if ( fabs(eta) < 2.0000 ) return 0.99036;
    else return 0.99107; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00314;
    else if ( fabs(eta) < 1.4442 ) return 0.99973;
    else if ( fabs(eta) < 1.5660 ) return 0.98042;
    else if ( fabs(eta) < 2.0000 ) return 0.99478;
    else return 0.98717; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00040;
    else if ( fabs(eta) < 1.4442 ) return 0.99805;
    else if ( fabs(eta) < 1.5660 ) return 0.97155;
    else if ( fabs(eta) < 2.0000 ) return 0.99244;
    else return 1.00736; }
  else {
    if ( fabs(eta) < 0.8000 ) return 1.00255;
    else if ( fabs(eta) < 1.4442 ) return 0.98895;
    else if ( fabs(eta) < 1.5660 ) return 0.94276;
    else if ( fabs(eta) < 2.0000 ) return 0.97590;
    else return 0.95455; }
else if ( ht < 500.0 ) {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.91125;
    else if ( fabs(eta) < 1.4442 ) return 0.91255;
    else if ( fabs(eta) < 1.5660 ) return 0.91320;
    else if ( fabs(eta) < 2.0000 ) return 0.91096;
    else return 0.92580; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.97762;
    else if ( fabs(eta) < 1.4442 ) return 0.96612;
    else if ( fabs(eta) < 1.5660 ) return 0.94374;
    else if ( fabs(eta) < 2.0000 ) return 0.95951;
    else return 0.94608; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98820;
    else if ( fabs(eta) < 1.4442 ) return 0.97780;
    else if ( fabs(eta) < 1.5660 ) return 0.96131;
    else if ( fabs(eta) < 2.0000 ) return 0.97193;
    else return 0.95789; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99043;
    else if ( fabs(eta) < 1.4442 ) return 0.98575;
    else if ( fabs(eta) < 1.5660 ) return 0.99037;
    else if ( fabs(eta) < 2.0000 ) return 0.97290;
    else return 0.95879; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98817;
    else if ( fabs(eta) < 1.4442 ) return 0.99129;
    else if ( fabs(eta) < 1.5660 ) return 0.99565;
    else if ( fabs(eta) < 2.0000 ) return 0.97798;
    else return 0.99394; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98908;
    else if ( fabs(eta) < 1.4442 ) return 0.98509;
    else if ( fabs(eta) < 1.5660 ) return 0.96883;
    else if ( fabs(eta) < 2.0000 ) return 0.98684;
    else return 0.96377; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00561;
    else if ( fabs(eta) < 1.4442 ) return 0.99634;
    else if ( fabs(eta) < 1.5660 ) return 1.00060;
    else if ( fabs(eta) < 2.0000 ) return 0.99926;
    else return 1.00209; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00175;
    else if ( fabs(eta) < 1.4442 ) return 0.99872;
    else if ( fabs(eta) < 1.5660 ) return 0.99259;
    else if ( fabs(eta) < 2.0000 ) return 0.99666;
    else return 0.99391; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00442;
    else if ( fabs(eta) < 1.4442 ) return 0.99628;
    else if ( fabs(eta) < 1.5660 ) return 0.99172;
    else if ( fabs(eta) < 2.0000 ) return 1.00216;
    else return 0.99298; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00358;
    else if ( fabs(eta) < 1.4442 ) return 0.99523;
    else if ( fabs(eta) < 1.5660 ) return 0.99121;
    else if ( fabs(eta) < 2.0000 ) return 1.00305;
    else return 0.99371; }
  else {
    if ( fabs(eta) < 0.8000 ) return 1.00928;
    else if ( fabs(eta) < 1.4442 ) return 0.98815;
    else if ( fabs(eta) < 1.5660 ) return 0.99225;
    else if ( fabs(eta) < 2.0000 ) return 0.99373;
    else return 0.96541; }
else if ( ht < 1000.0 ) {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.88491;
    else if ( fabs(eta) < 1.4442 ) return 0.89026;
    else if ( fabs(eta) < 1.5660 ) return 0.88856;
    else if ( fabs(eta) < 2.0000 ) return 0.86792;
    else return 0.88780; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.97558;
    else if ( fabs(eta) < 1.4442 ) return 0.97043;
    else if ( fabs(eta) < 1.5660 ) return 0.95654;
    else if ( fabs(eta) < 2.0000 ) return 0.96625;
    else return 0.95139; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99046;
    else if ( fabs(eta) < 1.4442 ) return 0.97513;
    else if ( fabs(eta) < 1.5660 ) return 0.98943;
    else if ( fabs(eta) < 2.0000 ) return 0.97154;
    else return 0.96690; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98451;
    else if ( fabs(eta) < 1.4442 ) return 0.98621;
    else if ( fabs(eta) < 1.5660 ) return 0.96114;
    else if ( fabs(eta) < 2.0000 ) return 0.99016;
    else return 0.97817; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99097;
    else if ( fabs(eta) < 1.4442 ) return 0.98258;
    else if ( fabs(eta) < 1.5660 ) return 0.98063;
    else if ( fabs(eta) < 2.0000 ) return 0.98361;
    else return 0.97679; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.99406;
    else if ( fabs(eta) < 1.4442 ) return 0.99066;
    else if ( fabs(eta) < 1.5660 ) return 0.97292;
    else if ( fabs(eta) < 2.0000 ) return 0.98449;
    else return 0.96912; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00524;
    else if ( fabs(eta) < 1.4442 ) return 1.00168;
    else if ( fabs(eta) < 1.5660 ) return 1.00363;
    else if ( fabs(eta) < 2.0000 ) return 1.00670;
    else return 0.99124; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00478;
    else if ( fabs(eta) < 1.4442 ) return 0.99890;
    else if ( fabs(eta) < 1.5660 ) return 0.99429;
    else if ( fabs(eta) < 2.0000 ) return 0.98986;
    else return 0.98963; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00556;
      else if ( fabs(eta) < 1.4442 ) return 1.00308;
      else if ( fabs(eta) < 1.5660 ) return 1.00788;
      else if ( fabs(eta) < 2.0000 ) return 1.00181;
      else return 0.99747; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00561;
      else if ( fabs(eta) < 1.4442 ) return 0.99898;
      else if ( fabs(eta) < 1.5660 ) return 0.99049;
      else if ( fabs(eta) < 2.0000 ) return 0.99377;
      else return 0.99508; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.00588;
      else if ( fabs(eta) < 1.4442 ) return 0.99978;
      else if ( fabs(eta) < 1.5660 ) return 0.99133;
      else if ( fabs(eta) < 2.0000 ) return 0.99216;
      else return 1.00938; }
  else if ( ht < 2000.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.83789;
      else if ( fabs(eta) < 1.4442 ) return 0.86871;
      else if ( fabs(eta) < 1.5660 ) return 0.87692;
      else if ( fabs(eta) < 2.0000 ) return 0.92593;
      else return 0.92023; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.96761;
      else if ( fabs(eta) < 1.4442 ) return 0.99011;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.94782;
      else return 0.98147; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99576;
      else if ( fabs(eta) < 1.4442 ) return 0.99294;
      else if ( fabs(eta) < 1.5660 ) return 1.01608;
      else if ( fabs(eta) < 2.0000 ) return 0.98259;
      else return 0.96875; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99139;
      else if ( fabs(eta) < 1.4442 ) return 0.98666;
      else if ( fabs(eta) < 1.5660 ) return 1.01724;
      else if ( fabs(eta) < 2.0000 ) return 1.02600;
      else return 0.98056; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00075;
      else if ( fabs(eta) < 1.4442 ) return 0.99972;
      else if ( fabs(eta) < 1.5660 ) return 0.90625;
      else if ( fabs(eta) < 2.0000 ) return 0.99905;
      else return 0.94971; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00153;
      else if ( fabs(eta) < 1.4442 ) return 1.01778;
      else if ( fabs(eta) < 1.5660 ) return 0.88000;
      else if ( fabs(eta) < 2.0000 ) return 1.01498;
      else return 0.98969; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00936;
      else if ( fabs(eta) < 1.4442 ) return 1.00921;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.98593;
      else return 1.00727; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01070;
      else if ( fabs(eta) < 1.4442 ) return 1.00312;
      else if ( fabs(eta) < 1.5660 ) return 1.01818;
      else if ( fabs(eta) < 2.0000 ) return 0.99262;
      else return 0.99897; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01238;
      else if ( fabs(eta) < 1.4442 ) return 1.00034;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00821;
      else return 0.99306; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00639;
      else if ( fabs(eta) < 1.4442 ) return 1.00385;
      else if ( fabs(eta) < 1.5660 ) return 0.98560;
      else if ( fabs(eta) < 2.0000 ) return 0.99337;
      else return 0.99538; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.00155;
      else if ( fabs(eta) < 1.4442 ) return 0.99354;
      else if ( fabs(eta) < 1.5660 ) return 0.97959;
      else if ( fabs(eta) < 2.0000 ) return 1.00106;
      else return 1.00000; }
  else {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.10000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.33333;
      else return 1.00000; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05263;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return inf; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return inf;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return inf; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.97500;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02463;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.01709;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.14286;
      else return 1.00000; }
}

double HardcodedConditions::GetMuonTriggerXSF2016(double ht, double pt, double eta){
  if ( ht < 400.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.43526;
      else if ( fabs(eta) < 1.4442 ) return 1.39205;
      else if ( fabs(eta) < 1.5660 ) return 1.37358;
      else if ( fabs(eta) < 2.0000 ) return 1.34922;
      else return 1.36196; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03154;
      else if ( fabs(eta) < 1.4442 ) return 1.03554;
      else if ( fabs(eta) < 1.5660 ) return 1.03026;
      else if ( fabs(eta) < 2.0000 ) return 1.05029;
      else return 1.05383; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01882;
      else if ( fabs(eta) < 1.4442 ) return 1.01950;
      else if ( fabs(eta) < 1.5660 ) return 1.04538;
      else if ( fabs(eta) < 2.0000 ) return 1.04286;
      else return 1.04620; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01353;
      else if ( fabs(eta) < 1.4442 ) return 1.01069;
      else if ( fabs(eta) < 1.5660 ) return 1.01983;
      else if ( fabs(eta) < 2.0000 ) return 1.03215;
      else return 1.03244; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01210;
      else if ( fabs(eta) < 1.4442 ) return 1.01351;
      else if ( fabs(eta) < 1.5660 ) return 1.02174;
      else if ( fabs(eta) < 2.0000 ) return 1.02746;
      else return 1.01845; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01086;
      else if ( fabs(eta) < 1.4442 ) return 1.01146;
      else if ( fabs(eta) < 1.5660 ) return 1.00811;
      else if ( fabs(eta) < 2.0000 ) return 1.02314;
      else return 1.01359; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00609;
      else if ( fabs(eta) < 1.4442 ) return 1.00681;
      else if ( fabs(eta) < 1.5660 ) return 1.00998;
      else if ( fabs(eta) < 2.0000 ) return 1.01400;
      else return 1.01266; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00485;
      else if ( fabs(eta) < 1.4442 ) return 1.00471;
      else if ( fabs(eta) < 1.5660 ) return 1.00331;
      else if ( fabs(eta) < 2.0000 ) return 1.01442;
      else return 1.00979; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00612;
      else if ( fabs(eta) < 1.4442 ) return 1.00471;
      else if ( fabs(eta) < 1.5660 ) return 1.01779;
      else if ( fabs(eta) < 2.0000 ) return 1.01112;
      else return 1.01129; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00546;
      else if ( fabs(eta) < 1.4442 ) return 1.00445;
      else if ( fabs(eta) < 1.5660 ) return 1.01176;
      else if ( fabs(eta) < 2.0000 ) return 1.01398;
      else return 1.01116; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.00627;
      else if ( fabs(eta) < 1.4442 ) return 1.00455;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.02439;
      else return 1.00000; }
  else if ( ht < 500.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03608;
      else if ( fabs(eta) < 1.4442 ) return 1.04160;
      else if ( fabs(eta) < 1.5660 ) return 1.03761;
      else if ( fabs(eta) < 2.0000 ) return 1.04516;
      else return 1.04617; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00608;
      else if ( fabs(eta) < 1.4442 ) return 1.00628;
      else if ( fabs(eta) < 1.5660 ) return 1.00441;
      else if ( fabs(eta) < 2.0000 ) return 1.01933;
      else return 1.01302; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00522;
      else if ( fabs(eta) < 1.4442 ) return 1.00798;
      else if ( fabs(eta) < 1.5660 ) return 1.01200;
      else if ( fabs(eta) < 2.0000 ) return 1.01823;
      else return 1.01300; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00563;
      else if ( fabs(eta) < 1.4442 ) return 1.00638;
      else if ( fabs(eta) < 1.5660 ) return 1.00700;
      else if ( fabs(eta) < 2.0000 ) return 1.01664;
      else return 1.01264; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00399;
      else if ( fabs(eta) < 1.4442 ) return 1.00739;
      else if ( fabs(eta) < 1.5660 ) return 1.00396;
      else if ( fabs(eta) < 2.0000 ) return 1.01452;
      else return 1.01250; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00626;
      else if ( fabs(eta) < 1.4442 ) return 1.00554;
      else if ( fabs(eta) < 1.5660 ) return 1.00885;
      else if ( fabs(eta) < 2.0000 ) return 1.01467;
      else return 1.00851; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00665;
      else if ( fabs(eta) < 1.4442 ) return 1.00576;
      else if ( fabs(eta) < 1.5660 ) return 1.00796;
      else if ( fabs(eta) < 2.0000 ) return 1.01809;
      else return 1.00913; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00739;
      else if ( fabs(eta) < 1.4442 ) return 1.00524;
      else if ( fabs(eta) < 1.5660 ) return 1.00845;
      else if ( fabs(eta) < 2.0000 ) return 1.01822;
      else return 1.00692; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00576;
      else if ( fabs(eta) < 1.4442 ) return 1.00623;
      else if ( fabs(eta) < 1.5660 ) return 1.00520;
      else if ( fabs(eta) < 2.0000 ) return 1.01139;
      else return 1.01099; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00675;
      else if ( fabs(eta) < 1.4442 ) return 1.00655;
      else if ( fabs(eta) < 1.5660 ) return 1.00814;
      else if ( fabs(eta) < 2.0000 ) return 1.01411;
      else return 1.01053; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.00719;
      else if ( fabs(eta) < 1.4442 ) return 1.00791;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.01242;
      else return 1.00775; }
  else if ( ht < 1000.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00644;
      else if ( fabs(eta) < 1.4442 ) return 1.01048;
      else if ( fabs(eta) < 1.5660 ) return 1.01466;
      else if ( fabs(eta) < 2.0000 ) return 1.02089;
      else return 1.01691; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00651;
      else if ( fabs(eta) < 1.4442 ) return 1.00755;
      else if ( fabs(eta) < 1.5660 ) return 1.01798;
      else if ( fabs(eta) < 2.0000 ) return 1.01952;
      else return 1.02018; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00606;
      else if ( fabs(eta) < 1.4442 ) return 1.00794;
      else if ( fabs(eta) < 1.5660 ) return 1.01449;
      else if ( fabs(eta) < 2.0000 ) return 1.02521;
      else return 1.01737; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00802;
      else if ( fabs(eta) < 1.4442 ) return 1.00720;
      else if ( fabs(eta) < 1.5660 ) return 1.00551;
      else if ( fabs(eta) < 2.0000 ) return 1.02000;
      else return 1.01189; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00798;
      else if ( fabs(eta) < 1.4442 ) return 1.01075;
      else if ( fabs(eta) < 1.5660 ) return 1.01624;
      else if ( fabs(eta) < 2.0000 ) return 1.02476;
      else return 1.02398; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00873;
      else if ( fabs(eta) < 1.4442 ) return 1.00779;
      else if ( fabs(eta) < 1.5660 ) return 1.00875;
      else if ( fabs(eta) < 2.0000 ) return 1.02157;
      else return 1.00891; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00742;
      else if ( fabs(eta) < 1.4442 ) return 1.00964;
      else if ( fabs(eta) < 1.5660 ) return 1.01136;
      else if ( fabs(eta) < 2.0000 ) return 1.02089;
      else return 1.01439; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00886;
      else if ( fabs(eta) < 1.4442 ) return 1.00836;
      else if ( fabs(eta) < 1.5660 ) return 1.01108;
      else if ( fabs(eta) < 2.0000 ) return 1.02019;
      else return 1.01405; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00834;
      else if ( fabs(eta) < 1.4442 ) return 1.00820;
      else if ( fabs(eta) < 1.5660 ) return 1.01650;
      else if ( fabs(eta) < 2.0000 ) return 1.02148;
      else return 1.01718; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00982;
      else if ( fabs(eta) < 1.4442 ) return 1.00819;
      else if ( fabs(eta) < 1.5660 ) return 1.01512;
      else if ( fabs(eta) < 2.0000 ) return 1.02212;
      else return 1.01273; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.00966;
      else if ( fabs(eta) < 1.4442 ) return 1.00872;
      else if ( fabs(eta) < 1.5660 ) return 1.01319;
      else if ( fabs(eta) < 2.0000 ) return 1.02425;
      else return 1.00000; }
  else if ( ht < 2000.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01164;
      else if ( fabs(eta) < 1.4442 ) return 1.00754;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00917;
      else return 1.01471; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00816;
      else if ( fabs(eta) < 1.4442 ) return 1.01873;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.03265;
      else return 1.01667; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00804;
      else if ( fabs(eta) < 1.4442 ) return 1.01308;
      else if ( fabs(eta) < 1.5660 ) return 1.05634;
      else if ( fabs(eta) < 2.0000 ) return 1.04294;
      else return 1.02727; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00593;
      else if ( fabs(eta) < 1.4442 ) return 1.01871;
      else if ( fabs(eta) < 1.5660 ) return 1.02326;
      else if ( fabs(eta) < 2.0000 ) return 1.02260;
      else return 1.01020; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00463;
      else if ( fabs(eta) < 1.4442 ) return 1.00857;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.01361;
      else return 1.02257; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01328;
      else if ( fabs(eta) < 1.4442 ) return 1.01361;
      else if ( fabs(eta) < 1.5660 ) return 1.04000;
      else if ( fabs(eta) < 2.0000 ) return 1.03053;
      else return 1.00000; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00940;
      else if ( fabs(eta) < 1.4442 ) return 1.01017;
      else if ( fabs(eta) < 1.5660 ) return 1.01136;
      else if ( fabs(eta) < 2.0000 ) return 1.02745;
      else return 1.02344; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01334;
      else if ( fabs(eta) < 1.4442 ) return 1.00863;
      else if ( fabs(eta) < 1.5660 ) return 1.02985;
      else if ( fabs(eta) < 2.0000 ) return 1.05076;
      else return 1.00000; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00938;
      else if ( fabs(eta) < 1.4442 ) return 1.00860;
      else if ( fabs(eta) < 1.5660 ) return 1.03415;
      else if ( fabs(eta) < 2.0000 ) return 1.01887;
      else return 1.04110; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01303;
      else if ( fabs(eta) < 1.4442 ) return 1.01173;
      else if ( fabs(eta) < 1.5660 ) return 1.01149;
      else if ( fabs(eta) < 2.0000 ) return 1.05431;
      else return 1.02762; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.01655;
      else if ( fabs(eta) < 1.4442 ) return 1.01168;
      else if ( fabs(eta) < 1.5660 ) return 1.01408;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.04762; }
  else {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05263;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.94044;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 2.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return inf; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.05263;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02778;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.02381;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00515;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return inf; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.02532;
      else if ( fabs(eta) < 1.4442 ) return 1.05000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
}
  
double HardcodedConditions::GetMuonTriggerXSF2017(double ht, double pt, double eta){
  double scaleCDEF = 38.783 / 43.841;
  if ( ht < 400.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.14190 * scaleCDEF;
      else if ( fabs(eta) < 1.4442 ) return 1.01702 * scaleCDEF;
      else if ( fabs(eta) < 1.5660 ) return 0.97751 * scaleCDEF;
      else if ( fabs(eta) < 2.0000 ) return 1.23855 * scaleCDEF;
      else return 1.68424 * scaleCDEF; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00262;
      else if ( fabs(eta) < 1.4442 ) return 1.01285;
      else if ( fabs(eta) < 1.5660 ) return 1.05072;
      else if ( fabs(eta) < 2.0000 ) return 1.05729;
      else return 1.07391; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01380;
      else if ( fabs(eta) < 1.4442 ) return 1.01504;
      else if ( fabs(eta) < 1.5660 ) return 1.02096;
      else if ( fabs(eta) < 2.0000 ) return 1.01893;
      else return 1.02219; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01139;
      else if ( fabs(eta) < 1.4442 ) return 1.01445;
      else if ( fabs(eta) < 1.5660 ) return 1.01063;
      else if ( fabs(eta) < 2.0000 ) return 1.02420;
      else return 1.02827; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01142;
      else if ( fabs(eta) < 1.4442 ) return 1.01344;
      else if ( fabs(eta) < 1.5660 ) return 1.01758;
      else if ( fabs(eta) < 2.0000 ) return 1.02689;
      else return 1.03060; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00871;
      else if ( fabs(eta) < 1.4442 ) return 1.01039;
      else if ( fabs(eta) < 1.5660 ) return 1.01503;
      else if ( fabs(eta) < 2.0000 ) return 1.01980;
      else return 1.02258; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00386;
      else if ( fabs(eta) < 1.4442 ) return 1.00672;
      else if ( fabs(eta) < 1.5660 ) return 1.00794;
      else if ( fabs(eta) < 2.0000 ) return 1.01454;
      else return 1.02236; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00452;
      else if ( fabs(eta) < 1.4442 ) return 1.00538;
      else if ( fabs(eta) < 1.5660 ) return 1.00570;
      else if ( fabs(eta) < 2.0000 ) return 1.01691;
      else return 1.01578; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00376;
      else if ( fabs(eta) < 1.4442 ) return 1.00581;
      else if ( fabs(eta) < 1.5660 ) return 1.00492;
      else if ( fabs(eta) < 2.0000 ) return 1.01170;
      else return 1.01797; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00316;
      else if ( fabs(eta) < 1.4442 ) return 1.00341;
      else if ( fabs(eta) < 1.5660 ) return 1.00199;
      else if ( fabs(eta) < 2.0000 ) return 1.00705;
      else return 1.01200; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.00593;
      else if ( fabs(eta) < 1.4442 ) return 1.00146;
      else if ( fabs(eta) < 1.5660 ) return 1.00376;
      else if ( fabs(eta) < 2.0000 ) return 0.99828;
      else return 1.01310; }
  else if ( ht < 500.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99418 * scaleCDEF;
      else if ( fabs(eta) < 1.4442 ) return 1.00568 * scaleCDEF;
      else if ( fabs(eta) < 1.5660 ) return 1.05919 * scaleCDEF;
      else if ( fabs(eta) < 2.0000 ) return 1.07103 * scaleCDEF;
      else return 1.14675 * scaleCDEF; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.94063;
      else if ( fabs(eta) < 1.4442 ) return 0.95516;
      else if ( fabs(eta) < 1.5660 ) return 0.93959;
      else if ( fabs(eta) < 2.0000 ) return 0.99141;
      else return 0.99743; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00858;
      else if ( fabs(eta) < 1.4442 ) return 1.01301;
      else if ( fabs(eta) < 1.5660 ) return 1.01502;
      else if ( fabs(eta) < 2.0000 ) return 1.02215;
      else return 1.02086; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00737;
      else if ( fabs(eta) < 1.4442 ) return 1.01205;
      else if ( fabs(eta) < 1.5660 ) return 1.01747;
      else if ( fabs(eta) < 2.0000 ) return 1.01799;
      else return 1.02929; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00668;
      else if ( fabs(eta) < 1.4442 ) return 1.01121;
      else if ( fabs(eta) < 1.5660 ) return 1.01045;
      else if ( fabs(eta) < 2.0000 ) return 1.01705;
      else return 1.02689; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00703;
      else if ( fabs(eta) < 1.4442 ) return 1.00909;
      else if ( fabs(eta) < 1.5660 ) return 1.01239;
      else if ( fabs(eta) < 2.0000 ) return 1.01908;
      else return 1.02394; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00396;
      else if ( fabs(eta) < 1.4442 ) return 1.00762;
      else if ( fabs(eta) < 1.5660 ) return 1.00808;
      else if ( fabs(eta) < 2.0000 ) return 1.01508;
      else return 1.01541; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00478;
      else if ( fabs(eta) < 1.4442 ) return 1.00704;
      else if ( fabs(eta) < 1.5660 ) return 1.00763;
      else if ( fabs(eta) < 2.0000 ) return 1.01107;
      else return 1.01839; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00528;
      else if ( fabs(eta) < 1.4442 ) return 1.00678;
      else if ( fabs(eta) < 1.5660 ) return 1.00513;
      else if ( fabs(eta) < 2.0000 ) return 1.01234;
      else return 1.01467; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00461;
      else if ( fabs(eta) < 1.4442 ) return 1.00326;
      else if ( fabs(eta) < 1.5660 ) return 1.00564;
      else if ( fabs(eta) < 2.0000 ) return 1.01062;
      else return 1.00898; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.00387;
      else if ( fabs(eta) < 1.4442 ) return 1.00389;
      else if ( fabs(eta) < 1.5660 ) return 1.00546;
      else if ( fabs(eta) < 2.0000 ) return 1.00914;
      else return 1.01708; }
  else if ( ht < 1000.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.98986 * scaleCDEF;
      else if ( fabs(eta) < 1.4442 ) return 0.99440 * scaleCDEF;
      else if ( fabs(eta) < 1.5660 ) return 0.99645 * scaleCDEF;
      else if ( fabs(eta) < 2.0000 ) return 1.00165 * scaleCDEF;
      else return 1.00270 * scaleCDEF; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.96197;
      else if ( fabs(eta) < 1.4442 ) return 0.97582;
      else if ( fabs(eta) < 1.5660 ) return 0.97860;
      else if ( fabs(eta) < 2.0000 ) return 0.98390;
      else return 0.99068; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00648;
      else if ( fabs(eta) < 1.4442 ) return 1.01538;
      else if ( fabs(eta) < 1.5660 ) return 1.02177;
      else if ( fabs(eta) < 2.0000 ) return 1.02067;
      else return 1.02082; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00711;
      else if ( fabs(eta) < 1.4442 ) return 1.01455;
      else if ( fabs(eta) < 1.5660 ) return 1.01819;
      else if ( fabs(eta) < 2.0000 ) return 1.01808;
      else return 1.02057; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00680;
      else if ( fabs(eta) < 1.4442 ) return 1.01375;
      else if ( fabs(eta) < 1.5660 ) return 1.00975;
      else if ( fabs(eta) < 2.0000 ) return 1.02280;
      else return 1.02289; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00791;
      else if ( fabs(eta) < 1.4442 ) return 1.01284;
      else if ( fabs(eta) < 1.5660 ) return 1.01243;
      else if ( fabs(eta) < 2.0000 ) return 1.01791;
      else return 1.02079; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00789;
      else if ( fabs(eta) < 1.4442 ) return 1.01047;
      else if ( fabs(eta) < 1.5660 ) return 1.00873;
      else if ( fabs(eta) < 2.0000 ) return 1.01909;
      else return 1.02354; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00781;
      else if ( fabs(eta) < 1.4442 ) return 1.01156;
      else if ( fabs(eta) < 1.5660 ) return 1.00965;
      else if ( fabs(eta) < 2.0000 ) return 1.01769;
      else return 1.02148; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00780;
      else if ( fabs(eta) < 1.4442 ) return 1.01017;
      else if ( fabs(eta) < 1.5660 ) return 1.01130;
      else if ( fabs(eta) < 2.0000 ) return 1.01805;
      else return 1.02147; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00672;
      else if ( fabs(eta) < 1.4442 ) return 1.00597;
      else if ( fabs(eta) < 1.5660 ) return 1.00383;
      else if ( fabs(eta) < 2.0000 ) return 1.01653;
      else return 1.01605; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.00687;
      else if ( fabs(eta) < 1.4442 ) return 1.00682;
      else if ( fabs(eta) < 1.5660 ) return 0.99812;
      else if ( fabs(eta) < 2.0000 ) return 1.01358;
      else return 1.01419; }
  else if ( ht < 2000.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.99588 * scaleCDEF;
      else if ( fabs(eta) < 1.4442 ) return 1.00825 * scaleCDEF;
      else if ( fabs(eta) < 1.5660 ) return 1.01854 * scaleCDEF;
      else if ( fabs(eta) < 2.0000 ) return 1.00941 * scaleCDEF;
      else return 1.02395 * scaleCDEF; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.97430;
      else if ( fabs(eta) < 1.4442 ) return 0.98296;
      else if ( fabs(eta) < 1.5660 ) return 0.99608;
      else if ( fabs(eta) < 2.0000 ) return 1.00734;
      else return 1.00686; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01107;
      else if ( fabs(eta) < 1.4442 ) return 1.02152;
      else if ( fabs(eta) < 1.5660 ) return 1.05167;
      else if ( fabs(eta) < 2.0000 ) return 1.03125;
      else return 1.02895; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01282;
      else if ( fabs(eta) < 1.4442 ) return 1.01976;
      else if ( fabs(eta) < 1.5660 ) return 1.02555;
      else if ( fabs(eta) < 2.0000 ) return 1.02284;
      else return 1.03138; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01077;
      else if ( fabs(eta) < 1.4442 ) return 1.02476;
      else if ( fabs(eta) < 1.5660 ) return 1.02008;
      else if ( fabs(eta) < 2.0000 ) return 1.00977;
      else return 1.03322; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01448;
      else if ( fabs(eta) < 1.4442 ) return 1.01553;
      else if ( fabs(eta) < 1.5660 ) return 1.03690;
      else if ( fabs(eta) < 2.0000 ) return 1.03070;
      else return 1.03858; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01250;
      else if ( fabs(eta) < 1.4442 ) return 1.01877;
      else if ( fabs(eta) < 1.5660 ) return 1.02661;
      else if ( fabs(eta) < 2.0000 ) return 1.03091;
      else return 1.03691; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01411;
      else if ( fabs(eta) < 1.4442 ) return 1.01683;
      else if ( fabs(eta) < 1.5660 ) return 1.01856;
      else if ( fabs(eta) < 2.0000 ) return 1.02950;
      else return 1.03678; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01087;
      else if ( fabs(eta) < 1.4442 ) return 1.01766;
      else if ( fabs(eta) < 1.5660 ) return 1.00885;
      else if ( fabs(eta) < 2.0000 ) return 1.02238;
      else return 1.02635; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01131;
      else if ( fabs(eta) < 1.4442 ) return 1.01055;
      else if ( fabs(eta) < 1.5660 ) return 1.01358;
      else if ( fabs(eta) < 2.0000 ) return 1.02849;
      else return 1.01744; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.01140;
      else if ( fabs(eta) < 1.4442 ) return 1.01326;
      else if ( fabs(eta) < 1.5660 ) return 1.01193;
      else if ( fabs(eta) < 2.0000 ) return 1.02936;
      else return 1.02837; }
  else {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 0.97488 * scaleCDEF;
      else if ( fabs(eta) < 1.4442 ) return 1.00000 * scaleCDEF;
      else if ( fabs(eta) < 1.5660 ) return 1.00000 * scaleCDEF;
      else if ( fabs(eta) < 2.0000 ) return 0.90909 * scaleCDEF;
      else return 1.00000 * scaleCDEF; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03529;
      else if ( fabs(eta) < 1.4442 ) return 0.93846;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 0.91667;
      else return 1.33333; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.02222;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.06667;
      else return 1.11111; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.03571;
      else if ( fabs(eta) < 1.4442 ) return 1.02326;
      else if ( fabs(eta) < 1.5660 ) return 1.14286;
      else if ( fabs(eta) < 2.0000 ) return 1.05556;
      else return 1.00000; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01163;
      else if ( fabs(eta) < 1.4442 ) return 1.00000;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.09091;
      else return 1.00000; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00000;
      else if ( fabs(eta) < 1.4442 ) return 1.01190;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.03333;
      else return 1.09091; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01227;
      else if ( fabs(eta) < 1.4442 ) return 1.01316;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00897;
      else if ( fabs(eta) < 1.4442 ) return 1.02551;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.01741;
      else if ( fabs(eta) < 1.4442 ) return 0.98797;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.01059;
      else if ( fabs(eta) < 1.4442 ) return 1.02139;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00000;
      else return 1.00000; }
}

double HardcodedConditions::GetMuonTriggerXSF2018(double ht, double pt, double eta){
  if ( ht < 400.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.11671;
      else if ( fabs(eta) < 1.4442 ) return 1.12918;
      else if ( fabs(eta) < 1.5660 ) return 1.14447;
      else if ( fabs(eta) < 2.0000 ) return 1.14417;
      else return 1.16220; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00901;
      else if ( fabs(eta) < 1.4442 ) return 1.01365;
      else if ( fabs(eta) < 1.5660 ) return 1.00992;
      else if ( fabs(eta) < 2.0000 ) return 1.01963;
      else return 1.02139; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00905;
      else if ( fabs(eta) < 1.4442 ) return 1.01171;
      else if ( fabs(eta) < 1.5660 ) return 1.01684;
      else if ( fabs(eta) < 2.0000 ) return 1.01832;
      else return 1.02085; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00704;
      else if ( fabs(eta) < 1.4442 ) return 1.00835;
      else if ( fabs(eta) < 1.5660 ) return 1.00768;
      else if ( fabs(eta) < 2.0000 ) return 1.01486;
      else return 1.02240; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00733;
      else if ( fabs(eta) < 1.4442 ) return 1.00719;
      else if ( fabs(eta) < 1.5660 ) return 1.00829;
      else if ( fabs(eta) < 2.0000 ) return 1.01988;
      else return 1.02221; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00499;
      else if ( fabs(eta) < 1.4442 ) return 1.00620;
      else if ( fabs(eta) < 1.5660 ) return 1.00755;
      else if ( fabs(eta) < 2.0000 ) return 1.01231;
      else return 1.01653; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00340;
      else if ( fabs(eta) < 1.4442 ) return 1.00335;
      else if ( fabs(eta) < 1.5660 ) return 1.00423;
      else if ( fabs(eta) < 2.0000 ) return 1.00879;
      else return 1.01285; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00305;
      else if ( fabs(eta) < 1.4442 ) return 1.00311;
      else if ( fabs(eta) < 1.5660 ) return 0.99992;
      else if ( fabs(eta) < 2.0000 ) return 1.00802;
      else return 1.01013; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00307;
      else if ( fabs(eta) < 1.4442 ) return 1.00276;
      else if ( fabs(eta) < 1.5660 ) return 1.00273;
      else if ( fabs(eta) < 2.0000 ) return 1.00844;
      else return 1.01431; }
    else if ( pt < 200.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00210;
      else if ( fabs(eta) < 1.4442 ) return 1.00166;
      else if ( fabs(eta) < 1.5660 ) return 1.00146;
      else if ( fabs(eta) < 2.0000 ) return 1.00656;
      else return 1.00613; }
    else {
      if ( fabs(eta) < 0.8000 ) return 1.00091;
      else if ( fabs(eta) < 1.4442 ) return 1.00052;
      else if ( fabs(eta) < 1.5660 ) return 1.00000;
      else if ( fabs(eta) < 2.0000 ) return 1.00409;
      else return 1.00000; }
  else if ( ht < 500.0 ) {
    if ( pt < 25.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.04135;
      else if ( fabs(eta) < 1.4442 ) return 1.04909;
      else if ( fabs(eta) < 1.5660 ) return 1.04667;
      else if ( fabs(eta) < 2.0000 ) return 1.05397;
      else return 1.06315; }
    else if ( pt < 30.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00682;
      else if ( fabs(eta) < 1.4442 ) return 1.00581;
      else if ( fabs(eta) < 1.5660 ) return 1.00693;
      else if ( fabs(eta) < 2.0000 ) return 1.01288;
      else return 1.01418; }
    else if ( pt < 35.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00600;
      else if ( fabs(eta) < 1.4442 ) return 1.00512;
      else if ( fabs(eta) < 1.5660 ) return 1.00064;
      else if ( fabs(eta) < 2.0000 ) return 1.01488;
      else return 1.01875; }
    else if ( pt < 40.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00536;
      else if ( fabs(eta) < 1.4442 ) return 1.00542;
      else if ( fabs(eta) < 1.5660 ) return 1.00500;
      else if ( fabs(eta) < 2.0000 ) return 1.01275;
      else return 1.01397; }
    else if ( pt < 45.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00502;
      else if ( fabs(eta) < 1.4442 ) return 1.00467;
      else if ( fabs(eta) < 1.5660 ) return 1.00383;
      else if ( fabs(eta) < 2.0000 ) return 1.00965;
      else return 1.01441; }
    else if ( pt < 50.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00429;
      else if ( fabs(eta) < 1.4442 ) return 1.00255;
      else if ( fabs(eta) < 1.5660 ) return 1.00399;
      else if ( fabs(eta) < 2.0000 ) return 1.00796;
      else return 1.01333; }
    else if ( pt < 60.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00345;
      else if ( fabs(eta) < 1.4442 ) return 1.00383;
      else if ( fabs(eta) < 1.5660 ) return 1.00235;
      else if ( fabs(eta) < 2.0000 ) return 1.01099;
      else return 1.01164; }
    else if ( pt < 70.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00360;
      else if ( fabs(eta) < 1.4442 ) return 1.00358;
      else if ( fabs(eta) < 1.5660 ) return 1.00326;
      else if ( fabs(eta) < 2.0000 ) return 1.00995;
      else return 1.01091; }
    else if ( pt < 100.0 ) {
      if ( fabs(eta) < 0.8000 ) return 1.00323;
      else if ( fabs(eta) < 1.4442 ) return 1.00306;
      else if ( fabs(eta) < 1.5660 ) return 1.00183;
      else if ( fabs(eta) < 2.0000 ) return 1.00770;
      else return 1.00959; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00281;
    else if ( fabs(eta) < 1.4442 ) return 1.00235;
    else if ( fabs(eta) < 1.5660 ) return 1.00053;
    else if ( fabs(eta) < 2.0000 ) return 1.00699;
    else return 1.00527; }
  else {
    if ( fabs(eta) < 0.8000 ) return 1.00242;
    else if ( fabs(eta) < 1.4442 ) return 1.00226;
    else if ( fabs(eta) < 1.5660 ) return 1.00004;
    else if ( fabs(eta) < 2.0000 ) return 1.00079;
    else return 1.00414; }
else if ( ht < 1000.0 ) {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00376;
    else if ( fabs(eta) < 1.4442 ) return 1.00377;
    else if ( fabs(eta) < 1.5660 ) return 1.00346;
    else if ( fabs(eta) < 2.0000 ) return 1.00826;
    else return 1.01391; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00349;
    else if ( fabs(eta) < 1.4442 ) return 1.00367;
    else if ( fabs(eta) < 1.5660 ) return 1.00205;
    else if ( fabs(eta) < 2.0000 ) return 1.01220;
    else return 1.01473; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00490;
    else if ( fabs(eta) < 1.4442 ) return 1.00434;
    else if ( fabs(eta) < 1.5660 ) return 1.00142;
    else if ( fabs(eta) < 2.0000 ) return 1.01217;
    else return 1.01438; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00495;
    else if ( fabs(eta) < 1.4442 ) return 1.00431;
    else if ( fabs(eta) < 1.5660 ) return 1.00297;
    else if ( fabs(eta) < 2.0000 ) return 1.01171;
    else return 1.01511; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00471;
    else if ( fabs(eta) < 1.4442 ) return 1.00459;
    else if ( fabs(eta) < 1.5660 ) return 1.00289;
    else if ( fabs(eta) < 2.0000 ) return 1.01202;
    else return 1.01595; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00414;
    else if ( fabs(eta) < 1.4442 ) return 1.00422;
    else if ( fabs(eta) < 1.5660 ) return 1.00011;
    else if ( fabs(eta) < 2.0000 ) return 1.01261;
    else return 1.01654; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00492;
    else if ( fabs(eta) < 1.4442 ) return 1.00516;
    else if ( fabs(eta) < 1.5660 ) return 1.00406;
    else if ( fabs(eta) < 2.0000 ) return 1.01157;
    else return 1.01520; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00466;
    else if ( fabs(eta) < 1.4442 ) return 1.00410;
    else if ( fabs(eta) < 1.5660 ) return 1.00197;
    else if ( fabs(eta) < 2.0000 ) return 1.01025;
    else return 1.01269; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00493;
    else if ( fabs(eta) < 1.4442 ) return 1.00509;
    else if ( fabs(eta) < 1.5660 ) return 1.00185;
    else if ( fabs(eta) < 2.0000 ) return 1.01159;
    else return 1.01525; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00328;
    else if ( fabs(eta) < 1.4442 ) return 1.00313;
    else if ( fabs(eta) < 1.5660 ) return 1.00053;
    else if ( fabs(eta) < 2.0000 ) return 1.00799;
    else return 1.01108; }
  else {
    if ( fabs(eta) < 0.8000 ) return 1.00457;
    else if ( fabs(eta) < 1.4442 ) return 1.00279;
    else if ( fabs(eta) < 1.5660 ) return 1.00184;
    else if ( fabs(eta) < 2.0000 ) return 1.00827;
    else return 1.00937; }
else if ( ht < 2000.0 ) {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00518;
    else if ( fabs(eta) < 1.4442 ) return 1.00346;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.02237;
    else return 1.02575; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00543;
    else if ( fabs(eta) < 1.4442 ) return 1.00924;
    else if ( fabs(eta) < 1.5660 ) return 1.00333;
    else if ( fabs(eta) < 2.0000 ) return 1.01491;
    else return 1.01782; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00614;
    else if ( fabs(eta) < 1.4442 ) return 1.00407;
    else if ( fabs(eta) < 1.5660 ) return 1.01060;
    else if ( fabs(eta) < 2.0000 ) return 1.02152;
    else return 1.01777; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00550;
    else if ( fabs(eta) < 1.4442 ) return 1.00925;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.01541;
    else return 1.05090; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00442;
    else if ( fabs(eta) < 1.4442 ) return 1.00174;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.01483;
    else return 1.02827; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00812;
    else if ( fabs(eta) < 1.4442 ) return 1.00636;
    else if ( fabs(eta) < 1.5660 ) return 1.00448;
    else if ( fabs(eta) < 2.0000 ) return 1.01124;
    else return 1.02952; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00570;
    else if ( fabs(eta) < 1.4442 ) return 1.00718;
    else if ( fabs(eta) < 1.5660 ) return 1.00476;
    else if ( fabs(eta) < 2.0000 ) return 1.01663;
    else return 1.02128; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00662;
    else if ( fabs(eta) < 1.4442 ) return 1.00418;
    else if ( fabs(eta) < 1.5660 ) return 1.00306;
    else if ( fabs(eta) < 2.0000 ) return 1.01743;
    else return 1.01369; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00546;
    else if ( fabs(eta) < 1.4442 ) return 1.01016;
    else if ( fabs(eta) < 1.5660 ) return 1.01108;
    else if ( fabs(eta) < 2.0000 ) return 1.01483;
    else return 1.01698; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00438;
    else if ( fabs(eta) < 1.4442 ) return 1.00316;
    else if ( fabs(eta) < 1.5660 ) return 1.01024;
    else if ( fabs(eta) < 2.0000 ) return 1.01609;
    else return 1.01188; }
  else {
    if ( fabs(eta) < 0.8000 ) return 1.00532;
    else if ( fabs(eta) < 1.4442 ) return 1.00775;
    else if ( fabs(eta) < 1.5660 ) return 1.00319;
    else if ( fabs(eta) < 2.0000 ) return 1.01196;
    else return 1.01762; }
else {
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01471;
    else if ( fabs(eta) < 1.4442 ) return 1.00000;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00000;
    else return 1.00000; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00000;
    else if ( fabs(eta) < 1.4442 ) return 0.94737;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00000;
    else return 1.14286; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00990;
    else if ( fabs(eta) < 1.4442 ) return 1.00000;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00000;
    else return 0.90909; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00000;
    else if ( fabs(eta) < 1.4442 ) return 1.00000;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00000;
    else return 1.00000; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01250;
    else if ( fabs(eta) < 1.4442 ) return 1.02326;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.14286;
    else return 1.00000; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01370;
    else if ( fabs(eta) < 1.4442 ) return 1.00000;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00000;
    else return 1.33333; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00000;
    else if ( fabs(eta) < 1.4442 ) return 1.00000;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.04348;
    else return 1.14286; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01399;
    else if ( fabs(eta) < 1.4442 ) return 1.01562;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00000;
    else return 1.00000; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00800;
    else if ( fabs(eta) < 1.4442 ) return 0.98813;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00000;
    else return 1.12500; }
  else if ( pt < 200.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00655;
    else if ( fabs(eta) < 1.4442 ) return 1.00980;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.03774;
    else return 1.00000; }
  else {
    if ( fabs(eta) < 0.8000 ) return 1.00763;
    else if ( fabs(eta) < 1.4442 ) return 1.00422;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.00000;
    else return 1.00000; }
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|                PILEUP WEIGHT SECTION                |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

void HardcodedConditions::GetPileupWeight(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn, std::string year, std::string sample)
{
  //The main getter for Pileup Weight Factors
  *pileupweight   = 1.000;
  *pileupweightup = 1.000;
  *pileupweightdn = 1.000;
  if      (year=="2016APV") GetPileupWeight2016APV(nTrueInt, pileupweight, pileupweightup, pileupweightdn);
  else if (year=="2016") GetPileupWeight2016(nTrueInt, pileupweight, pileupweightup, pileupweightdn);
  else if (year=="2017") GetPileupWeight2017(nTrueInt, pileupweight, pileupweightup, pileupweightdn);
  else if (year=="2018") GetPileupWeight2018(nTrueInt, pileupweight, pileupweightup, pileupweightdn);
}//end GetPileupWeight

void HardcodedConditions::GetPileupWeight2016APV(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn){
  std::vector<float> puWeights;
  std::vector<float> puWeightsUP;
  std::vector<float> puWeightsDN;
  puWeights = { 2.397e-01, 3.821e-01, 8.494e-01, 9.920e-01, 1.410e+00, 1.914e+00, 1.843e+00, 1.394e+00, 1.224e+00, 1.179e+00, 1.148e+00, 1.106e+00, 1.074e+00, 1.061e+00, 1.064e+00, 1.080e+00, 1.095e+00, 1.108e+00, 1.113e+00, 1.108e+00, 1.093e+00, 1.076e+00, 1.060e+00, 1.043e+00, 1.022e+00, 9.931e-01, 9.562e-01, 9.136e-01, 8.692e-01, 8.256e-01, 7.834e-01, 7.458e-01, 7.153e-01, 6.907e-01, 6.691e-01, 6.482e-01, 6.306e-01, 6.133e-01, 5.994e-01, 5.878e-01, 5.787e-01, 5.755e-01, 5.819e-01, 5.995e-01, 6.315e-01, 6.620e-01, 7.046e-01, 7.595e-01, 7.931e-01, 8.048e-01, 7.812e-01, 7.440e-01, 6.529e-01, 5.750e-01, 4.733e-01, 3.377e-01, 2.626e-01, 1.636e-01, 1.399e-01, 1.056e-01, 7.550e-02, 6.081e-02, 5.766e-02, 4.566e-02, 2.463e-02, 1.594e-02, 2.412e-02, 1.644e-02, 1.071e-02, 3.100e-02, 4.764e-02, 4.368e-03, 4.237e-03, 2.459e-02, 8.440e-03, 6.855e-04, 4.173e-03, 1.446e-03, 1.000e+00, 2.368e-04, 2.251e-05, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00 };
  puWeightsUP = { 2.093e-01, 3.285e-01, 7.532e-01, 8.673e-01, 1.122e+00, 1.371e+00, 1.464e+00, 1.148e+00, 9.557e-01, 9.038e-01, 8.933e-01, 8.800e-01, 8.663e-01, 8.626e-01, 8.745e-01, 9.101e-01, 9.563e-01, 9.991e-01, 1.031e+00, 1.051e+00, 1.057e+00, 1.057e+00, 1.057e+00, 1.061e+00, 1.063e+00, 1.061e+00, 1.052e+00, 1.036e+00, 1.015e+00, 9.911e-01, 9.651e-01, 9.417e-01, 9.261e-01, 9.194e-01, 9.194e-01, 9.243e-01, 9.381e-01, 9.566e-01, 9.843e-01, 1.020e+00, 1.063e+00, 1.123e+00, 1.207e+00, 1.323e+00, 1.484e+00, 1.658e+00, 1.883e+00, 2.166e+00, 2.415e+00, 2.618e+00, 2.715e+00, 2.762e+00, 2.587e+00, 2.425e+00, 2.117e+00, 1.590e+00, 1.290e+00, 8.276e-01, 7.187e-01, 5.420e-01, 3.820e-01, 3.005e-01, 2.773e-01, 2.144e-01, 1.138e-01, 7.318e-02, 1.113e-01, 7.708e-02, 5.143e-02, 1.533e-01, 2.440e-01, 2.326e-02, 2.351e-02, 1.425e-01, 5.120e-02, 4.361e-03, 2.790e-02, 1.018e-02, 1.000e+00, 1.860e-03, 1.874e-04, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000 };
  puWeightsDN = { 2.772e-01, 4.471e-01, 9.617e-01, 1.150e+00, 1.867e+00, 2.665e+00, 2.280e+00, 1.741e+00, 1.608e+00, 1.551e+00, 1.476e+00, 1.393e+00, 1.339e+00, 1.310e+00, 1.285e+00, 1.256e+00, 1.228e+00, 1.206e+00, 1.180e+00, 1.150e+00, 1.115e+00, 1.078e+00, 1.040e+00, 9.982e-01, 9.488e-01, 8.930e-01, 8.319e-01, 7.699e-01, 7.110e-01, 6.568e-01, 6.067e-01, 5.612e-01, 5.210e-01, 4.844e-01, 4.489e-01, 4.137e-01, 3.808e-01, 3.490e-01, 3.204e-01, 2.944e-01, 2.711e-01, 2.518e-01, 2.376e-01, 2.282e-01, 2.240e-01, 2.186e-01, 2.165e-01, 2.171e-01, 2.108e-01, 1.990e-01, 1.800e-01, 1.604e-01, 1.324e-01, 1.107e-01, 8.767e-02, 6.112e-02, 4.728e-02, 2.979e-02, 2.609e-02, 2.027e-02, 1.489e-02, 1.223e-02, 1.168e-02, 9.196e-03, 4.876e-03, 3.073e-03, 4.496e-03, 2.948e-03, 1.840e-03, 5.084e-03, 7.444e-03, 6.488e-04, 5.967e-04, 3.276e-03, 1.062e-03, 8.119e-05, 4.642e-04, 1.507e-04, 1.000e+00, 2.149e-05, 1.899e-06, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000 };
  *pileupweight = puWeights[nTrueInt];
  *pileupweightup = puWeightsUP[nTrueInt];
  *pileupweightdn = puWeightsDN[nTrueInt];
}

void HardcodedConditions::GetPileupWeight2016(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn){
  std::vector<float> puWeights;
  std::vector<float> puWeightsUP;
  std::vector<float> puWeightsDN;
  puWeights = { 2.777e-01, 3.416e-01, 9.148e-01, 6.970e-01, 6.332e-01, 3.420e-01, 1.601e-01, 1.107e-01, 1.110e-01, 1.298e-01, 2.317e-01, 3.666e-01, 4.856e-01, 5.667e-01, 6.208e-01, 6.691e-01, 7.154e-01, 7.568e-01, 7.916e-01, 8.241e-01, 8.593e-01, 9.024e-01, 9.530e-01, 1.007e+00, 1.061e+00, 1.119e+00, 1.182e+00, 1.252e+00, 1.327e+00, 1.406e+00, 1.483e+00, 1.559e+00, 1.637e+00, 1.719e+00, 1.799e+00, 1.874e+00, 1.952e+00, 2.023e+00, 2.094e+00, 2.158e+00, 2.209e+00, 2.254e+00, 2.302e+00, 2.353e+00, 2.414e+00, 2.414e+00, 2.403e+00, 2.376e+00, 2.236e+00, 2.016e+00, 1.721e+00, 1.440e+00, 1.119e+00, 8.937e-01, 6.946e-01, 4.945e-01, 4.086e-01, 2.864e-01, 2.870e-01, 2.588e-01, 2.213e-01, 2.108e-01, 2.322e-01, 2.096e-01, 1.267e-01, 9.046e-02, 1.493e-01, 1.101e-01, 7.696e-02, 2.375e-01, 3.877e-01, 3.761e-02, 3.847e-02, 2.349e-01, 8.472e-02, 7.223e-03, 4.613e-02, 1.677e-02, 1.000e+00, 3.035e-03, 3.042e-04, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00 };
  puWeightsUP = { 2.441e-01, 2.895e-01, 8.507e-01, 6.287e-01, 5.801e-01, 3.108e-01, 1.482e-01, 8.596e-02, 8.725e-02, 8.356e-02, 1.354e-01, 2.315e-01, 3.370e-01, 4.227e-01, 4.849e-01, 5.420e-01, 6.015e-01, 6.600e-01, 7.097e-01, 7.512e-01, 7.898e-01, 8.330e-01, 8.872e-01, 9.515e-01, 1.020e+00, 1.091e+00, 1.168e+00, 1.254e+00, 1.353e+00, 1.464e+00, 1.583e+00, 1.711e+00, 1.856e+00, 2.017e+00, 2.192e+00, 2.381e+00, 2.596e+00, 2.833e+00, 3.107e+00, 3.415e+00, 3.757e+00, 4.151e+00, 4.624e+00, 5.188e+00, 5.872e+00, 6.512e+00, 7.209e+00, 7.941e+00, 8.324e+00, 8.334e+00, 7.850e+00, 7.154e+00, 5.939e+00, 4.916e+00, 3.802e+00, 2.572e+00, 1.935e+00, 1.204e+00, 1.071e+00, 8.760e-01, 7.022e-01, 6.477e-01, 7.100e-01, 6.503e-01, 4.040e-01, 2.992e-01, 5.151e-01, 3.973e-01, 2.913e-01, 9.443e-01, 1.620e+00, 1.653e-01, 1.779e-01, 1.143e+00, 4.338e-01, 3.892e-02, 2.616e-01, 1.001e-01, 1.000e+00, 2.006e-02, 2.116e-03, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000 };
  puWeightsDN = { 3.181e-01, 4.258e-01, 9.716e-01, 7.741e-01, 6.967e-01, 3.742e-01, 1.778e-01, 1.522e-01, 1.457e-01, 2.259e-01, 3.930e-01, 5.612e-01, 6.782e-01, 7.453e-01, 7.832e-01, 8.108e-01, 8.320e-01, 8.521e-01, 8.736e-01, 9.006e-01, 9.345e-01, 9.723e-01, 1.010e+00, 1.048e+00, 1.087e+00, 1.130e+00, 1.175e+00, 1.219e+00, 1.261e+00, 1.298e+00, 1.325e+00, 1.344e+00, 1.357e+00, 1.363e+00, 1.359e+00, 1.341e+00, 1.313e+00, 1.270e+00, 1.217e+00, 1.151e+00, 1.072e+00, 9.884e-01, 9.062e-01, 8.273e-01, 7.549e-01, 6.707e-01, 5.935e-01, 5.237e-01, 4.440e-01, 3.665e-01, 2.944e-01, 2.409e-01, 1.926e-01, 1.668e-01, 1.463e-01, 1.189e-01, 1.104e-01, 8.405e-02, 8.803e-02, 8.028e-02, 6.778e-02, 6.272e-02, 6.644e-02, 5.730e-02, 3.293e-02, 2.232e-02, 3.492e-02, 2.436e-02, 1.612e-02, 4.705e-02, 7.261e-02, 6.661e-03, 6.443e-03, 3.720e-02, 1.269e-02, 1.022e-03, 6.173e-03, 2.121e-03, 1.000e+00, 3.426e-04, 3.240e-05, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000 };
  *pileupweight = puWeights[nTrueInt];
  *pileupweightup = puWeightsUP[nTrueInt];
  *pileupweightdn = puWeightsDN[nTrueInt];
}

void HardcodedConditions::GetPileupWeight2017(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn){
  std::vector<float> puWeights;
  std::vector<float> puWeightsUP;
  std::vector<float> puWeightsDN;
  puWeights = { 5.606e-01, 7.357e-01, 5.379e-01, 1.218e+00, 8.023e-01, 9.163e-01, 1.004e+00, 9.252e-01, 6.847e-01, 7.132e-01, 7.505e-01, 8.165e-01, 8.377e-01, 8.464e-01, 8.440e-01, 8.439e-01, 8.666e-01, 8.930e-01, 9.180e-01, 9.358e-01, 9.556e-01, 9.721e-01, 9.812e-01, 9.832e-01, 9.781e-01, 9.760e-01, 9.766e-01, 9.827e-01, 9.904e-01, 9.981e-01, 1.008e+00, 1.019e+00, 1.030e+00, 1.044e+00, 1.053e+00, 1.061e+00, 1.068e+00, 1.071e+00, 1.070e+00, 1.061e+00, 1.043e+00, 1.029e+00, 1.011e+00, 9.898e-01, 9.667e-01, 9.597e-01, 9.605e-01, 9.726e-01, 9.860e-01, 1.020e+00, 1.080e+00, 1.131e+00, 1.175e+00, 1.206e+00, 1.189e+00, 1.175e+00, 1.153e+00, 1.139e+00, 1.149e+00, 1.186e+00, 1.230e+00, 1.284e+00, 1.348e+00, 1.415e+00, 1.489e+00, 1.564e+00, 1.761e+00, 2.497e+00, 3.605e+00, 3.510e+00, 5.546e+00, 1.647e+01, 3.021e+01, 1.596e+02, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00 };
  puWeightsUP = { 5.283e-01, 6.444e-01, 4.356e-01, 1.233e+00, 6.813e-01, 8.174e-01, 9.700e-01, 8.474e-01, 5.507e-01, 4.611e-01, 5.343e-01, 5.670e-01, 6.342e-01, 6.532e-01, 6.458e-01, 6.380e-01, 6.526e-01, 6.895e-01, 7.374e-01, 7.766e-01, 8.149e-01, 8.511e-01, 8.780e-01, 8.934e-01, 8.957e-01, 8.962e-01, 9.014e-01, 9.178e-01, 9.408e-01, 9.671e-01, 9.964e-01, 1.027e+00, 1.058e+00, 1.094e+00, 1.127e+00, 1.155e+00, 1.177e+00, 1.190e+00, 1.193e+00, 1.177e+00, 1.139e+00, 1.090e+00, 1.023e+00, 9.496e-01, 8.837e-01, 8.498e-01, 8.451e-01, 8.750e-01, 9.323e-01, 1.038e+00, 1.204e+00, 1.400e+00, 1.628e+00, 1.877e+00, 2.078e+00, 2.299e+00, 2.510e+00, 2.738e+00, 3.021e+00, 3.379e+00, 3.761e+00, 4.178e+00, 4.621e+00, 5.073e+00, 5.533e+00, 5.970e+00, 6.840e+00, 9.786e+00, 1.413e+01, 1.366e+01, 2.133e+01, 6.250e+01, 1.131e+02, 5.917e+02, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000 };
  puWeightsDN = { 5.978e-01, 8.077e-01, 7.068e-01, 1.168e+00, 9.349e-01, 1.015e+00, 1.047e+00, 1.035e+00, 9.934e-01, 1.062e+00, 1.098e+00, 1.138e+00, 1.099e+00, 1.116e+00, 1.127e+00, 1.137e+00, 1.145e+00, 1.131e+00, 1.120e+00, 1.108e+00, 1.099e+00, 1.092e+00, 1.084e+00, 1.078e+00, 1.069e+00, 1.059e+00, 1.045e+00, 1.031e+00, 1.016e+00, 1.002e+00, 9.908e-01, 9.804e-01, 9.691e-01, 9.613e-01, 9.547e-01, 9.521e-01, 9.538e-01, 9.587e-01, 9.719e-01, 9.945e-01, 1.026e+00, 1.073e+00, 1.111e+00, 1.125e+00, 1.103e+00, 1.065e+00, 1.004e+00, 9.338e-01, 8.524e-01, 7.841e-01, 7.322e-01, 6.749e-01, 6.183e-01, 5.626e-01, 4.956e-01, 4.420e-01, 3.956e-01, 3.605e-01, 3.390e-01, 3.295e-01, 3.249e-01, 3.259e-01, 3.318e-01, 3.417e-01, 3.562e-01, 3.744e-01, 4.249e-01, 6.109e-01, 8.951e-01, 8.834e-01, 1.409e+00, 4.197e+00, 7.666e+00, 4.005e+01, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000 };
  *pileupweight = puWeights[nTrueInt];
  *pileupweightup = puWeightsUP[nTrueInt];
  *pileupweightdn = puWeightsDN[nTrueInt];
}

void HardcodedConditions::GetPileupWeight2018(int nTrueInt, float *pileupweight, float *pileupweightup, float *pileupweightdn){
  std::vector<float> puWeights;
  std::vector<float> puWeightsUP;
  std::vector<float> puWeightsDN;
  puWeights = { 4.760e+00, 1.081e+00, 1.217e+00, 8.809e-01, 7.662e-01, 1.012e+00, 1.323e+00, 1.340e+00, 1.105e+00, 9.124e-01, 8.241e-01, 8.004e-01, 7.908e-01, 8.068e-01, 8.324e-01, 8.564e-01, 8.725e-01, 8.821e-01, 8.947e-01, 9.187e-01, 9.464e-01, 9.664e-01, 9.802e-01, 9.908e-01, 9.926e-01, 9.874e-01, 9.798e-01, 9.813e-01, 9.869e-01, 9.929e-01, 9.982e-01, 1.002e+00, 1.003e+00, 1.005e+00, 1.007e+00, 1.009e+00, 1.012e+00, 1.016e+00, 1.021e+00, 1.028e+00, 1.037e+00, 1.047e+00, 1.058e+00, 1.071e+00, 1.082e+00, 1.095e+00, 1.110e+00, 1.126e+00, 1.142e+00, 1.155e+00, 1.168e+00, 1.177e+00, 1.183e+00, 1.200e+00, 1.197e+00, 1.195e+00, 1.192e+00, 1.209e+00, 1.219e+00, 1.240e+00, 1.253e+00, 1.239e+00, 1.171e+00, 1.082e+00, 1.007e+00, 9.125e-01, 8.601e-01, 7.821e-01, 6.576e-01, 6.309e-01, 5.988e-01, 7.141e-01, 7.152e-01, 5.360e-01, 4.091e-01, 4.283e-01, 4.417e-01, 4.424e-01, 1.035e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00 };
  puWeightsUP = { 4.427e+00, 9.470e-01, 1.017e+00, 7.567e-01, 6.606e-01, 8.755e-01, 1.131e+00, 1.133e+00, 9.294e-01, 7.589e-01, 6.725e-01, 6.433e-01, 6.301e-01, 6.411e-01, 6.618e-01, 6.823e-01, 6.979e-01, 7.103e-01, 7.279e-01, 7.584e-01, 7.959e-01, 8.300e-01, 8.601e-01, 8.864e-01, 9.013e-01, 9.056e-01, 9.037e-01, 9.074e-01, 9.134e-01, 9.195e-01, 9.259e-01, 9.319e-01, 9.379e-01, 9.458e-01, 9.556e-01, 9.688e-01, 9.859e-01, 1.009e+00, 1.037e+00, 1.073e+00, 1.117e+00, 1.169e+00, 1.230e+00, 1.299e+00, 1.375e+00, 1.462e+00, 1.560e+00, 1.668e+00, 1.784e+00, 1.901e+00, 2.024e+00, 2.142e+00, 2.255e+00, 2.387e+00, 2.479e+00, 2.566e+00, 2.645e+00, 2.772e+00, 2.881e+00, 3.024e+00, 3.161e+00, 3.242e+00, 3.188e+00, 3.074e+00, 2.998e+00, 2.856e+00, 2.837e+00, 2.724e+00, 2.420e+00, 2.456e+00, 2.465e+00, 3.108e+00, 3.289e+00, 2.604e+00, 2.099e+00, 2.321e+00, 2.530e+00, 2.682e+00, 6.654e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000 };
  puWeightsDN = { 5.143e+00, 1.252e+00, 1.460e+00, 1.031e+00, 8.940e-01, 1.180e+00, 1.566e+00, 1.600e+00, 1.328e+00, 1.116e+00, 1.029e+00, 1.012e+00, 1.005e+00, 1.026e+00, 1.057e+00, 1.084e+00, 1.097e+00, 1.097e+00, 1.096e+00, 1.103e+00, 1.111e+00, 1.108e+00, 1.100e+00, 1.095e+00, 1.085e+00, 1.074e+00, 1.063e+00, 1.064e+00, 1.069e+00, 1.073e+00, 1.075e+00, 1.072e+00, 1.064e+00, 1.054e+00, 1.040e+00, 1.023e+00, 1.002e+00, 9.783e-01, 9.505e-01, 9.210e-01, 8.897e-01, 8.566e-01, 8.227e-01, 7.887e-01, 7.530e-01, 7.195e-01, 6.880e-01, 6.591e-01, 6.326e-01, 6.064e-01, 5.838e-01, 5.620e-01, 5.418e-01, 5.288e-01, 5.093e-01, 4.913e-01, 4.733e-01, 4.634e-01, 4.491e-01, 4.377e-01, 4.222e-01, 3.969e-01, 3.552e-01, 3.098e-01, 2.717e-01, 2.317e-01, 2.054e-01, 1.757e-01, 1.390e-01, 1.255e-01, 1.122e-01, 1.260e-01, 1.188e-01, 8.375e-02, 6.001e-02, 5.885e-02, 5.669e-02, 5.284e-02, 1.147e-01, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000e+00, 1.000 };
  *pileupweight = puWeights[nTrueInt];
  *pileupweightup = puWeightsUP[nTrueInt];
  *pileupweightdn = puWeightsDN[nTrueInt];
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|           Njet SF                                   |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

// need to update for UL
float HardcodedConditions::GetNjetSF(int njet, std::string year, std::string variation, bool isTT){
  unsigned int iSF=0;
  if (njet==4){
    iSF=0;
  } else if(njet==5) {
    iSF=1;
  } else if(njet==6) {
    iSF=2;
  } else if(njet==7) {
    iSF=3;
  } else if(njet==8) {
    iSF=4;
  } else if(njet>=9) {
    iSF=5;
  } else return 1.0;
  
  std::vector<float> njetSF16APV = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  std::vector<float> njetSF16APV_err = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  
  std::vector<float> njetSF16 = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  std::vector<float> njetSF16_err = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  
  std::vector<float> njetSF17 = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  std::vector<float> njetSF17_err = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  
  std::vector<float> njetSF18 = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  std::vector<float> njetSF18_err = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  std::vector<float> njetSF;
  std::vector<float> njetSF_err;

  if (year=="2016APV"){
    njetSF=njetSF16APV;
    njetSF_err=njetSF16APV_err;
  } else if  (year=="2016"){
    njetSF=njetSF16;
    njetSF_err=njetSF16_err;
  } else if  (year=="2017"){
    njetSF=njetSF17;
    njetSF_err=njetSF17_err;
  } else if  (year=="2018"){
    njetSF=njetSF18;
    njetSF_err=njetSF18_err;
  }

  if (variation=="up"){
    return njetSF[iSF]+njetSF_err[iSF];
  } else if (variation=="down"){
    return njetSF[iSF]-njetSF_err[iSF];
  } else {
    return njetSF[iSF];
  }
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
  |  /   \                                                       /   \  |
  | |\_.  |                                                     |    /| |
  |\|  | /|           Jet pileup ID SF                          |\  | |/|
  | `---' |                                                     | `---' |
  |       |                                                     |       |
  |       |-----------------------------------------------------|       |
  \       |                                                     |       /
   \     /                                                       \     /
    `---'                                                         `---'*/
void HardcodedConditions::GetJetPileupIDSF( double pt, double eta, double *puJetIDsf, double *puJetIDsfUp, double *puJetIDsfDn, std::string year ){
  *puJetIDsf   = 1.0;
  *puJetIDsfUp = 1.0;
  *puJetIDsfDn = 1.0;
  if      ( year == "2016APV" ) GetJetPileupIDSF2016APV( pt, eta, puJetIDsf, puJetIDsfUp, puJetIDsfDn );
  else if ( year == "2016" ) GetJetPileupIDSF2016( pt, eta, puJetIDsf, puJetIDsfUp, puJetIDsfDn );
  else if ( year == "2017" ) GetJetPileupIDSF2017( pt, eta, puJetIDsf, puJetIDsfUp, puJetIDsfDn );
  else if ( year == "2018" ) GetJetPileupIDSF2018( pt, eta, puJetIDsf, puJetIDsfUp, puJetIDsfDn );
}

void HardcodedConditions::GetJetPileupIDSF2016APV( double pt, double eta, double *puJetIDsf, double *puJetIDsfUp, double *puJetIDsfDn ){
  if ( pt < 40.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDsf   = 0.95920;
      *puJetIDsfUp = 0.98838;
      *puJetIDsfDn = 0.93002;
    }
    else if ( eta < -1.479 ){
      *puJetIDsf   = 0.99321;
      *puJetIDsfUp = 1.00404;
      *puJetIDsfDn = 0.98238;
    }
    else if ( eta < 0.0 ){
      *puJetIDsf   = 0.97992;
      *puJetIDsfUp = 0.98665;
      *puJetIDsfDn = 0.97319;
    }
    else if ( eta < 1.479 ){
      *puJetIDsf   = 0.98129;
      *puJetIDsfUp = 0.98782;
      *puJetIDsfDn = 0.97477;
    }
    else if ( eta < 2.0 ){
      *puJetIDsf   = 0.95903;
      *puJetIDsfUp = 0.97867;
      *puJetIDsfDn = 0.93938;
    }
    else {
      *puJetIDsf   = 0.97421;
      *puJetIDsfUp = 0.99375;
      *puJetIDsfDn = 0.95466;
    }
  }
  else if ( pt < 50.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDsf   = 0.96555;
      *puJetIDsfUp = 0.99042;
      *puJetIDsfDn = 0.94068;
    }
    else if ( eta < -1.479 ){
      *puJetIDsf   = 0.98388;
      *puJetIDsfUp = 1.03353;
      *puJetIDsfDn = 0.93424;
    }
    else if ( eta < 0.0 ){
      *puJetIDsf   = 0.98751;
      *puJetIDsfUp = 0.99574;
      *puJetIDsfDn = 0.97929;
    }
    else if ( eta < 1.479 ){
      *puJetIDsf   = 0.99080;
      *puJetIDsfUp = 0.99729;
      *puJetIDsfDn = 0.98431;
    }
    else if ( eta < 2.0 ){
      *puJetIDsf   = 0.97770;
      *puJetIDsfUp = 0.99066;
      *puJetIDsfDn = 0.96475;
    }
    else {
      *puJetIDsf   = 0.97016;
      *puJetIDsfUp = 1.00348;
      *puJetIDsfDn = 0.93684;
    }
  }
  else {
    *puJetIDsf   = 1.0;
    *puJetIDsfUp = 1.0;
    *puJetIDsfDn = 1.0;
  }
}

void HardcodedConditions::GetJetPileupIDSF2016( double pt, double eta, double *puJetIDsf, double *puJetIDsfUp, double *puJetIDsfDn ){
  if ( pt < 40.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDsf   = 0.86771;
      *puJetIDsfUp = 0.88420;
      *puJetIDsfDn = 0.85122;
    }
    else if ( eta < -1.479 ){
      *puJetIDsf   = 0.91153;
      *puJetIDsfUp = 0.92341;
      *puJetIDsfDn = 0.89965;
    }
    else if ( eta < 0.0 ){
      *puJetIDsf   = 0.95379;
      *puJetIDsfUp = 0.95882;
      *puJetIDsfDn = 0.94875;
    }
    else if ( eta < 1.479 ){
      *puJetIDsf   = 0.95773;
      *puJetIDsfUp = 0.96221;
      *puJetIDsfDn = 0.95324;
    }
    else if ( eta < 2.0 ){
      *puJetIDsf   = 0.92001;
      *puJetIDsfUp = 0.92690;
      *puJetIDsfDn = 0.91312;
    }
    else {
      *puJetIDsf   = 0.86779;
      *puJetIDsfUp = 0.89193;
      *puJetIDsfDn = 0.84364;
    }
  }
  else if ( pt < 50.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDsf   = 0.88277;
      *puJetIDsfUp = 0.92261;
      *puJetIDsfDn = 0.84293;
    }
    else if ( eta < -1.479 ){
      *puJetIDsf   = 0.91071;
      *puJetIDsfUp = 0.93824;
      *puJetIDsfDn = 0.88317;
    }
    else if ( eta < 0.0 ){
      *puJetIDsf   = 0.95284;
      *puJetIDsfUp = 0.95935;
      *puJetIDsfDn = 0.94632;
    }
    else if ( eta < 1.479 ){
      *puJetIDsf   = 0.96283;
      *puJetIDsfUp = 0.97546;
      *puJetIDsfDn = 0.95019;
    }
    else if ( eta < 2.0 ){
      *puJetIDsf   = 0.92458;
      *puJetIDsfUp = 0.95390;
      *puJetIDsfDn = 0.89526;
    }
    else {
      *puJetIDsf   = 0.88288;
      *puJetIDsfUp = 0.92152;
      *puJetIDsfDn = 0.84424;
    }
  }
  else {
    *puJetIDsf   = 1.0;
    *puJetIDsfUp = 1.0;
    *puJetIDsfDn = 1.0;
  }
}

void HardcodedConditions::GetJetPileupIDSF2017( double pt, double eta, double *puJetIDsf, double *puJetIDsfUp, double *puJetIDsfDn ){
  if ( pt < 40.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDsf   = 0.90366;
      *puJetIDsfUp = 0.92574;
      *puJetIDsfDn = 0.88157;
    }
    else if ( eta < -1.479 ){
      *puJetIDsf   = 0.93747;
      *puJetIDsfUp = 0.94775;
      *puJetIDsfDn = 0.92719;
    }
    else if ( eta < 0.0 ){
      *puJetIDsf   = 0.97475;
      *puJetIDsfUp = 0.98085;
      *puJetIDsfDn = 0.96864;
    }
    else if ( eta < 1.479 ){
      *puJetIDsf   = 0.98245;
      *puJetIDsfUp = 0.98852;
      *puJetIDsfDn = 0.97638;
    }
    else if ( eta < 2.0 ){
      *puJetIDsf   = 0.92917;
      *puJetIDsfUp = 0.94473;
      *puJetIDsfDn = 0.91360;
    }
    else {
      *puJetIDsf   = 0.88668;
      *puJetIDsfUp = 0.91097;
      *puJetIDsfDn = 0.86240;
    }
  }
  else if ( pt < 50.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDsf   = 0.87745;
      *puJetIDsfUp = 0.91613;
      *puJetIDsfDn = 0.83877;
    }
    else if ( eta < -1.479 ){
      *puJetIDsf   = 0.93925;
      *puJetIDsfUp = 0.95844;
      *puJetIDsfDn = 0.92006;
    }
    else if ( eta < 0.0 ){
      *puJetIDsf   = 0.97620;
      *puJetIDsfUp = 0.98168;
      *puJetIDsfDn = 0.97073;
    }
    else if ( eta < 1.479 ){
      *puJetIDsf   = 0.98366;
      *puJetIDsfUp = 0.99112;
      *puJetIDsfDn = 0.97620;
    }
    else if ( eta < 2.0 ){
      *puJetIDsf   = 0.92853;
      *puJetIDsfUp = 0.94687;
      *puJetIDsfDn = 0.91019;
    }
    else {
      *puJetIDsf   = 0.86179;
      *puJetIDsfUp = 0.89902;
      *puJetIDsfDn = 0.82455;
    }
  }
  else {
    *puJetIDsf   = 1.0;
    *puJetIDsfUp = 1.0;
    *puJetIDsfDn = 1.0;
  }
}

void HardcodedConditions::GetJetPileupIDSF2018( double pt, double eta, double *puJetIDsf, double *puJetIDsfUp, double *puJetIDsfDn ){
  if ( pt < 40.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDsf   = 0.91464;
      *puJetIDsfUp = 0.94989;
      *puJetIDsfDn = 0.87939;
    }
    else if ( eta < -1.479 ){
      *puJetIDsf   = 0.94455;
      *puJetIDsfUp = 0.96187;
      *puJetIDsfDn = 0.92722;
    }
    else if ( eta < 0.0 ){
      *puJetIDsf   = 0.96779;
      *puJetIDsfUp = 0.97529;
      *puJetIDsfDn = 0.96028;
    }
    else if ( eta < 1.479 ){
      *puJetIDsf   = 0.97057;
      *puJetIDsfUp = 0.97880;
      *puJetIDsfDn = 0.96234;
    }
    else if ( eta < 2.0 ){
      *puJetIDsf   = 0.93484;
      *puJetIDsfUp = 0.95405;
      *puJetIDsfDn = 0.91564;
    }
    else {
      *puJetIDsf   = 0.91721;
      *puJetIDsfUp = 0.95018;
      *puJetIDsfDn = 0.88425;
    }
  }
  else if ( pt < 50.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDsf   = 0.88748;
      *puJetIDsfUp = 0.92029;
      *puJetIDsfDn = 0.85468;
    }
    else if ( eta < -1.479 ){
      *puJetIDsf   = 0.93207;
      *puJetIDsfUp = 0.96865;
      *puJetIDsfDn = 0.89549;
    }
    else if ( eta < 0.0 ){
      *puJetIDsf   = 0.96150;
      *puJetIDsfUp = 0.97160;
      *puJetIDsfDn = 0.95140;
    }
    else if ( eta < 1.479 ){
      *puJetIDsf   = 0.96443;
      *puJetIDsfUp = 0.97089;
      *puJetIDsfDn = 0.95798;
    }
    else if ( eta < 2.0 ){
      *puJetIDsf   = 0.93855;
      *puJetIDsfUp = 0.97602;
      *puJetIDsfDn = 0.90108;
    }
    else {
      *puJetIDsf   = 0.89367;
      *puJetIDsfUp = 0.93227;
      *puJetIDsfDn = 0.85506;
    }
  }
  else {
    *puJetIDsf   = 1.0;
    *puJetIDsfUp = 1.0;
    *puJetIDsfDn = 1.0;
  }
}


/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
  |  /   \                                                       /   \  |
  | |\_.  |                                                     |    /| |
  |\|  | /|           Jet pileup ID Efficiency                  |\  | |/|
  | `---' |                                                     | `---' |
  |       |                                                     |       |
  |       |-----------------------------------------------------|       |
  \       |                                                     |       /
   \     /                                                       \     /
    `---'                                                         `---'*/
void HardcodedConditions::GetJetPileupIDEff( double pt, double eta, double *puJetIDEff, std::string year ){
  *puJetIDEff   = 1.0;
  if      ( year == "2016APV" ) GetJetPileupIDEff2016APV( pt, eta, puJetIDEff );
  else if ( year == "2016" ) GetJetPileupIDEff2016( pt, eta, puJetIDEff );
  else if ( year == "2017" ) GetJetPileupIDEff2017( pt, eta, puJetIDEff );
  else if ( year == "2018" ) GetJetPileupIDEff2018( pt, eta, puJetIDEff );
}

void HardcodedConditions::GetJetPileupIDEff2016APV( double pt, double eta, double *puJetIDEff ){
  if ( pt < 40.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDEff   = 0.55150;
    }
    else if ( eta < -1.479 ){
      *puJetIDEff   = 0.69260;
    }
    else if ( eta < 0.0 ){
      *puJetIDEff   = 0.85670;
    }
    else if ( eta < 1.479 ){
      *puJetIDEff   = 0.86070;
    }
    else if ( eta < 2.0 ){
      *puJetIDEff   = 0.72240;
    }
    else {
      *puJetIDEff   = 0.51950;
    }
  }
  else if ( pt < 50.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDEff   = 0.46450;
    }
    else if ( eta < -1.479 ){
      *puJetIDEff   = 0.64530;
    }
    else if ( eta < 0.0 ){
      *puJetIDEff   = 0.83280;
    }
    else if ( eta < 1.479 ){
      *puJetIDEff   = 0.83710;
    }
    else if ( eta < 2.0 ){
      *puJetIDEff   = 0.65480;
    }
    else {
      *puJetIDEff   = 0.44570;
    }
  }
  else {
    *puJetIDEff   = 1.0;
  }
}

void HardcodedConditions::GetJetPileupIDEff2016( double pt, double eta, double *puJetIDEff ){
  if ( pt < 40.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDEff   = 0.57450;
    }
    else if ( eta < -1.479 ){
      *puJetIDEff   = 0.72680;
    }
    else if ( eta < 0.0 ){
      *puJetIDEff   = 0.86340;
    }
    else if ( eta < 1.479 ){
      *puJetIDEff   = 0.86110;
    }
    else if ( eta < 2.0 ){
      *puJetIDEff   = 0.72760;
    }
    else {
      *puJetIDEff   = 0.55290;
    }
  }
  else if ( pt < 50.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDEff   = 0.48280;
    }
    else if ( eta < -1.479 ){
      *puJetIDEff   = 0.66410;
    }
    else if ( eta < 0.0 ){
      *puJetIDEff   = 0.84390;
    }
    else if ( eta < 1.479 ){
      *puJetIDEff   = 0.83390;
    }
    else if ( eta < 2.0 ){
      *puJetIDEff   = 0.66030;
    }
    else {
      *puJetIDEff   = 0.46790;
    }
  }
  else {
    *puJetIDEff   = 1.0;
  }
}

void HardcodedConditions::GetJetPileupIDEff2017( double pt, double eta, double *puJetIDEff ){
  if ( pt < 40.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDEff   = 0.67780;
    }
    else if ( eta < -1.479 ){
      *puJetIDEff   = 0.75160;
    }
    else if ( eta < 0.0 ){
      *puJetIDEff   = 0.85140;
    }
    else if ( eta < 1.479 ){
      *puJetIDEff   = 0.84320;
    }
    else if ( eta < 2.0 ){
      *puJetIDEff   = 0.74260;
    }
    else {
      *puJetIDEff   = 0.64510;
    }
  }
  else if ( pt < 50.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDEff   = 0.62180;
    }
    else if ( eta < -1.479 ){
      *puJetIDEff   = 0.70950;
    }
    else if ( eta < 0.0 ){
      *puJetIDEff   = 0.83630;
    }
    else if ( eta < 1.479 ){
      *puJetIDEff   = 0.82640;
    }
    else if ( eta < 2.0 ){
      *puJetIDEff   = 0.69960;
    }
    else {
      *puJetIDEff   = 0.58460;
    }
  }
  else {
    *puJetIDEff   = 1.0;
  }
}

void HardcodedConditions::GetJetPileupIDEff2018( double pt, double eta, double *puJetIDEff ){
  if ( pt < 40.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDEff   = 0.63850;
    }
    else if ( eta < -1.479 ){
      *puJetIDEff   = 0.71230;
    }
    else if ( eta < 0.0 ){
      *puJetIDEff   = 0.82270;
    }
    else if ( eta < 1.479 ){
      *puJetIDEff   = 0.81550;
    }
    else if ( eta < 2.0 ){
      *puJetIDEff   = 0.71980;
    }
    else {
      *puJetIDEff   = 0.62330;
    }
  }
  else if ( pt < 50.0 ) {
    if ( eta < -2.0 ) {
      *puJetIDEff   = 0.56970;
    }
    else if ( eta < -1.479 ){
      *puJetIDEff   = 0.67130;
    }
    else if ( eta < 0.0 ){
      *puJetIDEff   = 0.80000;
    }
    else if ( eta < 1.479 ){
      *puJetIDEff   = 0.79290;
    }
    else if ( eta < 2.0 ){
      *puJetIDEff   = 0.66230;
    }
    else {
      *puJetIDEff   = 0.56050;
    }
  }
  else {
    *puJetIDEff   = 1.0;
  }
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
  |  /   \                                                       /   \  |
  | |\_.  |                                                     |    /| |
  |\|  | /|               Jet Veto Map                          |\  | |/|
  | `---' |                                                     | `---' |
  |       |                                                     |       |
  |       |-----------------------------------------------------|       |
  \       |                                                     |       /
   \     /                                                       \     /
    `---'                                                         `---'*/
// Extracted using the correctionlib tool from the JSON POG: https://gitlab.cern.ch/cms-nanoAOD/jsonpog-integration
// Using the analysis recommended working point "jetvetomap": https://twiki.cern.ch/twiki/bin/view/CMS/JECDataMC#Jet_veto_maps

bool HardcodedConditions::GetJetVetoMap( double eta, double phi, std::string year ){
  if      ( year == "2016APV" ) GetJetVetoMap2016( eta, phi ); // 2016preVFP and postVFP use same veto map
  else if ( year == "2016" ) GetJetVetoMap2016( eta, phi );
  else if ( year == "2017" ) GetJetVetoMap2017( eta, phi );
  else if ( year == "2018" ) GetJetVetoMap2018( eta, phi ); // complements the HEM 15/16 electron veto
  return false;
}

bool HardcodedConditions::GetJetVetoMap2016( double eta, double phi ){
  if ( ( eta >= -3.839 && eta < -3.664 ) && ( phi >= -3.142 && phi < -3.054 ) ) return true;
  if ( ( eta >= -3.839 && eta < -3.664 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= -3.664 && eta < -3.489 ) && ( phi >= 1.833 && phi < 1.920 ) ) return true;
  if ( ( eta >= -3.664 && eta < -3.489 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= -2.853 && eta < -2.650 ) && ( phi >= 1.833 && phi < 1.920 ) ) return true;
  if ( ( eta >= -2.650 && eta < -2.500 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -1.930 && eta < -1.830 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= -1.392 && eta < -1.305 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -1.305 && eta < -1.218 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -1.218 && eta < -1.131 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -1.131 && eta < -1.044 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -1.044 && eta < -0.957 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.957 && eta < -0.879 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.879 && eta < -0.783 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.783 && eta < -0.696 ) && ( phi >= 0.262 && phi < 0.349 ) ) return true;
  if ( ( eta >= -0.783 && eta < -0.696 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.696 && eta < -0.609 ) && ( phi >= 0.262 && phi < 0.349 ) ) return true;
  if ( ( eta >= -0.696 && eta < -0.609 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.609 && eta < -0.522 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.609 && eta < -0.522 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= -0.522 && eta < -0.435 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.522 && eta < -0.435 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= -0.435 && eta < -0.348 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.348 && eta < -0.261 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.261 && eta < -0.174 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.174 && eta < -0.087 ) && ( phi >= -1.745 && phi < -1.658 ) ) return true;
  if ( ( eta >= -0.174 && eta < -0.087 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.087 && eta < 0.000 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= -0.087 && eta < 0.000 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= -0.087 && eta < 0.000 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.000 && eta < 0.087 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.000 && eta < 0.087 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.087 && eta < 0.174 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.087 && eta < 0.174 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.174 && eta < 0.261 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.174 && eta < 0.261 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.261 && eta < 0.348 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.261 && eta < 0.348 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.348 && eta < 0.435 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.348 && eta < 0.435 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.435 && eta < 0.522 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.435 && eta < 0.522 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.783 && eta < 0.879 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.783 && eta < 0.879 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.879 && eta < 0.957 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.879 && eta < 0.957 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.957 && eta < 1.044 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.957 && eta < 1.044 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 1.044 && eta < 1.131 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 1.044 && eta < 1.131 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 1.131 && eta < 1.218 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 1.131 && eta < 1.218 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 1.930 && eta < 2.043 ) && ( phi >= -1.745 && phi < -1.658 ) ) return true;
  if ( ( eta >= 1.930 && eta < 2.043 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= 2.172 && eta < 2.322 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= 2.322 && eta < 2.500 ) && ( phi >= -0.611 && phi < -0.524 ) ) return true;
  if ( ( eta >= 2.322 && eta < 2.500 ) && ( phi >= -0.436 && phi < -0.349 ) ) return true;
  if ( ( eta >= 2.650 && eta < 2.853 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 2.650 && eta < 2.853 ) && ( phi >= 2.356 && phi < 2.443 ) ) return true;
  if ( ( eta >= 2.650 && eta < 2.853 ) && ( phi >= 2.443 && phi < 2.531 ) ) return true;
  if ( ( eta >= 2.853 && eta < 2.964 ) && ( phi >= -3.054 && phi < -2.967 ) ) return true;
  if ( ( eta >= 2.853 && eta < 2.964 ) && ( phi >= -2.967 && phi < -2.880 ) ) return true;
  if ( ( eta >= 2.853 && eta < 2.964 ) && ( phi >= 1.047 && phi < 1.134 ) ) return true;
  if ( ( eta >= 2.853 && eta < 2.964 ) && ( phi >= 1.134 && phi < 1.222 ) ) return true;
  if ( ( eta >= 2.853 && eta < 2.964 ) && ( phi >= 1.309 && phi < 1.396 ) ) return true;
  if ( ( eta >= 2.964 && eta < 3.139 ) && ( phi >= -3.054 && phi < -2.967 ) ) return true;
  if ( ( eta >= 2.964 && eta < 3.139 ) && ( phi >= -2.967 && phi < -2.880 ) ) return true;
  if ( ( eta >= 3.139 && eta < 3.314 ) && ( phi >= -3.054 && phi < -2.967 ) ) return true;
  if ( ( eta >= 3.139 && eta < 3.314 ) && ( phi >= -2.967 && phi < -2.880 ) ) return true;
  if ( ( eta >= 3.139 && eta < 3.314 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 3.314 && eta < 3.489 ) && ( phi >= -3.054 && phi < -2.967 ) ) return true;
  if ( ( eta >= 3.314 && eta < 3.489 ) && ( phi >= -2.967 && phi < -2.880 ) ) return true;
  if ( ( eta >= 3.314 && eta < 3.489 ) && ( phi >= 2.531 && phi < 2.618 ) ) return true;
  if ( ( eta >= 3.489 && eta < 3.664 ) && ( phi >= -3.054 && phi < -2.967 ) ) return true;
  if ( ( eta >= 3.489 && eta < 3.664 ) && ( phi >= -2.967 && phi < -2.880 ) ) return true;
  return false;
}

bool HardcodedConditions::GetJetVetoMap2017( double eta, double phi ){
  if ( ( eta >= -3.139 && eta < -2.964 ) && ( phi >= 2.094 && phi < 2.182 ) ) return true;
  if ( ( eta >= -3.139 && eta < -2.964 ) && ( phi >= 2.182 && phi < 2.269 ) ) return true;
  if ( ( eta >= -3.139 && eta < -2.964 ) && ( phi >= 2.269 && phi < 2.356 ) ) return true;
  if ( ( eta >= -3.139 && eta < -2.964 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= -2.964 && eta < -2.853 ) && ( phi >= 2.094 && phi < 2.182 ) ) return true;
  if ( ( eta >= -2.964 && eta < -2.853 ) && ( phi >= 2.182 && phi < 2.269 ) ) return true;
  if ( ( eta >= -2.964 && eta < -2.853 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= -2.043 && eta < -1.930 ) && ( phi >= -0.349 && phi < -0.262 ) ) return true;
  if ( ( eta >= -2.043 && eta < -1.930 ) && ( phi >= -0.262 && phi < -0.175 ) ) return true;
  if ( ( eta >= -0.696 && eta < -0.609 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.609 && eta < -0.522 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.522 && eta < -0.435 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.087 && eta < 0.000 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= -0.087 && eta < 0.000 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= -0.087 && eta < 0.000 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= -0.087 && eta < 0.000 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= -0.087 && eta < 0.000 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 0.000 && eta < 0.087 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 0.000 && eta < 0.087 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 0.000 && eta < 0.087 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 0.000 && eta < 0.087 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 0.000 && eta < 0.087 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 0.087 && eta < 0.174 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 0.087 && eta < 0.174 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 0.087 && eta < 0.174 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 0.087 && eta < 0.174 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 0.087 && eta < 0.174 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 0.174 && eta < 0.261 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 0.174 && eta < 0.261 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 0.174 && eta < 0.261 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 0.174 && eta < 0.261 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 0.174 && eta < 0.261 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 0.261 && eta < 0.348 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 0.261 && eta < 0.348 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 0.261 && eta < 0.348 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 0.261 && eta < 0.348 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 0.261 && eta < 0.348 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 0.348 && eta < 0.435 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.348 && eta < 0.435 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 0.348 && eta < 0.435 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 0.348 && eta < 0.435 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 0.348 && eta < 0.435 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 0.348 && eta < 0.435 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 0.435 && eta < 0.522 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 0.435 && eta < 0.522 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 0.435 && eta < 0.522 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 0.435 && eta < 0.522 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 0.435 && eta < 0.522 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 0.783 && eta < 0.879 ) && ( phi >= -2.531 && phi < -2.443 ) ) return true;
  if ( ( eta >= 0.783 && eta < 0.879 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 0.783 && eta < 0.879 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 0.783 && eta < 0.879 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 0.783 && eta < 0.879 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 0.783 && eta < 0.879 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 0.879 && eta < 0.957 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 0.879 && eta < 0.957 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 0.879 && eta < 0.957 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 0.879 && eta < 0.957 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 0.879 && eta < 0.957 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 0.957 && eta < 1.044 ) && ( phi >= -2.443 && phi < -2.356 ) ) return true;
  if ( ( eta >= 0.957 && eta < 1.044 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 0.957 && eta < 1.044 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 0.957 && eta < 1.044 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 0.957 && eta < 1.044 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 0.957 && eta < 1.044 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 1.044 && eta < 1.131 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 1.044 && eta < 1.131 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 1.044 && eta < 1.131 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 1.044 && eta < 1.131 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 1.044 && eta < 1.131 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 1.131 && eta < 1.218 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 1.131 && eta < 1.218 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 1.131 && eta < 1.218 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 1.131 && eta < 1.218 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 1.131 && eta < 1.218 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 1.218 && eta < 1.305 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 1.218 && eta < 1.305 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 1.218 && eta < 1.305 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 1.218 && eta < 1.305 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 1.218 && eta < 1.305 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 1.218 && eta < 1.305 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 1.218 && eta < 1.305 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 1.218 && eta < 1.305 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 1.218 && eta < 1.305 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 1.305 && eta < 1.392 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 1.305 && eta < 1.392 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 1.305 && eta < 1.392 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 1.305 && eta < 1.392 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 1.305 && eta < 1.392 ) && ( phi >= 2.618 && phi < 2.705 ) ) return true;
  if ( ( eta >= 1.305 && eta < 1.392 ) && ( phi >= 2.705 && phi < 2.793 ) ) return true;
  if ( ( eta >= 1.305 && eta < 1.392 ) && ( phi >= 2.793 && phi < 2.880 ) ) return true;
  if ( ( eta >= 1.305 && eta < 1.392 ) && ( phi >= 2.880 && phi < 2.967 ) ) return true;
  if ( ( eta >= 1.305 && eta < 1.392 ) && ( phi >= 2.967 && phi < 3.054 ) ) return true;
  if ( ( eta >= 1.392 && eta < 1.479 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 1.392 && eta < 1.479 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 1.392 && eta < 1.479 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 1.392 && eta < 1.479 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 1.479 && eta < 1.566 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 1.479 && eta < 1.566 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 1.479 && eta < 1.566 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 1.479 && eta < 1.566 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 1.566 && eta < 1.653 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 1.566 && eta < 1.653 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 1.566 && eta < 1.653 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 1.566 && eta < 1.653 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 1.653 && eta < 1.740 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 1.653 && eta < 1.740 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 1.653 && eta < 1.740 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 1.653 && eta < 1.740 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 1.740 && eta < 1.830 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 1.740 && eta < 1.830 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 1.740 && eta < 1.830 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 1.740 && eta < 1.830 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 1.830 && eta < 1.930 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 1.830 && eta < 1.930 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 1.830 && eta < 1.930 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 1.830 && eta < 1.930 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 1.930 && eta < 2.043 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 1.930 && eta < 2.043 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 1.930 && eta < 2.043 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 1.930 && eta < 2.043 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 2.043 && eta < 2.172 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 2.043 && eta < 2.172 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 2.043 && eta < 2.172 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 2.043 && eta < 2.172 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 2.172 && eta < 2.322 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 2.172 && eta < 2.322 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 2.172 && eta < 2.322 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 2.172 && eta < 2.322 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 2.322 && eta < 2.500 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 2.322 && eta < 2.500 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 2.322 && eta < 2.500 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 2.322 && eta < 2.500 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 2.500 && eta < 2.650 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 2.500 && eta < 2.650 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 2.500 && eta < 2.650 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 2.500 && eta < 2.650 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 2.650 && eta < 2.853 ) && ( phi >= -0.960 && phi < -0.873 ) ) return true;
  if ( ( eta >= 2.650 && eta < 2.853 ) && ( phi >= -0.873 && phi < -0.785 ) ) return true;
  if ( ( eta >= 2.650 && eta < 2.853 ) && ( phi >= -0.785 && phi < -0.698 ) ) return true;
  if ( ( eta >= 2.650 && eta < 2.853 ) && ( phi >= -0.698 && phi < -0.611 ) ) return true;
  if ( ( eta >= 2.650 && eta < 2.853 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 2.650 && eta < 2.853 ) && ( phi >= 0.698 && phi < 0.785 ) ) return true;
  return false;
}

bool HardcodedConditions::GetJetVetoMap2018( double eta, double phi ){
  if ( ( eta >= -3.139 && eta < -2.964 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -3.139 && eta < -2.964 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -3.139 && eta < -2.964 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -3.139 && eta < -2.964 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -3.139 && eta < -2.964 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -3.139 && eta < -2.964 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -3.139 && eta < -2.964 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -3.139 && eta < -2.964 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -2.964 && eta < -2.853 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -2.964 && eta < -2.853 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -2.964 && eta < -2.853 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -2.964 && eta < -2.853 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -2.964 && eta < -2.853 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -2.964 && eta < -2.853 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -2.964 && eta < -2.853 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -2.964 && eta < -2.853 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -2.853 && eta < -2.650 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -2.853 && eta < -2.650 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -2.853 && eta < -2.650 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -2.853 && eta < -2.650 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -2.853 && eta < -2.650 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -2.853 && eta < -2.650 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -2.853 && eta < -2.650 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -2.853 && eta < -2.650 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -2.650 && eta < -2.500 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -2.650 && eta < -2.500 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -2.650 && eta < -2.500 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -2.650 && eta < -2.500 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -2.650 && eta < -2.500 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -2.650 && eta < -2.500 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -2.650 && eta < -2.500 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -2.650 && eta < -2.500 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -2.500 && eta < -2.322 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -2.500 && eta < -2.322 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -2.500 && eta < -2.322 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -2.500 && eta < -2.322 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -2.500 && eta < -2.322 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -2.500 && eta < -2.322 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -2.500 && eta < -2.322 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -2.500 && eta < -2.322 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -2.322 && eta < -2.172 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -2.322 && eta < -2.172 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -2.322 && eta < -2.172 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -2.322 && eta < -2.172 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -2.322 && eta < -2.172 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -2.322 && eta < -2.172 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -2.322 && eta < -2.172 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -2.322 && eta < -2.172 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -2.172 && eta < -2.043 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -2.172 && eta < -2.043 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -2.172 && eta < -2.043 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -2.172 && eta < -2.043 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -2.172 && eta < -2.043 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -2.172 && eta < -2.043 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -2.172 && eta < -2.043 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -2.172 && eta < -2.043 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -2.043 && eta < -1.930 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -2.043 && eta < -1.930 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -2.043 && eta < -1.930 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -2.043 && eta < -1.930 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -2.043 && eta < -1.930 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -2.043 && eta < -1.930 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -2.043 && eta < -1.930 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -2.043 && eta < -1.930 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -1.930 && eta < -1.830 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -1.930 && eta < -1.830 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -1.930 && eta < -1.830 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -1.930 && eta < -1.830 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -1.930 && eta < -1.830 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -1.930 && eta < -1.830 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -1.930 && eta < -1.830 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -1.930 && eta < -1.830 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -1.830 && eta < -1.740 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -1.830 && eta < -1.740 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -1.830 && eta < -1.740 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -1.830 && eta < -1.740 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -1.830 && eta < -1.740 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -1.830 && eta < -1.740 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -1.830 && eta < -1.740 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -1.830 && eta < -1.740 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -1.740 && eta < -1.653 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -1.740 && eta < -1.653 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -1.740 && eta < -1.653 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -1.740 && eta < -1.653 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -1.740 && eta < -1.653 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -1.740 && eta < -1.653 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -1.740 && eta < -1.653 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -1.740 && eta < -1.653 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -1.653 && eta < -1.566 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -1.653 && eta < -1.566 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -1.653 && eta < -1.566 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -1.653 && eta < -1.566 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -1.653 && eta < -1.566 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -1.653 && eta < -1.566 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -1.653 && eta < -1.566 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -1.653 && eta < -1.566 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -1.566 && eta < -1.479 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -1.566 && eta < -1.479 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -1.566 && eta < -1.479 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -1.566 && eta < -1.479 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -1.566 && eta < -1.479 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -1.566 && eta < -1.479 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -1.566 && eta < -1.479 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -1.566 && eta < -1.479 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -1.479 && eta < -1.392 ) && ( phi >= -1.658 && phi < -1.571 ) ) return true;
  if ( ( eta >= -1.479 && eta < -1.392 ) && ( phi >= -1.571 && phi < -1.484 ) ) return true;
  if ( ( eta >= -1.479 && eta < -1.392 ) && ( phi >= -1.484 && phi < -1.396 ) ) return true;
  if ( ( eta >= -1.479 && eta < -1.392 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= -1.479 && eta < -1.392 ) && ( phi >= -1.309 && phi < -1.222 ) ) return true;
  if ( ( eta >= -1.479 && eta < -1.392 ) && ( phi >= -1.222 && phi < -1.134 ) ) return true;
  if ( ( eta >= -1.479 && eta < -1.392 ) && ( phi >= -1.134 && phi < -1.047 ) ) return true;
  if ( ( eta >= -1.479 && eta < -1.392 ) && ( phi >= -1.047 && phi < -0.960 ) ) return true;
  if ( ( eta >= -1.218 && eta < -1.131 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.087 && eta < 0.000 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= -0.087 && eta < 0.000 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= -0.087 && eta < 0.000 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= -0.087 && eta < 0.000 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 0.000 && eta < 0.087 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.000 && eta < 0.087 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 0.000 && eta < 0.087 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 0.000 && eta < 0.087 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 0.087 && eta < 0.174 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.087 && eta < 0.174 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 0.087 && eta < 0.174 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 0.087 && eta < 0.174 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 0.174 && eta < 0.261 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.174 && eta < 0.261 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 0.174 && eta < 0.261 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 0.174 && eta < 0.261 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 0.261 && eta < 0.348 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.261 && eta < 0.348 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 0.261 && eta < 0.348 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 0.261 && eta < 0.348 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 0.348 && eta < 0.435 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.348 && eta < 0.435 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 0.348 && eta < 0.435 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 0.348 && eta < 0.435 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 0.435 && eta < 0.522 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.435 && eta < 0.522 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 0.435 && eta < 0.522 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 0.435 && eta < 0.522 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 0.522 && eta < 0.609 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 0.609 && eta < 0.696 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 0.696 && eta < 0.783 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 0.783 && eta < 0.879 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.783 && eta < 0.879 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 0.783 && eta < 0.879 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 0.783 && eta < 0.879 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 0.879 && eta < 0.957 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.879 && eta < 0.957 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 0.879 && eta < 0.957 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 0.879 && eta < 0.957 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 0.957 && eta < 1.044 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 0.957 && eta < 1.044 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 0.957 && eta < 1.044 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 0.957 && eta < 1.044 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 1.044 && eta < 1.131 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 1.044 && eta < 1.131 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 1.044 && eta < 1.131 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 1.044 && eta < 1.131 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 1.131 && eta < 1.218 ) && ( phi >= 0.349 && phi < 0.436 ) ) return true;
  if ( ( eta >= 1.131 && eta < 1.218 ) && ( phi >= 0.436 && phi < 0.524 ) ) return true;
  if ( ( eta >= 1.131 && eta < 1.218 ) && ( phi >= 0.524 && phi < 0.611 ) ) return true;
  if ( ( eta >= 1.131 && eta < 1.218 ) && ( phi >= 0.611 && phi < 0.698 ) ) return true;
  if ( ( eta >= 1.479 && eta < 1.566 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= 1.566 && eta < 1.653 ) && ( phi >= -1.396 && phi < -1.309 ) ) return true;
  if ( ( eta >= 2.322 && eta < 2.500 ) && ( phi >= -0.611 && phi < -0.524 ) ) return true;
  return false;
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|           ttHF SF                                   |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

float HardcodedConditions::GetTtHfSF(bool isTT, bool isTTHF, bool isTTLF){
  if (isTT) {
    if (isTTHF) return 4.7/3.9; 
    if (isTTLF) return 0.989;
  }
  return 1.0;
}

/*.-----------------------------------------------------------------.
  /  .-.                                                         .-.  \
 |  /   \                                                       /   \  |
 | |\_.  |                                                     |    /| |
 |\|  | /|                MET Phi Corrections                  |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/
// values taken from https://lathomas.web.cern.ch/lathomas/METStuff/XYCorrections/XYMETCorrection_withUL17andUL18andUL16.h

void HardcodedConditions::GetMETPhiCorrection( Double_t *met, Double_t *met_phi, int nPV, int nRun, std::string era, bool isMC ){
  double met_x_corr(0.); double met_y_corr(0.);
  double pi = 3.14159265359;
  if( era ==  "2016APV" || era == "2016" ) GetMETPhiCorrection2016( &met_x_corr, &met_y_corr, nPV, nRun, era, isMC );
  else if( era == "2017" ) GetMETPhiCorrection2017( &met_x_corr, &met_y_corr, nPV, nRun, isMC );
  else if( era == "2018" ) GetMETPhiCorrection2018( &met_x_corr, &met_y_corr, nPV, nRun, isMC );
  
  met_x_corr += *met * cos( *met_phi );
  met_y_corr += *met * sin( *met_phi );

  double met_corr = sqrt( met_x_corr * met_x_corr + met_y_corr * met_y_corr );
  double met_phi_corr;
  if( met_x_corr == 0 && met_y_corr > 0 ) met_phi_corr = pi;
  else if( met_x_corr == 0 && met_y_corr < 0 ) met_phi_corr = -pi; 
  else if( met_x_corr > 0 ) met_phi_corr = TMath::ATan( met_y_corr / met_x_corr );
  else if( met_x_corr < 0 && met_y_corr > 0 ) met_phi_corr = TMath::ATan( met_y_corr / met_x_corr ) + pi;
  else if( met_x_corr < 0 && met_y_corr < 0 ) met_phi_corr = TMath::ATan( met_y_corr / met_x_corr ) - pi;
  else met_phi_corr = 0;

  *met = met_corr;
  *met_phi = met_phi_corr;
}

void HardcodedConditions::GetMETPhiCorrection2016( double *met_x_corr, double *met_y_corr, double nPV, double nRun, std::string era, bool isMC ){
  if( isMC ){
    if( era == "2016APV" ){
      *met_x_corr = -( -0.188743 * nPV + 0.136539 );
      *met_y_corr = -( 0.0127927 * nPV + 0.117747 );
    }
    else if( era == "2016" ){
      *met_x_corr = -( -0.188743 * nPV + 0.136539);
      *met_y_corr = -( 0.0127927 * nPV + 0.117747);
    }
  }
  else {
    if( nRun >= 272007 && nRun <= 275656 ){
      *met_x_corr = -( -0.0214894 * nPV + -0.188255 );
      *met_y_corr = -( 0.0876624 * nPV + 0.812885 );
    }
    else if( nRun >= 275657 && nRun <= 276283 ){
      *met_x_corr = -( -0.032209 * nPV + 0.067288 );
      *met_y_corr = -( 0.113917 * nPV + 0.743906 );
    }
    else if( nRun >= 276315 && nRun <= 276811 ){
      *met_x_corr = -( -0.0293663 * nPV + 0.21106 );
      *met_y_corr = -( 0.11331 * nPV + 0.815787 );
    }
    else if( nRun >= 276831 && nRun <= 277420 ){
      *met_x_corr = -( -0.0132046 * nPV + 0.20073 );
      *met_y_corr = -( 0.134809 * nPV + 0.679068 );
    }
    else if( ( nRun >= 277772 && nRun <= 278768 ) || nRun == 278770 ){
      *met_x_corr = -( -0.0543566 * nPV + 0.816597 );
      *met_y_corr = -( 0.114225 * nPV + 1.17266 );
    }
    else if( ( nRun >= 278801 && nRun <= 278808 ) || nRun == 278769 ){
      *met_x_corr = -( 0.134616 * nPV + -0.89965 );
      *met_y_corr = -( 0.0397736 * nPV + 1.0385 );
    }
    else if( nRun >= 278820 && nRun <= 280385 ){
      *met_x_corr = -( 0.121809 * nPV + -0.584893 );
      *met_y_corr = -( 0.0558974 * nPV + 0.891234 );
    }
    else if( nRun >= 280919 && nRun <= 284044 ){
      *met_x_corr = -( 0.0868828 * nPV + -0.703489 );
      *met_y_corr = -( 0.0888774 * nPV + 0.902632 );
    }
  }
}

void HardcodedConditions::GetMETPhiCorrection2017( double *met_x_corr, double *met_y_corr, double nPV, double nRun, bool isMC ){
  if( isMC ){
    *met_x_corr = -( -0.300155 * nPV + 1.90608 );
    *met_y_corr = -( 0.300213 * nPV + -2.02232 );
  }
  else {
    if( nRun >= 297020 && nRun <= 299329 ){
      *met_x_corr = -( -0.211161 * nPV + 0.419333 );
      *met_y_corr = -( 0.251789 * nPV + -1.28089 );
    }
    else if( nRun >= 299337 && nRun <= 302029 ){
      *met_x_corr = -( -0.185184 * nPV + -0.164009 );
      *met_y_corr = -( 0.200941 * nPV + -0.56853 );
    }
    else if( nRun >= 302030 && nRun <= 303434 ){
      *met_x_corr = -( -0.201606 * nPV + 0.426502 );
      *met_y_corr = -( 0.188208 * nPV + -0.58313 );
    }
    else if( nRun >= 302435 && nRun <= 304826 ){
      *met_x_corr = -( -0.162472 * nPV + 0.176329 );
      *met_y_corr = -( 0.138076 * nPV + -0.250239 );
    }
    else if( nRun >= 304911 && nRun <= 306462 ){
      *met_x_corr = -( -0.210639 * nPV + 0.72934 );
      *met_y_corr = -( 0.198626 * nPV + 1.028 );
}
  }
}

void HardcodedConditions::GetMETPhiCorrection2018( double *met_x_corr, double *met_y_corr, double nPV, double nRun, bool isMC ){
  if( isMC ){
    *met_x_corr = -( 0.183518 * nPV + 0.546754 );
    *met_y_corr = -( 0.192263 * nPV + -0.42121 );

  }
  else {
    if( nRun >= 315252 && nRun <= 316995 ){
      *met_x_corr = -( 0.263733 * nPV + -1.91115 );
      *met_y_corr = -( 0.0431304 * nPV + -0.112043 );
    }
    else if( nRun >= 316998 && nRun <= 319312 ){
      *met_x_corr = -( 0.400466 * nPV + -3.05914 );
      *met_y_corr = -( 0.146125 * nPV + -0.533233 );
    }
    else if( nRun >= 319313 && nRun <= 320393 ){
      *met_x_corr = -( 0.430911 * nPV + -1.42865 );
      *met_y_corr = -( 0.0620083 * nPV + -1.46021 );
    }
    else if( nRun >= 320394 && nRun <= 325273 ){
      *met_x_corr = -( 0.457327 * nPV + -1.56856 );
      *met_y_corr = -( 0.0684071 * nPV + -0.928372 );
    }
  }
}
