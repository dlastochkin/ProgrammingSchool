#include "GraphicWidget.h"

GraphicWidget::GraphicWidget(QWidget* parent, QString name, int id)
{
	graphicWidget = new QFrame(parent);						   //
	centralLayout = new QVBoxLayout(graphicWidget);			  // Frame / Layout		          
	graphicWidget->setLayout(centralLayout);	             //

	messageDisplay = new MessageDisplayWidget(); // Инициализация виджета вывода сообщений

	conferenceName = name;

	drawChatInterface();
}

void GraphicWidget::drawChatInterface()
{
	//===========Название конференции / имя адресата и кнопка показа всех участников
	QHBoxLayout* confName_UsersButton = new QHBoxLayout(graphicWidget);
	QLabel* confName = new QLabel(conferenceName);
	confName->setStyleSheet("QLabel { background-color : QColor(0, 0, 25, 255); color: QColor(0, 0, 180, 255); padding: 0px 0px 0px 5px;}}");
	confName->setFont(QFont("Courier", 15, QFont::Bold));

	userListButton = new QPushButton("Users", graphicWidget);
	userListButton->setMinimumSize(60, 50);
	userListButton->setMaximumSize(100, 90);
	userListButton->setFont(QFont("Courier", 15, QFont::Bold));
	userListButton->setStyleSheet("QPushButton {background-color : QColor(0, 0, 25, 255); color: QColor(0, 0, 180, 255);}");

	confName_UsersButton->addWidget(confName);
	confName_UsersButton->addWidget(userListButton);
	centralLayout->addLayout(confName_UsersButton);

	//===========Виджет вывода сообщений
	messageDisplay->setScrollArea(graphicWidget, centralLayout);

	//===========Поле ввода текста и кнопка SEND===========================
	QHBoxLayout* sendButton_InputField = new QHBoxLayout(graphicWidget);
	sendButton = new QPushButton("Send", graphicWidget);
	sendButton->setMinimumHeight(40);
	sendButton->setMaximumSize(50, 45);
	sendButton->setFont(QFont("Courier", 13, QFont::Bold));
	sendButton->setStyleSheet("QPushButton {background-color : QColor(0, 0, 25, 255); color: QColor(0, 0, 180, 255);}");
	connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));

	drawInputField(graphicWidget, sendButton_InputField);
	sendButton_InputField->addWidget(sendButton);
	centralLayout->addLayout(sendButton_InputField);
}

void GraphicWidget::drawInputField(QFrame* parent, QHBoxLayout* layout)
{
	QScrollBar* scroll = new QScrollBar(parent);
	inputField = new QTextEdit(parent);
	layout->addWidget(inputField);
	inputField->setPlaceholderText("Enter your message...");
	inputField->setMinimumSize(100, 30);
	inputField->setMaximumHeight(40);
	inputField->setFont(QFont("Courier", 9, QFont::Bold));
	inputField->setVerticalScrollBar(scroll);
	inputField->setStyleSheet("QTextEdit {background-color : QColor(0, 0, 65, 255); color : QColor(0, 0, 180, 255);}");
	inputField->setFrameShape(QFrame::NoFrame);
}

void GraphicWidget::setMessageAndUserName(QString message, QString username)
{
	messageText = message;
	userName = username;
}

void GraphicWidget::setUserName(QString username)
{
	userName = username;
}

QString GraphicWidget::sendMessage()
{
	messageText = inputField->toPlainText();
	//if (!messageText.isEmpty())
	{
		setMessageAndUserName(messageText, userName);
		printMessage();
		inputField->clear();
	}

	return messageText;
}

void GraphicWidget::printMessage()
{
	messageDisplay->printMessage(messageText, userName, true);
}

GraphicWidget::~GraphicWidget()
{
}
