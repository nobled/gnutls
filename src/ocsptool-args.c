/*   -*- buffer-read-only: t -*- vi: set ro:
 *  
 *  DO NOT EDIT THIS FILE   (ocsptool-args.c)
 *  
 *  It has been AutoGen-ed  November  8, 2012 at 11:35:48 PM by AutoGen 5.16
 *  From the definitions    ocsptool-args.def
 *  and the template file   options
 *
 * Generated from AutoOpts 36:4:11 templates.
 *
 *  AutoOpts is a copyrighted work.  This source file is not encumbered
 *  by AutoOpts licensing, but is provided under the licensing terms chosen
 *  by the ocsptool author or copyright holder.  AutoOpts is
 *  licensed under the terms of the LGPL.  The redistributable library
 *  (``libopts'') is licensed under the terms of either the LGPL or, at the
 *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources
 *  for details.
 *
 * The ocsptool program is copyrighted and licensed
 * under the following terms:
 *
 *  Copyright (C) 2000-2012 Free Software Foundation, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the
 *  GNU General Public License, version 3 or later
 *      <http://gnu.org/licenses/gpl.html>
 *
 *  ocsptool is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  ocsptool is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __doxygen__
#define OPTION_CODE_COMPILE 1
#include "ocsptool-args.h"
#include <sys/types.h>

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifdef  __cplusplus
extern "C" {
#endif
extern FILE * option_usage_fp;

/* TRANSLATORS: choose the translation for option names wisely because you
                cannot ever change your mind. */
#define zCopyright      (ocsptool_opt_strs+0)
#define zLicenseDescrip (ocsptool_opt_strs+279)


#ifndef NULL
#  define NULL 0
#endif

/*
 *  ocsptool option static const strings
 */
static char const ocsptool_opt_strs[2273] =
/*     0 */ "ocsptool @VERSION@\n"
            "Copyright (C) 2000-2012 Free Software Foundation, all rights reserved.\n"
            "This is free software. It is licensed for use, modification and\n"
            "redistribution under the terms of the\n"
            "GNU General Public License, version 3 or later\n"
            "    <http://gnu.org/licenses/gpl.html>\n\0"
/*   279 */ "ocsptool is free software: you can redistribute it and/or modify it under\n"
            "the terms of the GNU General Public License as published by the Free\n"
            "Software Foundation, either version 3 of the License, or (at your option)\n"
            "any later version.\n\n"
            "ocsptool is distributed in the hope that it will be useful, but WITHOUT ANY\n"
            "WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS\n"
            "FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more\n"
            "details.\n\n"
            "You should have received a copy of the GNU General Public License along\n"
            "with this program.  If not, see <http://www.gnu.org/licenses/>.\n\0"
