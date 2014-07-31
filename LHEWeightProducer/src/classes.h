#ifndef __LHEWeightsProducer_Classes__
#define __LHEWeightsProducer_Classes__

//#include "DataFormats/MGWeights/interface/MGWeights.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include <map>
#include <string>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace WSUAnaalusis_LHEWeightProducer {
  struct WSUAnaalusis_LHEWeightProducer_dictionary {
    //MGWeightsContainer dummy0;
    //edm::Wrapper<MGWeightsContainer> dummy1;
    
    std::map<      std::string, double> dummyMapd;
    std::map<      std::string, float > dummyMapf;

    edm::Wrapper<std::map<      std::string, double> > dummyMapdWrapper;
    edm::Wrapper<std::map<      std::string, float > > dummyMapfWrapper;
  };
}

#endif

