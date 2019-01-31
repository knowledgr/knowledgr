#pragma once

#include <colab/protocol/block.hpp>

namespace colab { namespace chain {

struct transaction_notification
{
   transaction_notification( const colab::protocol::signed_transaction& tx ) : transaction(tx)
   {
      transaction_id = tx.id();
   }

   colab::protocol::transaction_id_type          transaction_id;
   const colab::protocol::signed_transaction&    transaction;
};

} }
