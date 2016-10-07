#ifndef PDFKIT_H
#define PDFKIT_H

#include "kit.h"

class PDFkit : public kit
{
public:
    PDKkit(){}
    ~PDFkit(){}

public:
    virtual int OpenFile();
    virtual int SaveFile();


};

#endif // PDFKIT_H
