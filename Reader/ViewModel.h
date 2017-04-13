
#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "Kit.h"
#include "PDFkit.h"


// 测试头文件
#include <QStandardPaths>
#include <QWidget>
#include <QPalette>
#include <QDesktopWidget>

class ChildViewer;

class ViewModel
{
public:
    ViewModel(ChildViewer* ChildViewer);
    ~ViewModel();

public:
    ChildViewer*   m_ChildViewer;
    Kit*           m_kit;

public:
    int GetNumCount() { return m_kit->GetNumCount(); }
    QSize GetActruallyPageSize(int nPageNum) { return m_kit->GetActruallyPageSize(nPageNum); }
    QImage GetActruallyPageImage(int nPageNum) { return m_kit->GetActruallyPageImage(nPageNum); }
    QImage GetPageImage(int nPageNum, int x, int y, int w, int h, int rotate){ return m_kit->GetPageImage(nPageNum, x, y, w, h, rotate); }

public:
    void RenderPages(QPainter* paint);

private:
    int  GetVScrollPos();
    int  GetHScrollPos();
    QImage GetImage();

};

#endif // VIEWMODEL_H
