#pragma once
#include <knowledgr/plugins/block_api/block_api_objects.hpp>

#include <knowledgr/protocol/types.hpp>
#include <knowledgr/protocol/transaction.hpp>
#include <knowledgr/protocol/block_header.hpp>

#include <knowledgr/plugins/json_rpc/utility.hpp>

namespace knowledgr { namespace plugins { namespace block_api {

/* get_block_header */

struct get_block_header_args
{
   uint32_t block_num;
};

struct get_block_header_return
{
   optional< block_header > header;
};

/* get_block */
struct get_block_args
{
   uint32_t block_num;
};

struct get_block_return
{
   optional< api_signed_block_object > block;
};

} } } // knowledgr::block_api

FC_REFLECT( knowledgr::plugins::block_api::get_block_header_args,
   (block_num) )

FC_REFLECT( knowledgr::plugins::block_api::get_block_header_return,
   (header) )

FC_REFLECT( knowledgr::plugins::block_api::get_block_args,
   (block_num) )

FC_REFLECT( knowledgr::plugins::block_api::get_block_return,
   (block) )

