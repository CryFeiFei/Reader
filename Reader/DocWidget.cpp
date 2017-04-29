#include "DocWidget.h"

DocWidget::DocWidget(IChildViewer* childviewer):m_IChildViewer(childviewer)
{
    setStyleSheet("background-color:red;");
    m_pScrollArea = new QScrollArea(this);
    m_pDocViewer = new DocViewer(NULL);

}

DocWidget::~DocWidget()
{

}
