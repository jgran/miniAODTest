import FWCore.ParameterSet.Config as cms

testMaker = cms.EDProducer("TestMaker",
                           pfCandidatesTag = cms.InputTag("packedPFCandidates"),
)
