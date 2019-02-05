#pragma once
#include <knowledgr/chain/database.hpp>
#include <knowledgr/protocol/asset_symbol.hpp>

#ifdef KNOWLEDGR_ENABLE_SMT

namespace knowledgr { namespace chain {

   void replenish_nai_pool( database& db );
   void remove_from_nai_pool( database &db, const asset_symbol_type& a );

} } // knowledgr::chain

#endif
