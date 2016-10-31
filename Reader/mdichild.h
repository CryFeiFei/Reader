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

private:
    QSplitter*            m_splitterMain;
    NavigationWidget*              m_navigationBar; //左边导航栏
//    QWidget*              m_topNBWidget; //上面的菜单栏
//    QTabWidget*           m_tabWidget; //导航栏里边的tab标签
//    QWidget*              m_OutlineWidget; //大纲栏
//    QWidget*              m_ThumbnailWidget; //缩略图
//    QWidget*              m_SemanticTree; //语义树




public:

    void InitOutline(); //初始化大纲树
    void InitThumbnail(); //初始化缩略图
    void InitSemantic(); //初始化语义树
    void CreatNavigationBar(); //创建导航栏

};

#endif // MDICHILD_H
