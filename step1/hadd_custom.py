import os
import numpy as np
from argparse import ArgumentParser
import config

parser = ArgumentParser()
parser.add_argument( "-y", "--year", required = True )
args = parser.parse_args()

PATH = "/isilon/hadoop/store/user/dali/FWLJMET106XUL_singleLep20{}UL_RunIISummer20_3t_step1hadds/".format( args.year )

SYSTS = [ str(syst) for syst in config.JES_shifts if config.JES_shifts[ syst ] ]
SHIFTS = [ "up", "down" ]

TT_SAMPLE = "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_HT0Njet0_ttjj_NUM_hadd.root"

#NUMS = [ 11, 12, 13 ] if args.year == "16" else [ 11, 12 ]
NUMS = range( 11, 12 )

for SHIFT in SHIFTS:
  for SYST in SYSTS:
    for NUM in NUMS:
      if NUM % 10 == 0:
        NUM_TO = "10"
      else:
        NUM_TO = str( int( NUM % 10 ) )
      #DIR = "{}{}/".format( PATH, SYST + SHIFT ).replace( "Era", "2016" )
      DIR = "{}{}/".format( PATH, SYST + SHIFT ).replace( "Era", "20" + args.year )
      if TT_SAMPLE.replace( "NUM", str(NUM) ) not in os.listdir( DIR ): continue
      else:
        os.system( "mv {0}{1} {0}{2}".format( DIR, TT_SAMPLE.replace( "NUM", NUM_TO ), TT_SAMPLE ) )
        hadd_command = "hadd -f {0}{1} {0}{2} {0}{3}".format( DIR, TT_SAMPLE.replace( "NUM", NUM_TO ), TT_SAMPLE.replace( "NUM", str(NUM) ), TT_SAMPLE )
        os.system( hadd_command )
        os.system( "rm {0}{1} {0}{2}".format( DIR, TT_SAMPLE, TT_SAMPLE.replace( "NUM", str(NUM) ) ) )
        print( "" )
