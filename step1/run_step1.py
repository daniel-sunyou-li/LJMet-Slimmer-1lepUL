import os,shutil,time
import getpass
import config
from argparse import ArgumentParser
from XRootD import client

parser = ArgumentParser()
parser.add_argument( "-y", "--year", required = True, help = "Options:16APV,16,17,18" )
parser.add_argument( "-g", "--groups", nargs = "+" )
parser.add_argument( "-f", "--filesPerJob", default = "30", help = "Default is 30, but recommended 10 for years 16APV,16" )
parser.add_argument( "-l", "--location", default = "LPC", help = "Options: LPC, BRUX" )
parser.add_argument( "--shifts", action = "store_true" )
args = parser.parse_args()

from ROOT import *

xrdClient = client.FileSystem( "root://brux30.hep.brown.edu:1094/" )
execfile( "../EOSSafeUtils.py" )

start_time = time.time()

#IO directories must be full paths
if args.year not in [ "16APV", "16", "17", "18" ]: sys.exit( "[ERR] Invalid year option. Use: 16APV, 16, 17, 18" )
if args.location not in [ "LPC", "BRUX" ]: sys.exit( "[ERR] Invalid location option. Use: BRUX, LPC" )
shifts = [ "nominal" ] if not args.shifts else [ "JECup", "JECdown" ] #, "JERup", "JERdown" ]
filesPerJob = int( args.filesPerJob )
postfix = config.postfix
inputDir = config.ljmetDir[ args.year ][ args.location ]

outputDir = {
  shift: os.path.join( config.step1Dir[ args.year ][ "LPC" ], shift ) for shift in shifts
}

condorDir = "./logs_UL{}_{}/".format( args.year, postfix )
for shift in shifts: os.system( "mkdir -p {}".format( os.path.join( condorDir, shift ) ) )

deepCSV_SF = config.deepCSV_SF[ args.year ]
deepJet_SF = config.deepJet_SF[ args.year ]

# Start processing
gROOT.ProcessLine( ".x compile_step1.C" )
print( "[START] Submitting step1 condor jobs" )
job_count = 0

samples = { shift: [] for shift in shifts }

for shift in shifts:
  for group in args.groups:
    if group not in config.samples[ args.year ].keys():
      print( "[WARN] {} not a valid group for 20{}, skipping".format( group, args.year ) )
      continue
    print( "[INFO] Preparing {} condor jobs for group: {}".format( shift, group ) )
    for sample in config.samples[ args.year ][ group ]:
      print( "   + {}".format( sample ) )
      samples[ shift ].append( sample )
      
