#pragma once
#include <QWidget.h>

class ClientGraphic : public QWidget 
{
public:
	ClientGraphic();
	~ClientGraphic();

private:
	void drawConnectionInterface(); //Отрисовка стартового окна
	void drawChatInterface(); //Отрисовка самого чата 
	void drawUserTable(); //Таблица пользователей
	void printMessage(QString message); //отрисовка сообщений

};


