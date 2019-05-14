#pragma once
#include <QObject>
#include <QDateTime>
#include <QString>
#include "MessageSeverity.h"

class TraceMessage : public QObject
{
	Q_OBJECT
private:
	MessageSeverity const* type;
	QString body;
	QDateTime dateTime;
public:
	TraceMessage(QString body, MessageSeverity const* type, QObject* parent = nullptr);
	TraceMessage(QString str, QObject* parent = nullptr); //from string
	QString toString(); 
	MessageSeverity getType();
};
