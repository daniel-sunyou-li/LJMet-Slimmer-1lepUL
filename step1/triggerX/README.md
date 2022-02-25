# Calculating `triggerX` Scale Factors
`triggerX` refers to the X-strategy introduced in AN-2019-091: "New High-Level-Trigger off-line combinations for a 2017-18 four-top analysis" where two single object HLT are combined with `or` logic to pass events. The use of `triggerX` over single-object and cross triggers allows for a lower lepton momentum cut (i.e. 35 GeV to 20 GeV) by applying constrains on other parameters, such as the scalar sum of the jet transverse momentum or the missing transverse momentum. 

The scale factors for `triggerX` are defined as the ratio of the data efficiency to MC efficiency, where the efficiency is defined as the ratio between events passing pre-selection plus `triggerX` to events only passing the pre-selection. The scale factors are calculated in bins of the lepton transverse momentum and pseudorapidity. For the MC samples, only the ttbar background is used as it constitutes over 90% of the background. 

The inputs to the `triggerXSF` calculation are step1 files, since that's where `triggerX` is calculated and added to the ntuples. Thus, the order of running these scripts are:
  1. Run step1 on data and ttbar MC using old `triggerXSF`
  2. Run `triggerX` scale factor calculation
  3. Update the scale factors in HardcodedConditions.cc
  4. Re-run step1 to add the new `triggerXSF` to the ntuples

## Quick-start instructions
To run the `triggerX` SF calculation:

    source /cvmfs/cms.cern.ch/cmsset_default.csh
    cmsenv
    source /cvmfs/sft.cern.ch/lcg/views/LCG_98/x86_64-centos7-gcc8-opt/setup.csh

    python triggerX_efficiency.py -y <16APV,16,17,18> -g <TTBAR,DATA> -l <e,m>
    python triggerX_SF.py -m efficiency_TTBAR_<e,m>_UL<16APV,16,17,18>.pkl -d efficiency_DATA_<e,m>_UL<16APV,16,17,18>.pkl
  
The `triggerX_SF.py` will automatically print out a block of `c++` code that you can directly paste into `HardcodedConditions.cc`.
