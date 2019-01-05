#include "kribbontabwidget.h"
#include <QTabBar>
#include <QScrollArea>
#include <QStyleOptionComplex>
#include <QPainter>
#include <QStylePainter>

const int ARROWSIZE = 15;

KRbScrollArrow::KRbScrollArrow(QWidget* parent) :
	QAbstractButton (parent)
{
	setAutoRepeat(true);
	setFocusPolicy(Qt::NoFocus);
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	setFixedWidth(ARROWSIZE);
}

void KRbScrollArrow::enterEvent(QEvent* event)
{
	QWidget::enterEvent(event);
}

void KRbScrollArrow::leaveEvent(QEvent* event)
{
	QWidget::leaveEvent(event);
}

void KRbScrollArrow::paintEvent(QPaintEvent* event)
{
	QStyleOptionComplex option;
	option.initFrom(this);

	if (isChecked())
		option.state |= QStyle::State_On;
	if (isDown())
		option.state |= QStyle::State_Sunken;
	if (!isChecked() && !isDown())
		option.state |= QStyle::State_Raised;

	option.state |= QStyle::State_AutoRaise;

	QPainter pp(this);
	QStylePainter painter(this);
	painter.drawComplexControl(QStyle::CC_ToolButton, option);
}

/////////////////////////////////////////////////////////////////////

KRibbonScrollWidget::KRibbonScrollWidget(QWidget* parent) :
	QWidget (parent)
{

}

void KRibbonScrollWidget::resizeEvent(QResizeEvent* event)
{
	QWidget::resizeEvent(event);
}

///////////////////////////////////////////////////////////////

KRibbonTabWidget::KRibbonTabWidget(QWidget *parent) : QTabWidget(parent)
{
	m_tabBar = this->tabBar();
//	m_tabBar-
//	this->addTab()
}
