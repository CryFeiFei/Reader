#ifndef NAVIGATIONWIDGET_H
#define NAVIGATIONWIDGET_H

#include<QWidget>
#include<QSplitter>
#include<QTextEdit>
#include<QTabWidget>
#include<QLayout>
#include<QPushButton>

class NavigationWidget : public QWidget
{
    Q_OBJECT

public:
    NavigationWidget(QSplitter *parent);
    QSplitter*            m_splitterMain; //主窗口

private:
    QList<qint32>         m_baseSize;
private:
    QWidget*              m_topNBWidget; //上面的菜单栏
    QTabWidget*           m_tabWidget; //导航栏里边的tab标签
    QWidget*              m_OutlineWidget; //大纲栏
    QWidget*              m_ThumbnailWidget; //缩略图
    QWidget*              m_SemanticTree; //语义树

private slots:

    void sl_btnClicked();

};

#endif // NAVIGATIONWIDGET_H
