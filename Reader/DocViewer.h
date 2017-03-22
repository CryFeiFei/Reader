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

#include "IChildViewer.h"

//class IChildViewer;

class DocViewer : public QWidget
{

public:
    DocViewer(IChildViewer* childviewer);
    ~DocViewer();

public:
    QScrollArea*        m_pscrollarea;
    QScrollBar*         m_pScrollBar;
    IChildViewer*       m_IChildViewer;

    // kit层不应该出现在这里，逻辑层应该与界面层分开
    Kit*                m_kit;

public:
    void paintEvent(QPaintEvent *e);


};

#endif // DOCVIEWER_H
