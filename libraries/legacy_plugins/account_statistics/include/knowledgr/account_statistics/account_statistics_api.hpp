#pragma once

#include <colab/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace colab { namespace app {
   struct api_context;
} }

namespace colab { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const colab::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // colab::account_statistics

FC_API( colab::account_statistics::account_statistics_api, )