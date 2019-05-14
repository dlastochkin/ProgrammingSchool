#include "Hub.h"

Hub::Hub(QWidget* parent, QString userName)
{
	hubInterfaceFrame = new QFrame(parent);

	this->userName = userName;

	drawHubInterface();
}

void Hub::drawHubInterface()
{
	hubInterfaceLayout = new QVBoxLayout(hubInterfaceFrame);
	hubInterfaceFrame->setLayout(hubInterfaceLayout);
	hubInterfaceLayout->setAlignment(Qt::AlignCenter);
	hubInterfaceLayout->setSpacing(30);

	QLabel* userNameLabel = new QLabel(userName, hubInterfaceFrame);
	QFont chatNameFont("Arial", 20, QFont::Bold);
	userNameLabel->setAlignment(Qt::AlignCenter);
	userNameLabel->setFont(chatNameFont);
	userNameLabel->setFixedHeight(100);
	userNameLabel->setStyleSheet("color : QColor(0, 0, 180, 255)");

	usersListWidget = new QListWidget(hubInterfaceFrame);
	usersListWidget->addItems(usersList);
	usersListWidget->setFixedWidth(300);
	

	hubInterfaceLayout->addWidget(userNameLabel);
	hubInterfaceLayout->addWidget(usersListWidget);
}

Hub::~Hub()
{
}