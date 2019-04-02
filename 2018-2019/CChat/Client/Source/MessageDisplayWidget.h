#pragma once
#include <QWidget.h>
#include <QColor.h>
#include <QScrollArea>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QDesktopWidget>

class MessageDisplayWidget : public QMainWindow
{
	Q_OBJECT
	
public:
	MessageDisplayWidget(int width, int height);
	~MessageDisplayWidget();

public:
	void printMessage(QString messageText, QString* userName, QScrollArea* scrollArea); //Вывод сообщения и имени
	//void printName(); //Вывод имени
	void setMessageBackground(QColor* color); //Задний фон сообщения
	void clear(); //очистка
	void addScrollArea(QFrame* parent, QHBoxLayout* layout);

public:
	QScrollArea* scrollArea;
};
