#include<mdichild.h>

MdiChild::MdiChild()
{
    setAttribute(Qt::WA_DeleteOnClose);//为了使关闭窗口时都关闭


    m_splitterMain = new QSplitter(Qt::Horizontal, this); //水平分割
  //  m_splitterMain->addWidget(m_navigationBar);
    m_navigationBar = new NavigationWidget(m_splitterMain);
    QTextEdit *textRight = new QTextEdit(QObject::tr("右部件"),m_splitterMain);
    textRight->setAlignment(Qt::AlignCenter);

    m_splitterMain->setStretchFactor(0,4);
    m_splitterMain->setStretchFactor(1,6);

    m_splitterMain->setAutoFillBackground(true);

    m_splitterMain->setWindowTitle(QObject::tr("分割窗口"));
    m_splitterMain->show();


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
