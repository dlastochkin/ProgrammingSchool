#pragma once
#include <QObject>
#include "TraceMessage.h"

TraceMessage::TraceMessage(QString body, MessageSeverity const* type, QObject* parent) : QObject(parent)
{
	this->body = body;
	this->type = type;
	dateTime = QDateTime(QDate::currentDate(), QTime::currentTime());
}

TraceMessage::TraceMessage(QString str, QObject* parent) : QObject(parent)
{
	int i, i1;
	for (i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(') break;
	}
	QString tmp = str.left(i);
	try {
		this->type = MessageSeverity::fromString(tmp);
	}
	catch (EXCEPTION ex) {
		throw ex;
	}

	++i;
	for (i1 = i + 1; i1 < str.size(); ++i1)
	{
		if (str[i1] == ')') break;
	}
	tmp = str.mid(i, i1 - i);
	//delete dateTime;
	QDateTime * dt;
	this->dateTime = QDateTime(QDateTime::fromString(tmp, "dd.MM.yyyy, hh:mm:ss"));
	if (dateTime.isNull())
	{
		throw IO_EXCEPTION;
	}
	i1 += 3;
	this->body = str.right(str.size() - i1);
}

QString TraceMessage::toString()
{
	QString out = type->toString() + "(";

	if (!dateTime.isValid())
	{
		dateTime.setDate(QDate::currentDate());
		dateTime.setTime(QTime::currentTime());
	}
	out += dateTime.toString("dd.MM.yyyy, hh:mm:ss");
	out += "): " + body;
	return out;
}

MessageSeverity TraceMessage::getType()
{
	return *type;
}
