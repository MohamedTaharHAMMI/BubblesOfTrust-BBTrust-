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


#include "Blockchain.h"

#define CONTRACT_PATH "/home/mohamed/THESE/Journal/Implementation/BCTrustV2/contracts/BCTrustV2.sol"
#define _32Bytes       64
#define _AddrTypeLen   (20 * 2)
#define _AddrPaddLen   _32Bytes - _AddrTypeLen




Blockchain::Blockchain(const QString& ipAddr, const QString& p) : ipAddress(ipAddr), port (p)/*, request(0), response (0)*/,
                                                                  coinbase(""), contractData(""), contractGasEstimate(""),
                                                                  transactionHash("")

#if 0
                                                                , myExternalAddress ("")
#endif
{
    client   = new HttpClient("http://" + ipAddress + ":" + port) ;

// 1) // Je pense qu'on a pas besoin de récupérer l'addresse du mineur (coinbase)

    coinbase = getCoinbaseFromTheBlockChain() ;
    if(coinbase.isEmpty()) {
        qDebug() << "Error:Blockchain::Blockchain, getCoinbaseFromTheBlockChain call failed" ;
        return ;
    }

// 2)
    QVariantList params ;
    params.append(FileToString (CONTRACT_PATH)) ;
    // I can use only 10 args as parameters ;
    request = QJsonRpcMessage::createRequest("eth_compileSolidity", QJsonArray::fromVariantList(params)) ;
    response = client->sendMessageBlocking(request) ;
    if (response.type() == QJsonRpcMessage::Error) {
        qDebug() << response.errorData() ;
        exit (0) ; // todo change it
    }

    QVariantMap resultObject = (QVariantMap) response.result().toObject().toVariantMap() ;
    contractData = (resultObject.take("code").toString()) ;

// 3)
    params.clear() ;
    resultObject.clear() ;
    resultObject.insert("from", coinbase) ;       // JP qu'au lieu de mettre l'adresse du mineur (coinbase) il vaut mieu mettre celle du createur du contract
    resultObject.insert("data", contractData ) ;
    params.append(resultObject) ;
    // I can use only 10 args ;
    request = QJsonRpcMessage::createRequest("eth_estimateGas", QJsonArray::fromVariantList(params)) ;
    response = client->sendMessageBlocking(request) ;
    if (response.type() == QJsonRpcMessage::Error) {
        qDebug() << response.errorData() ;
        exit (0) ; // todo change it
    }
    contractGasEstimate = response.result().toString();

// 4)
    params.clear() ;
    resultObject.clear();
    resultObject.insert("from", coinbase) ; // JP ça ne doit pas être l'adresse du miner (coinbase) mais plutôt celle du createur du contract
    resultObject.insert("gas",  contractGasEstimate) ;
    resultObject.insert("data", contractData ) ;
    params.append(resultObject) ;
    // I can use only 10 args ;
    request = QJsonRpcMessage::createRequest("eth_sendTransaction", QJsonArray::fromVariantList(params)) ; // Creates new message call transaction or a contract creation, if the data field contains code.
    response = client->sendMessageBlocking(request) ;
    if (response.type() == QJsonRpcMessage::Error) {
        qDebug() << response.errorData() ;
        exit (0) ; // todo change it
    }
    transactionHash = response.result().toString() ;

// 5)
    params.clear();
    params.append(transactionHash);
    // I can use only 10 args ;
    request = QJsonRpcMessage::createRequest("eth_getTransactionReceipt", QJsonArray::fromVariantList(params)) ;
    response = client->sendMessageBlocking(request) ;
    if (response.type() == QJsonRpcMessage::Error) {
        qDebug() << response.errorData() ;
        exit (0) ; // todo change it
    }
    resultObject.clear() ;
    resultObject = (QVariantMap) response.result().toObject().toVariantMap() ;
    contractAddress = resultObject.take("contractAddress").toString() ;

#if 0
    // 0)
    request  = QJsonRpcMessage::createRequest("eth_accounts") ;
    response = client->sendMessageBlocking(request) ;
    if (response.type() == QJsonRpcMessage::Error) {
        qDebug() << response.errorData() ;
        exit (0) ; // todo: change it
    }

    QStringList allAccounts = response.result().toVariant().toStringList() ;

    QString     paramsTypes ("address") ;
    QStringList paramsValues ;
    for (int i =0; i < allAccounts.length(); i++) {
        paramsValues.append (EncodeAddress(allAccounts.at(i))) ;
        QString v = CallFunction(coinbase,
                                 contractAddress,
                                 EncodeFunction(EncodeFunctionSelector("registerAddress(address)"),
                                                paramsTypes,
                                                paramsValues),
                                 "eth_sendTransaction"
                                 ) ;
        if (v == "0x") {
            qDebug() << "Error:Blockchain::Blockchain, registerAddress transaction failed" ;
            return ;
        }
        paramsValues.clear() ;
    }
#endif
}



