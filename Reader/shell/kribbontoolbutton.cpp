#include "kribbontoolbutton.h"

#include <QVBoxLayout>

KRibbonToolButton::KRibbonToolButton(QWidget *parent) : QWidget(parent)
	, m_text(nullptr)
	, m_Icon(nullptr)
{
	setObjectName("KRibbonToolButton");
	_init();
}

void KRibbonToolButton::_init()
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);

}
