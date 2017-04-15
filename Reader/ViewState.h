#ifndef VIEWSTATE_H
#define VIEWSTATE_H

#include <QPainter>

class ViewModel;

class ViewState
{
public:
    ViewState(){};
    virtual ~ViewState(){};

public:
    virtual void RenderPages(QPainter* paint) = 0;
};

#endif // VIEWSTATE_H
