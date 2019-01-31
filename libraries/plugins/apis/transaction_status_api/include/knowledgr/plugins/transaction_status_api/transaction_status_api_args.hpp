#pragma once

#include <colab/protocol/types.hpp>
#include <colab/protocol/transaction.hpp>
#include <colab/protocol/block_header.hpp>

#include <colab/plugins/json_rpc/utility.hpp>
#include <colab/plugins/transaction_status/transaction_status_objects.hpp>

namespace colab { namespace plugins { namespace transaction_status_api {

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

} } } // colab::transaction_status_api

FC_REFLECT( colab::plugins::transaction_status_api::find_transaction_args, (transaction_id)(expiration) )
FC_REFLECT( colab::plugins::transaction_status_api::find_transaction_return, (status)(block_num) )
