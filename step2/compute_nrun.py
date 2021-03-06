import os, sys
import config
from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument( "-y", "--year", default = "17" )
parser.add_argument( "-s", "--shift", default = "nominal" )
parser.add_argument( "-l", "--location", default = "LPC", help = "Options: LPC, BRUX, LOCAL" )
parser.add_argument( "-f", "--folder", help = "Used only if location == LOCAL" )
args = parser.parse_args()

execfile( "../EOSSafeUtils.py" )

import ROOT

if args.year not in [ "16APV", "16", "17", "18" ]: sys.exit( "[ERR] Invalid year option. Use: 16APV, 16, 17, 18" )
if args.location not in [ "LPC", "BRUX", "LOCAL" ]: sys.exit( "[ERR] Invalid location option. Use: LPC, BRUX, LOCAL" )

if args.location in [ "LPC", "BRUX" ]:
  if args.location == "LPC":
    haddDir = "root://cmsxrootd.fnal.gov/" + config.haddPath[ args.year ][ "LPC" ].split( "uscms" )[-1] + "/{}/".format( args.shift )
    samples = EOSlistdir( os.path.join( config.haddPath[ args.year ][ "LPC" ], args.shift ) )
  else: 
    haddDir = os.path.join( config.haddPath[ args.year ][ args.location ], "{}/".format( args.shift ) )
    samples = os.listdir( haddDir )
else:
  haddDir = args.folder



print( "[INFO] Found {} samples:".format( len( samples ) ) )
for sample in samples:
  print( "   + {}".format( sample ) )

print( haddDir )

for sample in sorted( samples ):
  if "single" in sample.lower() or "egamma" in sample.lower(): continue
  rFile = ROOT.TFile.Open( haddDir + sample )
  hist = rFile.Get( "NumTrueHist" ).Clone( "NumTrueHist" )
  print( "{}: {}".format( sample, hist.Integral() ) )