/*   884 */ "Enable debugging.\0"
/*   902 */ "DEBUG\0"
/*   908 */ "debug\0"
/*   914 */ "More verbose output\0"
/*   934 */ "VERBOSE\0"
/*   942 */ "verbose\0"
/*   950 */ "Input file\0"
/*   961 */ "INFILE\0"
/*   968 */ "infile\0"
/*   975 */ "Output file\0"
/*   987 */ "OUTFILE\0"
/*   995 */ "outfile\0"
/*  1003 */ "Ask an OCSP/HTTP server on a certificate validity\0"
/*  1053 */ "ASK\0"
/*  1057 */ "ask\0"
/*  1061 */ "Verify response\0"
/*  1077 */ "VERIFY_RESPONSE\0"
/*  1093 */ "verify-response\0"
/*  1109 */ "Print information on a OCSP request\0"
/*  1145 */ "REQUEST_INFO\0"
/*  1158 */ "request-info\0"
/*  1171 */ "Print information on a OCSP response\0"
/*  1208 */ "RESPONSE_INFO\0"
/*  1222 */ "response-info\0"
/*  1236 */ "Generate an OCSP request\0"
/*  1261 */ "GENERATE_REQUEST\0"
/*  1278 */ "generate-request\0"
/*  1295 */ "Don't add nonce to OCSP request\0"
/*  1327 */ "NONCE\0"
/*  1333 */ "no-nonce\0"
/*  1342 */ "no\0"
/*  1345 */ "Read issuer certificate from file\0"
/*  1379 */ "LOAD_ISSUER\0"
/*  1391 */ "load-issuer\0"
/*  1403 */ "Read certificate to check from file\0"
/*  1439 */ "LOAD_CERT\0"
/*  1449 */ "load-cert\0"
/*  1459 */ "Read OCSP trust anchors from file\0"
/*  1493 */ "LOAD_TRUST\0"
/*  1504 */ "load-trust\0"
/*  1515 */ "Read OCSP response signer from file\0"
/*  1551 */ "LOAD_SIGNER\0"
/*  1563 */ "load-signer\0"
/*  1575 */ "Use DER format for input certificates and private keys\0"
/*  1630 */ "INDER\0"
/*  1636 */ "no-inder\0"
/*  1645 */ "Read DER encoded OCSP request from file\0"
/*  1685 */ "LOAD_REQUEST\0"
/*  1698 */ "load-request\0"
/*  1711 */ "Read DER encoded OCSP response from file\0"
/*  1752 */ "LOAD_RESPONSE\0"
/*  1766 */ "load-response\0"
/*  1780 */ "Display extended usage information and exit\0"
/*  1824 */ "help\0"
/*  1829 */ "Extended usage information passed thru pager\0"
/*  1874 */ "more-help\0"
/*  1884 */ "Output version information and exit\0"
/*  1920 */ "version\0"
/*  1928 */ "OCSPTOOL\0"
/*  1937 */ "ocsptool - GnuTLS OCSP tool - Ver. @VERSION@\n"
            "USAGE:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]...\n\0"
/*  2040 */ "bug-gnutls@gnu.org\0"
/*  2059 */ "\n\n\0"
/*  2062 */ "\n"
            "Ocsptool is a program that can parse and print information about OCSP\n"
            "requests/responses, generate requests and verify responses.\n\0"
/*  2194 */ "ocsptool @VERSION@\0"
/*  2213 */ "ocsptool [options]\n"
            "ocsptool --help for usage instructions.\n";

/*
 *  debug option description:
 */
#define DEBUG_DESC      (ocsptool_opt_strs+884)
#define DEBUG_NAME      (ocsptool_opt_strs+902)
#define DEBUG_name      (ocsptool_opt_strs+908)
#define DEBUG_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/*
 *  verbose option description:
 */
#define VERBOSE_DESC      (ocsptool_opt_strs+914)
#define VERBOSE_NAME      (ocsptool_opt_strs+934)
#define VERBOSE_name      (ocsptool_opt_strs+942)
#define VERBOSE_FLAGS     (OPTST_DISABLED)

/*
 *  infile option description:
 */
#define INFILE_DESC      (ocsptool_opt_strs+950)
#define INFILE_NAME      (ocsptool_opt_strs+961)
#define INFILE_name      (ocsptool_opt_strs+968)
#define INFILE_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_FILE))

/*
 *  outfile option description:
 */
#define OUTFILE_DESC      (ocsptool_opt_strs+975)
#define OUTFILE_NAME      (ocsptool_opt_strs+987)
#define OUTFILE_name      (ocsptool_opt_strs+995)
#define OUTFILE_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/*
 *  ask option description with
 *  "Must also have options" and "Incompatible options":
 */
#define ASK_DESC      (ocsptool_opt_strs+1003)
#define ASK_NAME      (ocsptool_opt_strs+1053)
#define ASK_name      (ocsptool_opt_strs+1057)
static int const aAskMustList[] = {
    INDEX_OPT_LOAD_CERT,
    INDEX_OPT_LOAD_ISSUER, NO_EQUIVALENT };
#define ASK_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | OPTST_ARG_OPTIONAL)

/*
 *  verify-response option description:
 */
#define VERIFY_RESPONSE_DESC      (ocsptool_opt_strs+1061)
#define VERIFY_RESPONSE_NAME      (ocsptool_opt_strs+1077)
#define VERIFY_RESPONSE_name      (ocsptool_opt_strs+1093)
#define VERIFY_RESPONSE_FLAGS     (OPTST_DISABLED)

