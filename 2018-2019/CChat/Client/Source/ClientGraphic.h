#pragma once
#include <QWidget.h>

class ClientGraphic : public QWidget 
{
public:
	ClientGraphic();
	~ClientGraphic();

private:
	void drawConnectionInterface(); //��������� ���������� ����
	void drawChatInterface(); //��������� ������ ���� 
	void drawUserTable(); //������� �������������
	void printMessage(QString message); //��������� ���������

};


