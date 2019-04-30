#include "ClientGraphic.h"

ClientGraphic::ClientGraphic(int width, int height) : QMainWindow()
{
	QDesktopWidget* desktop = QApplication::desktop();  //
	this->setGeometry(500, 100, width, height);	
	this->setMinimumSize(400, 500);// Окно

	this->setStyleSheet("background-color : QColor(0, 0, 35, 255);"); // 

	centralFrame = new QFrame(this);				//
	centralLayout = new QVBoxLayout(centralFrame); //
	this->setCentralWidget(centralFrame);		  // Frame / Layout
	centralFrame->setLayout(centralLayout);		 //

	messageDisplay = new MessageDisplayWidget(); // Инициализация виджета вывода сообщений

	drawChatInterface();

	setMessageAndUserName("Hello, how are you doing? I will fsdjk fsdjk fnsdjk fnsdjk fndsjk", "djklsamndas");
	printMessage();
	setMessageAndUserName("Hek fnsdjk be so happy to see you today! ", "djklsamndas");
	printMessage();
	setMessageAndUserName("f","fadfdsfda");
	printMessage();
	setMessageAndUserName("f f f f f f f f f f f f f f f f f f f f f f f f", "djklsamndas");
	printMessage();
}

void ClientGraphic::drawConnectionInterface()
{
}

void ClientGraphic::drawChatInterface()
{
	//===========Название конференции / имя адресата и кнопка показа всех участников
	QHBoxLayout* confName_UsersButton = new QHBoxLayout(centralFrame);
	QLabel* confName = new QLabel(" Conference name");
	confName->setStyleSheet("QLabel { background-color : QColor(0, 0, 25, 255); color: QColor(0, 0, 180, 255);}");
	confName->setFont(QFont("Courier", 15, QFont::Bold));

	userListButton = new QPushButton("Users",centralFrame);
	userListButton->setMinimumSize(60, 50);
	userListButton->setMaximumSize(100,90);
	userListButton->setFont(QFont("Courier", 15, QFont::Bold));
	userListButton->setStyleSheet("QPushButton {background-color : QColor(0, 0, 25, 255); color: QColor(0, 0, 180, 255);}");
	//userListButton->setMenu(NULL); //попытка сделать выпадающее меню 
	//userListButton->menu();		 //

	confName_UsersButton->addWidget(confName);
	confName_UsersButton->addWidget(userListButton);
	centralLayout->addLayout(confName_UsersButton);

	//===========Виджет вывода сообщений
	messageDisplay->setScrollArea(centralFrame, centralLayout);

	//===========Поле ввода текста и кнопка SEND===========================
	QHBoxLayout* sendButton_InputField = new QHBoxLayout(centralFrame);
	sendButton = new QPushButton("Send",centralFrame);
	sendButton->setMinimumHeight(40);
	sendButton->setMaximumSize(50, 45);
	sendButton->setFont(QFont("Courier", 13, QFont::Bold));
	sendButton->setStyleSheet("QPushButton {background-color : QColor(0, 0, 25, 255); color: QColor(0, 0, 180, 255);}");
	//sendButton->connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));

	drawInputField(centralFrame, sendButton_InputField);
	sendButton_InputField->addWidget(sendButton);
	centralLayout->addLayout(sendButton_InputField);
}

void ClientGraphic::drawInputField(QFrame* parent, QHBoxLayout* layout)
{
	QScrollBar* scroll = new QScrollBar(parent);
	inputField = new QTextEdit(parent);
	layout->addWidget(inputField);
	inputField->setPlaceholderText("Enter your message...");
	inputField->setMinimumSize(100,30);
	inputField->setMaximumHeight(40);
	inputField->setFont(QFont("Courier", 9, QFont::Bold));
	inputField->setVerticalScrollBar(scroll);
	inputField->setStyleSheet("QTextEdit {background-color : QColor(0, 0, 65, 255); color : QColor(0, 0, 180, 255);}");
	inputField->setFrameShape(QFrame::NoFrame);
}

void ClientGraphic::drawUserTable()
{
}

void ClientGraphic::setMessageAndUserName(QString message, QString username)
{
	messageText = message;
	userName = username;
}

void ClientGraphic::sendMessage()
{
	messageText = inputField->toPlainText();
	setMessageAndUserName(messageText, "aaaa");
	printMessage();
	inputField->clear();
}

void ClientGraphic::printMessage()
{
	messageDisplay->printMessage(messageText, userName);
}

ClientGraphic::~ClientGraphic()
{
}