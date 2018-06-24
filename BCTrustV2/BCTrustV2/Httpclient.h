#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H



#include <QCoreApplication>
#include <QDebug>
#include <QtCore/qjsonvalue.h>
#include <QJsonObject>
#include <qjsonvalue.h>
#include "qjsonrpchttpclient.h"


class HttpClient : public QJsonRpcHttpClient
{
    Q_OBJECT
public:
    HttpClient(const QString &endpoint, QObject *parent = 0) : QJsonRpcHttpClient(endpoint, parent)
    {
    }

};


#endif // HTTPCLIENT_H
