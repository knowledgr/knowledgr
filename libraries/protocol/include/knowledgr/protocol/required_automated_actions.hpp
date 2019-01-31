#pragma once

#include <colab/protocol/colab_required_actions.hpp>

#include <colab/protocol/operation_util.hpp>

namespace colab { namespace protocol {

   /** NOTE: do not change the order of any actions or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            example_required_action
         > required_automated_action;

} } // colab::protocol

COLAB_DECLARE_OPERATION_TYPE( colab::protocol::required_automated_action );
FC_REFLECT_TYPENAME( colab::protocol::required_automated_action );
