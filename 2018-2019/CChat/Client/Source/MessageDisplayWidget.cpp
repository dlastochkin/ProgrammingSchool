#include "MessageDisplayWidget.h"

MessageDisplayWidget::MessageDisplayWidget()
{
}

void MessageDisplayWidget::printMessage(QString messageText, QString userName)
{
	QFrame* messageFrame = new QFrame(scrollArea); // ����� ���������
	QHBoxLayout* messageLayout = new QHBoxLayout(messageFrame); // ������ ��������� (������)
	QLabel* message = new QLabel(messageFrame); // ����� ���������
	QWidget* placeHolder = new QWidget(messageFrame); // ������, ������� ������ �������� �����  
	QFont messageFont("Courier", 13, QFont::Bold); // ����� ������
	QFontMetrics messageFontMetrics(messageFont); // ������ ������ (�������)
	int width = 0;
	int height = 0;

	message->setWordWrap(true);
	message->setText(messageText); // ������������� ����� ��������� 
	message->setFont(messageFont); // ������������� ����� ������
	message->setStyleSheet("background-color : QColor(0, 0, 65, 255); color : black;"); // �������� ������ ��� ��������� ����

	if (messageFontMetrics.width(message->text()) + 5 < 350)
	{
		width = messageFontMetrics.width(message->text()) + 5; // ������ ������
	}
	else
	{
		width = 350;
	}

	height = messageFontMetrics.height(); // ������ ������
	
	if (height % 20 != 0)
	{
		int a = (width / 20) + 1;
		height *= a;
	}
	else
	{
		int a = (height / 20);
		height *= a;
	}
	std::cout << width << " | " << height << std::endl;  // ����

	message->setFixedWidth(width); // ������ ������ ������
	message->setFixedHeight(height + 10);

	messageLayout->addWidget(message); // ���������� ����� �� ������
	messageLayout->addWidget(placeHolder); // ���������� ���� �� ������ ������, ���� ��������� �����

	messageFrame->setStyleSheet("background-color : QColor(255, 0, 0, 255);");

	scrollAreaLayout->addWidget(messageFrame); // ��������� ����� ��������� � ScrollArea
}

void MessageDisplayWidget::setScrollArea(QFrame* parent, QVBoxLayout* layout)
{
	scrollArea = new QScrollArea(parent);
	scrollAreaLayout = new QVBoxLayout(scrollArea);

	layout->addWidget(scrollArea);

	scrollArea->setLayout(scrollAreaLayout);
	scrollArea->setStyleSheet("background-color : QColor(0, 0, 35, 255);");
	scrollArea->setFrameShape(QFrame::NoFrame);
}

void MessageDisplayWidget::clear()
{
}

MessageDisplayWidget::~MessageDisplayWidget()
{
}