Blockchain::~Blockchain ()
{

}

QString Blockchain::getCoinbaseFromTheBlockChain ()
{
    QJsonRpcMessage request  = QJsonRpcMessage::createRequest("eth_coinbase") ;
    QJsonRpcMessage response = client->sendMessageBlocking(request) ;
    if (response.type() == QJsonRpcMessage::Error) {
        qDebug() << response.errorData() ;
        return "" ; // todo: change it
    }
    return response.result().toString() ;
}

#if 0
QString Blockchain::getCoinbase()
{
    return coinbase ;
}

QString Blockchain::getContractData ()
{
    return contractData ;
}

QString Blockchain::getContractGasEstimate ()
{
    return contractGasEstimate ;
}

QString Blockchain::getTransactionHash ()
{
    return transactionHash ;
}

QString Blockchain::getTransactionReturnedValue ()
{
    return transactionReturnedValue ;
}
#endif // #if 0
QString Blockchain::getContractAddress ()
{
    return contractAddress ;
}

#if 0
QStringList Blockchain::getAvailableAccounts ()
{
    QString     paramsTypes = "" ;
    QStringList paramsValues ;
    QString     externalAddress ;

    externalAddress = (getMyExternalAddress().isEmpty()) ? getCoinbase():getMyExternalAddress() ;

    return DecodeAddressArray(CallFunction(externalAddress,
                                           contractAddress,
                                           EncodeFunction(EncodeFunctionSelector("GetAvailableAccounts()"),
                                                          paramsTypes,
                                                          paramsValues),
                                           "eth_call"
                                           )
                              ) ;
}


QStringList Blockchain::getUsedAccounts ()
{    
    QString     paramsTypes = "" ;
    QStringList paramsValues ;
    QString     externalAddr = getMyExternalAddress() ;
    if(externalAddr.isEmpty()) {
        qDebug() << "Error:Blockchain::getUsedAccounts, you don't have the right to do this operation (the external address can not be found)" ;
        return paramsValues ; // empty
    }
    return DecodeAddressArray(CallFunction(externalAddr,
                                           contractAddress,
                                           EncodeFunction(EncodeFunctionSelector("GetUsedAccounts()"),
                                                          paramsTypes,
                                                          paramsValues),
                                           "eth_call"
                                           )
                              ) ;
}


QString Blockchain::getMyExternalAddress ()
{
    return myExternalAddress ;
}

void Blockchain::setMyExternalAddress (const QString& _myExternalAddress)
{
    myExternalAddress = _myExternalAddress ;
}


QString Blockchain::TakeAddress ()
{
    QString     paramsTypes = "" ;
    QStringList paramsValues ;
    QString     v = "" ;

    if (!getMyExternalAddress().isEmpty()) {
        qDebug() << "Error:Blockchain::TakeAddress, you already have an external address" ;
        goto error ;
    }

    paramsTypes = "" ;
    v = DecodeAddress(CallFunction(getCoinbase(),
                                   contractAddress,
                                   EncodeFunction(EncodeFunctionSelector("GetMinterAddress()"),
                                                  paramsTypes,
                                                  paramsValues),
                                   "eth_call"
                                   )
                      ) ;

    if (v.length() != _AddrTypeLen + 2) {
        qDebug() << "Error:Blockchain::TakeAddress, TakeAddress transaction failed" ;
        goto error ;
    }

    paramsValues.clear() ;
error:
    return v ;
}
#endif

