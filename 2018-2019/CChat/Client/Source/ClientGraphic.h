#pragma once
#include <QWidget.h>
#include <QMainWindow>
#include <QApplication>
#include "AuthorizationInterface.h"
#include "Hub.h"
#include "GraphicWidget.h"

class ClientGraphic : public QMainWindow
{
	Q_OBJECT

public:
	ClientGraphic(int width, int height);
	~ClientGraphic();

private:
	void createDialog(QString userName);

private:
	QFrame* centralFrame = NULL;
	QVBoxLayout* centralLayout = NULL;
	QTabWidget* tabWidget = NULL;
	QString userName = "UserName";
	AuthorizationInterface* AI = NULL;
	Hub* hub = NULL;

private slots:
	void authorizationIsEnd();
};

