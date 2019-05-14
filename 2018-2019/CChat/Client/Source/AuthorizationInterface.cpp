#include "AuthorizationInterface.h"

AuthorizationInterface::AuthorizationInterface(QWidget* parent)
{
	connectionInterfaceFrame = new QFrame(parent);

	drawConnectionInterface();
}


AuthorizationInterface::~AuthorizationInterface()
{
}

void AuthorizationInterface::drawConnectionInterface()
{
	connectionInterfaceLayout = new QVBoxLayout(connectionInterfaceFrame);
	connectionInterfaceFrame->setLayout(connectionInterfaceLayout);
	connectionInterfaceLayout->setAlignment(Qt::AlignCenter);
	connectionInterfaceLayout->setSpacing(30);
	
	QLabel* chatName = new QLabel("   CChat",connectionInterfaceFrame);
	QFont chatNameFont("Arial", 30, QFont::Bold);
	chatName->setFont(chatNameFont);
	chatName->setFixedHeight(100);
	chatName->setStyleSheet("color : QColor(0, 0, 180, 255)");

	QTextEdit* userNameField = new QTextEdit(connectionInterfaceFrame);
	QFont fieldsFont("Arial", 15, QFont::Bold);
	userNameField->setFont(fieldsFont);
	userNameField->setStyleSheet("background-color : QColor(0, 0, 65, 255); border:0px solid black; color : QColor(0, 0, 180, 255);");
	userNameField->setPlaceholderText("Name");
	userNameField->setFixedSize(200,30);
	userNameField->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	userNameField->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	QTextEdit* portField = new QTextEdit(connectionInterfaceFrame);
	portField->setFont(fieldsFont);
	portField->setStyleSheet("background-color : QColor(0, 0, 65, 255); border:0px solid black; color : QColor(0, 0, 180, 255);");
	portField->setPlaceholderText("Port");
	portField->setFixedSize(200, 30);
	portField->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	portField->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	QTextEdit* ipField = new QTextEdit(connectionInterfaceFrame);
	ipField->setFont(fieldsFont);
	ipField->setStyleSheet("background-color : QColor(0, 0, 65, 255); border:0px solid black; color : QColor(0, 0, 180, 255);");
	ipField->setPlaceholderText("Ip");
	ipField->setFixedSize(200, 30);
	ipField->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ipField->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	 connectButton = new QPushButton("Connect",connectionInterfaceFrame);
	QFont buttonFont("Arial", 20, QFont::Bold);
	connectButton->setStyleSheet("background-color : QColor(0, 0, 25, 255); color : QColor(0, 0, 180, 255);");
	connectButton->setFixedHeight(40);
	connectButton->setFont(buttonFont);

	connectionInterfaceLayout->addWidget(chatName);
	connectionInterfaceLayout->addWidget(userNameField);
	connectionInterfaceLayout->addWidget(ipField);
	connectionInterfaceLayout->addWidget(portField);
	connectionInterfaceLayout->addWidget(connectButton);
}
