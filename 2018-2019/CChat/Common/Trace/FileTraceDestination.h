#pragma once
#include <QObject>
#include <QList>
#include <QFile>
#include <QTextStream>
#include "AbstractTraceDestination.h"

class FileTraceDestination : public AbstractTraceDestination
{
	Q_OBJECT;
private:
	QString destinationFilename;
	QFile file;
	QTextStream* out;
public:
	FileTraceDestination(QString destinationFilename, QObject* parent = nullptr); 
	void putMessage(TraceMessage* message);
	~FileTraceDestination();
};