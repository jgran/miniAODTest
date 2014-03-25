import FWCore.ParameterSet.Config as cms

process = cms.Process("miniCMS2")

process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.load('Configuration.StandardSequences.Services_cff')
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:/home/users/jgran/miniAOD/patTuple_TTbar.root'
    )
)

process.out = cms.OutputModule(
        "PoolOutputModule",
        fileName = cms.untracked.string('ntuple.root'),
        dropMetaData = cms.untracked.string("ALL")
)
process.outpath = cms.EndPath(process.out)
process.out.outputCommands = cms.untracked.vstring( 'drop *' )
process.out.outputCommands.extend(cms.untracked.vstring('keep *_*Maker*_*_*'))

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = "START70_V5::All"

process.load("miniCMS2.miniNtupleMaker.testMaker_cfi");

process.p = cms.Path(process.testMaker)
