/*
 * Copyright (C) 2001-2012 Free Software Foundation, Inc.
 *
 * Author: Nikos Mavrogiannopoulos
 *
 * This file is part of GnuTLS.
 *
 * The GnuTLS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 */

#include "gnutls_int.h"
#include "gnutls_errors.h"
#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
#include <gnutls_mpi.h>

#ifdef DEBUG
void
_gnutls_dump_mpi (const char *prefix, bigint_t a)
{
  char buf[400];
  char buf_hex[2 * sizeof (buf)];
  size_t n = sizeof buf;

  if (_gnutls_mpi_print (a, buf, &n))
    strcpy (buf, "[can't print value]");        /* Flawfinder: ignore */
  _gnutls_debug_log ("MPI: length: %d\n\t%s%s\n", (int) n, prefix,
                     _gnutls_bin2hex (buf, n, buf_hex, sizeof (buf_hex),
                                      NULL));
}
#endif

const char *
_gnutls_packet2str (content_type_t packet)
{
  switch (packet)
    {
    case GNUTLS_CHANGE_CIPHER_SPEC:
      return "ChangeCipherSpec";
    case GNUTLS_ALERT:
      return "Alert";
    case GNUTLS_HANDSHAKE:
      return "Handshake";
    case GNUTLS_APPLICATION_DATA:
      return "Application Data";
    case GNUTLS_HEARTBEAT:
      return "HeartBeat";
    default:
      return "Unknown Packet";
    }
}

const char *
_gnutls_handshake2str (gnutls_handshake_description_t handshake)
{

  switch (handshake)
    {
    case GNUTLS_HANDSHAKE_HELLO_REQUEST:
      return "HELLO REQUEST";
      break;
    case GNUTLS_HANDSHAKE_CLIENT_HELLO:
      return "CLIENT HELLO";
      break;
    case GNUTLS_HANDSHAKE_CLIENT_HELLO_V2:
      return "SSL2 CLIENT HELLO";
      break;
    case GNUTLS_HANDSHAKE_SERVER_HELLO:
      return "SERVER HELLO";
      break;
    case GNUTLS_HANDSHAKE_HELLO_VERIFY_REQUEST:
      return "HELLO VERIFY REQUEST";
      break;
    case GNUTLS_HANDSHAKE_CERTIFICATE_PKT:
      return "CERTIFICATE";
      break;
    case GNUTLS_HANDSHAKE_SERVER_KEY_EXCHANGE:
      return "SERVER KEY EXCHANGE";
      break;
    case GNUTLS_HANDSHAKE_CERTIFICATE_REQUEST:
      return "CERTIFICATE REQUEST";
      break;
    case GNUTLS_HANDSHAKE_SERVER_HELLO_DONE:
      return "SERVER HELLO DONE";
      break;
    case GNUTLS_HANDSHAKE_CERTIFICATE_VERIFY:
      return "CERTIFICATE VERIFY";
      break;
    case GNUTLS_HANDSHAKE_CLIENT_KEY_EXCHANGE:
      return "CLIENT KEY EXCHANGE";
      break;
    case GNUTLS_HANDSHAKE_FINISHED:
      return "FINISHED";
      break;
    case GNUTLS_HANDSHAKE_SUPPLEMENTAL:
      return "SUPPLEMENTAL";
      break;
    case GNUTLS_HANDSHAKE_CERTIFICATE_STATUS:
      return "CERTIFICATE STATUS";
      break;
    case GNUTLS_HANDSHAKE_NEW_SESSION_TICKET:
      return "NEW SESSION TICKET";
      break;
    case GNUTLS_HANDSHAKE_CHANGE_CIPHER_SPEC:
      return "CHANGE CIPHER SPEC";
      break;
    default:
      return "Unknown Handshake packet";

    }
}
