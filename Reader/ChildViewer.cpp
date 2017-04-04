#include "ChildViewer.h"

ChildViewer::ChildViewer(IMainViewer* iMainViewer) : m_IMainViewer(iMainViewer)
{
    // 为了使关闭窗口时都关闭
    setAttribute(Qt::WA_DeleteOnClose);
    m_strFileName = m_IMainViewer->getFileName();

    // 水平分割
    m_splitterMain = new QSplitter(Qt::Horizontal, this);
    m_pscrollarea = new QScrollArea(this);

    m_ViewModel = new ViewModel(this);


    // 绘制主界面
    m_DocViewer =  new DocViewer(this);
    // 左边工具栏
    m_navigationBar = new NaviViewer();






    m_splitterMain->addWidget(m_navigationBar);
    m_splitterMain->addWidget(m_pscrollarea);

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
