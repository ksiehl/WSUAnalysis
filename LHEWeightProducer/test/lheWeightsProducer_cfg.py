import FWCore.ParameterSet.Config as cms

process = cms.Process("WEIGHTS")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.MessageLogger.cerr.FwkReport.reportEvery = 25

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:/afs/cern.ch/user/s/sturdy/work/WSUAnalysis/anomalous_couplings/GEN_TO_RECO/step1/NEWER_TRY_multi.root'
    )
)

MGWeightsFromLHE = cms.EDProducer('LHEWeightProducer',
    lheSrc            = cms.InputTag("source"),
    #lheSrc            = cms.InputTag("generator"),
    weightLabel       = cms.string("mg_reweight_13"),
    makeWeightsMap    = cms.untracked.bool(True),
    produceAllWeights = cms.untracked.bool(False),
    numWeights        = cms.int32(30),
    debug             = cms.untracked.bool(False)
)
process.weightsMap = MGWeightsFromLHE.clone()
process.weight10   = process.weightsMap.clone(
    makeWeightsMap    = cms.untracked.bool(False),
    weightLabel       = cms.string("mg_reweight_10"),
    )
process.weight15   = process.weight10.clone(
    weightLabel       = cms.string("mg_reweight_15"),
    )
process.weight30   = process.weight10.clone(
    weightLabel       = cms.string("mg_reweight_30"),
    )
process.weight5   = process.weight10.clone(
    weightLabel       = cms.string("mg_reweight_5"),
    )
process.allWeights = MGWeightsFromLHE.clone(
    makeWeightsMap    = cms.untracked.bool(False),
    produceAllWeights = cms.untracked.bool(True),
)

process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('testOut.root')
)

process.MGWeights = cms.Sequence(
      process.weight5
    + process.weight10
    + process.weight15
    + process.weight30
    + process.allWeights
    + process.weightsMap
)
process.p = cms.Path(process.MGWeights)

process.e = cms.EndPath(process.out)
