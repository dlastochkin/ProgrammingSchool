#pragma once
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QTextStream>

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
	QTextEdit* portField = NULL;
	QTextEdit* ipField = NULL;
	QTextEdit* userNameField = NULL;

private:
	void drawConnectionInterface();
	
private slots:
	void connectButtonClicked();

signals:
	void connectToServer(QString name, QString ip, quint16 port);
};

