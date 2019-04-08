#pragma once
#include <QObject>
#include <QList>
#include "AbstractTraceDestination.h"

class FileTraceDestination : public AbstractTraceDestination
{
	Q_OBJECT;
private:
	QString destinationFilename;
public:
	FileTraceDestination(QString destinationFilename, QObject* parent = nullptr); 
	void putMessage(TraceMessage* message);
};