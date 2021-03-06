/*
 * Copyright (C) 2012 Free Software Foundation, Inc.
 *
 * Author: Olga Smolenchuk
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

#include <gnutls_errors.h>
#include <gnutls_int.h>
#include <gnutls_dtls.h>
#include <gnutls_record.h>
#include <ext/heartbeat.h>
#include <gnutls_extensions.h>
#include <random.h>

/**
  * gnutls_heartbeat_enable:
  * @session: is a #gnutls_session_t structure.
  * @type: one of the GNUTLS_HB_* flags
  *
  * This function will allow heartbeat messages to be
  * received.
  *
  * Since: 3.1.2
  **/
void
gnutls_heartbeat_enable (gnutls_session_t session, unsigned int type)
{
  extension_priv_data_t epriv;

  epriv.num = type;
  _gnutls_ext_set_session_data (session, GNUTLS_EXTENSION_HEARTBEAT,
                                epriv);
}

/*-
 * Convenience helper:
 *
 * Returns:
 * textual policy description or NULL.
 -*/
static inline const char *
_gnutls_heartbeat (unsigned policy)
{
  if (policy & GNUTLS_HB_PEER_ALLOWED_TO_SEND)
    return "PEER ALLOWED TO SEND";
  else if (policy & GNUTLS_HB_PEER_NOT_ALLOWED_TO_SEND)
    return "PEER NOT ALLOWED TO SEND";
  return "Unknown policy";
}

/**
  * gnutls_heartbeat_allowed:
  * @session: is a #gnutls_session_t structure.
  * @type: one of %GNUTLS_HB_LOCAL_ALLOWED_TO_SEND and %GNUTLS_HB_PEER_ALLOWED_TO_SEND
  *
  * This function will check whether heartbeats are allowed
  * to be sent or received in this session. 
  *
  * Returns: Non zero if heartbeats are allowed.
  *
  * Since: 3.1.2
  **/
int
gnutls_heartbeat_allowed (gnutls_session_t session, unsigned int type)
{
  extension_priv_data_t epriv;

  if (_gnutls_ext_get_session_data
      (session, GNUTLS_EXTENSION_HEARTBEAT, &epriv) < 0)
    return 0;                   /* Not enabled */

  if (type == GNUTLS_HB_LOCAL_ALLOWED_TO_SEND)
    {
      if (epriv.num & LOCAL_ALLOWED_TO_SEND)
        return 1;
    }
  else if (epriv.num & GNUTLS_HB_PEER_ALLOWED_TO_SEND)
    return 1;
    
  return 0;
}

static int
heartbeat_allow_recv (gnutls_session_t session)
{
  return gnutls_heartbeat_allowed(session, GNUTLS_HB_PEER_ALLOWED_TO_SEND);
}

static int
heartbeat_allow_send (gnutls_session_t session)
{
  return gnutls_heartbeat_allowed(session, GNUTLS_HB_LOCAL_ALLOWED_TO_SEND);
}

#define DEFAULT_PAYLOAD_SIZE 16

/*-
 * heartbeat_send_data:
 * @session: is a #gnutls_session_t structure.
 * @data: contains the data to send.
 * @data_size: is the length of the data.
 * @start_timer: true if the heartbeat timer is to be started.
 *
 * This function has the similar semantics with gnutls_record_send() The only
 * difference is that it uses GNUTLS_HEARTBEAT content type.
 *
 * This function send either HeartBeat request or response message
 * with proper padding. It set timeout and timestamp without check - it's up to
 * caller to make sure no messages are already in-flight and handle timeout expiration.
 *
 * Returns: The number of bytes sent, or a negative error code.  The
 *   number of bytes sent might be less than @data_size.  The maximum
 *   number of bytes this function can send in a single call depends
 *   on the negotiated maximum record size.
 -*/
static int
heartbeat_send_data (gnutls_session_t session, const void *data,
                     size_t data_size, uint8_t type)
{
  int ret;
  gnutls_buffer_st response;
  uint8_t payload[DEFAULT_PAYLOAD_SIZE];
  _gnutls_buffer_init (&response);

  ret = gnutls_rnd (GNUTLS_RND_RANDOM, payload, DEFAULT_PAYLOAD_SIZE);
  if (ret < 0)
    return gnutls_assert_val(ret);

  BUFFER_APPEND (&response, &type, 1);
  BUFFER_APPEND_PFX2 (&response, data, data_size);

  BUFFER_APPEND (&response, payload, DEFAULT_PAYLOAD_SIZE);
  ret = _gnutls_send_int (session, GNUTLS_HEARTBEAT, -1,
                          EPOCH_WRITE_CURRENT, response.data,
                          response.length, MBUFFER_FLUSH);

  _gnutls_record_log ("REC[%p]: HB sent: %d\n", session, ret);

  _gnutls_buffer_clear (&response);
  return ret;
}

