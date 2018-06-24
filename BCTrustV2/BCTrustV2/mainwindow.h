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


private:
    Blockchain * blockchain ;

public slots:
    void on_buttonStart_clicked () ;


//signals:
//    void UpdateView ();


};

#endif // MAINWINDOW_H
