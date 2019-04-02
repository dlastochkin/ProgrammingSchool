#include "FileTraceDestination.h"

FileTraceDestination::FileTraceDestination(QString destinationFile, QObject * parent) : AbstractTraceDestination(parent)
{
	this->destinationFile = destinationFile;
}

void FileTraceDestination::putMessage(TraceMessage message)
{
	messageList.append(message);
}