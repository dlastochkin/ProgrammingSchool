#pragma once
#include "CChatTrace.h"
#include <fstream>

TraceMessage::TraceMessage(QString body, MessageSeverity type = EVENT, dateType dtype = INTERNATIONAL, QDateTime dateTime = NULL)
{
	this->body = body;
	this->type = type;
	if (dateTime.isValid())
	{
		this->dtype = dt;
	}
	else
	{
		dt = QDateTime::CurrentDayTime();
	}
	this->dtype = dtype;
}

void TraceMessage::setDateType(dateType dtype)
{
	this->dtype = dtype;
}

QString TraceMessage::out()
{
	QString out;
	switch (type)
	{
	case EVENT:
		out += "(";
		break;
	case WARNRNG:
		out += "Warning:(";
		break;
	case ERROR:
		out += "Error:(";
		break;
	}

	switch (dtype)
	{
	case INTERNATIONAL:
		out += dt.toString("dd-MM-yyyy, hh:mm:ss");
			break;
	case USA:
		out += dt.toString("MM-dd-yyyy, hh:mm:ss");
			break;
	case GERMANY:
		out += dt.toString("dd.MM.yyyy, hh:mm:ss");
			break;
	case UK:
		out += dt.toString("dd/MM/yyyy, hh:mm:ss");
			break;
	case HUNGARY:
		out += dt.toString("yyyy-MM-dd, hh:mm:ss");
			break;
	}

	out += ") " + body;
	return out;
}

TraceMessage::~TraceMessage(){}


CChatTrace::CChatTrace(QWidget* parent = nullptr, QString filename, dateType dtype = INTERNATIONAL) : QWidget(parent)
{
	this->filename = "trace" + filename + ".log";
	this->dtype = dtype;
}

void CChatTrace::import()
{
	string s, s1;
	MessageSeverity mtype;
	ifstream in(filename);
	if (in.is_open())
	{
		while (getline(in, s))
		{
			int i = 0;
			while (s[i] != '(') ++i;
			s1 = s.substr(0, i);
			if (s1 == "")
			{
				mtype = EVENT;
			}
			else if (s1 == "W:")
			{
				mtype = WARNING;
			}
			else if (s1 == "E:")
			{
				mtype = ERROR;
			}
			else
			{
				TraceMessage* mt = new TraceMessage("Import error", ERROR);
				return;
			}
			int i1 = i + 1;
			while (s[i] != ')') ++i;
			s1 = s.substr(i1, i-i1);
			QDateTime dt;
			switch (dtype)
			{
			case INTERNATIONAL:
				dt = QDateTime::fromString(s1, "dd-MM-yyyy, hh:mm:ss");
				break;
			case USA:
				dt = QDateTime::fromString(s1, "MM-dd-yyyy, hh:mm:ss");
				break;
			case GERMANY:
				dt = QDateTime::fromString(s1, "dd.MM.yyyy, hh:mm:ss");
				break;
			case UK:
				dt = QDateTime::fromString(s1, "dd/MM/yyyy, hh:mm:ss");
				break;
			case HUNGARY:
				dt = QDateTime::fromString(s1, "yyyy-MM-dd, hh:mm:ss");
				break;
			}
			i1 = min(i + 2), s.size()-1;
			s1 = s.substr(i1, s.size() - i1 - 1);
			list.insert(TraceMessage(s1, mtype, dtype, dt));
		}
	}
}

void CChatTrace::transmit(TraceMessage message)
{
	//does nothing yet...
}

void CChatTrace::add(QString ms, MessageSeverity type)
{
	TraceMessage mt(ms, type, dtype);
	list.insert(mt);
	transmit(mt);
}

void CChatTrace::setDateType(dateType dtype)
{
	this->dtype = dtype;
}

CChatTrace::~CChatTrace()
{
	while (list.size() > 0)
		delete(list.pop_front());
}