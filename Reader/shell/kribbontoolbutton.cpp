#include "kribbontoolbutton.h"

#include <QVBoxLayout>

KRibbonToolButton::KRibbonToolButton(QWidget *parent) : QWidget(parent)
	, m_toolIcon(nullptr)
	, m_textWidget(nullptr)
{
	setObjectName("KRibbonToolButton");
	_init();
}

void KRibbonToolButton::_init()
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);

}
