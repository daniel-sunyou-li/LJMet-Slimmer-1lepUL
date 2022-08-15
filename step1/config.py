eosUserName = "dali" # EDIT ME
postfix = "3t" # EDIT ME
years = [ "16APV", "16", "17", "18" ]

sampleDir = {
  year: "FWLJMET106XUL_singleLep20{}UL_RunIISummer20".format( year ) for year in years
}

ljmetDir = {
  year: {
    "LPC": "/eos/uscms/store/group/lpcljm/{}".format( sampleDir[ year ] ),
    "BRUX": "/isilon/hadoop/store/group/bruxljm/{}".format( sampleDir[ year ] )
  } for year in years
}

# can temporarily store step1 on lpcljm or bruxljm, but delete after hadd'ing
step1Dir = {
  year: {
    "LPC": "/eos/uscms/store/group/lpcljm/{}_{}_step1".format( sampleDir[ year ], postfix ), 
    "BRUX": "/isilon/hadoop/store/group/bruxljm/{}_{}_step1".format( sampleDir[ year ], postfix ) 
  } for year in years
}

# store step1's on your personal space on an analysis basis
haddDir = {
  year: {
    "LPC": "/eos/uscms/store/user/{}/{}_{}_step1hadds".format( eosUserName, sampleDir[ year ], postfix ),
    "BRUX": "/isilon/hadoop/store/user/{}/{}_{}_step1hadds".format( eosUserName, sampleDir[ year ], postfix ) 
  } for year in years
}

# make sure this matches with the names in step1.cc and in make_step1.C
deepCSV_SF = {
  "16APV": "btag_sf/reshaping_deepCSV_106XUL16preVFP_v2.csv",
  "16":    "btag_sf/reshaping_deepCSV_106XUL16postVFP_v3.csv",
  "17":    "btag_sf/reshaping_deepCSV_106XUL17_v3.csv",
  "18":    "btag_sf/reshaping_deepCSV_106XUL18_v2.csv"
}

deepJet_SF = {
  "16APV": "btag_sf/reshaping_deepJet_106XUL16preVFP_v2.csv",
  "16":    "btag_sf/reshaping_deepJet_106XUL16postVFP_v3.csv",
  "17":    "btag_sf/reshaping_deepJet_106XUL17_v3.csv",
  "18":    "btag_sf/reshaping_deepJet_106XUL18_v2.csv"
}

JEC_files = {
  "16APV": "btag_sf/RegroupedV2_Summer19UL16APV_V7_MC_UncertaintySources_AK4PFchs.txt",
  "16": "btag_sf/RegroupedV2_Summer19UL16_V7_MC_UncertaintySources_AK4PFchs.txt",
  "17": "btag_sf/RegroupedV2_Summer19UL17_V5_MC_UncertaintySources_AK4PFchs.txt",
  "18": "btag_sf/RegroupedV2_Summer19UL18_V5_MC_UncertaintySources_AK4PFchs.txt"
}

JES_shifts = {
  "JER": False,
  "JEC": False, # fully de-correlated, corresponds to total JEC from LJMet
  "FlavorQCD": True,
  "RelativeBal": True,
  "RelativeSamples_Era": True,
  "HF": True,
  "HF_Era": True,
  "BBEC1": True,
  "BBEC1_Era": True,
  "EC2": True,
  "EC2_Era": True,
  "Absolute": True,
  "Absolute_Era": True
}

selection = {
  "leptonPt_MultiLepCalc": { "VALUE": [ 20 ], "CONDITION": [ ">" ] },
  "leptonEta_MultiLepCalc": { "VALUE": [ 2.5 ], "CONDITION": [ "<" ] },
  "AK4HT": { "VALUE": [ 350. ], "CONDITION": [ ">" ] },
  "NJets_JetSubCalc": { "VALUE": [ 4 ], "CONDITION": [ ">=" ] },
  "NJetsCSV_JetSubCalc": { "VALUE": [ 2 ], "CONDITION": [ ">=" ] },
  "corr_met_MultiLepCalc": { "VALUE": [ 20. ], "CONDITION": [ ">" ] },
}

