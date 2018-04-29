#include "ThumbnailWidget.h"

ThumbnailWidget::ThumbnailWidget(IChildViewer* childViewer):m_IChildViewer(childViewer),m_nCurThumDrawPageNum(0),m_nPageCount(0)
{
	m_nTimerIdle = startTimer(0);
	m_vBoxlayout = new QVBoxLayout(this);
	m_listView = new QListView();
	m_listView->setViewMode(QListView::IconMode);
	m_listView->setSpacing(10);
	m_listView->setIconSize(QSize(150,300));
	m_listView->setModelColumn(1);
	m_listView->setMovement(QListView::Static);
	m_listView->setResizeMode(QListView::Adjust);
	m_ItemModel = new QStandardItemModel();
	m_listView->setModel(m_ItemModel);
	m_vBoxlayout->addWidget(m_listView);
	m_vBoxlayout->setContentsMargins(1,1,1,1);

	m_nPageCount = m_IChildViewer->getPageCount();

}

ThumbnailWidget::~ThumbnailWidget()
{

}

//待优化，不能一下画这么多啊！
void ThumbnailWidget::timerEvent(QTimerEvent *)
{
	if (m_nCurThumDrawPageNum >= m_nPageCount)
		return;

	QImage img;
	img = m_IChildViewer->getActruallyPageImage(m_nCurThumDrawPageNum);
	QPixmap pixmap;
	pixmap = QPixmap::fromImage(img);

	QString strPageNum = QString::number(m_nCurThumDrawPageNum + 1);
	QStandardItem* item = new QStandardItem(QIcon(pixmap), strPageNum);
	m_ItemModel->appendRow(item);
	m_nCurThumDrawPageNum++;
//    m_listView->setModel(m_ItemModel);

}

