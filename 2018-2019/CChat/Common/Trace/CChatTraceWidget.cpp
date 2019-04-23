#include "CChatTraceWidget.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>

CChatTraceWidget::CChatTraceWidget(QWidget * parent) : QWidget(parent){}

void CChatTraceWidget::initialize()
{
	QFrame* mainFrame = new QFrame(this);
	QHBoxLayout* layout = new QHBoxLayout(mainFrame);

	//filter


	//message list
	listWidget = new QListWidget(mainFrame);
	layout->addWidget(listWidget);
}

