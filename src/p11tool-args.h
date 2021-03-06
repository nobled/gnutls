/*   -*- buffer-read-only: t -*- vi: set ro:
 *  
 *  DO NOT EDIT THIS FILE   (p11tool-args.h)
 *  
 *  It has been AutoGen-ed  November 28, 2012 at 11:45:35 PM by AutoGen 5.16
 *  From the definitions    p11tool-args.def
 *  and the template file   options
 *
 * Generated from AutoOpts 36:4:11 templates.
 *
 *  AutoOpts is a copyrighted work.  This header file is not encumbered
 *  by AutoOpts licensing, but is provided under the licensing terms chosen
 *  by the p11tool author or copyright holder.  AutoOpts is
 *  licensed under the terms of the LGPL.  The redistributable library
 *  (``libopts'') is licensed under the terms of either the LGPL or, at the
 *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources
 *  for details.
 *
 * The p11tool program is copyrighted and licensed
 * under the following terms:
 *
 *  Copyright (C) 2000-2012 Free Software Foundation, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the
 *  GNU General Public License, version 3 or later
 *      <http://gnu.org/licenses/gpl.html>
 *
 *  p11tool is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  p11tool is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
 *  This file contains the programmatic interface to the Automated
 *  Options generated for the p11tool program.
 *  These macros are documented in the AutoGen info file in the
 *  "AutoOpts" chapter.  Please refer to that doc for usage help.
 */
#ifndef AUTOOPTS_P11TOOL_ARGS_H_GUARD
#define AUTOOPTS_P11TOOL_ARGS_H_GUARD 1
#include "config.h"
#include <autoopts/options.h>

/*
 *  Ensure that the library used for compiling this generated header is at
 *  least as new as the version current when the header template was released
 *  (not counting patch version increments).  Also ensure that the oldest
 *  tolerable version is at least as old as what was current when the header
 *  template was released.
 */
#define AO_TEMPLATE_VERSION 147460
#if (AO_TEMPLATE_VERSION < OPTIONS_MINIMUM_VERSION) \
 || (AO_TEMPLATE_VERSION > OPTIONS_STRUCT_VERSION)
# error option template version mismatches autoopts/options.h header
  Choke Me.
#endif

/*
 *  Enumeration of each option:
 */
typedef enum {
    INDEX_OPT_DEBUG              =  0,
    INDEX_OPT_OUTFILE            =  1,
    INDEX_OPT_LIST_TOKENS        =  2,
    INDEX_OPT_EXPORT             =  3,
    INDEX_OPT_LIST_MECHANISMS    =  4,
    INDEX_OPT_LIST_ALL           =  5,
    INDEX_OPT_LIST_ALL_CERTS     =  6,
    INDEX_OPT_LIST_CERTS         =  7,
    INDEX_OPT_LIST_ALL_PRIVKEYS  =  8,
    INDEX_OPT_LIST_ALL_TRUSTED   =  9,
    INDEX_OPT_INITIALIZE         = 10,
    INDEX_OPT_WRITE              = 11,
    INDEX_OPT_DELETE             = 12,
    INDEX_OPT_GENERATE_RSA       = 13,
    INDEX_OPT_GENERATE_DSA       = 14,
    INDEX_OPT_GENERATE_ECC       = 15,
    INDEX_OPT_LABEL              = 16,
    INDEX_OPT_TRUSTED            = 17,
    INDEX_OPT_PRIVATE            = 18,
    INDEX_OPT_LOGIN              = 19,
    INDEX_OPT_DETAILED_URL       = 20,
    INDEX_OPT_SECRET_KEY         = 21,
    INDEX_OPT_LOAD_PRIVKEY       = 22,
    INDEX_OPT_LOAD_PUBKEY        = 23,
    INDEX_OPT_LOAD_CERTIFICATE   = 24,
    INDEX_OPT_PKCS8              = 25,
    INDEX_OPT_BITS               = 26,
    INDEX_OPT_SEC_PARAM          = 27,
    INDEX_OPT_INDER              = 28,
    INDEX_OPT_INRAW              = 29,
    INDEX_OPT_PROVIDER           = 30,
    INDEX_OPT_VERSION            = 31,
    INDEX_OPT_HELP               = 32,
    INDEX_OPT_MORE_HELP          = 33
} teOptIndex;

#define OPTION_CT    34
#define P11TOOL_VERSION       "@VERSION@"
#define P11TOOL_FULL_VERSION  "p11tool @VERSION@"

/*
 *  Interface defines for all options.  Replace "n" with the UPPER_CASED
 *  option name (as in the teOptIndex enumeration above).
 *  e.g. HAVE_OPT(DEBUG)
 */
#define         DESC(n) (p11toolOptions.pOptDesc[INDEX_OPT_## n])
#define     HAVE_OPT(n) (! UNUSED_OPT(& DESC(n)))
#define      OPT_ARG(n) (DESC(n).optArg.argString)
#define    STATE_OPT(n) (DESC(n).fOptState & OPTST_SET_MASK)
#define    COUNT_OPT(n) (DESC(n).optOccCt)
#define    ISSEL_OPT(n) (SELECTED_OPT(&DESC(n)))
#define ISUNUSED_OPT(n) (UNUSED_OPT(& DESC(n)))
#define  ENABLED_OPT(n) (! DISABLED_OPT(& DESC(n)))
#define  STACKCT_OPT(n) (((tArgList*)(DESC(n).optCookie))->useCt)
#define STACKLST_OPT(n) (((tArgList*)(DESC(n).optCookie))->apzArgs)
#define    CLEAR_OPT(n) STMTS( \
                DESC(n).fOptState &= OPTST_PERSISTENT_MASK;   \
                if ((DESC(n).fOptState & OPTST_INITENABLED) == 0) \
                    DESC(n).fOptState |= OPTST_DISABLED; \
                DESC(n).optCookie = NULL )

