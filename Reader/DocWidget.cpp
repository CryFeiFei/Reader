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
//	m_pDocViewer->resize(this->size().width() + m_pScrollBar->width(), m_IChildViewer->getPageHighCount());
//	m_pDocViewer->resize(m_IChildViewer->getMaxPageWidth(), m_IChildViewer->getPageHighCount());
//	QVBoxLayout* scrollLayout = new QVBoxLayout();
//	scrollLayout->addWidget(m_pDocViewer);

//	m_pScrollArea->setLayout(scrollLayout);
//	m_pScrollArea->setMinimumHeight();
	m_pScrollArea->setAlignment(Qt::AlignCenter);

//	m_pScrollArea->setMinimumWidth(m_IChildViewer->getMaxPageWidth());

}

DocWidget::~DocWidget()
{

}

void DocWidget::resizeEvent(QResizeEvent* e)
{
//	m_pScrollArea->resize(this->size());
//	m_pScrollArea->size.width();
//	m_pScrollArea->size().
	if (m_IChildViewer->getMaxPageWidth() > m_pScrollArea->size().width())
		m_pDocViewer->resize(m_IChildViewer->getMaxPageWidth() + m_pScrollBar->size().width(), m_IChildViewer->getPageHighCount());
	else
		m_pDocViewer->resize(m_pScrollArea->size().width() - m_pScrollBar->size().width(), m_IChildViewer->getPageHighCount());
}

void DocWidget::RefreshWindow()
{
	update();
	if (m_IChildViewer->getMaxPageWidth() > m_pScrollArea->size().width())
		m_pDocViewer->resize(m_IChildViewer->getMaxPageWidth() + m_pScrollBar->size().width(), m_IChildViewer->getPageHighCount());
	else
		m_pDocViewer->resize(m_pScrollArea->size().width() - m_pScrollBar->size().width(), m_IChildViewer->getPageHighCount());
//	m_pDocViewer->resize(m_IChildViewer->getMaxPageWidth(), m_IChildViewer->getPageHighCount());
}

