eosUserName = "dali" # EDIT ME
postfix = "3t" # EDIT ME
years = [ "16APV", "16", "17", "18" ]

ljmetDir = {
  year: {
    "LPC": "/eos/uscms/store/group/lpcljm/FWLJMET106XUL_singleLep20{}UL_RunIISummer20".format( year ),
    "BRUX": "/isilon/hadoop/store/group/bruxljm/FWLJMET106XUL_singleLep20{}UL_RunIISummer20".format( year )
  } for year in years
}

# can temporarily store step1 on lpcljm or bruxljm, but delete after hadd'ing
step1Dir = {
  year: {
    "LPC": "/eos/uscms/store/group/lpcljm/FWLJMET106XUL_singleLep20{}UL_RunIISummer20_{}_step1".format( year, postfix ), 
    "BRUX": "/isilon/hadoop/store/group/bruxljm/FWLJMET106XUL_singleLep20{}UL_RunIISummer20_{}_step1".format( year, postfix ) 
  } for year in years
}

# store step1's on your personal space on an analysis basis
haddDir = {
  year: {
    "LPC": "/eos/uscms/store/user/{}/FWLJMET106XUL_singleLep20{}UL_RunIISummer20_{}_step1hadds".format( eosUserName, year, postfix ),
    "BRUX": "/isilon/hadoop/store/user/{}/FWLJMET106XUL_singleLep20{}UL_RunIISummer20_{}_step1hadds".format( eosUserName, year, postfix ) 
  } for year in years
}

# make sure this matches with the names in step1.cc
deepCSV_SF = {
  "16APV": "btag_sf/reshaping_deepCSV_106XUL16preVFP_v2.csv",
  "16":    "btag_sf/reshaping_deepCSV_106XUL16postVFP_v3.csv",
  "17":    "btag_sf/reshaping_deepCSV_106XUL17_v3.csv",
  "18":    "btag_sf/reshaping_deepCSV_106XUL18_v2.csv"
}

deepJet_SF = {
  "16APV": "btag_sf/reshaping_deepJet_106XUL16preVFP_v2.csv",
  "16":    "btag_sf/reshaping_deepJet_106XULpostVFP_v3.csv",
  "17":    "btag_sf/reshaping_deepJet_106XUL17_v3.csv",
  "18":    "btag_sf/reshaping_deepJet_106XUL18_v2.csv"
}

outputPath = "/store/user/{}/".format( eosUserName ),

