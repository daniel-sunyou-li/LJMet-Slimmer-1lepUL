# LJMet-Slimmer-1lepUL -- `step1` 
### Updates:
* Switched `Year` argument from `int` to `std::string` to accomodate `2016APV` as an argument
* Defaulted scale factors that haven't had an UL update to `1.0` (and their uncertainties to `0.0`) 
* Defaulted efficiencies that haven't had an UL update to `1.0`
* Updated the b-tagging working points and changed file versions in `step1.cc` to just "reshaping"
* Updated the pileup reweighting scheme so that all eras have `0` to `99` true interaction entries  


#### __Notes:__
* Kept the HOT-tagging UL SF, mistag and efficiencies the same as for Legacy SF and duplicated the `2016` values over to `2016APV`
* UL Top tagging was calculated for only 2017 and 2018 for the `RunIISummer19` production, and each era will be added with the switch to the `RunIISummer20` production
* Temporarily removed the VLQ trigger SF

#### __Scale factors updated to UL:__
* EGamma Gsf: using the JSON POG EGamma `.json` scale factors with the working point `RecoAbove20`
* Electron ID: using the JSON POG EGamma `.json` scale factors with the working point `ID`
* Muon ID: using the JSON POG Muon `.json` scale factors with the working point 
* Muon Trigger: using the JSON POG Muon `.json` scale factors with the working point `NUM_IsoMu24_or_IsoTkMu24_DEN_CutBasedIdTight_and_PFIsoTight`
* Pileup Weight: using the JSON POG Lum `.json` scale factors 
* Pileup Jet ID Weights: using the JSON POG JMAR `.json` scale factors and efficiencies
* TriggerX: calculated using cut-and-count in [triggerX folder](https://github.com/daniel-sunyou-li/LJMet-Slimmer-1lepUL/tree/main/step1/triggerX)
* Electron miniIso: calculated using EGamma POG tag and probe tool
* Muon miniIso: calculated using Muon POG spark tag and probe tool

#### _Scale factors needing UL update_:
* Top-tagging scale factors and efficiencies
* W-tagging scale factors and efficiencies
