import os, sys, time, subprocess, math
from argparse import ArgumentParser
import config

parser = ArgumentParser()
parser.add_argument( "-y", "--year", default = "17" )
parser.add_argument( "-t", "--tag" )
args = parser.parse_args()

from ROOT import *

execfile( "../EOSSafeUtils.py" )

haddDir = os.path.join( config.haddPath[ args.year ][ "LPC" ], "nominal" )

haddFiles = EOSlist_root_files( haddDir )

files_to_hadd = []

hadd_command = "hadd -f root://cmseos.fnal.gov/{}/{}_hadd.root".format( haddDir, args.tag )

for sample in haddFiles:
  if args.tag in sample and "up" not in sample.lower() and "down" not in sample.lower(): 
    print( ">> Found {}, adding to hadd'd list...".format( sample ) )
    files_to_hadd.append( sample )
    hadd_command += " root://cmseos.fnal.gov/{}/{}".format( haddDir, sample )

os.system( hadd_command )
