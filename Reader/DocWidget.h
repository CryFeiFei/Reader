//sum:窗口分割右边的widget容器，页面绘制在此容器里
#ifndef DOCWIDGET_H
#define DOCWIDGET_H

#include <QWidget>
#include <QScrollArea>

#include "IDocWidget.h"
#include "ViewModel.h"
#include "DocViewer.h"

class IChildViewer;

class DocWidget: public IDocWidget
{
//    Q_OBJECT
public:
    DocWidget(IChildViewer* childviewer);
    ~DocWidget();

public:
    virtual int getPageCount(){ return m_IChildViewer->getPageCount();}
    virtual QSize getActruallyPageSize(int nPageNum) { return m_IChildViewer->getActruallyPageSize(nPageNum);}
    virtual QImage getActruallyPageImage(int nPageNum) { return m_IChildViewer->getActruallyPageImage(nPageNum);}
    virtual void RenderPages(QPainter *painter) { m_IChildViewer->RenderPages(painter);}
    virtual QScrollArea* getScrollArea() { return m_pScrollArea;}

public:
    QScrollArea*        m_pScrollArea;  //滚动条区域
    QScrollBar*         m_pScrollBar;   //滚动条
    IChildViewer*       m_IChildViewer;
    DocViewer*          m_pDocViewer;   //绘制区域

public:
//    void paintEvent(QPaintEvent *e);
    QScrollArea* getScroll(){ return m_pScrollArea;}
    void RefreshWindow();

public:
    void resizeEvent(QResizeEvent* e);

};

#endif // DOCWIDGET_H
