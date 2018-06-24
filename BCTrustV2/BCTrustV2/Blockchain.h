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

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H




#include "Httpclient.h"
#include "QFile"
#include <QCryptographicHash>
#include <QTextCodec>
#include <qdebug.h>





class Blockchain
{
public:
    Blockchain(const QString& ipAddr, const QString& p) ;
    ~Blockchain () ;
    QString FileToString (const QString& fileName) ;

#if 0
    QString   EncodeFunctionSelector(const QString& functionSelector) ;

    QString   EncodeUint64  (u_int64_t      value) ;
    u_int64_t DecodeUint64  (const QString& value) ;
    QString   EncodeInt64   (int64_t        value) ;
    int64_t   DecodeInt64   (const QString& value) ;
    QString   EncodeUint8   (u_int8_t       value) ;
    u_int8_t  DecodeUint8   (const QString& value) ;
    QString   EncodeBoolean (bool           value) ;
    bool      DecodeBoolean (const QString& value) ;
    QString   EncodeString  (const QString& value) ;
    QString   DecodeString  (const QString& value) ;
    QString   EncodeAddress (const QString& value) ;
    QString   DecodeAddress (const QString& value) ;

    QString   EncodeUint8Array   (u_int8_t      * value,
                                  int64_t         valueLen)   ;
    /*not implemented*/
    int32_t   DecodeUint8Array   (u_int8_t      * decValue,
                                 int64_t          decValueLen,
                                 const QString&   value) ;
    /*end*/

    QStringList DecodeAddressArray (const QString& value) ;

    QString   DecodeChunkString (const QString& value) ;
    bool      IsDynamicType     (const QString& type)      ;
    QString   EncodeFunction    (const QString& functionSelector,
                                 const QString& paramsTypes,
                                 QStringList    paramsValues) ;
    QString   CallFunction      (const QString& from,
                                 const QString& to,
                                 const QString& data,
                                 const QString& eth_methodName) ;
#endif
    QString   getCoinbaseFromTheBlockChain() ;
#if 0
    QString   getCoinbase                 () ;
    QString   getContractData             () ;
    QString   getContractGasEstimate      () ;
    QString   getTransactionHash          () ;
    QString   getTransactionReturnedValue () ;
#endif
    QString   getContractAddress          () ;
#if 0
    QString   getMyExternalAddress        () ;
    void      setMyExternalAddress (const QString& _myExternalAddress) ;

    QStringList getAvailableAccounts () ;
    QStringList getUsedAccounts      () ;
    QString     TakeAddress          () ;
#endif


private:
    QString         ipAddress            ;
    QString         port                 ;

    QJsonRpcMessage request              ;
    QJsonRpcMessage response             ;
    HttpClient    * client               ;
    QString         coinbase             ; // miner's address
    QString         contractData         ;
    QString         contractGasEstimate ;
    QString         transactionHash      ; // used in order to track the transaction
    QString         transactionReturnedValue ;
    QString         contractAddress      ;
#if 0
    QString         myExternalAddress    ;
#endif


};

#endif // BLOCKCHAIN_H
