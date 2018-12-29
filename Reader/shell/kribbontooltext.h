#ifndef KRIBBONTOOLTEXT_H
#define KRIBBONTOOLTEXT_H

#include <QWidget>

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

#endif // KRIBBONTOOLTEXT_H
