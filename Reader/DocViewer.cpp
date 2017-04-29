#include "DocViewer.h"

DocViewer::DocViewer(IDocWidget* DocWidget) : m_IDocWidget(DocWidget)
{
    setStyleSheet("background-color:gray;");

    int nNumCount = m_IDocWidget->getNumCount();
    QSize size = m_IDocWidget->getActruallyPageSize(0);

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

    m_IDocWidget->RenderPages(painter);

}


