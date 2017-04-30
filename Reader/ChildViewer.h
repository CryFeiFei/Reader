// summary:单文档显示区域

#ifndef ChildViewer_H
#define ChildViewer_H

#include <QWidget>
#include <QSplitter>
#include <QTabWidget>
#include <QLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>

#include "IChildViewer.h"
#include "NaviViewer.h"
#include "ViewModel.h"
#include "DocWidget.h"
#include "IMainViewer.h"


class ChildViewer : public IChildViewer
{
    Q_OBJECT

public:
    ChildViewer(IMainViewer* iMainViewer);
    ~ChildViewer();
    void resizeEvent(QResizeEvent *event);

    void newFile()
    {
        setWindowTitle("qwe");
    }

public:
    virtual QString getFileName() { return m_strFileName; }
    virtual QScrollArea* getScrollArea() { return m_pDocWidget->getScrollArea(); }
    virtual int getNumCount() { return m_ViewModel->GetNumCount(); }
    virtual QSize getActruallyPageSize(int nPageNum) { return m_ViewModel->GetActruallyPageSize(nPageNum); }
    virtual QImage getActruallyPageImage(int nPageNum) { return m_ViewModel->GetActruallyPageImage(nPageNum); }
    virtual void RenderPages(QPainter *painter) { m_ViewModel->RenderPages(painter); }
    virtual double getCurDocMultiple(){ return m_dCurDocMultiple; }
    virtual QImage getPageImage(int nPageNum, int x, int y, int w, int h, int rotate) { return m_ViewModel->GetPageImage(nPageNum, x, y, w, h, rotate); }
    virtual int getActruallyPageHighCount() { return m_ViewModel->GetActruallyPageHighCount();}
    virtual QSize getDocWidgetSize() { return m_pDocWidget->size(); }

private:
    enum DocState
    {
        SINGLE_CONTINUOUS,
        UNSINGLE_CONTINUOUS,
        DOUBLE_CONTINUOUS,
        UNDOUBLE_CONTINUOUS
    };

    ViewModel*            m_ViewModel;     // the most imporent point
    DocState              m_docstate;
    double                m_dCurDocMultiple; //当前文档放大倍数



public:
    IMainViewer*          m_IMainViewer;
    QString               m_strFileName;
    QSplitter*            m_splitterMain;
    NaviViewer*           m_navigationBar; //左边导航栏
    DocWidget*            m_pDocWidget;    //右边绘制widget

private:

    void InitOutline(); //初始化大纲树
    void InitThumbnail(); //初始化缩略图
    void InitSemantic(); //初始化语义树
    void CreatNavigationBar(); //创建导航栏

};

#endif // ChildViewer_H
