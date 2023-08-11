import os
from argparse import ArgumentParser
import config

parser = ArgumentParser()
parser.add_argument( "-y", "--year", required = True )
parser.add_argument( "-t", "--total", default = 10 )
parser.add_argument( "-s", "--step", default = "step1hadds" )
parser.add_argument( "--shifts", action = "store_true" )
args = parser.parse_args()

pathName = "/isilon/hadoop/store/user/dali/FWLJMET106XUL_singleLep20{}UL_RunIISummer20_{}_{}/".format( args.year, config.postfix, args.step )


systs = [ str(syst) for syst in config.JES_shifts if config.JES_shifts[ syst ] ] if args.shifts else [ "nominal" ]
shifts = [ "up", "down" ] if args.shifts else [ "" ]

sampleName = "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_NUM_hadd.root"
#sampleName = "TTTT_TuneCP5_13TeV-amcatnlo-pythia8_NUM_hadd.root"

def hadd_sample( directory, subDirectory, sampleName, numHadd ):
  step1Files = [ name_ for name_ in os.listdir( os.path.join( directory, subDirectory ) ) if sampleName.split( "NUM" )[0] in name_ ]
  sizeGroup = 1 + len( step1Files ) / numHadd
  print( "[INFO] Hadd'ing {} {}/{} files into {} groups of {}".format( len( step1Files ), subDirectory, sampleName, numHadd, sizeGroup ) )
  remove = []
  for i in range( 1, numHadd + 1 ):
    j = i + numHadd
    haddCommand = [ "hadd -a" ]
    if not os.path.exists( os.path.join( directory, subDirectory, sampleName.replace( "NUM", str(j) ) ) ): continue
    haddCommand.append( os.path.join( directory, subDirectory, sampleName.replace( "NUM", str(i) ) ) )
    haddCommand.append( os.path.join( directory, subDirectory, sampleName.replace( "NUM", str(j) ) ) ) 
    remove.append( os.path.join( directory, subDirectory, sampleName.replace( "NUM", str(j) ) ) )
    os.system( " ".join( haddCommand ) )
  if remove: os.system( "rm {}".format( " ".join( remove ) ) )
    
count = 1
for shift_ in shifts:
  for syst_ in systs:
    syst_ = syst_.replace( "Era", "20" + args.year ).replace( "APV", "" )
    hadd_sample( pathName, syst_ + shift_, sampleName, int( args.total ) )
    print( "[DONE] {} out of {}".format( count, len(shifts) * len(systs) ) )
    count += 1
