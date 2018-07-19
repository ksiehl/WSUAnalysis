#include "iostream"
#include "WSUAnalysis/LHEWeightProducer/interface/LHEWeightProducer.h"

LHEWeightProducer::LHEWeightProducer(const edm::ParameterSet& cfg):
  lhesrc_(            cfg.getParameter<edm::InputTag>( "lheSrc" )    ),
  label_(             cfg.getParameter<std::string>( "weightLabel" ) ),
  makeWeightsMap_(    cfg.getUntrackedParameter<bool>( "makeWeightsMap" )     ),
  produceAllWeights_( cfg.getUntrackedParameter<bool>( "produceAllWeights" )  ),
  numWeights_(        cfg.getParameter<int>(  "numWeights" )         ),
  debug_(             cfg.getUntrackedParameter<bool>( "debug" )              )
{
  //register your products
  //map based product not quite working yet
  if (makeWeightsMap_ && !produceAllWeights_)
    produces <std::map<std::basic_string<char>,double> >("MGWeightMap");
  produces <double>("mgreweight0");////FIXME:This should work, it was commented out
  //loop over all weight names and generate a product
  if (produceAllWeights_ && !makeWeightsMap_)
    for (int wgtNum = 0; wgtNum < numWeights_; ++wgtNum) 
      {
	std::stringstream prodname;
	prodname << "mgreweight" << (wgtNum+1);
	if (debug_)
	  std::cout << "DEBUG::" << prodname.str() << std::endl;
	produces <double>(prodname.str());
      }
  
  /**
   * individually specify the product label
   * in this way, one could also make a single label, or no label,
   * and run this producer with a switch to produce a single weight
   * for each possibility in the LHE file
   **/
  //produces <double>("mgIreweightI1");
  //produces <double>("mgIreweightI2");
  //produces <double>("mgIreweightI3");
  //produces <double>("mgIreweightI4");
  //produces <double>("mgIreweightI5");
  //produces <double>("mgIreweightI6");
  //produces <double>("mgIreweightI7");
  //produces <double>("mgIreweightI8");
  //produces <double>("mgIreweightI9");
  //produces <double>("mgIreweightI10");
  //produces <double>("mgIreweightI11");
  //produces <double>("mgIreweightI12");
  //produces <double>("mgIreweightI13");
  //produces <double>("mgIreweightI14");
  //produces <double>("mgIreweightI15");
  //produces <double>("mgIreweightI16");
  //produces <double>("mgIreweightI17");
  //produces <double>("mgIreweightI18");
  //produces <double>("mgIreweightI19");
  //produces <double>("mgIreweightI20");
  //produces <double>("mgIreweightI21");
  //produces <double>("mgIreweightI22");
  //produces <double>("mgIreweightI23");
  //produces <double>("mgIreweightI24");
  //produces <double>("mgIreweightI25");
  //produces <double>("mgIreweightI26");
  //produces <double>("mgIreweightI27");
  //produces <double>("mgIreweightI28");
  //produces <double>("mgIreweightI29");
  //produces <double>("mgIreweightI30");

  if (!produceAllWeights_ && !makeWeightsMap_)
    produces <double>();
  
  /**
   * if do put with a label (label_ picked up from config file)
   * if no label is specified, then the product just uses the name
   * of the process that generated it
   **/
  //produces <double>(label_);
  //
  ////if you want to put into the Run
  //produces <double,InRun>();
  
  lheToken_ = consumes<LHEEventProduct>(lhesrc_); //added for new requirement
}


LHEWeightProducer::~LHEWeightProducer()
{
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
}


