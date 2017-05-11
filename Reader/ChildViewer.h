// summary:单文档显示区域

#ifndef ChildViewer_H
#define ChildViewer_H

#include "ReadDefine.h"

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

public:
    virtual QString getFileName() { return m_strFileName; }
    virtual QScrollArea* getScrollArea() { return m_pDocWidget->getScrollArea(); }
    virtual int getNumCount() { return m_ViewModel->GetNumCount(); }
    virtual QSize getActruallyPageSize(int nPageNum) { return m_ViewModel->GetActruallyPageSize(nPageNum); }
    virtual QImage getActruallyPageImage(int nPageNum) { return m_ViewModel->GetActruallyPageImage(nPageNum); }
    virtual QSize getPageSize(int nPageNum) { return m_ViewModel->GetPageSize(nPageNum); }
    virtual QImage getPageImage(int nPageNum) { return m_ViewModel->GetPageImage(nPageNum); }
    virtual void RenderPages(QPainter *painter) { m_ViewModel->RenderPages(painter); }
    virtual double getCurDocMultiple(){ return m_dCurDocMultiple; }
    virtual int getActruallyPageHighCount() { return m_ViewModel->GetActruallyPageHighCount();}
    virtual int getPageHighCount() { return m_ViewModel->GetPageHighCount(); }
    virtual QSize getDocWidgetSize() { return m_pDocWidget->size(); }

public:
    void ZoomIn();
    void ZoomOut();
    void ZoomReset();
    double ComputeMul();

public:
    void resizeEvent(QResizeEvent *event);
    void RefreshWindow(); //刷新界面

private:
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
