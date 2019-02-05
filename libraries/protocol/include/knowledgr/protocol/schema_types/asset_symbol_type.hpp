
#pragma once

#include <knowledgr/schema/abstract_schema.hpp>
#include <knowledgr/schema/schema_impl.hpp>

#include <knowledgr/protocol/asset_symbol.hpp>

namespace knowledgr { namespace schema { namespace detail {

//////////////////////////////////////////////
// asset_symbol_type                        //
//////////////////////////////////////////////

struct schema_asset_symbol_type_impl
   : public abstract_schema
{
   KNOWLEDGR_SCHEMA_CLASS_BODY( schema_asset_symbol_type_impl )
};

}

template<>
struct schema_reflect< knowledgr::protocol::asset_symbol_type >
{
   typedef detail::schema_asset_symbol_type_impl           schema_impl_type;
};

} }