#if 0
QString Blockchain::CallFunction (const QString &from,
                                  const QString& to,
                                  const QString& data,
                                  const QString& eth_methodName)
{

    QVariantList    params       ;
    QVariantMap     resultObject ;
    QJsonRpcMessage request      ;
    QJsonRpcMessage response     ;

    resultObject.insert("from", from) ;
    resultObject.insert("to",   to  ) ;
    resultObject.insert("data", data) ;

    params.append(resultObject) ;
        // I can use only 10 args ;
    request  = QJsonRpcMessage::createRequest(eth_methodName, QJsonArray::fromVariantList(params)) ; // Executes a new message call immediately without creating a transaction on the block chain
    response = client->sendMessageBlocking(request) ;
    if (response.type() == QJsonRpcMessage::Error) {
        qDebug() << "Error:Blockchain::CallFunction," << response.errorData() ;
        // exit (0) ; // todo change it
    }

    return response.result().toString() ;
}
#endif // #if 0
QString Blockchain::FileToString (const QString& fileName)
{
    QString contractDef = "" ;
    QFile file(fileName) ;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error : file opening" ;
        return contractDef ;
    }
    while (!file.atEnd())
        contractDef += file.readLine();

    return  contractDef ;
}

#if 0
QString Blockchain::EncodeFunctionSelector(const QString& functionSelector)
{

    QByteArray data ;
    data.append(functionSelector) ; // using this append the Unicode functionName is converted into 8-bit characters using QString::toAscii()
    QByteArray md = QCryptographicHash::hash(data, QCryptographicHash::Sha3_256) ;
    QString first4bytes(md.toHex()) ;

    return first4bytes.left(8) ;
}


bool Blockchain::IsDynamicType(const QString& type) {
    if (type.at(type.length()-1) == ']')
        return true ;
    if      (type == "string") return true ;
    else if (type == "bytes" ) return true ;

    return false ;
}


QString Blockchain::EncodeFunction(const QString& functionSelector, const QString& paramsType, QStringList paramsValues)
{
    QString     value   = ""  ;
    int         dP      = 0   ;

    if (paramsType == "") {
        value = "0x" + functionSelector ;
        QString padding ;
        padding.fill('0', _32Bytes) ;

        return value + padding ;
    }

    QStringList paramsTypes  = paramsType.split(',') ;

    QList <int> dataPosList ; // for the dynamic types

    if (paramsTypes.length() != paramsValues.length()) {
        qDebug () << "Error: ExecuteFunction, paramsTypes.length()" << paramsTypes.length() << "!= paramsValues.length()" << paramsValues.length() ;
        exit (0) ; // todo change it by another one
    }

    value = "0x" + functionSelector ;

    for (int i = 0; i < paramsTypes.length(); i++) {
        if (IsDynamicType(paramsTypes.at(i))) {
            dP += 32 * paramsTypes.length() ;

            for (int j = 0; j < i; j++) {
                if (IsDynamicType(paramsTypes.at(j))) {
                    int dynamicLen = DecodeUint64(paramsValues.at(j).left(_32Bytes)) ;
                    dP += 32 + dynamicLen + (32 - (dynamicLen % 32)) ; // 32 for the dynamicTypeLen of prec dynamicType + ...
                }
            }
            dataPosList.append(dP) ;
            dP = 0 ;
        }
    }

    dP = 0 ;

    for (int i = 0; i < paramsTypes.length(); i++) {
        if (IsDynamicType(paramsTypes.at(i))) {
            value += EncodeUint64(dataPosList.at(dP)) ;
            dP ++ ;
        } else {
            value += paramsValues.at(i) ;
        }
    }

    for (int i = 0; i < paramsTypes.length(); i++) {
        if (IsDynamicType(paramsTypes.at(i)))
            value += paramsValues.at(i);
    }

    return value ;
}



/*We distinguish static and dynamic types.
  Static types are encoded in-place and dynamic types are encoded at a separately allocated location after the current block*/

/* Static types (the length is a multiple of 32 bytes):*/
/*X represent a value*/


QString Blockchain::EncodeUint64(u_int64_t value)
{
/*uint<M>: enc(X) is the big-endian encoding of X, padded on the higher-order (left) side with zero-bytes such that the length is a multiple of 32 bytes*/
    QString v ;
    v = QString::number(value, 16) ; // we should convert the DEC to HEX
    int paddingLen = _32Bytes - (v.length() % _32Bytes) ;
    QString padding (paddingLen, '0') ;

    return padding + v ;
}

u_int64_t Blockchain::DecodeUint64(const QString& value)
{
    bool ok;

    quint64 decodedValue = (value).toUInt(&ok, 16) ;
    if (!ok)
        qDebug() << "Error: Blockchain::DecodeUint64, Conversion failed!";

    return (u_int64_t) decodedValue ;
}


