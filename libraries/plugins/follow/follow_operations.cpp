#include <knowledgr/plugins/follow/follow_operations.hpp>

#include <knowledgr/protocol/operation_util_impl.hpp>

namespace knowledgr { namespace plugins{ namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } } //knowledgr::plugins::follow

KNOWLEDGR_DEFINE_OPERATION_TYPE( knowledgr::plugins::follow::follow_plugin_operation )
