
#pragma once

#include <knowledgr/schema/abstract_schema.hpp>
#include <knowledgr/schema/schema_impl.hpp>

#include <knowledgr/protocol/types.hpp>

namespace knowledgr { namespace schema { namespace detail {

//////////////////////////////////////////////
// account_name_type                        //
//////////////////////////////////////////////

struct schema_account_name_type_impl
   : public abstract_schema
{
   KNOWLEDGR_SCHEMA_CLASS_BODY( schema_account_name_type_impl )
};

}

template<>
struct schema_reflect< knowledgr::protocol::account_name_type >
{
   typedef detail::schema_account_name_type_impl           schema_impl_type;
};

} }

namespace fc {

template<>
struct get_typename< knowledgr::protocol::account_name_type >
{
   static const char* name()
   {
      return "knowledgr::protocol::account_name_type";
   }
};

}
