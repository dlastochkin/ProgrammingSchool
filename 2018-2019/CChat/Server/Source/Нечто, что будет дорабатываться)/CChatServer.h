#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap> 


#define VERSION				0x1
#define CLIENT_CONNECTED	0x2
#define CLIENTS_LIST		0X3
#define PRIVATE_MESSAGE		0X4
#define CHAT_MESSAGE		0X5
#define KICK				0X6
#define CLIENT_DISCONNECTED	0X7
#define SERVER_SHUTDOWN		0X8
#define KEEP_ALIVE_RQ		0X9
#define KEEP_ALIVE_RS		0XA
#define SERVER_REJECTED_REQUEST		0XB


#include "Exceptions.h"



class CChatServer : public QObject
{
	Q_OBJECT

private:
	QTcpServer* server;
	QMap<QTcpSocket*, QString> clients;
	quint16 nextBlockSize;
	qint8 minorV = 0x1;
	qint8 majorV = 0x0;

	qint8 messageType = PRIVATE_MESSAGE;


private:
	void sendMessageConect(QString messsage); 	// ������������ �����������
	void sendMessage(QString fromUsername); //��������� ��������� QString message,
	void sendMessageTo(QString text, QString toUsername);
	void printServerInfo(QString messsage);
	void trace();//�������� ������
	void saveIntoTrace();//��������� ������ � ������
	void convertIn();//������������� ���������
	void convertOut();//����������� ���������
	void kick();
	void start(int port);
	void stop();
	void showMore(); // ���. ���� ��� ������� �� �������

private slots:
	void newClientConnectionSlot();					// ����, ������� ����������� ��� ����������� �������
	void readDataFromClientSlot();					// ����, ������� ����������� ��� ������ ������ �� �������
	void startServer();
	void stopServer();
	void updateList();
	void sendMessageConectSlot(QString messsage);
	void sendMessageSlot(QString messsage);
	void traceSlot();
	void kickSlot();
	void showMoreSlot();

public:
	CChatServer(QObject *parent = 0);
	~CChatServer();
};

