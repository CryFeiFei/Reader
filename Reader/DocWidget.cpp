#include "DocWidget.h"

DocWidget::DocWidget(IChildViewer* childviewer):m_IChildViewer(childviewer)
{
    setStyleSheet("background-color:red;");

    m_pScrollArea = new QScrollArea(this);
    m_pDocViewer = new DocViewer(this);
    m_pScrollArea->setWidget(m_pDocViewer);

}

DocWidget::~DocWidget()
{

}
