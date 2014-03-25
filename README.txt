Setting up
------------------------
cmsrel CMSSW_7_0_0
cd CMSSW_7_0_0/src
git clone https://github.com/jgran/miniAODTest miniCMS2/miniNtupleMaker
cd miniCMS2/miniNtupleMaker
source setup/patchesToSource.sh
cd $CMSSW_BASE/src
scram b -j20


Running
------------------------
cmsRun python/runMini_cfg.py
