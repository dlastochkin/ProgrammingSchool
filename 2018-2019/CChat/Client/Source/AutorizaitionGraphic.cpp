#include "AutorizaitionGraphic.h"




AutorizaitionGraphic::AutorizaitionGraphic(int width, int height) : QMainWindow()
{
	QDesktopWidget* desktop = QApplication::desktop();  //
	this->setGeometry(500, 100, width, height);
	this->setMinimumSize(400, 500);// Окно

	this->setStyleSheet("background-color : QColor(0, 0, 35, 255);"); // 

	centralFrame = new QFrame(this);				//
	centralLayout = new QVBoxLayout(centralFrame); //
	this->setCentralWidget(centralFrame);		  // Frame / Layout
	centralFrame->setLayout(centralLayout);		 //

	drawAutorizationInterface();

 
}

AutorizaitionGraphic::~AutorizaitionGraphic()
{
}

void AutorizaitionGraphic::drawAutorizationInterface()
{

}


