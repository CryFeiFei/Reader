#ifndef MDICHILD_H
#define MDICHILD_H

#include<QWidget>
#include<QSplitter>
#include<QTextEdit>
#include<QTabWidget>

class MdiChild : public QWidget
{
    Q_OBJECT

public:
    MdiChild();
    ~MdiChild();
    void resizeEvent(QResizeEvent *event);

    void newFile()
    {
        setWindowTitle("qwe");
    }

private:
    QSplitter *splitterMain;

};

#endif // MDICHILD_H
