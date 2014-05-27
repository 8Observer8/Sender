#-------------------------------------------------
#
# Project created by QtCreator 2014-05-27T07:29:42
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Transmitter
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp

HEADERS  += Dialog.h \
    Sender.h \
    PortError.h

FORMS    += Dialog.ui
