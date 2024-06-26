import sys, os
import numpy as np
import argparse
import array
import config

parser = argparse.ArgumentParser()
parser.add_argument( "-y", "--year", default = "17" )
parser.add_argument( "-loc", "--location", required = True, help = "BRUX,LPC,LOCAL" )
args = parser.parse_args()

from ROOT import TFile, TTree, TH2F

labels = {
  #"TTTX": "TTTX_renorm.root",
  #"TTNOBB": "TTNOBB_renorm.root",
  #"TTBB": "TTBB_renorm.root",
  #"TTNOBBHT500": "TTNOBBHT500_renorm.root",
  #"TTBBHT500": "TTBBHT500_renorm.root",
  #"ST": "ST_renorm.root",
  #"TTH": "TTH_renorm.root",
  #"QCD": "QCD_renorm.root",
  #"TTXY": "TTXY_renorm.root",
  "EWK": "EWK_renorm.root"
}

if not os.path.exists( "renorm/UL{}/".format( args.year ) ): os.system( "mkdir -vp renorm/UL{}/".format( args.year ) )

if args.location == "LPC":
  haddPath = "root://cmsxrootd.fnal.gov/" + config.haddPath[ args.year ][ "LPC" ].split( "uscms" )[-1] + "/nominal/"
elif args.location == "BRUX":
  haddPath = config.haddPath[ args.year ][ "BRUX" ] + "/nominal/"

limits = {
  "NJ": [4,4,8],
  "HT": [50,350,4000]
}

for label in labels:
  if os.path.exists( "renorm/UL{}/{}".format( args.year, "Weights_{}_extended_HT_cuts_sys.root".format( label ) ) ): 
    print( "[INFO] {} weights already exist, skipping...".format( label ) )
    continue
  
  print( "[START] Computing deepJet renormalization weight for: {}".format( label ) )
  if args.location == "LOCAL":
    tfile = TFile.Open( args.file )
  else:
    tfile = TFile.Open( os.path.join( haddPath, labels[ label ] ) )

  fout = TFile( "Weights_{}_extended_HT_cuts_sys.root".format( str( label ) ), "RECREATE" )

  systematics = []
  for shift in [ "up", "dn" ]:
    for systematic in [ "HF", "LF", "jes", "hfstats1", "hfstats2", "lfstats1", "lfstats2", "cferr1", "cferr2" ]:
      systematics.append( systematic + shift )
  h2D = { "origin": {}, "weight": {}, "scale": {} }

  h2D[ "origin" ][ "nominal" ] = TH2F( "h2D_origin", "h2D_origin", limits["NJ"][0], limits["NJ"][1], limits["NJ"][2], limits["HT"][0], limits["HT"][1], limits["HT"][2] )
  h2D[ "origin" ][ "nominal" ].Sumw2()
  h2D[ "weight" ][ "nominal" ] = TH2F( "h2D_weight", "h2D_weight", limits["NJ"][0], limits["NJ"][1], limits["NJ"][2], limits["HT"][0], limits["HT"][1], limits["HT"][2] )
  h2D[ "weight" ][ "nominal" ].Sumw2()

  # the nominal h2d[ "origin" ] gets cloned for the systematics scales
  for systematic in systematics:
    h2D[ "weight" ][ systematic ] = TH2F( "h2D_weight_{}".format( systematic ), "h2D_{}".format( systematic ), limits["NJ"][0], limits["NJ"][1], limits["NJ"][2], limits["HT"][0], limits["HT"][1], limits["HT"][2] )
    h2D[ "weight" ][ systematic ].Sumw2()

  ttree = tfile.Get( "ljmet" )

  ttree.SetBranchStatus( "*", 0 )
  ttree.SetBranchStatus( "NJets_JetSubCalc*", 1 )
  ttree.SetBranchStatus( "AK4HT*", 1 )
  ttree.SetBranchStatus( "btagDeepJetWeight*", 1 )
  ttree.SetBranchStatus( "leptonPt_MultiLepCalc*", 1 )
  ttree.SetBranchStatus( "isElectron*", 1 )
  ttree.SetBranchStatus( "isMuon*", 1 )
  ttree.SetBranchStatus( "corr_met_MultiLepCalc*", 1 )
  ttree.SetBranchStatus( "MCPastTrigger*", 1 )

  nEvents = ttree.GetEntries()
  checkpoints = np.linspace( 0, nEvents, 11 ).round() 
  nPassed = 0

  for i in range( nEvents ):
    ttree.GetEntry(i)
    if i in checkpoints: print( "  >> Finished processing {:.0f}% ({}/{}) events".format( 100.* float( i ) / float ( nEvents ), i, nEvents ) )
    if not ( ( ttree.leptonPt_MultiLepCalc > 20 and ttree.isElectron ) or ( ttree.leptonPt_MultiLepCalc > 20 and ttree.isMuon ) ): continue
    if not ( ttree.MCPastTriggerX ): continue 
    njet = getattr( ttree, "NJets_JetSubCalc" ) 
    HT = getattr( ttree, "AK4HT" )
    if njet > 8: njet = 8

    h2D[ "origin" ][ "nominal" ].Fill( njet, HT ) # this gets cloned by the other systematics
    h2D[ "weight" ][ "nominal" ].Fill( njet, HT, getattr( ttree, "btagDeepJetWeight" ) )

    for systematic in systematics:
      h2D[ "weight" ][ systematic ].Fill( njet, HT, getattr( ttree, "btagDeepJetWeight_{}".format( systematic ) ) )

    nPassed += 1

  h2D[ "scale" ][ "nominal" ] = h2D[ "origin" ][ "nominal" ].Clone()
  h2D[ "scale" ][ "nominal" ].SetTitle( "h2D_scale" )
  h2D[ "scale" ][ "nominal" ].Divide( h2D[ "weight" ][ "nominal" ] )
  fout.WriteTObject( h2D[ "origin" ][ "nominal" ], "h2D_origin" )
  fout.WriteTObject( h2D[ "weight" ][ "nominal" ], "h2D_weight" )
  fout.WriteTObject( h2D[ "scale" ][ "nominal" ], "h2D_scale" )

  for systematic in systematics:
    h2D[ "scale" ][ systematic ] = h2D[ "origin" ][ "nominal" ].Clone()
    h2D[ "scale" ][ systematic ].SetTitle( "h2D_scale_{}".format( systematic ) ) 
    h2D[ "scale" ][ systematic ].Divide( h2D[ "weight" ][ systematic ] )
    fout.WriteTObject( h2D[ "scale" ][ systematic ], "h2D_scale_{}".format( systematic ) )

  fout.Close()
  print( "[DONE] {}/{} events passed".format( nPassed, nEvents ) )
  os.system( "mv {} renorm/UL{}/".format( "Weights_{}_extended_HT_cuts_sys.root".format( label ), args.year ) )