# LJMET samples should be by default stored on BRUX, LPC only for personal-use case
samples = {
  "16APV": {
  "TEST": {
    "TTTJ": "/TTTJ_TuneCP5_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    #"SingleElectronRun2016B": "/SingleElectron/Run2016B-ver2_HIPM_UL2016_MiniAODv2-v2/MINIAOD",
  },
  "DATAE": {
    "SingleElectronRun2016APVB": "/SingleElectron/Run2016B-ver2_HIPM_UL2016_MiniAODv2-v2/MINIAOD",
    "SingleElectronRun2016APVC": "/SingleElectron/Run2016C-HIPM_UL2016_MiniAODv2-v2/MINIAOD",
    "SingleElectronRun2016APVD": "/SingleElectron/Run2016D-HIPM_UL2016_MiniAODv2-v2/MINIAOD",
    "SingleElectronRun2016APVE": "/SingleElectron/Run2016E-HIPM_UL2016_MiniAODv2-v5/MINIAOD",
    "SingleElectronRun2016APVF": "/SingleElectron/Run2016F-HIPM_UL2016_MiniAODv2-v2/MINIAOD",
  },
  "DATAM": {
    "SingleMuonRun2016APVB": "/SingleMuon/Run2016B-ver2_HIPM_UL2016_MiniAODv2-v2/MINIAOD",
    "SingleMuonRun2016APVC": "/SingleMuon/Run2016C-HIPM_UL2016_MiniAODv2-v2/MINIAOD",
    "SingleMuonRun2016APVD": "/SingleMuon/Run2016D-HIPM_UL2016_MiniAODv2-v2/MINIAOD",
    "SingleMuonRun2016APVE": "/SingleMuon/Run2016E-HIPM_UL2016_MiniAODv2-v2/MINIAOD",
    "SingleMuonRun2016APVF": "/SingleMuon/Run2016F-HIPM_UL2016_MiniAODv2-v2/MINIAOD",
  },
  "DATAJ": { # not a priority for now
    "JetHTRun2016APVB": "/JetHT/Run2016B-ver2_HIPM_UL2016_MiniAODv2-v2/MINIAOD", 
    "JetHTRun2016APVC": "/JetHT/Run2016C-HIPM_UL2016_MiniAODv2-v2/MINIAOD",
    "JetHTRun2016APVD": "/JetHT/Run2016D-HIPM_UL2016_MiniAODv2-v2/MINIAOD",
    "JetHTRun2016APVE": "/JetHT/Run2016E-HIPM_UL2016_MiniAODv2-v2/MINIAOD",
    "JetHTRun2016APVF": "/JetHT/Run2016F-HIPM_UL2016_MiniAODv2-v2/MINIAOD",
  },
  "CHARGEDHIGGS": {
    "HPTB200": "/ChargedHiggs_HplusTB_HplusToTB_M-200_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB220": "/ChargedHiggs_HplusTB_HplusToTB_M-220_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB250": "/ChargedHiggs_HplusTB_HplusToTB_M-250_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB300": "/ChargedHiggs_HplusTB_HplusToTB_M-300_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB350": "/ChargedHiggs_HplusTB_HplusToTB_M-350_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB400": "/ChargedHiggs_HplusTB_HplusToTB_M-400_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB500": "/ChargedHiggs_HplusTB_HplusToTB_M-500_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB600": "/ChargedHiggs_HplusTB_HplusToTB_M-600_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB700": "/ChargedHiggs_HplusTB_HplusToTB_M-700_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB800": "/ChargedHiggs_HplusTB_HplusToTB_M-800_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB1000": "/ChargedHiggs_HplusTB_HplusToTB_M-1000_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB1250": "/ChargedHiggs_HplusTB_HplusToTB_M-1250_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB1500": "/ChargedHiggs_HplusTB_HplusToTB_M-1500_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB1750": "/ChargedHiggs_HplusTB_HplusToTB_M-1750_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB2000": "/ChargedHiggs_HplusTB_HplusToTB_M-2000_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB2500": "/ChargedHiggs_HplusTB_HplusToTB_M-2500_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "HPTB3000": "/ChargedHiggs_HplusTB_HplusToTB_M-3000_TuneCP5_13TeV_amcatnlo_pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM"
  },
  "TTTX": {
    "TTTT": "/TTTT_TuneCP5_13TeV-amcatnlo-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "TTTJ": "/TTTJ_TuneCP5_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "TTTW": "/TTTW_TuneCP5_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM"
  },
  "VLQ": {
  # Not submitted
  },
  "TPRIMEBPRIME": {
  # Not submitted
  },
  "TTBAR": {
    "TTToSemiLeptonic": "/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTToHadronic": "/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTTo2L2Nu": "/TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTToSemiLeptonHT500Njet9": "/TTToSemiLepton_HT500Njet9_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM"
  },
  "TTMT": {
    "TTMT700": "/TT_Mtt-700to1000_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTMT1000": "/TT_Mtt-700to1000_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM"
  },
  "TTBAR_SHIFTS": {
    "TTToSemiLeptonicHDUP": "/TTToSemiLeptonic_hdampUP_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTToSemiLeptonicHDDN": "/TTToSemiLeptonic_hdampDOWN_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTToSemiLeptonicUEUP": "/TTToSemiLeptonic_TuneCP5up_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTToSemiLeptonicUEDN": "/TTToSemiLeptonic_TuneCP5down_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTToHadronicHDUP": "/TTToHadronic_hdampUP_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTToHadronicHDDN": "/TTToHadronic_hdampDOWN_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTToHadronicUEUP": "/TTToHadronic_TuneCP5up_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTToHadronicUEDN": "/TTToHadronic_TuneCP5down_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTTo2L2NuHDUP": "/TTTo2L2Nu_hdampUP_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTTo2L2NuHDDN": "/TTTo2L2Nu_hdampDOWN_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTTo2L2NuUEUP": "/TTTo2L2Nu_TuneCP5up_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTTo2L2NuUEDN": "/TTTo2L2Nu_TuneCP5down_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM"
  },
  "DYM": {
    "DYM": "/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM"
  },
  "DYMHT": {
    "DYMHT200": "/DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "DYMHT400": "/DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "DYMHT600": "/DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "DYMHT800": "/DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "DYMHT1200": "/DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "DYMHT2500": "/DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM"
  },
  "QCDHT": {
    "QCDHT200": "/QCD_HT200to300_TuneCP5_PSWeights_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "QCDHT300": "/QCD_HT300to500_TuneCP5_PSWeights_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "QCDHT500": "/QCD_HT500to700_TuneCP5_PSWeights_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "QCDHT700": "/QCD_HT700to1000_TuneCP5_PSWeights_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "QCDHT1000": "/QCD_HT1000to1500_TuneCP5_PSWeights_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "QCDHT1500": "/QCD_HT1500to2000_TuneCP5_PSWeights_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "QCDHT2000": "/QCD_HT2000toInf_TuneCP5_PSWeights_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
  },
  "WJETS": {
    "WJets": "WJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM"
  },
  "WJETSHT": {
    "WJetsHT200": "/WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "WJetsHT400": "/WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "WJetsHT600": "/WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "WJetsHT800": "/WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "WJetsHT1200": "/WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "WJetsHT2500": "/WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
  },
  "TTXY": {
    "TTWl": "/TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "TTWq": "/TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "TTZM1to10": "/TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8/RunIISummer20UL16MiniAODv2-106X_mcRun2_asymptotic_v17-v2/MINIAODSIM",
    "TTZM10": "/TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTHH": "/TTHH_TuneCP5_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "TTZZ": "/TTZZ_TuneCP5_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTWW": "/TTWW_TuneCP5_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTWH": "/TTWH_TuneCP5_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "TTZH": "/TTZH_TuneCP5_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "TTWZ": "/TTWZ_TuneCP5_13TeV-madgraph-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "TTHB": "/ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
    "TTHnonB": "/ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v2/MINIAODSIM",
  },
  "TOP": {
    "STtWb": "/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "STtW": "/ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "STtb": "/ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v3/MINIAODSIM",
    "STt": "/ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v3/MINIAODSIM",
    "STs": "/ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM"
  },
  "EWK": {
    "WW": "/WW_TuneCP5_13TeV-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "WZ": "/WZ_TuneCP5_13TeV-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM",
    "ZZ": "/ZZ_TuneCP5_13TeV-pythia8/RunIISummer20UL16MiniAODAPVv2-106X_mcRun2_asymptotic_preVFP_v11-v1/MINIAODSIM"
  }
}

  },
  "16": {
    "TEST": [ "TTTW_TuneCP5_13TeV-madgraph-pythia8" ],
    "LPC": [],
    "BRUX": [
      
    ]
  },
  "17": {
    "TEST": [ "" ],
    "LPC": [],
    "BRUX": [
      
    ]
  },
  "18": {
    "TEST": [ "TTTW_TuneCP5_13TeV-madgraph-pythia8" ],
    "LPC": [],
    "BRUX": [
      
    ]
  }
}
