#pragma once
#include <colab/plugins/block_api/block_api_objects.hpp>

#include <colab/protocol/types.hpp>
#include <colab/protocol/transaction.hpp>
#include <colab/protocol/block_header.hpp>

#include <colab/plugins/json_rpc/utility.hpp>

namespace colab { namespace plugins { namespace block_api {

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

} } } // colab::block_api

FC_REFLECT( colab::plugins::block_api::get_block_header_args,
   (block_num) )

FC_REFLECT( colab::plugins::block_api::get_block_header_return,
   (header) )

FC_REFLECT( colab::plugins::block_api::get_block_args,
   (block_num) )

FC_REFLECT( colab::plugins::block_api::get_block_return,
   (block) )

