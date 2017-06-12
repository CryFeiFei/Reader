#ifndef THUMBNAILWIDGET_H
#define THUMBNAILWIDGET_H

#include "ReadDefine.h"
#include "IChildViewer.h"
#include <QStandardItem>

class ThumbnailWidget : public QWidget
{
	Q_OBJECT
public:
	ThumbnailWidget(IChildViewer* childviewer);
	~ThumbnailWidget();

private:
	IChildViewer* m_IChildViewer;
	QVBoxLayout*  m_vBoxlayout;

	int	 m_nTimerIdle;
	QListView*	m_listView;
	QStandardItemModel* m_ItemModel;
	int m_nCurThumDrawPageNum; //控制缩略图绘制多少页的
	int m_nPageCount;

private:
	void timerEvent(QTimerEvent*);
};

#endif // THUMBNAILWIDGET_H
