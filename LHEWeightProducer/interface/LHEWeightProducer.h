#ifndef __WSUAnalysis_LHEWeightProducer_h__
#define __WSUAnalysis_LHEWeightProducer_h__
// -*- C++ -*-
//
// Package:    WSUAnalysis/LHEWeightProducer
// Class:      LHEWeightProducer
// 
/**\class LHEWeightProducer LHEWeightProducer.cc WSUAnalysis/LHEWeightProducer/plugins/LHEWeightProducer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Jared Sturdy
//         Created:  Wed, 30 Jul 2014 15:49:36 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "SimDataFormats/GeneratorProducts/interface/LHERunInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "FWCore/Utilities/interface/EDMException.h"
#include <iomanip>
#include <iostream>
//using namespace std;
//using namespace edm;
//using namespace lhef;

//
// class declaration
//

class LHEWeightProducer : public edm::EDProducer {
   public:
      explicit LHEWeightProducer(const edm::ParameterSet&);
      ~LHEWeightProducer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      virtual void beginJob() override;
      virtual void produce(edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;
      
      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------
      edm::InputTag lhesrc_;
      std::string label_;
      bool makeWeightsMap_;
      bool produceAllWeights_;
      int  numWeights_;
      bool debug_;
};

#endif
