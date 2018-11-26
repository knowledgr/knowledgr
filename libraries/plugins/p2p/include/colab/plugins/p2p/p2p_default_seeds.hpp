#pragma once

#include <vector>

namespace colab{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "seed.colabnodes.com:2001",            // wackou
};
#endif

} } } // colab::plugins::p2p
