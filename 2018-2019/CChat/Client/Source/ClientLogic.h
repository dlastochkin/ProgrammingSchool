#pragma once
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <QString>
#include <QDataStream>
#include <string>
#include "ClientGraphic.h"

#define VERSION				0x1
#define CLIENT_CONNECTION	0x2
#define CLIENTS_LIST		0X3
#define PRIVATE_MESSAGE		0X4
#define CHAT_MESSAGE		0X5
#define KICK				0X6
#define CLIENT_DISCONNECTED	0X7
#define SERVER_SHUTDOWN		0X8
#define KEEP_ALIVE_RQ		0X9
#define KEEP_ALIVE_RS		0XA

class ClientLogic : public QObject
{
	Q_OBJECT
private:
	quint16 MinorBite;
	quint16 MajorBite;
	QString Name;
	QString IP;
	quint16 port;
	void sendVersion(QString version);
	QTcpServer* server;
	QTcpSocket* socket = nullptr;
	quint16 nextBlockSize;
	QStringList clientList;
	QStringList mainChat;
	//PrivateMessage
	//==============================
	QString PrivateCurrentName;
	QString PrivateCurrentMessage;
	//ChatMessage
	//==============================
	QString ChatCurrentName;
	QString ChatCurrentMessage;
	//==============================
	QString kickReason;

private:
	//SEND_MESSAGE
	//void sendVersion(QString version);	// отправка сообщения "medved" клиенту
	void clientConnected(QString* name);
	void privateMessage(QString message);
	void chatMessage(QString* message);
	void clientDisconnected();
	void keepAliveRS();
	//RECIEVE_MESSAGE
	void recieveMessage();
	void start(int w, int h);
public slots:
	//void newClientConnectionSlot();					// слот, который срабатывает при подключении клиента
	//void readDataFromServerSlot();					// слот, который срабатывает при приеме данных от клиента
	void connectToKek(QString name, QString ip, quint16 port);
	void connectStatus(bool tmp);
public:
	ClientLogic();
	~ClientLogic();
signals:
	//void AlrightEveryBody()
	//void MischaVseHuiniaDavaiPoNovoi()
	void connectOrNot(bool tmp);
	
};
