#include <colab/protocol/validation.hpp>
#include <colab/protocol/colab_required_actions.hpp>

namespace colab { namespace protocol {

void example_required_action::validate()const
{
   validate_account_name( account );
}

bool operator==( const example_required_action& lhs, const example_required_action& rhs )
{
   return lhs.account == rhs.account;
}

} } //colab::protocol
