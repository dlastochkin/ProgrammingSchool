#pragma once
#include <QWidget.h>

class MessageWidget : public QWidget
{
public:
	MessageWidget();
	~MessageWidget();

private:
	void message(); //Отрисовка текста сообщения
	void name(); //Отрисовка имени
	void background(); //Отрисовка окна, на котором пишется сообщение


}; 
