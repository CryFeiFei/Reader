#include "kribbonwidget.h"
#include <QVBoxLayout>

KRibbonWidget::KRibbonWidget(QWidget* parent) :
	QWidget (parent)
{
	setObjectName("KRibbonWidget");

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);





}
