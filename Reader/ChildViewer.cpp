#include<ChildViewer.h>

ChildViewer::ChildViewer()
{
    // 为了使关闭窗口时都关闭
    setAttribute(Qt::WA_DeleteOnClose);
    // 水平分割
    m_splitterMain = new QSplitter(Qt::Horizontal, this);

    QWidget *textRight =  new QWidget();
    textRight->setStyleSheet("background-color:gray;");
    m_navigationBar = new NaviViewer();

    m_splitterMain->addWidget(m_navigationBar);
    m_splitterMain->addWidget(textRight);
    m_splitterMain->setStretchFactor(0,0);
    m_splitterMain->setStretchFactor(1,1);
    m_splitterMain->setAutoFillBackground(true);
    m_splitterMain->setWindowTitle(QObject::tr("分割窗口"));
    m_splitterMain->show();

}

void ChildViewer::resizeEvent(QResizeEvent *event)
{
    m_splitterMain->resize(this->size());
}

void ChildViewer::CreatNavigationBar()
{

}

ChildViewer::~ChildViewer()
{

}

void ChildViewer::InitOutline()
{

}

void ChildViewer::InitThumbnail()
{

}

void ChildViewer::InitSemantic()
{

}
