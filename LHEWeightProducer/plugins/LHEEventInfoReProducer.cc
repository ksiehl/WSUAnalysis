#include "iostream"
#include "WSUAnalysis/LHEWeightProducer/interface/LHEEventInfoReProducer.h"

LHEEventInfoReProducer::LHEEventInfoReProducer(const edm::ParameterSet& cfg):
  lhesrc_(  cfg.getParameter<edm::InputTag>( "lheSrc" )),
  lhetoken_(consumes<LHEEventProduct>(lhesrc_)),
  debug_(   cfg.getUntrackedParameter<bool>( "debug" ) )
{
  
  //register your products
  //produces <std::vector<LHEEventRe> >();
  //produces <std::vector<LHEEventRe>, InRun>();
  
  /**
   * if do put with a label (label_ picked up from config file)
   * if no label is specified, then the product just uses the name
   * of the process that generated it
   **/
  //produces <double>();
  ////if you want to put into the Run
  //produces <double,InRun>();
  
}


LHEEventInfoReProducer::~LHEEventInfoReProducer()
{
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
}


// ------------ method called to produce the data  ------------
void LHEEventInfoReProducer::produce(edm::Event& ev, const edm::EventSetup& es)
{
  using namespace edm;
  //Read 'LHEEventProduct' from the Event
  edm::Handle<LHEEventProduct> lhevt;
  ev.getByToken(lhetoken_,lhevt);

  std::cout << "DEBUG:::comments_size " << lhevt->comments_size() << std::endl;
  for (auto comment = lhevt->comments_begin(); comment != lhevt->comments_end(); ++comment)
    std::cout << "DEBUG::: " << *comment << std::endl;
  
  std::cout << "DEBUG:::hepeup size " << lhevt->hepeup().NUP << std::endl;
  lhef::HEPEUP myhepeup = lhevt->hepeup();
  for (int part = 0; part < myhepeup.NUP; ++part) {
    std::cout << "DEBUG::: "
	      << myhepeup.IDUP[part]  << " "
	      << myhepeup.ISTUP[part] << " "
	      << myhepeup.MOTHUP[part].first  << " "
	      << myhepeup.MOTHUP[part].second << " "
	      << myhepeup.ICOLUP[part].first  << " "
	      << myhepeup.ICOLUP[part].second << " ";
    for(unsigned int j = 0; j < 5; j++)
      std::cout << myhepeup.PUP[part][j] << " ";
    std::cout << myhepeup.VTIMUP[part] << " "
	      << myhepeup.SPINUP[part] << " "
	      << std::endl;
  }
  //LHEEventRe mytest;
  
  //std::auto_ptr<LHEEventRe> pOut(new LHEEventRe(mytest));
  //ev.put( pOut);
}

// ------------ method called once each job just before starting event loop  ------------
void LHEEventInfoReProducer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void LHEEventInfoReProducer::endJob() {
}

// ------------ method called when starting to processes a run  ------------
/*
  void LHEEventInfoReProducer::beginRun(edm::Run const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method called when ending the processing of a run  ------------
/*
  void LHEEventInfoReProducer::endRun(edm::Run const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method called when starting to processes a luminosity block  ------------
/*
  void LHEEventInfoReProducer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method called when ending the processing of a luminosity block  ------------
/*
  void LHEEventInfoReProducer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void LHEEventInfoReProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(LHEEventInfoReProducer);
