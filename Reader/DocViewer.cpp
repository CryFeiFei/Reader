#include "DocViewer.h"

DocViewer::DocViewer(IChildViewer* childviewer) : m_IChildViewer(childviewer)
{
    setStyleSheet("background-color:gray;");

    int nNumCount = m_IChildViewer->getNumCount();
    QSize size = m_IChildViewer->getActruallyPageSize(0);

    this->resize(size.width(), size.height() * nNumCount);

    m_pscrollarea = m_IChildViewer->getScrollArea();
    m_pscrollarea->setBackgroundRole(QPalette::Dark);
    m_pscrollarea->setWidget(this);

}

DocViewer::~DocViewer()
{

}


void DocViewer::paintEvent(QPaintEvent *e)
{
    QPainter* painter = new QPainter(this);

    QSize size = m_IChildViewer->getActruallyPageSize(0);
    QImage imag = m_IChildViewer->getActruallyPageImage(0);


    QImage image1 = m_IChildViewer->getActruallyPageImage(0);
    painter->drawImage(0,0,image1);

    QImage image2 = m_IChildViewer->getActruallyPageImage(1);
    painter->drawImage(0, size.height(), image2);

}


