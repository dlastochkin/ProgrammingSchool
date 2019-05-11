#pragma once
#include <QVariant>
#include "..\\Exceptions.h"

class MessageSeverity;

class MessageSeverity : public QVariant
{
private:
	int code;
	MessageSeverity(int code) : QVariant(code) { this->code = code; }
	static MessageSeverity* initDebug();
	static MessageSeverity* initEvent();
	static MessageSeverity* initWarning();
	static MessageSeverity* initError();

public:
	static MessageSeverity const* DEBUG;
	static MessageSeverity const* EVENT;
	static MessageSeverity const* WARNING;
	static MessageSeverity const* ERROR;

	static MessageSeverity const* fromString(QString str);
	QString toString() const;
	bool equals(MessageSeverity const* other);
	//int is(MessageSeverity const* other);
};


//#define DEBUG_INIT nullptr; static int tDebug = MessageSeverity::DEBUG_INIT_IMPL()
//#define EVENT_INIT nullptr; static int tEvent = MessageSeverity::EVENT_INIT_IMPL()
//#define WARNING_INIT nullptr; static int tWarning = MessageSeverity::WARNING_INIT_IMPL()
//#define ERROR_INIT nullptr; static int tError = MessageSeverity::ERROR_INIT_IMPL()
//
//	DEBUG = DEBUG_INIT;
//	EVENT = EVENT_INIT;
//	WARNING = WARNING_INIT;
//	ERROR = ERROR_INIT;