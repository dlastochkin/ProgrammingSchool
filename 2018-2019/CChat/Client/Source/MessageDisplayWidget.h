#pragma once
#include <QWidget.h>

class MessageDisplayWidget : public QWidget
{
public:
	MessageDisplayWidget();
	~MessageDisplayWidget();
	void addMessage(); //�������� ��������� � ���
	void clear(); //�������� ���
private:
	void display(); //��������� �������
	void scrollDown(); //����������� �������� ����
	


};
