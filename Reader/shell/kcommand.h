// command means
#ifndef KCOMMAND_H
#define KCOMMAND_H

#include <QObject>
#include <QString>

class kcommand : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString text READ text WRITE setText)
	Q_PROPERTY(QString text MEMBER m_text NOTIFY textChange)
	Q_PROPERTY(bool visible READ visible WRITE setVisible)
	Q_PROPERTY(bool visible MEMBER m_visible NOTIFY visibleChange)
public:
	explicit kcommand(QObject *parent = nullptr);

public:
	QString text() const;
	void setText(const QString& text);

	bool visible() const;
	void setVisible(bool visible);


signals:
	void textChange();
	void visibleChange();

public slots:

private:
	QString m_text;
	bool m_visible;
};

#endif // KCOMMAND_H
