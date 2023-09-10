import os, sys, time, subprocess, math
from argparse import ArgumentParser
import config

parser = ArgumentParser()
parser.add_argument( "-y", "--year", default = "17" )
parser.add_argument( "-l", "--loc", required = True, help = "BRUX,LPC" )
args = parser.parse_args()

from ROOT import *

execfile( "../EOSSafeUtils.py" )

tags = [
  "TTTX",
  "TTNOBB",
  "TTBB",
  "TTNOBBHT500",
  "TTBBHT500",
  "ST",
  "TTH",
  "QCD",
  "TTXY",
  "EWK"
]

customFiles = {
  "TTTX": [
    "TTTT_TuneCP5_13TeV-amcatnlo-pythia8_hadd.root",
    "TTTT_TuneCP5_13TeV-amcatnlo-pythia8_1_hadd.root",
    "TTTT_TuneCP5_13TeV-amcatnlo-pythia8_2_hadd.root",
    "TTTT_TuneCP5_13TeV-amcatnlo-pythia8_3_hadd.root",
    "TTTJ_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
    "TTTW_TuneCP5_13TeV-madgraph-pythia8_hadd.root"
  ],
  "TTNOBB": [
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_1_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_2_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_3_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_4_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_5_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_6_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_7_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_8_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_9_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_10_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttcc_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_tt1b_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_tt2b_hadd.root",
  ],
  "TTBB": [
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttbb_hadd.root",
  ],
  "TTNOBBHT500": [
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT500Njet9_tt1b_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT500Njet9_tt2b_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT500Njet9_ttbb_hadd.root",
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT500Njet9_ttcc_hadd.root",
  ],
  "TTBBHT500": [
    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT500Njet9_ttjj_hadd.root"
  ],
  "TTH": [
    "ttHTobb_M125_TuneCP5_13TeV-powheg-pythia8_hadd.root",
    "ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8"
  ],
  "ST": [
    "ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8_hadd.root",
    "ST_t-channel_top_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8_hadd.root",
    "ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8_hadd.root",
    "ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_hadd.root",
    "ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8_hadd.root",
  ],
  "QCD": [
    "QCD_HT200to300_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root",
    "QCD_HT300to500_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root",
    "QCD_HT500to700_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root",
    "QCD_HT700to1000_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root",
    "QCD_HT1000to1500_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root",
    "QCD_HT1500to2000_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root",
    "QCD_HT2000toInf_TuneCP5_PSWeights_13TeV-madgraph-pythia8_hadd.root",
  ],
  "TTXY": [
    "TTWH_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
    "TTWW_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
    "TTWZ_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
    "TTZH_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
    "TTZZ_TuneCP5_13TeV-madgraph-pythia8_hadd.root"
    "TTHH_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
    "TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_hadd.root",
    "TTWJetsToQQ_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_hadd.root", 
    "TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8_hadd.root",
    "TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8_hadd.root",
  ],
  "EWK": [
    "WW_TuneCP5_13TeV-pythia8_hadd.root",
    "WZ_TuneCP5_13TeV-pythia8_hadd.root",
    "ZZ_TuneCP5_13TeV-pythia8_hadd.root",
    "DYJetsToLL_M-50_HT-200to400_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_hadd.root",
    "DYJetsToLL_M-50_HT-400to600_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_hadd.root",
    "DYJetsToLL_M-50_HT-600to800_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_hadd.root",
    "DYJetsToLL_M-50_HT-800to1200_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_hadd.root",
    "DYJetsToLL_M-50_HT-1200to2500_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_hadd.root",
    "DYJetsToLL_M-50_HT-2500toInf_TuneCP5_PSweights_13TeV-madgraphMLM-pythia8_hadd.root",
    "WJetsToLNu_HT-200To400_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root",
    "WJetsToLNu_HT-400To600_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root",
    "WJetsToLNu_HT-600To800_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root",
    "WJetsToLNu_HT-800To1200_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root",
    "WJetsToLNu_HT-1200To2500_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root",
    "WJetsToLNu_HT-2500ToInf_TuneCP5_13TeV-madgraphMLM-pythia8_hadd.root",
  ]
}

for tag in tags:
  print( "[INFO] Hadding files for tag: {}".format( tag ) )
  if args.loc == "LPC":
    haddDir = os.path.join( config.haddPath[ args.year ][ "LPC" ], "nominal" )
    haddFiles = EOSlist_root_files( haddDir )
    hadd_command = "hadd -f root://cmseos.fnal.gov/{}/{}_renorm.root".format( haddDir, tag )
  elif args.loc == "BRUX":
    haddDir = os.path.join( config.haddPath[ args.year ][ "BRUX" ], "nominal" )
    haddFiles = os.listdir( haddDir )
    hadd_command = "hadd -f {}/{}_renorm.root".format( haddDir, tag )
  if tag in customFiles:
    for sample in haddFiles:
      if sample not in customFiles[ tag ] or "renorm" in sample: continue
      print( "  + {}".format( sample ) )
      if args.loc == "LPC":
        hadd_command += " root://cmseos.fnal.gov/{}/{}".format( haddDir, sample ) 
      elif args.loc == "BRUX":
        hadd_command += " {}/{}".format( haddDir, sample )
  else:
    for sample in haddFiles:
      if "renorm" in sample: continue
      if tag in sample and "up" not in sample.lower() and "down" not in sample.lower():
        print( "  + {}".format( sample ) )
        if args.loc == "LPC":
          hadd_command += " root://cmseos.fnal.gov/{}/{}".format( haddDir, sample )
        elif args.loc == "BRUX":
          hadd_command += " {}/{}".format( haddDir, sample )

  os.system( hadd_command )
