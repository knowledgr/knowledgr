#pragma once

#include <cstdint>

#include <knowledgr/protocol/config.hpp>
#include <knowledgr/protocol/types.hpp>

#include <fc/uint128.hpp>

namespace knowledgr { namespace protocol {

template< uint16_t percent, uint64_t multiply_constant, uint64_t shift_constant >
share_type calc_percent_reward( share_type current_supply )
{
   static_assert( shift_constant > 0, "shift constant cannot be zero" );
   static_assert( shift_constant < 128, "shift constant is implausibly large, re-check your arguments" );
   static_assert( multiply_constant > 256, "multiply constant is implausibly small, re-check your arguments" );
   static_assert( multiply_constant < UINT64_MAX / (10 * uint64_t( KNOWLEDGR_100_PERCENT )), "multiply constant is too large, we may be in danger of overflow" );
   static_assert( (percent == 0) || (percent > KNOWLEDGR_1_PERCENT), "percent is smaller than 1%, re-check your arguments" );
   static_assert( percent <= KNOWLEDGR_100_PERCENT, "percent is implausibly large, re-check your arguments (if you really mean to do this, you should revise the overflow check above accordingly)" );

   static const uint128_t half = uint128_t(1) << (shift_constant - 1);

   uint128_t reward = current_supply.value;
   reward *= (percent * multiply_constant);      // compile-time constant, fits in 64 bits
   reward += half;                               // round to nearest whole integer instead of truncating
   reward >>= shift_constant;
   return reward.to_uint64();
}

template< uint16_t percent >
inline share_type calc_percent_reward_per_hour( share_type current_supply )
{
   return calc_percent_reward< percent, KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_HOUR, KNOWLEDGR_APR_PERCENT_SHIFT_PER_HOUR >( current_supply );
}

template< uint16_t percent >
inline share_type calc_percent_reward_per_block( share_type current_supply )
{
   return calc_percent_reward< percent, KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_BLOCK, KNOWLEDGR_APR_PERCENT_SHIFT_PER_BLOCK >( current_supply );
}

template< uint16_t percent >
inline share_type calc_percent_reward_per_round( share_type current_supply )
{
   return calc_percent_reward< percent, KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_ROUND, KNOWLEDGR_APR_PERCENT_SHIFT_PER_ROUND >( current_supply );
}

} }
