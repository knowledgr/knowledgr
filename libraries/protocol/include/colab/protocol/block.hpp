#pragma once
#include <colab/protocol/block_header.hpp>
#include <colab/protocol/transaction.hpp>

namespace colab { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // colab::protocol

FC_REFLECT_DERIVED( colab::protocol::signed_block, (colab::protocol::signed_block_header), (transactions) )
