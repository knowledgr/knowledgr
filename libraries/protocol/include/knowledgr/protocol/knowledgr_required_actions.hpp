#pragma once
#include <colab/protocol/base.hpp>
#include <colab/protocol/block_header.hpp>
#include <colab/protocol/asset.hpp>
#include <colab/protocol/validation.hpp>
#include <colab/protocol/legacy_asset.hpp>

#include <fc/crypto/equihash.hpp>

namespace colab { namespace protocol {

   struct example_required_action : public base_operation
   {
      account_name_type account;

      void validate()const;
      void get_required_active_authorities( flat_set<account_name_type>& a )const{ a.insert(account); }

      friend bool operator==( const example_required_action& lhs, const example_required_action& rhs );
   };

} } // colab::protocol

FC_REFLECT( colab::protocol::example_required_action, (account) )
