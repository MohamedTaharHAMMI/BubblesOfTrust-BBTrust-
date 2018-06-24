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










#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <time.h>
#include <QStringListModel>
#include "ui_MainWindow.h"
#include "Blockchain.h"




class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0) ;
    ~MainWindow() ;

    void    setLogo(QString imageFileName) ;
    int32_t FromQStringToUint8(u_int8_t * bytes, int32_t bytesLen, const QString& strArray) ;
    void    Print_uint8 (const char * title, u_int8_t * data, int32_t dataLen) ;



public slots:
    void SwitchLogo    (int index) ;
    void on_startButton_clicked () ;
    void on_sendButton_clicked  () ;
    void on_readButton_clicked  () ;

//signals:
//    void UpdateView ();

private:
    Blockchain * blockchain ;
    u_int8_t     m_category ;


};

#endif // MAINWINDOW_H
