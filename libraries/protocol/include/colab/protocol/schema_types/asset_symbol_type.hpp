
#pragma once

#include <colab/schema/abstract_schema.hpp>
#include <colab/schema/schema_impl.hpp>

#include <colab/protocol/asset_symbol.hpp>

namespace colab { namespace schema { namespace detail {

//////////////////////////////////////////////
// asset_symbol_type                        //
//////////////////////////////////////////////

struct schema_asset_symbol_type_impl
   : public abstract_schema
{
   COLAB_SCHEMA_CLASS_BODY( schema_asset_symbol_type_impl )
};

}

template<>
struct schema_reflect< colab::protocol::asset_symbol_type >
{
   typedef detail::schema_asset_symbol_type_impl           schema_impl_type;
};

} }
