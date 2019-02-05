
#pragma once

#include <knowledgr/protocol/base.hpp>
#include <knowledgr/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

#include <cstdint>
#include <string>
#include <vector>

namespace knowledgr { namespace private_message {

struct private_message_operation : public knowledgr::protocol::base_operation
{
    protocol::account_name_type  from;
    protocol::account_name_type  to;
    protocol::public_key_type    from_memo_key;
    protocol::public_key_type    to_memo_key;
    uint64_t                     sent_time = 0; /// used as seed to secret generation
    uint32_t                     checksum = 0;
    std::vector<char>            encrypted_message;
};

typedef fc::static_variant< private_message_operation > private_message_plugin_operation;

} }

FC_REFLECT( knowledgr::private_message::private_message_operation, (from)(to)(from_memo_key)(to_memo_key)(sent_time)(checksum)(encrypted_message) )

KNOWLEDGR_DECLARE_OPERATION_TYPE( knowledgr::private_message::private_message_plugin_operation )
FC_REFLECT_TYPENAME( knowledgr::private_message::private_message_plugin_operation )
