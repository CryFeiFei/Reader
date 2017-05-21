
#ifndef I_MAINVIEWER_H
#define I_MAINVIEWER_H

#include <QMainWindow>
#include <QLineEdit>

class IMainViewer
{
public:
    IMainViewer(){}
    virtual ~IMainViewer(){}

public:
    virtual QString getFileName() = 0;
    virtual QLineEdit* getPageNumLineEdit() = 0;

};

#endif // I_MAINVIEWER_H
