#ifndef MDICHILD_H
#define MDICHILD_H

#include<QWidget>
#include<QSplitter>
#include<QTextEdit>
#include<QTabWidget>
#include<QLayout>
#include<QPushButton>

#include "navigationwidget.h"


class MdiChild : public QWidget
{
    Q_OBJECT

public:
    MdiChild();
    ~MdiChild();
    void resizeEvent(QResizeEvent *event);

    void newFile()
    {
        setWindowTitle("qwe");
    }

public:
    QSplitter*            m_splitterMain;
    NavigationWidget*     m_navigationBar; //左边导航栏
    QWidget*              m_Canves;




public:

    void InitOutline(); //初始化大纲树
    void InitThumbnail(); //初始化缩略图
    void InitSemantic(); //初始化语义树
    void CreatNavigationBar(); //创建导航栏

};

#endif // MDICHILD_H
