// summary : 多文档区域

#ifndef MULTIVIEWER_H
#define MULTIVIEWER_H

#include <QMdiArea>
#include <QWidget>

class MultiViwer:public QMdiArea
{
public:
	explicit MultiViwer(QWidget* parent);
	MultiViwer(){}
	~MultiViwer();
};

#endif // MULTIVIEWER_H
