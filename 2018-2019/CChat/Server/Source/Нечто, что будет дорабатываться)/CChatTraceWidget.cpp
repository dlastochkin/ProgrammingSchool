#include "CChatTraceWidget.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>

void CChatTraceWidget::filterItems(QString text)
{
	if (text == "")
	{
		for (int row = 0; row < listWidget->count(); ++row)
		{
			(listWidget->item(row))->setHidden(false);
		}
		return;
	}
	for (int row = 0; row < listWidget->count(); ++row)
	{
		if ((listWidget->item(row))->data(Qt::UserRole) == QVariant(text))
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
	filter->addItem("");
	filter->addItem("DEBUG");
	filter->addItem("EVENT");
	filter->addItem("WARNING");
	filter->addItem("ERROR");
	filter->connect(filter, SIGNAL(activated(QString)), this, SLOT(filterItems(QString)));
	layout->addWidget(filter);

	//message list
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
		item->setData(Qt::UserRole, QVariant("DEBUG"));
		break;
	case MessageSeverity::EVENT:
		item->setForeground(QBrush(QColor(0, 0, 128)));
		item->setData(Qt::UserRole, QVariant("EVENT"));
		break;
	case MessageSeverity::WARNING:
		item->setForeground(QBrush(QColor(240, 192, 0)));
		item->setData(Qt::UserRole, QVariant("WARNING"));
		break;
	case MessageSeverity::ERROR:
		item->setForeground(QBrush(QColor(255, 0, 0)));
		item->setData(Qt::UserRole, QVariant("ERROR"));
		break;
	}
	listWidget->addItem(item);
}

