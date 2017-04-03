// summary: 主窗口
#ifndef MAIN_VIEWER_H
#define MAIN_VIEWER_H

#include<QMainWindow>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QToolBar>
#include<QDialog>
#include<QFileDialog>
#include<QString>
#include<QMdiArea>

#include"ChildViewer.h"
#include "MultiViwer.h"

class MainViewer : public QMainWindow
{
     Q_OBJECT
    
public:
     MainViewer(QWidget *parent = 0);
     ~MainViewer();

public:


public:
     void CreatToolBar(); //创建工具栏
     void CreatActions(); //创建动作
     void CreatMenus(); //创建菜单栏

     void resizeEvent();

private:
     QMenu*               m_FileMenu; //菜单栏
     QMenu*               m_EditMenu;
     QMenu*               m_WindowMenu;
     QMenu*               m_HelpMenu;

     //动作
     QAction*             m_OpenAction; //打开文件
     QAction*             m_SaveAction; //保存文件
     QAction*             m_QuitAction; //退出

     //test
     QAction*             m_NewAction; //新建文件

     //两个工具栏
     QToolBar*            m_FileTool;
     QToolBar*            m_ZoomTool;

     //窗口布局
//     QWidget*             m_MainWin;    //主窗体
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

private:
     QString m_strFileName;
};
#endif // MAIN_VIEWER_H
