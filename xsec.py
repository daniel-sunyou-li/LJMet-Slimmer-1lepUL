import ROOT

year = "2018"
rPath = "root://brux30.hep.brown.edu:1094//store/user/dali/"
rDir = rPath + "FWLJMET106XUL_singleLep{}UL_RunIISummer20_3t_step1hadds/nominal/".format( year )

lumi = {
    "2016APV": 19520,
    "2016": 16810. * 0.995,
    "2017": 41480.,
    "2018": 59832.
}

k_factor = {
      "WJetsMG": 1.21
}

xsec = {
    "TTTW_TuneCP5_13TeV-madgraph-pythia8_hadd.root": 0.0003974,
    "TTTJ_TuneCP5_13TeV-madgraph-pythia8_hadd.root": 0.0007314,
    "ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8_hadd.root": 3.44,
    "ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8_hadd.root": 136.02,
    "ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8_hadd.root": 80.95,
    "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_hadd.root": 35.83,
    "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_hadd.root": 35.83,
    #"TTTT_TuneCP5_13TeV-amcatnlo-pythia8_hadd.root": 0.01197,
    "TTTT_TuneCP5_13TeV-amcatnlo-pythia8_1_hadd.root": 0.01197,
    "TTTT_TuneCP5_13TeV-amcatnlo-pythia8_2_hadd.root": 0.01197,
    "TTTT_TuneCP5_13TeV-amcatnlo-pythia8_3_hadd.root": 0.01197,
    "TTHH_TuneCP5_13TeV-madgraph-pythia8_hadd.root": 0.0006655,
    "TTWH_TuneCP5_13TeV-madgraph-pythia8_hadd.root": 0.001141,
    "TTWW_TuneCP5_13TeV-madgraph-pythia8_hadd.root": 0.00703,
    "TTWZ_TuneCP5_13TeV-madgraph-pythia8_hadd.root": 0.002453,
    "TTZH_TuneCP5_13TeV-madgraph-pythia8_hadd.root": 0.00113,
    "TTZZ_TuneCP5_13TeV-madgraph-pythia8_hadd.root": 0.001385,
    "TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8_hadd.root": 0.2439,
    "TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_hadd.root": 0.4377, 
    "TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_hadd.root": 0.2161,
    "TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8_hadd.root": 0.05324,
    "ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8_hadd.root": 0.291,
    "ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8_hadd.root": 0.209,
    "WW_TuneCP5_13TeV-pythia8_hadd.root": 118.7,
    "WZ_TuneCP5_13TeV-pythia8_hadd.root": 47.13,
    "ZZ_TuneCP5_13TeV-pythia8_hadd.root": 16.523,
    "DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_hadd.root": 54.951,
    "DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_hadd.root": 7.862,
    "DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_hadd.root": 1.977,
    "DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_hadd.root": 0.858,
    "DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_hadd.root": 0.191,
    "DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_hadd.root": 0.0045,
    "QCD_HT200to300_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root": 1712000,
    "QCD_HT300to500_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root": 347700,
    "QCD_HT500to700_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root": 32100,
    "QCD_HT700to1000_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root": 6831,
    "QCD_HT1000to1500_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root": 1207,
    "QCD_HT1500to2000_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root": 119.9,
    "QCD_HT2000toInf_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root": 25.24,
    "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root": 359.7 * k_factor[ "WJetsMG" ],
    "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root": 48.91 * k_factor[ "WJetsMG" ],
    "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root": 12.05 * k_factor[ "WJetsMG" ],
    "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root": 5.501 * k_factor[ "WJetsMG" ],
    "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root": 1.329 * k_factor[ "WJetsMG" ],
    "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root": 0.03216 * k_factor[ "WJetsMG" ],   
    "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8_tt1b_hadd.root": 831.8 * 0.105,
    "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8_tt2b_hadd.root": 831.8 * 0.105,
    "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8_ttbb_hadd.root": 831.8 * 0.105,
    "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8_ttcc_hadd.root": 831.8 * 0.105,
    "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8_ttjj_hadd.root": 831.8 * 0.105,
    "TTToHadronic_TuneCP5_13TeV-powheg-pythia8_tt1b_hadd.root": 831.8 * 0.457,
    "TTToHadronic_TuneCP5_13TeV-powheg-pythia8_tt2b_hadd.root": 831.8 * 0.457,
    "TTToHadronic_TuneCP5_13TeV-powheg-pythia8_ttbb_hadd.root": 831.8 * 0.457,
    "TTToHadronic_TuneCP5_13TeV-powheg-pythia8_ttcc_hadd.root": 831.8 * 0.457,
    "TTToHadronic_TuneCP5_13TeV-powheg-pythia8_ttjj_hadd.root": 831.8 * 0.457,
    "TTToSemiLepton_HT500Njet9_TuneCP5_13TeV-powheg-pythia8_tt1b_hadd.root": 2.251,
    "TTToSemiLepton_HT500Njet9_TuneCP5_13TeV-powheg-pythia8_tt2b_hadd.root": 2.251,
    "TTToSemiLepton_HT500Njet9_TuneCP5_13TeV-powheg-pythia8_ttbb_hadd.root": 2.251,
    "TTToSemiLepton_HT500Njet9_TuneCP5_13TeV-powheg-pythia8_ttcc_hadd.root": 2.251,
    "TTToSemiLepton_HT500Njet9_TuneCP5_13TeV-powheg-pythia8_ttjj_hadd.root": 2.251,
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_tt1b_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_tt2b_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttbb_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttcc_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_1_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_2_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_3_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_4_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_5_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_6_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_7_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_8_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_9_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_10_hadd.root": 831.8 * 0.438 * ( 1 - 0.00618 ),
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT500Njet9_tt1b_hadd.root": 831.8 * 0.438 * 0.00618,
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT500Njet9_tt2b_hadd.root": 831.8 * 0.438 * 0.00618,
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT500Njet9_ttbb_hadd.root": 831.8 * 0.438 * 0.00618,
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT500Njet9_ttcc_hadd.root": 831.8 * 0.438 * 0.00618,
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT500Njet9_ttjj_hadd.root": 831.8 * 0.438 * 0.00618,
}
norm = {}
for file in xsec:
    if "TTToSemiLeptonic" in file and "HT0Njet0_ttjj" in file:
        rFile = ROOT.TFile.Open( rDir + "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_tt1b_hadd.root" )
        rTree = rFile.Get( "NumTrueHist" ).Clone( "NumTrueHist" )
        nTrueHist = rTree.Integral()
    elif "TTTT" in file and year == "2018":
        nTrueHist = 0
        for i in range(1,4):
            rFile = ROOT.TFile.Open( rDir + "TTTT_TuneCP5_13TeV-amcatnlo-pythia8_{}_hadd.root".format(i) )
            rTree = rFile.Get( "NumTrueHist" ).Clone( "NumTrueHist" )
            nTrueHist += rTree.Integral()
    else:
        rFile = ROOT.TFile.Open( rDir + file )
        rTree = rFile.Get( "NumTrueHist" ).Clone( "NumTrueHist" )
        nTrueHist = rTree.Integral()
    norm[file] = lumi[year] * xsec[file] / nTrueHist
    rFile.Close()