#ifndef KRIBBONTOOLBUTTON_H
#define KRIBBONTOOLBUTTON_H

#include <QWidget>
class QPixmap;
class KRibbonToolIcon;
class KRibbonToolText;

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
	KRibbonToolText* m_text;
	KRibbonToolIcon* m_Icon;
};

#endif // KRIBBONTOOLBUTTON_H
