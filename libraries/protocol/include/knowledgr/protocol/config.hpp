/*
 * Copyright (c) 2016 Knowledgrit, Inc., and contributors.
 */
#pragma once
#include <knowledgr/protocol/hardfork.hpp>

// WARNING!
// Every symbol defined here needs to be handled appropriately in get_config.cpp
// This is checked by get_config_check.sh called from Dockerfile

#ifdef IS_TEST_NET
#define KNOWLEDGR_BLOCKCHAIN_VERSION              ( version(0, 21, 0) )

#define KNOWLEDGR_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define KNOWLEDGR_INIT_PUBLIC_KEY_STR             (std::string( knowledgr::protocol::public_key_type(KNOWLEDGR_INIT_PRIVATE_KEY.get_public_key()) ))
#define KNOWLEDGR_CHAIN_ID (fc::sha256::hash("testnet"))
#define KNOWLEDGR_ADDRESS_PREFIX                  "TST"

#define KNOWLEDGR_GENESIS_TIME                    (fc::time_point_sec(1451606400))
#define KNOWLEDGR_MINING_TIME                     (fc::time_point_sec(1451606400))
#define KNOWLEDGR_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define KNOWLEDGR_CASHOUT_WINDOW_SECONDS_PRE_HF12 (KNOWLEDGR_CASHOUT_WINDOW_SECONDS)
#define KNOWLEDGR_CASHOUT_WINDOW_SECONDS_PRE_HF17 (KNOWLEDGR_CASHOUT_WINDOW_SECONDS)
#define KNOWLEDGR_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define KNOWLEDGR_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define KNOWLEDGR_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define KNOWLEDGR_UPVOTE_LOCKOUT_SECONDS          (60*5)    /// 5 minutes
#define KNOWLEDGR_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define KNOWLEDGR_MIN_ACCOUNT_CREATION_FEE          0
#define KNOWLEDGR_MAX_ACCOUNT_CREATION_FEE          int64_t(1000000000)

#define KNOWLEDGR_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define KNOWLEDGR_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define KNOWLEDGR_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define KNOWLEDGR_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1

#define KNOWLEDGR_INIT_SUPPLY                     (int64_t( 250 ) * int64_t( 1000000 ) * int64_t( 1000 ))

/// Allows to limit number of total produced blocks.
#define TESTNET_BLOCK_LIMIT                   (3000000)

#else // IS LIVE KNOWLEDGR NETWORK

#define KNOWLEDGR_BLOCKCHAIN_VERSION              ( version(0, 20, 6) )

#define KNOWLEDGR_INIT_PUBLIC_KEY_STR             "KWR6YegkQ1bqQ3jzMdA87ekWBr4bFcUwc12hkVD5tWipVNXA1b14J"
#define KNOWLEDGR_CHAIN_ID 							(fc::sha256::hash("Knowledgr Chain"))
#define KNOWLEDGR_ADDRESS_PREFIX                  "KWR"

#define KNOWLEDGR_GENESIS_TIME                    (fc::time_point_sec(1458835200))
#define KNOWLEDGR_MINING_TIME                     (fc::time_point_sec(1458838800))
#define KNOWLEDGR_CASHOUT_WINDOW_SECONDS_PRE_HF12 300///(60*60*24)    /// 1 day
#define KNOWLEDGR_CASHOUT_WINDOW_SECONDS_PRE_HF17 300///(60*60*12)    /// 12 hours
#define KNOWLEDGR_CASHOUT_WINDOW_SECONDS          300///(60*60*24*7)  /// 7 days
#define KNOWLEDGR_SECOND_CASHOUT_WINDOW           300///(60*60*24*30) /// 30 days
#define KNOWLEDGR_MAX_CASHOUT_WINDOW_SECONDS      600///(60*60*24*14) /// 2 weeks
#define KNOWLEDGR_UPVOTE_LOCKOUT_HF7              90///(fc::minutes(1))
#define KNOWLEDGR_UPVOTE_LOCKOUT_SECONDS          90///(60*60*12)    /// 12 hours
#define KNOWLEDGR_UPVOTE_LOCKOUT_HF17             90///(fc::hours(12))

#define KNOWLEDGR_MIN_ACCOUNT_CREATION_FEE           1
#define KNOWLEDGR_MAX_ACCOUNT_CREATION_FEE           int64_t(1000000000)

