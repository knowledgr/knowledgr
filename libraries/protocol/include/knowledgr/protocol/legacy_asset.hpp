#pragma once

#include <knowledgr/protocol/asset.hpp>

#define KNOWLEDGR_SYMBOL_LEGACY_SER_1   (uint64_t(1) | (KNLG_SYMBOL_U64 << 8))
#define KNOWLEDGR_SYMBOL_LEGACY_SER_2   (uint64_t(2) | (KNLG_SYMBOL_U64 << 8))
#define KNOWLEDGR_SYMBOL_LEGACY_SER_3   (uint64_t(5) | (KNLG_SYMBOL_U64 << 8))
#define KNOWLEDGR_SYMBOL_LEGACY_SER_4   (uint64_t(3) | (uint64_t('0') << 8) | (uint64_t('.') << 16) | (uint64_t('0') << 24) | (uint64_t('0') << 32) | (uint64_t('1') << 40))
#define KNOWLEDGR_SYMBOL_LEGACY_SER_5   (uint64_t(3) | (uint64_t('6') << 8) | (uint64_t('.') << 16) | (uint64_t('0') << 24) | (uint64_t('0') << 32) | (uint64_t('0') << 40))

namespace knowledgr { namespace protocol {

class legacy_knowledgr_asset_symbol_type
{
   public:
      legacy_knowledgr_asset_symbol_type() {}

      bool is_canon()const
      {   return ( ser == KNLG_SYMBOL_SER );    }

      uint64_t ser = KNLG_SYMBOL_SER;
};

struct legacy_knowledgr_asset
{
   public:
      legacy_knowledgr_asset() {}

      template< bool force_canon >
      asset to_asset()const
      {
         if( force_canon )
         {
            FC_ASSERT( symbol.is_canon(), "Must use canonical KNLG symbol serialization" );
         }
         return asset( amount, KNLG_SYMBOL );
      }

      static legacy_knowledgr_asset from_amount( share_type amount )
      {
         legacy_knowledgr_asset leg;
         leg.amount = amount;
         return leg;
      }

      static legacy_knowledgr_asset from_asset( const asset& a )
      {
         FC_ASSERT( a.symbol == KNLG_SYMBOL );
         return from_amount( a.amount );
      }

      share_type                       amount;
      legacy_knowledgr_asset_symbol_type   symbol;
};

} }

namespace fc { namespace raw {

template< typename Stream >
inline void pack( Stream& s, const knowledgr::protocol::legacy_knowledgr_asset_symbol_type& sym )
{
   switch( sym.ser )
   {
      case KNOWLEDGR_SYMBOL_LEGACY_SER_1:
      case KNOWLEDGR_SYMBOL_LEGACY_SER_2:
      case KNOWLEDGR_SYMBOL_LEGACY_SER_3:
      case KNOWLEDGR_SYMBOL_LEGACY_SER_4:
      case KNOWLEDGR_SYMBOL_LEGACY_SER_5:
         wlog( "pack legacy serialization ${s}", ("s", sym.ser) );
      case KNLG_SYMBOL_SER:
         pack( s, sym.ser );
         break;
      default:
         FC_ASSERT( false, "Cannot serialize legacy symbol ${s}", ("s", sym.ser) );
   }
}

template< typename Stream >
inline void unpack( Stream& s, knowledgr::protocol::legacy_knowledgr_asset_symbol_type& sym )
{
   //  994240:        "account_creation_fee": "0.1 KNLG"
   // 1021529:        "account_creation_fee": "10.0 KNLG"
   // 3143833:        "account_creation_fee": "3.00000 KNLG"
   // 3208405:        "account_creation_fee": "2.00000 KNLG"
   // 3695672:        "account_creation_fee": "3.00 KNLG"
   // 4338089:        "account_creation_fee": "0.001 0.001"
   // 4626205:        "account_creation_fee": "6.000 6.000"
   // 4632595:        "account_creation_fee": "6.000 6.000"

   uint64_t ser = 0;

   fc::raw::unpack( s, ser );
   switch( ser )
   {
      case KNOWLEDGR_SYMBOL_LEGACY_SER_1:
      case KNOWLEDGR_SYMBOL_LEGACY_SER_2:
      case KNOWLEDGR_SYMBOL_LEGACY_SER_3:
      case KNOWLEDGR_SYMBOL_LEGACY_SER_4:
      case KNOWLEDGR_SYMBOL_LEGACY_SER_5:
         wlog( "unpack legacy serialization ${s}", ("s", ser) );
      case KNLG_SYMBOL_SER:
         sym.ser = ser;
         break;
      default:
         FC_ASSERT( false, "Cannot deserialize legacy symbol ${s}", ("s", ser) );
   }
}

} // fc::raw

inline void to_variant( const knowledgr::protocol::legacy_knowledgr_asset& leg, fc::variant& v )
{
   to_variant( leg.to_asset<false>(), v );
}

inline void from_variant( const fc::variant& v, knowledgr::protocol::legacy_knowledgr_asset& leg )
{
   knowledgr::protocol::asset a;
   from_variant( v, a );
   leg = knowledgr::protocol::legacy_knowledgr_asset::from_asset( a );
}

template<>
struct get_typename< knowledgr::protocol::legacy_knowledgr_asset_symbol_type >
{
   static const char* name()
   {
      return "knowledgr::protocol::legacy_knowledgr_asset_symbol_type";
   }
};

} // fc

FC_REFLECT( knowledgr::protocol::legacy_knowledgr_asset,
   (amount)
   (symbol)
   )
