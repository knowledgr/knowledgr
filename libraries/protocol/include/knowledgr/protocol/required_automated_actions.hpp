#pragma once

#include <knowledgr/protocol/knowledgr_required_actions.hpp>

#include <knowledgr/protocol/operation_util.hpp>

namespace knowledgr { namespace protocol {

   /** NOTE: do not change the order of any actions or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            example_required_action
         > required_automated_action;

} } // knowledgr::protocol

KNOWLEDGR_DECLARE_OPERATION_TYPE( knowledgr::protocol::required_automated_action );
FC_REFLECT_TYPENAME( knowledgr::protocol::required_automated_action );
