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

SF = np.zeros( ( len( mc_dict[ "PT BINS" ] ) + 1, len( mc_dict[ "ETA BINS" ] ) + 1 ) )
SF_err = np.zeros( ( len( mc_dict[ "PT BINS" ] ) + 1, len( mc_dict[ "ETA BINS" ] ) + 1 ) )

for i in range( len( mc_dict[ "PT BINS" ] ) + 1 ):
  for j in range( len( mc_dict[ "ETA BINS" ] ) + 1 ):
    SF[i][j] = data_dict[ "EFFICIENCY" ][i][j] / mc_dict[ "EFFICIENCY" ][i][j]
    SF_err[i][j] = ratio_err( data_dict[ "EFFICIENCY" ][i][j], data_dict[ "EFFICIENCY ERR" ][i][j], mc_dict[ "EFFICIENCY" ][i][j], mc_dict[ "EFFICIENCY ERR" ][i][j] )

# print the SF in a copy-paste format for HardcodedConditions.cc
def print_table( matrix, pt_bins, eta_bins ):
  for i in range( len( pt_bins ) + 1 ):
    if i == 0:
      print( "if ( pt < {:.1f} )".format( pt_bins[i] ) ), 
      print( "{" )
    elif i == len( pt_bins ):
      print( "else {" )
    else:
      print( "else if ( pt < {:.1f} )".format( pt_bins[i] ) ), 
      print( "{" )
    for j in range( len( eta_bins ) + 1 ):
      if np.isnan( matrix[i][j] ) or matrix[i][j] == 0.: matrix[i][j] = 1.0
      if j == 0:
        print( "  if ( fabs(eta) < {:.4f} ) return {:.5f};".format( eta_bins[j], matrix[i][j] ) )
      elif j == len( eta_bins ):
        print( "  else return {:.5f};".format( matrix[i][j] ) ), 
        print( "}" )
      else:
        print( "  else if ( fabs(eta) < {:.4f} ) return {:.5f};".format( eta_bins[j], matrix[i][j] ) )

print_table( SF, mc_dict[ "PT BINS" ], data_dict[ "ETA BINS" ] )
if args.error: 
  print_table( SF_err, mc_dict[ "PT BINS" ], data_dict[ "ETA BINS" ] )

