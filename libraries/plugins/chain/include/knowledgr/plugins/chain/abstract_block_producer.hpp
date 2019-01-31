#pragma once

#include <fc/time.hpp>

#include <colab/chain/database.hpp>

namespace colab { namespace plugins { namespace chain {
   
class abstract_block_producer {
public:
   virtual ~abstract_block_producer() = default;

   virtual colab::chain::signed_block generate_block(
      fc::time_point_sec when,
      const colab::chain::account_name_type& witness_owner,
      const fc::ecc::private_key& block_signing_private_key,
      uint32_t skip = colab::chain::database::skip_nothing) = 0;
};

} } } // colab::plugins::chain
