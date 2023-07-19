import os
from argparse import ArgumentParser
execfile( "step1/config.py" )

parser = ArgumentParser()
parser.add_argument( "-y", "--year", required = True )
parser.add_argument( "-s", "--step", required = True )
args = parser.parse_args()

pathName = "/isilon/hadoop/store/user/dali/FWLJMET106XUL_singleLep20{}UL_RunIISummer20_3t_{}/".format( args.year, args.step )

subDirectories = [ subDirectory for subDirectory in os.listdir( pathName ) if subDirectory != "nominal" ]

nomFiles = os.listdir( os.path.join( pathName, "nominal" ) )
nFilesExpected = len( os.listdir( os.path.join( pathName, "nominal" ) ) ) - 2

for subDirectory in subDirectories:
  subFiles = os.listdir( os.path.join( pathName, subDirectory ) )
  nFiles = len( subFiles )
  print( "[INFO] {} has {} / {} files".format( subDirectory, nFiles, nFilesExpected ) )
  for fileName in subFiles:
    if fileName not in nomFiles:
      print( "  - {}".format( fileName ) )
  for fileName in nomFiles:
    if fileName not in subFiles:
      if "EGAMMA" in fileName.upper() or "SINGLEMUON" in fileName.upper() or "SINGLEELECTRON" in fileName.upper(): continue
      print( "  + {}".format( fileName ) )
