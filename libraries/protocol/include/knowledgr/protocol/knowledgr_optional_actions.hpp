#pragma once
#include <knowledgr/protocol/base.hpp>
#include <knowledgr/protocol/block_header.hpp>
#include <knowledgr/protocol/asset.hpp>
#include <knowledgr/protocol/validation.hpp>
#include <knowledgr/protocol/legacy_asset.hpp>

#include <fc/crypto/equihash.hpp>

namespace knowledgr { namespace protocol {

   struct example_optional_action : public base_operation
   {
      account_name_type account;

      void validate()const;
      void get_required_active_authorities( flat_set<account_name_type>& a )const{ a.insert(account); }
   };

} } // knowledgr::protocol

FC_REFLECT( knowledgr::protocol::example_optional_action, (account) )