/**
 * gnutls_heartbeat_ping:
 * @session: is a #gnutls_session_t structure.
 * @data_size: is the length of the ping payload.
 * @max_tries: if flags is %GNUTLS_HEARTBEAT_WAIT then this sets the number of retransmissions. Use zero for indefinite (until timeout).
 * @flags: if %GNUTLS_HEARTBEAT_WAIT then wait for pong or timeout instead of returning immediately.
 *
 * This function sends a ping to the peer. If the @flags is set
 * to %GNUTLS_HEARTBEAT_WAIT then it waits for a reply from the peer.
 * 
 * Note that it is highly recommended to use this function with the
 * flag %GNUTLS_HEARTBEAT_WAIT, or you need to handle retransmissions
 * and timeouts manually.
 *
 * Returns: %GNUTLS_E_SUCCESS on success, otherwise a negative error code.
 *
 * Since: 3.1.2
 **/
int
gnutls_heartbeat_ping (gnutls_session_t session, size_t data_size, 
                       unsigned int max_tries, unsigned int flags)
{
  int ret;
  unsigned int retries = 1, diff;
  struct timespec now;

  if (data_size > MAX_HEARTBEAT_LENGTH)
    return gnutls_assert_val (GNUTLS_E_UNEXPECTED_PACKET_LENGTH);

  if (!heartbeat_allow_send (session))
    return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);
  
  switch(session->internals.hb_state)
    {
      case SHB_SEND1:
        _gnutls_record_log
         ("REC[%p]: sending HB_REQUEST with length: %zu to peer\n", session, data_size);
         
        if (data_size > DEFAULT_PAYLOAD_SIZE)
          data_size -= DEFAULT_PAYLOAD_SIZE;
        else
          data_size = 0;

        _gnutls_buffer_reset(&session->internals.hb_local_data);

        ret = _gnutls_buffer_resize (&session->internals.hb_local_data, data_size);
        if (ret < 0)
          return gnutls_assert_val(ret);

        ret = _gnutls_rnd (GNUTLS_RND_NONCE, session->internals.hb_local_data.data, data_size);
        if (ret < 0)
          return gnutls_assert_val(ret);

        gettime (&session->internals.hb_ping_start);
        session->internals.hb_local_data.length = data_size;
        session->internals.hb_state = SHB_SEND2;
      case SHB_SEND2:
        session->internals.hb_actual_retrans_timeout_ms = session->internals.hb_retrans_timeout_ms;
retry:
        ret = heartbeat_send_data (session, session->internals.hb_local_data.data, 
                                   session->internals.hb_local_data.length, 
                                   HEARTBEAT_REQUEST);
        if (ret < 0)
          return gnutls_assert_val(ret);

        gettime (&session->internals.hb_ping_sent);
            
        if (!(flags & GNUTLS_HEARTBEAT_WAIT))
          {
            session->internals.hb_state = SHB_SEND1;
            break;
          }
        
        session->internals.hb_state = SHB_RECV;

      case SHB_RECV:
        ret = _gnutls_recv_int(session, GNUTLS_HEARTBEAT, -1, NULL, 0, NULL, session->internals.hb_actual_retrans_timeout_ms);
        if (ret == GNUTLS_E_HEARTBEAT_PONG_RECEIVED)
          {
            session->internals.hb_state = SHB_SEND1;
            break;
          }
        else if (ret == GNUTLS_E_TIMEDOUT)
          {
            retries++;
            if (max_tries > 0 && retries > max_tries)
              {
                session->internals.hb_state = SHB_SEND1;
                return gnutls_assert_val(ret);
              }

            gettime(&now);
            diff = _dtls_timespec_sub_ms(&now, &session->internals.hb_ping_start);
            if (diff > session->internals.hb_total_timeout_ms)
              {
                session->internals.hb_state = SHB_SEND1;
                return gnutls_assert_val(GNUTLS_E_TIMEDOUT);
              }

            session->internals.hb_actual_retrans_timeout_ms *= 2;
            session->internals.hb_actual_retrans_timeout_ms %= MAX_DTLS_TIMEOUT;
            
            session->internals.hb_state = SHB_SEND2;
            goto retry;
          }
        else if (ret < 0)
          {
            session->internals.hb_state = SHB_SEND1;
            return gnutls_assert_val(ret);
          }
    }

  return 0;
}

