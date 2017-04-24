#include "DocViewer.h"

DocViewer::DocViewer(IChildViewer* childviewer) : m_IChildViewer(childviewer)
{
    setStyleSheet("background-color:gray;");

    int nNumCount = m_IChildViewer->getNumCount();
    QSize size = m_IChildViewer->getActruallyPageSize(0);

    this->resize(size.width(), size.height() * nNumCount + 8 * nNumCount);

    m_pscrollarea = m_IChildViewer->getScrollArea();
    m_pscrollarea->setBackgroundRole(QPalette::Dark);
    m_pscrollarea->setWidget(this);

    QScrollBar* pScrollBar = m_pscrollarea->verticalScrollBar();
//    pScrollBar->setFixedHeight(size.height() * nNumCount);
    pScrollBar->setMaximum(size.height() * nNumCount);
    pScrollBar->setSingleStep(8);


}

DocViewer::~DocViewer()
{

}


void DocViewer::paintEvent(QPaintEvent *e)
{
    QPainter* painter = new QPainter(this);

    m_IChildViewer->RenderPages(painter);

}


