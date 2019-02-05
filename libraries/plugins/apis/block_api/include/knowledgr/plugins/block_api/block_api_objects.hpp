#pragma once
#include <knowledgr/chain/account_object.hpp>
#include <knowledgr/chain/block_summary_object.hpp>
#include <knowledgr/chain/comment_object.hpp>
#include <knowledgr/chain/global_property_object.hpp>
#include <knowledgr/chain/history_object.hpp>
#include <knowledgr/chain/knowledgr_objects.hpp>
#include <knowledgr/chain/transaction_object.hpp>
#include <knowledgr/chain/witness_objects.hpp>
#include <knowledgr/chain/database.hpp>

namespace knowledgr { namespace plugins { namespace block_api {

using namespace knowledgr::chain;

struct api_signed_block_object : public signed_block
{
   api_signed_block_object( const signed_block& block ) : signed_block( block )
   {
      block_id = id();
      signing_key = signee();
      transaction_ids.reserve( transactions.size() );
      for( const signed_transaction& tx : transactions )
         transaction_ids.push_back( tx.id() );
   }
   api_signed_block_object() {}

   block_id_type                 block_id;
   public_key_type               signing_key;
   vector< transaction_id_type > transaction_ids;
};

} } } // knowledgr::plugins::database_api

FC_REFLECT_DERIVED( knowledgr::plugins::block_api::api_signed_block_object, (knowledgr::protocol::signed_block),
                     (block_id)
                     (signing_key)
                     (transaction_ids)
                  )
