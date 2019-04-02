#pragma once

#include <QObject>
#include <QTcpSocket>
#include "ClientGraphic.h"

class ClientLogic : public QObject
{

	Q_OBJECT

public:
	ClientLogic(QObject* parent = 0);
	~ClientLogic();

private:
	quint16 nextBlockSize;
	QTcpSocket socket; 
	int version;
	QString userName;
	//trace
	ClientGraphic* gui;

private:
	void initSocket(const QString& ip, int port); // Ввод имени, IP, порта
	void getMessageFromServer(); //Получение сообщения от сервера 
	void sendMessageToServer(QString message); //Передача сообщения серверу 
	void getClientName(); //Имя клиента

private slots:
	void connect(); //подключение
	void disconnecte(); //мирное отключение от сервера
	void error(QAbstractSocket::SocketError); //ошибки

	/*
		Добавить слоты для обработки сигналов GUI
	*/
};