# loop through samples and submit job
for shift in samples:
  print( "[START] Submitting step1 jobs for shift: {}".format( shift ) )
  for sample in sorted( samples[ shift ] ):
    if args.year == "18" and sample == "SingleElectron": sample = "EGamma"
    outList = []
    if "TTToSemiLeptonic" in sample and "up" not in sample.lower() and "down" not in sample.lower(): 
      for HT_key in [ "HT0Njet0" ]:  #[ "HT0Njet0", "HT500Njet9" ]:
        for fs_key in [ "ttbb", "tt2b", "tt1b", "ttcc", "ttjj" ]:
          outList.append( "{}_{}".format( HT_key, fs_key ) )
    elif "TTTo" in sample: 
      outList = [ "ttbb", "tt2b", "tt1b", "ttcc", "ttjj" ]
    else:
      outList = [ "none" ]

    isData = True if ( "Single" in sample or "EGamma" in sample or "JetHT" in sample ) else False
    
    # don't run JEC/JER shifts on data or on hdamp/ue systematic shift samples
    if shift != "nominal" and ( isData or "hdamp" in sample or "TuneCP5up" in sample or "TuneCP5down" in sample ): continue
    
    # check for completed jobs and decide to resubmit (or not)
    
    # loop through final states for a given sample --> mostly for flavor matched ttbar final states
    for outlabel in outList:
      fs_count = 0
      step1_sample = sample if outlabel == "none" else "{}_{}".format( sample, outlabel )
      os.system( "eos root://cmseos.fnal.gov mkdir -p {}".format( os.path.join( outputDir[ shift ], step1_sample ) ) )
      if args.location == "LPC":    
        runList = EOSlistdir( "{}/{}/singleLep20{}UL/".format( inputDir, sample, args.year ) )
      elif args.location == "BRUX":
        runPath = "{}/{}/singleLep20{}UL/".format( inputDir, sample, args.year ) 
        status, dirList = xrdClient.dirlist( runPath )
        runList = [ item.name for item in dirList ]

      print( "[INFO] Running {} CRAB directories...".format( len(runList) ) )
    
      for run in runList:
        if args.location == "LPC":
          numList = EOSlistdir( "{}/{}/singleLep20{}UL/{}/".format( inputDir, sample, args.year, run ) )
        elif args.location == "BRUX":
          xrd_command = "{}/{}/singleLep20{}UL/{}".format( inputDir, sample, args.year, run )
          status, dirList = xrdClient.dirlist( xrd_command )
          numList = [ item.name for item in dirList ]
        
        for num in numList:
          numPath = "{}/{}/singleLep20{}UL/{}/{}".format( inputDir, sample, args.year, run, num )
          pathSuffix = numPath.split("/")[-3:]
          pathSuffix = "/".join( pathSuffix )

          if args.location == "LPC":
            rootFiles = EOSlist_root_files( numPath )
          elif args.location == "BRUX":
            xrdPath = "{}/{}/singleLep20{}UL/{}/{}/".format( inputDir, sample, args.year, run, num )
            print( xrdPath )
            status, fileList = xrdClient.dirlist( xrdPath )
            rootFiles = [ item.name for item in fileList if item.name.endswith( ".root" ) ]
          if not rootFiles: continue #Check if rootfiles is empty list (remove failed jobs)
          baseFilename = "_".join( ( rootFiles[0].split(".")[0] ).split("_")[:-1] )
          print( ">> Running path: {}\t Base filename: {}".format( pathSuffix, baseFilename ) )

          for i in range( 0, len(rootFiles), filesPerJob ):
            fs_count += 1

            segments = rootFiles[i].split(".")[0].split("_")                       

            if isData:    # need unique IDs across eras
              idList = "{}{} ".format( segments[-2][-1], segments[-1] )
              for j in range( i + 1, i + filesPerJob ):
                if j >= len(rootFiles): continue
                idParts = ( rootFiles[j].split('.')[0] ).split('_')[-2:]
                idList += "{}{} ".format( idParts[0][-1], idParts[1] )
            else:
              idList = "{} ".format( segments[-1] )
              for j in range( i + 1, i + filesPerJob ):
                if j >= len( rootFiles ): continue
                idList += "{} ".format( rootFiles[j].split(".")[0].split("_")[-1] )

            idList = idList.strip()
            #remove the problematic 2018 fwljmet jobs
            #if args.year == "18" and sample == "ST_t-channel_antitop_4f_InclusiveDecays_TuneCP5_13TeV-powheg-madspin-pythia8":
            #  problematicIDs = ['1048','1177','1217','1412','1413','1414','1415','1416','1417','1418','1419','1429','1441','1664','1883']
            #  for id_ in problematicIDs:
            #    idList = idList.replace( id_, "" ).replace( "  ", " " )
            print( ">> Running IDs: {}".format( idList ) )
            jobParams = {
              'RUNDIR': os.getcwd(), 
              'SAMPLE': sample, 
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
              'DEEPJET':deepJet_SF
            }
            jdfName = "{}{}/{}_{}.job".format( condorDir, shift, jobParams["OUTFILENAME"], jobParams["ID"] )
            print( ">> Storing job information in {}".format( jdfName ) )
            jdf = open( jdfName, 'w' )
            jdf.write(
"""use_x509userproxy = true
universe = vanilla
Executable = %(RUNDIR)s/make_step1.sh
should_transfer_files = YES
when_to_transfer_output = ON_EXIT
Transfer_Input_Files = %(RUNDIR)s/compile_step1.C, %(RUNDIR)s/make_step1.C, %(RUNDIR)s/step1.cc, %(RUNDIR)s/step1.h, %(RUNDIR)s/HardcodedConditions.cc, %(RUNDIR)s/HardcodedConditions.h, %(RUNDIR)s/BTagCalibForLJMet.cpp, %(RUNDIR)s/BTagCalibForLJMet.h, %(RUNDIR)s/%(DEEPCSV)s, %(RUNDIR)s/%(DEEPJET)s
request_memory = 6144
Output = %(OUTFILENAME)s_%(ID)s.out
Error = %(OUTFILENAME)s_%(ID)s.err
Log = %(OUTFILENAME)s_%(ID)s.log
Notification = Never
Arguments = "%(FILENAME)s %(OUTFILENAME)s %(INPUTDIR)s/%(SAMPLE)s/%(INPATHSUFFIX)s %(OUTPUTDIR)s/%(OUTFILENAME)s '%(LIST)s' %(ID)s %(YEAR)s %(SHIFT)s"
Queue 1"""%jobParams)
            jdf.close()
            os.chdir( os.path.join( condorDir, shift ) )
            os.system( "condor_submit {}".format( jdfName.split("/")[-1] ) )
            os.system( "sleep 0.5" )                                
            os.chdir( jobParams["RUNDIR"] )
            job_count += 1
                                                 
print( "[DONE] {} jobs submitted in {:.2f} minutes".format( job_count, round( time.time() - start_time, 2 ) / 60. ) )
