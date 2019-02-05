#include <knowledgr/protocol/validation.hpp>
#include <knowledgr/protocol/knowledgr_optional_actions.hpp>

namespace knowledgr { namespace protocol {

void example_optional_action::validate()const
{
   validate_account_name( account );
}

} } //knowledgr::protocol
