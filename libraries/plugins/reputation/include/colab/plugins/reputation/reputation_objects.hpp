#pragma once
#include <colab/chain/colab_object_types.hpp>

#include <boost/multi_index/composite_key.hpp>

namespace colab { namespace chain {
struct by_account;
} }

namespace colab { namespace plugins { namespace reputation {

using namespace std;
using namespace colab::chain;

using chainbase::t_vector;

#ifndef COLAB_REPUTATION_SPACE_ID
#define COLAB_REPUTATION_SPACE_ID 17
#endif

enum reputation_plugin_object_type
{
   reputation_object_type        = ( COLAB_REPUTATION_SPACE_ID << 8 )
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

} } } // colab::plugins::reputation


FC_REFLECT( colab::plugins::reputation::reputation_object, (id)(account)(reputation) )
CHAINBASE_SET_INDEX_TYPE( colab::plugins::reputation::reputation_object, colab::plugins::reputation::reputation_index )
