#include "navigationwidget.h"

NavigationWidget::NavigationWidget(QSplitter* parent): m_splitterMain(parent)
{
    m_OutlineWidget = new QWidget();
    m_ThumbnailWidget = new QWidget();
    m_SemanticTree = new QWidget();
    this->setParent(m_splitterMain);
 //   m_navigationBar = new (m_splitterMain);
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

}