#define KNOWLEDGR_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define KNOWLEDGR_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define KNOWLEDGR_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define KNOWLEDGR_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 3186477

#define KNOWLEDGR_INIT_SUPPLY                     int64_t(0)

#endif

#define VESTS_SYMBOL  (knowledgr::protocol::asset_symbol_type::from_asset_num( KNOWLEDGR_ASSET_NUM_VESTS ) )
#define NLG_SYMBOL  (knowledgr::protocol::asset_symbol_type::from_asset_num( KNOWLEDGR_ASSET_NUM_NLG))
#define SBD_SYMBOL    (knowledgr::protocol::asset_symbol_type::from_asset_num( KNOWLEDGR_ASSET_NUM_SBD ) )

#define KNOWLEDGR_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( KNOWLEDGR_BLOCKCHAIN_VERSION ) )

#define KNOWLEDGR_BLOCK_INTERVAL                  3
#define KNOWLEDGR_BLOCKS_PER_YEAR                 (365*24*60*60/KNOWLEDGR_BLOCK_INTERVAL)
#define KNOWLEDGR_BLOCKS_PER_DAY                  (24*60*60/KNOWLEDGR_BLOCK_INTERVAL)
#define KNOWLEDGR_START_VESTING_BLOCK             (KNOWLEDGR_BLOCKS_PER_DAY * 7)
#define KNOWLEDGR_START_MINER_VOTING_BLOCK        (KNOWLEDGR_BLOCKS_PER_DAY * 30)

#define KNOWLEDGR_INIT_MINER_NAME                 "initminer"
#define KNOWLEDGR_NUM_INIT_MINERS                 1
#define KNOWLEDGR_INIT_TIME                       (fc::time_point_sec());

#define KNOWLEDGR_MAX_WITNESSES                   21

#define KNOWLEDGR_MAX_VOTED_WITNESSES_HF0         19
#define KNOWLEDGR_MAX_MINER_WITNESSES_HF0         1
#define KNOWLEDGR_MAX_RUNNER_WITNESSES_HF0        1

#define KNOWLEDGR_MAX_VOTED_WITNESSES_HF17        20
#define KNOWLEDGR_MAX_MINER_WITNESSES_HF17        0
#define KNOWLEDGR_MAX_RUNNER_WITNESSES_HF17       1

#define KNOWLEDGR_HARDFORK_REQUIRED_WITNESSES     17 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define KNOWLEDGR_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define KNOWLEDGR_MAX_MEMO_SIZE                   2048
#define KNOWLEDGR_MAX_PROXY_RECURSION_DEPTH       4
#define KNOWLEDGR_VESTING_WITHDRAW_INTERVALS_PRE_HF_16 104
#define KNOWLEDGR_VESTING_WITHDRAW_INTERVALS      13
#define KNOWLEDGR_VESTING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval
#define KNOWLEDGR_MAX_WITHDRAW_ROUTES             10
#define KNOWLEDGR_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
#define KNOWLEDGR_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define KNOWLEDGR_VOTING_MANA_REGENERATION_SECONDS (5*60*60*24) // 5 day
#define KNOWLEDGR_MAX_VOTE_CHANGES                5
#define KNOWLEDGR_REVERSE_AUCTION_WINDOW_SECONDS_HF6 (60*30) /// 30 minutes
#define KNOWLEDGR_REVERSE_AUCTION_WINDOW_SECONDS_HF20 (60*15) /// 15 minutes
#define KNOWLEDGR_MIN_VOTE_INTERVAL_SEC           3
#define KNOWLEDGR_VOTE_DUST_THRESHOLD             (50000000)

#define KNOWLEDGR_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define KNOWLEDGR_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
#define KNOWLEDGR_MIN_REPLY_INTERVAL_HF20         (fc::seconds(3)) // 3 seconds
#define KNOWLEDGR_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
#define KNOWLEDGR_POST_WEIGHT_CONSTANT            (uint64_t(4*KNOWLEDGR_100_PERCENT) * (4*KNOWLEDGR_100_PERCENT))// (4*KNOWLEDGR_100_PERCENT) -> 2 posts per 1 days, average 1 every 12 hours

#define KNOWLEDGR_MAX_ACCOUNT_WITNESS_VOTES       30

