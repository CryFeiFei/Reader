#include "kcommand.h"

kcommand::kcommand(QObject* host, QObject *parent) : QObject(parent)
, m_host (host)
{

}

QString kcommand::text() const
{
	return m_text;
}

void kcommand::setText(const QString& text)
{
	m_text = text;
}

bool kcommand::visible() const
{
	return  m_visible;
}

void kcommand::setVisible(bool visible)
{
	m_visible = visible;
}
