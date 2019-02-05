#include <appbase/application.hpp>
#include <knowledgr/manifest/plugins.hpp>

#include <knowledgr/protocol/types.hpp>
#include <knowledgr/protocol/version.hpp>

#include <knowledgr/utilities/logging_config.hpp>
#include <knowledgr/utilities/key_conversion.hpp>
#include <knowledgr/utilities/git_revision.hpp>

#include <knowledgr/plugins/account_by_key/account_by_key_plugin.hpp>
#include <knowledgr/plugins/account_by_key_api/account_by_key_api_plugin.hpp>
#include <knowledgr/plugins/chain/chain_plugin.hpp>
#include <knowledgr/plugins/condenser_api/condenser_api_plugin.hpp>
#include <knowledgr/plugins/p2p/p2p_plugin.hpp>
#include <knowledgr/plugins/webserver/webserver_plugin.hpp>
#include <knowledgr/plugins/witness/witness_plugin.hpp>

#include <fc/exception/exception.hpp>
#include <fc/thread/thread.hpp>
#include <fc/interprocess/signals.hpp>
#include <fc/git_revision.hpp>
#include <fc/stacktrace.hpp>

#include <boost/exception/diagnostic_information.hpp>
#include <boost/program_options.hpp>

#include <iostream>
#include <csignal>
#include <vector>

namespace bpo = boost::program_options;
using knowledgr::protocol::version;
using std::string;
using std::vector;

string& version_string()
{
   static string v_str =
      "knowledgr_blockchain_version: " + fc::string( KNOWLEDGR_BLOCKCHAIN_VERSION ) + "\n" +
      "knowledgr_git_revision:       " + fc::string( knowledgr::utilities::git_revision_sha ) + "\n" +
      "fc_git_revision:          " + fc::string( fc::git_revision_sha ) + "\n";
   return v_str;
}

void info()
{
#ifdef IS_TEST_NET
      std::cerr << "------------------------------------------------------\n\n";
      std::cerr << "            STARTING TEST NETWORK\n\n";
      std::cerr << "------------------------------------------------------\n";
      auto initminer_private_key = knowledgr::utilities::key_to_wif( KNOWLEDGR_INIT_PRIVATE_KEY );
      std::cerr << "initminer public key: " << KNOWLEDGR_INIT_PUBLIC_KEY_STR << "\n";
      std::cerr << "initminer private key: " << initminer_private_key << "\n";
      std::cerr << "blockchain version: " << fc::string( KNOWLEDGR_BLOCKCHAIN_VERSION ) << "\n";
      std::cerr << "------------------------------------------------------\n";
#else
      std::cerr << "------------------------------------------------------\n\n";
      std::cerr << "            STARTING KNOWLEDGR NETWORK\n\n";
      std::cerr << "------------------------------------------------------\n";
      std::cerr << "initminer public key: " << KNOWLEDGR_INIT_PUBLIC_KEY_STR << "\n";
      std::cerr << "chain id: " << std::string( KNOWLEDGR_CHAIN_ID ) << "\n";
      std::cerr << "blockchain version: " << fc::string( KNOWLEDGR_BLOCKCHAIN_VERSION ) << "\n";
      std::cerr << "------------------------------------------------------\n";
#endif
}

int main( int argc, char** argv )
{
   try
   {
      // Setup logging config
      bpo::options_description options;

      knowledgr::utilities::set_logging_program_options( options );
      options.add_options()
         ("backtrace", bpo::value< string >()->default_value( "yes" ), "Whether to print backtrace on SIGSEGV" );

      appbase::app().add_program_options( bpo::options_description(), options );

      knowledgr::plugins::register_plugins();

      appbase::app().set_version_string( version_string() );
      appbase::app().set_app_name( "knowledgrd" );

      // These plugins are included in the default config
      appbase::app().set_default_plugins<
         knowledgr::plugins::witness::witness_plugin,
         knowledgr::plugins::account_by_key::account_by_key_plugin,
         knowledgr::plugins::account_by_key::account_by_key_api_plugin,
         knowledgr::plugins::condenser_api::condenser_api_plugin >();

      // These plugins are loaded regardless of the config
      bool initialized = appbase::app().initialize<
            knowledgr::plugins::chain::chain_plugin,
            knowledgr::plugins::p2p::p2p_plugin,
            knowledgr::plugins::webserver::webserver_plugin >
            ( argc, argv );

      info();

      if( !initialized )
         return 0;

      auto& args = appbase::app().get_args();

      try
      {
         fc::optional< fc::logging_config > logging_config = knowledgr::utilities::load_logging_config( args, appbase::app().data_dir() );
         if( logging_config )
            fc::configure_logging( *logging_config );
      }
      catch( const fc::exception& e )
      {
         wlog( "Error parsing logging config. ${e}", ("e", e.to_string()) );
      }

      if( args.at( "backtrace" ).as< string >() == "yes" )
      {
         fc::print_stacktrace_on_segfault();
         ilog( "Backtrace on segfault is enabled." );
      }

      appbase::app().startup();
      appbase::app().exec();
      std::cout << "exited cleanly\n";
      return 0;
   }
   catch ( const boost::exception& e )
   {
      std::cerr << boost::diagnostic_information(e) << "\n";
   }
   catch ( const fc::exception& e )
   {
      std::cerr << e.to_detail_string() << "\n";
   }
   catch ( const std::exception& e )
   {
      std::cerr << e.what() << "\n";
   }
   catch ( ... )
   {
      std::cerr << "unknown exception\n";
   }

   return -1;
}
