
#include "ViewModel.h"
#include "ChildViewer.h"


ViewModel::ViewModel(ChildViewer* ChildViewer) : m_ChildViewer(ChildViewer), m_kit(NULL)
{
    m_kit = new PDFkit();

    // todo待重构
    QString strFileName = m_ChildViewer->getFileName();
    m_kit->SetFileName(strFileName);
    m_kit->Init();

    m_ViewState = new SingleContinuousState(m_ChildViewer);

}

ViewModel::~ViewModel()
{

}

int ViewModel::GetActruallyPageHighCount()
{
    int nPageHighCount = 0;
    int nPageCount = GetPageCount();
    for (int i = 0; i < nPageCount; i++)
        nPageHighCount += (GetActruallyPageSize(i).height() + 8);

    return nPageHighCount;
}

int ViewModel::GetPageHighCount()
{
    int nPageHighCount = 0;
    int nPageCount = GetPageCount();
    for (int i =0; i < nPageCount; i++)
        nPageHighCount += (GetPageSize(i).height() + 8);

    return nPageHighCount;
}

void ViewModel::SetDocMultiple(double docMultiple)
{
    m_DocMultiple = docMultiple;
    m_kit->SetDocMultiple(docMultiple);
}

void ViewModel::RenderPages(QPainter *painter)
{
    if (painter == NULL || m_ViewState == NULL)
        return;

    m_ViewState->RenderPages(painter);
}




