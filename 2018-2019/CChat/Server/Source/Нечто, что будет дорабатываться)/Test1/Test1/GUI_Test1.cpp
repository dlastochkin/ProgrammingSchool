#include "GUI_Test1.h"
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextStream>
#include <QApplication>
#include <QLabel>

ServerGUI::ServerGUI(int width, int height) : QMainWindow()
{
	QDesktopWidget* desktop = QApplication::desktop();

	int deskW = desktop->width();
	int deskH = desktop->height();

	int maxWidth = width > deskW ? deskW : width;
	int maxHeight = height > deskH ? deskH : height;

	int x = deskW / 2 - (width > deskW ? maxWidth : width) / 2;
	int y = deskH / 2 - (height > deskH ? maxHeight : height) / 2;
	this->setGeometry(x, y, width, height);

	this->initialize();
}



void ServerGUI::initialize()
{
	QFrame* centralFrame = new QFrame(this);
	this->setCentralWidget(centralFrame);

	listUsersName = new QListWidget();

	port = new QTextEdit();
	

	QHBoxLayout* centralframeLayout = new QHBoxLayout(centralFrame);

	QVBoxLayout* dialogAndStartButtonLayout = new QVBoxLayout;
	dialogAndStartButtonLayout->setMargin(0);

	QVBoxLayout* listOfConnectedAndButtonsLayout = new QVBoxLayout;
	listOfConnectedAndButtonsLayout->setMargin(0);

	centralframeLayout->addLayout(dialogAndStartButtonLayout);
	centralframeLayout->addLayout(listOfConnectedAndButtonsLayout);
	dialogAndStartButtonLayout->setAlignment(Qt::AlignCenter);
	listOfConnectedAndButtonsLayout->setAlignment(Qt::AlignCenter);

	withWhomDialog = new QLabel(" ");
	withWhomDialog->setEnabled(false);
	dialogAndStartButtonLayout->addWidget(withWhomDialog);

	QHBoxLayout* portLayout = new QHBoxLayout;
	portLayout->setMargin(0);

	QLabel* label = new QLabel(" PORT: ");
	portLayout->addWidget(label);
	label->setFixedHeight(15);
	label->setFixedWidth(50);
	label->setAlignment(Qt::AlignRight);

	port = new QTextEdit;
	portLayout->addWidget(port);
	port->setFixedHeight(25);
	port->setFixedWidth(150);
	port->setAlignment(Qt::AlignLeft);

	playOrStopButton = new QPushButton;
	portLayout->addWidget(playOrStopButton);
	playOrStopButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	playOrStopButton->setFixedHeight(35);
	playOrStopButton->setFixedWidth(35);

	connect(playOrStopButton, SIGNAL(clicked()), this, SLOT(startOrStopSlot()));

	dialogAndStartButtonLayout->addLayout(portLayout);

	listUsersName = new QListWidget;
	listOfConnectedAndButtonsLayout->addWidget(listUsersName);
	listUsersName->setFixedWidth(300);

	contextmenu = new QMenu(listUsersName);

	QHBoxLayout* showsLayout = new QHBoxLayout;
	showsLayout->setMargin(0);
	//showsLayout->setAlignment(Qt::AlignRight);

	showChatButton = new QPushButton(tr("Show chat"));
	showsLayout->addWidget(showChatButton);
	showChatButton->setFixedWidth(100);
	//listOfConnectedAndButtonsLayout->setAlignment(showChatButton, Qt::AlignCenter);

	showTraceButton = new QPushButton(tr("Show trace"));//
	//showTraceButton->setIcon(QIcon("showTraceIcon.png"));
	showsLayout->addWidget(showTraceButton);
	//listOfConnectedAndButtonsLayout->setAlignment(showTraceButton, Qt::AlignCenter);
	showTraceButton->setFixedWidth(100);
	listOfConnectedAndButtonsLayout->addLayout(showsLayout);

	connect(showTraceButton, SIGNAL(clicked()), this, SLOT(traceSlot()));

	QAction* deleteClient = new QAction();

	contextmenu->addAction(deleteClient);
	
}


void ServerGUI::sendMessageConectSlot(QString messsage)
{
}

void ServerGUI::sendMessageSlot(QString messsage)
{
}

void ServerGUI::traceSlot()
{
	//сделать то что есть отдельным виджетом и после реализовать этот метод (перерисовывать окно с трассой или без неё)
}

void ServerGUI::kickSlot()
{
}

void ServerGUI::showMoreSlot()
{
}


void ServerGUI::startOrStopSlot()
{
	if (playNow == true)
	{
		emit stopServerSignal();
		mediaStateChangedSlot();
		printf("0");
	}
	else
	{
		if (port->toPlainText() != "")
		{
			emit startServerSignal();
			mediaStateChangedSlot();
			port->setStyleSheet("QTextEdit {background-color : rgb(255, 255, 255);}");
			printf("1");
		}
		else
		{
			port->setStyleSheet("QTextEdit {background : rgb(255, 0, 0);}");
			printf("2");
		}

	}
}

void ServerGUI::mediaStateChangedSlot()
{
	if (playNow == true)
	{
		playOrStopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
		playNow = false;
	}
	else
	{
		playOrStopButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
		playNow = true;
	}

}

void ServerGUI::addClient(QString name)
{
	listUsersName->addItem(name);
}
