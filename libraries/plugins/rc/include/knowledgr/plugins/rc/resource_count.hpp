#pragma once

#include <colab/protocol/transaction.hpp>
#include <colab/protocol/optional_automated_actions.hpp>

#include <fc/int_array.hpp>
#include <fc/reflect/reflect.hpp>
#include <vector>

#define COLAB_NUM_RESOURCE_TYPES     5

namespace colab { namespace plugins { namespace rc {

enum rc_resource_types
{
   resource_history_bytes,
   resource_new_accounts,
   resource_market_bytes,
   resource_state_bytes,
   resource_execution_time
};

typedef fc::int_array< int64_t, COLAB_NUM_RESOURCE_TYPES > resource_count_type;

struct count_resources_result
{
   resource_count_type                            resource_count;
};

void count_resources(
   const colab::protocol::signed_transaction& tx,
   count_resources_result& result );

void count_resources(
   const colab::protocol::optional_automated_action&,
   count_resources_result& result );

} } } // colab::plugins::rc

FC_REFLECT_ENUM( colab::plugins::rc::rc_resource_types,
    (resource_history_bytes)
    (resource_new_accounts)
    (resource_market_bytes)
    (resource_state_bytes)
    (resource_execution_time)
   )

FC_REFLECT( colab::plugins::rc::count_resources_result,
   (resource_count)
)

FC_REFLECT_TYPENAME( colab::plugins::rc::resource_count_type )
