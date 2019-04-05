#include "MessageDisplayWidget.h"

MessageDisplayWidget::MessageDisplayWidget(int width, int height) : QMainWindow()
{

	// Необходимые для теста штучки
	//====================================================
	QDesktopWidget* desktop = QApplication::desktop(); //
	this->setGeometry(500, 100, width, height);		   // Окно

	QFrame* centralFrame = new QFrame(this);					//
	QVBoxLayout* centralLayout = new QVBoxLayout(centralFrame); //
	this->setCentralWidget(centralFrame);						// Frame / Layout
	centralFrame->setLayout(centralLayout);						//
	
	addScrollArea(centralFrame, centralLayout);	// Добавление ScrollArea

	message = new QLabel(scrollArea);

	message->setStyleSheet("QLabel { background-color : QColor(64, 64, 64, 255); color : white; }");


	QString messageText = "First message"; // Текст / Имя 					
	QString userName = "userName";      //

	printMessage(messageText, userName); //Вывод сообшения

	messageText = "Second message"; // Текст для 2 сообщения
	printMessage(messageText, userName); // Повторный вывод сообщения
	//====================================================
}

void MessageDisplayWidget::printMessage(QString messageText, QString userName)
{
	message->setText(messageText);

	scrollAreaLayout->addWidget(message);
}

void MessageDisplayWidget::addScrollArea(QFrame* parent, QVBoxLayout* layout)
{
	scrollArea = new QScrollArea(parent);
	scrollAreaLayout = new QVBoxLayout(scrollArea);

	layout->addWidget(scrollArea);

	scrollArea->setLayout(scrollAreaLayout);
}

void MessageDisplayWidget::clear()
{
}

MessageDisplayWidget::~MessageDisplayWidget()
{
}
