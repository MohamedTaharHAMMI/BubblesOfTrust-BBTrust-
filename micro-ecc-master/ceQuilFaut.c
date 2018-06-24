/* Copyright 2014, Kenneth MacKay. Licensed under the BSD 2-clause license. */

#include "uECC.h"
#include "sha3.h"

#include <stdio.h>
#include <string.h>


void print_uint8 (const char * title, uint8_t * data, int32_t dataLen) 
{
	printf("%s", title) ;
	int i ;
	for (i = 0; i < dataLen; i++) {
		printf("%02X",data[i]) ;
	}
	printf("\n") ;
}


int main() 
{
	int i, c;
    	const struct uECC_Curve_t * curve = uECC_secp256k1();
 
    	uint8_t private[32] = {0x5b,0x97,0xb6,0x52,0x4b,0x5a,0x46,0x07,0x1c,0x9a,0x89,0x05,0x27,0x58,0x9e,0xb0,
			       0x54,0x16,0x90,0xea,0xc2,0x00,0xad,0x88,0xb0,0xb8,0x69,0x8a,0x89,0x2e,0x8c,0x21} ;

    	uint8_t public[64]  = {0xc7,0x9e,0xa9,0xbb,0xd5,0x89,0x75,0xad,0x57,0x0c,0x3b,0x5c,0x27,0x6a,0x4f,0xf0,
			       0xb1,0x1a,0x42,0x9d,0x78,0xd2,0xb5,0x12,0x57,0x55,0xe8,0x72,0xa5,0x03,0x5f,0xc7,
			       0x55,0xe4,0x8a,0x29,0x26,0xfa,0x9d,0x12,0xd9,0xbc,0xba,0xf3,0x2a,0x5e,0x81,0xbe,
			       0x10,0x23,0x27,0x3d,0x5c,0x38,0xeb,0x3c,0x4c,0xee,0x91,0x0f,0xe7,0x61,0x43,0xd8} ;
	uint8_t pub [64] = {0} ;
    	uint8_t hash[32] = {0} ;
    	uint8_t sig[64]  = {0} ;

/*
        if (!uECC_make_key(public, private, curve)) {
        	printf("uECC_make_key() failed\n");
                return 1;
        }
*/
	//unsigned char md[MD_SHA3_256BIT_LEN] ;

	sha3_ctx ctx ;
	rhash_sha3_256_init(&ctx) ;
	rhash_sha3_update(&ctx, (const unsigned char *) "hello", strlen("hello")) ;
	rhash_keccak_final(&ctx, hash) ;

	if (hash == NULL) {
                printf("hash == NULL\n");
                return 1;
	}




    printf("Testing 256 signatures\n");

            fflush(stdout);

            if (!uECC_compute_public_key(private, pub, curve)) {
                printf("uECC_make_key() failed\n");
                return 1;
            }

           // memcpy(hash, public, sizeof(hash));
            
            if (!uECC_sign(private, hash, sizeof(hash), sig, curve)) {
                printf("uECC_sign() failed\n");
                return 1;
            }

            if (!uECC_verify(public, hash, sizeof(hash), sig, curve)) {
                printf("uECC_verify() failed\n");
                return 1;
            }

	print_uint8 ("pub:",pub, 64) ;
	print_uint8 ("priv:",private, 32) ;	


        printf("signature verification finished with success\n");

    
    return 0;
}
