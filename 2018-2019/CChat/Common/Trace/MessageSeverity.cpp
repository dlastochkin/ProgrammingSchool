#include "MessageSeverity.h"

MessageSeverity const* MessageSeverity::DEBUG = MessageSeverity::initDebug();
MessageSeverity const* MessageSeverity::EVENT = MessageSeverity::initEvent();
MessageSeverity const* MessageSeverity::WARNING = MessageSeverity::initWarning();
MessageSeverity const* MessageSeverity::ERROR = MessageSeverity::initError();

MessageSeverity* MessageSeverity::initDebug()
{
	return new MessageSeverity(0);
}

MessageSeverity* MessageSeverity::initEvent()
{
	return new MessageSeverity(1);
}

MessageSeverity* MessageSeverity::initWarning()
{
	return new MessageSeverity(2);
}

MessageSeverity* MessageSeverity::initError()
{
	return new MessageSeverity(3);
}

QString MessageSeverity::toString() const
{
	//int code = this->toInt();
	switch (code)
	{
	case 0:
		return "DEBUG";
	case 1:
		return "EVENT";
	case 2:
		return "WARNING";
	case 3:
		return "ERROR";
	default:
		return "";
	}
}

bool MessageSeverity::equals(MessageSeverity const* other)
{
	//return this->toInt() == other.toInt();
	return this->code == other->code;
}

/*int MessageSeverity::isMoreSevere(MessageSeverity const* other)
{
	return this->code > other->code ? 1 : (equals(other) ? 0 : -1);
}*/

MessageSeverity const* MessageSeverity::fromString(QString str)
{
	str = str.toUpper();
	if (str == "DEBUG")
	{
		return DEBUG;
	}
	else if (str == "EVENT")
	{
		return EVENT;
	}
	else if (str == "WARNING")
	{
		return WARNING;
	}
	else if (str == "ERROR")
	{
		return ERROR;
	}
	else
	{
		throw TRACE_PARSE_EXCEPTION;
	}
}