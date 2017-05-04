// summary: 主窗口
#ifndef MAIN_VIEWER_H
#define MAIN_VIEWER_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QMdiArea>
#include <QDesktopServices>
#include <QMdiSubWindow>

#include "IMainViewer.h"
#include "ChildViewer.h"
#include "MultiViwer.h"

class MainViewer : public QMainWindow, public IMainViewer
{
     Q_OBJECT
    
public:
     MainViewer(QWidget *parent = 0);
     ~MainViewer();

public:
     virtual QString getFileName(){ return m_strFileName; }

public:
     void CreatToolBar(); //创建工具栏
     void CreatActions(); //创建动作
     void CreatMenus(); //创建菜单栏

public:
     ChildViewer* getCurChildViewer();

private:
     QMenu*               m_FileMenu; //菜单栏
     QMenu*               m_EditMenu;
     QMenu*               m_WindowMenu;
     QMenu*               m_HelpMenu;

     //动作
     QAction*             m_OpenAction; //打开文件
     QAction*             m_SaveAction; //保存文件
     QAction*             m_QuitAction; //退出

     QAction*             m_ZoomIn;
     QAction*             m_ZoomOut;
     QAction*             m_ZoomReset;

     //test
     QAction*             m_NewAction; //新建文件

     //两个工具栏
     QToolBar*            m_FileTool;
     QToolBar*            m_ZoomTool;

     //窗口布局
     MultiViwer*          m_MainMdiArea; //主窗体中的多文档区域


public:
     ChildViewer* CreateChildViewer();

public slots:
     //定义槽函数
     void OpenFile();
     void SaveFile();
     void CloseFile();
     void NewFile();
     void UpDataMenus(); //更新状态栏
     void ZoomIn();
     void ZoomOut();
     void ZoomReset();

private:
     QString m_strFileName;
};
#endif // MAIN_VIEWER_H
