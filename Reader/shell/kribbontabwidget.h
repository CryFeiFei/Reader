#ifndef KRIBBONTABWIDGET_H
#define KRIBBONTABWIDGET_H

#include <QTabWidget>
#include <QObject>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgWidget>
#include <QAbstractButton>

class QScrollArea;

class KRbScrollArrow : public QAbstractButton
{
	Q_OBJECT
public:
	KRbScrollArrow(QWidget* parent = nullptr);

public:
	virtual void enterEvent(QEvent* event) override;
	virtual void leaveEvent(QEvent* event) override;
	virtual void paintEvent(QPaintEvent* event) override;
};

class KRibbonScrollWidget : public QWidget
{
	Q_OBJECT
public:
	KRibbonScrollWidget(QWidget* parent = nullptr);

public:
	virtual void resizeEvent(QResizeEvent *event) override;

private:
	KRbScrollArrow* m_leftArrow;
	KRbScrollArrow* m_rightArrow;
	QScrollArea* m_scrollArea;
	QWidget* m_centerWidget;
};

class KRibbonTabWidget : public QTabWidget
{
	Q_OBJECT
public:
	explicit KRibbonTabWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
	QTabBar* m_tabBar;
};

#endif // KRIBBONTABWIDGET_H
