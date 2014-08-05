#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Run.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/Utilities/interface/EDMException.h"
#include <iomanip>
#include <iostream>

class LHEWeightsAnalyzer : public edm::EDAnalyzer {
  
  private:
    virtual void beginJob() ;
    virtual void endJob() ;
    virtual void analyze( const edm::Event&, const edm::EventSetup& ) ;
    //
    //virtual void beginRun(edm::Run const&, edm::EventSetup const&);
    //virtual void endRun(edm::Run const&, edm::EventSetup const&);
    //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
    //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
  
    edm::InputTag weightMapSrc_;
    edm::InputTag weightSrc_;

  public:
    explicit LHEWeightsAnalyzer( const edm::ParameterSet & cfg ) : 
      weightMapSrc_( cfg.getParameter<edm::InputTag>( "weightMapSrc" ) ),
      weightSrc_   ( cfg.getParameter<edm::InputTag>( "weightSrc"    ) ) {
    }
  
  //static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  
};

//LHEWeightsAnalyzer::~LHEWeightsAnalyzer() {
//}

void LHEWeightsAnalyzer::analyze( const edm::Event & ev, const edm::EventSetup & es ) {
  
  edm::Handle<std::map<std::string,double> > mapH;
  edm::Handle<double > weightH;
  ev.getByLabel( weightMapSrc_, mapH );
  ev.getByLabel( weightSrc_,    weightH );
  
  std::map<std::string, double>::const_iterator mWeight = (*mapH).begin();
  for ( ; mWeight != (*mapH).end(); ++mWeight )
    std::cout << mWeight->first<< " = " << mWeight->second << std::endl;
  
  std::cout << "The specified weight is " << *weightH << std::endl;
}


// ------------ method called once each job just before starting event loop  ------------
void LHEWeightsAnalyzer::beginJob() {
  
}

// ------------ method called once each job just after ending the event loop  ------------
void LHEWeightsAnalyzer::endJob() {
  
}

//// ------------ method called when starting to processes a run  ------------
//void LHEWeightsAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&) {
//}
//
//// ------------ method called when ending the processing of a run  ------------
//void LHEWeightsAnalyzer::endRun(edm::Run const&, edm::EventSetup const&) {
//}
//
//// ------------ method called when starting to processes a luminosity block  ------------
//void LHEWeightsAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) {
//}
//
//// ------------ method called when ending the processing of a luminosity block  ------------
//void  LHEWeightsAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) {
//}
//
// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
//void LHEWeightsAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
//  //The following says we do not know what parameters are allowed so do no validation
//  // Please change this to state exactly what you do use, even if it is no parameters
//  edm::ParameterSetDescription desc;
//  desc.setUnknown();
//  descriptions.addDefault(desc);
//}
//
#include "FWCore/Framework/interface/MakerMacros.h"

DEFINE_FWK_MODULE(LHEWeightsAnalyzer);


