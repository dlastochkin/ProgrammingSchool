#include <QtCore/QCoreApplication>

#include "CChatTrace.h"
#include "FileTraceDestination.h"

int main(int argc, char *argv[])
{
	CChatTrace* trace = new CChatTrace();
	trace->import("trace.txt");
	FileTraceDestination* fdest = new FileTraceDestination("trace.txt");
	trace->addDestination(fdest);
	trace->add("kek", MessageSeverity::DEBUG);
	trace->add("ALARM!! SPOILERS!!!", MessageSeverity::WARNING);
	trace->add("Max is gay", MessageSeverity::EVENT);
	return 0;
}