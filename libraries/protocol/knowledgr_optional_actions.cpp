#include <colab/protocol/validation.hpp>
#include <colab/protocol/colab_optional_actions.hpp>

namespace colab { namespace protocol {

void example_optional_action::validate()const
{
   validate_account_name( account );
}

} } //colab::protocol
