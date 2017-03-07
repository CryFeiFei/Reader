// summary: 中间主要文档显示区域

#ifndef DOC_VIEWER_H
#define DOC_VIEWER_H

#include <QWidget>
#include <QScrollArea>

class ChildViewer;

class DocViewer : public QWidget
{
public:
    DocViewer(ChildViewer* childviewer);
    ~DocViewer();

public:
    QScrollArea*        m_pscrollarea;
    ChildViewer*        m_ChildViewer; //todo待重构


};

#endif // DOCVIEWER_H
