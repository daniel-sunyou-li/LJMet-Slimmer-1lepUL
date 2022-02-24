import os, sys
from argparse import ArgumentParser
import numpy as np
import json
import ..config

parser = ArgumentParser()
parser.add_argument( "-y", "--year", help = "16APV,16,17,18" )
parser.add_argument( "-g", "--group" )
parser.add_argument( "-l", "--lepton", default = "e", help = "e,m" )
args = parser.parse_args()

import ROOT

def calculate_efficiency_err( N1, N2 ):
  k = min( N1, N2 )
  n = max( N1, N2 )
  return ( ( k + 1 )( k + 2 ) )/( ( n + 2 )( n + 3 ) ) - ( ( k + 1 )**2 / ( n + 2 )**2 )
  
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
    if filter_string == "":
      filter_string += "( {} {} {} ) && ".format( variable, config.selection[ variable ][ "CONDITION" ][i], config.selection[ variable ][ "VALUE" ][i] )
if args.lepton.upper() in "ELECTRON":
  filter_string += "( isElectron == 1 )"
else:
  filter_string += "( isMuon == 1 )"
      
for sample in config.samples[ args.year ][ args.group ]:
  if args.group == "DATA" and args.lepton.upper() not in sample.upper(): continue
  samplePath = os.path.join( config.haddDir[ args.year ][ "LPC" ], "nominal/", sample + "_hadd.root" )
  # load the sample
  rDF = ROOT.RDataFrame( "ljmet", samplePath )
  total_events = rDF.Count().GetValue()
  filter_string = ""
  rDF_nominal = rDF.Filter( filter_string )
  rDF_hlt = rDF.Filter( filter_string + " && ( ( MCPastTriggerX == 1 ) || ( DataPastTriggerX == 1 ) )" )
  nominal_events = rDF_nominal.Count().GetValue()
  hlt_events = rDF_hlt.Count().GetValue()
  print( "[INFO] {} has {} total events:".format( sample, total_events ) )
  print( "  + {} passed pre-selection".format( nominal_events ) )
  print( "  + {} passed pre-selection + triggerX".format( hlt_events ) )
  nom_df = pandas.DataFrame( rDF_nominal.AsNumpy( columns = [ "leptonPt_MultiLepCalc", "leptonEta_MultiLepCalc" ] ) )
  hlt_df = pandas.DataFrame( rDF_nominal.AsNumpy( columns = [ "leptonPt_MultiLepCalc", "leptonEta_MultiLepCalc" ] ) )

  for i in range( len( config.triggerX_bins[ "PT" ] ) + 1 ):
    if i == 0: 
      pt_pass_nom = nom_df[ "leptonPt_MultiLepCalc" ] < config.triggerX_bins[ "PT" ][i] 
      pt_pass_hlt = hlt_df[ "leptonPt_MultiLepCalc" ] < config.triggerX_bins[ "PT" ][i] 
    elif i == len( config.triggerX_bins[ "PT" ] ):
      pt_pass_nom = ( nom_df[ "leptonPt_MultiLepCalc" ] >= config.triggerX_bins[ "PT" ][i-1] ) 
      pt_pass_hlt = ( nom_df[ "leptonPt_MultiLepCalc" ] >= config.triggerX_bins[ "PT" ][i-1] )
    else:
      pt_pass_nom = ( nom_df[ "leptonPt_MultiLepCalc" ] >= config.triggerX_bins[ "PT" ][i] ) & ( nom_df[ "leptonPt_MultiLepCalc" ] < config.triggerX_bins[ "PT" ][i+1] )
      pt_pass_hlt = ( hlt_df[ "leptonPt_MultiLepCalc" ] >= config.triggerX_bins[ "PT" ][i] ) & ( hlt_df[ "leptonPt_MultiLepCalc" ] < config.triggerX_bins[ "PT" ][i+1] )
    for j in range( len( config.triggerX_bins[ "ETA" ] ) + 1 ):
      if j == 0:
        eta_pass_nom = nom_df[ "leptonEta_MultiLepCalc" ] < config.triggerX_bins[ "ETA" ][j]
        eta_pass_hlt = hlt_df[ "leptonEta_MultiLepCalc" ] < config.triggerX_bins[ "ETA" ][j]
      elif j == len( config.triggerX_bins[ "ETA" ] ):
        eta_pass_nom = ( nom_df[ "leptonEta_MultiLepCalc" ] >= config.triggerX_bins[ "ETA" ][j-1] )
        eta_pass_hlt = ( hlt_df[ "leptonEta_MultiLepCalc" ] >= config.triggerX_bins[ "ETA" ][j-1] )
      else:
        eta_pass_nom = ( nom_df[ "leptonEta_MultiLepCalc" ] >= config.triggerX_bins[ "ETA" ][j] ) & ( nom_df[ "leptonEta_MultiLepCalc" ] < config.triggerX_bins[ "ETA" ][j+1] )
        eta_pass_hlt = ( hlt_df[ "leptonEta_MultiLepCalc" ] >= config.triggerX_bins[ "ETA" ][j] ) & ( hlt_df[ "leptonEta_MultiLepCalc" ] < config.triggerX_bins[ "ETA" ][j+1] )
        
      yields[ "NOMINAL" ][i][j] += len( nom_df[ ( pt_pass ) & ( eta_pass ) ] )
      yields[ "HLT" ][i][j] += len( hlt_df[ ( pt_pass ) & ( eta_pass ) ] )
     
# compute efficiencies for pt and eta bins
efficiency = yields[ "HLT" ] / yields[ "NOMINAL" ]
efficiency_err = np.zeros( ( len( config.triggerX_bins[ "PT" ] ) + 1, len( config.triggerX_bins[ "ETA" ] ) + 1 ) )
for i in range( efficiency_err.shape[0] ):
  for j in range( efficiency_err.shape[1] ):
    efficiency_err[i][j] = calculate_efficiency_err( yields[ "HLT" ][i][j], yields[ "NOMINAL" ][i][j] )

# read out the efficiencies in json format
json_dict = {
  "NOMINAL YIELD": yields[ "NOMINAL" ],
  "HLT YIELD": yields[ "HLT" ],
  "EFFICIENCY": efficiency,
  "EFFICIENCY ERR": efficiency_err,
  "PT BINS": config.triggerX_bins[ "PT" ],
  "ETA BINS": config.triggerX_bins[ "ETA" ]
}

json.dumps( json_dict, open( "efficiency_{}_UL{}.json".format( args.group, args.year ), "w" ), indent = 2 )
