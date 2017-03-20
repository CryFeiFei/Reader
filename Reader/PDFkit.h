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

public:
    virtual int OpenFile(){};
    virtual int SaveFile(){};

private:
    Poppler::Page*       m_pdfPage;
    Poppler::Document*   m_document;

public:

    //初始化Doc指针
    void Init(QString strFileName);
    // 获取某一页的页指针
    Poppler::Page* GetPage(int nPageNum);
    // 获得某一页的真实图像
    QImage GetActruallyPageImage(int nPageNum);
    // 获得某一页真实的大小
    QSize GetActruallyPageSize(int nPageNum);

};

#endif // PDFKIT_H
