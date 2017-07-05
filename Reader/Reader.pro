#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T22:02:44
#
#-------------------------------------------------

QT       += core gui
QT       += xml

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
    PDFkit.cpp \
    ViewModel.cpp \
    ImageCache.cpp \
    ViewState.cpp \
    SingleContinuousState.cpp \
    DocWidget.cpp \
    ThumbnailWidget.cpp \
    TOCModel.cpp \
    TOCTreeItem.cpp

HEADERS  += \
    PDFkit.h \
    NaviViewer.h \
    MainViewer.h \
    ChildViewer.h \
    Kit.h \
    DocViewer.h \
    MultiViwer.h \
    IChildViewer.h \
    ViewModel.h \
    IMainViewer.h \
    ImageCache.h \
    ViewState.h \
    SingleContinuousState.h \
    DocWidget.h \
    IDocWidget.h \
    ReadDefine.h \
    ThumbnailWidget.h \
    TOCModel.h \
    TOCTreeItem.h

RESOURCES += \
    resource.qrc

INCLUDEPATH += $$PWD/3rdparty/Win32/poppler
win32: LIBS += -L$$PWD/3rdparty/Win32/poppler -llibpoppler
win32: LIBS += -L$$PWD/3rdparty/Win32/poppler -llibpoppler-qt5

unix: PKGCONFIG += poppler-qt5
unix: CONFIG += c++11 link_pkgconfig

DISTFILES +=