#define KNOWLEDGR_100_PERCENT                     10000
#define KNOWLEDGR_1_PERCENT                       (KNOWLEDGR_100_PERCENT/100)
#define KNOWLEDGR_DEFAULT_SBD_INTEREST_RATE       (10*KNOWLEDGR_1_PERCENT) ///< 10% APR

#define KNOWLEDGR_INFLATION_RATE_START_PERCENT    (978) // Fixes block 7,000,000 to 9.5%
#define KNOWLEDGR_INFLATION_RATE_STOP_PERCENT     (95) // 0.95%
#define KNOWLEDGR_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define KNOWLEDGR_CONTENT_REWARD_PERCENT          (75*KNOWLEDGR_1_PERCENT) //75% of inflation, 7.125% inflation
#define KNOWLEDGR_VESTING_FUND_PERCENT            (15*KNOWLEDGR_1_PERCENT) //15% of inflation, 1.425% inflation

#define KNOWLEDGR_MINER_PAY_PERCENT               (KNOWLEDGR_1_PERCENT) // 1%
#define KNOWLEDGR_MAX_RATION_DECAY_RATE           (1000000)

#define KNOWLEDGR_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define KNOWLEDGR_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define KNOWLEDGR_MAX_COMMENT_DEPTH_PRE_HF17      6
#define KNOWLEDGR_MAX_COMMENT_DEPTH               0xffff // 64k
#define KNOWLEDGR_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define KNOWLEDGR_MAX_RESERVE_RATIO               (20000)

#define KNOWLEDGR_CREATE_ACCOUNT_WITH_KNOWLEDGR_MODIFIER 30
#define KNOWLEDGR_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define KNOWLEDGR_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define KNOWLEDGR_MINING_REWARD                   asset( 1000, NLG_SYMBOL )
#define KNOWLEDGR_EQUIHASH_N                      140
#define KNOWLEDGR_EQUIHASH_K                      6

#define KNOWLEDGR_LIQUIDITY_TIMEOUT_SEC           (fc::seconds(60*60*24*7)) // After one week volume is set to 0
#define KNOWLEDGR_MIN_LIQUIDITY_REWARD_PERIOD_SEC (fc::seconds(60)) // 1 minute required on books to receive volume
#define KNOWLEDGR_LIQUIDITY_REWARD_PERIOD_SEC     (60*60)
#define KNOWLEDGR_LIQUIDITY_REWARD_BLOCKS         (KNOWLEDGR_LIQUIDITY_REWARD_PERIOD_SEC/KNOWLEDGR_BLOCK_INTERVAL)
#define KNOWLEDGR_MIN_LIQUIDITY_REWARD            (asset( 1000*KNOWLEDGR_LIQUIDITY_REWARD_BLOCKS, NLG_SYMBOL )) // Minumum reward to be paid out to liquidity providers
#define KNOWLEDGR_MIN_CONTENT_REWARD              KNOWLEDGR_MINING_REWARD
#define KNOWLEDGR_MIN_CURATE_REWARD               KNOWLEDGR_MINING_REWARD
#define KNOWLEDGR_MIN_PRODUCER_REWARD             KNOWLEDGR_MINING_REWARD
#define KNOWLEDGR_MIN_POW_REWARD                  KNOWLEDGR_MINING_REWARD

#define KNOWLEDGR_ACTIVE_CHALLENGE_FEE            asset( 2000, NLG_SYMBOL )
#define KNOWLEDGR_OWNER_CHALLENGE_FEE             asset( 30000, NLG_SYMBOL )
#define KNOWLEDGR_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define KNOWLEDGR_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

#define KNOWLEDGR_POST_REWARD_FUND_NAME           ("post")
#define KNOWLEDGR_COMMENT_REWARD_FUND_NAME        ("comment")
#define KNOWLEDGR_RECENT_RSHARES_DECAY_TIME_HF17    (fc::days(30))
#define KNOWLEDGR_RECENT_RSHARES_DECAY_TIME_HF19    (fc::days(15))
#define KNOWLEDGR_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))
// note, if redefining these constants make sure calculate_claims doesn't overflow

// 5ccc e802 de5f
// int(expm1( log1p( 1 ) / BLOCKS_PER_YEAR ) * 2**KNOWLEDGR_APR_PERCENT_SHIFT_PER_BLOCK / 100000 + 0.5)
// we use 100000 here instead of 10000 because we end up creating an additional 9x for vesting
#define KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_BLOCK          ( (uint64_t( 0x5ccc ) << 0x20) \
                                                        | (uint64_t( 0xe802 ) << 0x10) \
                                                        | (uint64_t( 0xde5f )        ) \
                                                        )
// chosen to be the maximal value such that KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_BLOCK * 2**64 * 100000 < 2**128
#define KNOWLEDGR_APR_PERCENT_SHIFT_PER_BLOCK             87

#define KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_ROUND          ( (uint64_t( 0x79cc ) << 0x20 ) \
                                                        | (uint64_t( 0xf5c7 ) << 0x10 ) \
                                                        | (uint64_t( 0x3480 )         ) \
                                                        )

#define KNOWLEDGR_APR_PERCENT_SHIFT_PER_ROUND             83

// We have different constants for hourly rewards
// i.e. hex(int(math.expm1( math.log1p( 1 ) / HOURS_PER_YEAR ) * 2**KNOWLEDGR_APR_PERCENT_SHIFT_PER_HOUR / 100000 + 0.5))
#define KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_HOUR           ( (uint64_t( 0x6cc1 ) << 0x20) \
                                                        | (uint64_t( 0x39a1 ) << 0x10) \
                                                        | (uint64_t( 0x5cbd )        ) \
                                                        )

// chosen to be the maximal value such that KNOWLEDGR_APR_PERCENT_MULTIPLY_PER_HOUR * 2**64 * 100000 < 2**128
#define KNOWLEDGR_APR_PERCENT_SHIFT_PER_HOUR              77

// These constants add up to GRAPHENE_100_PERCENT.  Each GRAPHENE_1_PERCENT is equivalent to 1% per year APY
// *including the corresponding 9x vesting rewards*
#define KNOWLEDGR_CURATE_APR_PERCENT              3875
#define KNOWLEDGR_CONTENT_APR_PERCENT             3875
#define KNOWLEDGR_LIQUIDITY_APR_PERCENT            750
#define KNOWLEDGR_PRODUCER_APR_PERCENT             750
#define KNOWLEDGR_POW_APR_PERCENT                  750

#define KNOWLEDGR_MIN_PAYOUT_SBD                  (asset(20,SBD_SYMBOL))

#define KNOWLEDGR_SBD_STOP_PERCENT_HF14           (5*KNOWLEDGR_1_PERCENT ) // Stop printing SBD at 5% Market Cap
#define KNOWLEDGR_SBD_STOP_PERCENT_HF20           (10*KNOWLEDGR_1_PERCENT ) // Stop printing SBD at 10% Market Cap
#define KNOWLEDGR_SBD_START_PERCENT_HF14          (2*KNOWLEDGR_1_PERCENT) // Start reducing printing of SBD at 2% Market Cap
#define KNOWLEDGR_SBD_START_PERCENT_HF20          (9*KNOWLEDGR_1_PERCENT) // Start reducing printing of SBD at 9% Market Cap

#define KNOWLEDGR_MIN_ACCOUNT_NAME_LENGTH          3
#define KNOWLEDGR_MAX_ACCOUNT_NAME_LENGTH         16

#define KNOWLEDGR_MIN_PERMLINK_LENGTH             0
#define KNOWLEDGR_MAX_PERMLINK_LENGTH             256
#define KNOWLEDGR_MAX_WITNESS_URL_LENGTH          2048

#define KNOWLEDGR_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define KNOWLEDGR_MAX_SATOSHIS                    int64_t(4611686018427387903ll)
#define KNOWLEDGR_MAX_SIG_CHECK_DEPTH             2
#define KNOWLEDGR_MAX_SIG_CHECK_ACCOUNTS          125