/*
 *  request-info option description:
 */
#define REQUEST_INFO_DESC      (ocsptool_opt_strs+1109)
#define REQUEST_INFO_NAME      (ocsptool_opt_strs+1145)
#define REQUEST_INFO_name      (ocsptool_opt_strs+1158)
#define REQUEST_INFO_FLAGS     (OPTST_DISABLED)

/*
 *  response-info option description:
 */
#define RESPONSE_INFO_DESC      (ocsptool_opt_strs+1171)
#define RESPONSE_INFO_NAME      (ocsptool_opt_strs+1208)
#define RESPONSE_INFO_name      (ocsptool_opt_strs+1222)
#define RESPONSE_INFO_FLAGS     (OPTST_DISABLED)

/*
 *  generate-request option description:
 */
#define GENERATE_REQUEST_DESC      (ocsptool_opt_strs+1236)
#define GENERATE_REQUEST_NAME      (ocsptool_opt_strs+1261)
#define GENERATE_REQUEST_name      (ocsptool_opt_strs+1278)
#define GENERATE_REQUEST_FLAGS     (OPTST_DISABLED)

/*
 *  nonce option description:
 */
#define NONCE_DESC      (ocsptool_opt_strs+1295)
#define NONCE_NAME      (ocsptool_opt_strs+1327)
#define NOT_NONCE_name  (ocsptool_opt_strs+1333)
#define NOT_NONCE_PFX   (ocsptool_opt_strs+1342)
#define NONCE_name      (NOT_NONCE_name + 3)
#define NONCE_FLAGS     (OPTST_DISABLED)

/*
 *  load-issuer option description:
 */
#define LOAD_ISSUER_DESC      (ocsptool_opt_strs+1345)
#define LOAD_ISSUER_NAME      (ocsptool_opt_strs+1379)
#define LOAD_ISSUER_name      (ocsptool_opt_strs+1391)
#define LOAD_ISSUER_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_FILE))

/*
 *  load-cert option description:
 */
#define LOAD_CERT_DESC      (ocsptool_opt_strs+1403)
#define LOAD_CERT_NAME      (ocsptool_opt_strs+1439)
#define LOAD_CERT_name      (ocsptool_opt_strs+1449)
#define LOAD_CERT_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_FILE))

/*
 *  load-trust option description with
 *  "Must also have options" and "Incompatible options":
 */
#define LOAD_TRUST_DESC      (ocsptool_opt_strs+1459)
#define LOAD_TRUST_NAME      (ocsptool_opt_strs+1493)
#define LOAD_TRUST_name      (ocsptool_opt_strs+1504)
static int const aLoad_TrustCantList[] = {
    INDEX_OPT_LOAD_SIGNER, NO_EQUIVALENT };
#define LOAD_TRUST_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_FILE))

/*
 *  load-signer option description with
 *  "Must also have options" and "Incompatible options":
 */
#define LOAD_SIGNER_DESC      (ocsptool_opt_strs+1515)
#define LOAD_SIGNER_NAME      (ocsptool_opt_strs+1551)
#define LOAD_SIGNER_name      (ocsptool_opt_strs+1563)
static int const aLoad_SignerCantList[] = {
    INDEX_OPT_LOAD_TRUST, NO_EQUIVALENT };
#define LOAD_SIGNER_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_FILE))

/*
 *  inder option description:
 */
#define INDER_DESC      (ocsptool_opt_strs+1575)
#define INDER_NAME      (ocsptool_opt_strs+1630)
#define NOT_INDER_name  (ocsptool_opt_strs+1636)
#define NOT_INDER_PFX   (ocsptool_opt_strs+1342)
#define INDER_name      (NOT_INDER_name + 3)
#define INDER_FLAGS     (OPTST_DISABLED)

/*
 *  load-request option description:
 */
