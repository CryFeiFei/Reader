
#include "ViewModel.h"
#include "ChildViewer.h"


ViewModel::ViewModel(ChildViewer* ChildViewer) : m_ChildViewer(ChildViewer), m_kit(NULL)
{
    m_kit = new PDFkit();
    // 测试用例
    QString filename;
    filename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/test.pdf";

    // todo待重构
    QString strFileName = m_ChildViewer->getFileName();
    m_kit->SetFileName(strFileName);
    m_kit->Init();

}

ViewModel::~ViewModel()
{

}

void ViewModel::RenderPages(QPainter *painter)
{
    if (painter == NULL)
        return;

    QImage image1 = GetImage();
    painter->drawImage(0, GetVScrollPos(),image1);

}

int ViewModel::GetVScrollPos()
{
    QScrollBar* pScrollBar = m_ChildViewer->getScrollArea()->verticalScrollBar();
    return pScrollBar->value();
}

int ViewModel::GetHScrollPos()
{
    QScrollBar* pScrollBar = m_ChildViewer->getScrollArea()->verticalScrollBar();
    return pScrollBar->value();
}

// 暂时完成单页非连续状态
QImage ViewModel::GetImage()
{
    int vPos = GetVScrollPos();

    // 获取第一页的大小
    int nNum = GetNumCount();
    QSize size = GetActruallyPageSize(0);


    int vhigh = size.height();

    int ny = vPos % vhigh;
    int nCurPageNum = vPos / vhigh;

    QImage image2 = GetPageImage(nCurPageNum, 0, nCurPageNum, size.width(), size.height(), 0);

    return image2;
}


