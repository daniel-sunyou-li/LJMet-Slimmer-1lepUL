import os, sys
sys.path.append( "../" ) 
sys.path.append( "../../" )
from argparse import ArgumentParser
import numpy as np
import pickle
import pandas
from XRootD import client
import config
import tqdm

execfile( "../../EOSSafeUtils.py" )

parser = ArgumentParser()
parser.add_argument( "-y", "--year", help = "16APV,16,17,18" )
parser.add_argument( "-g", "--group" )
parser.add_argument( "-l", "--lepton", default = "e", help = "e,m" )
parser.add_argument( "-p", "--percent", default = "100", help = "Percent of events to consider" )
parser.add_argument( "--single", action = "store_true" )
parser.add_argument( "-loc", "--location", default = "BRUX" )
parser.add_argument( "-s", "--site", default = "BRUX", help = "Site running: BRUX, LPC" )
parser.add_argument( "--verbose", action = "store_true" )
args = parser.parse_args()
                    
import ROOT

def calculate_efficiency_err( N1, N2 ):
  k = min( N1, N2 )
  n = max( N1, N2 )
  return np.sqrt( ( ( k + 1 ) * ( k + 2 ) )/( ( n + 2 ) * ( n + 3 ) ) - ( ( k + 1 )**2 / ( n + 2 )**2 ) )

def print_efficiency( efficiency, efficiency_err, ht_bins, pt_bins, eta_bins ):
  for i in range( len( ht_bins ) ):
    header = "{:<15} |".format( "HT {}".format( ht_bins[i] ) )
    split = "_"*17
    for j in range( len( pt_bins ) + 1 ):
      if j == 0:
        header += "{:>7.1f}-{:<7.1f} |".format( 0, pt_bins[j] )
      elif j == len( pt_bins ):
        header += "{:>7.1f}-Inf".format( pt_bins[j-1] )
      else:
        header += "{:>7.1f}-{:<7.1f} |".format( pt_bins[j-1], pt_bins[j] )
      split += "_"*17
    print( header )
    print( split )
    for k in range( len( eta_bins ) + 1 ):
      if k == 0:
        row = "{:>7.3f}-{:<7.3f} |".format( 0, eta_bins[k] )
      elif k == len( eta_bins ):
        row = "{:>7.3f}-{:<7} |".format( eta_bins[k-1], "INF" )
      else:
        row = "{:>7.3f}-{:<7.3f} |".format( eta_bins[k-1], eta_bins[k] )
      for j in range( len( pt_bins ) + 1 ):
        row += " {:<4.3f} pm {:<4.3f} |".format( efficiency[i][j][k], efficiency_err[i][j][k] ) 
      print( row )
    print( split )
    print( "" )
      

# prepare the yield arrays
yields = {
  "HLT": np.zeros( ( len( config.triggerX_bins[ "HT" ] ) + 1, len( config.triggerX_bins[ "PT" ] ) + 1, len( config.triggerX_bins[ "ETA" ] ) + 1 ) ),
  "NOMINAL": np.zeros( ( len( config.triggerX_bins[ "HT" ] ) + 1, len( config.triggerX_bins[ "PT" ] ) + 1, len( config.triggerX_bins[ "ETA" ] ) + 1 ) )
}

# compile the pre-selection
filter_string = ""
# compile pre-selection filter
print( "[INFO] Applying pre-selection cuts:" )
for variable in config.selection:
  for i in range( len( config.selection[ variable ][ "CONDITION" ] ) ):
    print( "   + {} {} {}".format( variable, config.selection[ variable ][ "CONDITION" ][i], config.selection[ variable ][ "VALUE" ][i] ) )
    filter_string += "( {} {} {} ) && ".format( variable, config.selection[ variable ][ "CONDITION" ][i], config.selection[ variable ][ "VALUE" ][i] )
if args.lepton.upper() in "ELECTRON":
  filter_string += "( isElectron == 1 )"
else:
  filter_string += "( isMuon == 1 )"

total_nominal = 0
total_hlt = 0

if args.site == "LPC":         
  if args.location == "LPC":
    samples_done = EOSlistdir( os.path.join( config.haddDir[ args.year ][ "LPC" ], "nominal" ) )
  elif args.location == "BRUX":
    xrdClient = client.FileSystem( "root://brux30.hep.brown.edu:1094/" )
    status, dirList = xrdClient.dirlist( os.path.join( config.haddDir[ args.year ][ "BRUX" ], "nominal" ) )
    samples_done = [ item.name for item in dirList ] 
elif args.site == "BRUX":
  if args.location == "LPC":
    samples_done = EOSlistdir( os.path.join( config.haddDir[ args.year ][ "LPC" ], "nominal" ) )
  elif args.location == "BRUX":
    samples_done = [ fName for fName in os.listdir( os.path.join( config.haddDir[ args.year ][ "BRUX" ], "nominal" ) ) ]

