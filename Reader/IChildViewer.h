#ifndef I_CHILDVIEWER_H
#define I_CHILDVIEWER_H

#include "ReadDefine.h"

class DocWidget;

class IChildViewer : public QWidget
{
public:
	IChildViewer(){}
	virtual ~IChildViewer(){}

public:
	// 获得
	virtual QString getFileName() = 0;
	virtual QScrollArea* getScrollArea() = 0;
	virtual int getPageCount() = 0;
	virtual QSize getActruallyPageSize(int nPageNum) = 0;
	virtual QImage getActruallyPageImage(int nPageNum) = 0;
	virtual QSize getPageSize(int nPageNum) = 0;
	virtual QImage getPageImage(int nPageNum) = 0;
	virtual void RenderPages(QPainter *painter) = 0;
	virtual double getCurDocMultiple() = 0;
	virtual int getActruallyPageHighCount() = 0;
	virtual int getPageHighCount() = 0;
	virtual int getActruallyMaxPageWidth() = 0;
	virtual int getMaxPageWidth() = 0;
	virtual QSize getDocWidgetSize() = 0;
	virtual int getCurPageNum() = 0;
	virtual QDomDocument* getTOC() = 0;
};

#endif // I_CHILDVIEWER_H
