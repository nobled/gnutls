## Process this file with automake to produce Makefile.in
# Copyright (C) 2002-2012 Free Software Foundation, Inc.
#
# Author: Nikos Mavrogiannopoulos
#
# This file is part of GnuTLS.
#
# The GnuTLS is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# as published by the Free Software Foundation; either version 3 of
# the License, or (at your option) any later version.
#
# The GnuTLS is distributed in the hope that it will be
# useful, but WITHOUT ANY WARRANTY; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>

AM_CFLAGS = $(WERROR_CFLAGS) $(WSTACK_CFLAGS) $(WARN_CFLAGS)
AM_CPPFLAGS = \
	-I$(srcdir)/../../gl		\
	-I$(builddir)/../../gl		\
	-I$(srcdir)/../includes		\
	-I$(builddir)/../includes	\
	-I$(builddir)/../../gl          \
	-I$(srcdir)/..			\
	-I$(srcdir)/../opencdk

if ENABLE_MINITASN1
AM_CPPFLAGS += -I$(srcdir)/../minitasn1
endif

noinst_LTLIBRARIES = libgnutls_auth.la

libgnutls_auth_la_SOURCES = anon.c cert.c dh_common.c dhe.c \
	dhe_psk.c psk.c psk_passwd.c rsa.c rsa_export.c srp.c \
	srp_passwd.c srp_rsa.c srp_sb64.c anon.h cert.h dh_common.h \
	psk.h psk_passwd.h srp.h srp_passwd.h anon_ecdh.c \
	ecdh_common.c ecdh_common.h
