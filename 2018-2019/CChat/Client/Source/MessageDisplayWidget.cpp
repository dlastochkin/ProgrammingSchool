#include "MessageDisplayWidget.h"

MessageDisplayWidget::MessageDisplayWidget()
{
}

void MessageDisplayWidget::printMessage(QString messageText, QString userName)
{
	message->setText(messageText);
	std::cout << "!";
	scrollAreaLayout->addWidget(message);
}

void MessageDisplayWidget::setScrollArea(QFrame* parent, QVBoxLayout* layout)
{
	scrollArea = new QScrollArea(parent);
	scrollAreaLayout = new QVBoxLayout(scrollArea);

	layout->addWidget(scrollArea);

	scrollArea->setLayout(scrollAreaLayout);
	scrollArea->setStyleSheet("background-color : QColor(0, 0, 35, 255);");
	scrollArea->setFrameShape(QFrame::NoFrame);

	//message = new QLabel(scrollArea);

	//message->setStyleSheet("background-color : QColor(0, 0, 65, 255); color : black;");
}

void MessageDisplayWidget::clear()
{
}

MessageDisplayWidget::~MessageDisplayWidget()
{
}
