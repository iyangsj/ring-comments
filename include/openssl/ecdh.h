/* ====================================================================
 * Copyright 2002 Sun Microsystems, Inc. ALL RIGHTS RESERVED.
 *
 * The Elliptic Curve Public-Key Crypto Library (ECC Code) included
 * herein is developed by SUN MICROSYSTEMS, INC., and is contributed
 * to the OpenSSL project.
 *
 * The ECC Code is licensed pursuant to the OpenSSL open source
 * license provided below.
 *
 * The ECDH software is originally written by Douglas Stebila of
 * Sun Microsystems Laboratories.
 *
 */
/* ====================================================================
 * Copyright (c) 2000-2002 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    licensing@OpenSSL.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com). */

#ifndef OPENSSL_HEADER_ECDH_H
#define OPENSSL_HEADER_ECDH_H

#include <openssl/base.h>

#include <openssl/ec_key.h>

#if defined(__cplusplus)
extern "C" {
#endif


/* Elliptic curve Diffie-Hellman. */


/* ECDH_compute_key_ex calculates the shared key between |priv_key| and
 * and the given peer encoded public key. ECDH_compute_key_ex verifies that
 * the peer public point curve, identified by |peer_pub_point_curve_nid| is the
 * same as |priv_key|'s curve. It also verifies that the encoded peer public
 * point in |peer_pub_point_bytes| with length |peer_pub_point_bytes_len| is on
 * the curve. |max_out_len| must be at least
 * |(EC_GROUP_get_degree(group) + 7) / 8|, and at most that many bytes of the
 * computed shared key are copied directly to |out|. (This differs from what
 * the OpenSSL |ECDH_compute_key| function does.) The number of bytes
 * written to |out| is returned in |out_len|. It returns 1 on success and 0 on
 * error. (This differs from what the OpenSSL |ECDH_compute_key| function
 * returns.) */
OPENSSL_EXPORT int ECDH_compute_key_ex(uint8_t *out, size_t *out_len,
                                       size_t max_out_len, EC_KEY *priv_key,
                                       int peer_pub_point_curve_nid,
                                       const uint8_t *peer_pub_point_bytes,
                                       size_t peer_pub_point_bytes_len);


#if defined(__cplusplus)
}  /* extern C */
#endif

#define ECDH_R_KDF_FAILED 100
#define ECDH_R_NO_PRIVATE_VALUE 101
#define ECDH_R_POINT_ARITHMETIC_FAILURE 102

#endif  /* OPENSSL_HEADER_ECDH_H */
