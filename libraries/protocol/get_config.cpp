#include <knowledgr/protocol/get_config.hpp>
#include <knowledgr/protocol/config.hpp>
#include <knowledgr/protocol/asset.hpp>
#include <knowledgr/protocol/types.hpp>
#include <knowledgr/protocol/version.hpp>

namespace knowledgr { namespace protocol {

fc::variant_object get_config()
{
   fc::mutable_variant_object result;

#ifdef IS_TEST_NET
   result[ "IS_TEST_NET" ] = true;
   result["TESTNET_BLOCK_LIMIT"] = TESTNET_BLOCK_LIMIT;
#else
   result[ "IS_TEST_NET" ] = false;
#endif
#ifdef KNOWLEDGR_ENABLE_SMT
   result[ "KNOWLEDGR_ENABLE_SMT" ] = true;
   result["SMT_VESTING_WITHDRAW_INTERVAL_SECONDS"] = SMT_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["SMT_UPVOTE_LOCKOUT"] = SMT_UPVOTE_LOCKOUT;
   result["SMT_MAX_VOTABLE_ASSETS"] = SMT_MAX_VOTABLE_ASSETS;
#else
   result[ "KNOWLEDGR_ENABLE_SMT" ] = false;
#endif

   result["SBD_SYMBOL"] = SBD_SYMBOL;
   result["KNOWLEDGR_INITIAL_VOTE_POWER_RATE"] = KNOWLEDGR_INITIAL_VOTE_POWER_RATE;
   result["KNOWLEDGR_REDUCED_VOTE_POWER_RATE"] = KNOWLEDGR_REDUCED_VOTE_POWER_RATE;
   result["KNOWLEDGR_100_PERCENT"] = KNOWLEDGR_100_PERCENT;
   result["KNOWLEDGR_1_PERCENT"] = KNOWLEDGR_1_PERCENT;
   result["KNOWLEDGR_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD"] = KNOWLEDGR_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD;
   result["KNOWLEDGR_ACTIVE_CHALLENGE_COOLDOWN"] = KNOWLEDGR_ACTIVE_CHALLENGE_COOLDOWN;
   result["KNOWLEDGR_ACTIVE_CHALLENGE_FEE"] = KNOWLEDGR_ACTIVE_CHALLENGE_FEE;
   result["KNOWLEDGR_ADDRESS_PREFIX"] = KNOWLEDGR_ADDRESS_PREFIX;
   result["KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_BLOCK"] = KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_BLOCK;
   result["KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_HOUR"] = KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_HOUR;
   result["KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_ROUND"] = KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_ROUND;
   result["KNOWLEDGR_APR_PERCENT_SHIFT_PER_BLOCK"] = KNOWLEDGR_APR_PERCENT_SHIFT_PER_BLOCK;
   result["KNOWLEDGR_APR_PERCENT_SHIFT_PER_HOUR"] = KNOWLEDGR_APR_PERCENT_SHIFT_PER_HOUR;
   result["KNOWLEDGR_APR_PERCENT_SHIFT_PER_ROUND"] = KNOWLEDGR_APR_PERCENT_SHIFT_PER_ROUND;
   result["KNOWLEDGR_BANDWIDTH_AVERAGE_WINDOW_SECONDS"] = KNOWLEDGR_BANDWIDTH_AVERAGE_WINDOW_SECONDS;
   result["KNOWLEDGR_BANDWIDTH_PRECISION"] = KNOWLEDGR_BANDWIDTH_PRECISION;
   result["KNOWLEDGR_BLOCKCHAIN_PRECISION"] = KNOWLEDGR_BLOCKCHAIN_PRECISION;
   result["KNOWLEDGR_BLOCKCHAIN_PRECISION_DIGITS"] = KNOWLEDGR_BLOCKCHAIN_PRECISION_DIGITS;
   result["KNOWLEDGR_BLOCKCHAIN_HARDFORK_VERSION"] = KNOWLEDGR_BLOCKCHAIN_HARDFORK_VERSION;
   result["KNOWLEDGR_BLOCKCHAIN_VERSION"] = KNOWLEDGR_BLOCKCHAIN_VERSION;
   result["KNOWLEDGR_BLOCK_INTERVAL"] = KNOWLEDGR_BLOCK_INTERVAL;
   result["KNOWLEDGR_BLOCKS_PER_DAY"] = KNOWLEDGR_BLOCKS_PER_DAY;
   result["KNOWLEDGR_BLOCKS_PER_HOUR"] = KNOWLEDGR_BLOCKS_PER_HOUR;
   result["KNOWLEDGR_BLOCKS_PER_YEAR"] = KNOWLEDGR_BLOCKS_PER_YEAR;
   result["KNOWLEDGR_CASHOUT_WINDOW_SECONDS"] = KNOWLEDGR_CASHOUT_WINDOW_SECONDS;
   result["KNOWLEDGR_CASHOUT_WINDOW_SECONDS_PRE_HF12"] = KNOWLEDGR_CASHOUT_WINDOW_SECONDS_PRE_HF12;
   result["KNOWLEDGR_CASHOUT_WINDOW_SECONDS_PRE_HF17"] = KNOWLEDGR_CASHOUT_WINDOW_SECONDS_PRE_HF17;
   result["KNOWLEDGR_CHAIN_ID"] = KNOWLEDGR_CHAIN_ID;
   result["KNOWLEDGR_COMMENT_REWARD_FUND_NAME"] = KNOWLEDGR_COMMENT_REWARD_FUND_NAME;
   result["KNOWLEDGR_CONTENT_APR_PERCENT"] = KNOWLEDGR_CONTENT_APR_PERCENT;
   result["KNOWLEDGR_CONTENT_CONSTANT_HF0"] = KNOWLEDGR_CONTENT_CONSTANT_HF0;
   result["KNOWLEDGR_CONTENT_REWARD_PERCENT"] = KNOWLEDGR_CONTENT_REWARD_PERCENT;
   result["KNOWLEDGR_CONVERSION_DELAY"] = KNOWLEDGR_CONVERSION_DELAY;
   result["KNOWLEDGR_CONVERSION_DELAY_PRE_HF_16"] = KNOWLEDGR_CONVERSION_DELAY_PRE_HF_16;
   result["KNOWLEDGR_CREATE_ACCOUNT_DELEGATION_RATIO"] = KNOWLEDGR_CREATE_ACCOUNT_DELEGATION_RATIO;
   result["KNOWLEDGR_CREATE_ACCOUNT_DELEGATION_TIME"] = KNOWLEDGR_CREATE_ACCOUNT_DELEGATION_TIME;
   result["KNOWLEDGR_CREATE_ACCOUNT_WITH_KNOWLEDGR_MODIFIER"] = KNOWLEDGR_CREATE_ACCOUNT_WITH_KNOWLEDGR_MODIFIER;
   result["KNOWLEDGR_CURATE_APR_PERCENT"] = KNOWLEDGR_CURATE_APR_PERCENT;
   result["KNOWLEDGR_DEFAULT_SBD_INTEREST_RATE"] = KNOWLEDGR_DEFAULT_SBD_INTEREST_RATE;
   result["KNOWLEDGR_EQUIHASH_K"] = KNOWLEDGR_EQUIHASH_K;
   result["KNOWLEDGR_EQUIHASH_N"] = KNOWLEDGR_EQUIHASH_N;
   result["KNOWLEDGR_FEED_HISTORY_WINDOW"] = KNOWLEDGR_FEED_HISTORY_WINDOW;
   result["KNOWLEDGR_FEED_HISTORY_WINDOW_PRE_HF_16"] = KNOWLEDGR_FEED_HISTORY_WINDOW_PRE_HF_16;
   result["KNOWLEDGR_FEED_INTERVAL_BLOCKS"] = KNOWLEDGR_FEED_INTERVAL_BLOCKS;
   result["KNOWLEDGR_GENESIS_TIME"] = KNOWLEDGR_GENESIS_TIME;
   result["KNOWLEDGR_HARDFORK_REQUIRED_WITNESSES"] = KNOWLEDGR_HARDFORK_REQUIRED_WITNESSES;
   result["KNOWLEDGR_INFLATION_NARROWING_PERIOD"] = KNOWLEDGR_INFLATION_NARROWING_PERIOD;
   result["KNOWLEDGR_INFLATION_RATE_START_PERCENT"] = KNOWLEDGR_INFLATION_RATE_START_PERCENT;
   result["KNOWLEDGR_INFLATION_RATE_STOP_PERCENT"] = KNOWLEDGR_INFLATION_RATE_STOP_PERCENT;
   result["KNOWLEDGR_INIT_MINER_NAME"] = KNOWLEDGR_INIT_MINER_NAME;
   result["KNOWLEDGR_INIT_PUBLIC_KEY_STR"] = KNOWLEDGR_INIT_PUBLIC_KEY_STR;
#if 0
   // do not expose private key, period.
   // we need this line present but inactivated so CI check for all constants in config.hpp doesn't complain.
   result["KNOWLEDGR_INIT_PRIVATE_KEY"] = KNOWLEDGR_INIT_PRIVATE_KEY;
#endif
   result["KNOWLEDGR_INIT_SUPPLY"] = KNOWLEDGR_INIT_SUPPLY;
   result["KNOWLEDGR_INIT_TIME"] = KNOWLEDGR_INIT_TIME;
   result["KNOWLEDGR_IRREVERSIBLE_THRESHOLD"] = KNOWLEDGR_IRREVERSIBLE_THRESHOLD;
   result["KNOWLEDGR_LIQUIDITY_APR_PERCENT"] = KNOWLEDGR_LIQUIDITY_APR_PERCENT;
   result["KNOWLEDGR_LIQUIDITY_REWARD_BLOCKS"] = KNOWLEDGR_LIQUIDITY_REWARD_BLOCKS;
   result["KNOWLEDGR_LIQUIDITY_REWARD_PERIOD_SEC"] = KNOWLEDGR_LIQUIDITY_REWARD_PERIOD_SEC;
   result["KNOWLEDGR_LIQUIDITY_TIMEOUT_SEC"] = KNOWLEDGR_LIQUIDITY_TIMEOUT_SEC;
   result["KNOWLEDGR_MAX_ACCOUNT_CREATION_FEE"] = KNOWLEDGR_MAX_ACCOUNT_CREATION_FEE;
   result["KNOWLEDGR_MAX_ACCOUNT_NAME_LENGTH"] = KNOWLEDGR_MAX_ACCOUNT_NAME_LENGTH;
   result["KNOWLEDGR_MAX_ACCOUNT_WITNESS_VOTES"] = KNOWLEDGR_MAX_ACCOUNT_WITNESS_VOTES;
   result["KNOWLEDGR_MAX_ASSET_WHITELIST_AUTHORITIES"] = KNOWLEDGR_MAX_ASSET_WHITELIST_AUTHORITIES;
   result["KNOWLEDGR_MAX_AUTHORITY_MEMBERSHIP"] = KNOWLEDGR_MAX_AUTHORITY_MEMBERSHIP;
   result["KNOWLEDGR_MAX_BLOCK_SIZE"] = KNOWLEDGR_MAX_BLOCK_SIZE;
   result["KNOWLEDGR_SOFT_MAX_BLOCK_SIZE"] = KNOWLEDGR_SOFT_MAX_BLOCK_SIZE;
   result["KNOWLEDGR_MAX_CASHOUT_WINDOW_SECONDS"] = KNOWLEDGR_MAX_CASHOUT_WINDOW_SECONDS;
   result["KNOWLEDGR_MAX_COMMENT_DEPTH"] = KNOWLEDGR_MAX_COMMENT_DEPTH;
   result["KNOWLEDGR_MAX_COMMENT_DEPTH_PRE_HF17"] = KNOWLEDGR_MAX_COMMENT_DEPTH_PRE_HF17;
   result["KNOWLEDGR_MAX_FEED_AGE_SECONDS"] = KNOWLEDGR_MAX_FEED_AGE_SECONDS;
   result["KNOWLEDGR_MAX_INSTANCE_ID"] = KNOWLEDGR_MAX_INSTANCE_ID;
   result["KNOWLEDGR_MAX_MEMO_SIZE"] = KNOWLEDGR_MAX_MEMO_SIZE;
   result["KNOWLEDGR_MAX_WITNESSES"] = KNOWLEDGR_MAX_WITNESSES;
   result["KNOWLEDGR_MAX_MINER_WITNESSES_HF0"] = KNOWLEDGR_MAX_MINER_WITNESSES_HF0;
   result["KNOWLEDGR_MAX_MINER_WITNESSES_HF17"] = KNOWLEDGR_MAX_MINER_WITNESSES_HF17;
   result["KNOWLEDGR_MAX_PERMLINK_LENGTH"] = KNOWLEDGR_MAX_PERMLINK_LENGTH;
   result["KNOWLEDGR_MAX_PROXY_RECURSION_DEPTH"] = KNOWLEDGR_MAX_PROXY_RECURSION_DEPTH;
   result["KNOWLEDGR_MAX_RATION_DECAY_RATE"] = KNOWLEDGR_MAX_RATION_DECAY_RATE;
   result["KNOWLEDGR_MAX_RESERVE_RATIO"] = KNOWLEDGR_MAX_RESERVE_RATIO;
   result["KNOWLEDGR_MAX_RUNNER_WITNESSES_HF0"] = KNOWLEDGR_MAX_RUNNER_WITNESSES_HF0;
   result["KNOWLEDGR_MAX_RUNNER_WITNESSES_HF17"] = KNOWLEDGR_MAX_RUNNER_WITNESSES_HF17;
   result["KNOWLEDGR_MAX_SATOSHIS"] = KNOWLEDGR_MAX_SATOSHIS;
   result["KNOWLEDGR_MAX_SHARE_SUPPLY"] = KNOWLEDGR_MAX_SHARE_SUPPLY;
   result["KNOWLEDGR_MAX_SIG_CHECK_DEPTH"] = KNOWLEDGR_MAX_SIG_CHECK_DEPTH;
   result["KNOWLEDGR_MAX_SIG_CHECK_ACCOUNTS"] = KNOWLEDGR_MAX_SIG_CHECK_ACCOUNTS;
   result["KNOWLEDGR_MAX_TIME_UNTIL_EXPIRATION"] = KNOWLEDGR_MAX_TIME_UNTIL_EXPIRATION;
   result["KNOWLEDGR_MAX_TRANSACTION_SIZE"] = KNOWLEDGR_MAX_TRANSACTION_SIZE;
   result["KNOWLEDGR_MAX_UNDO_HISTORY"] = KNOWLEDGR_MAX_UNDO_HISTORY;
   result["KNOWLEDGR_MAX_URL_LENGTH"] = KNOWLEDGR_MAX_URL_LENGTH;
   result["KNOWLEDGR_MAX_VOTE_CHANGES"] = KNOWLEDGR_MAX_VOTE_CHANGES;
   result["KNOWLEDGR_MAX_VOTED_WITNESSES_HF0"] = KNOWLEDGR_MAX_VOTED_WITNESSES_HF0;
   result["KNOWLEDGR_MAX_VOTED_WITNESSES_HF17"] = KNOWLEDGR_MAX_VOTED_WITNESSES_HF17;
   result["KNOWLEDGR_MAX_WITHDRAW_ROUTES"] = KNOWLEDGR_MAX_WITHDRAW_ROUTES;
   result["KNOWLEDGR_MAX_WITNESS_URL_LENGTH"] = KNOWLEDGR_MAX_WITNESS_URL_LENGTH;
   result["KNOWLEDGR_MIN_ACCOUNT_CREATION_FEE"] = KNOWLEDGR_MIN_ACCOUNT_CREATION_FEE;
   result["KNOWLEDGR_MIN_ACCOUNT_NAME_LENGTH"] = KNOWLEDGR_MIN_ACCOUNT_NAME_LENGTH;
   result["KNOWLEDGR_MIN_BLOCK_SIZE_LIMIT"] = KNOWLEDGR_MIN_BLOCK_SIZE_LIMIT;
   result["KNOWLEDGR_MIN_BLOCK_SIZE"] = KNOWLEDGR_MIN_BLOCK_SIZE;
   result["KNOWLEDGR_MIN_CONTENT_REWARD"] = KNOWLEDGR_MIN_CONTENT_REWARD;
   result["KNOWLEDGR_MIN_CURATE_REWARD"] = KNOWLEDGR_MIN_CURATE_REWARD;
   result["KNOWLEDGR_MIN_PERMLINK_LENGTH"] = KNOWLEDGR_MIN_PERMLINK_LENGTH;
   result["KNOWLEDGR_MIN_REPLY_INTERVAL"] = KNOWLEDGR_MIN_REPLY_INTERVAL;
   result["KNOWLEDGR_MIN_REPLY_INTERVAL_HF20"] = KNOWLEDGR_MIN_REPLY_INTERVAL_HF20;
   result["KNOWLEDGR_MIN_ROOT_COMMENT_INTERVAL"] = KNOWLEDGR_MIN_ROOT_COMMENT_INTERVAL;
   result["KNOWLEDGR_MIN_VOTE_INTERVAL_SEC"] = KNOWLEDGR_MIN_VOTE_INTERVAL_SEC;
   result["KNOWLEDGR_MINER_ACCOUNT"] = KNOWLEDGR_MINER_ACCOUNT;
   result["KNOWLEDGR_MINER_PAY_PERCENT"] = KNOWLEDGR_MINER_PAY_PERCENT;
   result["KNOWLEDGR_MIN_FEEDS"] = KNOWLEDGR_MIN_FEEDS;
   result["KNOWLEDGR_MINING_REWARD"] = KNOWLEDGR_MINING_REWARD;
   result["KNOWLEDGR_MINING_TIME"] = KNOWLEDGR_MINING_TIME;
   result["KNOWLEDGR_MIN_LIQUIDITY_REWARD"] = KNOWLEDGR_MIN_LIQUIDITY_REWARD;
   result["KNOWLEDGR_MIN_LIQUIDITY_REWARD_PERIOD_SEC"] = KNOWLEDGR_MIN_LIQUIDITY_REWARD_PERIOD_SEC;
   result["KNOWLEDGR_MIN_PAYOUT_SBD"] = KNOWLEDGR_MIN_PAYOUT_SBD;
   result["KNOWLEDGR_MIN_POW_REWARD"] = KNOWLEDGR_MIN_POW_REWARD;
   result["KNOWLEDGR_MIN_PRODUCER_REWARD"] = KNOWLEDGR_MIN_PRODUCER_REWARD;
   result["KNOWLEDGR_MIN_TRANSACTION_EXPIRATION_LIMIT"] = KNOWLEDGR_MIN_TRANSACTION_EXPIRATION_LIMIT;
   result["KNOWLEDGR_MIN_TRANSACTION_SIZE_LIMIT"] = KNOWLEDGR_MIN_TRANSACTION_SIZE_LIMIT;
   result["KNOWLEDGR_MIN_UNDO_HISTORY"] = KNOWLEDGR_MIN_UNDO_HISTORY;
   result["KNOWLEDGR_NULL_ACCOUNT"] = KNOWLEDGR_NULL_ACCOUNT;
   result["KNOWLEDGR_NUM_INIT_MINERS"] = KNOWLEDGR_NUM_INIT_MINERS;
   result["KNOWLEDGR_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM"] = KNOWLEDGR_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM;
   result["KNOWLEDGR_OWNER_AUTH_RECOVERY_PERIOD"] = KNOWLEDGR_OWNER_AUTH_RECOVERY_PERIOD;
   result["KNOWLEDGR_OWNER_CHALLENGE_COOLDOWN"] = KNOWLEDGR_OWNER_CHALLENGE_COOLDOWN;
   result["KNOWLEDGR_OWNER_CHALLENGE_FEE"] = KNOWLEDGR_OWNER_CHALLENGE_FEE;
   result["KNOWLEDGR_OWNER_UPDATE_LIMIT"] = KNOWLEDGR_OWNER_UPDATE_LIMIT;
   result["KNOWLEDGR_POST_AVERAGE_WINDOW"] = KNOWLEDGR_POST_AVERAGE_WINDOW;
   result["KNOWLEDGR_POST_REWARD_FUND_NAME"] = KNOWLEDGR_POST_REWARD_FUND_NAME;
   result["KNOWLEDGR_POST_WEIGHT_CONSTANT"] = KNOWLEDGR_POST_WEIGHT_CONSTANT;
   result["KNOWLEDGR_POW_APR_PERCENT"] = KNOWLEDGR_POW_APR_PERCENT;
   result["KNOWLEDGR_PRODUCER_APR_PERCENT"] = KNOWLEDGR_PRODUCER_APR_PERCENT;
   result["KNOWLEDGR_PROXY_TO_SELF_ACCOUNT"] = KNOWLEDGR_PROXY_TO_SELF_ACCOUNT;
   result["KNOWLEDGR_SBD_INTEREST_COMPOUND_INTERVAL_SEC"] = KNOWLEDGR_SBD_INTEREST_COMPOUND_INTERVAL_SEC;
   result["KNOWLEDGR_SECONDS_PER_YEAR"] = KNOWLEDGR_SECONDS_PER_YEAR;
   result["KNOWLEDGR_RECENT_RSHARES_DECAY_TIME_HF19"] = KNOWLEDGR_RECENT_RSHARES_DECAY_TIME_HF19;
   result["KNOWLEDGR_RECENT_RSHARES_DECAY_TIME_HF17"] = KNOWLEDGR_RECENT_RSHARES_DECAY_TIME_HF17;
   result["KNOWLEDGR_REVERSE_AUCTION_WINDOW_SECONDS_HF6"] = KNOWLEDGR_REVERSE_AUCTION_WINDOW_SECONDS_HF6;
   result["KNOWLEDGR_REVERSE_AUCTION_WINDOW_SECONDS_HF20"] = KNOWLEDGR_REVERSE_AUCTION_WINDOW_SECONDS_HF20;
   result["KNOWLEDGR_ROOT_POST_PARENT"] = KNOWLEDGR_ROOT_POST_PARENT;
   result["KNOWLEDGR_SAVINGS_WITHDRAW_REQUEST_LIMIT"] = KNOWLEDGR_SAVINGS_WITHDRAW_REQUEST_LIMIT;
   result["KNOWLEDGR_SAVINGS_WITHDRAW_TIME"] = KNOWLEDGR_SAVINGS_WITHDRAW_TIME;
   result["KNOWLEDGR_SBD_START_PERCENT_HF14"] = KNOWLEDGR_SBD_START_PERCENT_HF14;
   result["KNOWLEDGR_SBD_START_PERCENT_HF20"] = KNOWLEDGR_SBD_START_PERCENT_HF20;
   result["KNOWLEDGR_SBD_STOP_PERCENT_HF14"] = KNOWLEDGR_SBD_STOP_PERCENT_HF14;
   result["KNOWLEDGR_SBD_STOP_PERCENT_HF20"] = KNOWLEDGR_SBD_STOP_PERCENT_HF20;
   result["KNOWLEDGR_SECOND_CASHOUT_WINDOW"] = KNOWLEDGR_SECOND_CASHOUT_WINDOW;
   result["KNOWLEDGR_SOFT_MAX_COMMENT_DEPTH"] = KNOWLEDGR_SOFT_MAX_COMMENT_DEPTH;
   result["KNOWLEDGR_START_MINER_VOTING_BLOCK"] = KNOWLEDGR_START_MINER_VOTING_BLOCK;
   result["KNOWLEDGR_START_VESTING_BLOCK"] = KNOWLEDGR_START_VESTING_BLOCK;
   result["KNOWLEDGR_TEMP_ACCOUNT"] = KNOWLEDGR_TEMP_ACCOUNT;
   result["KNOWLEDGR_UPVOTE_LOCKOUT_HF7"] = KNOWLEDGR_UPVOTE_LOCKOUT_HF7;
   result["KNOWLEDGR_UPVOTE_LOCKOUT_HF17"] = KNOWLEDGR_UPVOTE_LOCKOUT_HF17;
   result["KNOWLEDGR_UPVOTE_LOCKOUT_SECONDS"] = KNOWLEDGR_UPVOTE_LOCKOUT_SECONDS;
   result["KNOWLEDGR_VESTING_FUND_PERCENT"] = KNOWLEDGR_VESTING_FUND_PERCENT;
   result["KNOWLEDGR_VESTING_WITHDRAW_INTERVALS"] = KNOWLEDGR_VESTING_WITHDRAW_INTERVALS;
   result["KNOWLEDGR_VESTING_WITHDRAW_INTERVALS_PRE_HF_16"] = KNOWLEDGR_VESTING_WITHDRAW_INTERVALS_PRE_HF_16;
   result["KNOWLEDGR_VESTING_WITHDRAW_INTERVAL_SECONDS"] = KNOWLEDGR_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["KNOWLEDGR_VOTE_DUST_THRESHOLD"] = KNOWLEDGR_VOTE_DUST_THRESHOLD;
   result["KNOWLEDGR_VOTING_MANA_REGENERATION_SECONDS"] = KNOWLEDGR_VOTING_MANA_REGENERATION_SECONDS;
   result["KNLG_SYMBOL"] = KNLG_SYMBOL;
   result["VESTS_SYMBOL"] = VESTS_SYMBOL;
   result["KNOWLEDGR_VIRTUAL_SCHEDULE_LAP_LENGTH"] = KNOWLEDGR_VIRTUAL_SCHEDULE_LAP_LENGTH;
   result["KNOWLEDGR_VIRTUAL_SCHEDULE_LAP_LENGTH2"] = KNOWLEDGR_VIRTUAL_SCHEDULE_LAP_LENGTH2;
   result["KNOWLEDGR_MAX_LIMIT_ORDER_EXPIRATION"] = KNOWLEDGR_MAX_LIMIT_ORDER_EXPIRATION;
   result["KNOWLEDGR_DELEGATION_RETURN_PERIOD_HF0"] = KNOWLEDGR_DELEGATION_RETURN_PERIOD_HF0;
   result["KNOWLEDGR_DELEGATION_RETURN_PERIOD_HF20"] = KNOWLEDGR_DELEGATION_RETURN_PERIOD_HF20;
   result["KNOWLEDGR_RD_MIN_DECAY_BITS"] = KNOWLEDGR_RD_MIN_DECAY_BITS;
   result["KNOWLEDGR_RD_MAX_DECAY_BITS"] = KNOWLEDGR_RD_MAX_DECAY_BITS;
   result["KNOWLEDGR_RD_DECAY_DENOM_SHIFT"] = KNOWLEDGR_RD_DECAY_DENOM_SHIFT;
   result["KNOWLEDGR_RD_MAX_POOL_BITS"] = KNOWLEDGR_RD_MAX_POOL_BITS;
   result["KNOWLEDGR_RD_MAX_BUDGET_1"] = KNOWLEDGR_RD_MAX_BUDGET_1;
   result["KNOWLEDGR_RD_MAX_BUDGET_2"] = KNOWLEDGR_RD_MAX_BUDGET_2;
   result["KNOWLEDGR_RD_MAX_BUDGET_3"] = KNOWLEDGR_RD_MAX_BUDGET_3;
   result["KNOWLEDGR_RD_MAX_BUDGET"] = KNOWLEDGR_RD_MAX_BUDGET;
   result["KNOWLEDGR_RD_MIN_DECAY"] = KNOWLEDGR_RD_MIN_DECAY;
   result["KNOWLEDGR_RD_MIN_BUDGET"] = KNOWLEDGR_RD_MIN_BUDGET;
   result["KNOWLEDGR_RD_MAX_DECAY"] = KNOWLEDGR_RD_MAX_DECAY;
   result["KNOWLEDGR_ACCOUNT_SUBSIDY_PRECISION"] = KNOWLEDGR_ACCOUNT_SUBSIDY_PRECISION;
   result["KNOWLEDGR_WITNESS_SUBSIDY_BUDGET_PERCENT"] = KNOWLEDGR_WITNESS_SUBSIDY_BUDGET_PERCENT;
   result["KNOWLEDGR_WITNESS_SUBSIDY_DECAY_PERCENT"] = KNOWLEDGR_WITNESS_SUBSIDY_DECAY_PERCENT;
   result["KNOWLEDGR_DEFAULT_ACCOUNT_SUBSIDY_DECAY"] = KNOWLEDGR_DEFAULT_ACCOUNT_SUBSIDY_DECAY;
   result["KNOWLEDGR_DEFAULT_ACCOUNT_SUBSIDY_BUDGET"] = KNOWLEDGR_DEFAULT_ACCOUNT_SUBSIDY_BUDGET;
   result["KNOWLEDGR_DECAY_BACKSTOP_PERCENT"] = KNOWLEDGR_DECAY_BACKSTOP_PERCENT;

   return result;
}

} } // knowledgr::protocol
