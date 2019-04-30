#pragma once
#include <QWidget.h>
#include "MessageDisplayWidget.h"
#include <QPushButton>
#include <QColor>

class ClientGraphic : public QMainWindow
{
public:
	ClientGraphic(int width, int height);
	~ClientGraphic();
	void drawConnectionInterface(); //Отрисовка стартового окна
	void drawChatInterface(); //Отрисовка самого чата 

private:
	void drawInputField(QFrame* parent, QHBoxLayout* layout); //ПОле вывода сообщений
	void drawUserTable(); //Таблица пользователей
	void setMessageAndUserName(QString message, QString username);
	void printMessage(); //отрисовка сообщений

private:
	QFrame* centralFrame = NULL;
	QVBoxLayout* centralLayout = NULL;
	MessageDisplayWidget* messageDisplay = NULL; //Виджет вывода сообщений
	QTextEdit* inputField = NULL;				 //Поле ввода текста
	QPushButton* userListButton = NULL;			
	QPushButton* sendButton = NULL;
	QString messageText = "";
	QString userName = "";

public slots:
	void showUserList(); //Показывает участников чата, 
							//но скорее всего за это будет отвечать 
								//выпадающая кнопка userLisetButton

	void sendMessage(); //Вывод сообщения клиента
};


