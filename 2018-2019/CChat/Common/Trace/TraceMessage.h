#pragma once
#include <QObject>
#include <QDateTime>
#include <QString>

enum MessageSeverity { DEBUG, EVENT, WARNING, ERROR };

class TraceMessage : public QObject
{
	Q_OBJECT
private:
	MessageSeverity type;
	QString body;
	QDateTime* dateTime;
public:
	TraceMessage(QString body, MessageSeverity type, QDateTime* dateTime = nullptr, QObject* parent = nullptr);
	QString toString();
	bool fromString(QString str);
};
