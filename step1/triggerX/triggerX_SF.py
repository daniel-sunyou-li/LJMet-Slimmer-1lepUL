import os, sys
from argparse import ArgumentParser
import numpy as np
import pickle

parser = ArgumentParser()
parser.add_argument( "-m", "--mc", required = True )
parser.add_argument( "-d", "--data", required = True )
args = parser.parse_args()

import ROOT

# load the two json files
mc_dict = pickle.load( args.mc )
data_dict = pickle.load( args.data )

# calculate the SF and SF uncertainty
def ratio_err = ( N1, N2 ):
  err1 = np.sqrt(N1)
  err2 = np.sqrt(N2)
  return np.sqrt( ( err1 / N2 )**2 + ( N1 * err2 / N2**2 )**2 )



# print the SF in a copy-paste format for HardcodedConditions.cc
