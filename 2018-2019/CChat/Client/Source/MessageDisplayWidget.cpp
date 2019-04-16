#include "MessageDisplayWidget.h"

MessageDisplayWidget::MessageDisplayWidget()
{
}

void MessageDisplayWidget::printMessage(QString messageText, QString userName)
{
	QFrame* messageFrame = new QFrame(scrollArea);
	QHBoxLayout* messageLayout = new QHBoxLayout(messageFrame);
	QLabel* message = new QLabel(messageFrame);
	QWidget* placeHolder = new QWidget(messageFrame);

	message->setText(messageText);
	messageLayout->addWidget(message);
	messageLayout->addWidget(placeHolder);

	message->setStyleSheet("background-color : QColor(0, 0, 65, 255); color : black;");
	message->setFont(QFont("Courier", 13, QFont::Bold));
	//message->setSiz

	scrollAreaLayout->addWidget(messageFrame);
}

void MessageDisplayWidget::setScrollArea(QFrame* parent, QVBoxLayout* layout)
{
	scrollArea = new QScrollArea(parent);
	scrollAreaLayout = new QVBoxLayout(scrollArea);

	layout->addWidget(scrollArea);

	scrollArea->setLayout(scrollAreaLayout);
	scrollArea->setStyleSheet("background-color : QColor(0, 0, 35, 255);");
	scrollArea->setFrameShape(QFrame::NoFrame);
}

void MessageDisplayWidget::clear()
{
}

MessageDisplayWidget::~MessageDisplayWidget()
{
}
