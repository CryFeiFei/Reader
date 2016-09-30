#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
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
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
     QMenu*               m_FileMenu;
     QMenu*               m_EditMenu;
     QMenu*               m_WindowMenu;
     QMenu*               m_HelpMenu;
     QMenuBar*            total;
     QAction*             open;
     QAction*             save;
     QAction*             cancel;
     QAction*             chat;
     QToolBar*            Tool1;
     QToolBar*            Tool2;
public slots:
     void openclicked();//定义槽函数
};
#endif // MAINWINDOW_H
