#pragma once
#include <QObject>
#include "TraceMessage.h"

TraceMessage::TraceMessage(QString body, MessageSeverity type, QDateTime* dateTime, QObject* parent) : QObject(parent)
{
	this->body = body;
	this->type = type;
	if (dateTime->isValid())
	{
		this->dateTime = dateTime;
	}
	else
	{
		this->dateTime = new QDateTime(QDate::currentDate(), QTime::currentTime());
	}
}

QString TraceMessage::toString()
{
	QString out;
	switch (type)
	{
	case DEBUG:
		out += "Debug:(";
		break;
	case EVENT:
		out += "Event:(";
		break;
	case WARNING:
		out += "Warning:(";
		break;
	case ERROR:
		out += "Error:(";
		break;
	}

	out += dateTime->toString("dd.MM.yyyy, hh:mm:ss") + ") " + body;
	return out;
}

bool TraceMessage::fromString(QString str)
{
	int i, i1;
	for (i = 0; i < str.size(); ++i)
	{
		if (str[i] == ':') break;
	}
	QString tmp = str.left(i);
	if (tmp == "Debug")
	{
		type = DEBUG;
	}
	else if (tmp == "Event")
	{
		type = EVENT;
	}
	else if (tmp == "Warning")
	{
		type = WARNING;
	}
	else if (tmp == "Error")
	{
		type = ERROR;
	}
	else
	{
		body = "Import error";
		type = ERROR;
		dateTime = new QDateTime(QDate::currentDate(), QTime::currentTime());
		return 1;
	}

	for (i1 = i + 1; i1 < str.size(); ++i1)
	{
		if (str[i] == ':') break;
	}
	while (str[i] != ')') ++i1;
	tmp = str.mid(i1, i - i1);

	dateTime = &(QDateTime::fromString(tmp, "dd.MM.yyyy, hh:mm:ss"));
	if (dateTime->isNull())
	{
		body = "Import error";
		type = ERROR;
		dateTime = new QDateTime(QDate::currentDate(), QTime::currentTime());
		return 1;
	}

	body = str.right(i1);
	return 0;
}
