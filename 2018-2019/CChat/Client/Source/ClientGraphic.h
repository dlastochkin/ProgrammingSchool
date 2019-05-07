#pragma once
#include <QWidget.h>
#include "MessageDisplayWidget.h"
#include <QPushButton>
#include <QColor>

class ClientGraphic : public QMainWindow
{
	Q_OBJECT

public:
	ClientGraphic(int width, int height);
	~ClientGraphic();
	void drawConnectionInterface(); //��������� ���������� ����
	void drawChatInterface(); //��������� ������ ���� 

private:
	void drawInputField(QFrame* parent, QHBoxLayout* layout); //���� ������ ���������
	void drawUserTable(); //������� �������������
	void setMessageAndUserName(QString message, QString username);
	void printMessage(); //��������� ���������

private:
	QFrame* centralFrame = NULL;
	QVBoxLayout* centralLayout = NULL;
	MessageDisplayWidget* messageDisplay = NULL; //������ ������ ���������
	QTextEdit* inputField = NULL;				 //���� ����� ������
	QPushButton* userListButton = NULL;
	QPushButton* sendButton = NULL;
	QString messageText = "";
	QString userName = "UserName";
	QString conferenceName = "ConferenceName";

private slots:
	QString sendMessage(); //����� ��������� �������
};

