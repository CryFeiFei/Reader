#ifndef KRIBBONTABWIDGET_H
#define KRIBBONTABWIDGET_H

#include <QTabWidget>

#include <QObject>

class KRibbonScrollWidget : QWidget
{
	Q_OBJECT
public:
	KRibbonScrollWidget(QWidget* parent = nullptr);

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
