////////////////////////////////////////////////////////////////////////////////
/// @brief shell colors
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2004-2013 triAGENS GmbH, Cologne, Germany
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
/// @author Copyright 2011-2013, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_BASICS_C_SHELL_COLORS_H
#define TRIAGENS_BASICS_C_SHELL_COLORS_H 1

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
// --SECTION--                                                  public constants
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup ShellColors
/// @{
////////////////////////////////////////////////////////////////////////////////

#ifndef _WIN32

////////////////////////////////////////////////////////////////////////////////
/// @brief color red
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_RED "\x1b[31m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color bold red
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_BOLD_RED "\x1b[1;31m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color green
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_GREEN "\x1b[32m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color bold green
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_BOLD_GREEN "\x1b[1;32m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color blue
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_BLUE "\x1b[34m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color bold blue
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_BOLD_BLUE "\x1b[1;34m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color yellow
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_YELLOW "\x1b[33m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color yellow
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_BOLD_YELLOW "\x1b[1;33m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color white
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_WHITE "\x1b[37m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color bold white
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_BOLD_WHITE "\x1b[1;37m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color black
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_BLACK "\x1b[30m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color bold black
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_BOLD_BLACK "\x1b[1;39m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color blink
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_BLINK "\x1b[5m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color bright
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_BRIGHT "\x1b[1m"

////////////////////////////////////////////////////////////////////////////////
/// @brief color reset
////////////////////////////////////////////////////////////////////////////////

#define TRI_SHELL_COLOR_RESET "\x1b[0m"

#else
  // .............................................................................
  // Quick hack for windows
  // .............................................................................

#define TRI_SHELL_COLOR_RED ""
#define TRI_SHELL_COLOR_BOLD_RED ""
#define TRI_SHELL_COLOR_GREEN ""
#define TRI_SHELL_COLOR_BOLD_GREEN ""
#define TRI_SHELL_COLOR_BLUE ""
#define TRI_SHELL_COLOR_BOLD_BLUE ""
#define TRI_SHELL_COLOR_YELLOW ""
#define TRI_SHELL_COLOR_BOLD_YELLOW ""
#define TRI_SHELL_COLOR_WHITE ""
#define TRI_SHELL_COLOR_BOLD_WHITE ""
#define TRI_SHELL_COLOR_BLACK ""
#define TRI_SHELL_COLOR_BOLD_BLACK ""
#define TRI_SHELL_COLOR_BLINK ""
#define TRI_SHELL_COLOR_BRIGHT ""
#define TRI_SHELL_COLOR_RESET ""

#endif

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif

// Local Variables:
// mode: outline-minor
// outline-regexp: "/// @brief\\|/// {@inheritDoc}\\|/// @addtogroup\\|/// @page\\|// --SECTION--\\|/// @\\}"
// End:
