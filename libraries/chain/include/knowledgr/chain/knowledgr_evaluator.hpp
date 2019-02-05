#pragma once

#include <knowledgr/protocol/knowledgr_operations.hpp>

#include <knowledgr/chain/evaluator.hpp>

namespace knowledgr { namespace chain {

using namespace knowledgr::protocol;

KNOWLEDGR_DEFINE_EVALUATOR( account_create )
KNOWLEDGR_DEFINE_EVALUATOR( account_admin_update ) ///~~~~~NLG~~~~~
KNOWLEDGR_DEFINE_EVALUATOR( account_expertise_update ) ///~~~~~NLG~~~~~
KNOWLEDGR_DEFINE_EVALUATOR( stake_request ) ///~~~~~NLG~~~~~
KNOWLEDGR_DEFINE_EVALUATOR( stake_process ) ///~~~~~NLG~~~~~
//KNOWLEDGR_DEFINE_EVALUATOR( account_create_with_delegation )
KNOWLEDGR_DEFINE_EVALUATOR( account_update )
KNOWLEDGR_DEFINE_EVALUATOR( transfer )
//KNOWLEDGR_DEFINE_EVALUATOR( transfer_to_vesting )
KNOWLEDGR_DEFINE_EVALUATOR( witness_update )
KNOWLEDGR_DEFINE_EVALUATOR( account_witness_vote )
KNOWLEDGR_DEFINE_EVALUATOR( account_witness_proxy )
//KNOWLEDGR_DEFINE_EVALUATOR( withdraw_vesting )
//KNOWLEDGR_DEFINE_EVALUATOR( set_withdraw_vesting_route )
KNOWLEDGR_DEFINE_EVALUATOR( comment )
KNOWLEDGR_DEFINE_EVALUATOR( comment_options )
KNOWLEDGR_DEFINE_EVALUATOR( delete_comment )
KNOWLEDGR_DEFINE_EVALUATOR( vote )
KNOWLEDGR_DEFINE_EVALUATOR( custom )
KNOWLEDGR_DEFINE_EVALUATOR( custom_json )
KNOWLEDGR_DEFINE_EVALUATOR( custom_binary )
KNOWLEDGR_DEFINE_EVALUATOR( pow )
KNOWLEDGR_DEFINE_EVALUATOR( pow2 )
//KNOWLEDGR_DEFINE_EVALUATOR( feed_publish )
//KNOWLEDGR_DEFINE_EVALUATOR( convert )
KNOWLEDGR_DEFINE_EVALUATOR( limit_order_create )
KNOWLEDGR_DEFINE_EVALUATOR( limit_order_cancel )
KNOWLEDGR_DEFINE_EVALUATOR( report_over_production )
KNOWLEDGR_DEFINE_EVALUATOR( limit_order_create2 )
KNOWLEDGR_DEFINE_EVALUATOR( escrow_transfer )
KNOWLEDGR_DEFINE_EVALUATOR( escrow_approve )
KNOWLEDGR_DEFINE_EVALUATOR( escrow_dispute )
KNOWLEDGR_DEFINE_EVALUATOR( escrow_release )
KNOWLEDGR_DEFINE_EVALUATOR( claim_account )
KNOWLEDGR_DEFINE_EVALUATOR( create_claimed_account )
KNOWLEDGR_DEFINE_EVALUATOR( request_account_recovery )
KNOWLEDGR_DEFINE_EVALUATOR( recover_account )
KNOWLEDGR_DEFINE_EVALUATOR( change_recovery_account )
KNOWLEDGR_DEFINE_EVALUATOR( transfer_to_savings )
KNOWLEDGR_DEFINE_EVALUATOR( transfer_from_savings )
KNOWLEDGR_DEFINE_EVALUATOR( cancel_transfer_from_savings )
KNOWLEDGR_DEFINE_EVALUATOR( decline_voting_rights )
KNOWLEDGR_DEFINE_EVALUATOR( reset_account )
KNOWLEDGR_DEFINE_EVALUATOR( set_reset_account )
KNOWLEDGR_DEFINE_EVALUATOR( claim_reward_balance )
#ifdef KNOWLEDGR_ENABLE_SMT
KNOWLEDGR_DEFINE_EVALUATOR( claim_reward_balance2 )
#endif
//KNOWLEDGR_DEFINE_EVALUATOR( delegate_vesting_shares )
KNOWLEDGR_DEFINE_EVALUATOR( witness_set_properties )
#ifdef KNOWLEDGR_ENABLE_SMT
KNOWLEDGR_DEFINE_EVALUATOR( smt_setup )
KNOWLEDGR_DEFINE_EVALUATOR( smt_cap_reveal )
KNOWLEDGR_DEFINE_EVALUATOR( smt_refund )
KNOWLEDGR_DEFINE_EVALUATOR( smt_setup_emissions )
KNOWLEDGR_DEFINE_EVALUATOR( smt_set_setup_parameters )
KNOWLEDGR_DEFINE_EVALUATOR( smt_set_runtime_parameters )
KNOWLEDGR_DEFINE_EVALUATOR( smt_create )
#endif

} } // knowledgr::chain
