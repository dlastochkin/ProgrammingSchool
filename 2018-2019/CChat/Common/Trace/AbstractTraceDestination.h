#pragma once
#include <QObject>
#include <QList>
#include "TraceMessage.h"

class AbstractTraceDestination : public QObject
{
	Q_OBJECT;
public:
	AbstractTraceDestination(QObject* parent = nullptr) : QObject(parent) {}
	virtual void putMessage(TraceMessage message) = 0;
};