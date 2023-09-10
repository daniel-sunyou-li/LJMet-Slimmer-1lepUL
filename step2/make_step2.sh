#!/bin/bash

infilename=${1}
outfilename=${2}
inputDir=${3}
outputDir=${4}
Year=${5}

source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc7_amd64_gcc700
scramv1 project CMSSW CMSSW_10_6_29
cd CMSSW_10_6_29
eval `scramv1 runtime -sh`
cd -

macroDir=${PWD}
export PATH=$PATH:$macroDir

rootPath=root://cmseos.fnal.gov/$inputDir
if [[ $inputDir == /isilon/hadoop/* ]];
then
rootPath=$inputDir
fi

root -l -b -q make_step2.C\(\"$macroDir\",\"$rootPath/$infilename\",\"$outfilename\",\"$Year\"\)

if [[ $inputDir == /isilon/hadoop/* ]];
then
  mv $outfilename $outputDir
else
  xrdcp -f $outfilename root://cmseos.fnal.gov/$outputDir/
  rm $outfilename
fi

