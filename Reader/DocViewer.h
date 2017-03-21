// summary: 中间主要文档显示区域

#ifndef DOC_VIEWER_H
#define DOC_VIEWER_H

#include <QWidget>
#include <QScrollArea>
#include <QPainter>

// 暂时这样写
#include "Kit.h"
#include "PDFkit.h"

// 测试头文件
#include <QStandardPaths>
#include <QWidget>
#include <QPalette>
#include <QDesktopWidget>

class ChildViewer;

class DocViewer : public QWidget
{

public:
    DocViewer(ChildViewer* childviewer);
    ~DocViewer();

public:
    QScrollArea*        m_pscrollarea;
    ChildViewer*        m_ChildViewer; //todo待重构,应该传进来接口父类而不是直接传进来

    Kit*             m_kit;

public:
    void paintEvent(QPaintEvent *e);


};

#endif // DOCVIEWER_H
