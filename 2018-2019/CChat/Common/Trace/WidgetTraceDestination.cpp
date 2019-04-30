#include "WidgetTraceDestination.h"

WidgetTraceDestination::WidgetTraceDestination(CChatTraceWidget* destinationWidget, QObject* parent)
{
	this->destinationWidget = destinationWidget;
}

void WidgetTraceDestination::putMessage(TraceMessage* message)
{
	destinationWidget->TraceMessageToQListWidgetItem(message);
}