#define LOAD_REQUEST_DESC      (ocsptool_opt_strs+1645)
#define LOAD_REQUEST_NAME      (ocsptool_opt_strs+1685)
#define LOAD_REQUEST_name      (ocsptool_opt_strs+1698)
#define LOAD_REQUEST_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_FILE))

/*
 *  load-response option description:
 */
#define LOAD_RESPONSE_DESC      (ocsptool_opt_strs+1711)
#define LOAD_RESPONSE_NAME      (ocsptool_opt_strs+1752)
#define LOAD_RESPONSE_name      (ocsptool_opt_strs+1766)
#define LOAD_RESPONSE_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_FILE))

/*
 *  Help/More_Help/Version option descriptions:
 */
#define HELP_DESC       (ocsptool_opt_strs+1780)
#define HELP_name       (ocsptool_opt_strs+1824)
#ifdef HAVE_WORKING_FORK
#define MORE_HELP_DESC  (ocsptool_opt_strs+1829)
#define MORE_HELP_name  (ocsptool_opt_strs+1874)
#define MORE_HELP_FLAGS (OPTST_IMM | OPTST_NO_INIT)
#else
#define MORE_HELP_DESC  NULL
#define MORE_HELP_name  NULL
#define MORE_HELP_FLAGS (OPTST_OMITTED | OPTST_NO_INIT)
#endif
#ifdef NO_OPTIONAL_OPT_ARGS
#  define VER_FLAGS     (OPTST_IMM | OPTST_NO_INIT)
#else
#  define VER_FLAGS     (OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | \
                         OPTST_ARG_OPTIONAL | OPTST_IMM | OPTST_NO_INIT)
#endif
#define VER_DESC        (ocsptool_opt_strs+1884)
#define VER_name        (ocsptool_opt_strs+1920)
/*
 *  Declare option callback procedures
 */
extern tOptProc
    optionBooleanVal,   optionNestedVal,    optionNumericVal,
    optionPagedUsage,   optionPrintVersion, optionResetOpt,
    optionStackArg,     optionTimeDate,     optionTimeVal,
    optionUnstackArg,   optionVendorOption;
static tOptProc
    doOptDebug,         doOptInfile,        doOptLoad_Cert,
    doOptLoad_Issuer,   doOptLoad_Request,  doOptLoad_Response,
    doOptLoad_Signer,   doOptLoad_Trust,    doUsageOpt;
#define VER_PROC        optionPrintVersion

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 *  Define the ocsptool Option Descriptions.
 * This is an array of OPTION_CT entries, one for each
 * option that the ocsptool program responds to.
 */
