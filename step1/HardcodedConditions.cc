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

double HardcodedConditions::GetEGammaGsfSF(double pt, double eta, std::string year)
{
  //The main getter for EGammaGsf Scale Factors
  if      (year=="2016APV") return GetEGammaGsfSF2016APV(pt, eta);
  else if (year=="2016") return GetEGammaGsfSF2016(pt, eta);
  else if (year=="2017") return GetEGammaGsfSF2017(pt, eta);
  else if (year=="2018") return GetEGammaGsfSF2018(pt, eta);
  else return 0.;
}

double HardcodedConditions::GetEGammaGsfSF2016APV(double pt, double eta){
	// From "RecoAbove20" in EG SF json
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

double HardcodedConditions::GetEGammaGsfSF2016( double pt, double eta ){
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

double HardcodedConditions::GetEGammaGsfSF2017(double pt, double eta){
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

double HardcodedConditions::GetEGammaGsfSF2018(double pt, double eta){
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

double HardcodedConditions::GetElectronIdSF(double pt, double eta, std::string year)
{
  //The main getter for Electron Id Scale Factors
  if      (year=="2016APV") return GetElectronIdSF2016APV(pt, eta);
  else if (year=="2016") return GetElectronIdSF2016(pt, eta);
  else if (year=="2017") return GetElectronIdSF2017(pt, eta);
  else if (year=="2018") return GetElectronIdSF2018(pt, eta);
  else return 0.;
}//end GetElectronIdSF

double HardcodedConditions::GetElectronIdSF2016APV(double pt, double eta){
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

double HardcodedConditions::GetElectronIdSF2016(double pt, double eta){
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
		
double HardcodedConditions::GetElectronIdSF2017(double pt, double eta){
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

double HardcodedConditions::GetElectronIdSF2018(double pt, double eta){
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

// using EOY SF for HLT_ele32_eta2p1_WPTight_Gsf_v* approved by KIT for Run 2016
// https://github.com/TopBrussels/TopTreeAnalysisBase/blob/CMSSW_80X/Calibrations/LeptonSF/ElectronSF/SF_HLT_Ele32_eta2p1.root
double HardcodedConditions::GetElectronTriggerSF2016APV(double pt, double eta){
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

double HardcodedConditions::GetElectronTriggerXSF(double pt, double eta, std::string year){
  if      (year=="2016APV") return GetElectronTriggerXSF2016APV(pt, eta);
  else if (year=="2016") return GetElectronTriggerXSF2017(pt, eta);
  else if (year=="2017") return GetElectronTriggerXSF2017(pt, eta);
  else if (year=="2018") return GetElectronTriggerXSF2018(pt, eta);
  else return 0. ;
}

double HardcodedConditions::GetElectronTriggerXSF2016APV(double pt, double eta){
  double scaleCDEF = 17.516 / 20.442;
  double scaleB    = ( 1. - scaleCDEF );
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.08659 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.12455 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.20537 * scaleCDEF;
    else return 1.21035 * scaleCDEF; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.06639 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.09437 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.16554 * scaleCDEF;
    else return 1.14364 * scaleCDEF; }
  else if ( pt < 32.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.06292 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.07619 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.12446 * scaleCDEF;
    else return 1.12838 * scaleCDEF; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.58314 * scaleB + 1.06292 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 2.06786 * scaleB + 1.07619 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.01020 * scaleB + 1.12446 * scaleCDEF;
    else return 0.38932 * scaleB + 1.12838 * scaleCDEF; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.19383 * scaleB + 1.05618 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.12618 * scaleB + 1.06484 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.95816 * scaleB + 1.10320 * scaleCDEF;
    else return 0.78417 * scaleB + 1.08899 * scaleCDEF; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.23217 * scaleB + 1.04434 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.14523 * scaleB + 1.05515 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.04984 * scaleB + 1.08740 * scaleCDEF;
    else return 0.81113 * scaleB + 1.06669 * scaleCDEF; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.24198 * scaleB + 1.03586 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.17750 * scaleB + 1.04011 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.99915 * scaleB + 1.07163 * scaleCDEF;
    else return 0.82839 * scaleB + 1.08415 * scaleCDEF; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.21713 * scaleB + 1.01997 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.17750 * scaleB + 1.01249 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97647 * scaleB + 1.04264 * scaleCDEF;
    else return 0.90637 * scaleB + 1.06095 * scaleCDEF; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.22371 * scaleB + 1.01803 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.15302 * scaleB + 1.01639 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97647 * scaleB + 1.02749 * scaleCDEF;
    else return 0.91517 * scaleB + 1.03794 * scaleCDEF; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.20704 * scaleB + 1.01061 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.14614 * scaleB + 1.00398 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.88450 * scaleB + 1.00616 * scaleCDEF;
    else return 0.83138 * scaleB + 1.03170 * scaleCDEF; }
  else {
    if ( fabs(eta) < 0.8000 ) return 1.18790 * scaleB + 1.00237 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.10756 * scaleB + 0.99051 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.77335 * scaleB + 0.98468 * scaleCDEF;
    else return 0.62373 * scaleB + 1.00085 * scaleCDEF; }
}

double HardcodedConditions::GetElectronTriggerXSF2016(double pt, double eta){
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.14782;
    else if ( fabs(eta) < 1.4442 ) return 1.18631;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.29749;
    else return 1.24157; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.08915;
    else if ( fabs(eta) < 1.4442 ) return 1.11135;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.19278;
    else return 1.16119; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.06652;
    else if ( fabs(eta) < 1.4442 ) return 1.08731;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.13757;
    else return 1.09036; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.05907;
    else if ( fabs(eta) < 1.4442 ) return 1.07224;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.11212;
    else return 1.10263; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.04784;
    else if ( fabs(eta) < 1.4442 ) return 1.05666;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.09641;
    else return 1.08932; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.03015;
    else if ( fabs(eta) < 1.4442 ) return 1.04212;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.05615;
    else return 1.06802; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01940;
    else if ( fabs(eta) < 1.4442 ) return 1.01754;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.99054;
    else return 0.99812; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01138;
    else if ( fabs(eta) < 1.4442 ) return 1.00831;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97730;
    else return 0.97372; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00496;
    else if ( fabs(eta) < 1.4442 ) return 0.99992;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.95467;
    else return 0.95763; }
  else {
    if ( fabs(eta) < 0.8000 ) return 0.98566;
    else if ( fabs(eta) < 1.4442 ) return 0.96761;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.81423;
    else return 0.81549; }
}

double HardcodedConditions::GetElectronTriggerXSF2017(double pt, double eta){
  double scaleCDEF = 38.783 / 43.841; 
  double scaleB    = ( 1. - scaleCDEF );
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.16567 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.22845 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.22274 * scaleCDEF;
    else return 1.38466 * scaleCDEF; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.17378 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.24713 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.23559 * scaleCDEF;
    else return 1.35677 * scaleCDEF; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.86609 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.94091 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.01112 * scaleCDEF;
    else return 1.09098 * scaleCDEF; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.97331 * scaleB + 0.98156 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.91262 * scaleB + 0.96138 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.84344 * scaleB + 0.99636 * scaleCDEF;
    else return 0.86060 * scaleB + 0.99253 * scaleCDEF; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.03441 * scaleB + 1.03829 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.01675 * scaleB + 1.04613 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.96547 * scaleB + 1.03379 * scaleCDEF;
    else return 0.99179 * scaleB + 1.06212 * scaleCDEF; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.04018 * scaleB + 1.03700 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.03637 * scaleB + 1.04998 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97562 * scaleB + 1.04128 * scaleCDEF;
    else return 1.02387 * scaleB + 1.06770 * scaleCDEF; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.03011 * scaleB + 1.02506 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.01276 * scaleB + 1.02256 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.94152 * scaleB + 1.00691 * scaleCDEF;
    else return 0.95796 * scaleB + 1.01928 * scaleCDEF; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01493 * scaleB + 1.01657 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.00979 * scaleB + 1.01724 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.91698 * scaleB + 0.98737 * scaleCDEF;
    else return 0.93451 * scaleB + 0.99985 * scaleCDEF; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01208 * scaleB + 1.01529 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.98313 * scaleB + 1.00834 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.88371 * scaleB + 0.97977 * scaleCDEF;
    else return 0.90585 * scaleB + 0.99339 * scaleCDEF; }
  else {
    if ( fabs(eta) < 0.8000 ) return 0.98542 * scaleB + 1.00935 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.92460 * scaleB + 0.99460 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.72931 * scaleB + 0.89882 * scaleCDEF;
    else return 0.69179 * scaleB + 0.88161 * scaleCDEF; }
}

double HardcodedConditions::GetElectronTriggerXSF2018(double pt, double eta){
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.11580;
    else if ( fabs(eta) < 1.4442 ) return 1.16769;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.20519;
    else return 1.33363; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.07938;
    else if ( fabs(eta) < 1.4442 ) return 1.11691;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.11615;
    else return 1.25092; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.95119;
    else if ( fabs(eta) < 1.4442 ) return 0.97900;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.98137;
    else return 1.09154; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01169;
    else if ( fabs(eta) < 1.4442 ) return 1.01965;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.10725;
    else return 1.14393; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.02757;
    else if ( fabs(eta) < 1.4442 ) return 1.03462;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.04519;
    else return 1.07198; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.02310;
    else if ( fabs(eta) < 1.4442 ) return 1.03258;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 1.03339;
    else return 1.04745; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00964;
    else if ( fabs(eta) < 1.4442 ) return 1.01093;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.98731;
    else return 0.99402; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00401;
    else if ( fabs(eta) < 1.4442 ) return 1.00521;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.97122;
    else return 0.97675; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00350;
    else if ( fabs(eta) < 1.4442 ) return 0.99915;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.96440;
    else return 0.95686; }
  else {
    if ( fabs(eta) < 0.8000 ) return 0.99735;
    else if ( fabs(eta) < 1.4442 ) return 0.98921;
    else if ( fabs(eta) < 1.5660 ) return 1.00000;
    else if ( fabs(eta) < 2.0000 ) return 0.88982;
    else return 0.87290; }
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

double HardcodedConditions::GetMuonIdSF(double pt, double eta, std::string year){
  if      (year=="2016APV") return GetMuonIdSF2016APV(pt, eta);
  else if (year=="2016") return GetMuonIdSF2017(pt, eta);
  else if (year=="2017") return GetMuonIdSF2017(pt, eta);
  else if (year=="2018") return GetMuonIdSF2018(pt, eta);
  else return 0.;
}

double HardcodedConditions::GetMuonIdSF2016APV(double pt, double eta){
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

double HardcodedConditions::GetMuonIdSF2016( double pt, double eta ){
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

double HardcodedConditions::GetMuonIdSF2017(double pt, double eta){
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

double HardcodedConditions::GetMuonIdSF2018(double pt, double eta){
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

// using EOY 2016
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

double HardcodedConditions::GetMuonTriggerXSF(double pt, double eta, std::string year){
  if      (year=="2016APV") return GetMuonTriggerXSF2016APV(pt, eta);
  else if (year=="2016") return GetMuonTriggerXSF2016(pt, eta);
  else if (year=="2017") return GetMuonTriggerXSF2017(pt, eta);
  else if (year=="2018") return GetMuonTriggerXSF2018(pt, eta);
  else return 0. ;
}

double HardcodedConditions::GetMuonTriggerXSF2016APV(double pt, double eta){
  double scaleCDEF = 17.516 / 20.442;
  double scaleB    = ( 1. - scaleCDEF );
  if ( pt < 24.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.94637 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.95790 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.96069 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.94582 * scaleCDEF;
    else return 0.96144 * scaleCDEF; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.90268 * scaleB + 0.98041 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.85771 * scaleB + 0.97109 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.84791 * scaleB + 0.96496 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.79518 * scaleB + 0.97183 * scaleCDEF;
    else return 0.76612 * scaleB + 0.95758 * scaleCDEF; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.93709 * scaleB +  0.99020 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.91127 * scaleB +  0.98104 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.94939 * scaleB + 0.97632 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.81169 * scaleB + 0.97472 * scaleCDEF;
    else return 0.84489 * scaleB + 0.96909 * scaleCDEF; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.96469 * scaleB +  0.99018 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.94609 * scaleB + 0.98580 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.92322 * scaleB + 0.97837 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.90132 * scaleB + 0.98298 * scaleCDEF;
    else return 0.84854 * scaleB + 0.97462 * scaleCDEF; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.97705 * scaleB +  0.98983 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.95378 * scaleB + 0.98734 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.99804 * scaleB + 0.98989 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.89635 * scaleB + 0.97871 * scaleCDEF;
    else return 0.88036 * scaleB + 0.97240 * scaleCDEF; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.97953 * scaleB + 0.99292 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.96676 * scaleB + 0.99010 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.99105 * scaleB + 0.97212 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.92806 * scaleB + 0.98668 * scaleCDEF;
    else return 0.90748 * scaleB + 0.97892 * scaleCDEF; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98185 * scaleB + 1.00465 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.95578 * scaleB + 0.99896 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.04354 * scaleB + 1.00392 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.90934 * scaleB + 1.00204 * scaleCDEF;
    else return 0.90253 * scaleB + 0.99439 * scaleCDEF; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98316 * scaleB + 1.00496 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.94568 * scaleB + 0.99818 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.96182 * scaleB + 0.99807 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.89956 * scaleB + 0.99386 * scaleCDEF;
    else return 0.88652 * scaleB + 0.99079 * scaleCDEF; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.97398 * scaleB + 1.00483 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.93595 * scaleB + 0.99915 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.97581 * scaleB + 0.99748 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.90511 * scaleB + 1.00200 * scaleCDEF;
    else return 0.88652 * scaleB + 0.99931 * scaleCDEF; }
  else {
    if ( fabs(eta) < 0.8000 ) return 0.97179 * scaleB + 1.00386 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.93244 * scaleB + 0.99792 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.98308 * scaleB + 0.98862 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.91301 * scaleB + 0.99701 * scaleCDEF;
    else return 0.92678 * scaleB + 0.99505 * scaleCDEF; }
}

double HardcodedConditions::GetMuonTriggerXSF2016(double pt, double eta){
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.09582;
    else if ( fabs(eta) < 1.4442 ) return 1.10100;
    else if ( fabs(eta) < 1.5660 ) return 1.09695;
    else if ( fabs(eta) < 2.0000 ) return 1.10252;
    else return 1.09121; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.01244;
    else if ( fabs(eta) < 1.4442 ) return 1.01534;
    else if ( fabs(eta) < 1.5660 ) return 1.01917;
    else if ( fabs(eta) < 2.0000 ) return 1.02772;
    else return 1.03346; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00962;
    else if ( fabs(eta) < 1.4442 ) return 1.01127;
    else if ( fabs(eta) < 1.5660 ) return 1.01008;
    else if ( fabs(eta) < 2.0000 ) return 1.02566;
    else return 1.02116; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00799;
    else if ( fabs(eta) < 1.4442 ) return 1.00832;
    else if ( fabs(eta) < 1.5660 ) return 1.00635;
    else if ( fabs(eta) < 2.0000 ) return 1.02640;
    else return 1.02238; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00799;
    else if ( fabs(eta) < 1.4442 ) return 1.01116;
    else if ( fabs(eta) < 1.5660 ) return 1.01524;
    else if ( fabs(eta) < 2.0000 ) return 1.02745;
    else return 1.01212; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00754;
    else if ( fabs(eta) < 1.4442 ) return 1.00776;
    else if ( fabs(eta) < 1.5660 ) return 1.01083;
    else if ( fabs(eta) < 2.0000 ) return 1.01895;
    else return 1.01396; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00701;
    else if ( fabs(eta) < 1.4442 ) return 1.00747;
    else if ( fabs(eta) < 1.5660 ) return 1.00836;
    else if ( fabs(eta) < 2.0000 ) return 1.01638;
    else return 1.01108; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00685;
    else if ( fabs(eta) < 1.4442 ) return 1.00631;
    else if ( fabs(eta) < 1.5660 ) return 1.01235;
    else if ( fabs(eta) < 2.0000 ) return 1.01837;
    else return 1.01113; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00707;
    else if ( fabs(eta) < 1.4442 ) return 1.00776;
    else if ( fabs(eta) < 1.5660 ) return 1.01112;
    else if ( fabs(eta) < 2.0000 ) return 1.01595;
    else return 1.01239; }
  else {
    if ( fabs(eta) < 0.8000 ) return 1.00912;
    else if ( fabs(eta) < 1.4442 ) return 1.00764;
    else if ( fabs(eta) < 1.5660 ) return 1.01059;
    else if ( fabs(eta) < 2.0000 ) return 1.02018;
    else return 1.01372; }
}
  
double HardcodedConditions::GetMuonTriggerXSF2017(double pt, double eta){
  double scaleCDEF = 38.783 / 43.841;
  double scaleB    = ( 1. - scaleCDEF );
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.03321 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 1.03894 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.05886 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 1.06851 * scaleCDEF;
    else return 1.09718 * scaleCDEF; }
  else if ( pt < 27.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.97808 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.98727 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.99883 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 1.02340 * scaleCDEF;
    else return 1.04081 * scaleCDEF; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00614 * scaleB + 0.97808 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.99220 * scaleB + 0.98727 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 1.02431 * scaleB + 0.99883 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.94157 * scaleB + 1.02340 * scaleCDEF;
    else return 0.79174 * scaleB + 1.04081 * scaleCDEF; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.96589 * scaleB + 1.00953 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.95695 * scaleB + 1.01569 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.98071 * scaleB + 1.01861 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.92698 * scaleB + 1.02066 * scaleCDEF;
    else return 0.81962 * scaleB + 1.02439 * scaleCDEF; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.97470 * scaleB + 1.00934 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.97421 * scaleB + 1.01427 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.97671 * scaleB + 1.01968 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.95320 * scaleB + 1.02299 * scaleCDEF;
    else return 0.85204 * scaleB + 1.02752 * scaleCDEF; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98322 * scaleB + 1.00737 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.98081 * scaleB + 1.01182 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.99663 * scaleB + 1.01145 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.96032 * scaleB + 1.02288 * scaleCDEF;
    else return 0.89159 * scaleB + 1.02464 * scaleCDEF; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.98573 * scaleB + 1.00790 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.98518 * scaleB + 1.01210 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.99890 * scaleB + 1.01381 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.96175 * scaleB + 1.01752 * scaleCDEF;
    else return 0.88843 * scaleB + 1.02897 * scaleCDEF; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.95504 * scaleB + 1.00585 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.95457 * scaleB + 1.00946 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.96895 * scaleB + 1.01071 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.93656 * scaleB + 1.01630 * scaleCDEF;
    else return 0.86194 * scaleB + 1.02220 * scaleCDEF; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.95600 * scaleB + 1.00616 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.94888 * scaleB + 1.00939 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.96200 * scaleB + 1.00748 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.94298 * scaleB + 1.01774 * scaleCDEF;
    else return 0.87871 * scaleB + 1.02065 * scaleCDEF; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 0.94823 * scaleB + 1.00582 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.94415 * scaleB + 1.00836 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.95820 * scaleB + 1.00630 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.92295 * scaleB + 1.01483 * scaleCDEF;
    else return 0.88170 * scaleB + 1.01900 * scaleCDEF; }
  else {
    if ( fabs(eta) < 0.8000 ) return 0.95060 * scaleB + 1.00568 * scaleCDEF;
    else if ( fabs(eta) < 1.4442 ) return 0.93062 * scaleB + 1.00501 * scaleCDEF;
    else if ( fabs(eta) < 1.5660 ) return 0.94993 * scaleB + 1.00438 * scaleCDEF;
    else if ( fabs(eta) < 2.0000 ) return 0.94105 * scaleB + 1.01201 * scaleCDEF;
    else return 0.91977 * scaleB + 1.01463 * scaleCDEF; }
}

double HardcodedConditions::GetMuonTriggerXSF2018(double pt, double eta){
  if ( pt < 25.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.02489;
    else if ( fabs(eta) < 1.4442 ) return 1.02709;
    else if ( fabs(eta) < 1.5660 ) return 1.03265;
    else if ( fabs(eta) < 2.0000 ) return 1.03443;
    else return 1.04119; }
  else if ( pt < 30.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00544;
    else if ( fabs(eta) < 1.4442 ) return 1.00717;
    else if ( fabs(eta) < 1.5660 ) return 1.00706;
    else if ( fabs(eta) < 2.0000 ) return 1.01314;
    else return 1.01741; }
  else if ( pt < 35.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00656;
    else if ( fabs(eta) < 1.4442 ) return 1.00657;
    else if ( fabs(eta) < 1.5660 ) return 1.00586;
    else if ( fabs(eta) < 2.0000 ) return 1.01576;
    else return 1.01581; }
  else if ( pt < 40.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00591;
    else if ( fabs(eta) < 1.4442 ) return 1.00609;
    else if ( fabs(eta) < 1.5660 ) return 1.00586;
    else if ( fabs(eta) < 2.0000 ) return 1.01260;
    else return 1.01824; }
  else if ( pt < 45.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00523;
    else if ( fabs(eta) < 1.4442 ) return 1.00514;
    else if ( fabs(eta) < 1.5660 ) return 1.00521;
    else if ( fabs(eta) < 2.0000 ) return 1.01283;
    else return 1.01783; }
  else if ( pt < 50.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00443;
    else if ( fabs(eta) < 1.4442 ) return 1.00446;
    else if ( fabs(eta) < 1.5660 ) return 1.00553;
    else if ( fabs(eta) < 2.0000 ) return 1.01023;
    else return 1.01518; }
  else if ( pt < 60.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00409;
    else if ( fabs(eta) < 1.4442 ) return 1.00417;
    else if ( fabs(eta) < 1.5660 ) return 1.00183;
    else if ( fabs(eta) < 2.0000 ) return 1.01035;
    else return 1.01210; }
  else if ( pt < 70.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00404;
    else if ( fabs(eta) < 1.4442 ) return 1.00411;
    else if ( fabs(eta) < 1.5660 ) return 1.00287;
    else if ( fabs(eta) < 2.0000 ) return 1.01023;
    else return 1.01158; }
  else if ( pt < 100.0 ) {
    if ( fabs(eta) < 0.8000 ) return 1.00429;
    else if ( fabs(eta) < 1.4442 ) return 1.00362;
    else if ( fabs(eta) < 1.5660 ) return 1.00169;
    else if ( fabs(eta) < 2.0000 ) return 1.00911;
    else return 1.01205; }
  else {
    if ( fabs(eta) < 0.8000 ) return 1.00346;
    else if ( fabs(eta) < 1.4442 ) return 1.00283;
    else if ( fabs(eta) < 1.5660 ) return 1.00078;
    else if ( fabs(eta) < 2.0000 ) return 1.00830;
    else return 1.00893; }
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
 |\|  | /|           btag CSV re-normalization                 |\  | |/|
 | `---' |                                                     | `---' |
 |       |                                                     |       | 
 |       |-----------------------------------------------------|       |
 \       |                                                     |       /
  \     /                                                       \     /
   `---'                                                         `---'*/

// need to be updated for UL
float HardcodedConditions::GetCSVRenormSF(std::string year, int isE, int njet, std::string sampleType) {
    return 1.0;
}
