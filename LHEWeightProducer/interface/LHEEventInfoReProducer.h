#ifndef __WSUAnalysis_LHEEventInfoReProducer_h__
#define __WSUAnalysis_LHEEventInfoReProducer_h__
// -*- C++ -*-
//
// Package:    WSUAnalysis/LHEWeightProducer
// Class:      LHEEventInfoReProducer
// 
/**\class LHEEventInfoReProducer LHEEventInfoReProducer.cc WSUAnalysis/LHEWeightProducer/plugins/LHEEventInfoReProducer.cc

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

#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
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

class LHEEventInfoReProducer : public edm::EDProducer {
   public:
      explicit LHEEventInfoReProducer(const edm::ParameterSet&);
      ~LHEEventInfoReProducer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

      typedef struct LHEEventRe {
	int    pid;
	int    q;
	double px;
	double py;
	double pz;
	double e;
	double m;
      } LHEEventRe;
      
   private:
      virtual void beginJob();
      virtual void produce(edm::Event&, const edm::EventSetup&);
      virtual void endJob();
      
      //virtual void beginRun(edm::Run const&, edm::EventSetup const&);
      //virtual void endRun(edm::Run const&, edm::EventSetup const&);
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

      // ----------member data ---------------------------
      edm::InputTag lhesrc_;
      edm::EDGetTokenT<LHEEventProduct> lhetoken_;
      bool debug_;

      /**
       * LHE Info
       *
       *<event>
       * 8      0 +2.9496000e-04 3.42144000e+02 7.81860900e-03 1.06589400e-01
       * I    IST ID   Mothers   Colours            p_x            p_y            p_z              E              m
       *        1 -1    0    0  501    0 +0.0000000e+00 +0.0000000e+00 +4.7850713e+02 4.78507128e+02 0.00000000e+00 0.0000e+00 -1.0000e+00
       *       -1 -1    0    0    0  501 +0.0000000e+00 +0.0000000e+00 -3.2500974e+02 3.25009744e+02 0.00000000e+00 0.0000e+00  1.0000e+00
       *       24  2    1    2    0    0 +1.9162283e+02 +2.7178037e+02 -1.2309450e+02 3.63613505e+02 8.04900390e+01 0.0000e+00  0.0000e+00
       *      -24  2    1    2    0    0 -1.9162283e+02 -2.7178037e+02 +2.7659188e+02 4.39903366e+02 8.01749534e+01 0.0000e+00  0.0000e+00
       *      -13  1    3    3    0    0 +1.3142330e+02 +1.5841163e+02 -1.1311752e+02 2.34865706e+02 0.00000000e+00 0.0000e+00  1.0000e+00
       *       14  1    3    3    0    0 +6.0199535e+01 +1.1336874e+02 -9.9769804e+00 1.28747799e+02 0.00000000e+00 0.0000e+00 -1.0000e+00
       *        1  1    4    4  502    0 -1.4616894e+02 -2.2808468e+02 +1.8250404e+02 3.26643084e+02 0.00000000e+00 0.0000e+00 -1.0000e+00
       *       -2  1    4    4    0  502 -4.5453898e+01 -4.3695690e+01 +9.4087838e+01 1.13260282e+02 0.00000000e+00 0.0000e+00  1.0000e+00
       */
};

#endif
