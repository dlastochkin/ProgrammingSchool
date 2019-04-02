#include "CChatTrace.h"
#include <fstream>
using namespace std;

CChatTrace::CChatTrace(QObject* parent) : QObject(parent) {}

void CChatTrace::import()
{/*
	string s, s1;
	MessageSeverity mtype;
	ifstream in;
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
			QDateTime dateTime;

			dateTime = QDateTime::fromString(s1, "dd.MM.yyyy, hh:mm:ss");
			i1 = min(i + 2, s.size()-1);
			s1 = s.substr(i1, s.size() - i1 - 1);
			list.insert(TraceMessage(s1, mtype, dateTime));
		}
	}
	//does not work yet...
	*/
}

void CChatTrace::transmit(TraceMessage message)
{
	//does nothing yet...
}

void CChatTrace::add(QString ms, MessageSeverity type)
{
	TraceMessage mt(ms, type);
	messageList.append(mt);
	//messageList.insert(messageList.end(), mt);
	emit messageListUpdated();
}

CChatTrace::~CChatTrace()
{
	while (messageList.isEmpty())
		messageList.removeFirst();
}