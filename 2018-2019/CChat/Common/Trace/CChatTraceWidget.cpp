#include "CChatTraceWidget.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>

void CChatTraceWidget::filterItems(int severity)
{
	for (int row = 0; row < listWidget->count(); ++row)
	{
		if (((listWidget->item(row)->data(Qt::UserRole))) >= severity)
		{
			(listWidget->item(row))->setHidden(false);
		}
		else
		{
			(listWidget->item(row))->setHidden(true);
		}
	}
}

CChatTraceWidget::CChatTraceWidget(QWidget* parent) : QWidget(parent)
{
	listWidget = new QListWidget(this);
	this->initialize();
}

void CChatTraceWidget::initialize()
{
	QVBoxLayout* layout = new QVBoxLayout(this);
	this->setLayout(layout);

	//filter
	QComboBox* filter = new QComboBox(this);
	//filter->addItem("");
	filter->addItem("DEBUG");
	filter->addItem("EVENT");
	filter->addItem("WARNING");
	filter->addItem("ERROR");
	filter->connect(filter, SIGNAL(highlighted(int)), this, SLOT(filterItems(int)));
	layout->addWidget(filter);

	//message list
	layout->addWidget(listWidget);
}

void CChatTraceWidget::TraceMessageToQListWidgetItem(TraceMessage* message)
{
	QListWidgetItem* item = new QListWidgetItem();
	item->setText(message->toString());
	MessageSeverity type = message->getType();
	if (type.equals(MessageSeverity::DEBUG))
	{
		item->setForeground(QBrush(QColor(128, 128, 128)));
		item->setData(Qt::UserRole, 0);
	}
	else if (type.equals(MessageSeverity::EVENT))
	{
		item->setForeground(QBrush(QColor(0, 0, 128)));
		item->setData(Qt::UserRole, 1);
	}
	else if (type.equals(MessageSeverity::WARNING))
	{
		item->setForeground(QBrush(QColor(224, 168, 0)));
		item->setData(Qt::UserRole, 2);
	}
	else if (type.equals(MessageSeverity::ERROR))
	{
		item->setForeground(QBrush(QColor(192, 0, 0)));
		item->setData(Qt::UserRole, 3);
	}
	listWidget->addItem(item);
}

