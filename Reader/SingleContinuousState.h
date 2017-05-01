#ifndef SINGLECONTINUOUSSTATE_H
#define SINGLECONTINUOUSSTATE_H

#include <QScrollArea>

#include "ViewState.h"

class SingleContinuousState : public ViewState
{
public:
    SingleContinuousState(IChildViewer* childViewer);
    virtual ~SingleContinuousState();

public:
    virtual void RenderPages(QPainter* paint);

public:
    ViewModel*      m_ViewModel;

private:
    IChildViewer*    m_ChildViewer;

private:
    int GetPageCount() { return m_ChildViewer->getNumCount();}
    QSize GetPageSize(int nPageNum) { return m_ChildViewer->getActruallyPageSize(nPageNum);}

    int GetVScrollPos();

    int GetHScrollPos();

    int GetPageHeightCount(int nNumPage);

    bool GetVPos(int nScrollPos, int& nPageNum, int& nPageVPos);

};

#endif // SINGLECONTINUOUSSTATE_H