/**
 * gnutls_heartbeat_pong:
 * @session: is a #gnutls_session_t structure.
 * @flags: should be zero
 *
 * This function replies to a ping by sending a pong to the peer.
 *
 * Returns: %GNUTLS_E_SUCCESS on success, otherwise a negative error code.
 *
 * Since: 3.1.2
 **/
int
gnutls_heartbeat_pong (gnutls_session_t session, unsigned int flags)
{
int ret;

  if (session->internals.hb_remote_data.length == 0)
    return gnutls_assert_val(GNUTLS_E_INVALID_REQUEST);

  ret = heartbeat_send_data (session, session->internals.hb_remote_data.data, 
                             session->internals.hb_remote_data.length, 
                             HEARTBEAT_RESPONSE);

  _gnutls_buffer_reset (&session->internals.hb_remote_data);
  return ret;
}

/*-
 * Process HB message in buffer.
 * @bufel: the (suspected) HeartBeat message (TLV+padding)
 *
 * Returns:
 * processing result
 * GNUTLS_E_AGAIN if processed OK
 * GNUTLS_E_HEARTBEAT_PONG_FAILED on response send failure for request message
 * GNUTLS_E_RECEIVED_ILLEGAL_PARAMETER on payload mismatch for response message
 -*/
int
_gnutls_heartbeat_handle (gnutls_session_t session, mbuffer_st * bufel)
{
  char pr[128];
  int ret;
  uint8_t *msg = _mbuffer_get_udata_ptr (bufel);
  size_t hb_len, len = _mbuffer_get_udata_size (bufel);

  if (!heartbeat_allow_recv (session))
    return gnutls_assert_val (GNUTLS_E_UNEXPECTED_PACKET);

  if (len < 4)
    return gnutls_assert_val (GNUTLS_E_UNEXPECTED_PACKET_LENGTH);

  hb_len = _gnutls_read_uint16 (msg + 1);
  if (hb_len > len - 3)
    return gnutls_assert_val (GNUTLS_E_UNEXPECTED_PACKET);
  
  switch (msg[0])
    {
    case HEARTBEAT_REQUEST:
      _gnutls_record_log
          ("REC[%p]: received HEARTBEAT_REQUEST\n", session);

      _gnutls_buffer_reset(&session->internals.hb_remote_data);

      ret = _gnutls_buffer_resize (&session->internals.hb_remote_data, hb_len);
      if (ret < 0)
        return gnutls_assert_val(ret);
      
      if (hb_len > 0)
        memcpy(session->internals.hb_remote_data.data, msg+3, hb_len);
      session->internals.hb_remote_data.length = hb_len;

      return gnutls_assert_val(GNUTLS_E_HEARTBEAT_PING_RECEIVED);

    case HEARTBEAT_RESPONSE:

      if (hb_len != session->internals.hb_local_data.length)
        return gnutls_assert_val (GNUTLS_E_UNEXPECTED_PACKET);

      if (hb_len > 0 && memcmp (msg + 3, session->internals.hb_local_data.data,
                  hb_len) != 0)
        {
          _gnutls_record_log ("REC[%p]: HB: %s - received\n", session,
                              _gnutls_bin2hex (msg + 3, hb_len, pr,
                                               sizeof (pr), NULL));
          return gnutls_assert_val (GNUTLS_E_UNEXPECTED_PACKET);
        }

      _gnutls_buffer_reset (&session->internals.hb_local_data);

      return gnutls_assert_val(GNUTLS_E_HEARTBEAT_PONG_RECEIVED);
    default:
      _gnutls_record_log
          ("REC[%p]: HB: received unknown type %u\n",
           session, msg[0]);
      return gnutls_assert_val (GNUTLS_E_UNEXPECTED_PACKET);
    }
}

/**
 * gnutls_heartbeat_get_timeout:
 * @session: is a #gnutls_session_t structure.
 *
 * This function will return the milliseconds remaining
 * for a retransmission of the previously sent ping
 * message. This function is useful when ping is used in
 * non-blocking mode, to estimate when to call gnutls_heartbeat_ping()
 * if no packets have been received.
 *
 * Returns: the remaining time in milliseconds.
 *
 * Since: 3.1.2
 **/
unsigned int gnutls_heartbeat_get_timeout (gnutls_session_t session)
{
struct timespec now;
unsigned int diff;

  gettime(&now);
  diff = _dtls_timespec_sub_ms(&now, &session->internals.hb_ping_sent);
  if (diff >= session->internals.hb_actual_retrans_timeout_ms)
    return 0;
  else
    return session->internals.hb_actual_retrans_timeout_ms - diff;
}

