import os, sys
from argparse import ArgumentParser
execfile( "step1/config.py" )

# this script is to be used while on BRUX and transferring step1hadds from the LPC eos area
parser = ArgumentParser()
parser.add_argument( "-y", "--year", required = True )
parser.add_argument( "-t", "--tag", default = "3t" )
parser.add_argument( "-g", "--groups", nargs = "+", required = True )
parser.add_argument( "-s", "--step", required = True, help = "1hadds,2,3,ABCDnn" )
parser.add_argument( "-o", "--outpath", required = True, help = "/isilon/hadoop/store/<outpath>" )
parser.add_argument( "--shifts", action = "store_true" )
args = parser.parse_args()

out_path = os.path.join( "/isilon/hadoop/store/", args.outpath )
if args.step == "1hadds":
  out_folder = sampleDir[ args.year ] + "_{}_step1hadds".format( args.tag )
elif args.step == "2":
  out_folder = sampleDir[ args.year ] + "_{}_step2".format( args.tag )
elif args.step == "3":
  out_folder = sampleDir[ args.year ] + "_{}_step3".format( args.tag )
elif args.step == "ABCDnn":
  out_folder = sampleDir[ args.year ] + "_{}_step3_ABCDnn".format( args.tag )
else:
  quit( "[ERR] Invalid 'step' argument used, try: '1hadds', '2'. Quitting..." )
  
if not os.path.exists( out_path ):
  quit( "[ERR] {} does not exist, quitting...".format( out_path ) )
out_dir = out_path + out_folder

def transfer_samples():
  if not os.path.exists( out_dir + "/nominal/" ):
    os.system( "mkdir -vp {}/nominal/".format( out_dir ) )
  if args.shifts:
    for syst in [ "JEC", "JER" ]:
      for shift in [ "up", "down" ]:
        if not os.path.exists( out_dir + "/{}{}/".format( syst, shift ) ):
          os.system( "mkdir -vp {}/{}{}/".format( out_dir, syst, shift ) )
  done_samples = { "nominal": os.listdir( out_dir + "/nominal/" ) }
  if args.shifts:
    for syst in [ "JEC", "JER" ]:
      for shift in [ "up", "down" ]:
        done_samples[ syst + shift ] = os.listdir( out_dir + "/{}{}/".format( syst, shift ) )
  
  transfer_samples = []
  for group in args.groups:
    for sample in samples[ args.year ][ group ]:
      if "TTTT" in sample:
        for n in [ "", "_1", "_2", "_3" ]:
          transfer_samples.append( "{}{}_hadd.root".format( sample, n ) )
      if "TTTo" in sample:
        if "SemiLeptonic" in sample:
          for HT in [ "HT0Njet0", "HT500Njet9" ]:
            for fs in [ "ttjj", "ttcc", "ttbb", "tt1b", "tt2b" ]:
              if fs == "ttjj":
                for n in [ "", "_1", "_2", "_3", "_4", "_5", "_6", "_7", "_8", "_9", "_10", "_11", "_12" ]:
                  transfer_samples.append( "{}_{}_{}{}_hadd.root".format( sample, HT, fs, n ) )
              else:
                transfer_samples.append( "{}_{}_{}_hadd.root".format( sample, HT, fs ) )
        else:
          for fs in [ "ttjj", "ttcc", "ttbb", "tt1b", "tt2b" ]:
            transfer_samples.append( "{}_{}_hadd.root".format( sample, fs ) )
      else:
        transfer_samples.append( "{}_hadd.root".format( sample ) )

  print( "[INFO] Transferring {} samples:".format( len(transfer_samples) ) )
  for i, sample in enumerate( transfer_samples ):
    # nominal transfer
    print( "  {:<4} {}".format( str(i) + ".", sample ) )
    if not args.shifts:
      try:
        if args.step == "ABCDnn":
          os.system( "xrdcp root://cmseos.fnal.gov///store/user/{}/{}/nominal/{} {}/nominal/".format(
            eosUserName, out_folder, sample.replace( "hadd", "ABCDnn_hadd" ), out_dir
          ) )
        else:
          os.system( "xrdcp root://cmseos.fnal.gov///store/user/{}/{}/nominal/{} {}/nominal/".format(
            eosUserName, out_folder, sample, out_dir
          ) )
      except:
        print( "[WARN] nominal/{} does not exist, passing...".format( sample ) )
    if args.shifts:
      for syst in [ "JEC", "JER" ]:
        for shift in [ "up", "down" ]:
          try:
            os.system( "xrdcp root://cmseos.fnal.gov///store/user/{}/{}/{}{}/{} {}/{}{}/".format(
              eosUserName, out_folder, syst, shift, sample, out_dir, syst, shift
            ) )
          except:
            print( "[WARN] {}{}/{} does not exist, passing...".format( syst, shift, sample ) )
         
transfer_samples()
