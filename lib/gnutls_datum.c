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

/* contains functions that make it easier to
 * write vectors of <size|data>. The destination size
 * should be preallocated (datum.size+(bits/8))
 */

#include <gnutls_int.h>
#include <gnutls_num.h>
#include <gnutls_datum.h>
#include <gnutls_errors.h>

int
_gnutls_set_datum (gnutls_datum_t * dat, const void *data,
                     size_t data_size)
{
  if (data_size == 0 || data == NULL)
    {
      dat->data = NULL;
      dat->size = 0;
      return 0;
    }

  dat->data = gnutls_malloc (data_size);
  if (dat->data == NULL)
    return GNUTLS_E_MEMORY_ERROR;

  dat->size = data_size;
  memcpy (dat->data, data, data_size);

  return 0;
}

int
_gnutls_datum_append (gnutls_datum_t * dst, const void *data,
                        size_t data_size)
{

  dst->data = gnutls_realloc (dst->data, data_size + dst->size);
  if (dst->data == NULL)
    return GNUTLS_E_MEMORY_ERROR;

  memcpy (&dst->data[dst->size], data, data_size);
  dst->size += data_size;

  return 0;
}

void
_gnutls_free_datum (gnutls_datum_t * dat)
{
  if (dat->data != NULL)
    gnutls_free (dat->data);

  dat->data = NULL;
  dat->size = 0;
}
