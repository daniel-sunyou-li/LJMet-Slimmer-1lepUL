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
  "QCD_HT",
  "DYJetsToLL_M-50",
  "WJetsToLNu_HT",
  "TTXY",
  "EWK"
]

customFiles = {
  "TTXY": [
    "TTWH_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
    "TTWW_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
    "TTWZ_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
    "TTZH_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
    "TTZZ_TuneCP5_13TeV-madgraph-pythia8_hadd.root"
  ],
  "EWK": [
    "WW_TuneCP5_13TeV-pythia8_hadd.root",
    "WZ_TuneCP5_13TeV-pythia8_hadd.root",
    "ZZ_TuneCP5_13TeV-pythia8_hadd.root",
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
