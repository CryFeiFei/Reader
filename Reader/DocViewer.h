// summary: 中间主要文档显示区域

#ifndef DOC_VIEWER_H
#define DOC_VIEWER_H

#include <QWidget>
#include <QScrollArea>

class DocViewer : public QWidget
{
public:
    DocViewer();
    ~DocViewer();

public:
    QScrollArea* m_pscrollarea;

};

#endif // DOCVIEWER_H
