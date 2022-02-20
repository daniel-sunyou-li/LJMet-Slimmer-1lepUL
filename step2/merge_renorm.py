import sys, os
from argparse import ArgumentParser
import math 

parser = ArgumentParser()
parser.add_argument( "-y", "--year", default = "17", help = "Options: 16,17,18" )
parser.add_argument( "files", nargs = "+", default = [], help = "Files to combine" )
args = parser.parse_args()

sys.path.append('/anaconda2/envs/fireworks/lib')
import ROOT
from ROOT import TFile, TCanvas, TH1F 
from ROOT import gStyle

foutName = "HT_njets_SF_3t_UL{}_sys.root".format( args.year )
fout = TFile( foutName, "RECREATE" )

TFiles = {}
print( ">> Combining renormalization files: " )

for file in args.files:
  if "weights" in file.lower():
    print( "  - {}".format( file ) )
    TFiles[ file.split("_")[1] ] = TFile( file )

sys_postfix = ["", "_HFup", "_HFdn", "_LFup", "_LFdn", "_jesup", "_jesdn", "_hfstats1up", "_hfstats1dn", "_hfstats2up", "_hfstats2dn", "_cferr1up", 
        "_cferr1dn", "_cferr2up", "_cferr2dn", "_lfstats1up", "_lfstats1dn", "_lfstats2up", "_lfstats2dn"]

systematics = [ "" ]
for shift in [ "up", "dn" ]:
  for systematic in [ "_HF", "_LF", "_jes", "_hfstats1", "_hfstats2", "_cferr1", "_cferr2", "_lfstats1", "_lfstats2" ]:
    systematics.append( systematic + shift )

hscale = { key: {} for key in TFiles } 

for key in hscale:
  for systematic in systematics:
    hscale[ key ][ systematic ] = TFiles[ key ].Get( "h2D_scale{}".format( systematic ) ).Clone()
    print( ">> Adding hscale_{}{}...".format( key, systematic ) )
    fout.WriteTObject( hscale[ key ][ systematic ], "hscale_{}{}".format( key, systematic ) )

fout.Close()
os.system( "mv {} renorm/".format( foutName ) )
