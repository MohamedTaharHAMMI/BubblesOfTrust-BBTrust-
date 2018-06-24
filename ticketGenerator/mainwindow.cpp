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
#include <QDebug>
#include <QMessageBox>







MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ecc (NULL)
{
    setupUi(this) ;
    labelPicture->setPixmap(QPixmap("/home/mohamed/THESE/Journal/Implementation/img/ticket2.png")) ;

    ecc = new ECC (uECC_secp256k1()) ;
}

MainWindow::~MainWindow()
{
    if (ecc != NULL) {
        delete ecc ;
        ecc = NULL ;
    }
}



void MainWindow::on_generateButton_clicked ()
{
    uint8_t   masterPrivateKey [PRIVKEY_SIZE]      ;
    uint8_t   objectPrivateKey [PRIVKEY_SIZE]      ;
    uint8_t   objectPublicKey  [PUBKEY_SIZE ]      ;
    uint8_t   objectAddress    [ADDR_SIZE   ]      ;
    uint8_t * ticket = new uint8_t [SIG_SIZE];//          [SIG_SIZE    ] = {0};
    uint8_t   ticketInputData  [1 + 1 + ADDR_SIZE] ; // grp_id_len + obj_id_len + obj_addr
    uint8_t   groupeId                          ;
    uint8_t   objectId                          ;
    uint8_t * pbuffer = NULL                       ;
    uint8_t * ebuffer = NULL                       ;

    if (lineEdit1->text().length() != PRIVKEY_SIZE * 2) {
        QMessageBox::warning(this, "Warning", "Check the validity of the master private key please..") ;
        return ;
    }

    if (lineEdit4->text().length() != PRIVKEY_SIZE * 2) {
        QMessageBox::warning(this, "Warning", "Check the validity of the object private key please..") ;
        return ;
    }

    if (Convertion::ReadPrivKey(masterPrivateKey, PRIVKEY_SIZE, lineEdit1->text())) {
        QMessageBox::warning(this, "Warning", "read masterPrivKey operation failed..") ;
        return ;
    }

    if (Convertion::ReadPrivKey(objectPrivateKey, PRIVKEY_SIZE, lineEdit4->text())) {
        QMessageBox::warning(this, "Warning", "read objectPrivKey operation failed..") ;
        return ;
    }


    ecc->ECC_getPubKey(objectPrivateKey, PRIVKEY_SIZE, objectPublicKey, PUBKEY_SIZE) ;
    textEdit1->setPlainText(Convertion::FromUint8ToQString(objectPublicKey, PUBKEY_SIZE)) ;

    ecc->ECC_getAddress(objectPublicKey,PUBKEY_SIZE, objectAddress, ADDR_SIZE) ;
    textEdit2->setText(Convertion::FromUint8ToQString(objectAddress, ADDR_SIZE)) ;


    groupeId = (u_int8_t) lineEdit2->text().toLong(0,16) ;

    objectId = (u_int8_t) lineEdit3->text().toLong(0,16) ;

    pbuffer = ticketInputData ;
    ebuffer = pbuffer + 1 + 1 + ADDR_SIZE ;

    pbuffer[0] = groupeId ;
    pbuffer[1] = objectId ;
    pbuffer += 2 ;

    memcpy(pbuffer, objectAddress, ADDR_SIZE) ;
    pbuffer += ADDR_SIZE ;

    if (pbuffer != ebuffer) {
        QMessageBox::critical(this, "Error", "ticket generation failed (internal error)..") ;
        return ;
    }

    if (ecc->ECC_sign(ticket, SIG_SIZE, masterPrivateKey, PRIVKEY_SIZE, ticketInputData, 1 + 1 + ADDR_SIZE)) {
        QMessageBox::critical(this, "Error", "ticket generation failed ..") ;
        return ;
    }

    ecc->ECC_print_uint8("ticket ", ticket, SIG_SIZE) ;
    textEdit3->setText(Convertion::FromUint8ToQString(ticket, SIG_SIZE)) ;

    delete[] ticket ;

}

