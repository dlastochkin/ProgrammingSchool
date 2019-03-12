#pragma once

#include <QTcpSocket>
#include <QObject>

class ClientLogic : public QObject 
{
public:
	ClientLogic(const QString& ip, int port, QObject* parent = 0);
	~ClientLogic();

private:
	quint16 nextBlockSize;
	QTcpSocket socket; 

private:
	void getMessageFromServer(); //��������� ��������� � ������� 
	void sendMessageToServer(QString message); //�������� ��������� �� ������ 

private slots:
	void connectedSlot(); //C��� �����������
	void disconnectedSlot(); //���� ����������
	void errorSlot(QAbstractSocket::SocketError); //���� ������
};

