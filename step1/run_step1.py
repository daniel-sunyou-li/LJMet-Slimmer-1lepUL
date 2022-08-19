import os,shutil,time
import numpy as np
import getpass
import config
import subprocess
from tqdm import tqdm
from argparse import ArgumentParser
from XRootD import client

parser = ArgumentParser()
parser.add_argument( "-y", "--year", required = True, help = "Era to process. Options: 16APV, 16, 17, 18" )
parser.add_argument( "-g", "--groups", nargs = "+", help = "Sample groups to process, see config.py." )
parser.add_argument( "-f", "--filesPerJob", default = "30", help = "Number of LJMet files per Condor job. Default is 30, but recommended 10 for years 16APV,16" )
parser.add_argument( "-l", "--location", default = "LPC", help = "Location of LJMet files. Options: LPC, BRUX." )
parser.add_argument( "-s", "--site", default = "LPC", help = "Location where running step1. Options: LPC, BRUX." )
parser.add_argument( "-j", "--joblimit", default = "-1", help = "Limit on number of jobs to submit per sample, per final state (-1 for all)." )
parser.add_argument( "--test", action = "store_true", help = "Only submit one job." )
parser.add_argument( "--shifts", action = "store_true", help = "Run on JEC/JER shifts." )
parser.add_argument( "--verbose", action = "store_true" )
args = parser.parse_args()

from ROOT import *

xrdClient = client.FileSystem( "root://brux30.hep.brown.edu:1094/" )
execfile( "../EOSSafeUtils.py" )

start_time = time.time()

#IO directories must be full paths
if args.year not in [ "16APV", "16", "17", "18" ]: quit( "[ERR] Invalid year option. Use: 16APV, 16, 17, 18. Quitting..." )
if args.location not in [ "LPC", "BRUX" ]: quit( "[ERR] Invalid location option. Use: BRUX, LPC. Quitting..." )
if args.site not in [ "LPC", "BRUX" ]: quit( "[ERR] Invalid site option. Use: BRUX, LPC. Quitting..." )
if not args.shifts:
  shifts = [ "nominal" ]
else:
  shifts = []
  print( "[INFO] Running step1 on shifts:" )
  for syst in config.JES_shifts:
    for shift in [ "up", "down" ]:
      if config.JES_shifts[ syst ]:
        sName = syst.replace( "Era", "20{}".format( args.year.replace( "APV", "" ) ) ) + shift
        print( "  + {}".format( sName ) )
        shifts.append( sName )
  
filesPerJob = int( args.filesPerJob )
postfix = config.postfix

inputDir = config.ljmetDir[ args.year ][ args.location ]
if args.site == "BRUX" and args.location == "LPC":
  inputDir = inputDir.replace( "/eos/uscms", "" )
outputDir = {
  shift: os.path.join( config.step1Dir[ args.year ][ args.site ], shift ) for shift in shifts
}
condorDir = "./logs_UL{}_{}/".format( args.year, postfix )
for shift in shifts: os.system( "mkdir -p {}".format( os.path.join( condorDir, shift ) ) )

deepCSV_SF = config.deepCSV_SF[ args.year ]
deepJet_SF = config.deepJet_SF[ args.year ]
JEC_file = config.JEC_files[ args.year ]

if args.test:
  deepCSV_SF = "btag_sf/reshaping_deepCSV_106XUL17_test.csv"
  deepJet_SF = "btag_sf/reshaping_deepJet_106XUL17_test.csv"

# Start processing
gROOT.ProcessLine( ".x compile_step1.C" )
job_count = 0

samples = { shift: [] for shift in shifts }

# compile list of samples to submit for each shift
for shift in shifts:
  for group in args.groups:
    if group not in config.samples[ args.year ].keys():
      print( "[WARN] {} not a valid group for 20{}, skipping".format( group, args.year ) )
      continue
    for sample in config.samples[ args.year ][ group ]:
      samples[ shift ].append( sample )
      
