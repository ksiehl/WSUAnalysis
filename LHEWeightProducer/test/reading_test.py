import FWCore.ParameterSet.Config as cms

process = cms.Process("DEMO")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.MessageLogger.cerr.FwkReport.reportEvery = 25

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(5)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:testOut.root'
    )
)

process.readWeights = cms.EDAnalyzer('LHEWeightsAnalyzer',
    weightMapSrc      = cms.InputTag("weightsMap","MGWeightMap"),
    weightSrc         = cms.InputTag("allWeights","mg-reweight-1"),
    #weightSrc         = cms.InputTag("weight30"),
    #weightLabel       = cms.string("mg_reweight_13"),
)
process.p = cms.Path(process.readWeights)
