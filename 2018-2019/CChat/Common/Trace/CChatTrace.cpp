#include "CChatTrace.h"
#include "TraceLoader.h"

CChatTrace::CChatTrace(QObject* parent) : QObject(parent) 
{
	messageList = new QList<TraceMessage*>();
}

void CChatTrace::import(QString filename)
{
	QList<TraceMessage*>* tmpList = TraceLoader::load(filename);
	while (!tmpList->isEmpty())
	{
		messageList->append(tmpList->takeFirst());
	}
}

void CChatTrace::addDestination(AbstractTraceDestination* destination)
{
	destinationList.append(destination);
	for (int i = 0; i < messageList->size(); ++i)
	{
		destination->putMessage(messageList->at(i));
	}
}

void CChatTrace::transmit(TraceMessage* message)
{
	for (int i = 0; i < destinationList.size(); ++i)
	{
		(destinationList.at(i))->putMessage(message);
	}
}

void CChatTrace::add(QString ms, MessageSeverity const* type)
{
	TraceMessage* mt = new TraceMessage(ms, type);
	messageList->append(mt);
	transmit(mt);
	emit messageListUpdated();
}

CChatTrace::~CChatTrace()
{
	while (messageList->isEmpty())
		messageList->removeFirst();
}