#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPainter>

class MessageDisplayWidget : public QWidget
{
	Q_OBJECT
	
public:
	MessageDisplayWidget();
	~MessageDisplayWidget();

private:
	void printMessage(QString messageText, QString userName); //Вывод сообщения и имени
	//void printName(); //ВЫвод имени
	void drawBackground(); //Задний фон сообщения
	void clear(); //очистка
};