#define KNOWLEDGR_MIN_TRANSACTION_SIZE_LIMIT      1024
#define KNOWLEDGR_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define KNOWLEDGR_SBD_INTEREST_COMPOUND_INTERVAL_SEC  (60*60*24*30)
#define KNOWLEDGR_MAX_TRANSACTION_SIZE            (1024*64)
#define KNOWLEDGR_MIN_BLOCK_SIZE_LIMIT            (KNOWLEDGR_MAX_TRANSACTION_SIZE)
#define KNOWLEDGR_MAX_BLOCK_SIZE                  (KNOWLEDGR_MAX_TRANSACTION_SIZE*KNOWLEDGR_BLOCK_INTERVAL*2000)
#define KNOWLEDGR_SOFT_MAX_BLOCK_SIZE             (2*1024*1024)
#define KNOWLEDGR_MIN_BLOCK_SIZE                  115
#define KNOWLEDGR_BLOCKS_PER_HOUR                 (60*60/KNOWLEDGR_BLOCK_INTERVAL)
#define KNOWLEDGR_FEED_INTERVAL_BLOCKS            (KNOWLEDGR_BLOCKS_PER_HOUR)
#define KNOWLEDGR_FEED_HISTORY_WINDOW_PRE_HF_16   (24*7) /// 7 days * 24 hours per day
#define KNOWLEDGR_FEED_HISTORY_WINDOW             (12*7) // 3.5 days
#define KNOWLEDGR_MAX_FEED_AGE_SECONDS            (60*60*24*7) // 7 days
#define KNOWLEDGR_MIN_FEEDS                       (KNOWLEDGR_MAX_WITNESSES/3) /// protects the network from conversions before price has been established
#define KNOWLEDGR_CONVERSION_DELAY_PRE_HF_16      (fc::days(7))
#define KNOWLEDGR_CONVERSION_DELAY                (fc::hours(KNOWLEDGR_FEED_HISTORY_WINDOW)) //3.5 day conversion

#define KNOWLEDGR_MIN_UNDO_HISTORY                10
#define KNOWLEDGR_MAX_UNDO_HISTORY                10000

#define KNOWLEDGR_MIN_TRANSACTION_EXPIRATION_LIMIT (KNOWLEDGR_BLOCK_INTERVAL * 5) // 5 transactions per block
#define KNOWLEDGR_BLOCKCHAIN_PRECISION            uint64_t( 1000 )

#define KNOWLEDGR_BLOCKCHAIN_PRECISION_DIGITS     3
#define KNOWLEDGR_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define KNOWLEDGR_MAX_AUTHORITY_MEMBERSHIP        40
#define KNOWLEDGR_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define KNOWLEDGR_MAX_URL_LENGTH                  127

#define KNOWLEDGR_IRREVERSIBLE_THRESHOLD          (75 * KNOWLEDGR_1_PERCENT)

#define KNOWLEDGR_VIRTUAL_SCHEDULE_LAP_LENGTH  ( fc::uint128(uint64_t(-1)) )
#define KNOWLEDGR_VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

#define KNOWLEDGR_INITIAL_VOTE_POWER_RATE (40)
#define KNOWLEDGR_REDUCED_VOTE_POWER_RATE (10)

#define KNOWLEDGR_MAX_LIMIT_ORDER_EXPIRATION     (60*60*24*28) // 28 days
#define KNOWLEDGR_DELEGATION_RETURN_PERIOD_HF0   (KNOWLEDGR_CASHOUT_WINDOW_SECONDS)
#define KNOWLEDGR_DELEGATION_RETURN_PERIOD_HF20  (KNOWLEDGR_VOTING_MANA_REGENERATION_SECONDS)

#define KNOWLEDGR_RD_MIN_DECAY_BITS               6
#define KNOWLEDGR_RD_MAX_DECAY_BITS              32
#define KNOWLEDGR_RD_DECAY_DENOM_SHIFT           36
#define KNOWLEDGR_RD_MAX_POOL_BITS               64
#define KNOWLEDGR_RD_MAX_BUDGET_1                ((uint64_t(1) << (KNOWLEDGR_RD_MAX_POOL_BITS + KNOWLEDGR_RD_MIN_DECAY_BITS - KNOWLEDGR_RD_DECAY_DENOM_SHIFT))-1)
#define KNOWLEDGR_RD_MAX_BUDGET_2                ((uint64_t(1) << (64-KNOWLEDGR_RD_DECAY_DENOM_SHIFT))-1)
#define KNOWLEDGR_RD_MAX_BUDGET_3                (uint64_t( std::numeric_limits<int32_t>::max() ))
#define KNOWLEDGR_RD_MAX_BUDGET                  (int32_t( std::min( { KNOWLEDGR_RD_MAX_BUDGET_1, KNOWLEDGR_RD_MAX_BUDGET_2, KNOWLEDGR_RD_MAX_BUDGET_3 } )) )
#define KNOWLEDGR_RD_MIN_DECAY                   (uint32_t(1) << KNOWLEDGR_RD_MIN_DECAY_BITS)
#define KNOWLEDGR_RD_MIN_BUDGET                  1
#define KNOWLEDGR_RD_MAX_DECAY                   (uint32_t(0xFFFFFFFF))

