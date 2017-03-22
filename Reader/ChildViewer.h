// summary:单文档显示区域

#ifndef ChildViewer_H
#define ChildViewer_H

#include <QWidget>
#include <QSplitter>
#include <QTextEdit>
#include <QTabWidget>
#include <QLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>

#include "IChildViewer.h"
#include "NaviViewer.h"
#include "DocViewer.h"


class ChildViewer : public IChildViewer
{
    Q_OBJECT

public:
    ChildViewer();
    ~ChildViewer();
    void resizeEvent(QResizeEvent *event);

    void newFile()
    {
        setWindowTitle("qwe");
    }

public:
    virtual QScrollArea* getScrollArea() { return m_pscrollarea; }


public:
    QSplitter*            m_splitterMain;
    NaviViewer*           m_navigationBar; //左边导航栏
    QWidget*              m_Canves;

    QScrollArea*          m_pscrollarea;




public:

    void InitOutline(); //初始化大纲树
    void InitThumbnail(); //初始化缩略图
    void InitSemantic(); //初始化语义树
    void CreatNavigationBar(); //创建导航栏

};

#endif // ChildViewer_H
