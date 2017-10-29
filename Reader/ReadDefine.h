#ifndef DEFINE_H
#define DEFINE_H

#include <QWidget>
#include <QSplitter>
#include <QTabWidget>
#include <QLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QString>
#include <QImage>
#include <QSplitter>
#include <QDomDocument>
#include <QPainter>
#include <QListWidget>
#include <QTimer>
#include <QTreeWidget>
#include <QListView>
#include "float.h"

enum DocState
{
	SINGLE_CONTINUOUS,
	UNSINGLE_CONTINUOUS,
	DOUBLE_CONTINUOUS,
	UNDOUBLE_CONTINUOUS
};

//用于PDF中TOC的数据结构
typedef struct _TOCInfo
{
public:
	QString strDestination;
	QString strDestinationName;
	QString strExternalFileName;
	bool bIsOpen;
}TOCInfo;

//文档倍数
//static double doc_multiple[] = {0.5, 0.75, 1, 1.5, 1.75, 2};

#define DELETE_POINT(p){delete p; p = NULL;}
#define DELETE_ARRAY(p){delete[](p); (p) = NULL;}

#endif // DEFINE_H
