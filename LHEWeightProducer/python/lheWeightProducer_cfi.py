import FWCore.ParameterSet.Config as cms

MGWeightsFromLHE = cms.EDProducer('LHEWeightProducer',
    lheSrc            = cms.InputTag("source"),
    weightLabel       = cms.string("mg_reweight_13"),
    makeWeightsMap    = cms.untracked.bool(True),
    produceAllWeights = cms.untracked.bool(False),
    numWeights        = cms.int32(30),
    debug             = cms.untracked.bool(False)
)
