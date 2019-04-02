#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap> 


class CChatServer : public QObject
{
	Q_OBJECT

private:
	QTcpServer* server;
	QMap<QTcpSocket*, QString> map;
	quint16 nextBlockSize;
	int version;

private:
	void sendMessageConect(QString messsage); 	// ������������ �����������
	void sendMessage(QString message); //��������� ���������
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

