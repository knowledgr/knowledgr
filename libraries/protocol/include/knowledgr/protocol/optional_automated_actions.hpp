#pragma once

#include <knowledgr/protocol/knowledgr_optional_actions.hpp>

#include <knowledgr/protocol/operation_util.hpp>

namespace knowledgr { namespace protocol {

   /** NOTE: do not change the order of any actions or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            example_optional_action
         > optional_automated_action;

} } // knowledgr::protocol

KNOWLEDGR_DECLARE_OPERATION_TYPE( knowledgr::protocol::optional_automated_action );
FC_REFLECT_TYPENAME( knowledgr::protocol::optional_automated_action );
