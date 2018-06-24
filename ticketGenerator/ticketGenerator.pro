#-------------------------------------------------
#
# Project created by QtCreator 2016-12-28T16:16:31
#
#-------------------------------------------------

QT       += core gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ticketGenerator
TEMPLATE = app


SOURCES += main.cpp\
           mainwindow.cpp\
           uECC.cpp \
           Convertion.cpp\
           sha3.cpp

HEADERS  += mainwindow.h\
            ECC.h\
            uECC.h \
            Convertion.h\
            sha3.h

FORMS    += \
    MainWindow.ui
