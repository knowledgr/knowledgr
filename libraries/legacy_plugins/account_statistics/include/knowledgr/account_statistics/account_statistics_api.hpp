#pragma once

#include <knowledgr/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace knowledgr { namespace app {
   struct api_context;
} }

namespace knowledgr { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const knowledgr::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // knowledgr::account_statistics

FC_API( knowledgr::account_statistics::account_statistics_api, )