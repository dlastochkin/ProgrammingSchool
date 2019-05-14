#pragma once
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

class AuthorizationInterface : public QWidget
{
	Q_OBJECT

public:
	AuthorizationInterface(QWidget* parent);
	~AuthorizationInterface();
	QFrame* connectionInterfaceFrame = NULL;
	QPushButton* connectButton = NULL;

private:
	QVBoxLayout* connectionInterfaceLayout;

private:
	void drawConnectionInterface();
	

};

