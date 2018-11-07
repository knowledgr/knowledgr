#pragma once

#include <colab/chain/evaluator.hpp>

#include <colab/private_message/private_message_operations.hpp>
#include <colab/private_message/private_message_plugin.hpp>

namespace colab { namespace private_message {

COLAB_DEFINE_PLUGIN_EVALUATOR( private_message_plugin, colab::private_message::private_message_plugin_operation, private_message )

} }
