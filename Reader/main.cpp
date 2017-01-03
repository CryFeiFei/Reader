#include "MainViewer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainViewer w;
    w.show();

    return a.exec();
}
