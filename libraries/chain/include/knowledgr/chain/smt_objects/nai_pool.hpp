#pragma once
#include <colab/chain/database.hpp>
#include <colab/protocol/asset_symbol.hpp>

#ifdef COLAB_ENABLE_SMT

namespace colab { namespace chain {

   void replenish_nai_pool( database& db );
   void remove_from_nai_pool( database &db, const asset_symbol_type& a );

} } // colab::chain

#endif
