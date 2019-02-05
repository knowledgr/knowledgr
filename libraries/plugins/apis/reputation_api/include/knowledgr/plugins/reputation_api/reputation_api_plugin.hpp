#pragma once
#include <knowledgr/plugins/reputation/reputation_plugin.hpp>
#include <knowledgr/plugins/json_rpc/json_rpc_plugin.hpp>

#include <appbase/application.hpp>

#define KNOWLEDGR_REPUTATION_API_PLUGIN_NAME "reputation_api"


namespace knowledgr { namespace plugins { namespace reputation {

using namespace appbase;

class reputation_api_plugin : public appbase::plugin< reputation_api_plugin >
{
public:
   APPBASE_PLUGIN_REQUIRES(
      (knowledgr::plugins::reputation::reputation_plugin)
      (knowledgr::plugins::json_rpc::json_rpc_plugin)
   )

   reputation_api_plugin();
   virtual ~reputation_api_plugin();

   static const std::string& name() { static std::string name = KNOWLEDGR_REPUTATION_API_PLUGIN_NAME; return name; }

   virtual void set_program_options( options_description& cli, options_description& cfg ) override;

   virtual void plugin_initialize( const variables_map& options ) override;
   virtual void plugin_startup() override;
   virtual void plugin_shutdown() override;

   std::shared_ptr< class reputation_api > api;
};

} } } // knowledgr::plugins::reputation
