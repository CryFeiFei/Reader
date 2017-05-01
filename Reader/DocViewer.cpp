#include "DocViewer.h"

DocViewer::DocViewer(IDocWidget* DocWidget) : m_IDocWidget(DocWidget)
{
    setStyleSheet("background-color:gray;");
}

DocViewer::~DocViewer()
{

}


void DocViewer::paintEvent(QPaintEvent *e)
{
    QPainter* painter = new QPainter(this);

    m_IDocWidget->RenderPages(painter);

}


