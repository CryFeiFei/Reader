
#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "Kit.h"
#include "PDFkit.h"
#include "ViewState.h"
#include "SingleContinuousState.h"


// 测试头文件
#include <QWidget>

class ChildViewer;
class DocWidget;

class ViewModel
{
public:
    ViewModel(ChildViewer* ChildViewer);
    ~ViewModel();

public:
    ChildViewer*   m_ChildViewer;
    Kit*           m_kit;

private:
    ViewState*     m_ViewState;
    double         m_DocMultiple;

public:
    int     GetNumCount() { return m_kit->GetNumCount(); }
    QSize   GetActruallyPageSize(int nPageNum) { return m_kit->GetActruallyPageSize(nPageNum); }
    QImage  GetActruallyPageImage(int nPageNum) { return m_kit->GetActruallyPageImage(nPageNum); }
    QSize   GetPageSize(int nPageNum) { return m_kit->GetPageSize(nPageNum);}
    QImage  GetPageImage(int nPageNum) { return m_kit->GetPageImage(nPageNum);}
    int     GetActruallyPageHighCount();
    int     GetPageHighCount();
    int     GetCurPageNum() { return m_ViewState->GetCurPageNum();}
public:
    ChildViewer*   GetChildViewer() { return m_ChildViewer; }
    void    SetDocMultiple(double docMultiple);

public:
    void RenderPages(QPainter* paint);
};

#endif // VIEWMODEL_H
