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
	m_ThumbnailLayout = new QVBoxLayout();
	m_ThumbnailWidget->setLayout(m_ThumbnailLayout);

    m_SemanticTree = new QWidget();
    m_topNBWidget = new QWidget();
    //上边水平布局
    QHBoxLayout* NBTopLayout = new QHBoxLayout();
    QPushButton* btn_ok = new QPushButton(QWidget::tr("OK"), m_topNBWidget);
    btn_ok->setDefault(true);
    btn_ok->setFixedSize(10,10);
    QPushButton* btn_cancel = new QPushButton(QWidget::tr("Cancel"), m_topNBWidget);
    btn_cancel->setFixedSize(10,10);
    NBTopLayout->addWidget(btn_ok, Qt::AlignLeft);
    NBTopLayout->addStretch();
    NBTopLayout->addWidget(btn_cancel, Qt::AlignRight);

    m_tabWidget = new QTabWidget();
    m_tabWidget->setTabPosition(QTabWidget::West);
	m_tabWidget->addTab(m_OutlineWidget,"目录");
	m_tabWidget->addTab(m_ThumbnailWidget,"缩略图");
    m_tabWidget->addTab(m_SemanticTree,"utitle");

    //垂直分割的布局
    QVBoxLayout* naVLayout = new QVBoxLayout();
    naVLayout->addLayout(NBTopLayout);
    naVLayout->addWidget(m_tabWidget);

    this->setLayout(naVLayout);
    connect(btn_cancel,SIGNAL(clicked()),this,SLOT(sl_btnClicked()));

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
//	m_OutlineTree->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

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
