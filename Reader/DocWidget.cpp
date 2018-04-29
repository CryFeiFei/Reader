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
	m_pScrollArea->setAlignment(Qt::AlignCenter);
}

DocWidget::~DocWidget()
{

}

//感觉没有啥好方法，让qscroll自动适配页面大小。只能这样做了。
void DocWidget::resizeEvent(QResizeEvent* e)
{
	_resize();
}

void DocWidget::RefreshWindow()
{
	update();
	_resize();
}

void DocWidget::_resize()
{
	//上边的逻辑是窗口小于页面大小时做的处理。得加上一个滚动条的大小，这样页面会比较好看。
	if (m_IChildViewer->getMaxPageWidth() > m_pScrollArea->size().width())
		m_pDocViewer->resize(m_IChildViewer->getMaxPageWidth() + m_pScrollBar->size().width(), m_IChildViewer->getPageHighCount());
	else
		m_pDocViewer->resize(m_pScrollArea->size().width() - m_pScrollBar->size().width(), m_IChildViewer->getPageHighCount());
}

