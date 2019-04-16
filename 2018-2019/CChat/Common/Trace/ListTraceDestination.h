#pragma once
#include <QObject>
#include <QList>
#include "AbstractTraceDestination.h"

class ListTraceDestination : public AbstractTraceDestination
{
	Q_OBJECT;
private:
	QList<TraceMessage*>* destinationList;
public:
	ListTraceDestination(QList<TraceMessage*>* destinationList, QObject* parent = nullptr);
	void putMessage(TraceMessage* message);
};