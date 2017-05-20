#include "MainViewer.h"


MainViewer::MainViewer(QWidget *parent) :  QMainWindow(parent)
{

    this->resize(QSize(800,600)); //设置初始窗口大小
    statusBar(); //显示状态栏
    CreatActions();
    CreatMenus();
    CreatToolBar();

    m_MainMdiArea = new MultiViwer();
    setCentralWidget(m_MainMdiArea);
    m_MainMdiArea->setViewMode(QMdiArea::TabbedView);

}

MainViewer::~MainViewer()
{

}

void MainViewer::CreatActions()
{
    //打开动作
    m_OpenAction = new QAction(QIcon(":/image/open"), "打开", this);
    m_OpenAction->setShortcut(tr("Ctrl+O"));
    m_OpenAction->setStatusTip(tr("打开文件"));
    connect(m_OpenAction,SIGNAL(triggered()), this, SLOT(OpenFile()));

    //保存动作
    m_SaveAction = new QAction(QIcon(":/image/save"), "保存", this);
    m_SaveAction->setShortcut(tr("Ctrl+S"));
    m_SaveAction->setStatusTip(tr("保存文件"));
    connect(m_SaveAction,SIGNAL(triggered()), this, SLOT(SaveFile()));

    //退出动作
    m_QuitAction = new QAction(QIcon(":/image/close"), "退出", this);
    m_QuitAction->setShortcut(tr("Ctrl+Q"));
    m_QuitAction->setStatusTip(tr("退出程序"));
    connect(m_QuitAction,SIGNAL(triggered()),this,SLOT(CloseFile()));

    //放大
    m_ZoomIn = new QAction(QIcon(":/image/zoom_in"), "放大", this);
    m_ZoomIn->setStatusTip(tr("放大"));
    connect(m_ZoomIn, SIGNAL(triggered()), this, SLOT(ZoomIn()));

    //缩小
    m_ZoomOut = new QAction(QIcon(":/image/zoom_out"), "缩小", this);
    m_ZoomOut->setStatusTip(tr("缩小"));
    connect(m_ZoomOut, SIGNAL(triggered()), this, SLOT(ZoomOut()));

    //重置大小
    m_ZoomReset = new QAction(QIcon(":/image/zoom_reset"), "重置", this);
    m_ZoomReset->setStatusTip(tr("重置"));
    connect(m_ZoomReset, SIGNAL(triggered()), this, SLOT(ZoomReset()));

    //跳转上一页
    m_PreviousPage = new QAction(QIcon(":/image/previouspage"), "上一页", this);
    m_PreviousPage->setStatusTip(tr("上一页"));
    connect(m_PreviousPage, SIGNAL(triggered()), this, SLOT(PreviousPage()));

    //跳转下一页
    m_NextPage = new QAction(QIcon(":/image/nextpage"), "下一页", this);
    m_NextPage->setStatusTip(tr("下一页"));
    connect(m_NextPage, SIGNAL(triggered()), this, SLOT(NextPage()));

}

void MainViewer::CreatMenus()
{
    m_FileMenu = menuBar()->addMenu(tr("文件(F)"));
    m_FileMenu->addAction(m_OpenAction);//往菜单栏内添加动作
    m_FileMenu->addAction(m_SaveAction);
    m_FileMenu->addSeparator();
    m_FileMenu->addAction(m_QuitAction);

    //两种添加menu的方法
    m_EditMenu = new QMenu("编辑(E)");
    menuBar()->addMenu(m_EditMenu);

    m_WindowMenu = menuBar()->addMenu(tr("视图(V)"));
    m_HelpMenu = menuBar()->addMenu(tr("帮助(H)"));
}

void MainViewer::CreatToolBar()
{
    // 打开工具条
    m_FileTool = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, m_FileTool);//把这两个工具栏添加到窗口
    m_FileTool->addAction(m_OpenAction);//向工具栏内添加动作
    m_FileTool->addAction(m_SaveAction);
    m_FileTool->addSeparator();
    m_FileTool->addAction(m_QuitAction);

    // zoom工具条
    m_ZoomTool = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, m_ZoomTool);
    m_ZoomTool->addAction(m_ZoomIn);
    m_ZoomTool->addAction(m_ZoomReset);
    m_ZoomTool->addAction(m_ZoomOut);

    // 页码工具条
    m_PageTool = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, m_PageTool);
    m_PageTool->addAction(m_PreviousPage);
    m_PageTool->addAction(m_NextPage);
}

void MainViewer::OpenFile()
{
    QString strFilter;
    strFilter = "*.pdf";
    QString strDir;
    strDir = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    m_strFileName = QFileDialog::getOpenFileName(this,"Reader", strDir, strFilter);

    if(m_strFileName.isEmpty())
        return;

    NewFile();
}

void MainViewer::NewFile()
{
    ChildViewer *childViewer = CreateChildViewer();

    int index = m_strFileName.lastIndexOf("/");
//    m_strFilePath = m_strFileName.mid(0, index + 1);
    QString strFileName = m_strFileName.mid((index + 1), (m_strFileName.size() - index));
    childViewer->setWindowTitle(strFileName);
    childViewer->show();
}

ChildViewer* MainViewer::CreateChildViewer()
{
    ChildViewer *child = new ChildViewer(this);
    m_MainMdiArea->addSubWindow(child);
    return child;
}

void MainViewer::SaveFile()
{

}

void MainViewer::CloseFile()
{
    this->close();
}

void MainViewer::UpDataMenus()
{

}

ChildViewer* MainViewer::getCurChildViewer()
{
    QMdiSubWindow* mdiSubWindow = m_MainMdiArea->currentSubWindow();
    if (mdiSubWindow == NULL)
        return NULL;

    ChildViewer* child = static_cast<ChildViewer*>(mdiSubWindow->widget());
    Q_ASSERT(child != NULL);

    return child;
}

void MainViewer::ZoomIn()
{
    ChildViewer* child = getCurChildViewer();
    if (child == NULL)
        return;

    child->ZoomIn();
}

void MainViewer::ZoomOut()
{
    ChildViewer* child = getCurChildViewer();
    if (child == NULL)
        return;

    child->ZoomOut();
}

void MainViewer::ZoomReset()
{
    ChildViewer* child = getCurChildViewer();
    if (child == NULL)
        return;

    child->ZoomReset();
}

void MainViewer::PreviousPage()
{
    ChildViewer* child = getCurChildViewer();
    if (child == NULL)
        return;
    child->PreviousPage();
//    child->LastPage()
}

void MainViewer::NextPage()
{
    ChildViewer* child = getCurChildViewer();
    if (child == NULL)
        return;

    child->NextPage();

}

void MainViewer::RefreshWindow()
{
    ChildViewer* child = getCurChildViewer();
    if (child == NULL)
        return;

    child->RefreshWindow();
}


