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
	void getMessageFromServer(); //Получение сообщений с сервера 
	void sendMessageToServer(QString message); //Отправка сообщений на сервер 

private slots:
	void connectedSlot(); //Cлот подключения
	void disconnectedSlot(); //Слот отключения
	void errorSlot(QAbstractSocket::SocketError); //Слот ошибок
};

