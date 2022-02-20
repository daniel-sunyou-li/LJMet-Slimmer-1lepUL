#!/bin/bash

infilename=${1}
outfilename=${2}
inputDir=${3}
outputDir=${4}

source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc7_amd64_gcc700
scramv1 project CMSSW CMSSW_10_6_19
cd CMSSW_10_6_19
eval `scramv1 runtime -sh`
cd -

macroDir=${PWD}
export PATH=$PATH:$macroDir

XRDpath=root://cmseos.fnal.gov/
if [[ $inputDir == /isilon/hadoop/* ]];
then
XRDpath=root://brux30.hep.brown.edu:1094/
fi

root -l -b -q make_step2.C\(\"$macroDir\",\"$XRDpath/$inputDir/$infilename\",\"$outfilename\"\)

xrdcp -f $outfilename root://cmseos.fnal.gov/$outputDir/
rm $outfilename
