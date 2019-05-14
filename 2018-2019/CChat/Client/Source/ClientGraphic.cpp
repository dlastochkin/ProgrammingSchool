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

	centralLayout->setMargin(0);

	tabWidget = new QTabWidget(centralFrame);
	tabWidget->setStyleSheet("QTabWidget::pane { border: 0; }");
	centralLayout->addWidget(tabWidget);
	
	AI = new AuthorizationInterface(this);

	tabWidget->addTab(AI->connectionInterfaceFrame, "Authorization");
	connect(AI, SIGNAL(connectToServer(QString, QString, quint16)), this, SLOT(tryToConnect()));

}

void ClientGraphic::tryToConnect(QString name, QString ip, quint16 port)
{
	emit connectTrying(name, ip, port);
}

void ClientGraphic::createDialog(QString userName)
{
	GraphicWidget* user = new GraphicWidget(tabWidget, userName, 0);
	user->setUserName(userName);
	tabWidget->addTab(user->graphicWidget, userName);
}

/*
void ClientGraphic::authorizationIsEnd()
{
	//if (clientConnected)
	{
		tabWidget->removeTab(0);
		hub = new Hub(centralFrame, userName);
		tabWidget->addTab(hub->hubInterfaceFrame, "Hub");
		connect(hub->usersListWidget, SIGNAL(itemSelectionChanged()), this, SLOT(addUser("kkkkk")));
	}
}

*/

ClientGraphic::~ClientGraphic()
{

}