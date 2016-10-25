#include<mdichild.h>

MdiChild::MdiChild()
{
    setAttribute(Qt::WA_DeleteOnClose);//为了使关闭窗口时都关闭

    m_OutlineWidget = new QWidget();
    m_ThumbnailWidget = new QWidget();
    m_SemanticTree = new QWidget();


    m_splitterMain = new QSplitter(Qt::Horizontal, this); //水平分割

    m_navigationBar = new QWidget(m_splitterMain);
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

    m_navigationBar->setLayout(naVLayout);


    QTextEdit *textRight = new QTextEdit(QObject::tr("右部件"),m_splitterMain);
    textRight->setAlignment(Qt::AlignCenter);


    m_splitterMain->setStretchFactor(2,6);

    m_splitterMain->setAutoFillBackground(true);

    m_splitterMain->setWindowTitle(QObject::tr("分割窗口"));
    m_splitterMain->show();
//    splitterMain->show();


}

void MdiChild::resizeEvent(QResizeEvent *event)
{
    m_splitterMain->resize(this->size());

}

void MdiChild::CreatNavigationBar()
{

}

MdiChild::~MdiChild()
{

}

void MdiChild::InitOutline()
{

}

void MdiChild::InitThumbnail()
{

}

void MdiChild::InitSemantic()
{

}
