#include <knowledgr/protocol/validation.hpp>
#include <knowledgr/protocol/knowledgr_required_actions.hpp>

namespace knowledgr { namespace protocol {

void example_required_action::validate()const
{
   validate_account_name( account );
}

bool operator==( const example_required_action& lhs, const example_required_action& rhs )
{
   return lhs.account == rhs.account;
}

} } //knowledgr::protocol
