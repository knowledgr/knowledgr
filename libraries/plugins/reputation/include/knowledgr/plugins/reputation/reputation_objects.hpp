#pragma once
#include <knowledgr/chain/knowledgr_object_types.hpp>

#include <boost/multi_index/composite_key.hpp>

namespace knowledgr { namespace chain {
struct by_account;
} }

namespace knowledgr { namespace plugins { namespace reputation {

using namespace std;
using namespace knowledgr::chain;

using chainbase::t_vector;

#ifndef KNOWLEDGR_REPUTATION_SPACE_ID
#define KNOWLEDGR_REPUTATION_SPACE_ID 17
#endif

enum reputation_plugin_object_type
{
   reputation_object_type        = ( KNOWLEDGR_REPUTATION_SPACE_ID << 8 )
};


class reputation_object : public object< reputation_object_type, reputation_object >
{
   public:
      template< typename Constructor, typename Allocator >
      reputation_object( Constructor&& c, allocator< Allocator > a )
      {
         c( *this );
      }

      reputation_object() {}

      id_type           id;

      account_name_type account;
      share_type        reputation;
};

typedef oid< reputation_object > reputation_id_type;

typedef multi_index_container<
   reputation_object,
   indexed_by<
      ordered_unique< tag< by_id >, member< reputation_object, reputation_id_type, &reputation_object::id > >,
      ordered_unique< tag< by_account >, member< reputation_object, account_name_type, &reputation_object::account > >
   >,
   allocator< reputation_object >
> reputation_index;

} } } // knowledgr::plugins::reputation


FC_REFLECT( knowledgr::plugins::reputation::reputation_object, (id)(account)(reputation) )
CHAINBASE_SET_INDEX_TYPE( knowledgr::plugins::reputation::reputation_object, knowledgr::plugins::reputation::reputation_index )
