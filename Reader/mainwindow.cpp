#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setBaseSize(400,300);
    open=new QAction(QIcon(":/image/clean"),"打开",this);
    open->setStatusTip("you will open a messagebox");
    statusBar();//它是类的函数所以可以直接调用，显示状态栏
    save=new QAction(QIcon(":/image/download"),"save",this);
    cancel=new QAction(QIcon(":/image/alert"),"cancel",this);
    chat=new QAction(QIcon(":/image/chat"),"chat",this);
    m_FileMenu=new QMenu("文件(F)");//往菜单栏内添加动作
    m_FileMenu->addAction(open);
    m_EditMenu=new QMenu("编辑(E)");
    m_EditMenu->addAction(chat);
    m_WindowMenu=new QMenu("视图(V)");
    m_WindowMenu->addAction(cancel);
    m_HelpMenu=new QMenu("帮助(H)");
    m_HelpMenu->addAction(save);
    menuBar()->addMenu(m_FileMenu); //往主窗口添加菜单项
    menuBar()->addMenu(m_EditMenu);
    menuBar()->addMenu(m_WindowMenu);
    menuBar()->addMenu(m_HelpMenu);
    Tool1=new QToolBar(this);//向工具栏内添加动作
    Tool1->addAction(open);
    Tool1->addAction(cancel);
    Tool2=new QToolBar(this);
    Tool2->addAction(save);
    Tool2->addAction(chat);
    addToolBar(Qt::TopToolBarArea,Tool1);//把这两个工具栏添加到窗口
    addToolBar(Qt::TopToolBarArea,Tool2);
    connect(open,SIGNAL(triggered()),this,SLOT(openclicked()));
}
class dialog:public QDialog
{
  public:
   QPushButton *button1;
   QPushButton *button2;
   QLineEdit   *lineidt;
   QLabel     *label;
   QGridLayout *gridlayout;
   dialog()//构造函数
   {
      this->setFixedSize(600,400);
      button1=new QPushButton("choose");
      button2=new QPushButton("quit");
      label=new QLabel("input data");
      lineidt=new QLineEdit("");
      gridlayout=new QGridLayout(this);
      gridlayout->addWidget(label,0,0);
      gridlayout->addWidget(lineidt,0,1);
      gridlayout->addWidget(button1,1,0);
      gridlayout->addWidget(button2,1,1);
      connect(button2,SIGNAL(clicked()),this,SLOT(close()));
      setLayout(gridlayout);
   }
   ~dialog()
   {
   }
};
void MainWindow::openclicked()
{
   dialog a;
   a.exec();
}
MainWindow::~MainWindow()
{
}
