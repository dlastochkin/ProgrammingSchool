#include "GraphicWidget.h"

GraphicWidget::GraphicWidget(int width, int height) : QMainWindow()
{
	QDesktopWidget* desktop = QApplication::desktop();  //
	this->setGeometry(500, 100, width, height);
	this->setMinimumSize(400, 500);// Окно

	this->setStyleSheet("background-color : QColor(0, 0, 35, 255);"); // цвет заднего фона

	centralFrame = new QFrame(this);							//
	centralLayout = new QVBoxLayout(centralFrame);			   //
	this->setCentralWidget(centralFrame);		              // Frame / Layout
	centralFrame->setLayout(centralLayout);	                 //

	centralLayout->setMargin(0);

	tabWidget = new QTabWidget(centralFrame);
	tabWidget->setStyleSheet("QTabWidget::pane { border: 0; }");
	centralLayout->addWidget(tabWidget);

	messageDisplay = new MessageDisplayWidget(); // Инициализация виджета вывода сообщений

	drawChatInterface();
}

void GraphicWidget::drawConnectionInterface()
{
	
}

void GraphicWidget::drawChatInterface()
{
	chatInterfaceFrame = new QFrame(+centralFrame);				
	chatInterfaceLayout = new QVBoxLayout(chatInterfaceFrame);

	QWidget* wid = new QWidget(this);

	tabWidget->addTab(wid, "aaaaaa");
	tabWidget->addTab(chatInterfaceFrame, "kkkkkk");

	//===========Название конференции / имя адресата и кнопка показа всех участников
	QHBoxLayout* confName_UsersButton = new QHBoxLayout(chatInterfaceFrame);
	QLabel* confName = new QLabel(conferenceName);
	confName->setStyleSheet("QLabel { background-color : QColor(0, 0, 25, 255); color: QColor(0, 0, 180, 255); padding: 0px 0px 0px 5px;}}");
	confName->setFont(QFont("Courier", 15, QFont::Bold));

	userListButton = new QPushButton("Users", chatInterfaceFrame);
	userListButton->setMinimumSize(60, 50);
	userListButton->setMaximumSize(100, 90);
	userListButton->setFont(QFont("Courier", 15, QFont::Bold));
	userListButton->setStyleSheet("QPushButton {background-color : QColor(0, 0, 25, 255); color: QColor(0, 0, 180, 255);}");

	confName_UsersButton->addWidget(confName);
	confName_UsersButton->addWidget(userListButton);
	chatInterfaceLayout->addLayout(confName_UsersButton);

	//===========Виджет вывода сообщений
	messageDisplay->setScrollArea(chatInterfaceFrame, chatInterfaceLayout);

	//===========Поле ввода текста и кнопка SEND===========================
	QHBoxLayout* sendButton_InputField = new QHBoxLayout(chatInterfaceFrame);
	sendButton = new QPushButton("Send", chatInterfaceFrame);
	sendButton->setMinimumHeight(40);
	sendButton->setMaximumSize(50, 45);
	sendButton->setFont(QFont("Courier", 13, QFont::Bold));
	sendButton->setStyleSheet("QPushButton {background-color : QColor(0, 0, 25, 255); color: QColor(0, 0, 180, 255);}");
	sendButton->connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));

	drawInputField(chatInterfaceFrame, sendButton_InputField);
	sendButton_InputField->addWidget(sendButton);
	chatInterfaceLayout->addLayout(sendButton_InputField);
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

void GraphicWidget::drawUserTable()
{
}

void GraphicWidget::setMessageAndUserName(QString message, QString username)
{
	messageText = message;
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
	messageDisplay->printMessage(messageText, userName);
}

GraphicWidget::~GraphicWidget()
{
}
