#include "MessageDisplayWidget.h"

MessageDisplayWidget::MessageDisplayWidget()
{
}

void MessageDisplayWidget::printMessage(QString messageText, QString userName, bool clientMessage)
{
	QFrame* messageFrame = new QFrame(scrollArea); // ����� ���������
	QVBoxLayout* messageFrameLayout = new QVBoxLayout(messageFrame);
	QHBoxLayout* messageLayout = new QHBoxLayout(messageFrame); // ������ ��������� (������)
	QTextEdit* message = new QTextEdit(messageFrame); // ������ ���������
	QLabel* name = new QLabel(messageFrame); // ������ �����
	QFont nameFont("Courier", 10, QFont::Bold); // ����� ������
	QFont messageFont("Courier", 13, QFont::Bold); // ����� ������
	QFontMetrics messageFontMetrics(messageFont); // ������ ������ (�������)
	int width = 0;
	int height = 0;

	messageFrame->setLayout(messageFrameLayout);
	messageFrameLayout->addWidget(name);
	messageFrameLayout->addLayout(messageLayout);
	messageFrameLayout->setSpacing(0);
	messageFrameLayout->setMargin(0);
	messageFrameLayout->setAlignment(Qt::AlignBottom);

	messageLayout->addWidget(message);
	messageLayout->setAlignment(Qt::AlignLeft);

	name->setText(userName);
	name->setFont(nameFont);
	name->setAlignment(Qt::AlignLeft);
	name->setStyleSheet("border:0px solid black; color : QColor(0, 0, 180, 255);");
	name->setFixedHeight(20);

	message->setText(messageText);
	message->setFont(messageFont); // ������������� ����� ������
	if (clientMessage)
		message->setStyleSheet("background-color : QColor(0, 0, 65, 255);"
			"border:0px solid black; color : QColor(0, 0, 180, 255);"); //���� ��������� �� �����
	else
		message->setStyleSheet("background-color : QColor(0, 0, 65, 255);"
			"border:0px solid black; color : QColor(30, 0, 180, 255);"); //���� ��������� �� �������
	message->setReadOnly(true);
	message->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	message->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	if (messageFontMetrics.width(message->toPlainText()) < 370)
	{
		width = messageFontMetrics.width(message->toPlainText()); // ������ ������
		height = 20;
	}
	else
	{
		height = 20 * ((messageFontMetrics.width(message->toPlainText()) / 370) + 1);
		width = 370;
	}
	message->setFixedSize(width + 10, height + 10); // ������ � ������ ������� ������ ���������
	messageFrame->setFixedHeight(height + 30); //������ ������� ���������

	scrollBar->setMaximum(scrollBar->maximum() + 56); //��������� ������ ��� ������ �� ������� � ����� ���
	scrollBar->setValue(scrollBar->maximum()); // ������� ���������� ������ ���

	scrollAreaLayout->addWidget(messageFrame);
}

void MessageDisplayWidget::setScrollArea(QFrame * parent, QVBoxLayout * layout)
{
	scrollBar = new QScrollBar(parent);
	scrollArea = new QScrollArea(parent);
	scrollAreaLayout = new QVBoxLayout(scrollArea);
	scrollAreaWidget = new QWidget(scrollArea);
	scrollAreaLayout->setMargin(0);
	scrollAreaLayout->setAlignment(Qt::AlignBottom);

	layout->addWidget(scrollArea);

	scrollAreaWidget->setLayout(scrollAreaLayout);

	
	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea->setVerticalScrollBar(scrollBar);
	scrollArea->setWidget(scrollAreaWidget);
	scrollArea->setWidgetResizable(true);
	scrollArea->setStyleSheet("background-color : QColor(0, 0, 35, 255);");
	scrollArea->setFrameShape(QFrame::NoFrame);
}

void MessageDisplayWidget::clear()
{
}

MessageDisplayWidget::~MessageDisplayWidget()
{
}

																			  