/**
 * gnutls_heartbeat_set_timeouts:
 * @session: is a #gnutls_session_t structure.
 * @retrans_timeout: The time at which a retransmission will occur in milliseconds
 * @total_timeout: The time at which the connection will be aborted, in milliseconds.
 *
 * This function will set the timeouts required for the DTLS handshake
 * protocol. The retransmission timeout is the time after which a
 * message from the peer is not received, the previous messages will
 * be retransmitted. The total timeout is the time after which the
 * handshake will be aborted with %GNUTLS_E_TIMEDOUT.
 *
 * The DTLS protocol recommends the values of 1 sec and 60 seconds
 * respectively.
 *
 * If the retransmission timeout is zero then the handshake will operate
 * in a non-blocking way, i.e., return %GNUTLS_E_AGAIN.
 *
 * Since: 3.1.2
 **/
void gnutls_heartbeat_set_timeouts (gnutls_session_t session, unsigned int retrans_timeout,
                                    unsigned int total_timeout)
{
  session->internals.hb_retrans_timeout_ms = retrans_timeout;
  session->internals.hb_total_timeout_ms = total_timeout;
}


static int
_gnutls_heartbeat_recv_params (gnutls_session_t session,
                               const uint8_t * data, size_t _data_size)
{
  heartbeat_policy_t pol;
  extension_priv_data_t epriv;

  if (_gnutls_ext_get_session_data
      (session, GNUTLS_EXTENSION_HEARTBEAT, &epriv) < 0)
    {
      if (session->security_parameters.entity == GNUTLS_CLIENT)
        return gnutls_assert_val (GNUTLS_E_RECEIVED_ILLEGAL_PARAMETER);
      return 0; /* Not enabled */
    }

  if (_data_size == 0)
    return GNUTLS_E_UNEXPECTED_PACKET_LENGTH;

  _gnutls_debug_log ("HB: received parameter %u (%zu bytes)\n",
                     (unsigned)data[0], _data_size);

  pol = epriv.num;

  switch (data[0])
    {
    case 1:
      pol |= LOCAL_ALLOWED_TO_SEND;
      break;
    case 2:
      pol |= LOCAL_NOT_ALLOWED_TO_SEND;
      break;
    default:
      return gnutls_assert_val (GNUTLS_E_RECEIVED_ILLEGAL_PARAMETER);
    }

  epriv.num = pol;
  _gnutls_ext_set_session_data (session, GNUTLS_EXTENSION_HEARTBEAT,
                                epriv);

  return 0;
}

static int
_gnutls_heartbeat_send_params (gnutls_session_t session,
                               gnutls_buffer_st * extdata)
{
  extension_priv_data_t epriv;
  uint8_t p;

  if (_gnutls_ext_get_session_data
      (session, GNUTLS_EXTENSION_HEARTBEAT, &epriv) < 0)
    return 0; /* nothing to send - not enabled */

  if (epriv.num & GNUTLS_HB_PEER_ALLOWED_TO_SEND)
    p = 1;
  else /*if (epriv.num & GNUTLS_HB_PEER_NOT_ALLOWED_TO_SEND)*/
    p = 2;

  _gnutls_debug_log ("HB: sending parameter %u\n", (unsigned)p);
  if (_gnutls_buffer_append_data (extdata, &p, 1) < 0)
    return gnutls_assert_val (GNUTLS_E_MEMORY_ERROR);

  return 1; /* number of bytes added for sending */
}

static int
_gnutls_heartbeat_pack (extension_priv_data_t _priv, gnutls_buffer_st * ps)
{
  int ret;
  BUFFER_APPEND_NUM (ps, _priv.num);
  return GNUTLS_E_SUCCESS;
}

static int
_gnutls_heartbeat_unpack (gnutls_buffer_st * ps,
                          extension_priv_data_t * _priv)
{
  int ret;
  extension_priv_data_t epriv;
  BUFFER_POP_NUM (ps, epriv.num);
  *_priv = epriv;
  ret = 0;
error:
  return ret;
}


extension_entry_st ext_mod_heartbeat = {
  .name = "HEARTBEAT",
  .type = GNUTLS_EXTENSION_HEARTBEAT,
  .parse_type = GNUTLS_EXT_TLS,

  .recv_func = _gnutls_heartbeat_recv_params,
  .send_func = _gnutls_heartbeat_send_params,
  .pack_func = _gnutls_heartbeat_pack,
  .unpack_func = _gnutls_heartbeat_unpack,
  .deinit_func = NULL
};
