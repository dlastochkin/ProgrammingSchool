#pragma once
#include <QObject>
#include "AbstractTraceDestination.h"
#include "CChatTraceWidget.h"

class WidgetTraceDestination : public AbstractTraceDestination
{
	Q_OBJECT;
private:
	CChatTraceWidget* destinationWidget;
public:
	WidgetTraceDestination(CChatTraceWidget* destinationWidget, QObject* parent = nullptr);
	void putMessage(TraceMessage* message);
};