# loop through samples and submit job
job_shift = []
job_submit = []
for shift in samples:
  print( "[INFO] Preparing {} samples for shift: {}".format( len( samples[ shift ] ), shift ) )
  if args.site == "BRUX":
    if not os.path.exists( outputDir[ shift ] ): os.system( "mkdir -p {}".format( outputDir[ shift ] ) ) 
  for sample in tqdm( sorted( samples[ shift ] ) ):
    if args.year == "18" and sample == "SingleElectron": sample = "EGamma"
    if args.verbose: print( "  + Sample: {}".format( sample ) )
    outList = []
    if "TTToSemiLeptonic" in sample and "up" not in sample.lower() and "down" not in sample.lower(): 
      for HT_key in [ "HT0Njet0", "HT500Njet9" ]:  
        for fs_key in [ "ttbb", "tt2b", "tt1b", "ttcc", "ttjj" ]:
          outList.append( "{}_{}".format( HT_key, fs_key ) )
    elif "TTTo" in sample: 
      outList = [ "ttbb", "tt2b", "tt1b", "ttcc", "ttjj" ]
    else:
      outList = [ "none" ]

    isData = True if ( "Single" in sample or "EGamma" in sample or "JetHT" in sample ) else False
    
    # don't run JEC/JER shifts on data or on hdamp/ue systematic shift samples
    if shift != "nominal" and ( isData or "hdamp" in sample or "TuneCP5up" in sample or "TuneCP5down" in sample ): continue
    
    # loop through final states for a given sample --> mostly for flavor matched ttbar final states
    for outlabel in outList:
      fs_count = 0
      step1_sample = sample if outlabel == "none" else "{}_{}".format( sample, outlabel )

      if args.site == "LPC":
        os.system( "eos root://cmseos.fnal.gov mkdir -p {}".format( os.path.join( outputDir[ shift ], step1_sample ) ) )
      elif args.site == "BRUX":
        if not os.path.exists( os.path.join( outputDir[ shift ], step1_sample ) ): os.system( "mkdir -p {}".format( os.path.join( outputDir[ shift ], step1_sample ) ) )

      if args.location == "LPC":    
        if args.site == "LPC":
          runList = EOSlistdir( "{}/{}/singleLep20{}UL/".format( inputDir, sample, args.year ) )
        elif args.site == "BRUX":
          runList = [ item.strip().split("/")[-1] for item in os.popen( "xrdfs root://cmseos.fnal.gov/ ls {}/{}/singleLep20{}UL/".format( inputDir, sample, args.year ) ).readlines() ]
      elif args.location == "BRUX":
        runPath = "{}/{}/singleLep20{}UL/".format( inputDir, sample, args.year ) 
        if args.site == "LPC":
          status, dirList = xrdClient.dirlist( runPath )
          runList = [ item.name for item in dirList ]
        elif args.site == "BRUX":
          runList = [ item for item in next( os.walk( runPath ) )[1] ]

      if args.verbose: print( "  + Found {} runs: {}".format( len( runList ), runList ) ) 

      for run in runList:
        if args.location == "LPC":
          if args.site == "LPC":
            numList = EOSlistdir( "{}/{}/singleLep20{}UL/{}/".format( inputDir, sample, args.year, run ) )
          elif args.site == "BRUX":
            numList = [ item.strip().split("/")[-1] for item in os.popen( "xrdfs root://cmseos.fnal.gov/ ls {}/{}/singleLep20{}UL/{}".format( inputDir, sample, args.year, run ) ).readlines() ]
        elif args.location == "BRUX":
          numPath = "{}/{}/singleLep20{}UL/{}".format( inputDir, sample, args.year, run )
          if args.site == "LPC":
            status, dirList = xrdClient.dirlist( numPath )
            numList = [ item.name for item in dirList ]
          elif args.site == "BRUX":
            numList = [ item for item in next( os.walk( numPath ) )[1] if item != "log" ]

        for num in numList:
          filePath = "{}/{}/singleLep20{}UL/{}/{}".format( inputDir, sample, args.year, run, num )
          pathSuffix = filePath.split("/")[-3:]
          pathSuffix = "/".join( pathSuffix )

          if args.location == "LPC":
            if args.site == "LPC":
              rootFiles = EOSlist_root_files( filePath )
            elif args.site == "BRUX":
              fileList = [ item.strip().split("/")[-1] for item in os.popen( "xrdfs root://cmseos.fnal.gov/ ls {}/{}/singleLep20{}UL/{}/{}".format( inputDir, sample, args.year, run, num ) ).readlines() ]
              rootFiles = []
              for fName in fileList:
                if fName.endswith( ".root" ): rootFiles.append( fName )

          elif args.location == "BRUX":
            if args.site == "LPC":
              status, fileList = xrdClient.dirlist( filePath )
              rootFiles = [ item.name for item in fileList if item.name.endswith( ".root" ) ]
            elif args.site == "BRUX":
              rootFiles = [ item for item in next( os.walk( filePath ) )[2] ]
          if not rootFiles: continue #Check if rootfiles is empty list (remove failed jobs)
          baseFilename = "_".join( ( rootFiles[0].split(".")[0] ).split("_")[:-1] )

          for i in range( 0, len(rootFiles), filesPerJob ):
            if fs_count + 1 > float( args.joblimit ) and float( args.joblimit ) > 0: continue
            fs_count += 1

            segments = rootFiles[i].split(".")[0].split("_")                       

            if isData:    # need unique IDs across eras
              idList_ = [ segments[-2][-1] + segments[-1] ]
              for j in range( i + 1, i + filesPerJob ):
                if j >= len(rootFiles): continue
                idParts = ( rootFiles[j].split('.')[0] ).split('_')[-2:]
                idList_.append( idParts[0][-1] + idParts[1] )
            else:
              idList_ = [ segments[-1] ]
              for j in range( i + 1, i + filesPerJob ):
                if j >= len( rootFiles ): continue
                idList_.append( rootFiles[j].split(".")[0].split("_")[-1] )

            idList = " ".join( idList_ ).strip()
            del idList_
            if args.verbose: print( "    - ID list: {}".format( idList ) )
            jobParams = {
              'RUNDIR': os.getcwd(), 
              'SAMPLE': sample, 
              'TAG': sample.split( "_TuneCP5_" )[0],
              'INPATHSUFFIX': pathSuffix, 
              'INPUTDIR': inputDir, 
              'FILENAME': baseFilename, 
              'OUTFILENAME': step1_sample, 
              'OUTPUTDIR': outputDir[ shift ], 
              'LIST': idList, 
              'ID': fs_count, 
              'YEAR': args.year, 
              'SHIFT': shift,
              'DEEPCSV': deepCSV_SF, 
              'DEEPJET': deepJet_SF,
              'JEC': JEC_file,
              'SITE': args.site,
              'LOCATION': args.location
            }
            jdfName = "{}{}/{}_{}.job".format( condorDir, shift, jobParams["OUTFILENAME"], jobParams["ID"] )
            jdf = open( jdfName, 'w' )
            jdf.write(
"""use_x509userproxy = true
universe = vanilla
Executable = %(RUNDIR)s/make_step1.sh
should_transfer_files = YES
when_to_transfer_output = ON_EXIT
Transfer_Input_Files = %(RUNDIR)s/compile_step1.C, %(RUNDIR)s/make_step1.C, %(RUNDIR)s/step1.cc, %(RUNDIR)s/step1.h, %(RUNDIR)s/HardcodedConditions.cc, %(RUNDIR)s/HardcodedConditions.h, %(RUNDIR)s/BTagCalibForLJMet.cpp, %(RUNDIR)s/BTagCalibForLJMet.h, %(RUNDIR)s/%(DEEPCSV)s, %(RUNDIR)s/%(DEEPJET)s, %(RUNDIR)s/%(JEC)s
request_memory = 6144
Output = %(OUTFILENAME)s_%(ID)s.out
Error = %(OUTFILENAME)s_%(ID)s.err
Log = %(OUTFILENAME)s_%(ID)s.log
JobBatchName = step1_%(SHIFT)sUL%(YEAR)s_%(TAG)s 
Notification = Never
Arguments = "%(FILENAME)s %(OUTFILENAME)s %(INPUTDIR)s/%(SAMPLE)s/%(INPATHSUFFIX)s %(OUTPUTDIR)s/%(OUTFILENAME)s '%(LIST)s' %(ID)s %(YEAR)s %(SHIFT)s %(SITE)s %(LOCATION)s"
Queue 1"""%jobParams)
            jdf.close()
            job_shift.append( shift )
            job_submit.append( jdfName.split( "/" )[-1] )
            del jdf
            if args.test: quit()
                                                 
for i in tqdm( range( len( job_submit ) ) ):
  os.chdir( os.path.join( condorDir, job_shift[i] ) )
  submit = subprocess.call( [ "condor_submit", job_submit[i] ], stdout = open( os.devnull, "w" ), stderr = subprocess.STDOUT )
  os.chdir( jobParams["RUNDIR"] )

print( "[DONE] {} jobs submitted in {:.2f} minutes".format( len( job_submit ), round( time.time() - start_time, 2 ) / 60. ) )
