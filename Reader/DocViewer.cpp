#include "DocViewer.h"

DocViewer::DocViewer(ChildViewer* childviewer) : m_pscrollarea(NULL), m_ChildViewer(childviewer)
{
    m_PDFkit = new PDFkit();
 //   m_PDFkit->Init();

    // 测试用例
    QString filename;
    filename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/test.pdf";

    m_PDFkit->Init(filename);

}

DocViewer::~DocViewer()
{

}

void DocViewer::paintEvent(QPaintEvent *e)
{
    QPainter* painter = new QPainter(this);

    QSize size = m_PDFkit->GetActruallyPageSize(0);
    QImage imag = m_PDFkit->GetActruallyPageImage(0);

    painter->drawImage(0,0,imag);

    imag = m_PDFkit->GetActruallyPageImage(1);
    painter->drawImage(0, size.height(), imag);

}


