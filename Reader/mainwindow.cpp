#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent)
{
    m_OpenAction = new QAction(QIcon(":/image/clean"),"打开",this);
    m_SaveAction = new QAction(QIcon(":/image/save"),"保存",this);
    m_CancelAction = new QAction(QIcon(":/image/cancel"),"取消",this);
    m_FileMenu = new QMenu("文件(F)");
    m_EditMenu = new QMenu("编辑(E)");
    m_WindowMenu = new QMenu("视图(V)");
    m_HelpMenu = new QMenu("帮助(H)");
    Tool1 = new QToolBar(this);
    Tool2 = new QToolBar(this);

}

void MainWindow::Init()
{
    this->resize(QSize( 800, 600 )); //设置初始窗口的大小
    m_OpenAction->setStatusTip("you will open a messagebox");
    statusBar();//它是类的函数所以可以直接调用，显示状态栏
    m_FileMenu->addAction(m_OpenAction);//往菜单栏内添加动作
    m_FileMenu->addAction(m_SaveAction);
//    m_EditMenu->addAction(chat);
    m_WindowMenu->addAction(m_CancelAction);
    m_HelpMenu->addAction(m_SaveAction);
    menuBar()->addMenu(m_FileMenu); //往主窗口添加菜单项
    menuBar()->addMenu(m_EditMenu);
    menuBar()->addMenu(m_WindowMenu);
    menuBar()->addMenu(m_HelpMenu);
    Tool1->addAction(m_OpenAction);//向工具栏内添加动作
    Tool1->addAction(m_CancelAction);
    Tool2->addAction(m_SaveAction);
    addToolBar(Qt::TopToolBarArea,Tool1);//把这两个工具栏添加到窗口
    addToolBar(Qt::TopToolBarArea,Tool2);

    //绑定槽
    connect(m_OpenAction, SIGNAL(triggered()), this, SLOT(openclicked()));
}

//class dialog:public QDialog
//{
//  public:
//   QPushButton *button1;
//   QPushButton *button2;
//   QLineEdit   *lineidt;
//   QLabel     *label;
//   QGridLayout *gridlayout;
//   dialog()//构造函数
//   {
//      this->setFixedSize(600,400);
//      button1=new QPushButton("choose");
//      button2=new QPushButton("quit");
//      label=new QLabel("input data");
//      lineidt=new QLineEdit("");
//      gridlayout=new QGridLayout(this);
//      gridlayout->addWidget(label,0,0);
//      gridlayout->addWidget(lineidt,0,1);
//      gridlayout->addWidget(button1,1,0);
//      gridlayout->addWidget(button2,1,1);
//      connect(button2,SIGNAL(clicked()),this,SLOT(close()));
//      setLayout(gridlayout);
//   }
//   ~dialog()
//   {
//   }
//};
void MainWindow::openclicked()
{
    QDialog a;
    QPushButton *button1;
    QPushButton *button2;
    QLineEdit   *lineidt;
    QLabel     *label;
    QGridLayout *gridlayout;
    a.setFixedSize(600,400);
    button1=new QPushButton("choose");
    button2=new QPushButton("quit");
    label=new QLabel("input data");
    lineidt=new QLineEdit("");
    gridlayout=new QGridLayout(&a);
    gridlayout->addWidget(label,0,0);
    gridlayout->addWidget(lineidt,0,1);
    gridlayout->addWidget(button1,1,0);
    gridlayout->addWidget(button2,1,1);
//    connect(button2,SIGNAL(clicked()),&a,SLOT(close()));
    setLayout(gridlayout);
    a.exec();
 //  dialog a;
 //  a.exec();
}
MainWindow::~MainWindow()
{
}
