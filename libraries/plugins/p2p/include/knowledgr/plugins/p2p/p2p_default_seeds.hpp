#pragma once

#include <vector>

namespace knowledgr{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "seed.knowledgrnodes.com:2001",            // wackou
};
#endif

} } } // knowledgr::plugins::p2p
