import os, sys
from argparse import ArgumentParser
import numpy as np
import pickle

parser = ArgumentParser()
parser.add_argument( "-m", "--mc", required = True )
parser.add_argument( "-d", "--data", required = True )
parser.add_argument( "--error", action = "store_true" )
args = parser.parse_args()

import ROOT

# load the two json files
mc_dict = pickle.load( open( args.mc, "rb" ) )
data_dict = pickle.load( open( args.data, "rb" ) )

# calculate the SF and SF uncertainty
def ratio_err( x1, err1, x2, err2 ):
  return np.sqrt( ( err1 / x2 )**2 + ( x1 * err2 / x2**2 )**2 )

SF = np.zeros( ( len( mc_dict[ "HT BINS" ] ) + 1, len( mc_dict[ "PT BINS" ] ) + 1, len( mc_dict[ "ETA BINS" ] ) + 1 ) )
SF_err = np.zeros( ( len( mc_dict[ "HT BINS" ] ) + 1, len( mc_dict[ "PT BINS" ] ) + 1, len( mc_dict[ "ETA BINS" ] ) + 1 ) )

for i in range( len( mc_dict[ "HT BINS" ] ) + 1 ):
  for j in range( len( mc_dict[ "PT BINS" ] ) + 1 ):
    for k in range( len( mc_dict[ "ETA BINS" ] ) + 1 ):
      SF[i][j][k] = data_dict[ "EFFICIENCY" ][i][j][k] / mc_dict[ "EFFICIENCY" ][i][j][k]
      SF_err[i][j][k] = ratio_err( data_dict[ "EFFICIENCY" ][i][j][k], data_dict[ "EFFICIENCY ERR" ][i][j][k], mc_dict[ "EFFICIENCY" ][i][j][k], mc_dict[ "EFFICIENCY ERR" ][i][j][k] )

# print the SF in a copy-paste format for HardcodedConditions.cc
def print_table( matrix, ht_bins, pt_bins, eta_bins ):
  for i in range( len( ht_bins ) + 1 ):
    if i == 0:
      print( "if ( ht < {:.1f} )".format( ht_bins[i] ) ),
      print( "{" )
    elif i == len( ht_bins ):
      print( "else {" )
    else:
      print( "else if ( ht < {:.1f} )".format( ht_bins[i] ) ),
      print( "{" )
    for j in range( len( pt_bins ) + 1 ):
      if j == 0:
        print( "  if ( pt < {:.1f} )".format( pt_bins[j] ) ), 
        print( "{" )
      elif j == len( pt_bins ):
        print( "  else {" )
      else:
        print( "  else if ( pt < {:.1f} )".format( pt_bins[j] ) ), 
        print( "{" )
      for k in range( len( eta_bins ) + 1 ):
        if np.isnan( matrix[i][j][k] ) or matrix[i][j][k] == 0.: matrix[i][j][k] = 1.0
        if k == 0:
          print( "    if ( fabs(eta) < {:.4f} ) return {:.5f};".format( eta_bins[k], matrix[i][j][k] ) )
        elif k == len( eta_bins ):
          print( "    else return {:.5f};".format( matrix[i][j][k] ) ), 
          print( "}" )
        else:
          print( "    else if ( fabs(eta) < {:.4f} ) return {:.5f};".format( eta_bins[k], matrix[i][j][k] ) )

print_table( SF, mc_dict[ "HT BINS" ], mc_dict[ "PT BINS" ], data_dict[ "ETA BINS" ] )
if args.error: 
  print_table( SF_err, mc_dict[ "HT BINS" ],  mc_dict[ "PT BINS" ], data_dict[ "ETA BINS" ] )

