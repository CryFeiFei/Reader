// summary: 中间主要文档显示区域

#ifndef DOC_VIEWER_H
#define DOC_VIEWER_H

#include <QWidget>
#include <QScrollArea>
#include <QPainter>

#include "IChildViewer.h"
#include "ViewModel.h"
#include "IDocWidget.h"

class DocViewer : public QWidget
{

public:
    DocViewer(IDocWidget* DocWidget);
    ~DocViewer();

public:
    QScrollArea*        m_pscrollarea;
    QScrollBar*         m_pScrollBar;
//    IChildViewer*       m_IChildViewer;
    IDocWidget*         m_IDocWidget;


public:
    void paintEvent(QPaintEvent *e);
    QScrollArea* getScroll(){ return m_pscrollarea;}


};

#endif // DOCVIEWER_H
