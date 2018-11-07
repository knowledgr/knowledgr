#pragma once

#include <fc/container/flat.hpp>
#include <colab/protocol/operations.hpp>
#include <colab/protocol/transaction.hpp>

#include <fc/string.hpp>

namespace colab { namespace app {

using namespace fc;

void operation_get_impacted_accounts(
   const colab::protocol::operation& op,
   fc::flat_set<protocol::account_name_type>& result );

void transaction_get_impacted_accounts(
   const colab::protocol::transaction& tx,
   fc::flat_set<protocol::account_name_type>& result
   );

} } // colab::app
