eosUserName = "dali"
postfix = "deepJetV1"
years = [ "17" ]

haddPath = {
  year: {
    "LPC": "/eos/uscms/store/user/{}/FWLJMET106XUL_1lep20{}_3t_{}_step1hadds".format( eosUserName, year, postfix ),
    "BRUX": "/isilon/hadoop/store/user/{}/FWLJMET106XUL_1lep20{}_3t_{}_step1hadds".format( eosUserName, year, postfix ) 
  } for year in years
}

step2Path = {
  year: {
    "LPC": "/eos/uscms/store/user/{}/FWLJMET106XUL_1lep20{}_3t_{}_step2".format( eosUserName, year, postfix ), 
    "BRUX": "/isilon/hadoop/store/user/{}/FWLJMET106XUL_1lep20{}_3t_step2".format( eosUserName, year, postfix )
  } for year in years
}

lumi = {
  "16": 35867.,
  "17": 41530.,
  "18": 59970.
}

xsec_ttbar = 831.8 # +19.8+35.1 -29.2-35.1 https://pdg.lbl.gov/2018/reviews/rpp2018-rev-top-quark.pdf
br_ttbar = {
  "TTToHadronic": 0.457,
  "TTToSemiLeptonic": 0.438,
  "TTTo2L2Nu": 0.105
}
filtEff_ttbar = {
  "Njet9": 0.00617938417682763,
  "Njet9HDdn": 0.005645170035947885,
  "Njet9HDup": 0.006711348259851689,
  "Njet9UEdn": 0.006108623095875414,
  "Njet9UEup": 0.0062286452403598055 
}
k_factor = {
  "WJets": 1.21
}

xsec = {
  "TTTW": 0.0007314, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20TTTW,
  "TTTJ": 0.0003974, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20TTTJ
  "TTToHadronic": xsec_ttbar * br_ttbar[ "TTToHadronic" ], 
  "TTToSemiLeptonicNjet0": xsec_ttbar * br_ttbar[ "TTToSemiLeptonic" ] * ( 1.0 - filtEff_ttbar[ "Njet9" ] ),
  "TTToSemiLeptonicNjet9": xsec_ttbar * br_ttbar[ "TTToSemiLeptonic" ] * filtEff_ttbar[ "Njet9" ],
  "TTToSemiLeptonHT500": 2.251,
  "TTTo2L2Nu": xsec_ttbar * br_ttbar[ "TTTo2L2Nu" ],
  "TTTT": 0.01197, # https://arxiv.org/pdf/1711.02116.pdf
  "TTWW": 0.00703, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20TTWW 
  "TTZZ": 0.001385, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20TTZZ
  "TTHH": 0.0006655, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20TTHH_TuneCP5
  "TTZH": 0.00113, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20TTZH_TuneCP5
  "TTWZ": 0.002453, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20TTWZ_TuneCP5
  "TTWH": 0.001141, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20TTWH_TuneCP5
  "TTWl": 0.2161, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20TTWJetsToLNu_TuneCP5_13TeV
  "TTWq": 0.4377, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20TTWJetsToQQ_TuneCP5_13TeV
  "TZM1to10": 0.05324, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20TTZToLL_M-1to10_TuneCP5
  "TTZM10": 0.2439, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20TTZToLLNuNu_M-10_TuneCP5_13TeV
  "TTHbb": 0.5269, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20ttHTobb_M125_TuneCP5
  "TTHnonbb": 0.5638, # https://cms-gen-dev.cern.ch/xsdb/?columns=67108863&currentPage=0&pageSize=10&searchQuery=process_name%20%3D%20ttHTobb_M125_TuneCP5 
  "ST_tW_top": 35.83, # https://twiki.cern.ch/twiki/bin/view/LHCPhysics/SingleTopRefXsec
  "ST_tW_antitop": 35.83, # https://twiki.cern.ch/twiki/bin/view/LHCPhysics/SingleTopRefXsec
  "ST_t_top": 136.02, # https://twiki.cern.ch/twiki/bin/view/LHCPhysics/SingleTopRefXsec
  "ST_t_antitop": 80.95, # https://twiki.cern.ch/twiki/bin/view/LHCPhysics/SingleTopRefXsec
  "ST_s": 3.44, # https://twiki.cern.ch/twiki/bin/view/LHCPhysics/SingleTopRefXsec
  "WW": 118.7, # https://arxiv.org/pdf/1408.5243.pdf
  "WZ": 47.13, # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "ZZ": 16.523, # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "DYM50HT200": 54.951, # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "DYM50HT400": 7.862, # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "DYM50HT600": 1.977, # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "DYM50HT800": 0.858, # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "DYM50HT1200": 0.191, # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "DYM50HT2500": 0.0045, # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "WJetsMG200": 359.7 * k_factor[ "WJets" ], # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "WJetsMG400": 48.91 * k_factor[ "WJets" ], # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "WJetsMG600": 12.05 * k_factor[ "WJets" ], # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "WJetsMG800": 5.501 * k_factor[ "WJets" ], # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "WJetsMG1200": 1.329 * k_factor[ "WJets" ], # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets 
  "WJetsMG2500": 0.03216 * k_factor[ "WJets" ], # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "QCDHT200": 1712000, # https://twiki.cern.ch/twiki/bin/view/CMS/SummaryTable1G25ns#W_jets
  "QCDHT300": 347700,
  "QCDHT500": 32100,
  "QCDHT700": 6831,
  "QCDHT1000": 1207,
  "QCDHT1500": 119.9,
  "QCDHT2000": 25.24
}

