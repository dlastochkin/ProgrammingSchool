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
	void drawChatInterface(); //��������� ������ ���� 
	void setMessageAndUserName(QString message, QString username); //��� ����� �����
	void printMessage(); //��������� ���������
	void setUserName(QString username); //��� ������ ����������
	QFrame* graphicWidget = NULL;

private:
	void drawInputField(QFrame* parent, QHBoxLayout* layout); //���� ����� ���������

private:
	QVBoxLayout* centralLayout= NULL;
	QFrame* chatInterfaceFrame = NULL;
	QVBoxLayout* chatInterfaceLayout = NULL;
	MessageDisplayWidget* messageDisplay = NULL; //������ ������ ���������
	QTextEdit* inputField = NULL;				 //���� ����� ������
	QPushButton* userListButton = NULL;
	QPushButton* sendButton = NULL;
	QString messageText = "";
	QString userName = "UserName";
	QString conferenceName = "ConferenceName";
	QTabWidget* tabWidget = NULL;
	
private slots:
	QString sendMessage(); //����� ��������� �������

};

