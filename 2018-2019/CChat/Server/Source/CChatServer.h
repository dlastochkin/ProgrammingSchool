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
		void sendMessageConect(QString messsage); 	// пользователь подключился
		void sendMessage(QString message); //отправить сообщение
		void printServerInfo(QString messsage);
		void trace();//показать трассу
		void saveIntoTrace();//сохранить данные в трассу
		void convertIn();//деконвертация сообщения
		void convertOut();//конвертация сообщения
		void kick();
		void start(int port);
		void stop();
		void showMore(); // доп. окно при нажатии на клиента

	private slots:
		void newClientConnectionSlot();					// слот, который срабатывает при подключении клиента
		void readDataFromClientSlot();					// слот, который срабатывает при приеме данных от клиента
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
