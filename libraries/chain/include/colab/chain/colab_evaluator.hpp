#pragma once

#include <colab/protocol/colab_operations.hpp>

#include <colab/chain/evaluator.hpp>

namespace colab { namespace chain {

using namespace colab::protocol;

COLAB_DEFINE_EVALUATOR( account_create )
COLAB_DEFINE_EVALUATOR( account_discpline_update ) //~~~~~CLC~~~~~
COLAB_DEFINE_EVALUATOR( account_create_with_delegation )
COLAB_DEFINE_EVALUATOR( account_update )
COLAB_DEFINE_EVALUATOR( transfer )
COLAB_DEFINE_EVALUATOR( transfer_to_vesting )
COLAB_DEFINE_EVALUATOR( witness_update )
COLAB_DEFINE_EVALUATOR( account_witness_vote )
COLAB_DEFINE_EVALUATOR( account_witness_proxy )
COLAB_DEFINE_EVALUATOR( withdraw_vesting )
COLAB_DEFINE_EVALUATOR( set_withdraw_vesting_route )
COLAB_DEFINE_EVALUATOR( comment )
COLAB_DEFINE_EVALUATOR( comment_options )
COLAB_DEFINE_EVALUATOR( delete_comment )
COLAB_DEFINE_EVALUATOR( vote )
COLAB_DEFINE_EVALUATOR( custom )
COLAB_DEFINE_EVALUATOR( custom_json )
COLAB_DEFINE_EVALUATOR( custom_binary )
COLAB_DEFINE_EVALUATOR( pow )
COLAB_DEFINE_EVALUATOR( pow2 )
COLAB_DEFINE_EVALUATOR( feed_publish )
COLAB_DEFINE_EVALUATOR( convert )
COLAB_DEFINE_EVALUATOR( limit_order_create )
COLAB_DEFINE_EVALUATOR( limit_order_cancel )
COLAB_DEFINE_EVALUATOR( report_over_production )
COLAB_DEFINE_EVALUATOR( limit_order_create2 )
COLAB_DEFINE_EVALUATOR( escrow_transfer )
COLAB_DEFINE_EVALUATOR( escrow_approve )
COLAB_DEFINE_EVALUATOR( escrow_dispute )
COLAB_DEFINE_EVALUATOR( escrow_release )
COLAB_DEFINE_EVALUATOR( claim_account )
COLAB_DEFINE_EVALUATOR( create_claimed_account )
COLAB_DEFINE_EVALUATOR( request_account_recovery )
COLAB_DEFINE_EVALUATOR( recover_account )
COLAB_DEFINE_EVALUATOR( change_recovery_account )
COLAB_DEFINE_EVALUATOR( transfer_to_savings )
COLAB_DEFINE_EVALUATOR( transfer_from_savings )
COLAB_DEFINE_EVALUATOR( cancel_transfer_from_savings )
COLAB_DEFINE_EVALUATOR( decline_voting_rights )
COLAB_DEFINE_EVALUATOR( reset_account )
COLAB_DEFINE_EVALUATOR( set_reset_account )
COLAB_DEFINE_EVALUATOR( claim_reward_balance )
#ifdef COLAB_ENABLE_SMT
COLAB_DEFINE_EVALUATOR( claim_reward_balance2 )
#endif
COLAB_DEFINE_EVALUATOR( delegate_vesting_shares )
COLAB_DEFINE_EVALUATOR( witness_set_properties )
#ifdef COLAB_ENABLE_SMT
COLAB_DEFINE_EVALUATOR( smt_setup )
COLAB_DEFINE_EVALUATOR( smt_cap_reveal )
COLAB_DEFINE_EVALUATOR( smt_refund )
COLAB_DEFINE_EVALUATOR( smt_setup_emissions )
COLAB_DEFINE_EVALUATOR( smt_set_setup_parameters )
COLAB_DEFINE_EVALUATOR( smt_set_runtime_parameters )
COLAB_DEFINE_EVALUATOR( smt_create )
#endif

} } // colab::chain
