#include "MainViewer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainViewer mainViewer;
	mainViewer.show();

	return a.exec();
}
