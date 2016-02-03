#include "Muse.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Muse w;
	w.show();
	return a.exec();
}
