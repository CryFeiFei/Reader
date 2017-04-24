#ifndef VIEWSTATE_H
#define VIEWSTATE_H

#include <QPainter>
#include <QScrollBar>

#include "IChildViewer.h"

class ViewModel;
class ChildViewer;

class ViewState
{
public:
    ViewState(){};
    virtual ~ViewState(){};

public:
    virtual void RenderPages(QPainter* paint) = 0;
};

#endif // VIEWSTATE_H
