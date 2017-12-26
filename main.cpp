#include "grabscreen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	grabScreen w;
	w.show();
	return a.exec();
}
