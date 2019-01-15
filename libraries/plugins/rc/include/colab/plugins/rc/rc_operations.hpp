#pragma once
#include <colab/protocol/base.hpp>

#include <colab/chain/evaluator.hpp>

namespace colab { namespace plugins { namespace rc {

struct delegate_to_pool_operation : base_operation
{
   account_name_type     from_account;
   account_name_type     to_pool;
   share_type            amount;

   void validate()const;
   void get_required_active_authorities( flat_set<account_name_type>& a )const { a.insert( from_account ); }
};

struct delegate_drc_from_pool_operation : base_operation
{
   account_name_type      from_pool;
   account_name_type      to_account;
   int64_t                mana_change = 0;
   int64_t                drc_max_mana = 0;

   void validate()const;
   void get_required_active_authorities( flat_set<account_name_type>& a )const { a.insert( from_pool ); }
};

typedef fc::static_variant<
         delegate_to_pool_operation,
         delegate_drc_from_pool_operation
      > rc_plugin_operation;

COLAB_DEFINE_PLUGIN_EVALUATOR( rc_plugin, rc_plugin_operation, delegate_to_pool_operation );
COLAB_DEFINE_PLUGIN_EVALUATOR( rc_plugin, rc_plugin_operation, delegate_drc_from_pool_operation );

} } } // colab::plugins::rc

FC_REFLECT( colab::plugins::rc::delegate_to_pool_operation,
   (from_account)
   (to_pool)
   (amount)
   )
FC_REFLECT( colab::plugins::rc::delegate_drc_from_pool_operation,
   (from_pool)
   (to_account)
   (mana_change)
   (drc_max_mana)
   )

COLAB_DECLARE_OPERATION_TYPE( colab::plugins::rc::rc_plugin_operation )
FC_REFLECT_TYPENAME( colab::plugins::rc::rc_plugin_operation )