#include "kribbontooltext.h"
#include <QFontMetrics>
#include <QPainter>

const int DRAW_TEXT_EXTEND = 6;

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
	return QSize(rect.width() + DRAW_TEXT_EXTEND, 20);
}

void KRibbonToolText::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.drawText(rect(), Qt::AlignCenter, m_text);
}