samples = []

print( "[START] Adding the following samples:" )
for sample_i in config.samples[ args.year ][ args.group ]:
  for sample_j in samples_done:
    if sample_i in sample_j:
      print( "  + {}".format( sample_j ) )
      samples.append( sample_j )

for sample in samples:
  if args.group == "DATA" and args.lepton.upper() not in sample.upper(): continue
  if args.site == "LPC":
    if args.location == "BRUX":
      samplePath = "root://brux30.hep.brown.edu:1094/" + config.haddDir[ args.year ][ "BRUX" ] + "/nominal/" + sample 
    elif args.locataion == "LPC":
      samplePath = os.path.join( config.haddDir[ args.year ][ "LPC" ], "nominal/", sample )
  elif args.site == "BRUX":
    if args.location == "BRUX":
      samplePath = config.haddDir[ args.year ][ "BRUX" ] + "/nominal/" + sample 
    elif args.location == "LPC":
      samplePath = os.path.join( config.haddDir[ args.year ][ "LPC" ], "nominal/", sample )
  # load the sample
  if args.site == "LPC":
    rDF = ROOT.RDataFrame( "ljmet", samplePath )
    total_events = rDF.Count().GetValue()
    print( "[INFO] {} has {} total events:".format( sample, total_events ) )
    rDF_nominal = rDF.Filter( filter_string )
    nominal_events = rDF_nominal.Count().GetValue()
    if args.single:
      rDF_hlt = rDF_nominal.Filter( "( MCLepPastTrigger == 1 ) && ( DataLepPastTrigger == 1 )" )
    else:
      rDF_hlt = rDF_nominal.Filter( "( MCPastTriggerX == 1 ) && ( DataPastTriggerX == 1 )" )
    nominal_events = rDF_nominal.Count().GetValue()
    hlt_events = rDF_hlt.Count().GetValue()
    total_nominal += nominal_events
    total_hlt += hlt_events
    print( "  + {} passed pre-selection".format( nominal_events ) )
    if args.single:
      print( "  + {} passed pre-selection + trigger = {:.3f}".format( hlt_events, float( hlt_events ) / float( nominal_events )  ) )
    else:
      print( "  + {} passed pre-selection + triggerX = {:.3f}".format( hlt_events, float( hlt_events ) / float( nominal_events ) ) )
    nom_df = pandas.DataFrame( rDF_nominal.AsNumpy( columns = [ "AK4HT", "leptonPt_MultiLepCalc", "leptonEta_MultiLepCalc" ] ) )
    hlt_df = pandas.DataFrame( rDF_hlt.AsNumpy( columns = [ "AK4HT", "leptonPt_MultiLepCalc", "leptonEta_MultiLepCalc" ] ) )
    
  elif args.site == "BRUX":
    events_nom = { "AK4HT": [], "leptonPt_MultiLepCalc": [], "leptonEta_MultiLepCalc": [] }
    events_hlt = { "AK4HT": [], "leptonPt_MultiLepCalc": [], "leptonEta_MultiLepCalc": [] }
    rFile = ROOT.TFile( samplePath )
    rTree = rFile.Get( "ljmet" )
    total_events = rTree.GetEntries()
    nominal_events = 0
    hlt_events = 0
    nEntries = int( rTree.GetEntries() * float( args.percent ) / 100. )
    for i in tqdm.tqdm( range( nEntries ) ):
      rTree.GetEntry(i)
      if args.lepton.lower() in [ "e", "el" ]:
        if getattr( rTree, "isElectron" ) != 1: continue
      elif args.lepton.lower() in [ "m", "mu" ]:
        if getattr( rTree, "isMuon" ) != 1: continue
      for vName in config.selection:
        if config.selection[ vName ][ "CONDITION" ] == ">":
          if abs( getattr( rTree, str( vName ) ) ) <= config.selection[ vName ][ "VALUE" ]: continue
        if config.selection[ vName ][ "CONDITION" ] == ">=":
          if abs( getattr( rTree, str( vName ) ) ) < config.selection[ vName ][ "VALUE" ]: continue
        if config.selection[ vName ][ "CONDITION" ] == "<":
          if abs( getattr( rTree, str( vName ) ) ) >= config.selection[ vName ][ "VALUE" ]: continue
        if config.selection[ vName ][ "CONDITION" ] == "<=":
          if abs( getattr( rTree, str( vName ) ) ) > config.selection[ vName ][ "VALUE" ]: continue
        if config.selection[ vName ][ "CONDITION" ] == "==":
          if abs( getattr( rTree, str( vName ) ) ) != config.selection[ vName ][ "VALUE" ]: continue
      events_nom[ "AK4HT" ].append( getattr( rTree, "AK4HT" ) )
      events_nom[ "leptonPt_MultiLepCalc" ].append(  getattr( rTree, "leptonPt_MultiLepCalc" ) )
      events_nom[ "leptonEta_MultiLepCalc" ].append( getattr( rTree, "leptonEta_MultiLepCalc" ) )
      nominal_events += 1
      passHLT = False
      if args.single:
        if getattr( rTree, "MCLepPastTrigger" ) == 1 and getattr( rTree, "DataLepPastTrigger" ) == 1: passHLT = True
      else:
        if getattr( rTree, "MCPastTriggerX" ) == 1 and getattr( rTree, "DataPastTriggerX" ) == 1: passHLT = True
      if passHLT:
        events_hlt[ "AK4HT" ].append( getattr( rTree, "AK4HT" ) )
        events_hlt[ "leptonPt_MultiLepCalc" ].append( getattr( rTree, "leptonPt_MultiLepCalc" ) )
        events_hlt[ "leptonEta_MultiLepCalc" ].append( getattr( rTree, "leptonEta_MultiLepCalc" ) )
        hlt_events += 1
    total_nominal += nominal_events
    total_hlt += hlt_events
    print( "[INFO] {} has {} total events".format( sample, total_events ) )
    print( "   + {} passed pre-selection".format( nominal_events ) )
    print( "   + {} passed pre-selection + trigger".format( hlt_events ) ) 
    nom_df  = pandas.DataFrame.from_dict( events_nom )
    hlt_df = pandas.DataFrame.from_dict( events_hlt )
    
  for i in range( len( config.triggerX_bins[ "HT" ] ) + 1 ):
    if i == 0:
      ht_pass_nom = ( nom_df[ "AK4HT" ] < config.triggerX_bins[ "HT" ][i] )
      ht_pass_hlt = ( hlt_df[ "AK4HT" ] < config.triggerX_bins[ "HT" ][i] )
    elif i == len( config.triggerX_bins[ "HT" ] ):
      ht_pass_nom = ( nom_df[ "AK4HT" ] >= config.triggerX_bins[ "HT" ][i-1] )
      ht_pass_hlt = ( hlt_df[ "AK4HT" ] >= config.triggerX_bins[ "HT" ][i-1] )
    else:
      ht_pass_nom = ( nom_df[ "AK4HT" ] >= config.triggerX_bins[ "HT" ][i-1] ) & ( nom_df[ "AK4HT" ] < config.triggerX_bins[ "HT" ][i] )
      ht_pass_hlt = ( hlt_df[ "AK4HT" ] >= config.triggerX_bins[ "HT" ][i-1] ) & ( hlt_df[ "AK4HT" ] < config.triggerX_bins[ "HT" ][i] )
    for j in range( len( config.triggerX_bins[ "PT" ] ) + 1 ):
      if j == 0: 
        pt_pass_nom = ( nom_df[ "leptonPt_MultiLepCalc" ] < config.triggerX_bins[ "PT" ][j] )
        pt_pass_hlt = ( hlt_df[ "leptonPt_MultiLepCalc" ] < config.triggerX_bins[ "PT" ][j] )
      elif j == len( config.triggerX_bins[ "PT" ] ):
        pt_pass_nom = ( nom_df[ "leptonPt_MultiLepCalc" ] >= config.triggerX_bins[ "PT" ][j-1] )
        pt_pass_hlt = ( hlt_df[ "leptonPt_MultiLepCalc" ] >= config.triggerX_bins[ "PT" ][j-1] )
      else:
        pt_pass_nom = ( nom_df[ "leptonPt_MultiLepCalc" ] >= config.triggerX_bins[ "PT" ][j-1] ) & ( nom_df[ "leptonPt_MultiLepCalc" ] < config.triggerX_bins[ "PT" ][j] )
        pt_pass_hlt = ( hlt_df[ "leptonPt_MultiLepCalc" ] >= config.triggerX_bins[ "PT" ][j-1] ) & ( hlt_df[ "leptonPt_MultiLepCalc" ] < config.triggerX_bins[ "PT" ][j] )
      for k in range( len( config.triggerX_bins[ "ETA" ] ) + 1 ):
        if k == 0:
          eta_pass_nom = ( nom_df[ "leptonEta_MultiLepCalc" ].abs() < config.triggerX_bins[ "ETA" ][k] )
          eta_pass_hlt = ( hlt_df[ "leptonEta_MultiLepCalc" ].abs() < config.triggerX_bins[ "ETA" ][k] )
        elif k == len( config.triggerX_bins[ "ETA" ] ):
          eta_pass_nom = ( nom_df[ "leptonEta_MultiLepCalc" ].abs() >= config.triggerX_bins[ "ETA" ][k-1] )
          eta_pass_hlt = ( hlt_df[ "leptonEta_MultiLepCalc" ].abs() >= config.triggerX_bins[ "ETA" ][k-1] )
        else:
          eta_pass_nom = ( nom_df[ "leptonEta_MultiLepCalc" ].abs() >= config.triggerX_bins[ "ETA" ][k-1] ) & ( nom_df[ "leptonEta_MultiLepCalc" ].abs() < config.triggerX_bins[ "ETA" ][k] )
          eta_pass_hlt = ( hlt_df[ "leptonEta_MultiLepCalc" ].abs() >= config.triggerX_bins[ "ETA" ][k-1] ) & ( hlt_df[ "leptonEta_MultiLepCalc" ].abs() < config.triggerX_bins[ "ETA" ][k] )
     
        if args.verbose:
          print( ">> Bin (i,j,k) = ({},{},{}):".format( i, j, k ) )
          try:
            print( "   + HLT / NOM = {} / {} ({:.3f})".format( len( hlt_df[ ( ht_pass_hlt ) & ( pt_pass_hlt ) & ( eta_pass_hlt ) ] ), len( nom_df[ ( ht_pass_nom ) & ( pt_pass_nom ) & ( eta_pass_nom ) ] ), float( len( hlt_df[ ( ht_pass_hlt ) & ( pt_pass_hlt ) & ( eta_pass_hlt ) ] ) ) / len( nom_df[ ( ht_pass_nom ) & ( pt_pass_nom ) & ( eta_pass_nom ) ] ) ) ) 
          except:
            print( "   + HLT / NOM = 0 / 0" )

        yields[ "NOMINAL" ][i][j][k] += len( nom_df[ ( ht_pass_nom ) & ( pt_pass_nom ) & ( eta_pass_nom ) ] )
        yields[ "HLT" ][i][j][k] += len( hlt_df[ ( ht_pass_hlt ) & ( pt_pass_hlt ) & ( eta_pass_hlt ) ] )
     
