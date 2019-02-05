#pragma once

#include <knowledgr/protocol/block.hpp>

namespace knowledgr { namespace chain {

struct transaction_notification
{
   transaction_notification( const knowledgr::protocol::signed_transaction& tx ) : transaction(tx)
   {
      transaction_id = tx.id();
   }

   knowledgr::protocol::transaction_id_type          transaction_id;
   const knowledgr::protocol::signed_transaction&    transaction;
};

} }
