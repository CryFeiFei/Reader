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

void DocWidget::resizeEvent(QResizeEvent* e)
{
    m_pScrollArea->resize(this->size());
    m_pDocViewer->resize(this->size().width(), m_IChildViewer->getPageHighCount());
}

void DocWidget::RefreshWindow()
{
    update();
    m_pDocViewer->resize(this->size().width(), m_IChildViewer->getPageHighCount());
}
