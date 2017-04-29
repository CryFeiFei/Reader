#include "DocViewer.h"

DocViewer::DocViewer(IChildViewer* childviewer) : m_IChildViewer(childviewer)
{
    setStyleSheet("background-color:gray;");

    m_pscrollarea = new QScrollArea();
 //   m_pscrollarea->setWidget(this);
    m_pscrollarea->setBackgroundRole(QPalette::Dark);

    int nNumCount = m_IChildViewer->getNumCount();
    QSize size = m_IChildViewer->getActruallyPageSize(0);

    this->resize(size.width(), size.height() * nNumCount + 8 * nNumCount);

//    m_pscrollarea = new QScrollArea(this);
//    m_pscrollarea->setBackgroundRole(QPalette::Dark);
    //m_pscrollarea->setWidgetResizable(true);


}

DocViewer::~DocViewer()
{

}


void DocViewer::paintEvent(QPaintEvent *e)
{
    QPainter* painter = new QPainter(this);

    m_IChildViewer->RenderPages(painter);

}


