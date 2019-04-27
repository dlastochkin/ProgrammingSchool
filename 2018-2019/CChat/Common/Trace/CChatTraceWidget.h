#pragma once
#include <QWidget>
#include <QListWidget>
#include "TraceMessage.h"


class CChatTraceWidget : public QWidget
{
	Q_OBJECT;

private:
	QListWidget* listWidget;
private slots:
	void filterItems(QString text);
public:
	CChatTraceWidget(QWidget* parent = nullptr);
	void initialize();
	void TraceMessageToQListWidgetItem(TraceMessage* message);
};
