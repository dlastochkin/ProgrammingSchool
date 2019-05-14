#pragma once
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>

class Hub
{
public:
	Hub(QWidget* parent, QString userName);
	~Hub();
	QFrame* hubInterfaceFrame = NULL;
	QListWidget* usersListWidget = NULL;

private:
	QVBoxLayout* hubInterfaceLayout = NULL;
	QString userName;
	QStringList usersList;

private:
	void drawHubInterface();
};

