#pragma once
#include <QObject>
#include "TraceMessage.h"
#include <iostream>

TraceMessage::TraceMessage(QString body, int type, QDateTime* dateTime, QObject* parent) : QObject(parent)
{
	this->body = body;
	this->type = type;
	if (dateTime == nullptr)
	{
		this->dateTime = new QDateTime(QDate::currentDate(), QTime::currentTime());
	}
	else
	{
		if (dateTime->isValid())
		{
			this->dateTime = dateTime;
		}
		else
		{
			this->dateTime->setDate(QDate::currentDate());
			this->dateTime->setTime(QTime::currentTime());
		}
	}
}

QString TraceMessage::toString()
{
	QString out;
	switch (type)
	{
	case MessageSeverity::DEBUG:
		out += "Debug(";
		break;
	case MessageSeverity::EVENT:
		out += "Event(";
		break;
	case MessageSeverity::WARNING:
		out += "Warning(";
		break;
	case MessageSeverity::ERROR:
		out += "Error(";
		break;
	}
	if (dateTime != nullptr)
	{
		if (!dateTime->isValid())
		{
			dateTime->setDate(QDate::currentDate());
			dateTime->setTime(QTime::currentTime());
		}
	}
	else
	{
		dateTime = new QDateTime(QDate::currentDate(), QTime::currentTime());
	}
	out += dateTime->toString("dd.MM.yyyy, hh:mm:ss");
	out += "): " + body;
	return out;
}

bool TraceMessage::fromString(QString str)
{
	int i, i1;
	for (i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(') break;
	}
	QString tmp = str.left(i);
	if (tmp == "Debug")
	{
		type = MessageSeverity::DEBUG;
	}
	else if (tmp == "Event")
	{
		type = MessageSeverity::EVENT;
	}
	else if (tmp == "Warning")
	{
		type = MessageSeverity::WARNING;
	}
	else if (tmp == "Error")
	{
		type = MessageSeverity::ERROR;
	}
	else
	{
		body = "Parse failed";
		type = MessageSeverity::ERROR;
		dateTime->setDate(QDate::currentDate());
		dateTime->setTime(QTime::currentTime());
		return false;
	}
	++i;
	for (i1 = i + 1; i1 < str.size(); ++i1)
	{
		if (str[i1] == ')') break;
	}
	tmp = str.mid(i, i1 - i);
	//delete dateTime;
	QDateTime* dt;
	dt = new QDateTime(QDateTime::fromString(tmp, "dd.MM.yyyy, hh:mm:ss"));
	dateTime = dt;
	if (dateTime->isNull())
	{
		body = "Parse failed";
		type = MessageSeverity::ERROR;
		dateTime->setDate(QDate::currentDate());
		dateTime->setTime(QTime::currentTime());
		return false;
	}
	i1 += 3;
	body = str.right(str.size()-i1);
	return true;
}

int TraceMessage::getType()
{
	return type;
}
