Пример использования - копия main.cpp проекта, который включает в себя создание QApplication и QMainWindow;
Их использование обязательно для работы примера, но опционально для работы трассы в Вашем проекте.

<code>
	/*!
	Example of how do CChatTrace and CChatTraceWidget work
	*/
	//! Base includes
	#include <QtCore/QCoreApplication> 
	#include <QApplication>
	#include <QMainWindow>
	#include <QWidget>
	//! Required includes for Trace
	#include "CChatTrace.h"
	//! Required includes for TraceWidget
	#include "WidgetTraceDestination.h"
	#include "CChatTraceWidget.h"
	//! Optional include for file destination
	#include "FileTraceDestination.h"

	int main(int argc, char *argv[])
	{
		//! Items required for a test launch
		QApplication app(argc, argv); 

		QMainWindow* mw = new QMainWindow(); 
		mw->setGeometry(200, 200, 800, 600);

		//! Trace implementation
		CChatTrace* trace = new CChatTrace();
		trace->import("traceImport.txt"); //! import, obviously; can be imported from and transmitted to the same file

		//! File destination implementation
		FileTraceDestination* fdest = new FileTraceDestination("traceExport.txt");
		trace->addDestination(fdest); /*! from this moment, Trace transmits every message that it gets
									  (or already has) to file*/
		//! Widget 
		CChatTraceWidget* widget = new CChatTraceWidget();//! without destination, Widget does not work properly!
		mw->setCentralWidget(widget);
		
		//! Widget destination implementation
		WidgetTraceDestination* wdest = new WidgetTraceDestination(widget);
		trace->addDestination(wdest);/*! from this moment, Trace transmits every message that it gets
									  (or already has) to TraceWidget*/
		
		trace->add("This is debug message. Dunno for what...", MessageSeverity::DEBUG); //! Example of debug message
		trace->add("This is event: something happened!", MessageSeverity::EVENT); //! Example of event message
		trace->add("This is warning: something can be not correct if you see this!", MessageSeverity::WARNING); //! Example of warning message
		trace->add("This is error: is you see this, something has crashed...", MessageSeverity::ERROR); //! Example of error message

		//! Items required for a test launch
		mw->show();
		app.exec();
		return 0;
	}
</code>
