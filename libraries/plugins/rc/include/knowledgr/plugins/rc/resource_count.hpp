#pragma once

#include <knowledgr/protocol/transaction.hpp>
#include <knowledgr/protocol/optional_automated_actions.hpp>

#include <fc/int_array.hpp>
#include <fc/reflect/reflect.hpp>
#include <vector>

#define KNOWLEDGR_NUM_RESOURCE_TYPES     5

namespace knowledgr { namespace plugins { namespace rc {

enum rc_resource_types
{
   resource_history_bytes,
   resource_new_accounts,
   resource_market_bytes,
   resource_state_bytes,
   resource_execution_time
};

typedef fc::int_array< int64_t, KNOWLEDGR_NUM_RESOURCE_TYPES > resource_count_type;

struct count_resources_result
{
   resource_count_type                            resource_count;
};

void count_resources(
   const knowledgr::protocol::signed_transaction& tx,
   count_resources_result& result );

void count_resources(
   const knowledgr::protocol::optional_automated_action&,
   count_resources_result& result );

} } } // knowledgr::plugins::rc

FC_REFLECT_ENUM( knowledgr::plugins::rc::rc_resource_types,
    (resource_history_bytes)
    (resource_new_accounts)
    (resource_market_bytes)
    (resource_state_bytes)
    (resource_execution_time)
   )

FC_REFLECT( knowledgr::plugins::rc::count_resources_result,
   (resource_count)
)

FC_REFLECT_TYPENAME( knowledgr::plugins::rc::resource_count_type )
