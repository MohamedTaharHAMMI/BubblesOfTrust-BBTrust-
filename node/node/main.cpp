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
#include <QApplication>

#include "Blockchain.h"







int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();

    return a.exec();
}