triggerX_bins = {
  "PT": [ 25., 30., 35., 40., 45., 50., 60., 70., 100. ],
  "ETA": [ 0.8, 1.4442, 1.566, 2.0 ]
}

outputPath = "/store/user/{}/".format( eosUserName ),

# LJMET samples should be by default stored on BRUX, LPC only for personal-use case
samples = {
  "16APV": {
    "TEST": [
      "TTTW_TuneCP5_13TeV-madgraph-pythia8",
      "TTTJ_TuneCP5_13TeV-madgraph-pythia8"
    ],
    "DATAE": [
      "SingleElectron"
     ],
     "DATAM": [
      "SingleMuon"
    ],
    "CHARGEDHIGGS": [
      "ChargedHiggs_HplusTB_HplusToTB_M-200_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-220_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-250_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-300_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-350_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-400_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-500_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-600_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-700_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-800_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1000_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1250_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1500_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1750_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-2000_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-2500_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-3000_TuneCP5_13TeV_amcatnlo_pythia8"
    ],
    "TTTX": [
      "TTTT_TuneCP5_13TeV-amcatnlo-pythia8",
      "TTTJ_TuneCP5_13TeV-madgraph-pythia8",
      "TTTW_TuneCP5_13TeV-madgraph-pythia8"
    ],
    "TTBAR": [
      "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8",
      "TTToHadronic_TuneCP5_13TeV-powheg-pythia8",
      "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8",
      "TTToSemiLepton_HT500Njet9_TuneCP5_13TeV-powheg-pythia8"
    ],
    "TTBAR_SHIFTS": [
      "TTToSemiLeptonic_hdampUP_TuneCP5_13TeV-powheg-pythia8",
      "TTToSemiLeptonic_hdampDOWN_TuneCP5_13TeV-powheg-pythia8",
      "TTToSemiLeptonic_TuneCP5up_13TeV-powheg-pythia8",
      "TTToSemiLeptonic_TuneCP5down_13TeV-powheg-pythia8",
      "TTToHadronic_hdampUP_TuneCP5_13TeV-powheg-pythia8",
      "TTToHadronic_hdampDOWN_TuneCP5_13TeV-powheg-pythia8",
      "TTToHadronic_TuneCP5up_13TeV-powheg-pythia8",
      "TTToHadronic_TuneCP5down_13TeV-powheg-pythia8",
      "TTTo2L2Nu_hdampUP_TuneCP5_13TeV-powheg-pythia8",
      "TTTo2L2Nu_hdampDOWN_TuneCP5_13TeV-powheg-pythia8",
      "TTTo2L2Nu_TuneCP5up_13TeV-powheg-pythia8",
      "TTTo2L2Nu_TuneCP5down_13TeV-powheg-pythia8"
    ],
    "DYM": [
      "DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8"
    ],
    "DYMHT": [
      "DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8"
    ],
    "QCDHT": [
      "QCD_HT200to300_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT300to500_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT500to700_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT700to1000_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT1000to1500_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT1500to2000_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT2000toInf_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
    ],
    "WJETS": [
      "WJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-pythia8"
    ],
    "WJETSHT": [
      "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8",
    ],
    "TTXY": [
      "TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8",
      "TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8",
      "TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8",
      "TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8",
      "TTHH_TuneCP5_13TeV-madgraph-pythia8",
      "TTZZ_TuneCP5_13TeV-madgraph-pythia8",
      "TTWW_TuneCP5_13TeV-madgraph-pythia8",
      "TTWH_TuneCP5_13TeV-madgraph-pythia8",
      "TTZH_TuneCP5_13TeV-madgraph-pythia8",
      "TTWZ_TuneCP5_13TeV-madgraph-pythia8",
      "ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8",
      "ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8",
    ],
    "TOP": [
      "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",
      "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",
      "ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8",
      "ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8",
      "ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8"
    ],
    "EWK": [
      "WW_TuneCP5_13TeV-pythia8",
      "WZ_TuneCP5_13TeV-pythia8",
      "ZZ_TuneCP5_13TeV-pythia8"
    ]
  },
  "16": {
    "TEST": [
      "TTTW_TuneCP5_13TeV-madgraph-pythia8",
      "TTTJ_TuneCP5_13TeV-madgraph-pythia8"
    ],
    "DATAE": [
      "SingleElectron",
    ],
    "DATAM": [
      "SingleMuon"
    ],
    "CHARGEDHIGGS": [
      "ChargedHiggs_HplusTB_HplusToTB_M-200_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-220_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-250_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-300_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-350_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-400_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-500_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-600_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-700_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-800_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1000_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1250_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1500_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1750_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-2000_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-2500_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-3000_TuneCP5_13TeV_amcatnlo_pythia8"
    ],
    "TTTX": [
      "TTTT_TuneCP5_13TeV-amcatnlo-pythia8",
      "TTTJ_TuneCP5_13TeV-madgraph-pythia8",
      "TTTW_TuneCP5_13TeV-madgraph-pythia8"
    ],
    "TTBAR": [
      "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8",
      "TTToHadronic_TuneCP5_13TeV-powheg-pythia8",
      "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8",
      "TTToSemiLepton_HT500Njet9_TuneCP5_13TeV-powheg-pythia8"
    ],
    "TTBAR_SHIFTS": [
      "TTToSemiLeptonic_hdampUP_TuneCP5_13TeV-powheg-pythia8",
      "TTToSemiLeptonic_hdampDOWN_TuneCP5_13TeV-powheg-pythia8",
      "TTToSemiLeptonic_TuneCP5up_13TeV-powheg-pythia8",
      "TTToSemiLeptonic_TuneCP5down_13TeV-powheg-pythia8",
      "TTToHadronic_hdampUP_TuneCP5_13TeV-powheg-pythia8",
      "TTToHadronic_hdampDOWN_TuneCP5_13TeV-powheg-pythia8",
      "TTToHadronic_TuneCP5up_13TeV-powheg-pythia8",
      "TTToHadronic_TuneCP5down_13TeV-powheg-pythia8",
      "TTTo2L2Nu_hdampUP_TuneCP5_13TeV-powheg-pythia8",
      "TTTo2L2Nu_hdampDOWN_TuneCP5_13TeV-powheg-pythia8",
      "TTTo2L2Nu_TuneCP5up_13TeV-powheg-pythia8",
      "TTTo2L2Nu_TuneCP5down_13TeV-powheg-pythia8"
    ],
    "DYM": [
      "DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8"
    ],
    "DYMHT": [
      "DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8"
    ],
    "QCDHT": [
      "QCD_HT200to300_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT300to500_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT500to700_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT700to1000_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT1000to1500_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT1500to2000_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT2000toInf_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
    ],
    "WJETS": [
      "WJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-pythia8"
    ],
    "WJETSHT": [
      "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8",
    ],
    "TTXY": [
      "TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8",
      "TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8",
      "TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8",
      "TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8",
      "TTHH_TuneCP5_13TeV-madgraph-pythia8",
      "TTZZ_TuneCP5_13TeV-madgraph-pythia8",
      "TTWW_TuneCP5_13TeV-madgraph-pythia8",
      "TTWH_TuneCP5_13TeV-madgraph-pythia8",
      "TTZH_TuneCP5_13TeV-madgraph-pythia8",
      "TTWZ_TuneCP5_13TeV-madgraph-pythia8",
      "ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8",
      "ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8",
    ],
    "TOP": [
      "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",
      "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",
      "ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8",
      "ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8",
      "ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8"
    ],
    "EWK": [
      "WW_TuneCP5_13TeV-pythia8",
      "WZ_TuneCP5_13TeV-pythia8",
      "ZZ_TuneCP5_13TeV-pythia8"
    ]
  },
  "17": {
    "TEST": [
      "TTTJ_TuneCP5_13TeV-madgraph-pythia8",
      #"SingleMuon"
    ],
    "DATAE": [
      "SingleElectron"
    ],
    "DATAM": [
      "SingleMuon"
    ],
    "CHARGEDHIGGS": [
      "ChargedHiggs_HplusTB_HplusToTB_M-200_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-220_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-250_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-300_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-350_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-400_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-500_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-600_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-700_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-800_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1000_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1250_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1500_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1750_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-2000_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-2500_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-3000_TuneCP5_13TeV_amcatnlo_pythia8"
    ],
    "TTTX": [
      "TTTT_TuneCP5_13TeV-amcatnlo-pythia8",
      "TTTJ_TuneCP5_13TeV-madgraph-pythia8",
      "TTTW_TuneCP5_13TeV-madgraph-pythia8"
    ],
    "TTBAR": [
      #"TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8",
      "TTToHadronic_TuneCP5_13TeV-powheg-pythia8",
      "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8",
      "TTToSemiLepton_HT500Njet9_TuneCP5_13TeV-powheg-pythia8"
    ],
    "TTBAR_SHIFTS": [
      "TTToSemiLeptonic_hdampUP_TuneCP5_13TeV-powheg-pythia8",
      "TTToSemiLeptonic_hdampDOWN_TuneCP5_13TeV-powheg-pythia8",
      "TTToSemiLeptonic_TuneCP5up_13TeV-powheg-pythia8",
      "TTToSemiLeptonic_TuneCP5down_13TeV-powheg-pythia8",
      "TTToHadronic_hdampUP_TuneCP5_13TeV-powheg-pythia8",
      "TTToHadronic_hdampDOWN_TuneCP5_13TeV-powheg-pythia8",
      "TTToHadronic_TuneCP5up_13TeV-powheg-pythia8",
      "TTToHadronic_TuneCP5down_13TeV-powheg-pythia8",
      "TTTo2L2Nu_hdampUP_TuneCP5_13TeV-powheg-pythia8",
      "TTTo2L2Nu_hdampDOWN_TuneCP5_13TeV-powheg-pythia8",
      "TTTo2L2Nu_TuneCP5up_13TeV-powheg-pythia8",
      "TTTo2L2Nu_TuneCP5down_13TeV-powheg-pythia8"
    ],
    "DYM": [
      "DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8"
    ],
    "DYMHT": [
      "DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8"
    ],
    "QCDHT": [
      "QCD_HT200to300_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT300to500_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT500to700_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT700to1000_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT1000to1500_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT1500to2000_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT2000toInf_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
    ],
    "WJETS": [
      "WJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-pythia8"
    ],
    "WJETSHT": [
      "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8",
    ],
    "TTXY": [
      "TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8",
      "TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8",
      "TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8",
      "TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8",
      "TTHH_TuneCP5_13TeV-madgraph-pythia8",
      "TTZZ_TuneCP5_13TeV-madgraph-pythia8",
      "TTWW_TuneCP5_13TeV-madgraph-pythia8",
      "TTWH_TuneCP5_13TeV-madgraph-pythia8",
      "TTZH_TuneCP5_13TeV-madgraph-pythia8",
      "TTWZ_TuneCP5_13TeV-madgraph-pythia8",
      "ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8",
      "ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8",
    ],
    "TOP": [
      "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",
      "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",
      "ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8",
      "ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8",
      "ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8"
    ],
    "EWK": [
      "WW_TuneCP5_13TeV-pythia8",
      "WZ_TuneCP5_13TeV-pythia8",
      "ZZ_TuneCP5_13TeV-pythia8"
    ]
  },
  "18": {
    "TEST": [
      "TTTW_TuneCP5_13TeV-madgraph-pythia8",
      "SingleMuon"
    ],
    "DATAE": [
      "EGamma"
    ],
    "DATAM": [
      "SingleMuon"
    ],
    "CHARGEDHIGGS": [
      "ChargedHiggs_HplusTB_HplusToTB_M-200_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-220_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-250_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-300_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-350_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-400_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-500_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-600_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-700_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-800_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1000_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1250_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1500_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-1750_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-2000_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-2500_TuneCP5_13TeV_amcatnlo_pythia8",
      "ChargedHiggs_HplusTB_HplusToTB_M-3000_TuneCP5_13TeV_amcatnlo_pythia8"
    ],
    "TTTX": [
      "TTTT_TuneCP5_13TeV-amcatnlo-pythia8",
      #"TTTJ_TuneCP5_13TeV-madgraph-pythia8",
      #"TTTW_TuneCP5_13TeV-madgraph-pythia8"
    ],
    "TTBAR": [
      "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8",
      "TTToHadronic_TuneCP5_13TeV-powheg-pythia8",
      "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8",
      "TTToSemiLepton_HT500Njet9_TuneCP5_13TeV-powheg-pythia8"
    ],
    "TTBAR_SHIFTS": [
      "TTToSemiLeptonic_hdampUP_TuneCP5_13TeV-powheg-pythia8",
      "TTToSemiLeptonic_hdampDOWN_TuneCP5_13TeV-powheg-pythia8",
      "TTToSemiLeptonic_TuneCP5up_13TeV-powheg-pythia8",
      "TTToSemiLeptonic_TuneCP5down_13TeV-powheg-pythia8",
      "TTToHadronic_hdampUP_TuneCP5_13TeV-powheg-pythia8",
      "TTToHadronic_hdampDOWN_TuneCP5_13TeV-powheg-pythia8",
      "TTToHadronic_TuneCP5up_13TeV-powheg-pythia8",
      "TTToHadronic_TuneCP5down_13TeV-powheg-pythia8",
      "TTTo2L2Nu_hdampUP_TuneCP5_13TeV-powheg-pythia8",
      "TTTo2L2Nu_hdampDOWN_TuneCP5_13TeV-powheg-pythia8",
      "TTTo2L2Nu_TuneCP5up_13TeV-powheg-pythia8",
      "TTTo2L2Nu_TuneCP5down_13TeV-powheg-pythia8"
    ],
    "DYM": [
      "DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8"
    ],
    "DYMHT": [
      "DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8",
      "DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8"
    ],
    "QCDHT": [
      "QCD_HT200to300_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT300to500_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT500to700_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT700to1000_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT1000to1500_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT1500to2000_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
      "QCD_HT2000toInf_TuneCP5_PSWeights_13TeV-madgraph-pythia8",
    ],
    "WJETS": [
      "WJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-pythia8"
    ],
    "WJETSHT": [
      "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8",
      "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8",
    ],
    "TTXY": [
      "TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8",
      "TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8",
      "TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8",
      "TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8",
      "TTHH_TuneCP5_13TeV-madgraph-pythia8",
      "TTZZ_TuneCP5_13TeV-madgraph-pythia8",
      "TTWW_TuneCP5_13TeV-madgraph-pythia8",
      "TTWH_TuneCP5_13TeV-madgraph-pythia8",
      "TTZH_TuneCP5_13TeV-madgraph-pythia8",
      "TTWZ_TuneCP5_13TeV-madgraph-pythia8",
      "ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8",
      "ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8",
    ],
    "TOP": [
      "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",
      "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8",
      "ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8",
      "ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8",
      "ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8"
    ],
    "EWK": [
      "WW_TuneCP5_13TeV-pythia8",
      "WZ_TuneCP5_13TeV-pythia8",
      "ZZ_TuneCP5_13TeV-pythia8"
    ]
  },
}
