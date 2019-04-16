#include "FileTraceDestination.h"

FileTraceDestination::FileTraceDestination(QString destinationFilename, QObject * parent) : AbstractTraceDestination(parent)
{
	this->destinationFilename = destinationFilename;
	file.setFileName(destinationFilename);
	if (!file.open(QIODevice::WriteOnly))
	{
		if (file.exists())
		{
			//exception
			return;
		}
		else
		{
			//create
		}
	}
	out = new QTextStream(&file);
}

void FileTraceDestination::putMessage(TraceMessage * message)
{
	(*out) << message->toString() << "\n";
	out->flush();
}

FileTraceDestination::~FileTraceDestination()
{
	file.close();
}

