#pragma once
#include <colab/plugins/rc/rc_plugin.hpp>
#include <colab/plugins/json_rpc/json_rpc_plugin.hpp>

#include <appbase/application.hpp>

#define COLAB_RC_API_PLUGIN_NAME "rc_api"


namespace colab { namespace plugins { namespace rc {

using namespace appbase;

class rc_api_plugin : public appbase::plugin< rc_api_plugin >
{
public:
   APPBASE_PLUGIN_REQUIRES(
      (colab::plugins::rc::rc_plugin)
      (colab::plugins::json_rpc::json_rpc_plugin)
   )

   rc_api_plugin();
   virtual ~rc_api_plugin();

   static const std::string& name() { static std::string name = COLAB_RC_API_PLUGIN_NAME; return name; }

   virtual void set_program_options( options_description& cli, options_description& cfg ) override;

   virtual void plugin_initialize( const variables_map& options ) override;
   virtual void plugin_startup() override;
   virtual void plugin_shutdown() override;

   std::shared_ptr< class rc_api > api;
};

} } } // colab::plugins::rc
