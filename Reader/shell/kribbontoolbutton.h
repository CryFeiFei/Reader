#ifndef KRIBBONTOOLBUTTON_H
#define KRIBBONTOOLBUTTON_H

#include <QWidget>
class QPixmap;

//-------------------------------------------------------
class KRibbonToolIcon : public QWidget
{
	Q_OBJECT
public:
	using QWidget::QWidget;
	void setIcon(QPixmap pixmap);

public:
	void paintEvent(QPaintEvent* event) override;
	QSize sizeHint() const override;

private:
	QPixmap m_icon;
};
//KRibbonToolIcon

//-----------------------------------------------
class KRibbonToolText : public QWidget
{
	Q_OBJECT
public:
	using QWidget::QWidget;

public:
	void setText(QString );
	QSize sizeHint() const override;
	void paintEvent(QPaintEvent* event) override;

signals:

public slots:

private:
	QString m_text;
};
//KRibbonToolText

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
