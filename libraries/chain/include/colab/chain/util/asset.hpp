#pragma once

#include <colab/protocol/asset.hpp>

namespace colab { namespace chain { namespace util {

using colab::protocol::asset;
using colab::protocol::price;

inline asset to_sbd( const price& p, const asset& colab )
{
   FC_ASSERT( colab.symbol == CLC_SYMBOL );
   if( p.is_null() )
      return asset( 0, SBD_SYMBOL );
   return colab * p;
}

inline asset to_colab( const price& p, const asset& sbd )
{
   FC_ASSERT( sbd.symbol == SBD_SYMBOL );
   if( p.is_null() )
      return asset( 0, CLC_SYMBOL );
   return sbd * p;
}

} } }
