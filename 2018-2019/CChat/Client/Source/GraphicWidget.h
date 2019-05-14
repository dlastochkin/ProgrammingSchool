#pragma once
#include <QWidget.h>
#include "MessageDisplayWidget.h"
#include <QPushButton>
#include <QColor>
#include <QTabWidget>

class GraphicWidget : public QWidget
{
	Q_OBJECT

public:
	GraphicWidget(QWidget* parent, QString name, int id);
	~GraphicWidget();
	void drawChatInterface(); //Отрисовка самого чата 
	void setMessageAndUserName(QString message, QString username); //Для общих чатов
	void printMessage(); //отрисовка сообщений
	void setUserName(QString username); //Для личных соообщений
	QFrame* graphicWidget = NULL;

private:
	void drawInputField(QFrame* parent, QHBoxLayout* layout); //ПОле ввода сообщений

private:
	QVBoxLayout* centralLayout= NULL;
	QFrame* chatInterfaceFrame = NULL;
	QVBoxLayout* chatInterfaceLayout = NULL;
	MessageDisplayWidget* messageDisplay = NULL; //Виджет вывода сообщений
	QTextEdit* inputField = NULL;				 //Поле ввода текста
	QPushButton* userListButton = NULL;
	QPushButton* sendButton = NULL;
	QString messageText = "";
	QString userName = "UserName";
	QString conferenceName = "ConferenceName";
	QTabWidget* tabWidget = NULL;
	
private slots:
	QString sendMessage(); //Вывод сообщения клиента

};

