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

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), blockchain (NULL)
{
    setupUi(this) ;
    labelPicture->setPixmap(QPixmap("/home/mohamed/THESE/Journal/Implementation/img/pic1.png"));

}

MainWindow::~MainWindow()
{

}

void MainWindow::on_buttonStart_clicked ()
{
    blockchain = new Blockchain(lineEdit1->text(), lineEdit2->text()) ;
    lineEdit3->setText(blockchain->getContractAddress().mid(2)) ;
    if (!lineEdit3->text().isEmpty())
        buttonStart->setEnabled(false) ;

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
