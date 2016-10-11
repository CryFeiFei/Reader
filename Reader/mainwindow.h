#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QToolBar>
#include<QDialog>
#include<QFileDialog>
#include<QString>
#include<QMdiArea>

class MainWindow : public QMainWindow
{
     Q_OBJECT
public:
     MainWindow(QWidget *parent = 0);
     ~MainWindow();

public:
     void CreatToolBar(); //创建工具栏
     void CreatActions(); //创建动作
     void CreatMenus(); //创建菜单栏

private:
     QMenu*               m_FileMenu; //菜单栏
     QMenu*               m_EditMenu;
     QMenu*               m_WindowMenu;
     QMenu*               m_HelpMenu;

     //动作
     QAction*             m_OpenAction; //打开文件
     QAction*             m_SaveAction; //保存文件
     QAction*             m_QuitAction;

     //两个工具栏
     QToolBar*            m_FileTool;
     QToolBar*            m_ZoomTool;

     //窗口布局
     QWidget*             m_MainWin;    //主窗体
     QMdiArea*            m_MainMdiArea; //主窗体中的多文档区域




public slots:
     //定义槽函数
     void OpenFile();
     void SaveFile();
     void CloseFile();

     void UpDataMenus(); //更新状态栏

private:
     QString m_strFileName;
};
#endif // MAINWINDOW_H
