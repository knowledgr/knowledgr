#pragma once

#include <colab/chain/util/asset.hpp>
#include <colab/chain/colab_objects.hpp>

#include <colab/protocol/asset.hpp>
#include <colab/protocol/config.hpp>
#include <colab/protocol/types.hpp>
#include <colab/protocol/misc_utilities.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace colab { namespace chain { namespace util {

using colab::protocol::asset;
using colab::protocol::price;
using colab::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_sbd;
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_colab;
   price      current_clc_price;
   protocol::curve_id   reward_curve = protocol::quadratic;
   uint128_t  content_constant = COLAB_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx );

inline uint128_t get_content_constant_s()
{
   return COLAB_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const protocol::curve_id& curve = protocol::quadratic, const uint128_t& content_constant = COLAB_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( const price& p, uint64_t clc_payout )
{
   return to_sbd( p, asset( clc_payout, CLC_SYMBOL ) ) < COLAB_MIN_PAYOUT_SBD;
}

} } } // colab::chain::util

FC_REFLECT( colab::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_sbd)
   (total_reward_shares2)
   (total_reward_fund_colab)
   (current_clc_price)
   (reward_curve)
   (content_constant)
   )
