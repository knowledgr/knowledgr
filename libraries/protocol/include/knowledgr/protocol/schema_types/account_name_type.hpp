
#pragma once

#include <colab/schema/abstract_schema.hpp>
#include <colab/schema/schema_impl.hpp>

#include <colab/protocol/types.hpp>

namespace colab { namespace schema { namespace detail {

//////////////////////////////////////////////
// account_name_type                        //
//////////////////////////////////////////////

struct schema_account_name_type_impl
   : public abstract_schema
{
   COLAB_SCHEMA_CLASS_BODY( schema_account_name_type_impl )
};

}

template<>
struct schema_reflect< colab::protocol::account_name_type >
{
   typedef detail::schema_account_name_type_impl           schema_impl_type;
};

} }

namespace fc {

template<>
struct get_typename< colab::protocol::account_name_type >
{
   static const char* name()
   {
      return "colab::protocol::account_name_type";
   }
};

}
