#pragma once
#include <QObject>
#include <QList>
#include "TraceMessage.h"
class AbstractTraceDestination : public QObject
{
	Q_OBJECT;
public:
	AbstractTraceDestination(QObject* parent = nullptr) : QObject(parent) {}
	virtual void putMessage(TraceMessage* message) = 0;
};
/*!
\class AbstraceTraceDestination AbstractTraceDestination.h
\brief Abstract class of destinations
\details Works as a template for destination classes (Guess I shouldn't teach you why are abstract classes needed)
\fn virtual void AbstractTraceDestination::putMessage(TraceMessage* message)
\brief Virtual function that is used by CChatTrace for putting a message into it. No need to include it, only inherited classes that are needed.
\param message pointer to TraceMessage object
*/