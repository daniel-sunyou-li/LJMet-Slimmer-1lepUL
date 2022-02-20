import os, sys
import config
from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument( "-y", "--year", default = "17" )
parser.add_argument( "-l", "--location", default = "LPC", help = "Options: LPC, BRUX, LOCAL" )
parser.add_argument( "-f", "--folder", help = "Used only if location == LOCAL" )
args = parser.parse_args()

execfile( "../EOSSafeUtils.py" )

import ROOT

if args.year not in [ "16", "17", "18" ]: sys.exit( "[ERR] Invalid year option. Use: 16, 17, 18" )
if args.location not in [ "LPC", "BRUX", "LOCAL" ]: sys.exit( "[ERR] Invalid location option. Use: LPC, BRUX, LOCAL" )

if args.location in [ "LPC", "BRUX" ]:
  if args.location == "LPC":
    haddDir = "root://cmsxrootd.fnal.gov//store/user/{}/FWLJMET106XUL_1lep20{}_3t_{}_step1hadds/nominal/".format( config.eosUserName, args.year, config.postfix )
    samples = EOSlistdir( os.path.join( config.haddPath[ args.year ][ "LPC" ], "nominal" ) )
  else: 
    haddDir = os.path.join( config.haddPath[ args.year ][ args.location ], "nominal" )
else:
  haddDir = args.folder


for sample in samples:
  if "single" in sample.lower() or "egamma" in sample.lower(): continue
  rFile = ROOT.TFile.Open( haddDir + sample )
  hist = rFile.Get( "NumTrueHist" ).Clone( "NumTrueHist" )
  print( "{}: {}".format( sample, hist.Integral() ) )
