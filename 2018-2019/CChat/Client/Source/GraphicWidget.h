#pragma once
#include <QWidget.h>
#include "MessageDisplayWidget.h"
#include <QPushButton>
#include <QColor>

class GraphicWidget : public QMainWindow
{
	Q_OBJECT

public:
	GraphicWidget(int width, int height);
	~GraphicWidget();
	void drawConnectionInterface(); //��������� ���������� ����
	void drawChatInterface(); //��������� ������ ���� 

private:
	void drawInputField(QFrame* parent, QHBoxLayout* layout); //���� ������ ���������
	void drawUserTable(); //������� �������������
	void setMessageAndUserName(QString message, QString username);
	void printMessage(); //��������� ���������

private:
	QFrame* centralFrame = NULL;
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

