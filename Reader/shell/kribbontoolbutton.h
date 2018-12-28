#ifndef KRIBBONTOOLBUTTON_H
#define KRIBBONTOOLBUTTON_H

#include <QWidget>
class QPixmap;

class KRibbonToolButton : public QWidget
{
	Q_OBJECT
public:
	KRibbonToolButton(QWidget *parent = nullptr);

signals:

public slots:

private:
	void _init();

private:
	QWidget* m_textWidget;
	QWidget* m_Icon;
};

#endif // KRIBBONTOOLBUTTON_H
