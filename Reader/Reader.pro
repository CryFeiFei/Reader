#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T22:02:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Reader
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    kit.cpp \
    mdichild.cpp \
    navigationwidget.cpp

HEADERS  += mainwindow.h \
    PDFkit.h \
    kit.h \
    mdichild.h \
    navigationwidget.h

RESOURCES += \
    resource.qrc
