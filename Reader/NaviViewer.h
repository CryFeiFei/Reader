// summary:导航栏
#ifndef NAVI_VIEWER_H
#define NAVI_VIEWER_H

#include<QWidget>
#include<QSplitter>
#include<QTextEdit>
#include<QTabWidget>
#include<QLayout>
#include<QVBoxLayout>
#include<QPushButton>
#include<QTreeWidget>
#include<QTreeWidgetItem>

#include "IChildViewer.h"

class NaviViewer : public QWidget
{
	Q_OBJECT
public:
	NaviViewer(IChildViewer* childviewer);

private:
	IChildViewer*         m_IChildViewer;


    //widget
private:   
    QWidget*              m_topNBWidget; //上面的菜单栏
    QTabWidget*           m_tabWidget; //导航栏里边的tab标签
	QWidget*              m_OutlineWidget; //大纲栏
	QTreeWidget*          m_OutlineTree;//大纲树
	QVBoxLayout*          m_OutlineLayout; //大纲树布局
	void                  ComputerToc(QDomNode* domNode, QTreeWidgetItem* parentWidgetItem);


	QWidget*              m_ThumbnailWidget; //缩略图
	QWidget*              m_SemanticTree; //语义树

private slots:
    void sl_btnClicked();

private:
    void InitUI();
    // 目录
    void InitTOC();

};

#endif // NAVI_VIEWER_H
