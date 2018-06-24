#-------------------------------------------------
#
# Project created by QtCreator 2016-12-28T16:16:31
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11

include(./devonit-qjsonrpc-f85751b70231/qjsonrpc.pri)
include(./devonit-qjsonrpc-f85751b70231/tests/tests.pri)


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Diaries
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Blockchain.cpp

HEADERS  += mainwindow.h \
    Blockchain.h \
    Httpclient.h

FORMS    += \
    MainWindow.ui
