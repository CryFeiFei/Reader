#include "NaviViewer.h"

NaviViewer::NaviViewer(IChildViewer* childviewer) : m_IChildViewer(childviewer)
{
	InitUI();
	InitTOC();
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
	m_tabWidget->addTab(m_OutlineWidget,"目录");
	m_tabWidget->addTab(m_ThumbnailWidget,"缩略图");
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

	QDomNode domNode = domdoc->firstChild();
	QTreeWidgetItem* treeWidgetItem = NULL;

	m_OutlineTree = new QTreeWidget();
	m_OutlineLayout->addWidget(m_OutlineTree);
	m_OutlineTree->setHeaderLabel(tr("图像选择"));
	m_OutlineTree->setHeaderHidden(true);

	treeWidgetItem = new QTreeWidgetItem(m_OutlineTree, QStringList(QString(domNode.toElement().tagName())));
	ComputerToc(&domNode, treeWidgetItem);

	m_OutlineTree->expandAll();
//	m_OutlineTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
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