QString Blockchain::EncodeUint8(u_int8_t value) // todo test this function
{
/*uint<M>: enc(X) is the big-endian encoding of X, padded on the higher-order (left) side with zero-bytes such that the length is a multiple of 32 bytes*/
    QString v ;
    v = QString::number(value, 16) ; // we should convert the DEC to HEX
    int paddingLen = _32Bytes - (v.length() % _32Bytes) ;
    QString padding (paddingLen, '0') ;

    return padding + v ;
}

u_int8_t Blockchain::DecodeUint8(const QString& value) // todo test this function
{
    bool ok;

    quint8 decodedValue = (value).toUInt(&ok, 16) ;
    if (!ok)
        qDebug() << "Error: Blockchain::DecodeUint8, Conversion failed!";

    return (u_int8_t) decodedValue ;
}





QString Blockchain::EncodeInt64(int64_t value)
{
/*uint<M>: enc(X) is the big-endian encoding of X, padded on the higher-order (left) side with zero-bytes such that the length is a multiple of 32 bytes*/
    QByteArray  buffer ;
    QDataStream stream(&buffer, QIODevice::WriteOnly) ;
    stream << (qint64)value;
    QString v ;
    QChar paddingValue = '0' ;
    if (value < 0) {
        value *= -1 ;
        paddingValue = 'f' ;
    }
    QString v2 ((QString)buffer.toHex()) ;
    int paddingLen = _32Bytes - (v2.length() % _32Bytes) ;
    v.fill(paddingValue, paddingLen) ;

    return v + v2 ;
}

int64_t Blockchain::DecodeInt64(const QString& value)
{
    bool    ok  = true ;
    QString right_16_bytes = (value).right(16) ;
    qint64  decodedValue = right_16_bytes.toULongLong(&ok, 16) ;
    if (!ok)
        qDebug() << "Error, DecodeInt64, Conversion failed!";

    return (int64_t) decodedValue;
}

QString Blockchain::EncodeBoolean(bool value)
{
/*uint<M>: enc(X) is the big-endian encoding of X, padded on the higher-order (left) side with zero-bytes such that the length is a multiple of 32 bytes*/
    if (value == false)
        return "0000000000000000000000000000000000000000000000000000000000000000" ;
    else
        return "0000000000000000000000000000000000000000000000000000000000000001" ;
}

bool Blockchain::DecodeBoolean(const QString& value)
{
    bool    ok = true ;
    quint64 v  = 0 ;

    v = value.toULongLong(&ok, 16) ;
    if (!ok)
        qDebug() << "Error: DecodeChunkString, Conversion failed!";

    return (bool) v ;
}


// Dynamic types:

QString Blockchain::EncodeString(const QString& value)
{
// dynamic sized unicode string assumed to be UTF-8 encoded
// Note that the length used in this subsequent encoding is the number of bytes of the utf-8 encoded string, not its number of characters
// len(a) is the number of bytes in a binary string a. The type of len(a) is assumed to be uint256

    QString v(value.toUtf8().toHex()) ;
    int32_t paddingLen = _32Bytes - (v.length() % _32Bytes) ;
    QString rightPadding ;
    rightPadding.fill('0', paddingLen) ;

    return EncodeUint64(v.length()/2) + v + rightPadding ;     // (v.length()/2) because we talk Bytes
}

QString Blockchain::DecodeString(const QString& value)
{
    u_int64_t dataPos     = 0  ;
    u_int64_t valueLen    = 0  ;
    QString   v           = "" ;
    QString   vRes        = "" ;
    QString   decodedStr  = "" ;
    u_int32_t chunkNumber = 0  ;
    u_int32_t chunkLen    = 0  ;

    dataPos = DecodeUint64(value.left(2 + _32Bytes)) ;  // 0x = 2 characters
    if (dataPos <= 0) {
        qDebug () << "Error: DecodeString, dataPos <= 0 " ;
        goto error ;
    }
    v = value.mid (2 + _32Bytes) ;
    valueLen = DecodeUint64(v.left(_32Bytes)) * 2 ;      // Byte = 2 characters
    if (valueLen <= 0) {
        qDebug () << "Error: DecodeString, valueLen <= 0 " ;
        goto error ;
    }
    vRes = v.mid(dataPos*2, valueLen) ;                   // dataPos*2 -> because we talk bytes // todo to check this info

    // 8 bytes

    chunkNumber += (valueLen / 8) ;
    chunkNumber += (valueLen % 8) ? 1 : 0 ;
    chunkLen    = 0 ;

    for (u_int32_t i = 0; i < chunkNumber; i++) {
        chunkLen   = (valueLen > 8) ? 8 : valueLen ;
        valueLen   -= chunkLen ;
        decodedStr += DecodeChunkString(vRes.mid(i*8, chunkLen)) ;
        chunkLen   = 0 ;
    }

    if (valueLen != chunkLen) {

        qDebug () << "Error: DecodeString, valueLen("<<valueLen<<") != chunkLen("<<chunkLen<<")" ;
        goto error ;
    }

    return decodedStr ;

error :
    return "" ;
}

