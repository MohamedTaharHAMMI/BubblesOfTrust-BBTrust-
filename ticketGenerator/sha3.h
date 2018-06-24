///* ustd.h common macros and includes */
//#ifndef LIBRHASH_USTD_H
//#define LIBRHASH_USTD_H

//#if _MSC_VER >= 1300

//# define int64_t __int64
//# define int32_t __int32
//# define int16_t __int16
//# define int8_t  __int8
//# define uint64_t unsigned __int64
//# define uint32_t unsigned __int32
//# define uint16_t unsigned __int16
//# define uint8_t  unsigned __int8

///* disable warnings: The POSIX name for this item is deprecated. Use the ISO C++ conformant name. */
//#pragma warning(disable : 4996)

//#else /* _MSC_VER >= 1300 */

//# include <stdint.h>
//# include <unistd.h>

//#endif /* _MSC_VER >= 1300 */

//#if _MSC_VER <= 1300
//# include <stdlib.h> /* size_t for vc6.0 */
//#endif /* _MSC_VER <= 1300 */

//#endif /* LIBRHASH_USTD_H */

#include "byte_order.h"



/* sha3.h */
#ifndef RHASH_SHA3_H
#define RHASH_SHA3_H

#ifdef __cplusplus
extern "C" {
#endif

#define sha3_224_hash_size  28
#define sha3_256_hash_size  32
#define sha3_384_hash_size  48
#define sha3_512_hash_size  64
#define sha3_max_permutation_size 25
#define sha3_max_rate_in_qwords 24

/**
 * SHA3 Algorithm context.
 */
typedef struct sha3_ctx
{
	/* 1600 bits algorithm hashing state */
	uint64_t hash[sha3_max_permutation_size];
	/* 1536-bit buffer for leftovers */
	uint64_t message[sha3_max_rate_in_qwords];
	/* count of bytes in the message[] buffer */
	unsigned rest;
	/* size of a message block processed at once */
	unsigned block_size;
} sha3_ctx;

/* methods for calculating the hash function */

void rhash_sha3_224_init(sha3_ctx *ctx);
void rhash_sha3_256_init(sha3_ctx *ctx);
void rhash_sha3_384_init(sha3_ctx *ctx);
void rhash_sha3_512_init(sha3_ctx *ctx);
void rhash_sha3_update(sha3_ctx *ctx, const unsigned char* msg, size_t size);
void rhash_sha3_final(sha3_ctx *ctx, unsigned char* result);

//#ifdef USE_KECCAK
#define rhash_keccak_224_init rhash_sha3_224_init
#define rhash_keccak_256_init rhash_sha3_256_init
#define rhash_keccak_384_init rhash_sha3_384_init
#define rhash_keccak_512_init rhash_sha3_512_init
#define rhash_keccak_update rhash_sha3_update
void rhash_keccak_final(sha3_ctx *ctx, unsigned char* result);
//#endif

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RHASH_SHA3_H */
