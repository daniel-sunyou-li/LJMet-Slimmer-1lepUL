import os, sys, shutil, time
import getpass
import config
from XRootD import client
from argparse import ArgumentParser

execfile( "../EOSSafeUtils.py" )

start_time = time.time()

parser = ArgumentParser()
parser.add_argument( "-y", "--year", default = "17", help = "Year options: [16,17,18]" )
parser.add_argument( "-t", "--test", action = "store_true" )
parser.add_argument( "-d", "--dnn", action = "store_true" )
parser.add_argument( "-s", "--systematics", action = "store_true" )
parser.add_argument( "-l", "--location", default = "LPC", help = "Options: LPC, BRUX" )
args = parser.parse_args()

from ROOT import *

if args.year not in [ "16", "17", "18" ]: sys.exit( "[ERR] Invalid year option used. Choose from: 16, 17, 18" )
shifts = [ "nominal" ] if not args.systematics else [ "JECup", "JECdown", "JERup", "JERdown" ]

runDir = os.getcwd()
inputDir = {
  shift: os.path.join( config.haddPath[ args.year ][ args.location ], shift ) for shift in shifts
}
outputDir = {
  shift: os.path.join( config.step2Path[ args.year ][ "LPC" ], shift ) for shift in shifts
}
condorDir = {
  shift: os.path.join( runDir, "logs_UL{}_{}/{}".format( args.year, config.postfix, shift ) ) for shift in shifts
}

for shift in shifts:
  os.system( "eos root://cmseos.fnal.gov mkdir -p {}".format( outputDir[ shift ] ) )
  os.system( "mkdir -p {}".format( condorDir[ shift ] ) )

gROOT.ProcessLine( ".x compile_step2.C" )

print( ">> Starting step2 Condor submission..." )

step1Files = {}
if args.location == "LPC":
  step1Files = {
    shift: EOSlistdir( inputDir[ shift ] ) for shift in shifts 
  }
elif args.location == "BRUX":
  xrdClient = client.FileSystem( "root://brux30.hep.brown.edu:1094/" )
  for shift in shifts:
    status, dirList = xrdClient.dirlist( inputDir[ shift ] )
    step1Files[ shift ] = [ item.name for item in dirList ]

step2Files = {
  shift: EOSlistdir( outputDir[ shift ] ) for shift in shifts
}

jobCount = 0
for shift in shifts:
  if args.test:
    if shift != "nominal": continue
  for rootFile in step1Files[ shift ]:
    if args.test: 
      if "TTTW" not in rootFile: continue
    if args.dnn:
      if "TTTW" not in rootFile and "TTTJ" not in rootFile and "TTTT" not in rootFile and "TTTo" not in rootFile: continue
      if "up" in rootFile.lower() or "down" in rootFile.lower(): continue
    if not rootFile.endswith( ".root" ): continue
    if rootFile in step2Files[ shift ]: 
      print( "[WARN] {} step2 completed, skipping...".format( rootFile ) )
      continue # skip finished step2 files
    
    jobParams = {
      "RUNDIR": runDir, 
      "CONDORDIR": condorDir[ shift ], 
      "INPUTDIR": inputDir[ shift ], 
      "FILENAME": rootFile.split( "." )[0], 
      "SYSFILE": "renorm/HT_njets_SF_3t_UL{}_sys.root".format( args.year ),
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
JobBatchName = step2_3t
Notification = Never
Arguments = %(FILENAME)s.root %(FILENAME)s.root %(INPUTDIR)s %(OUTPUTDIR)s
Queue 1"""%jobParams )
    jdf.close()
    os.chdir( condorDir[ shift ] )
    print( ">> Submitting {}: {}".format( shift, rootFile.split( "." )[0] ) )
    os.system( "condor_submit {}.job".format( rootFile.split( "." )[0] ) )
    os.system( "sleep 0.5" )                                 
    os.chdir( runDir )
    jobCount += 1

   
print( "[DONE] {} job(s) submitted after {:.2f} minutes".format( jobCount, round( time.time() - start_time, 2 ) / 60. ) )
