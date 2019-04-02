#pragma once
#include <QObject>
#include <QList>
#include "AbstractTraceDestination.h"

class FileTraceDestination : public AbstractTraceDestination
{
	Q_OBJECT;
private:
	QString destinationFile;
public:
	FileTraceDestination(QString destinationFile, QObject* parent = nullptr); 
	void putMessage(TraceMessage message);
};