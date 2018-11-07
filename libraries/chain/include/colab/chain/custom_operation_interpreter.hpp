
#pragma once

#include <memory>

namespace colab { namespace schema {
   struct abstract_schema;
} }

namespace colab { namespace protocol {
   struct custom_json_operation;
} }

namespace colab { namespace chain {

class custom_operation_interpreter
{
   public:
      virtual void apply( const protocol::custom_json_operation& op ) = 0;
      virtual void apply( const protocol::custom_binary_operation & op ) = 0;
      virtual std::shared_ptr< colab::schema::abstract_schema > get_operation_schema() = 0;
};

} } // colab::chain
