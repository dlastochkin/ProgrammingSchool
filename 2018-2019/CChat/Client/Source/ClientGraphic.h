#pragma once
#include <QWidget.h>

class ClientGraphic : public QWidget 
{

	Q_OBJECT

public:
	ClientGraphic();
	~ClientGraphic();

private:
	void drawConnectionInterface(); //Интерфейс авторизации
	void drawChatInterface(); //Интерфейс чата 
	void drawInputLine(); //Строка ввода текста
	void drawTabDialog(); //Вкладки с диалогами 
	
private slots:
	void showUserList(); //Список пользователей
	void changeDialog(); //Смена диалога
};


