#include "C:\Users\kompass\Documents\GitHub\ProgrammingSchool\2018-2019\CChat\Client\Source\MessageDisplayWidget.h"

MessageDisplayWidget::MessageDisplayWidget(int width, int height)
{
	QDesktopWidget* desktop = QApplication::desktop();
	//this->setGeometry(width, height);

	this->setGeometry(100, 100, width, height);

	QFrame* centralFrame = new QFrame;
	this->setCentralWidget(centralFrame);

	addScrollArea();
}

MessageDisplayWidget::~MessageDisplayWidget()
{

}

void MessageDisplayWidget::printMessage(QString messageText, QString * userName, QScrollArea* scrollArea)
{
	QTextEdit* message = new QTextEdit(scrollArea);
	message->setText(messageText);
	scrollArea->setWidget(message);
}

void MessageDisplayWidget::setMessageBackground(QColor * color)
{
}

void MessageDisplayWidget::clear()
{
}

void MessageDisplayWidget::addScrollArea(QFrame * parent, QHBoxLayout * layout)
{
	scrollArea = new QScrollArea(parent);

	layout->addWidget(scrollArea);

	scrollArea->setStyleSheet("background-color: yellow");
}
