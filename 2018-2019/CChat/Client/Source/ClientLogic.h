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
	void getMessageFromServer(); //Получение сообщения от сервера 
	void sendMessageToServer(QString message); //Передача сообщения серверу 
	void getClientName(); //Имя клиента

private slots:
	void connect(); //подключение
	void disconnecte(); //мирное отключение от сервера
	void error(QAbstractSocket::SocketError); //ошибки
};

