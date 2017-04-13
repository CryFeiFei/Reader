#ifndef PDFKIT_H
#define PDFKIT_H

#include <QImage>

#include "_Inclusion/Win32/poppler/poppler-qt5.h"
#include "Kit.h"

class PDFkit : public Kit
{
public:
    PDFkit();
    ~PDFkit();

private:
    Poppler::Page*       m_pdfPage;
    Poppler::Document*   m_document;

public:
    // 获取某一页的页指针
    Poppler::Page* GetPage(int nPageNum);

public:

    //初始化Doc指针
    virtual int Init();
    // 获得某一页的真实图像
    virtual QImage GetActruallyPageImage(int nPageNum);
    // 获得某一页真实的大小
    virtual QSize GetActruallyPageSize(int nPageNum);
    // 获得页总数大小
    virtual int GetNumCount();

    virtual QImage GetPageImage(int nPageNum, int x, int y, int w, int h, int rotate = 0);



};

#endif // PDFKIT_H
