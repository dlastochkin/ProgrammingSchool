#include <QtCore/QCoreApplication>
#include "ClientLogic.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ClientLogic* client = new ClientLogic();

	client->start(400,500);

	return a.exec();
}
