#!/bin/bash

#script to get updated packages needed to run on miniAOD

cmsenv
pushd .
cd $CMSSW_BASE/src
git init
git config core.sparsecheckout true
echo DataFormats/PatCandidates >> .git/info/sparse-checkout
echo PhysicsTools/PatAlgos >> .git/info/sparse-checkout
echo RecoJets/JetProducers >> .git/info/sparse-checkout
git remote add -f origin https://github.com/gpetruc/cmssw.git
git pull origin micro-from700
popd