// ------------ method called to produce the data  ------------
void LHEWeightProducer::produce(edm::Event& ev, const edm::EventSetup& es)
{
  using namespace edm;
  //Read 'LHEEventProduct' from the Event
  edm::Handle<LHEEventProduct> lhevt; //i added edm:: and uncommented
  ////edm::Handle<GenEventInfoProduct> lhevt; //i added edm:: and commented
  //ev.getByLabel(lhesrc_,lhevt);

  //edm::Handle<GenEventInfoProduct> lheColl; //added for new requirement
  ev.getByToken(lheToken_, lhevt); //added for new requirement
  
  /****
       const lhef::HEPEUP hepeup_ = lhevt->hepeup();
  
       const int nup_ = hepeup_.NUP; 
       const std::vector<int> idup_ = hepeup_.IDUP;
       const std::vector<lhef::HEPEUP::FiveVector> pup_ = hepeup_.PUP;
  
  
       std::cout << "Number of particles = " << nup_ << std::endl;
  
       if ( lhevt->pdf() != NULL ) {
       std::cout << "PDF scale = "  << std::setw(14) << std::fixed << lhevt->pdf()->scalePDF << std::endl;  
       std::cout << "PDF 1 : id = " << std::setw(14) << std::fixed << lhevt->pdf()->id.first 
       << " x = "         << std::setw(14) << std::fixed << lhevt->pdf()->x.first 
       << " xPDF = "      << std::setw(14) << std::fixed << lhevt->pdf()->xPDF.first << std::endl;  
       std::cout << "PDF 2 : id = " << std::setw(14) << std::fixed << lhevt->pdf()->id.second 
       << " x = "         << std::setw(14) << std::fixed << lhevt->pdf()->x.second 
       << " xPDF = "      << std::setw(14) << std::fixed << lhevt->pdf()->xPDF.second << std::endl;  
       }
    
       for ( unsigned int icount = 0 ; icount < (unsigned int)nup_; icount++ ) {
      
       std::cout << "# " << std::setw(14) << std::fixed << icount 
       << std::setw(14) << std::fixed << idup_[icount] 
       << std::setw(14) << std::fixed << (pup_[icount])[0] 
       << std::setw(14) << std::fixed << (pup_[icount])[1] 
       << std::setw(14) << std::fixed << (pup_[icount])[2] 
       << std::setw(14) << std::fixed << (pup_[icount])[3] 
       << std::setw(14) << std::fixed << (pup_[icount])[4] 
       << std::endl;
       }
  ***/
  std::auto_ptr<std::map<std::basic_string<char>, double> > weightMap(new std::map<std::basic_string<char>,double>());
  double prodWeight = 0.0;
  //double reweight00 = .000022640;
  //int numlheevents = 10;
  if( lhevt->weights().size() ) 
    {
      if (debug_)
	std::cout << "DEBUG::weights:" << std::endl;
      for ( size_t iwgt = 0; iwgt < lhevt->weights().size(); ++iwgt ) 
	{
	  //double wgt = lhevt->weights().at(iwgt); //i commented out
	  const LHEEventProduct::WGT& wgt = lhevt->weights().at(iwgt); //i uncommented
	    if (debug_)
	    std::cout << "DEBUG::\t" << wgt.id << ' ' 
	    << std::scientific << wgt.wgt << std::endl;
	    
	    //put all weights as individual products
	    std::stringstream sskey; //i must have added this later
	    sskey << "mgreweight" << iwgt; //i must have added this later
	    std::string key = sskey.str(); //i must have added this later
	    if (produceAllWeights_ && !makeWeightsMap_) 
	    {
	    std::auto_ptr<double> pOut(new double(wgt.wgt));
	    std::string key = wgt.id;
	    if (debug_)
	    std::cout << "DEBUG::before replace: " << key << std::endl;
	    //std::replace(key.begin(), key.end(), '_', '-'); //i commented this line out after apparently changing a colon to a hyphen as the last argument to std::replace
            key.erase(std::remove(key.begin(),key.end(),'_'),key.end()); //i added this line
	    if (debug_)
	    std::cout << "DEBUG::after replace: " << key << std::endl;
	    ev.put(pOut , key);
	    }
	    if (!produceAllWeights_ && !makeWeightsMap_) 
	    if (label_== wgt.id)
	    prodWeight = wgt.wgt;
      
	    //generate the weighs map as a product
	    if (makeWeightsMap_ && !produceAllWeights_)
	    (*weightMap)[wgt.id] = wgt.wgt; //it's here that ends the part i uncommented
	  
	  //double wgt = lhevt->weights().at(iwgt); //i say it's not in jared's
	  //put all weights as individual products
	  //std::stringstream sskey; //i must have originally removed this
	  //sskey << "mg_reweight_" << iwgt; //i must have originally removed this
	  //std::string key = sskey.str();  //i must have originally removed this
	  /*if (produceAllWeights_ && !makeWeightsMap_) //i commented this block out
	    {
	      std::auto_ptr<double> pOut(new double(wgt));
	      if (debug_)
		std::cout << "DEBUG::before replace: " << key << std::endl;
	      std::replace(key.begin(), key.end(), '_', ':');
	      if (debug_)
		std::cout << "DEBUG::after replace: " << key << std::endl;
	      ev.put(pOut , key);
	    }
	  if (!produceAllWeights_ && !makeWeightsMap_) 
	    if (label_==sskey.str())
	      prodWeight = wgt;
      
	  //generate the weighs map as a product
	  if (makeWeightsMap_ && !produceAllWeights_)
	    (*weightMap)[key] = wgt; */ //it ends here the block i commented out
	}
    }
  
  // put the std:map of weights into the event (currently not working)
  //std::auto_ptr<std::map<std::string, double> > weightMapP(new std::map<std::string,double>(weightMap));
  if (makeWeightsMap_) 
    ev.put(weightMap, "MGWeightMap");
  
  if (!produceAllWeights_ && !makeWeightsMap_) 
    {
      std::auto_ptr<double> pOut(new double(prodWeight));
      ev.put(pOut);
    }

  /*if (produceAllWeights_ && !makeWeightsMap_) ////////////////////HERE IS MY ADDITION
    {
      std::auto_ptr<double> pOut(new double(mgreweight00));
      ev.put(pOut);
      std::auto_ptr<double> pOut(new int(numlheevents));
      ev.put(pOut);
     }*/

  /* this is an EventSetup example
  //Read SetupData from the SetupRecord in the EventSetup
  ESHandle<SetupData> pSetup;
  es.get<SetupRecord>().get(pSetup);
  */
  
}

// ------------ method called once each job just before starting event loop  ------------
void LHEWeightProducer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void LHEWeightProducer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
  void LHEWeightProducer::beginRun(edm::Run const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method called when ending the processing of a run  ------------
/*
  void LHEWeightProducer::endRun(edm::Run const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method called when starting to processes a luminosity block  ------------
/*
  void LHEWeightProducer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method called when ending the processing of a luminosity block  ------------
/*
  void LHEWeightProducer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void LHEWeightProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) 
{
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(LHEWeightProducer);
