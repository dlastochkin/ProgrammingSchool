#include "CChatTraceWidget.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>

CChatTraceWidget::CChatTraceWidget(QWidget* parent) : QWidget(parent)
{
	this->initialize();
}

void CChatTraceWidget::initialize()
{
	QVBoxLayout* layout = new QVBoxLayout(this);
	this->setLayout(layout);

	//filter
	QFrame* someshitframe = new QFrame(this);
	someshitframe->setStyleSheet("background-color:red");
	layout->addWidget(someshitframe);

	//message list
	listWidget = new QListWidget(this);
	layout->addWidget(listWidget);
}

void CChatTraceWidget::TraceMessageToQListWidgetItem(TraceMessage* message)
{
	QListWidgetItem* item = new QListWidgetItem();
	item->setText(message->toString());
	int type = message->getType();
	switch (type)
	{
	case MessageSeverity::DEBUG:
		item->setForeground(QBrush(QColor(0, 192, 0)));
		break;
	case MessageSeverity::EVENT:
		item->setForeground(QBrush(QColor(0, 0, 128)));
		break;
	case MessageSeverity::WARNING:
		item->setForeground(QBrush(QColor(240, 192, 0)));
		break;
	case MessageSeverity::ERROR:
		item->setForeground(QBrush(QColor(255, 0, 0)));
		break;
	}
	listWidget->addItem(item);
}

