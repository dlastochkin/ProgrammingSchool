#pragma once
#include <QWidget.h>

class MessageWidget : public QWidget
{
public:
	MessageWidget();
	~MessageWidget();

private:
	void message(); //��������� ������ ���������
	void name(); //��������� �����
	void background(); //��������� ����, �� ������� ������� ���������


}; 
