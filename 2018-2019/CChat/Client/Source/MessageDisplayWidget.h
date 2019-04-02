#pragma once
#include <QWidget.h>
#include <QColor.h>

class MessageDisplayWidget : public QWidget
{

	Q_OBJECT
	
public:
	MessageDisplayWidget();
	~MessageDisplayWidget();

public:
	void printMessage(QString* messageText, QString* userName); //Вывод сообщения и имени
	//void printName(); //Вывод имени
	void setMessageBackground(QColor* color); //Задний фон сообщения
	void setBackground(QColor* color);
	void clear(); //очистка
};
