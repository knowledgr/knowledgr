#pragma once

#include <colab/protocol/colab_optional_actions.hpp>

#include <colab/protocol/operation_util.hpp>

namespace colab { namespace protocol {

   /** NOTE: do not change the order of any actions or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            example_optional_action
         > optional_automated_action;

} } // colab::protocol

COLAB_DECLARE_OPERATION_TYPE( colab::protocol::optional_automated_action );
FC_REFLECT_TYPENAME( colab::protocol::optional_automated_action );
