#!/bin/bash

hostname
date

INFILENAME=${1}
OUTFILENAME=${2}
INPUTDIR=${3}
OUTPUTDIR=${4}
IDLIST=${5}
ID=${6}
YEAR=${7}
SHIFT=${8}
SITE=${9}
SCRATCH=${PWD}


source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc7_amd64_gcc700
scramv1 project CMSSW CMSSW_10_6_29
cd CMSSW_10_6_29
eval `scramv1 runtime -sh`
cd -

echo ">> Setting macroDir to PWD"
macroDir=${PWD}
export PATH=$PATH:$macroDir
root -l -b -q compile_step1.C

XRDpath=root://cmseos.fnal.gov/$INPUTDIR
if [[ $INPUTDIR == /isilon/hadoop/* ]] ;
then
XRDpath=root://brux30.hep.brown.edu:1094/$INPUTDIR
fi
if [[ $SITE == BRUX ]];
then
XRDpath=$INPUTDIR
fi

echo ">> Running step1 over list: ${IDLIST}"

for iFile in $IDLIST; do
  inFile=${iFile}
  if [[ $iFile == ext* ]] ;
  then
    inFile=${iFile:4}
  elif [[ $iFile == [ABCDEFGHWXYZ]* ]] ;
  then
    inFile=${iFile:1}
  fi

  echo ">> Adding ${OUTFILENAME}_${iFile}.root to the list by reading ${INFILENAME}_${inFile}"
  echo  $XRDpath/${INFILENAME}_${inFile}.root,${OUTFILENAME}_${iFile}.root>> filelist
done

root -l -b -q -g make_step1.C\(\"$macroDir\",\"filelist\",\"$SHIFT\",\"20${YEAR}\"\)

echo ">> Available ROOT Files:"
ls -l *.root

# copy output to eos

NOM="nominal"
echo ">> xrdcp output for condor"

haddFile=${OUTFILENAME}_${ID}${SHIFT}_hadd.root
hadd ${haddFile} *${SHIFT}.root

if [[ $SITE == LPC ]];
then
echo ">> xrdcp -f ${haddFile} root://cmseos.fnal.gov/${OUTPUTDIR//$NOM/$SHIFT}/${haddFile//${SHIFT}_hadd/}"
xrdcp -f ${haddFile} root://cmseos.fnal.gov/${OUTPUTDIR//$NOM/$SHIFT}/${haddFile//${SHIFT}_hadd/} 2>&1
fi
if [[ $SITE == BRUX ]];
then
echo ">> mv ${haddFile} ${OUTPUTDIR//$NOM/$SHIFT}/${haddFile//${SHIFT}_hadd/}"
mv ${haddFile} ${OUTPUTDIR//$NOM/$SHIFT}/${haddFile//${SHIFT}_hadd/}
fi

XRDEXIT=$?
if [[ $XRDEXIT -ne 0 ]]; then
  rm *.root
  echo "[ERR] Exit code $XRDEXIT, failure in xrdcp (or gfal-copy)"
  exit $XRDEXIT
fi
rm *${SHIFT}.root
rm ${haddFile}
if [[ $haddFile == Single* || $haddFile == EGamma* ]]; then break; fi;

echo "[DONE]"
