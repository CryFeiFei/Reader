#include "kribbontabwidget.h"
#include <QTabBar>

KRibbonScrollWidget::KRibbonScrollWidget(QWidget* parent) :
	QWidget (parent)
{

}

///////////////////////////////////////////////////////////////

KRibbonTabWidget::KRibbonTabWidget(QWidget *parent) : QTabWidget(parent)
{
	m_tabBar = this->tabBar();
//	m_tabBar-
//	this->addTab()
}
