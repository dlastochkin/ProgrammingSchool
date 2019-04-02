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
	void getMessageFromServer(); //Получение сообщений с сервера 
	void sendMessageToServer(QString message); //Отправка сообщений на сервер
	void getClientName();

private slots:
	void connectedSlot(); //Cлот подключения
	void disconnectedSlot(); //Слот отключения
	void errorSlot(QAbstractSocket::SocketError); //Слот ошибок
	void 
};

