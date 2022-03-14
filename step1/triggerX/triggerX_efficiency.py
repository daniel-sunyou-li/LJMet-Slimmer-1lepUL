import os, sys
sys.path.append( "../" ) 
sys.path.append( "../../" )
from argparse import ArgumentParser
import numpy as np
import pickle
import pandas
import config

execfile( "../../EOSSafeUtils.py" )

parser = ArgumentParser()
parser.add_argument( "-y", "--year", help = "16APV,16,17,18" )
parser.add_argument( "-g", "--group" )
parser.add_argument( "-l", "--lepton", default = "e", help = "e,m" )
parser.add_argument( "--single", action = "store_true" )
args = parser.parse_args()

import ROOT

def calculate_efficiency_err( N1, N2 ):
  k = min( N1, N2 )
  n = max( N1, N2 )
  return ( ( k + 1 ) * ( k + 2 ) )/( ( n + 2 ) * ( n + 3 ) ) - ( ( k + 1 )**2 / ( n + 2 )**2 )

def print_efficiency( efficiency, efficiency_err, pt_bins, eta_bins ):
  header = "{:<15} |".format( "Eff." )
  split = "_"*17
  for i in range( len( pt_bins ) + 1 ):
    if i == 0:
      header += "{:>7.1f}-{:<7.1f} |".format( 0, pt_bins[i] )
    elif i == len( pt_bins ):
      header += "{:>7.1f}-Inf".format( pt_bins[i-1] )
    else:
      header += "{:>7.1f}-{:<7.1f} |".format( pt_bins[i-1], pt_bins[i] )
    split += "_"*17
  print( header )
  print( split )
  for j in range( len( eta_bins ) + 1 ):
    if j == 0:
      row = "{:>7.3f}-{:<7.3f} |".format( 0, eta_bins[j] )
    elif j == len( eta_bins ):
      row = "{:>7.3f}-{:<7} |".format( eta_bins[j-1], "INF" )
    else:
      row = "{:>7.3f}-{:<7.3f} |".format( eta_bins[j-1], eta_bins[j] )
    for i in range( len( pt_bins ) + 1 ):
      row += " {:<4.3f} pm {:<4.3f} |".format( efficiency[i][j], efficiency_err[i][j] ) 
    print( row )
      

