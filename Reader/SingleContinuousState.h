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
    virtual int GetCurPageNum();
    virtual void GotoPage(int nPageNum);

public:
    ViewModel*      m_ViewModel;

private:
    IChildViewer*    m_ChildViewer;

private:
    int GetPageCount() { return m_ChildViewer->getPageCount();}
    QSize GetPageSize(int nPageNum) { return m_ChildViewer->getPageSize(nPageNum);}

    int GetVScrollPos();

    int GetHScrollPos();

    int GetPageHeightCount(int nNumPage);

    bool GetVPos(int nScrollPos, int& nPageNum, int& nPageVPos);

};

#endif // SINGLECONTINUOUSSTATE_H
