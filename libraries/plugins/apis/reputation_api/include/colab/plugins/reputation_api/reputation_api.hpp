#pragma once
#include <colab/plugins/json_rpc/utility.hpp>
#include <colab/plugins/reputation/reputation_objects.hpp>
#include <colab/plugins/database_api/database_api_objects.hpp>

#include <colab/protocol/types.hpp>

#include <fc/optional.hpp>
#include <fc/variant.hpp>
#include <fc/vector.hpp>

namespace colab { namespace plugins { namespace reputation {

using colab::protocol::account_name_type;

namespace detail
{
   class reputation_api_impl;
}

struct account_reputation
{
   account_name_type             account;
   colab::protocol::share_type   reputation;
};

struct get_account_reputations_args
{
   account_name_type account_lower_bound;
   uint32_t          limit = 1000;
};

struct get_account_reputations_return
{
   vector< account_reputation > reputations;
};

class reputation_api
{
   public:
      reputation_api();
      ~reputation_api();

      DECLARE_API(
         (get_account_reputations)
      )

   private:
      std::unique_ptr< detail::reputation_api_impl > my;
};

} } } // colab::plugins::reputation

FC_REFLECT( colab::plugins::reputation::account_reputation,
            (account)(reputation) );

FC_REFLECT( colab::plugins::reputation::get_account_reputations_args,
            (account_lower_bound)(limit) );

FC_REFLECT( colab::plugins::reputation::get_account_reputations_return,
            (reputations) );
