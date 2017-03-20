#include "PDFkit.h"

PDFkit::PDFkit():m_pdfPage(NULL),m_document(NULL)
{

}

PDFkit::~PDFkit()
{

}

void PDFkit::Init(QString strFileName)
{
    m_document = Poppler::Document::load(strFileName);

    // 更加清晰
    m_document->setRenderHint(Poppler::Document::Antialiasing);
    m_document->setRenderHint(Poppler::Document::TextAntialiasing);
}

Poppler::Page* PDFkit::GetPage(int nPageNum)
{
    if (m_document == NULL)
        return NULL;

    Poppler::Page* pPage = NULL;
    pPage = m_document->page(nPageNum);

    Q_ASSERT(pPage != NULL);

    return pPage;
}

QImage PDFkit::GetActruallyPageImage(int nPageNum)
{
//    if (m_document == NULL)
//        return NULL;

    Poppler::Page*  pPage = NULL;
    pPage = GetPage(nPageNum);
//    if (pPage == NULL)
//        return NULL;

    QSize size = GetActruallyPageSize(nPageNum);

    QImage imageBuffer = pPage->renderToImage(72, 72, 0, nPageNum, size.width(), size.height());

    return imageBuffer;

}

QSize PDFkit::GetActruallyPageSize(int nPageNum)
{
    QSize size = QSize(0,0);
    if (m_document == NULL)
        return size;

    Poppler::Page*  pPage = NULL;
    pPage = GetPage(nPageNum);

    size = pPage->pageSize();

    return size;

}


