import os, sys, shutil, time
import getpass
import config
from XRootD import client
from argparse import ArgumentParser

execfile( "../EOSSafeUtils.py" )

start_time = time.time()

parser = ArgumentParser()
parser.add_argument( "-y", "--year", default = "17", help = "Year options: [16APV,16,17,18]" )
parser.add_argument( "--test", action = "store_true", help = "Run only a single file" )
parser.add_argument( "--dnn", action = "store_true", help = "Run only files used in step3 DNN training" )
parser.add_argument( "--shifts", action = "store_true", help = "Run JEC/JER shift samples" )
parser.add_argument( "-i", "--inLoc", default = "LPC", help = "step1 location options: LPC, BRUX" )
parser.add_argument( "-o", "--outLoc", default = "LPC", help = "step2 destination options: LPC, BRUX" )
args = parser.parse_args()

from ROOT import *

if args.year not in [ "16APV", "16", "17", "18" ]: 
  sys.exit( "[ERR] Invalid year option used. Choose from: 16APV, 16, 17, 18" )

shifts = []
if not args.shifts:
  shifts.append( "nominal" )
else:
  print( "[INFO] Running step2 on shifts:" )
  for syst in config.JES_shifts:
    for shift in [ "up", "down" ]:
      if config.JES_shifts[ syst ]:
        sName = syst.replace( "Era", "20{}".format( args.year ) ) + shift
        sName = sName.replace( "2016APV", "2016" )
        print( "  + {}".format( sName ) )
        shifts.append( sName )

runDir = os.getcwd()
inputDir = {
  shift: os.path.join( config.haddPath[ args.year ][ args.inLoc ], shift ) for shift in shifts
}
outputDir = {
  shift: os.path.join( config.step2Path[ args.year ][ args.outLoc ], shift ) for shift in shifts
}
condorDir = {
  shift: os.path.join( runDir, "logs_UL{}_{}/{}".format( args.year, config.postfix, shift ) ) for shift in shifts
}

if args.outLoc == "LPC":
  for shift in shifts:
    os.system( "eos root://cmseos.fnal.gov mkdir -p {}".format( outputDir[ shift ] ) )
    os.system( "mkdir -p {}".format( condorDir[ shift ] ) )
else:
  for shift in shifts:
    os.system( "mkdir -vp {}".format( outputDir[ shift ] ) )
    os.system( "mkdir -p {}".format( condorDir[ shift ] ) )


gROOT.ProcessLine( ".x compile_step2.C" )

print( ">> Starting step2 Condor submission..." )

step1Files = {}
if args.inLoc == "LPC":
  step1Files = {
    shift: EOSlistdir( inputDir[ shift ] ) for shift in shifts 
  }
elif args.inLoc == "BRUX":
  xrdClient = client.FileSystem( "root://brux30.hep.brown.edu:1094/" )
  for shift in shifts:
    status, dirList = xrdClient.dirlist( inputDir[ shift ].replace( "/isilon/hadoop", "" ) )
    step1Files[ shift ] = [ item.name for item in dirList ]
else:
  quit( "[ERR] Invalid input location, quitting..." )

if args.outLoc == "LPC":
  step2Files = {
    shift: EOSlistdir( outputDir[ shift ] ) for shift in shifts
  }
elif args.outLoc == "BRUX":
  step2Files = {
    shift: os.listdir( os.path.join( config.step2Path[ args.year ][ "BRUX" ], shift ) ) for shift in shifts
  }
else:
  quit( "[ERR] Invalid output location, quitting..." )

jobCount = 0
for shift in shifts:
  if args.test:
    if shift != "nominal": continue
  for rootFile in step1Files[ shift ]:
    if args.test: 
      if "TTTJ" not in rootFile: continue
    if args.dnn:
      if "TTTW" not in rootFile and "TTTJ" not in rootFile and "TTTT" not in rootFile and "TTTo" not in rootFile: continue
      if "up" in rootFile.lower() or "down" in rootFile.lower(): continue
    if not rootFile.endswith( ".root" ) or "hadd" not in rootFile: continue
    if rootFile in step2Files[ shift ]: 
      print( "[WARN] {} step2 completed, skipping...".format( rootFile ) )
      continue # skip finished step2 files
    
    jobParams = {
      "RUNDIR": runDir, 
      "CONDORDIR": condorDir[ shift ], 
      "INPUTDIR": inputDir[ shift ], 
      "SHIFT": shift,
      "FILENAME": rootFile.split( "." )[0], 
      "TAG": rootFile.split( "_TuneCP5" )[0],
      "YEAR": "20" + args.year,
      "SYSFILE": "renorm/HT_njets_SF_UL{}_sys.root".format( args.year ),
      "OUTPUTDIR": outputDir[ shift ]
    }
    jdfName = os.path.join( condorDir[ shift ], rootFile.split( "." )[0] ) + ".job"
    jdf = open( jdfName, "w" )
    jdf.write(
"""universe = vanilla
Executable = %(RUNDIR)s/make_step2.sh
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
request_memory = 4096
Transfer_Input_Files = %(RUNDIR)s/%(SYSFILE)s, %(RUNDIR)s/HardcodedConditions.cc, %(RUNDIR)s/HardcodedConditions.h, %(RUNDIR)s/make_step2.C, %(RUNDIR)s/step2.cc, %(RUNDIR)s/step2.h, %(RUNDIR)s/step2_cc.d, %(RUNDIR)s/step2_cc.so, %(RUNDIR)s/Davismt2.cc, %(RUNDIR)s/Davismt2.h, %(RUNDIR)s/Davismt2_cc.d, %(RUNDIR)s/Davismt2_cc.so
Output = %(FILENAME)s.out
Error = %(FILENAME)s.err
Log = %(FILENAME)s.log
JobBatchName = step2_UL%(YEAR)s_%(SHIFT)s_%(TAG)s
Notification = Never
Arguments = %(FILENAME)s.root %(FILENAME)s.root %(INPUTDIR)s %(OUTPUTDIR)s %(YEAR)s
Queue 1"""%jobParams )
    jdf.close()
    os.chdir( condorDir[ shift ] )
    print( ">> Submitting {}: {}".format( shift, rootFile.split( "." )[0] ) )
    os.system( "condor_submit {}.job -allow-crlf-script".format( rootFile.split( "." )[0] ) )
    os.system( "sleep 0.5" )                                 
    os.chdir( runDir )
    jobCount += 1

   
print( "[DONE] {} job(s) submitted after {:.2f} minutes".format( jobCount, round( time.time() - start_time, 2 ) / 60. ) )
