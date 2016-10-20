#include<mdichild.h>

MdiChild::MdiChild()
{
    setAttribute(Qt::WA_DeleteOnClose);//为了使关闭窗口时都关闭

    m_OutlineWidget = new QWidget();
    m_ThumbnailWidget = new QWidget();
    m_SemanticTree = new QWidget();

    m_splitterMain = new QSplitter(Qt::Horizontal, this); //水平分割

    m_navigationBar = new QWidget();

    m_tabWidget = new QTabWidget(m_splitterMain);
    m_tabWidget->setTabPosition(QTabWidget::West);
    m_tabWidget->addTab(m_OutlineWidget,"utitle");
    m_tabWidget->addTab(m_ThumbnailWidget,"utitle");
    m_tabWidget->addTab(m_SemanticTree,"utitle");

    


//    QTextEdit *textLeft = new QTextEdit(QObject::tr("左部件"), splitterMain);
//    textLeft->setAlignment(Qt::AlignCenter);

    QTextEdit *textRight = new QTextEdit(QObject::tr("右部件"),m_splitterMain);
    textRight->setAlignment(Qt::AlignCenter);

//    QSplitter *splitterRight = new QSplitter(Qt::Vertical, splitterMain);   //右分割窗口，并以主分割窗口作为父窗口
//    splitterRight->setOpaqueResize(false);

//    QTextEdit *textUp = new QTextEdit(QObject::tr("上部件"),splitterRight);
//    textUp->setAlignment(Qt::AlignCenter);

//    QTextEdit *textMiddle = new QTextEdit(QObject::tr("中间部件"),splitterRight);
//    textMiddle->setAlignment(Qt::AlignCenter);

//    QTextEdit *textBottom = new QTextEdit(QObject::tr("底部部件"),splitterRight);
//    textBottom->setAlignment(Qt::AlignCenter);

    m_splitterMain->setStretchFactor(1,1);
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