/* * * * * *
 *
 *  Enumeration of p11tool exit codes
 */
typedef enum {
    P11TOOL_EXIT_SUCCESS = 0,
    P11TOOL_EXIT_FAILURE = 1,
    P11TOOL_EXIT_LIBOPTS_FAILURE = 70
} p11tool_exit_code_t;
/* * * * * *
 *
 *  Interface defines for specific options.
 */
#define VALUE_OPT_DEBUG          'd'

#define OPT_VALUE_DEBUG          (DESC(DEBUG).optArg.argInt)
#define VALUE_OPT_OUTFILE        1
#define VALUE_OPT_LIST_TOKENS    2
#define VALUE_OPT_EXPORT         3
#define VALUE_OPT_LIST_MECHANISMS 4
#define VALUE_OPT_LIST_ALL       5
#define VALUE_OPT_LIST_ALL_CERTS 6
#define VALUE_OPT_LIST_CERTS     7
#define VALUE_OPT_LIST_ALL_PRIVKEYS 8
#define VALUE_OPT_LIST_ALL_TRUSTED 9
#define VALUE_OPT_INITIALIZE     10
#define VALUE_OPT_WRITE          11
#define VALUE_OPT_DELETE         12
#define VALUE_OPT_GENERATE_RSA   13
#define VALUE_OPT_GENERATE_DSA   14
#define VALUE_OPT_GENERATE_ECC   15
#define VALUE_OPT_LABEL          16
#define VALUE_OPT_TRUSTED        17
#define VALUE_OPT_PRIVATE        18
#define VALUE_OPT_LOGIN          19
#define VALUE_OPT_DETAILED_URL   20
#define VALUE_OPT_SECRET_KEY     21
#define VALUE_OPT_LOAD_PRIVKEY   22
#define VALUE_OPT_LOAD_PUBKEY    23
#define VALUE_OPT_LOAD_CERTIFICATE 24
#define VALUE_OPT_PKCS8          '8'
#define VALUE_OPT_BITS           26

#define OPT_VALUE_BITS           (DESC(BITS).optArg.argInt)
#define VALUE_OPT_SEC_PARAM      27
#define VALUE_OPT_INDER          28
#define VALUE_OPT_INRAW          29
#define VALUE_OPT_PROVIDER       30
#define VALUE_OPT_HELP          'h'
#define VALUE_OPT_MORE_HELP     '!'
#define VALUE_OPT_VERSION       'v'
/*
 *  Interface defines not associated with particular options
 */
#define ERRSKIP_OPTERR  STMTS(p11toolOptions.fOptSet &= ~OPTPROC_ERRSTOP)
#define ERRSTOP_OPTERR  STMTS(p11toolOptions.fOptSet |= OPTPROC_ERRSTOP)
#define RESTART_OPT(n)  STMTS( \
                p11toolOptions.curOptIdx = (n); \
                p11toolOptions.pzCurOpt  = NULL)
#define START_OPT       RESTART_OPT(1)
#define USAGE(c)        (*p11toolOptions.pUsageProc)(&p11toolOptions, c)
/* extracted from opthead.tlib near line 484 */

#ifdef  __cplusplus
extern "C" {
#endif
/*
 *  global exported definitions
 */
#include <gettext.h>


/* * * * * *
 *
 *  Declare the p11tool option descriptor.
 */
extern tOptions p11toolOptions;

#if defined(ENABLE_NLS)
# ifndef _
#   include <stdio.h>
static inline char* aoGetsText(char const* pz) {
    if (pz == NULL) return NULL;
    return (char*)gettext(pz);
}
#   define _(s)  aoGetsText(s)
# endif /* _() */

# define OPT_NO_XLAT_CFG_NAMES  STMTS(p11toolOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT_CFG;)
# define OPT_NO_XLAT_OPT_NAMES  STMTS(p11toolOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG;)

# define OPT_XLAT_CFG_NAMES     STMTS(p11toolOptions.fOptSet &= \
                                  ~(OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG);)
# define OPT_XLAT_OPT_NAMES     STMTS(p11toolOptions.fOptSet &= \
                                  ~OPTPROC_NXLAT_OPT;)

#else   /* ENABLE_NLS */
# define OPT_NO_XLAT_CFG_NAMES
# define OPT_NO_XLAT_OPT_NAMES

# define OPT_XLAT_CFG_NAMES
# define OPT_XLAT_OPT_NAMES

# ifndef _
#   define _(_s)  _s
# endif
#endif  /* ENABLE_NLS */

#ifdef  __cplusplus
}
#endif
#endif /* AUTOOPTS_P11TOOL_ARGS_H_GUARD */
/* p11tool-args.h ends here */