#define KNOWLEDGR_ACCOUNT_SUBSIDY_PRECISION      (KNOWLEDGR_100_PERCENT)

// We want the global subsidy to run out first in normal (Poisson)
// conditions, so we boost the per-witness subsidy a little.
#define KNOWLEDGR_WITNESS_SUBSIDY_BUDGET_PERCENT (125 * KNOWLEDGR_1_PERCENT)

// Since witness decay only procs once per round, multiplying the decay
// constant by the number of witnesses means the per-witness pools have
// the same effective decay rate in real-time terms.
#define KNOWLEDGR_WITNESS_SUBSIDY_DECAY_PERCENT  (KNOWLEDGR_MAX_WITNESSES * KNOWLEDGR_100_PERCENT)

// 347321 corresponds to a 5-day halflife
#define KNOWLEDGR_DEFAULT_ACCOUNT_SUBSIDY_DECAY  (347321)
// Default rate is 0.5 accounts per block
#define KNOWLEDGR_DEFAULT_ACCOUNT_SUBSIDY_BUDGET (797)
#define KNOWLEDGR_DECAY_BACKSTOP_PERCENT         (90 * KNOWLEDGR_1_PERCENT)

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define KNOWLEDGR_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define KNOWLEDGR_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define KNOWLEDGR_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define KNOWLEDGR_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define KNOWLEDGR_ROOT_POST_PARENT                (account_name_type())
///@}

#define KNOWLEDGR_STAKE_PROCESS_DELAY				(10 * 60)
#define KNOWLEDGR_NUM_OF_INIT_STAKING_ACCOUNTS		1000///~~~~~NLG~~~~~
#define KNOWLEDGR_LIMIT_STAKING_AMOUNT				asset( 1000000, NLG_SYMBOL )///~~~~~NLG~~~~~
#define KNOWLEDGR_RPOWER_REWARD_PERCENT          (5 * KNOWLEDGR_1_PERCENT)
#define KNOWLEDGR_ADMIN_ACCOUNT1				"admin1"
#define KNOWLEDGR_ADMIN_ACCOUNT2				"admin2"
#define KNOWLEDGR_ADMIN_ACCOUNT3				"admin3"
#define KNOWLEDGR_ADMIN_ACCOUNT4				"admin4"
#define KNOWLEDGR_ADMIN_ACCOUNT5				"admin5"
#define KNOWLEDGR_ADMIN_ACCOUNT1_PUBKEY_STR		"KWR6FpYKEGBx18ZqVAebCPtu7hG8USBW4499H6Sxuooev1PjijGfD"
#define KNOWLEDGR_ADMIN_ACCOUNT2_PUBKEY_STR		"KWR897nE2eNpfBQ8qig3YEXoBjdyJGth4fQUbtMwYQ8sVBU5fWtjc"
#define KNOWLEDGR_ADMIN_ACCOUNT3_PUBKEY_STR		"KWR84wtjcvnnkFKysWjwqM8XrW7Tqr197r3F2qeLfjyqTELeyR4gp"
#define KNOWLEDGR_ADMIN_ACCOUNT4_PUBKEY_STR		"KWR7wxDzt4YTi3JtaVWmyS21vWuTfZisvNJJECavGzhJpR5Mgrr9y"
#define KNOWLEDGR_ADMIN_ACCOUNT5_PUBKEY_STR		"KWR58j6MWs87AvF79EnTfg35AJkBYYHQTWTiob5tz9L6m7uZdttw2"

#ifdef KNOWLEDGR_ENABLE_SMT

#define SMT_MAX_VOTABLE_ASSETS 2
#define SMT_VESTING_WITHDRAW_INTERVAL_SECONDS   (60*60*24*7) /// 1 week per interval
#define SMT_UPVOTE_LOCKOUT                      (60*60*12)  /// 12 hours

#endif /// KNOWLEDGR_ENABLE_SMT

