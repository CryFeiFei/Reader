#include "kribbontoolbutton.h"

#include <QVBoxLayout>
#include <QPainter>

//--------------------------------------------------
void KRibbonToolIcon::setIcon(QPixmap pixmap)
{
	m_icon = pixmap;
}

QSize KRibbonToolIcon::sizeHint() const
{
	return QSize(50, 50);
}

void KRibbonToolIcon::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.drawPixmap(rect(), m_icon);
}

//----------------------------------------------------
void KRibbonToolText::setText(QString text)
{
	if (m_text == text)
		return;

	m_text = text;
}

QSize KRibbonToolText::sizeHint() const
{
	QFontMetrics fm(font());
	QRect rect = fm.boundingRect(m_text);
	return QSize(50, 20);
}

void KRibbonToolText::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.drawText(rect(), Qt::AlignCenter, m_text);
}
//----------------------------------------------------------

KRibbonToolButton::KRibbonToolButton(QWidget *parent) : QWidget(parent)
	, m_textWidget(nullptr)
	, m_IconWidget(nullptr)
{
	setObjectName("KRibbonToolButton");
	_init();
}

QString KRibbonToolButton::text()
{
	return m_text;
}

void KRibbonToolButton::setText(QString text)
{
	m_text = text;
}

QPixmap KRibbonToolButton::icon()
{
	return m_pixmap;
}

void KRibbonToolButton::setIcon(QPixmap pixmap)
{
	m_pixmap = pixmap;
}


void KRibbonToolButton::_init()
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	//m_text->setText()
	//
}
