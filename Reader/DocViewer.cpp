#include "DocViewer.h"

DocViewer::DocViewer(ChildViewer* childviewer) : m_pscrollarea(NULL), m_ChildViewer(childviewer)
{
    // 支持别的格式的话，在这里用构造函数来创建新的子类对象
    m_kit = new PDFkit();

    // 测试用例
    QString filename;
    filename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/test.pdf";

    m_kit->SetFileName(filename);
    m_kit->Init();

}

DocViewer::~DocViewer()
{

}

void DocViewer::paintEvent(QPaintEvent *e)
{
    QPainter* painter = new QPainter(this);

    QSize size = m_kit->GetActruallyPageSize(0);
    QImage imag = m_kit->GetActruallyPageImage(0);

    painter->drawImage(0,0,imag);

    imag = m_kit->GetActruallyPageImage(1);
    painter->drawImage(0, size.height(), imag);

}


