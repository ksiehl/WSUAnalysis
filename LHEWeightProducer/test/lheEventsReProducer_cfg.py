import FWCore.ParameterSet.Config as cms

process = cms.Process("REPRODUCE")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.MessageLogger.cerr.FwkReport.reportEvery = 25

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

process.source = cms.Source("LHESource",
    fileNames = cms.untracked.vstring("file:/afs/cern.ch/user/k/ksiehl/public/unweighted_events.lhe"),

    # and the usual optional stuff (refer to documentation/code of InputSources for more)

    # skipEvents        = cms.untracked.uint32(0),      # events to skip
    # firstEvent        = cms.untracked.uint32(1),      # event number to assign to first event 
    # firstRun          = cms.untracked.uint32(1),      # first run number
    # numberEventsInRun = cms.untracked.uint32(100000)  # number of events after which run number is incremented
)


process.LHE = cms.OutputModule("PoolOutputModule",
    dataset = cms.untracked.PSet(dataTier = cms.untracked.string('LHEEvents')),
    fileName = cms.untracked.string('lhe.root')
)

from WSUAnalysis.LHEWeightProducer.lheEventInfoReProducer_cfi import *

process.reproduced = LHEEventInfoReProduced.clone()

process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('testOut.root')
)

process.revents = cms.Sequence(
      process.reproduced
)
process.p = cms.Path(process.revents)

process.e = cms.EndPath(process.LHE)
