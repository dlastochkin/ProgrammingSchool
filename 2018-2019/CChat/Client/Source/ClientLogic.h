#pragma once

#include <QObject>
#include <QTcpSocket>

class ClientLogic : public QObject
{
	Q_OBJECT
public:
	ClientLogic(const QString& ip, int port, QObject* parent = 0);
	~ClientLogic();

private:
	quint16 nextBlockSize;
	QTcpSocket socket; 
	int version;
	int nameOfClient;
	//trace



private:
	void getMessageFromServer(); //��������� ��������� � ������� 
	void sendMessageToServer(QString message); //�������� ��������� �� ������
	void getClientName();

private slots:
	void connectedSlot(); //C��� �����������
	void disconnectedSlot(); //���� ����������
	void errorSlot(QAbstractSocket::SocketError); //���� ������
	void 
};

