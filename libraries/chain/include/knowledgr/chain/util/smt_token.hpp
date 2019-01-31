#pragma once

#ifdef COLAB_ENABLE_SMT

#include <colab/chain/database.hpp>
#include <colab/chain/smt_objects/smt_token_object.hpp>
#include <colab/protocol/asset_symbol.hpp>

namespace colab { namespace chain { namespace util {

const smt_token_object* find_smt_token( database& db, uint32_t nai );
const smt_token_object* find_smt_token( database& db, asset_symbol_type symbol, bool precision_agnostic = false );

} } } // colab::chain::util

#endif
