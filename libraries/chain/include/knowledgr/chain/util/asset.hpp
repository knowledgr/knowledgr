#pragma once

#include <knowledgr/protocol/asset.hpp>

namespace knowledgr { namespace chain { namespace util {

using knowledgr::protocol::asset;
using knowledgr::protocol::price;

inline asset to_sbd( const price& p, const asset& knowledgr )
{
   FC_ASSERT( knowledgr.symbol == KNLG_SYMBOL );
   if( p.is_null() )
      return asset( 0, SBD_SYMBOL );
   return knowledgr * p;
}

inline asset to_knowledgr( const price& p, const asset& sbd )
{
   FC_ASSERT( sbd.symbol == SBD_SYMBOL );
   if( p.is_null() )
      return asset( 0, KNLG_SYMBOL );
   return sbd * p;
}

} } }
