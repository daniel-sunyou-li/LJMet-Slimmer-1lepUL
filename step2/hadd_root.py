import os, sys, time, subprocess, math
from argparse import ArgumentParser
import config

parser = ArgumentParser()
parser.add_argument( "-y", "--year", default = "17" )
parser.add_argument( "-t", "--tag" )
parser.add_argument( "-l", "--loc", required = True, help = "BRUX,LPC" )
parser.add_argument( "--custom", action = "store_true" )
args = parser.parse_args()

from ROOT import *

execfile( "../EOSSafeUtils.py" )


if args.loc == "LPC":
  haddDir = os.path.join( config.haddPath[ args.year ][ "LPC" ], "nominal" )
  haddFiles = EOSlist_root_files( haddDir )
  hadd_command = "hadd -f root://cmseos.fnal.gov/{}/{}_renorm.root".format( haddDir, args.tag )
elif args.loc == "BRUX":
  haddDir = os.path.join( config.haddPath[ args.year ][ "BRUX" ], "nominal" )
  haddFiles = os.listdir( haddDir )
  hadd_command = "hadd -f {}/{}_renorm.root".format( haddDir, args.tag )

customFiles = [
#"TTWH_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
#"TTWW_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
#"TTWZ_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
#"TTZH_TuneCP5_13TeV-madgraph-pythia8_hadd.root",
#"TTZZ_TuneCP5_13TeV-madgraph-pythia8_hadd.root"
"WW_TuneCP5_13TeV-pythia8_hadd.root",
"WZ_TuneCP5_13TeV-pythia8_hadd.root",
"ZZ_TuneCP5_13TeV-pythia8_hadd.root",
]



for sample in haddFiles:
  if args.custom:
    if sample in customFiles:
      print( ">> Found {}, adding to hadd'd list...".format( sample ) )
      if args.loc == "LPC":
        hadd_command += " root://cmseos.fnal.gov/{}/{}".format( haddDir, sample )
      elif args.loc == "BRUX":
        hadd_command += " {}/{}".format( haddDir, sample ) 
  else:
    if args.tag in sample and "up" not in sample.lower() and "down" not in sample.lower(): 
      print( ">> Found {}, adding to hadd'd list...".format( sample ) )
      if args.loc == "LPC":
        hadd_command += " root://cmseos.fnal.gov/{}/{}".format( haddDir, sample )
      elif args.loc == "BRUX":
        hadd_command += " {}/{}".format( haddDir, sample )

os.system( hadd_command )
