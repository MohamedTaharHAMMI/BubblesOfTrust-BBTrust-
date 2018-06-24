#ifndef ECC_H
#define ECC_H


#include "Convertion.h"




class ECC
{

public:
    ECC(const struct uECC_Curve_t * _curve)
    {
        curve = _curve ;
    }

private:
    const struct uECC_Curve_t * curve ;

public:
    void ECC_print_uint8 (const char * title, uint8_t * data, int32_t dataLen)
    {
        printf("%s", title) ;
        int i ;
        for (i = 0; i < dataLen; i++) {
            printf("%02X",data[i]) ;
        }
        printf("\n") ;
    }

    int32_t ECC_getPubKey(uint8_t * privateKey, int32_t privateKeyLen, uint8_t * publicKey, int32_t publicKeyLen)
    {
        int32_t rc = 0 ;

        if (privateKey == NULL) {
            // error
            qDebug() << "ECC_getPubKey, " << "privateKey == NULL" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (privateKeyLen != PRIVKEY_SIZE)  {
            // error
            qDebug() << "ECC_getPubKey, " << "privateKeyLen != PRIVKEY_SIZE" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (publicKey == NULL) {
            // error
            qDebug() << "ECC_getPubKey, " << "publicKey == NULL" ;
            rc =  (int32_t) 1 ;
            goto error ;
        }

        if (publicKeyLen != PUBKEY_SIZE)  {
            // error
            qDebug() << "ECC_getPubKey, " << "publicKeyLen != PRIVKEY_SIZE" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (!uECC_compute_public_key(privateKey, publicKey, curve)) {
            // error
            qDebug() << "ECC_getPubKey, " << "uECC_compute_public_key failed" ;
            rc =  (int32_t) 1 ;
            goto error ;
        }

error:
        return rc ;
    }

    int32_t ECC_getAddress(uint8_t * publicKey, int32_t publicKeyLen, uint8_t * address, int32_t addressLen)
    {
        int32_t      rc      = 0             ;
        uint8_t    * pbuffer = NULL          ;
        uint8_t    * ebuffer = NULL          ;
        uint8_t      hash [KECCAK_HASH_SIZE] ;
        sha3_ctx     ctx                     ;

        ECC_print_uint8("pub before ", publicKey, publicKeyLen );

        if (publicKey == NULL) {
            // error
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (publicKeyLen != PUBKEY_SIZE)  {
            // error
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (address == NULL) {
            // error
            rc =  (int32_t) 1 ;
            goto error ;
        }

        if (addressLen != ADDR_SIZE)  {
            // error
            rc = (int32_t) 1 ;
            goto error ;
        }


        rhash_sha3_256_init(&ctx) ;
        rhash_sha3_update(&ctx, (const unsigned char *) publicKey, publicKeyLen) ;
        rhash_keccak_final(&ctx, hash) ;


        pbuffer = hash ;
        ebuffer = pbuffer + KECCAK_HASH_SIZE ;

        memcpy (address, pbuffer + 12, addressLen) ;
        pbuffer += addressLen ;

        if (pbuffer != ebuffer) {
            // error
            rc = (int32_t) 1 ;
            goto error ;
        }

error:
        return rc ;
    }


    int32_t ECC_sign (uint8_t * signature, int32_t signatureLen, uint8_t * privateKey, int32_t privateKeyLen, uint8_t * data, int32_t dataLen)
    {
        int32_t      rc  = 0                 ;
        uint8_t      hash [KECCAK_HASH_SIZE] ;
        sha3_ctx     ctx                     ;


        if (signature == NULL) {
            // error
            qDebug() << "ECC_sign, " << "signature == NULL" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (signatureLen != SIG_SIZE)  {
            // error
            qDebug() << "ECC_sign, " << "signatureLen != SIG_SIZE" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (privateKey == NULL) {
            // error
            qDebug() << "ECC_sign, " << "privateKey == NULL" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (privateKeyLen != PRIVKEY_SIZE)  {
            // error
            qDebug() << "ECC_sign, " << "privateKeyLen != PRIVKEY_SIZE" ;
            rc = (int32_t) 1 ;
            goto error ;
        }


        if (data == NULL) {
            // error
            qDebug() << "ECC_sign, " << "data == NULL" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (dataLen <= 0) {
            qDebug() << "ECC_sign, " << "dataLen <= 0" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        rhash_sha3_256_init(&ctx) ;
        rhash_sha3_update(&ctx, (const unsigned char *) data, dataLen) ;
        rhash_keccak_final(&ctx, hash) ;

        if (!uECC_sign(privateKey, hash, KECCAK_HASH_SIZE, signature, curve)) {
            qDebug() << "ECC_sign, " << "uECC_sign operation failed" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

error:
        return rc ;
    }

    int32_t ECC_verify (uint8_t * signature, int32_t signatureLen, uint8_t * publicKey, int32_t publicKeyLen, uint8_t * data, int32_t dataLen)
    {
        int32_t      rc  = 0                 ;
        uint8_t      hash [KECCAK_HASH_SIZE] ;
        sha3_ctx     ctx                     ;


        ECC_print_uint8("signature ", signature, 32) ;

        if (signature == NULL)  {
            // error
            qDebug() << "ECC_verify, " << "signature == NULL" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (signatureLen != SIG_SIZE)  {
            // error
            qDebug() << "ECC_verify, " << "signatureLen != SIG_SIZE" ;
            rc = (int32_t) 1 ;
            goto error ;
        }


        if (data == NULL) {
            // error
            qDebug() << "ECC_verify, " << "data == NULL" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (dataLen <= 0) {
            qDebug() << "ECC_verify, " << "dataLen <= 0" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (publicKey == NULL) {
            // error
            qDebug() << "ECC_verify, " << "publicKey == NULL" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        if (publicKeyLen != PUBKEY_SIZE)  {
            // error
            qDebug() << "ECC_verify, " << "publicKeyLen != PUBKEY_SIZE" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

        rhash_sha3_256_init(&ctx) ;
        rhash_sha3_update(&ctx, (const unsigned char *) data, dataLen) ;
        rhash_keccak_final(&ctx, hash) ;


        if (!uECC_verify(publicKey, hash, KECCAK_HASH_SIZE, signature, curve)) {
            qDebug() << "ECC_verify, " << "uECC_verify operation failed" ;
            rc = (int32_t) 1 ;
            goto error ;
        }

error:
        return rc ;
    }

private:



} ;




#endif // ECC_H
