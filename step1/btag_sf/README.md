# UL b-tagging Scale Factor Files
b-tagging SF using deepCSV and DeepJet are stored here. There are two methods for implementing the scale factors. Starting in November 2021, the parameters of the scale factors were adjusted from using the notation of:
* `operatingPoint` = 0, 1, 2, 3 for Loose, Medium, Tight and Reshaping to `operatingPoint` = L, M, T and having a separate reshaping file
* `jetFlavor` = 0, 1, 2 for b-, c- and light jets to `jetFlavor` = 5, 4, 0 (to match the pdgID convention)  

Furthermore, following the new convention for the scale factor labels was the introduction of using `.json` files in addition to the previously used `.csv` files. The [b-tag calibration](https://twiki.cern.ch/twiki/bin/view/CMS/BTagCalibration) provides more details on the switch as well as the [jsonPOG-integration gitlab](https://gitlab.cern.ch/cms-nanoAOD/jsonpog-integration/-/tree/master/) containing all of the `.json` files for the various POGs and examples on how to load them into an analysis.

Our current implementation is to stick with using `.csv` format and adjust the `BTagCalibForLJMet.cpp` tool that parses the file to account for the new naming convention.
