#pragma once
#include <QWidget.h>

class MessageDisplayWidget : public QWidget
{
public:
	MessageDisplayWidget();
	~MessageDisplayWidget();
	void addMessage(); //Добавить сообщение в чат
	void clear(); //очистить чат
private:
	void display(); //Отрисовка дисплея
	void scrollDown(); //Перемещение ползунка вниз
	


};
