#pragma once

#include <knowledgr/protocol/types.hpp>
#include <knowledgr/protocol/transaction.hpp>
#include <knowledgr/protocol/block_header.hpp>

#include <knowledgr/plugins/json_rpc/utility.hpp>
#include <knowledgr/plugins/transaction_status/transaction_status_objects.hpp>

namespace knowledgr { namespace plugins { namespace transaction_status_api {

struct find_transaction_args
{
   chain::transaction_id_type transaction_id;
   fc::optional< fc::time_point_sec > expiration;
};

struct find_transaction_return
{
   transaction_status::transaction_status status;
   fc::optional< uint32_t > block_num;
};

} } } // knowledgr::transaction_status_api

FC_REFLECT( knowledgr::plugins::transaction_status_api::find_transaction_args, (transaction_id)(expiration) )
FC_REFLECT( knowledgr::plugins::transaction_status_api::find_transaction_return, (status)(block_num) )
