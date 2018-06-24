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





#include "mainwindow.h"
#include <QMessageBox>
#include <QTimer>






#define FOLLOWER_IMG "/home/mohamed/THESE/Journal/Implementation/img/follower.png"
#define MASTER_IMG   "/home/mohamed/THESE/Journal/Implementation/img/master.png"
#define FAIL_TRANSAC "/home/mohamed/THESE/Journal/Implementation/img/failed.png"
#define SUCC_TRANSAC "/home/mohamed/THESE/Journal/Implementation/img/success.png"




MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), blockchain (NULL), m_category (1)
{
    setupUi(this) ;
    setLogo("/home/mohamed/THESE/Journal/Implementation/img/follower.png") ;
    QObject::connect(comboBox, SIGNAL(currentIndexChanged (int)), this, SLOT(SwitchLogo(int))) ;

}

MainWindow::~MainWindow()
{

}


void MainWindow::setLogo(QString imageFileName)
{
    labelPicture->setPixmap(QPixmap(imageFileName));
}

void MainWindow::SwitchLogo(int index)
{
    if (index == 0) {
        setLogo(FOLLOWER_IMG) ;
        m_category = 1 ; // follower
        textEdit->setEnabled(true) ;
    }
    else {
        setLogo(MASTER_IMG);
        m_category = 0 ;
        textEdit->setEnabled(false);
    }
}
void MainWindow::on_startButton_clicked ()
{
    QString transactionHash ;
    QString warnings = "" ;
    u_int64_t res = 0 ;

    if (lineEdit1->text().length() < 7)
        warnings.append("Check the validity of your IP address..\n"     ) ;
    if (lineEdit2->text().isEmpty())
        warnings.append("Check the validity of your port value..\n"     ) ;
    if (lineEdit3->text().length() != 40)
        warnings.append("Check the validity of the contract address..\n") ;
    if (lineEdit4->text().isEmpty() || lineEdit4->text() == "00000000")
        warnings.append("Check the validity of your group ID..\n"       ) ;
    if (lineEdit5->text().isEmpty() || lineEdit5->text() == "00000000")
        warnings.append("Check the validity of your node ID..\n"        ) ;
    if (lineEdit6->text().length() != 40)
        warnings.append("Check the validity of your public address..\n" ) ;
    if ((textEdit->toPlainText().length() != 0) && (textEdit->toPlainText().length() != 128))
        warnings.append("Check the validity of your ticket <length should = 64 bytes or none>..\n" ) ;

    if (!warnings.isEmpty()) {
        QMessageBox::warning(this, "Warning", warnings) ;
        return ;
    }


    blockchain = new Blockchain(lineEdit1->text(), lineEdit2->text()) ;

    blockchain->setMyExternalAddress(lineEdit6->text()) ;
    blockchain->setContractAddress(lineEdit3->text());



    QString     paramsTypes ("uint8,uint8,uint8,uint256,uint256") ;
    QStringList paramsValues ;

    paramsValues.append (blockchain->EncodeUint8 (m_category)) ;                            // category
    paramsValues.append (blockchain->EncodeUint8(lineEdit4->text().toUInt(0, 16)))  ;       // groupe ID
    paramsValues.append (blockchain->EncodeUint8(lineEdit5->text().toUInt(0, 16)))  ;       // object ID
    if(!textEdit->toPlainText().isEmpty()) {
        paramsValues.append (blockchain->EncodeUint256((const QString) textEdit->toPlainText().left(64)))  ;  // r --> (signature parameter 1)
        paramsValues.append (blockchain->EncodeUint256((const QString) textEdit->toPlainText().right(64))) ;  // s --> (signature parameter 2)
    } else {
        paramsValues.append (blockchain->EncodeString("")) ;
        paramsValues.append (blockchain->EncodeString("")) ;
    }


     transactionHash = blockchain->CallFunction(blockchain->getMyExternalAddress(),
                                                blockchain->getContractAddress(),
                                                blockchain->EncodeFunction(blockchain->EncodeFunctionSelector("BCTrustV2_AddNode(uint8,uint8,uint8,uint256,uint256)"),
                                                                           paramsTypes,
                                                                           paramsValues),
                                                "eth_sendTransaction"
                                                ) ;
    qDebug() << transactionHash ;

    paramsValues.clear() ;

    paramsTypes = "" ;


    res =    blockchain->DecodeUint64(blockchain->CallFunction(blockchain->getMyExternalAddress(),
                                                               blockchain->getContractAddress(),
                                                               blockchain->EncodeFunction(blockchain->EncodeFunctionSelector("test()"),
                                                                                          paramsTypes,
                                                                                          paramsValues),
                                                               "eth_call"
                                                               )
                                      ) ;

    if  (res != 0 && transactionHash != "") {
        labTansaction->setPixmap(QPixmap(SUCC_TRANSAC)) ;
        this->setMinimumHeight(480) ;

    } else {
        labTansaction->setPixmap(QPixmap(FAIL_TRANSAC)) ;
    }


}


