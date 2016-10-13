#include<mdichild.h>

MdiChild::MdiChild()
{
    setAttribute(Qt::WA_DeleteOnClose);
//    setSizePolicy(QSizePolicy::Policy::Expanding,QSizePolicy::Policy::Expanding);
    splitterMain = new QSplitter(Qt::Horizontal, this);
//    splitterMain->resize(this->size());
    QTabWidget *tab = new QTabWidget(splitterMain);
    tab->setTabPosition(QTabWidget::West);
    tab->addTab(new QWidget,"utitle");
    tab->addTab(new QWidget,"utitle");


//    QTextEdit *textLeft = new QTextEdit(QObject::tr("左部件"), splitterMain);
//    textLeft->setAlignment(Qt::AlignCenter);

    QTextEdit *textRight = new QTextEdit(QObject::tr("右部件"),splitterMain);
    textRight->setAlignment(Qt::AlignCenter);

//    QSplitter *splitterRight = new QSplitter(Qt::Vertical, splitterMain);   //右分割窗口，并以主分割窗口作为父窗口
//    splitterRight->setOpaqueResize(false);

//    QTextEdit *textUp = new QTextEdit(QObject::tr("上部件"),splitterRight);
//    textUp->setAlignment(Qt::AlignCenter);

//    QTextEdit *textMiddle = new QTextEdit(QObject::tr("中间部件"),splitterRight);
//    textMiddle->setAlignment(Qt::AlignCenter);

//    QTextEdit *textBottom = new QTextEdit(QObject::tr("底部部件"),splitterRight);
//    textBottom->setAlignment(Qt::AlignCenter);

    splitterMain->setStretchFactor(1,1);
    splitterMain->setWindowTitle(QObject::tr("分割窗口"));
    splitterMain->show();
//    splitterMain->show();


}

void MdiChild::resizeEvent(QResizeEvent *event)
{
    splitterMain->resize(this->size());

}

MdiChild::~MdiChild()
{

}
