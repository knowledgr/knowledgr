#pragma once

#include <knowledgr/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

namespace knowledgr { namespace protocol {
struct signed_transaction;
} } // knowledgr::protocol

namespace knowledgr { namespace plugins { namespace rc {

using knowledgr::protocol::account_name_type;
using knowledgr::protocol::signed_transaction;

account_name_type get_resource_user( const signed_transaction& tx );

} } } // knowledgr::plugins::rc
