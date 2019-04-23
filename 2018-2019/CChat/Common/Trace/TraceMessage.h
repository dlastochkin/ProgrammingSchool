#pragma once
#include <QObject>
#include <QDateTime>
#include <QString>
#include "MessageSeverity.h"

class TraceMessage : public QObject
{
	Q_OBJECT
private:
	int type;
	QString body;
	QDateTime* dateTime;
public:
	TraceMessage(QString body, int type, QDateTime* dateTime = nullptr, QObject* parent = nullptr);
	QString toString();
	bool fromString(QString str); //overwrites this; returns false if parse failed and true otherwise
};
