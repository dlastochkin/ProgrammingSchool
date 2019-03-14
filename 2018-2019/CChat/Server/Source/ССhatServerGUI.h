#pragma once
#include <QWidget.h>

class ССhatServerGUI
{
	Q_OBJECT

public:
	ССhatServerGUI();
	~ССhatServerGUI();

private:
	void drawClientsList();
	void drawMessageBox(); //Строка сообщения 
	void drawMessageButton(); //Кнопка сообщения
	void drawTraceButton(); //Кнопка для вызова трассы
	void drawStartStop(); //Кнопка для старта/остановки сервера
	void drawServerInfo();
	void drawMoreBox();
	void drawChatList();

private slots:
	void startServer();
	void stopServer();
	void updateList();
	void sendMessageConectSlot(QString messsage);
	void sendMessageSlot(QString messsage);
	void traceSlot();
	void kickSlot();
	void showMoreSlot();

public signals:
	void startServerSignal();
	void stopServerSignal();
	void updateListSignal();
	void sendMessageConectSignal(QString messsage);
	void sendMessageSignal(QString messsage);
	void traceSignal();
	void kickSignal();
	void showMoreSignal();
};

