#ifndef crypto_pwhash_scryptsalsa208sha256_H
#define crypto_pwhash_scryptsalsa208sha256_H

#include <stddef.h>

#include "export.h"

#ifdef __cplusplus
# if __GNUC__
#  pragma GCC diagnostic ignored "-Wlong-long"
# endif
extern "C" {
#endif

#define crypto_pwhash_scryptsalsa208sha256_SALTBYTES 32
SODIUM_EXPORT
size_t crypto_pwhash_scryptsalsa208sha256_saltbytes(void);

#define crypto_pwhash_scryptsalsa208sha256_STRBYTES 102
SODIUM_EXPORT
size_t crypto_pwhash_scryptsalsa208sha256_strbytes(void);

SODIUM_EXPORT
int crypto_pwhash_scryptsalsa208sha256(unsigned char * const out,
                                        unsigned long long outlen,
                                        const char * const passwd,
                                        unsigned long long passwdlen,
                                        const unsigned char * const salt,
                                        unsigned long long opslimit,
                                        size_t memlimit);

SODIUM_EXPORT
int crypto_pwhash_scryptsalsa208sha256_str(char out[crypto_pwhash_scryptsalsa208sha256_STRBYTES],
                                            const char * const passwd,
                                            unsigned long long passwdlen,
                                            unsigned long long opslimit,
                                            size_t memlimit);

SODIUM_EXPORT
int crypto_pwhash_scryptsalsa208sha256_str_verify(const char str[crypto_pwhash_scryptsalsa208sha256_STRBYTES],
                                                   const char * const passwd,
                                                   unsigned long long passwdlen);

SODIUM_EXPORT
int crypto_pwhash_scryptsalsa208sha256_ll(const uint8_t * passwd, size_t passwdlen,
                                          const uint8_t * salt, size_t saltlen,
                                          uint64_t N, uint32_t r, uint32_t p,
                                          uint8_t * buf, size_t buflen);

#ifdef __cplusplus
}
#endif

/* Backward compatibility with version 0.5.0 */

#define crypto_pwhash_scryptxsalsa208sha256_SALTBYTES crypto_pwhash_scryptsalsa208sha256_SALTBYTES
#define crypto_pwhash_scryptxsalsa208sha256_saltbytes crypto_pwhash_scryptsalsa208sha256_saltbytes
#define crypto_pwhash_scryptxsalsa208sha256_STRBYTES crypto_pwhash_scryptsalsa208sha256_STRBYTES
#define crypto_pwhash_scryptxsalsa208sha256_strbytes crypto_pwhash_scryptsalsa208sha256_strbytes
#define crypto_pwhash_scryptxsalsa208sha256 crypto_pwhash_scryptsalsa208sha256
#define crypto_pwhash_scryptxsalsa208sha256_str crypto_pwhash_scryptsalsa208sha256_str
#define crypto_pwhash_scryptxsalsa208sha256_str_verify crypto_pwhash_scryptsalsa208sha256_str_verify

#endif