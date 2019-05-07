#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QFileDialog>
#include <QListWidget>
#include <QLabel>
#include <QMenu>


class ServerGUI : public QMainWindow
{
	Q_OBJECT

private:
	QTextEdit* message;
	QPushButton* showTraceButton;
	QPushButton* showChatButton;
	QPushButton* playOrStopButton;
	QListWidget* listUsersName;
	QLabel* withWhomDialog;
	QMenu* contextmenu;
	

	void initialize();
	//void drawClientsList();
	//void drawMessageBox(); //Строка сообщения
	//void drawMessageButton(); //Кнопка сообщения
	//void drawTraceButton(); //Кнопка для вызова трассы
	//void drawStartStop(); //Кнопка для старта/остановки сервера
	//void drawServerInfo();
	//void drawMoreBox();
	//void drawChatList();

private slots:
	/*void startServer();
	void stopServer();*/
	//void updateList();
	void sendMessageConectSlot(QString messsage);
	void sendMessageSlot(QString messsage);
	void traceSlot();
	void kickSlot();
	void showMoreSlot();
	void startOrStopSlot();
	void mediaStateChangedSlot();

public:
	ServerGUI(int width, int height);
	bool playNow = false;
	QTextEdit* port;

signals:
	void startServerSignal();
	void stopServerSignal();
	/*void sendMessageConectSignal(QString messsage);
	void sendMessageSignal(QString messsage);
	void traceSignal();
	void kickSignal();
	void showMoreSignal();*/

public slots:
	void addClient(QString name);
};