void MainWindow::on_sendButton_clicked()
{
    QString     transactionHash ;
    QString     paramsTypes ("uint8,uint8,string") ;
    QStringList paramsValues ;

    QString     msg = lineEdit5->text() + ": " + textEdit2->toPlainText() ;

    paramsValues.append (blockchain->EncodeUint8 (lineEdit5->text().toUInt(0, 16))) ; // object ID of the sender
    paramsValues.append (blockchain->EncodeUint8 (lineEdit7->text().toUInt(0, 16))) ; // object ID of the receiver
    paramsValues.append (blockchain->EncodeString(msg)) ;


     transactionHash = blockchain->CallFunction(blockchain->getMyExternalAddress(),
                                                blockchain->getContractAddress(),
                                                blockchain->EncodeFunction(blockchain->EncodeFunctionSelector("BCTrustV2_Send(uint8,uint8,string)"),
                                                                           paramsTypes,
                                                                           paramsValues),
                                                "eth_sendTransaction"
                                                ) ;
    qDebug() << transactionHash ;

    paramsValues.clear() ;

}

void MainWindow::on_readButton_clicked()
{
    QString     res = "" ;
    QString     paramsTypes ("uint8") ;
    QStringList paramsValues ;

    paramsValues.append (blockchain->EncodeUint8 (lineEdit5->text().toUInt(0, 16))) ; // object ID of the sender

    res = blockchain->DecodeString(blockchain->CallFunction(blockchain->getMyExternalAddress(),
                                                            blockchain->getContractAddress(),
                                                            blockchain->EncodeFunction(blockchain->EncodeFunctionSelector("BCTrustV2_ReadMSG(uint8)"),
                                                                                       paramsTypes,
                                                                                       paramsValues),
                                                            "eth_call"
                                                            )
                                   ) ;
    if (res != "") {
        textEdit2->append(res) ;
    }
    paramsValues.clear() ;

}


int32_t MainWindow::FromQStringToUint8(u_int8_t * bytes, int32_t bytesLen, const QString& strArray)
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
        qDebug () << "MainWindow::FromQStringToUint8, bytesLen != strArray.length()/2" ;
        rc = (int32_t) 1 ;
        goto error ;
    }

    for (int i = 0; i < bytesLen; i++)
        bytes[i] = strArray.mid(i*2,2).toUInt(0,16) ;


error:

    return rc ;
}



void MainWindow::Print_uint8 (const char * title, u_int8_t * data, int32_t dataLen)
{
    printf("%s", title) ;
    int i ;
    for (i = 0; i < dataLen; i++) {
        printf("%02X",data[i]) ;
    }
    printf("\n") ;
}

















/*
void MainWindow::on_pushButton1_clicked ()
{
    QString     paramsTypes ("string") ;
    QStringList paramsValues ;
    paramsValues.append (blockchain->EncodeString(plainTextEdit1->toPlainText())) ;


    blockchain->CallFunction(blockchain->getCoinbase(),
                             blockchain->getContractAddress(),
                             blockchain->EncodeFunction(blockchain->EncodeFunctionSelector("WriteStory(string)"),
                                                        paramsTypes,
                                                        paramsValues),
                             "eth_sendTransaction"
                             ) ;
    lineEdit3->setText(blockchain->getContractAddress()) ;
    lineEdit4->setText(blockchain->getContractAddress()) ;

    paramsValues.clear() ;
}
*/

/*void MainWindow::on_pushButton2_clicked ()
{
    QString     paramsTypes ("uint256");
    QStringList paramsValues ;
    paramsValues.append (blockchain->EncodeUint64((u_int64_t) spinBox->value())) ;

    plainTextEdit2->setPlainText(blockchain->DecodeString(
                                                          blockchain->CallFunction(blockchain->getCoinbase(),
                                                                                   lineEdit4->text(),
                                                                                   blockchain->EncodeFunction(blockchain->EncodeFunctionSelector("ReadStory(uint256)"),
                                                                                                              paramsTypes,
                                                                                                              paramsValues),
                                                                                    "eth_call"
                                                                                    )
                                                         )
                                 ) ;
    BalanceUpdateValue() ;
}
*/
