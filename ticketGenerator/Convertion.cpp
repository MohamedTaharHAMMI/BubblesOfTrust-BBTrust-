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




#include "Convertion.h"





int32_t Convertion::FromQStringToUint8(uint8_t * bytes, int32_t bytesLen, const QString strArray)
{
    int32_t rc  = 0 ;
    if (bytes == NULL) {
        qDebug () << "MainWindow::FromQStringToUint8, bytes == NULL" ;
        rc = (int32_t) 1 ;
        goto error ;
    }

    if (bytesLen <= 0) {
        qDebug () << "MainWindow::FromQStringToUint8, bytesLen <= 0" ;
        rc = (int32_t) 1 ;
        goto error ;
    }

    if (strArray.isEmpty()) {
        qDebug () << "MainWindow::FromQStringToUint8, strArray.isEmpty()" ;
        rc = (int32_t) 1 ;
        goto error ;
    }

    if (strArray.length() <= 0) {
        qDebug () << "MainWindow::FromQStringToUint8, strArrayLen <= 0" ;
        rc = (int32_t) 1 ;
        goto error ;
    }

    if (bytesLen != strArray.length()/2) {
        qDebug () << "Convertion::FromQStringToUint8, bytesLen != strArray.length()/2"  << bytesLen << "!=" << strArray.length()/2 ;
        rc = (int32_t) 1 ;
        goto error ;
    }

    for (int i = 0; i < bytesLen; i++)
        bytes[i] = strArray.mid(i*2,2).toUInt(0,16) ;

error:

    return rc ;
}


QString Convertion::FromUint8ToQString(const uint8_t *bytes, int32_t bytesLen)
{
    QString rc        ;
    uint8_t byteLeft  ;
    uint8_t byteRight ;

    if (bytes == NULL) {
        qDebug () << "MainWindow::FromQStringToUint8, bytes == NULL" ;
        rc =  "" ;
        goto error ;
    }

    if (bytesLen <= 0) {
        qDebug () << "MainWindow::FromQStringToUint8, bytesLen <= 0" ;
        rc = "" ;
        goto error ;
    }

    for (int i = 0; i < bytesLen; i++) {

        byteLeft  = (bytes[i] >> 4) & 0x0f ;
        byteRight = bytes[i] & 0x0f ;

        rc.append(QString::number(byteLeft, 16)) ;
        rc.append(QString::number(byteRight, 16)) ;
    }
error:
    return rc ;
}


int32_t Convertion::FromInt32ToUintArray(int32_t value, uint8_t ** pbuffer, uint8_t * ebuffer)
{
    int32_t   rc = 0         ;
    uint8_t * pb = * pbuffer ;

    if (pb + sizeof(int32_t) > ebuffer) {
        rc = (int32_t) 1 ;
        goto error ;
    }

    value = ((value & 0xFF000000) >> 24) ^
            ((value & 0x00FF0000) >> 8 ) ^
            ((value & 0x0000FF00) << 8 ) ^
            ((value & 0x000000FF) << 24) ;

    memcpy(pb, &value, sizeof(int32_t)) ;
    pb += sizeof(int32_t) ;


error:
    return rc ;
}


int32_t Convertion::ReadPrivKey (uint8_t * privateKey, int32_t privateKeyLen, QString privateKeyStr)
{
    int32_t rc = 0 ;

    if (privateKeyStr.length() != PRIVKEY_SIZE*2) {
        qDebug () << "MainWindow::ReadPrivKey, privateKeyStr.length() != PRIVKEY_SIZE (" << privateKeyStr.length() << " != " << PRIVKEY_SIZE << ")";
        rc = (int32_t) 1 ;
        goto error ;
    }

    if (FromQStringToUint8(privateKey, privateKeyLen, privateKeyStr)) {
        qDebug () << "MainWindow::ReadPrivKey, FromQStringToUint8 operation failed..";
        rc = (int32_t) 1 ;
        goto error ;
    }

error:
    return rc ;
}


