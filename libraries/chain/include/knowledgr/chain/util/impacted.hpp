#pragma once

#include <fc/container/flat.hpp>
#include <knowledgr/protocol/operations.hpp>
#include <knowledgr/protocol/transaction.hpp>

#include <fc/string.hpp>

namespace knowledgr { namespace app {

using namespace fc;

void operation_get_impacted_accounts(
   const knowledgr::protocol::operation& op,
   fc::flat_set<protocol::account_name_type>& result );

void transaction_get_impacted_accounts(
   const knowledgr::protocol::transaction& tx,
   fc::flat_set<protocol::account_name_type>& result
   );

} } // knowledgr::app
