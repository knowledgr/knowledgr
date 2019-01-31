#pragma once
#include <appbase/application.hpp>

#include <colab/plugins/chain/chain_plugin.hpp>

namespace colab { namespace plugins { namespace smt_test {

using namespace appbase;

#define COLAB_SMT_TEST_PLUGIN_NAME "smt_test"

class smt_test_plugin : public appbase::plugin< smt_test_plugin >
{
   public:
      smt_test_plugin();
      virtual ~smt_test_plugin();

      APPBASE_PLUGIN_REQUIRES( (colab::plugins::chain::chain_plugin) )

      static const std::string& name() { static std::string name = COLAB_SMT_TEST_PLUGIN_NAME; return name; }

      virtual void set_program_options( options_description& cli, options_description& cfg ) override;
      void plugin_initialize( const variables_map& options ) override;
      void plugin_startup() override;
      void plugin_shutdown() override;

   private:
      std::unique_ptr< class smt_test_plugin_impl > my;
};

} } } // colab::plugins::smt_test
