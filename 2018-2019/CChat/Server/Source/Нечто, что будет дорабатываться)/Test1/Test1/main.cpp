#include <QtCore/QCoreApplication>
#include <QApplication>
#include "GUI_Test1.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	ServerGUI win(800, 600);

	win.show();

	return a.exec();
}
