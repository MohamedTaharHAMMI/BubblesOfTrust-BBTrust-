/**********************************************************
*                                                         *
*	Copyright (C)  2017				  *
*	GNU GENERAL PUBLIC LICENSE Version 3              *
*                                                         *
*	Author name : Mohamed Tahar HAMMI                 *
*	Date        : 01/June/2017                        *
*	Contact     : hammi_mohamed_tahar@hotmail.fr      *
*                                                         *
**********************************************************/


#ifndef CONVERTION_H
#define CONVERTION_H





#include <stdio.h>
#include <string.h>
#include <qdebug.h>
#include <time.h>
#include <QStringListModel>

#include "sha3.h"
#include "uECC.h"



#define PUBKEY_SIZE       64
#define PRIVKEY_SIZE      32
#define KECCAK_HASH_SIZE  32
#define ADDR_SIZE         20
#define SIG_SIZE          64


class Convertion
{
public:

    static int32_t FromQStringToUint8(uint8_t * bytes, int32_t bytesLen, const QString strArray)    ;
    static QString FromUint8ToQString(const uint8_t *bytes, int32_t bytesLen)                       ;
    static int32_t FromInt32ToUintArray(int32_t value, uint8_t ** pbuffer, uint8_t * ebuffer)       ;
    static int32_t ReadPrivKey (uint8_t * privateKey, int32_t privateKeyLen, QString privateKeyStr) ;

};

#endif // CONVERTION_H
