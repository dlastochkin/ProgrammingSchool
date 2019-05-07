#include <QtCore/QCoreApplication>
#include "CChatServer.h"
#include <QApplication>
#include <QMainWindow>
#include "CChatTrace.h"
#include "WidgetTraceDestination.h"
#include "FileTraceDestination.h"
#include "CChatTraceWidget.h"
#include <stdexcept>


int test(int a, int b)
{
	if (b == 0)
	{
		throw NULL_MESSAGE_EXCEPTION;
	}

	return a / b;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QMainWindow* mw = new QMainWindow();
	CChatTrace* trace = new CChatTrace();
	CChatTraceWidget* widget = new CChatTraceWidget(mw);
	mw->setCentralWidget(widget);
	trace->import("trace.txt");

	WidgetTraceDestination* wdest = new WidgetTraceDestination(widget);
	FileTraceDestination* fdest = new FileTraceDestination("trace.txt");
	trace->addDestination(wdest);
	trace->addDestination(fdest);
	mw->show();

	trace->add("Debugovskiy kek", MessageSeverity::DEBUG);
	trace->add("Debugovskiy kek", MessageSeverity::DEBUG);
	trace->add("Eventovskiy kek", MessageSeverity::EVENT);
	trace->add("Eventovskiy kek", MessageSeverity::EVENT);
	//system("pause");
	trace->add("Warningovskiy kek", MessageSeverity::WARNING);
	trace->add("Warningovskiy kek", MessageSeverity::WARNING);

	trace->add("Errorovskiy kek", MessageSeverity::ERROR);
	trace->add("Errorovskiy kek", MessageSeverity::ERROR);

	try
	{
		test(5, 0);
	}
	catch (EXCEPTION e)
	{
		trace->add(e, MessageSeverity::ERROR);
	}



	/*
	try
	{
		sendMessage("Jarracsus");
	}
	catch (EXCEPTION e)
	{
		trace->add(e, MessageSeverity::ERROR);
	}*/
	
	
	
	


	return a.exec();
}
