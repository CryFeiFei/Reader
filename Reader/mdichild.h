#ifndef MDICHILD_H
#define MDICHILD_H

#include<QWidget>

class MdiChild : public QWidget
{
    Q_OBJECT

public:
    MdiChild();
    ~MdiChild();

    void newFile()
    {
        setWindowTitle("qwe");
    }

};

#endif // MDICHILD_H
