#pragma once
#include <QWidget.h>

class ClientGraphic : public QWidget 
{

	Q_OBJECT

public:
	ClientGraphic();
	~ClientGraphic();

private:
	void showConnectionForm(); //Интерфейс авторизации
	void showChatForm(); //Интерфейс чата 
	void showTabDialog(); //Вкладки с диалогами 
	
private slots:
	void showUserList(); //Список пользователей
	void changeDialog(); //Смена диалога

	//Добавить сигналы
};


