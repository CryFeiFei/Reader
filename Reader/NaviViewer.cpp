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
    m_ThumbnailWidget = new QWidget();
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
    m_tabWidget->addTab(m_OutlineWidget,"utitle");
    m_tabWidget->addTab(m_ThumbnailWidget,"utitle");
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

    QDomNode domroot = domdoc->firstChild();

    QString strDom;

    while (!domroot.isNull())
    {
        strDom = domroot.toElement().tagName();
        domroot = domroot.firstChild();
    }
}

void NaviViewer::sl_btnClicked()
{

}
