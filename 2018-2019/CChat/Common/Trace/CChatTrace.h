#pragma once
#include <QObject>
#include <QList>
#include "TraceMessage.h"
#include "AbstractTraceDestination.h"


class CChatTrace : public QObject
{
	Q_OBJECT;

private:
	QString filename;
	QList <TraceMessage*>* messageList;
	QList <AbstractTraceDestination*> destinationList;
	void transmit(TraceMessage* message);

signals:
	void messageListUpdated();
public:
	CChatTrace(QObject* parent = nullptr);
	void import(QString filename);
	void add(QString ms, MessageSeverity const* type);
	void addDestination(AbstractTraceDestination* destination);
	~CChatTrace();
};