QString Blockchain::DecodeChunkString(const QString& value)
{
    bool    ok = true ;
    quint64 decodedValue = 0 ;

    decodedValue = value.toULongLong(&ok, 16) ;
    if (!ok)
        qDebug() << "Error: DecodeChunkString, Conversion failed!";

    QByteArray array ;
    array.setNum(decodedValue, 16) ;
    QString decodedStr (QByteArray::fromHex(array)) ;

    return decodedStr ;
}


QString Blockchain::EncodeAddress(const QString& value)
{
// This is just the right representation (we does not require an encode operation)
    QString paddingValue ;
    QString encodedValue = "" ;

    if (value.left(2) == "0x")
        encodedValue = value.mid(2) ;

    if (encodedValue.length() != _AddrTypeLen) {
        qDebug() << "Error:Blockchain::EncodeAddress, the address is not correct (length should be equal to 20 bytes" ;
        encodedValue = "" ;
        goto error ;
    }

    paddingValue.fill('0', _AddrPaddLen) ;
    encodedValue = paddingValue + encodedValue.right(_AddrTypeLen) ;
error:
    return encodedValue ;
}

QString Blockchain::DecodeAddress(const QString& value)
{
// This is just the right representation (we does not require an encode operation)
    return "0x" + value.right(_AddrTypeLen) ;
}

QStringList Blockchain::DecodeAddressArray(const QString& value)
{
// T[] where X has k elements (k is assumed to be of type uint256)
// enc(X) = enc(k) enc([X[1], ..., X[k]])

    QStringList list        ;
    u_int64_t   dataPos   = 0 ;
    u_int64_t   eltNumber = 0 ;
    QString     addr      = "";

    dataPos   = (DecodeUint64(value.left(2 + _32Bytes))*2) + 2 ;      // +2 for "0x", *2 because 1Byte represented by 2Chars
    eltNumber = DecodeUint64(value.mid(dataPos, _32Bytes)) ; // mid(position, bytesNumber)
    dataPos   += _32Bytes ;
    if ((u_int64_t) value.mid(dataPos).length() != (_32Bytes * eltNumber)) {
        qDebug () << "Error:Blockchain::DecodeAddressArray the received adresses length is not correct" ;
        goto error ;
    }

    for (u_int64_t i =0; i < eltNumber; i++) {
        addr = value.mid(dataPos, _32Bytes) ;
        list << DecodeAddress(addr) ;
        dataPos += _32Bytes ;
    }

error:
    return list ;

}


QString Blockchain::EncodeUint8Array (u_int8_t * value, int64_t valueLen)
{

    QString encValue = "" ;

    if (value == NULL) {
        qDebug () << "Error:Blockchain::EncodeStatTab (value == NULL)" ;
        return "" ;
    }

    if (valueLen <= 0) {
        qDebug () << "Error:Blockchain::EncodeStatTab (valueLen <= 0)" ;
        return "" ;
    }

    encValue = EncodeInt64(valueLen) ;

    for (int i =0 ; i < valueLen; i++) {
        encValue += EncodeUint8(value[i]) ;
    }

    return encValue ;
}


/*not implemented*/
int32_t   DecodeUint8Array   (u_int8_t      * decValue,
                              int32_t         decValueLen,
                              const QString&  value)
{
    Q_UNUSED(decValue)    ;
    Q_UNUSED(decValueLen) ;
    Q_UNUSED(value)       ;
    return 0 ;
}
/*end*/

#endif



















