#include <colab/plugins/follow/follow_operations.hpp>

#include <colab/protocol/operation_util_impl.hpp>

namespace colab { namespace plugins{ namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } } //colab::plugins::follow

COLAB_DEFINE_OPERATION_TYPE( colab::plugins::follow::follow_plugin_operation )