for syst in [ "HD", "UE" ]:
  for shift in [ "up", "dn" ]:
    xsec[ "TTToSemiLeptonicNjet0" + syst + shift ] = xsec_ttbar * br_ttbar[ "TTToSemiLeptonic" ] * ( 1.0 - filtEff_ttbar[ "Njet9" + syst + shift ] )
    xsec[ "TTToSemiLeptonicNjet9" + syst + shift ] = xsec_ttbar * br_ttbar[ "TTToSemiLeptonic" ] * filtEff_ttbar[ "Njet9" + syst + shift ]
  
nrun = {
  "17": {
    "TTTW": 360000.,
    "TTTJ": 354000.,
    "TTToHadronic": 233815417.,
    "TTToSemiLeptonicNjet0": 352212660.,
    "TTToSemiLeptonicNjet9": 352212660.,
    "TTToSemiLeptonHT500": 10179200.,
    "TTTo2L2Nu": 44580106. + 28515514. + 51439568. + 47012288. + 25495972.,
    "TTTT": 4526556.,
    "TTWW": 698000.,
    "TTZZ": 327000.,
    "TTHH": 360000.,
    "TTZH": 350000.,
    "TTWZ": 350000.,
    "TTWH": 360000.,
    "TTWl": 6497731.,
    "TTWq": 359006.,
    #"TTZM1to10": 
    "TTZM10": 6990534.,
    "TTHbb": 7661778.,
    "TTHnonbb": 4965389.,
    "ST_tW_top": 5648712.,
    "ST_tW_antitop": 5673700.,
    #ST_t_top": 
    "ST_t_antitop": 65821722., 
    "ST_s": 8938338., 
    "WW": 15634000.,
    "WZ": 7889000.,
    "ZZ": 2706000.,
    "DYM50HT200":  12513057.,
    "DYM50HT400":  5543804.,
    "DYM50HT600":  5278417., 
    "DYM50HT800":  4506887.,
    "DYM50HT1200": 4802716., 
    "DYM50HT2500": 1480047.,
    "WJetsMG200": 42602407.,
    "WJetsMG400": 5437447.,
    "WJetsMG600": 5545298.,
    #"WJetsMG800": 
    "WJetsMG1200": 4942590., 
    #"WJetsMG2500": 
    #"QCDHT200": 
    #"QCDHT300": 
    "QCDHT500": 36194860.,
    "QCDHT700": 34051754.,
    #"QCDHT1000": 
    "QCDHT1500": 7701876.,
    #"QCDHT2000": 
  }
}

xsecEff = { year: {} for year in years }
for year in years:
  for sample in nrun[ year ]:
    xsecEff[ year ][ sample ] = lumi[ year ] * xsec[ sample ] / nrun[ year ][ sample ] 
