// summary: 中间主要文档显示区域

#ifndef DOC_VIEWER_H
#define DOC_VIEWER_H

#include <QWidget>
#include <QScrollArea>
#include <QPainter>

// 测试头文件
#include <QStandardPaths>
#include <QWidget>
#include <QPalette>
#include <QDesktopWidget>

#include "IChildViewer.h"
#include "ViewModel.h"

class DocViewer : public QWidget
{

public:
    DocViewer(IChildViewer* childviewer);
    ~DocViewer();

public:
    QScrollArea*        m_pscrollarea;
    QScrollBar*         m_pScrollBar;
    IChildViewer*       m_IChildViewer;


public:
    void paintEvent(QPaintEvent *e);
    QScrollArea* getScroll(){ return m_pscrollarea;}


};

#endif // DOCVIEWER_H
