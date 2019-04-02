#include "ListTraceDestination.h"

ListTraceDestination::ListTraceDestination(QList<TraceMessage>* destinationList, QObject * parent) : AbstractTraceDestination(parent)
{
	this->destinationList = destinationList;
}

void ListTraceDestination::putMessage(TraceMessage message)
{
	destinationList->append(message);
}