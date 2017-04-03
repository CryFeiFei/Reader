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

private:
    ChildViewer*   m_ChildViewer;
    Kit*           m_kit;





public:
    int GetNumCount();
    QSize GetActruallyPageSize(int nPageNum);



};

#endif // VIEWMODEL_H
