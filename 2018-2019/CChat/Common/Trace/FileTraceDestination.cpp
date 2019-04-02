#include "FileTraceDestination.h"

FileTraceDestination::FileTraceDestination(QString destinationFile, QObject * parent) : AbstractTraceDestination(parent)
{
	this->destinationFile = destinationFile;
}

void FileTraceDestination::putMessage(TraceMessage message)
{
	//cout << message.toString();
}