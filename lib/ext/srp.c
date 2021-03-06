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

#include <gnutls_int.h>
#include <ext/srp.h>

#ifdef ENABLE_SRP

#include "gnutls_auth.h"
#include <auth/srp.h>
#include "gnutls_errors.h"
#include "algorithms.h"
#include <gnutls_num.h>
#include <gnutls_extensions.h>

static int _gnutls_srp_unpack (gnutls_buffer_st * ps,
                               extension_priv_data_t * _priv);
static int _gnutls_srp_pack (extension_priv_data_t epriv,
                             gnutls_buffer_st * ps);
static void _gnutls_srp_deinit_data (extension_priv_data_t epriv);
static int _gnutls_srp_recv_params (gnutls_session_t state,
                                    const uint8_t * data, size_t data_size);
static int _gnutls_srp_send_params (gnutls_session_t state, gnutls_buffer_st * extdata);

extension_entry_st ext_mod_srp = {
  .name = "SRP",
  .type = GNUTLS_EXTENSION_SRP,
  .parse_type = GNUTLS_EXT_TLS,

  .recv_func = _gnutls_srp_recv_params,
  .send_func = _gnutls_srp_send_params,
  .pack_func = _gnutls_srp_pack,
  .unpack_func = _gnutls_srp_unpack,
  .deinit_func = _gnutls_srp_deinit_data
};


static int
_gnutls_srp_recv_params (gnutls_session_t session, const uint8_t * data,
                         size_t _data_size)
{
  uint8_t len;
  ssize_t data_size = _data_size;
  extension_priv_data_t epriv;
  srp_ext_st *priv;

  if (session->security_parameters.entity == GNUTLS_SERVER)
    {
      if (data_size > 0)
        {
          len = data[0];
          DECR_LEN (data_size, len);

          if (MAX_USERNAME_SIZE < len)
            {
              gnutls_assert ();
              return GNUTLS_E_ILLEGAL_SRP_USERNAME;
            }

          priv = gnutls_calloc (1, sizeof (*priv));
          if (priv == NULL)
            {
              gnutls_assert ();
              return GNUTLS_E_MEMORY_ERROR;
            }

          priv->username = gnutls_malloc (len + 1);
          if (priv->username)
            {
              memcpy (priv->username, &data[1], len);
              /* null terminated */
              priv->username[len] = 0;
            }

          epriv.ptr = priv;
          _gnutls_ext_set_session_data (session, GNUTLS_EXTENSION_SRP, epriv);
        }
    }
  return 0;
}

/* returns data_size or a negative number on failure
 * data is allocated locally
 */
static int
_gnutls_srp_send_params (gnutls_session_t session, 
    gnutls_buffer_st * extdata)
{
  unsigned len;
  int ret;
  extension_priv_data_t epriv;
  srp_ext_st *priv = NULL;
  char *username = NULL, *password = NULL;

  if (_gnutls_kx_priority (session, GNUTLS_KX_SRP) < 0 &&
      _gnutls_kx_priority (session, GNUTLS_KX_SRP_DSS) < 0 &&
      _gnutls_kx_priority (session, GNUTLS_KX_SRP_RSA) < 0)
    {
      /* algorithm was not allowed in this session
       */
      return 0;
    }

  /* this function sends the client extension data (username) */
  if (session->security_parameters.entity == GNUTLS_CLIENT)
    {
      gnutls_srp_client_credentials_t cred = (gnutls_srp_client_credentials_t)
        _gnutls_get_cred (session, GNUTLS_CRD_SRP, NULL);

      if (cred == NULL)
        return 0;

      priv = gnutls_malloc (sizeof (*priv));
      if (priv == NULL)
        return gnutls_assert_val(GNUTLS_E_MEMORY_ERROR);

      if (cred->username != NULL)
        {                       /* send username */
          len = MIN (strlen (cred->username), 255);

          ret = _gnutls_buffer_append_data_prefix(extdata, 8, cred->username, len);
          if (ret < 0)
            {
              gnutls_assert();
              goto cleanup;
            }

          priv->username = strdup(cred->username);
          if (priv->username == NULL)
            {
              gnutls_assert();
              goto cleanup;
            }

          priv->password = strdup(cred->password);
          if (priv->password == NULL)
            {
              gnutls_assert();
              goto cleanup;
            }

          epriv.ptr = priv;
          _gnutls_ext_set_session_data (session, GNUTLS_EXTENSION_SRP, epriv);

          return len + 1;
        }
      else if (cred->get_function != NULL)
        {
          /* Try the callback
           */

          if (cred->get_function (session, &username, &password) < 0
              || username == NULL || password == NULL)
            {
              gnutls_assert ();
              return GNUTLS_E_ILLEGAL_SRP_USERNAME;
            }

          len = MIN (strlen (username), 255);

          priv->username = username;
          priv->password = password;

          ret = _gnutls_buffer_append_data_prefix(extdata, 8, username, len);
          if (ret < 0)
            {
              ret = gnutls_assert_val(ret);
              goto cleanup;
            }

          epriv.ptr = priv;
          _gnutls_ext_set_session_data (session, GNUTLS_EXTENSION_SRP, epriv);

          return len + 1;
        }
    }
  return 0;

cleanup:
  gnutls_free (username);
  gnutls_free (password);
  gnutls_free (priv);
  
  return ret;
}

static void
_gnutls_srp_deinit_data (extension_priv_data_t epriv)
{
  srp_ext_st *priv = epriv.ptr;

  gnutls_free (priv->username);
  gnutls_free (priv->password);
  gnutls_free (priv);
}

static int
_gnutls_srp_pack (extension_priv_data_t epriv, gnutls_buffer_st * ps)
{
  srp_ext_st *priv = epriv.ptr;
  int ret;
  int password_len = 0, username_len = 0;

  if (priv->username)
    username_len = strlen (priv->username);

  if (priv->password)
    password_len = strlen (priv->password);

  BUFFER_APPEND_PFX4 (ps, priv->username, username_len);
  BUFFER_APPEND_PFX4 (ps, priv->password, password_len);

  return 0;
}

static int
_gnutls_srp_unpack (gnutls_buffer_st * ps, extension_priv_data_t * _priv)
{
  srp_ext_st *priv;
  int ret;
  extension_priv_data_t epriv;
  gnutls_datum_t username = { NULL, 0 };
  gnutls_datum_t password = { NULL, 0 };

  priv = gnutls_calloc (1, sizeof (*priv));
  if (priv == NULL)
    {
      gnutls_assert ();
      return GNUTLS_E_MEMORY_ERROR;
    }

  BUFFER_POP_DATUM (ps, &username);
  BUFFER_POP_DATUM (ps, &password);

  priv->username = (char*)username.data;
  priv->password = (char*)password.data;

  epriv.ptr = priv;
  *_priv = epriv;

  return 0;

error:
  _gnutls_free_datum (&username);
  _gnutls_free_datum (&password);
  return ret;
}


#endif /* ENABLE_SRP */
