#pragma once
#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>

#include <QTextEdit>
#include <QScrollBar>

class MessageDisplayWidget : public QWidget
{
	Q_OBJECT

public:
	MessageDisplayWidget();
	~MessageDisplayWidget();

	void clear(); //Очистка содержимого 
	void setScrollArea(QFrame* parent, QVBoxLayout* layout); //Инициализация виджета вывода сообщений
	void printMessage(QString messageText, QString userName, bool clientMessage); //Вывод сообщения и имени

private:
	QVBoxLayout* scrollAreaLayout = NULL;
	QScrollArea* scrollArea = NULL;
	QWidget* scrollAreaWidget = NULL;
	QScrollBar* scrollBar = NULL;
};
