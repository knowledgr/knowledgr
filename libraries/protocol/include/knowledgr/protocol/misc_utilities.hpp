#pragma once

namespace colab { namespace protocol {

// TODO:  Rename these curves to match naming in manual.md
enum curve_id
{
   quadratic,
   quadratic_curation,
   linear,
   square_root
};

} } // colab::utilities


FC_REFLECT_ENUM(
   colab::protocol::curve_id,
   (quadratic)
   (quadratic_curation)
   (linear)
   (square_root)
)
