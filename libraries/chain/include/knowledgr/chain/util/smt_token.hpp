#pragma once

#ifdef KNOWLEDGR_ENABLE_SMT

#include <knowledgr/chain/database.hpp>
#include <knowledgr/chain/smt_objects/smt_token_object.hpp>
#include <knowledgr/protocol/asset_symbol.hpp>

namespace knowledgr { namespace chain { namespace util {

const smt_token_object* find_smt_token( database& db, uint32_t nai );
const smt_token_object* find_smt_token( database& db, asset_symbol_type symbol, bool precision_agnostic = false );

} } } // knowledgr::chain::util

#endif
