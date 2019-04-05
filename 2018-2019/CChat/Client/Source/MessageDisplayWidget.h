#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPainter>
#include <QWidget>
#include <QColor>
#include <QScrollArea>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QDesktopWidget>
#include <QApplication>
#include <QLabel>




class MessageDisplayWidget : public QMainWindow
{
	Q_OBJECT

public:
	MessageDisplayWidget(int width, int height);
	~MessageDisplayWidget();

	void clear(); //Очистка содержимого 
	//void setMessageBackground(QColor* color); //Задний фон сообщения
	void addScrollArea(QFrame* parent, QVBoxLayout* layout); //Инициализация виджета вывода сообщений
	void printMessage(QString messageText, QString userName); //Вывод сообщения и имени
	
private:
	QVBoxLayout* scrollAreaLayout = NULL;
	//QTextEdit* message = NULL;
	QLabel* message;
	QScrollArea* scrollArea;
};