static tOptDesc optDesc[OPTION_CT] = {
  {  /* entry idx, value */ 0, VALUE_OPT_DEBUG,
     /* equiv idx, value */ 0, VALUE_OPT_DEBUG,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ DEBUG_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --debug */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptDebug,
     /* desc, NAME, name */ DEBUG_DESC, DEBUG_NAME, DEBUG_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 1, VALUE_OPT_VERBOSE,
     /* equiv idx, value */ 1, VALUE_OPT_VERBOSE,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, NOLIMIT, 0,
     /* opt state flags  */ VERBOSE_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --verbose */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ VERBOSE_DESC, VERBOSE_NAME, VERBOSE_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 2, VALUE_OPT_INFILE,
     /* equiv idx, value */ 2, VALUE_OPT_INFILE,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ INFILE_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --infile */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptInfile,
     /* desc, NAME, name */ INFILE_DESC, INFILE_NAME, INFILE_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 3, VALUE_OPT_OUTFILE,
     /* equiv idx, value */ 3, VALUE_OPT_OUTFILE,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OUTFILE_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --outfile */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ OUTFILE_DESC, OUTFILE_NAME, OUTFILE_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 4, VALUE_OPT_ASK,
     /* equiv idx, value */ 4, VALUE_OPT_ASK,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ ASK_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --ask */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ aAskMustList, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ ASK_DESC, ASK_NAME, ASK_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 5, VALUE_OPT_VERIFY_RESPONSE,
     /* equiv idx, value */ 5, VALUE_OPT_VERIFY_RESPONSE,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ VERIFY_RESPONSE_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --verify-response */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ VERIFY_RESPONSE_DESC, VERIFY_RESPONSE_NAME, VERIFY_RESPONSE_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 6, VALUE_OPT_REQUEST_INFO,
     /* equiv idx, value */ 6, VALUE_OPT_REQUEST_INFO,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ REQUEST_INFO_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --request-info */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ REQUEST_INFO_DESC, REQUEST_INFO_NAME, REQUEST_INFO_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 7, VALUE_OPT_RESPONSE_INFO,
     /* equiv idx, value */ 7, VALUE_OPT_RESPONSE_INFO,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ RESPONSE_INFO_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --response-info */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ RESPONSE_INFO_DESC, RESPONSE_INFO_NAME, RESPONSE_INFO_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 8, VALUE_OPT_GENERATE_REQUEST,
     /* equiv idx, value */ 8, VALUE_OPT_GENERATE_REQUEST,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ GENERATE_REQUEST_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --generate-request */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ GENERATE_REQUEST_DESC, GENERATE_REQUEST_NAME, GENERATE_REQUEST_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 9, VALUE_OPT_NONCE,
     /* equiv idx, value */ 9, VALUE_OPT_NONCE,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ NONCE_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --nonce */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ NONCE_DESC, NONCE_NAME, NONCE_name,
     /* disablement strs */ NOT_NONCE_name, NOT_NONCE_PFX },

  {  /* entry idx, value */ 10, VALUE_OPT_LOAD_ISSUER,
     /* equiv idx, value */ 10, VALUE_OPT_LOAD_ISSUER,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ LOAD_ISSUER_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --load-issuer */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptLoad_Issuer,
     /* desc, NAME, name */ LOAD_ISSUER_DESC, LOAD_ISSUER_NAME, LOAD_ISSUER_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 11, VALUE_OPT_LOAD_CERT,
     /* equiv idx, value */ 11, VALUE_OPT_LOAD_CERT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ LOAD_CERT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --load-cert */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptLoad_Cert,
     /* desc, NAME, name */ LOAD_CERT_DESC, LOAD_CERT_NAME, LOAD_CERT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 12, VALUE_OPT_LOAD_TRUST,
     /* equiv idx, value */ 12, VALUE_OPT_LOAD_TRUST,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ LOAD_TRUST_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --load-trust */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, aLoad_TrustCantList,
     /* option proc      */ doOptLoad_Trust,
     /* desc, NAME, name */ LOAD_TRUST_DESC, LOAD_TRUST_NAME, LOAD_TRUST_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 13, VALUE_OPT_LOAD_SIGNER,
     /* equiv idx, value */ 13, VALUE_OPT_LOAD_SIGNER,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ LOAD_SIGNER_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --load-signer */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, aLoad_SignerCantList,
     /* option proc      */ doOptLoad_Signer,
     /* desc, NAME, name */ LOAD_SIGNER_DESC, LOAD_SIGNER_NAME, LOAD_SIGNER_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 14, VALUE_OPT_INDER,
     /* equiv idx, value */ 14, VALUE_OPT_INDER,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ INDER_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --inder */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ INDER_DESC, INDER_NAME, INDER_name,
     /* disablement strs */ NOT_INDER_name, NOT_INDER_PFX },

  {  /* entry idx, value */ 15, VALUE_OPT_LOAD_REQUEST,
     /* equiv idx, value */ 15, VALUE_OPT_LOAD_REQUEST,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ LOAD_REQUEST_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --load-request */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptLoad_Request,
     /* desc, NAME, name */ LOAD_REQUEST_DESC, LOAD_REQUEST_NAME, LOAD_REQUEST_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 16, VALUE_OPT_LOAD_RESPONSE,
     /* equiv idx, value */ 16, VALUE_OPT_LOAD_RESPONSE,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ LOAD_RESPONSE_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --load-response */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptLoad_Response,
     /* desc, NAME, name */ LOAD_RESPONSE_DESC, LOAD_RESPONSE_NAME, LOAD_RESPONSE_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_VERSION, VALUE_OPT_VERSION,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_VERSION,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ VER_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ VER_PROC,
     /* desc, NAME, name */ VER_DESC, NULL, VER_name,
     /* disablement strs */ NULL, NULL },



  {  /* entry idx, value */ INDEX_OPT_HELP, VALUE_OPT_HELP,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_HELP,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OPTST_IMM | OPTST_NO_INIT, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doUsageOpt,
     /* desc, NAME, name */ HELP_DESC, NULL, HELP_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_MORE_HELP, VALUE_OPT_MORE_HELP,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_MORE_HELP,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ MORE_HELP_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL,  NULL,
     /* option proc      */ optionPagedUsage,
     /* desc, NAME, name */ MORE_HELP_DESC, NULL, MORE_HELP_name,
     /* disablement strs */ NULL, NULL }
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  Define the ocsptool Option Environment
 */
#define zPROGNAME       (ocsptool_opt_strs+1928)
#define zUsageTitle     (ocsptool_opt_strs+1937)
#define zRcName         NULL
#define apzHomeList     NULL
#define zBugsAddr       (ocsptool_opt_strs+2040)
#define zExplain        (ocsptool_opt_strs+2059)
#define zDetail         (ocsptool_opt_strs+2062)
#define zFullVersion    (ocsptool_opt_strs+2194)
/* extracted from optcode.tlib near line 350 */

#if defined(ENABLE_NLS)
# define OPTPROC_BASE OPTPROC_TRANSLATE | OPTPROC_NXLAT_OPT
  static tOptionXlateProc translate_option_strings;
#else
# define OPTPROC_BASE OPTPROC_NONE
# define translate_option_strings NULL
#endif /* ENABLE_NLS */


#define ocsptool_full_usage (NULL)

#define ocsptool_short_usage (ocsptool_opt_strs+2213)

#endif /* not defined __doxygen__ */

/*
 *  Create the static procedure(s) declared above.
 */
/**
 * The callout function that invokes the optionUsage function.
 *
 * @param pOptions the AutoOpts option description structure
 * @param pOptDesc the descriptor for the "help" (usage) option.
 * @noreturn
 */
static void
doUsageOpt(tOptions * pOptions, tOptDesc * pOptDesc)
{
    optionUsage(&ocsptoolOptions, OCSPTOOL_EXIT_SUCCESS);
    /* NOTREACHED */
    (void)pOptDesc;
    (void)pOptions;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the debug option.
 *
 * @param pOptions the ocsptool options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptDebug(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static struct {long rmin, rmax;} const rng[1] = {
        { 0 ,  9999 } };
    int  ix;

    if (pOptions <= OPTPROC_EMIT_LIMIT)
        goto emit_ranges;
    optionNumericVal(pOptions, pOptDesc);

    for (ix = 0; ix < 1; ix++) {
        if (pOptDesc->optArg.argInt < rng[ix].rmin)
            continue;  /* ranges need not be ordered. */
        if (pOptDesc->optArg.argInt == rng[ix].rmin)
            return;
        if (rng[ix].rmax == LONG_MIN)
            continue;
        if (pOptDesc->optArg.argInt <= rng[ix].rmax)
            return;
    }

    option_usage_fp = stderr;

emit_ranges:

    optionShowRange(pOptions, pOptDesc, (void *)rng, 1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the infile option.
 *
 * @param pOptions the ocsptool options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptInfile(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static teOptFileType const  type =
        FTYPE_MODE_MUST_EXIST + FTYPE_MODE_NO_OPEN;
    static tuFileMode           mode;
#ifndef O_CLOEXEC
#  define O_CLOEXEC 0
#endif
    mode.file_flags = O_CLOEXEC;

    optionFileCheck(pOptions, pOptDesc, type, mode);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the load-issuer option.
 *
 * @param pOptions the ocsptool options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptLoad_Issuer(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static teOptFileType const  type =
        FTYPE_MODE_MUST_EXIST + FTYPE_MODE_NO_OPEN;
    static tuFileMode           mode;
#ifndef O_CLOEXEC
#  define O_CLOEXEC 0
#endif
    mode.file_flags = O_CLOEXEC;

    optionFileCheck(pOptions, pOptDesc, type, mode);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the load-cert option.
 *
 * @param pOptions the ocsptool options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptLoad_Cert(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static teOptFileType const  type =
        FTYPE_MODE_MUST_EXIST + FTYPE_MODE_NO_OPEN;
    static tuFileMode           mode;
#ifndef O_CLOEXEC
#  define O_CLOEXEC 0
#endif
    mode.file_flags = O_CLOEXEC;

    optionFileCheck(pOptions, pOptDesc, type, mode);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the load-trust option.
 *
 * @param pOptions the ocsptool options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptLoad_Trust(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static teOptFileType const  type =
        FTYPE_MODE_MUST_EXIST + FTYPE_MODE_NO_OPEN;
    static tuFileMode           mode;
#ifndef O_CLOEXEC
#  define O_CLOEXEC 0
#endif
    mode.file_flags = O_CLOEXEC;

    optionFileCheck(pOptions, pOptDesc, type, mode);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the load-signer option.
 *
 * @param pOptions the ocsptool options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptLoad_Signer(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static teOptFileType const  type =
        FTYPE_MODE_MUST_EXIST + FTYPE_MODE_NO_OPEN;
    static tuFileMode           mode;
#ifndef O_CLOEXEC
#  define O_CLOEXEC 0
#endif
    mode.file_flags = O_CLOEXEC;

    optionFileCheck(pOptions, pOptDesc, type, mode);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the load-request option.
 *
 * @param pOptions the ocsptool options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptLoad_Request(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static teOptFileType const  type =
        FTYPE_MODE_MUST_EXIST + FTYPE_MODE_NO_OPEN;
    static tuFileMode           mode;
#ifndef O_CLOEXEC
#  define O_CLOEXEC 0
#endif
    mode.file_flags = O_CLOEXEC;

    optionFileCheck(pOptions, pOptDesc, type, mode);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the load-response option.
 *
 * @param pOptions the ocsptool options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptLoad_Response(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static teOptFileType const  type =
        FTYPE_MODE_MUST_EXIST + FTYPE_MODE_NO_OPEN;
    static tuFileMode           mode;
#ifndef O_CLOEXEC
#  define O_CLOEXEC 0
#endif
    mode.file_flags = O_CLOEXEC;

    optionFileCheck(pOptions, pOptDesc, type, mode);
}
/* extracted from optmain.tlib near line 1113 */

/**
 * The directory containing the data associated with ocsptool.
 */
#ifndef  PKGDATADIR
# define PKGDATADIR ""
#endif

/**
 * Information about the person or institution that packaged ocsptool
 * for the current distribution.
 */
#ifndef  WITH_PACKAGER
# define ocsptool_packager_info NULL
#else
static char const ocsptool_packager_info[] =
    "Packaged by " WITH_PACKAGER

# ifdef WITH_PACKAGER_VERSION
        " ("WITH_PACKAGER_VERSION")"
# endif

# ifdef WITH_PACKAGER_BUG_REPORTS
    "\nReport ocsptool bugs to " WITH_PACKAGER_BUG_REPORTS
# endif
    "\n";
#endif
#ifndef __doxygen__

#endif /* __doxygen__ */
/**
 * The option definitions for ocsptool.  The one structure that
 * binds them all.
 */
tOptions ocsptoolOptions = {
    OPTIONS_STRUCT_VERSION,
    0, NULL,                    /* original argc + argv    */
    ( OPTPROC_BASE
    + OPTPROC_ERRSTOP
    + OPTPROC_SHORTOPT
    + OPTPROC_LONGOPT
    + OPTPROC_NO_REQ_OPT
    + OPTPROC_NEGATIONS
    + OPTPROC_NO_ARGS
    + OPTPROC_GNUUSAGE
    + OPTPROC_MISUSE ),
    0, NULL,                    /* current option index, current option */
    NULL,         NULL,         zPROGNAME,
    zRcName,      zCopyright,   zLicenseDescrip,
    zFullVersion, apzHomeList,  zUsageTitle,
    zExplain,     zDetail,      optDesc,
    zBugsAddr,                  /* address to send bugs to */
    NULL, NULL,                 /* extensions/saved state  */
    optionUsage, /* usage procedure */
    translate_option_strings,   /* translation procedure */
    /*
     *  Indexes to special options
     */
    { INDEX_OPT_MORE_HELP, /* more-help option index */
      NO_EQUIVALENT, /* save option index */
      NO_EQUIVALENT, /* '-#' option index */
      NO_EQUIVALENT /* index of default opt */
    },
    20 /* full option count */, 17 /* user option count */,
    ocsptool_full_usage, ocsptool_short_usage,
    NULL, NULL,
    PKGDATADIR, ocsptool_packager_info
};

#if ENABLE_NLS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <autoopts/usage-txt.h>

static char* AO_gettext(char const* pz);
static void  coerce_it(void** s);

/**
 * AutoGen specific wrapper function for gettext.
 * It relies on the macro _() to convert from English to the target
 * language, then strdup-duplicates the result string.
 *
 * @param[in] pz the input text used as a lookup key.
 * @returns the translated text (if there is one),
 *   or the original text (if not).
 */
static char *
AO_gettext(char const* pz)
{
    char* pzRes;
    if (pz == NULL)
        return NULL;
    pzRes = _(pz);
    if (pzRes == pz)
        return pzRes;
    pzRes = strdup(pzRes);
    if (pzRes == NULL) {
        fputs(_("No memory for duping translated strings\n"), stderr);
        exit(OCSPTOOL_EXIT_FAILURE);
    }
    return pzRes;
}

static void coerce_it(void** s) { *s = AO_gettext(*s);
}

/**
 * Translate all the translatable strings in the ocsptoolOptions
 * structure defined above.  This is done only once.
 */
static void
translate_option_strings(void)
{
    tOptions * const pOpt = &ocsptoolOptions;

    /*
     *  Guard against re-translation.  It won't work.  The strings will have
     *  been changed by the first pass through this code.  One shot only.
     */
    if (option_usage_text.field_ct != 0) {
        /*
         *  Do the translations.  The first pointer follows the field count
         *  field.  The field count field is the size of a pointer.
         */
        tOptDesc * pOD = pOpt->pOptDesc;
        char **    ppz = (char**)(void*)&(option_usage_text);
        int        ix  = option_usage_text.field_ct;

        do {
            ppz++;
            *ppz = AO_gettext(*ppz);
        } while (--ix > 0);

        coerce_it((void*)&(pOpt->pzCopyright));
        coerce_it((void*)&(pOpt->pzCopyNotice));
        coerce_it((void*)&(pOpt->pzFullVersion));
        coerce_it((void*)&(pOpt->pzUsageTitle));
        coerce_it((void*)&(pOpt->pzExplain));
        coerce_it((void*)&(pOpt->pzDetail));
        coerce_it((void*)&(pOpt->pzPackager));
        coerce_it((void*)&(pOpt->pzShortUsage));
        option_usage_text.field_ct = 0;

        for (ix = pOpt->optCt; ix > 0; ix--, pOD++)
            coerce_it((void*)&(pOD->pzText));
    }

    if ((pOpt->fOptSet & OPTPROC_NXLAT_OPT_CFG) == 0) {
        tOptDesc * pOD = pOpt->pOptDesc;
        int        ix;

        for (ix = pOpt->optCt; ix > 0; ix--, pOD++) {
            coerce_it((void*)&(pOD->pz_Name));
            coerce_it((void*)&(pOD->pz_DisableName));
            coerce_it((void*)&(pOD->pz_DisablePfx));
        }
        /* prevent re-translation */
        ocsptoolOptions.fOptSet |= OPTPROC_NXLAT_OPT_CFG | OPTPROC_NXLAT_OPT;
    }
}

#endif /* ENABLE_NLS */

#ifdef  __cplusplus
}
#endif
/* ocsptool-args.c ends here */
