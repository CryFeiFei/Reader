#include "SingleContinuousState.h"

SingleContinuousState::SingleContinuousState(IChildViewer* childViewer): m_ChildViewer(childViewer)
{

}

SingleContinuousState::~SingleContinuousState()
{

}

void SingleContinuousState::RenderPages(QPainter *paint)
{
    if (paint == NULL)
        return;

    int nScrollHeight = 0; //当前窗口的高度
    int nScrollYFlag = 0;  //当前坐标（画布）
    nScrollHeight = m_ChildViewer->getScrollArea()->size().height(); //当前绘制的剩余窗口高度
    nScrollYFlag  = GetVScrollPos();

    // 当前绘制的页码
    int nPageNum;
    // 当前页码绘制的起始VPos
    int nPageVPos;
    // 当前页码的图片
    QImage img;
    QImage imageCopy;

    while (nScrollHeight > 0)
    {
        GetVPos(nScrollYFlag, nPageNum, nPageVPos);
        // 绘制当前页的高度
        int nRenderHeight = GetPageSize(nPageNum).height() - nPageVPos;

        imageCopy = m_ChildViewer->getActruallyPageImage(nPageNum);
        img = imageCopy.copy(0, nPageVPos, GetPageSize(nPageNum).width(), nRenderHeight);
        paint->drawImage(0, nScrollYFlag, img);

        nScrollHeight -= img.height();
        nScrollYFlag += img.height();
    }


}

int SingleContinuousState::GetRenderRaw()
{
    QSize size = m_ChildViewer->getScrollArea()->size();
    double dCurDocMultiple = m_ChildViewer->getCurDocMultiple();
    double dDocHeight = m_ChildViewer->getActruallyPageSize(0).height();
    int nPageCount = m_ChildViewer->getNumCount();

    //todo暂时这样做，先把demo做起来
    int nRaw = ceil(size.height()/dCurDocMultiple*dDocHeight*nPageCount);

    return nRaw;

}

int SingleContinuousState::GetRenderColumn()
{
    QSize size = m_ChildViewer->getScrollArea()->size();
    double dCurDocMultiple = m_ChildViewer->getCurDocMultiple();
    double dDocWidth = m_ChildViewer->getActruallyPageSize(0).width();

    int nColumn = ceil(size.width() / dCurDocMultiple * dDocWidth);

    return nColumn;

}

int SingleContinuousState::GetVScrollPos()
{
    QScrollBar* pScrollBar = m_ChildViewer->getScrollArea()->verticalScrollBar();

    return pScrollBar->value();
}

int SingleContinuousState::GetHScrollPos()
{
    QScrollBar* pScrollBar = m_ChildViewer->getScrollArea()->horizontalScrollBar();
    return pScrollBar->value();
}

double SingleContinuousState::GetVScrollPercent()
{
    QScrollBar* pScrollBar = m_ChildViewer->getScrollArea()->verticalScrollBar();
    int nHeight = 0;
    int nNumCount = m_ChildViewer->getNumCount();
    for (int i = 0; i < nNumCount; i++)
    {
        nHeight += m_ChildViewer->getActruallyPageSize(i).height();
    }
    int nHPos = pScrollBar->value();
    double dPercent = (double)nHPos / (double)nHeight;
    return dPercent;
}

int SingleContinuousState::GetPageHeightCount(int nNumPage)
{
    int nHeight = 0;
    for (int i = 0; i < nNumPage; i++)
        nHeight += m_ChildViewer->getActruallyPageImage(i).height();

    return nHeight;
}

bool SingleContinuousState::GetVPos(int nScrollPos, int &nPageNum, int &nPageVStartPos)
{
    int nPageCount = GetPageCount();

    for (int i = 0; i < nPageCount; i++)
    {
        if (nScrollPos < GetPageSize(i).height())
        {
            nPageNum = i;
            nPageVStartPos = nScrollPos;
            break;
        }
        nScrollPos -= GetPageSize(i).height();
    }

    return true;
}




// 暂时完成单页非连续状态
//QImage ViewModel::GetImage()
//{
//    int vPos = GetVScrollPos();

//    // 获取第一页的大小
//    int nNum = GetNumCount();
//    QSize size = GetActruallyPageSize(0);


//    int vhigh = size.height();

//    int ny = vPos % vhigh;
//    int nCurPageNum = vPos / vhigh;

//    QImage image2 = GetPageImage(nCurPageNum, 0, nCurPageNum, size.width(), size.height(), 0);

//    return image2;
//}
