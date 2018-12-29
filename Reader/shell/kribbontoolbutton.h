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
	Q_PROPERTY(QString text READ text WRITE setText)
	Q_PROPERTY(QPixmap pixmap READ icon WRITE setIcon)
public:
	KRibbonToolButton(QWidget *parent = nullptr);

public:
	QString text();
	void setText(QString text);
	QPixmap icon();
	void setIcon(QPixmap pixmap);

signals:

public slots:

private:
	void _init();

private:
	QString m_text;
	QPixmap m_pixmap;

	KRibbonToolText* m_textWidget;
	KRibbonToolIcon* m_IconWidget;
};

#endif // KRIBBONTOOLBUTTON_H
