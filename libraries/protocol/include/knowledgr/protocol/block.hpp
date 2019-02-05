#pragma once
#include <knowledgr/protocol/block_header.hpp>
#include <knowledgr/protocol/transaction.hpp>

namespace knowledgr { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // knowledgr::protocol

FC_REFLECT_DERIVED( knowledgr::protocol::signed_block, (knowledgr::protocol::signed_block_header), (transactions) )
