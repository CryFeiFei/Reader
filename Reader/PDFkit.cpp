#include "PDFkit.h"

PDFkit::PDFkit():m_pdfPage(NULL),m_document(NULL)
{

}

PDFkit::~PDFkit()
{

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

bool PDFkit::Init()
{
    m_document = Poppler::Document::load(m_strFileName);

    // 更加清晰
    m_document->setRenderHint(Poppler::Document::Antialiasing);
    m_document->setRenderHint(Poppler::Document::TextAntialiasing);

    return true;
}

QImage PDFkit::GetActruallyPageImage(int nPageNum)
{
    Poppler::Page*  pPage = NULL;
    pPage = GetPage(nPageNum);

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

int PDFkit::GetPageCount()
{
    if (m_document == NULL)
        return 0;

    int nNumCount = m_document->numPages();

    return nNumCount > 0 ? nNumCount: 0;
}

QSize PDFkit::GetPageSize(int nPageNum)
{
    QSize size = QSize(0,0);
    if (m_document == NULL)
        return size;

    Poppler::Page*  pPage = NULL;
    pPage = GetPage(nPageNum);

    size = pPage->pageSize();
    size = size * m_multiple;

 //   DELETE_POINT(pPage);

    return size;
}

QImage PDFkit::GetPageImage(int nPageNum)
{
    Poppler::Page*  pPage = NULL;
    pPage = GetPage(nPageNum);

    QSize size = GetPageSize(nPageNum);
    QImage imageBuffer = pPage->renderToImage(72 * m_multiple, 72 * m_multiple, 0, nPageNum, size.width(), size.height());

    return imageBuffer;
}

QDomDocument* PDFkit::GetTOC()
{
    Q_ASSERT(m_document != NULL);

    return m_document->toc();
}





