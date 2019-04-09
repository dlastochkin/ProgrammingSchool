
#pragma once
#include <QWidget.h>
#include <QPushButton>
#include <QColor>
#include <MessageDisplayWidget.h>

class AutorizaitionGraphic : public QMainWindow
{
public:
	AutorizaitionGraphic(int width, int height);
	~AutorizaitionGraphic();
	

private:

	void drawAutorizationInterface();
	
private:
	QFrame* centralFrame = NULL;
	QVBoxLayout* centralLayout = NULL;
	
	

};
