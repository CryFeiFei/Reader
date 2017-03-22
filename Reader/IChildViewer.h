#ifndef I_CHILDVIEWER_H
#define I_CHILDVIEWER_H

#include <QWidget>

class IChildViewer : public QWidget
{
public:
    IChildViewer(){}
    virtual ~IChildViewer(){}


// 提供给子模块的接口
public:
    // 获得
    virtual QScrollArea* getScrollArea() = 0;

};

#endif // I_CHILDVIEWER_H
