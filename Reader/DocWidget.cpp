#include "DocWidget.h"
#include <QVBoxLayout>

DocWidget::DocWidget(IChildViewer* childviewer):m_IChildViewer(childviewer)
{
	setStyleSheet("background-color:gray");

	m_pScrollArea = new QScrollArea();
	m_pDocViewer = new DocViewer(this);
	m_pScrollArea->setWidget(m_pDocViewer);

	QVBoxLayout* layout = new QVBoxLayout();
	setLayout(layout);
	layout->addWidget(m_pScrollArea);

	m_pScrollBar = m_pScrollArea->verticalScrollBar();

}

DocWidget::~DocWidget()
{

}

void DocWidget::resizeEvent(QResizeEvent* e)
{
//	m_pScrollArea->resize(this->size());
	m_pDocViewer->resize(this->size().width(), m_IChildViewer->getPageHighCount());
}

void DocWidget::RefreshWindow()
{
	update();
//	m_pDocViewer->resize(this->size().width(), m_IChildViewer->getPageHighCount());
}

