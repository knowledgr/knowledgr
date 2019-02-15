#pragma once

#include <knowledgr/chain/util/asset.hpp>
#include <knowledgr/chain/knowledgr_objects.hpp>

#include <knowledgr/protocol/asset.hpp>
#include <knowledgr/protocol/config.hpp>
#include <knowledgr/protocol/types.hpp>
#include <knowledgr/protocol/misc_utilities.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace knowledgr { namespace chain { namespace util {

using knowledgr::protocol::asset;
using knowledgr::protocol::price;
using knowledgr::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_knlg;
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_knowledgr;
//   price      current_knlg_price;
   protocol::curve_id   reward_curve = protocol::quadratic;
   uint128_t  content_constant = KNOWLEDGR_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx );

inline uint128_t get_content_constant_s()
{
   return KNOWLEDGR_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const protocol::curve_id& curve = protocol::quadratic, const uint128_t& content_constant = KNOWLEDGR_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( const price& p, uint64_t knlg_payout )
{
   return true; //to_sbd( p, asset( knlg_payout, KNLG_SYMBOL ) ) < KNOWLEDGR_MIN_PAYOUT_SBD;
}

} } } // knowledgr::chain::util

FC_REFLECT( knowledgr::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_knlg)
   (total_reward_shares2)
   (total_reward_fund_knowledgr)
//   (current_knlg_price)
   (reward_curve)
   (content_constant)
   )
