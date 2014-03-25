// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "RecoParticleFlow/PFProducer/interface/PFMuonAlgo.h"
#include "DataFormats/ParticleFlowReco/interface/PFBlock.h"
#include "DataFormats/Common/interface/ValueMap.h"

#include "miniCMS2/miniNtupleMaker/interface/TestMaker.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/deltaPhi.h"
#include "TMath.h"

typedef math::XYZTLorentzVectorF LorentzVector;
typedef math::XYZPoint Point;
using namespace reco;
using namespace edm;
using namespace std;

TestMaker::TestMaker(const edm::ParameterSet& iConfig) {

     pfCandidatesTag_	= iConfig.getParameter<InputTag>	("pfCandidatesTag");

     produces<vector<LorentzVector>	> ("pfcandsp4"              ).setBranchAlias("pfcands_p4"			          );

}

TestMaker::~TestMaker() 
{
}

void TestMaker::beginRun(const edm::Run&, const edm::EventSetup& es) {}
void TestMaker::beginJob() {}
void TestMaker::endJob()   {}

// ------------ method called to produce the data  ------------
void TestMaker::produce(edm::Event& iEvent, const edm::EventSetup& iSetup) {

    auto_ptr<vector<LorentzVector> >	pfcands_p4 (new vector<LorentzVector>  );

    //get pfcandidates
    Handle<pat::PackedCandidateCollection> pfCandidatesHandle;
    iEvent.getByLabel(pfCandidatesTag_, pfCandidatesHandle);
    pfCandidates  = pfCandidatesHandle.product();

    for( pat::PackedCandidateCollection::const_iterator pf_it = pfCandidates->begin(); pf_it != pfCandidates->end(); pf_it++ ) {

      pfcands_p4->push_back( LorentzVector(pf_it->p4()));

    }


    iEvent.put(pfcands_p4, "pfcandsp4");
 
}

//define this as a plug-in
DEFINE_FWK_MODULE(TestMaker);
