#include "DocViewer.h"

DocViewer::DocViewer(IChildViewer* childviewer) : m_IChildViewer(childviewer)
{
    // 支持别的格式的话，在这里用构造函数来创建新的子类对象
    m_kit = new PDFkit();

    // 测试用例
    QString filename;
    filename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/test.pdf";

    m_pscrollarea = m_IChildViewer->getScrollArea();




    // todo待重构
    m_kit->SetFileName(filename);
    m_kit->Init();

    int nNumCount = m_IChildViewer->getNumCount();
    QSize size = m_IChildViewer->getActruallyPageSize(0);

    this->resize(size.width(), size.height() * nNumCount);

    m_pscrollarea->setBackgroundRole(QPalette::Dark);
    m_pscrollarea->setWidget(this);

}

DocViewer::~DocViewer()
{

}


void DocViewer::paintEvent(QPaintEvent *e)
{
    QPainter* painter = new QPainter(this);

    QSize size = m_kit->GetActruallyPageSize(0);
    QImage imag = m_kit->GetActruallyPageImage(0);


    QImage image1 = m_kit->GetActruallyPageImage(0);
    painter->drawImage(0,0,image1);

    QImage image2 = m_kit->GetActruallyPageImage(1);
    painter->drawImage(0, size.height(), image2);

}


