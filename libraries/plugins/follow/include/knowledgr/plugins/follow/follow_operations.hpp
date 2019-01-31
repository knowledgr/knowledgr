#pragma once
#include <colab/protocol/base.hpp>

#include <colab/chain/evaluator.hpp>


namespace colab { namespace plugins { namespace follow {

using namespace std;
using colab::protocol::account_name_type;
using colab::protocol::base_operation;

class follow_plugin;

struct follow_operation : base_operation
{
    account_name_type follower;
    account_name_type following;
    set< string >     what; /// blog, mute

    void validate()const;

    void get_required_posting_authorities( flat_set<account_name_type>& a )const { a.insert( follower ); }
};

struct reblog_operation : base_operation
{
   account_name_type account;
   account_name_type author;
   string            permlink;

   void validate()const;

   void get_required_posting_authorities( flat_set<account_name_type>& a )const { a.insert( account ); }
};

typedef fc::static_variant<
         follow_operation,
         reblog_operation
      > follow_plugin_operation;

COLAB_DEFINE_PLUGIN_EVALUATOR( follow_plugin, follow_plugin_operation, follow );
COLAB_DEFINE_PLUGIN_EVALUATOR( follow_plugin, follow_plugin_operation, reblog );

} } } // colab::plugins::follow

FC_REFLECT( colab::plugins::follow::follow_operation, (follower)(following)(what) )
FC_REFLECT( colab::plugins::follow::reblog_operation, (account)(author)(permlink) )

COLAB_DECLARE_OPERATION_TYPE( colab::plugins::follow::follow_plugin_operation )

FC_REFLECT_TYPENAME( colab::plugins::follow::follow_plugin_operation )
