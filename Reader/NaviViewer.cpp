#include "NaviViewer.h"

TocTreeItem::TocTreeItem(QString des, TocTreeItem* parentItem)
{
	m_description = des;
	m_parentItem = parentItem;
	m_childList.clear();
	qDeleteAll(m_childList);
}

TocTreeItem::~TocTreeItem()
{
	qDeleteAll(m_childList);
}

void TocTreeItem::appendChild(TocTreeItem *child)
{
	m_childList.append(child);
}

TocTreeItem* TocTreeItem::child(int row)
{
	return m_childList.value(row);
}

int TocTreeItem::childCount() const
{
	return m_childList.count() > 0 ? m_childList.count() : 0;
}

int TocTreeItem::columnCount() const
{
	return 1;
}

QString TocTreeItem::getDescription(int column) const
{
	return m_description;
}

int TocTreeItem::row() const
{
	if (m_parentItem)
		return m_parentItem->m_childList.indexOf(const_cast<TocTreeItem*>(this));

	return 0;
}
TocTreeItem* TocTreeItem::parentItem()
{
	return m_parentItem;
}

//==================================================================================

TocTreeModel::TocTreeModel(QDomDocument* domdoc, QObject *parent)
{
//	QDomDocument* domdoc = m_IChildViewer->getTOC();
	if (domdoc == NULL)
		return;

	QDomNode domNode = domdoc->firstChild();
	rootItem = new TocTreeItem("domNode.toElement().tagName()");
    TocTreeItem* treeItem;
    for(QDomNode childNode = domNode; !childNode.isNull(); childNode = childNode.nextSibling())
    {
        QString strDom = childNode.toElement().tagName();
        treeItem = new TocTreeItem(strDom, rootItem);
        rootItem->appendChild(treeItem);
        parserDom(&domNode, treeItem);
    }
//    parserDom(&domNode, treeItem);
}

TocTreeModel::~TocTreeModel()
{
	delete rootItem;
}

void TocTreeModel::parserDom(QDomNode* domNode, TocTreeItem* parentItem)
{
	TocTreeItem* treeItem = NULL;
	QString strDom;
    for(QDomNode childNode = domNode->firstChild(); !childNode.isNull(); childNode = childNode.nextSibling())
	{
		strDom = childNode.toElement().tagName();
		treeItem = new TocTreeItem(strDom, parentItem);
		parentItem->appendChild(treeItem);
		parserDom(&childNode, treeItem);
	}

}

int TocTreeModel::columnCount(const QModelIndex &parent) const
{
	if (parent.isValid())
		return static_cast<TocTreeItem*>(parent.internalPointer())->columnCount();
	else
		return rootItem->columnCount();
}

int TocTreeModel::rowCount(const QModelIndex &parent) const
{
	TocTreeItem *parentItem;
	if (parent.column() > 0)
		return 0;

	if (!parent.isValid())
		parentItem = rootItem;
	else
		parentItem = static_cast<TocTreeItem*>(parent.internalPointer());

	return parentItem->childCount();
}

QVariant TocTreeModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (role != Qt::DisplayRole)
		return QVariant();

	TocTreeItem *item = static_cast<TocTreeItem*>(index.internalPointer());

//	return item->data(index.column());
	return QVariant(item->getDescription(index.column()));
}

Qt::ItemFlags TocTreeModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;

	return QAbstractItemModel::flags(index);
}

QVariant TocTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	return QVariant();
}

QModelIndex TocTreeModel::index(int row, int column, const QModelIndex &parent) const
{
	if (!hasIndex(row, column, parent))
		return QModelIndex();

	TocTreeItem *parentItem;

	if (!parent.isValid())
		parentItem = rootItem;
	else
		parentItem = static_cast<TocTreeItem*>(parent.internalPointer());

	TocTreeItem *childItem = parentItem->child(row);
	if (childItem)
		return createIndex(row, column, childItem);
	else
		return QModelIndex();
}

QModelIndex TocTreeModel::parent(const QModelIndex &index) const
{
	if (!index.isValid())
		return QModelIndex();

	TocTreeItem *childItem = static_cast<TocTreeItem*>(index.internalPointer());
	TocTreeItem *parentItem = childItem->parentItem();

	if (parentItem == rootItem)
		return QModelIndex();

	return createIndex(parentItem->row(), 0, parentItem);
}

NaviViewer::NaviViewer(IChildViewer* childviewer) : m_IChildViewer(childviewer), m_OutlineTree(NULL)
{
	InitUI();
	InitTOC();
	InitConnect();
}

void NaviViewer::InitUI()
{
    //new project
	m_OutlineWidget = new QWidget();
	m_OutlineLayout = new QVBoxLayout();
	m_OutlineWidget->setLayout(m_OutlineLayout);


	m_ThumbnailWidget = new ThumbnailWidget(m_IChildViewer);

	m_SemanticTree = new QWidget();


	m_tabWidget = new QTabWidget();
	m_tabWidget->setTabPosition(QTabWidget::West);
	m_tabWidget->addTab(m_OutlineWidget,"333");
	m_tabWidget->addTab(m_ThumbnailWidget, "123");
	m_tabWidget->addTab(m_SemanticTree,"utitle");

	//垂直分割的布局
	QVBoxLayout* naVLayout = new QVBoxLayout();
	naVLayout->addWidget(m_tabWidget);

	this->setLayout(naVLayout);
}

void NaviViewer::InitTOC()
{
	QDomDocument* domdoc = m_IChildViewer->getTOC();
	if (domdoc == NULL)
		return;

//	TocTreeModel* treeModel = new TocTreeModel(domdoc, NULL);

//	QDomNode domNode = domdoc->firstChild();
//	QTreeWidgetItem* treeWidgetItem = NULL;

	m_OutlineTree = new QTreeWidget();
//	m_OutlineLayout->addWidget(m_OutlineTree);
//	m_OutlineTree->setHeaderLabel(tr("图像选择"));
//	m_OutlineTree->setHeaderHidden(true);
//	m_OutlineTree->setStyleSheet( "QTreeView::item:hover{background-color:rgb(0,255,0,50)}"
//							   "QTreeView::item:selected{background-color:rgb(255,0,0,100)}");


//	m_OutlineTree->setModel(treeModel);
//	treeWidgetItem = new QTreeWidgetItem(m_OutlineTree, QStringList(QString(domNode.toElement().tagName())));
//	ComputerToc(&domNode, treeWidgetItem);

	QTreeView* treeView = new QTreeView();
	TocTreeModel* treeModel = new TocTreeModel(domdoc);
	treeView->setModel(treeModel);
	m_OutlineLayout->addWidget(treeView);

//	m_OutlineTree->expandAll();
//	m_OutlineTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void NaviViewer::InitConnect()
{
	if (m_OutlineTree)
		connect(m_OutlineTree, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(outLineTreeClicked(QTreeWidgetItem*,int)));
}

void NaviViewer::ComputerToc(QDomNode* domNode, QTreeWidgetItem* parentWidgetItem)
{
	QTreeWidgetItem* treeWidgetItem = NULL;
	QString strDom;
	for(QDomNode childNode = domNode->firstChild(); !childNode.isNull(); childNode = childNode.nextSibling())
	{
		strDom = childNode.toElement().tagName();
		treeWidgetItem = new QTreeWidgetItem(parentWidgetItem, QStringList(strDom));
		ComputerToc(&childNode, treeWidgetItem);
	}

}

void NaviViewer::sl_btnClicked()
{

}

void NaviViewer::outLineTreeClicked(QTreeWidgetItem* item, int n)
{

}
