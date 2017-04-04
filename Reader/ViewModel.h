
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

public:
    void RenderPages(QPainter* paint);

};

#endif // VIEWMODEL_H
