import FWCore.ParameterSet.Config as cms

LHEEventInfoReProduced = cms.EDProducer('LHEEventInfoReProducer',
    lheSrc            = cms.InputTag("source"),
    debug             = cms.untracked.bool(False)
)
