#pragma once

#include <colab/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

namespace colab { namespace protocol {
struct signed_transaction;
} } // colab::protocol

namespace colab { namespace plugins { namespace rc {

using colab::protocol::account_name_type;
using colab::protocol::signed_transaction;

account_name_type get_resource_user( const signed_transaction& tx );

} } } // colab::plugins::rc
