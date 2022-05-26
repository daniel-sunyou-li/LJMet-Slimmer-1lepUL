import os, sys, time, subprocess, math
from argparse import ArgumentParser
import config

start_time = time.time()

parser = ArgumentParser()
parser.add_argument( "-y", "--year", default = "17", help = "Options: [16APV,16,17,18]" )
parser.add_argument( "-g", "--groups", nargs = "+", required = True )
parser.add_argument( "-f", "--filesPerHadd", default = "900" )
parser.add_argument( "-l", "--location", default = "LPC", help = "Options: LPC, BRUX" )
parser.add_argument( "--shifts", action = "store_true" )
args = parser.parse_args()

from ROOT import *

execfile( "../EOSSafeUtils.py" )

shifts = [ "nominal" ] if not args.shifts else [ "JECdown" ] # [ "JECup", "JECdown", "JERup", "JERdown" ]

step1Dir = {
  shift: os.path.join( config.step1Dir[ args.year ][ args.location ], shift ) for shift in shifts
}

haddDir = {
  shift: os.path.join( config.haddDir[ args.year ][ args.location ], shift ) for shift in shifts 
}

for shift in shifts:
  if args.location == "LPC":
    os.system( "eos root://cmseos.fnal.gov/ mkdir -p {}".format( haddDir[ shift ] ) )
  elif args.location == "BRUX":
    if not os.path.exists( haddDir[ shift ] ): os.system( "mkdir -p {}".format( haddDir[ shift ] ) )

if args.location not in [ "LPC", "BRUX" ]: 
  print( ">> [] is not a valid location option. Using: LPC" )
  location = "LPC"
else: location = args.location

samples = {}
for shift in shifts:
  samples[ shift ] = []
  for group in args.groups:
    if group not in config.samples[ args.year ].keys():
      print( "[WARN] {} not a valid group for 20{}, skipping".format( group, args.year ) )
      continue
    print( "[INFO] Preparing {} condor jobs for group: {}".format( shift, group ) )
    for sample in config.samples[ args.year ][ group ]: 
      print( "   + {}".format( sample ) )
      samples[ shift ].append( sample )

failed_hadd = {}

for shift in shifts:
  failed_hadd[shift] = []
  for sample in samples[ shift ]:
    if args.year == "18" and sample == "SingleElectron": sample = "EGamma"
    if shift != "nominal":
      if "Single" in sample or "EGamma" in sample or "up" in sample.lower() or "down" in sample.lower(): continue
    outList = []
    if "TTToSemiLeptonic" in sample and "up" not in sample.lower() and "down" not in sample.lower():
      for HT_key in [ "HT0Njet0", "HT500Njet9" ]:
        for fs_key in [ "ttbb", "tt2b", "tt1b", "ttcc", "ttjj" ]:
          outList.append( "{}_{}".format( HT_key, fs_key ) )
    elif "TTTo" in sample:
      outList = [ "ttbb", "tt2b", "tt1b", "ttcc", "ttjj" ]
    else:
      outList = [ "none" ]

    for outLabel in outList:
      outSample = sample if outLabel == "none" else "{}_{}".format( sample, outLabel )
      if args.location == "LPC":
        step1Files = EOSlist_root_files( os.path.join( step1Dir[ shift ], outSample ) )
      elif args.location == "BRUX":
        step1Files = [ fName for fName in os.listdir( os.path.join( step1Dir[ shift ], outSample ) ) if ".root" in fName ]

      print( ">> Hadd'ing {}: {} files".format( outSample, len( step1Files ) ) )
    
      filesPerHadd = int( args.filesPerHadd )
      if "TTToSemiLeptonic" in outSample and outLabel in [ "HT0Njet0_ttjj" ]: filesPerHadd = 45
      #elif "WJetsToLNu_HT-1200To2500" in outSample: filesPerHadd = 120
      #elif "WJetsToLNu_HT-2500ToInf" in outSample: filesPerHadd = 13
      if "hdamp" in outSample.lower() or "tunecp5up" in outSample.lower() or "tunecp5down" in outSample.lower(): filesPerHadd = 900

      singleFile = " root://cmseos.fnal.gov/{}/{}/{}".format( step1Dir[shift], outSample, step1Files[-1] )
      multipleFiles = filesPerHadd * singleFile
      lengthCheck = len( "hadd -f root://cmseos.fnal.gov/{}/{}_hadd.root {}".format( haddDir[shift], outSample, multipleFiles ) )
      if lengthCheck > 126000:
        overflow = lengthCheck - 126000
        nRemove = math.ceil( overflow / len( singleFile ) )
        filesPerHadd = int( filesPerHadd - nRemove )
        print( "[WARN] Length estimate reduced from {} by {} via removing {} files for {} hadd'd files".format( lengthCheck, overflow, nRemove, filesPerHadd ) )

      haddCommand = ""
      if len( step1Files ) < filesPerHadd:
        if args.location == "LPC":
          haddCommand = "hadd -f root://cmseos.fnal.gov/{}/{}_hadd.root ".format( haddDir[shift], outSample )
        elif args.location == "BRUX":
          haddCommand = "hadd -f {}/{}_hadd.root".format( haddDir[shift], outSample )
        for step1 in step1Files: 
          if args.location == "LPC":
            haddCommand += " root://cmseos.fnal.gov/{}/{}/{}".format( step1Dir[shift], outSample, step1 )
          elif args.location == "BRUX":
            haddCommand += " {}/{}/{}".format( step1Dir[shift], outSample, step1 )
        print( ">> Length of {} hadd command: {}".format( outSample, len( haddCommand ) ) )
        subprocess.call( haddCommand, shell = True )
      else:
        for i in range( int( math.ceil( len( step1Files ) / float( filesPerHadd ) ) ) ):
          if args.location == "LPC":
            haddCommand = "hadd -f root://cmseos.fnal.gov/{}/{}_{}_hadd.root ".format( haddDir[ shift ], outSample, i + 1 )
          elif args.location == "BRUX":
            haddCommand = "hadd -f {}/{}_{}_hadd.root".format( haddDir[ shift ], outSample, i + 1 )
          begin = i * filesPerHadd
          end = ( i + 1 ) * filesPerHadd
          if end > len( step1Files ): end = len( step1Files )
          for j in range( begin, end ):
            if args.location == "LPC":
              haddCommand += " root://cmseos.fnal.gov/{}/{}/{}".format( step1Dir[ shift ], outSample, step1Files[j] )
            elif args.location == "BRUX":
              haddCommand += " {}/{}/{}".format( step1Dir[ shift ], outSample, step1Files[j] )
          try:
            subprocess.call( haddCommand, shell = True )
          except:
            failed_hadd[ shift ].append( outSample )

for shift in failed_hadd:
  if len( failed_hadd[ shift ] ) > 0:
    print( "[WARN] Failed hadd'ing {}:".format( shift ) )
    for sample in failed_hadd[ shift ]:
      print( "  + {}".format( sample ) )

print( "[DONE] Finished hadd'ing samples in {:.2f} minutes.".format( round( time.time() - start_time, 2 ) / 60 ) )
