#pragma once
#include <QWidget>
#include <QScrollArea>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QDesktopWidget>
#include <QLabel>
#include <QApplication>
#include <iostream>
#include <QTextEdit>
#include <QScrollBar>

class MessageDisplayWidget : public QWidget
{
	Q_OBJECT

public:
	MessageDisplayWidget();
	~MessageDisplayWidget();

	void clear(); //������� ����������� 
	void setScrollArea(QFrame* parent, QVBoxLayout* layout); //������������� ������� ������ ���������
	void printMessage(QString messageText, QString userName); //����� ��������� � �����

private:
	QVBoxLayout* scrollAreaLayout = NULL;
	QScrollArea* scrollArea = NULL;
	QWidget* scrollAreaWidget = NULL;
	QScrollBar* scrollBar = NULL;
};