# prepare the yield arrays
yields = {
  "HLT": np.zeros( ( len( config.triggerX_bins[ "PT" ] ) + 1, len( config.triggerX_bins[ "ETA" ] ) + 1 ) ),
  "NOMINAL": np.zeros( ( len( config.triggerX_bins[ "PT" ] ) + 1, len( config.triggerX_bins[ "ETA" ] ) + 1 ) )
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
 
samples_done = EOSlistdir( os.path.join( config.haddDir[ args.year ][ "LPC" ], "nominal" ) )
samples = []

print( "[START] Adding the following samples:" )
for sample_i in config.samples[ args.year ][ args.group ]:
  for sample_j in samples_done:
    if sample_i in sample_j:
      print( "  + {}".format( sample_j ) )
      samples.append( sample_j )

for sample in samples:
  if args.group == "DATA" and args.lepton.upper() not in sample.upper(): continue
  samplePath = os.path.join( config.haddDir[ args.year ][ "LPC" ], "nominal/", sample )
  # load the sample
  rDF = ROOT.RDataFrame( "ljmet", samplePath )
  total_events = rDF.Count().GetValue()
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
  print( "[INFO] {} has {} total events:".format( sample, total_events ) )
  print( "  + {} passed pre-selection".format( nominal_events ) )
  if args.single:
    print( "  + {} passed pre-selection + trigger = {:.3f}".format( hlt_events, float( hlt_events ) / float( nominal_events )  ) )
  else:
    print( "  + {} passed pre-selection + triggerX = {:.3f}".format( hlt_events, float( hlt_events ) / float( nominal_events ) ) )
  nom_df = pandas.DataFrame( rDF_nominal.AsNumpy( columns = [ "leptonPt_MultiLepCalc", "leptonEta_MultiLepCalc" ] ) )
  hlt_df = pandas.DataFrame( rDF_hlt.AsNumpy( columns = [ "leptonPt_MultiLepCalc", "leptonEta_MultiLepCalc" ] ) )

  for i in range( len( config.triggerX_bins[ "PT" ] ) + 1 ):
    if i == 0: 
      pt_pass_nom = ( nom_df[ "leptonPt_MultiLepCalc" ] < config.triggerX_bins[ "PT" ][i] )
      pt_pass_hlt = ( hlt_df[ "leptonPt_MultiLepCalc" ] < config.triggerX_bins[ "PT" ][i] )
    elif i == len( config.triggerX_bins[ "PT" ] ):
      pt_pass_nom = ( nom_df[ "leptonPt_MultiLepCalc" ] >= config.triggerX_bins[ "PT" ][i-1] )
      pt_pass_hlt = ( hlt_df[ "leptonPt_MultiLepCalc" ] >= config.triggerX_bins[ "PT" ][i-1] )
    else:
      pt_pass_nom = ( nom_df[ "leptonPt_MultiLepCalc" ] >= config.triggerX_bins[ "PT" ][i-1] ) & ( nom_df[ "leptonPt_MultiLepCalc" ] < config.triggerX_bins[ "PT" ][i] )
      pt_pass_hlt = ( hlt_df[ "leptonPt_MultiLepCalc" ] >= config.triggerX_bins[ "PT" ][i-1] ) & ( hlt_df[ "leptonPt_MultiLepCalc" ] < config.triggerX_bins[ "PT" ][i] )
    for j in range( len( config.triggerX_bins[ "ETA" ] ) + 1 ):
      if j == 0:
        eta_pass_nom = ( nom_df[ "leptonEta_MultiLepCalc" ].abs() < config.triggerX_bins[ "ETA" ][j] )
        eta_pass_hlt = ( hlt_df[ "leptonEta_MultiLepCalc" ].abs() < config.triggerX_bins[ "ETA" ][j] )
      elif j == len( config.triggerX_bins[ "ETA" ] ):
        eta_pass_nom = ( nom_df[ "leptonEta_MultiLepCalc" ].abs() >= config.triggerX_bins[ "ETA" ][j-1] )
        eta_pass_hlt = ( hlt_df[ "leptonEta_MultiLepCalc" ].abs() >= config.triggerX_bins[ "ETA" ][j-1] )
      else:
        eta_pass_nom = ( nom_df[ "leptonEta_MultiLepCalc" ].abs() >= config.triggerX_bins[ "ETA" ][j-1] ) & ( nom_df[ "leptonEta_MultiLepCalc" ].abs() < config.triggerX_bins[ "ETA" ][j] )
        eta_pass_hlt = ( hlt_df[ "leptonEta_MultiLepCalc" ].abs() >= config.triggerX_bins[ "ETA" ][j-1] ) & ( hlt_df[ "leptonEta_MultiLepCalc" ].abs() < config.triggerX_bins[ "ETA" ][j] )
      
      print( ">> Bin (i,j) = ({},{}):".format( i, j ) )
      try:
        print( "   + HLT / NOM = {} / {} ({:.3f})".format( len( hlt_df[ ( pt_pass_hlt ) & ( eta_pass_hlt ) ] ), len( nom_df[ ( pt_pass_nom ) & ( eta_pass_nom ) ] ), float( len( hlt_df[ ( pt_pass_hlt ) & ( eta_pass_hlt ) ] ) ) / len( nom_df[ ( pt_pass_nom ) & ( eta_pass_nom ) ] ) ) ) 
      except:
        print( "   + HLT / NOM = 0 / 0" )

      yields[ "NOMINAL" ][i][j] += len( nom_df[ ( pt_pass_nom ) & ( eta_pass_nom ) ] )
      yields[ "HLT" ][i][j] += len( hlt_df[ ( pt_pass_hlt ) & ( eta_pass_hlt ) ] )
     
# compute efficiencies for pt and eta bins
efficiency = np.zeros( ( len( config.triggerX_bins[ "PT" ] ) + 1, len( config.triggerX_bins[ "ETA" ] ) + 1 ) )
efficiency_err = np.zeros( ( len( config.triggerX_bins[ "PT" ] ) + 1, len( config.triggerX_bins[ "ETA" ] ) + 1 ) )
print( "[START] Calculating efficiency and efficiency error" )
for i in range( efficiency_err.shape[0] ):
  for j in range( efficiency_err.shape[1] ):
    efficiency_err[i][j] = calculate_efficiency_err( yields[ "HLT" ][i][j], yields[ "NOMINAL" ][i][j] )
    if yields[ "NOMINAL" ][i][j] == 0:
      efficiency[i][j] = 0
    else:
      efficiency[i][j] = yields["HLT"][i][j] / yields["NOMINAL"][i][j]
print( "[DONE]" )
print_efficiency( efficiency, efficiency_err, config.triggerX_bins[ "PT" ], config.triggerX_bins[ "ETA" ] )
# read out the efficiencies in json format
pickle_dict = {
  "NOMINAL YIELD": yields[ "NOMINAL" ],
  "HLT YIELD": yields[ "HLT" ],
  "EFFICIENCY": efficiency,
  "EFFICIENCY ERR": efficiency_err,
  "PT BINS": config.triggerX_bins[ "PT" ],
  "ETA BINS": config.triggerX_bins[ "ETA" ]
}
print( "[INFO] Total efficiency: {}/{} = {:.3f}".format( total_hlt, total_nominal, float( total_hlt ) / float( total_nominal ) ) )
print( ">> Dumping efficiency matrix into pickle" )
if not os.path.exists( os.path.join( os.getcwd(), "results/" ) ):
  os.mkdir( os.path.join( os.getcwd(), "results/" ) )

if args.single:
  pickle.dump( pickle_dict, open( "results/efficiency_{}_{}_UL{}.pkl".format( args.group, args.lepton, args.year ), "w" ) )
else:
  pickle.dump( pickle_dict, open( "results/efficiencyX_{}_{}_UL{}.pkl".format( args.group, args.lepton, args.year ), "w" ) )