# compute efficiencies for pt and eta bins
efficiency = np.zeros( ( len( config.triggerX_bins[ "HT" ] ) + 1, len( config.triggerX_bins[ "PT" ] ) + 1, len( config.triggerX_bins[ "ETA" ] ) + 1 ) )
efficiency_err = np.zeros( ( len( config.triggerX_bins[ "HT" ] ) + 1, len( config.triggerX_bins[ "PT" ] ) + 1, len( config.triggerX_bins[ "ETA" ] ) + 1 ) )
print( "[START] Calculating efficiency and efficiency error" )
for i in range( efficiency_err.shape[0] ):
  for j in range( efficiency_err.shape[1] ):
    for k in range( efficiency_err.shape[2] ):
      efficiency_err[i][j][k] = calculate_efficiency_err( yields[ "HLT" ][i][j][k], yields[ "NOMINAL" ][i][j][k] )
      if yields[ "NOMINAL" ][i][j][k] == 0:
        efficiency[i][j][k] = 0
      else:
        efficiency[i][j][k] = yields["HLT"][i][j][k] / yields["NOMINAL"][i][j][k]
print( "[DONE]" )
print_efficiency( efficiency, efficiency_err, config.triggerX_bins[ "HT" ], config.triggerX_bins[ "PT" ], config.triggerX_bins[ "ETA" ] )
# read out the efficiencies in json format
pickle_dict = {
  "NOMINAL YIELD": yields[ "NOMINAL" ],
  "HLT YIELD": yields[ "HLT" ],
  "EFFICIENCY": efficiency,
  "EFFICIENCY ERR": efficiency_err,
  "HT BINS": config.triggerX_bins[ "HT" ],
  "PT BINS": config.triggerX_bins[ "PT" ],
  "ETA BINS": config.triggerX_bins[ "ETA" ]
}
print( "[INFO] Total efficiency: {}/{} = {:.3f} pm {:.3f}".format( total_hlt, total_nominal, float( total_hlt ) / float( total_nominal ), calculate_efficiency_err( total_hlt, total_nominal ) ) )
print( ">> Dumping efficiency matrix into pickle" )
if not os.path.exists( os.path.join( os.getcwd(), "results/" ) ):
  os.mkdir( os.path.join( os.getcwd(), "results/" ) )

if args.single:
  pickle.dump( pickle_dict, open( "results/efficiency_{}_{}_UL{}.pkl".format( args.group, args.lepton, args.year ), "w" ) )
else:
  pickle.dump( pickle_dict, open( "results/efficiencyX_{}_{}_UL{}.pkl".format( args.group, args.lepton, args.year ), "w" ) )
