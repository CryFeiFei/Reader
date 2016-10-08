#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QToolBar>
#include<QDialog>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QLineEdit>
#include<QLabel>
#include<QString>
#include<QFileDialog>

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

protected:
     QMenu*               m_FileMenu;
     QMenu*               m_EditMenu;
     QMenu*               m_WindowMenu;
     QMenu*               m_HelpMenu;
     QMenuBar*            total;
     QAction*             m_OpenAction;
     QAction*             m_SaveAction;
     QAction*             m_QuitAction;
     QToolBar*            m_FileTool;
     QToolBar*            m_ZoomTool;

public slots:
     //定义槽函数
     void ShowOpenFile();
     void SaveFile();
     void CloseFile();

private:
     QString m_strFileName;
};
#endif // MAINWINDOW_H
