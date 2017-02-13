#ifndef PDFKIT_H
#define PDFKIT_H

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

};

#endif // PDFKIT_H
