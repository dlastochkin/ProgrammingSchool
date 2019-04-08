#include "FileTraceDestination.h"
#include <QFile>
#include <QTextStream>

FileTraceDestination::FileTraceDestination(QString destinationFilename, QObject * parent) : AbstractTraceDestination(parent)
{
	this->destinationFilename = destinationFilename;
}

void FileTraceDestination::putMessage(TraceMessage * message)
{
	QFile file(destinationFilename);
	if (!file.open(QIODevice::ReadOnly))
	{
	}
	QTextStream out(&file);
	QString str;
	out << message->toString() << "\n";
	file.close();
}
