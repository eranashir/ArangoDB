////////////////////////////////////////////////////////////////////////////////
/// @brief fulltext query functionality 
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2010-2011 triagens GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is triAGENS GmbH, Cologne, Germany
///
/// @author Jan Steemann
/// @author Copyright 2012 triagens GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_FULLTEXT_FULLTEXT_QUERY_H
#define TRIAGENS_FULLTEXT_FULLTEXT_QUERY_H 1

#include "BasicsC/common.h"

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
// --SECTION--                                                      public types
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Fulltext
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief fulltext query options
////////////////////////////////////////////////////////////////////////////////

typedef enum {
  TRI_FULLTEXT_COMPLETE,
  TRI_FULLTEXT_PREFIX,
  TRI_FULLTEXT_SUBSTRING   // TODO: currently not implemented
}
TRI_fulltext_query_option_e;

////////////////////////////////////////////////////////////////////////////////
/// @brief fulltext query
////////////////////////////////////////////////////////////////////////////////

typedef struct TRI_fulltext_query_s {
  size_t                       _numWords;
  char**                       _words;
  TRI_fulltext_query_option_e* _options; 
}
TRI_fulltext_query_t;

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                        constructors / destructors
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Fulltext
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief create a fulltext query
////////////////////////////////////////////////////////////////////////////////

TRI_fulltext_query_t* TRI_CreateQueryFulltextIndex (size_t);

////////////////////////////////////////////////////////////////////////////////
/// @brief free a fulltext query
////////////////////////////////////////////////////////////////////////////////

void TRI_FreeQueryFulltextIndex (TRI_fulltext_query_t*);

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                                  public functions
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup Fulltext
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief set a search word & option for a query
/// the query will take ownership of the search word
/// the caller must not free the word itself
////////////////////////////////////////////////////////////////////////////////

bool TRI_SetQueryFulltextIndex (TRI_fulltext_query_t* const, 
                                const size_t, 
                                const char* const,
                                const size_t, 
                                TRI_fulltext_query_option_e);

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif

// Local Variables:
// mode: outline-minor
// outline-regexp: "^\\(/// @brief\\|/// {@inheritDoc}\\|/// @addtogroup\\|// --SECTION--\\|/// @\\}\\)"
// End: