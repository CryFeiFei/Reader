#ifndef I_CHILDVIEWER_H
#define I_CHILDVIEWER_H

#include <QWidget>
#include <QScrollArea>

class IChildViewer : public QWidget
{
public:
    IChildViewer(){}
    virtual ~IChildViewer(){}


// 提供给子模块的接口
public:
    // 获得
    virtual QScrollArea* getScrollArea() = 0;
    virtual int getNumCount() = 0;
    virtual QSize getActruallyPageSize(int nPageNum) = 0;

};

#endif // I_CHILDVIEWER_H
