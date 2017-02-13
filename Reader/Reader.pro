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
    Kit.cpp \
    DocViewer.cpp \
    MultiViewer.cpp \
    PDFkit.cpp

HEADERS  += \
    PDFkit.h \
    NaviViewer.h \
    MainViewer.h \
    ChildViewer.h \
    Kit.h \
    DocViewer.h \
    MultiViwer.h

RESOURCES += \
    resource.qrc

INCLUDEPATH += $$PWD/_Inclusion/Win32/poppler
win32: LIBS += -L$$PWD/_Inclusion/Win32/poppler -llibpoppler
win32: LIBS += -L$$PWD/_Inclusion/Win32/poppler -llibpoppler-qt5
