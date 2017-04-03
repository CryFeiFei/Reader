#include "ViewModel.h"


ViewModel::ViewModel(ChildViewer* ChildViewer) : m_ChildViewer(ChildViewer), m_kit(NULL)
{
    m_kit = new PDFkit();
    // 测试用例
    QString filename;
    filename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/test.pdf";

    // todo待重构
    m_kit->SetFileName(filename);
    m_kit->Init();

}

ViewModel::~ViewModel()
{
}

int ViewModel::GetNumCount()
{
    return m_kit->GetNumCount();
}

QSize ViewModel::GetActruallyPageSize(int nPageNum)
{
    return m_kit->GetActruallyPageSize(nPageNum);
}
