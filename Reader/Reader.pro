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
    NaviViewer.cpp \
    MainViewer.cpp \
    ChildViewer.cpp \
    Kit.cpp

HEADERS  += \
    PDFkit.h \
    NaviViewer.h \
    MainViewer.h \
    ChildViewer.h \
    Kit.h

RESOURCES += \
    resource.qrc
