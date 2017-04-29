//sum:窗口分割右边的widget容器，页面绘制在此容器里
#ifndef DOCWIDGET_H
#define DOCWIDGET_H

#include <QWidget>
#include <QScrollArea>

#include "IChildViewer.h"
#include "ViewModel.h"

class DocWidget: public QWidget
{
public:
    DocWidget(IChildViewer* childviewer);
    ~DocWidget();

public:
    QScrollArea*        m_pScrollArea;  //滚动条区域
    QScrollBar*         m_pScrollBar;   //滚动条
    IChildViewer*       m_IChildViewer;

public:
    void paintEvent(QPaintEvent *e);
    QScrollArea* getScroll(){ return m_pScrollArea;}

};

#endif // DOCWIDGET_H
