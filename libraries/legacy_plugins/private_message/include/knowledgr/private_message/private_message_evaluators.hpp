#pragma once

#include <knowledgr/chain/evaluator.hpp>

#include <knowledgr/private_message/private_message_operations.hpp>
#include <knowledgr/private_message/private_message_plugin.hpp>

namespace knowledgr { namespace private_message {

KNOWLEDGR_DEFINE_PLUGIN_EVALUATOR( private_message_plugin, knowledgr::private_message::private_message_plugin_operation, private_message )

} }
