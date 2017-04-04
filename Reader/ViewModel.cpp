
#include "ViewModel.h"
#include "ChildViewer.h"


ViewModel::ViewModel(ChildViewer* ChildViewer) : m_ChildViewer(ChildViewer), m_kit(NULL)
{
    m_kit = new PDFkit();
    // 测试用例
    QString filename;
    filename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/test.pdf";

    // todo待重构
    QString strFileName = m_ChildViewer->getFileName();
    m_kit->SetFileName(strFileName);
    m_kit->Init();

}

ViewModel::~ViewModel()
{

}

void ViewModel::RenderPages(QPainter *painter)
{
    if (painter == NULL)
        return;

    QSize size = m_ChildViewer->getActruallyPageSize(0);
    QImage imag = m_ChildViewer->getActruallyPageImage(0);


    QImage image1 = m_ChildViewer->getActruallyPageImage(0);
    painter->drawImage(0,0,image1);

    QImage image2 = m_ChildViewer->getActruallyPageImage(1);
    painter->drawImage(0, size.height(), image2);
}

