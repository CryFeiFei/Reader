#ifndef SINGLECONTINUOUSSTATE_H
#define SINGLECONTINUOUSSTATE_H

#include <QScrollArea>

#include "ViewState.h"
//#include "ChildViewer.h"
//class ChildViewer;

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
//   QScrollArea*    m_ScrollArea;

private:
    int GetPageCount() { return m_ChildViewer->getNumCount();}
    QSize GetPageSize(int nPageNum) { return m_ChildViewer->getActruallyPageSize(nPageNum);}
    // 计算绘制行数
    int GetRenderRaw();
    // 计算绘制列数
    int GetRenderColumn();

    int GetVScrollPos();

    int GetHScrollPos();

    double GetVScrollPercent();

    int GetPageHeightCount(int nNumPage);

    bool GetVPos(int nScrollPos, int& nPageNum, int& nPageVPos);



};

#endif // SINGLECONTINUOUSSTATE_H
