#include "MessageDisplayWidget.h"

MessageDisplayWidget::MessageDisplayWidget()
{
}

void MessageDisplayWidget::printMessage(QString messageText, QString userName)
{
	QFrame* messageFrame = new QFrame(scrollArea); // ����� ���������
	QHBoxLayout* messageLayout = new QHBoxLayout(messageFrame); // ������ ��������� (������)
	QTextEdit* message = new QTextEdit(messageFrame); // ������ ���������
	QWidget* placeHolder = new QWidget(messageFrame); // ������, ������� ������ �������� �����  
	QFont messageFont("Courier", 13, QFont::Bold); // ����� ������
	QFontMetrics messageFontMetrics(messageFont); // ������ ������ (�������)
	int width = 0;
	int height = 0;

	message->setText(messageText); // ������������� ����� ��������� 
	message->setFont(messageFont); // ������������� ����� ������
	message->setStyleSheet("background-color : QColor(0, 0, 65, 255); color : black; border:0px solid black;"); // �������� ������ ��� ��������� ����
	message->setReadOnly(true);
	message->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	message->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	if (messageFontMetrics.width(message->toPlainText()) < 350)
	{
		width = messageFontMetrics.width(message->toPlainText()); // ������ ������
		height = 40;
	}
	else
	{
		height = 20 * ((messageFontMetrics.width(message->toPlainText()) / 350) + 1);
		width = 350;
	}

	std::cout << width << " | " << height << std::endl;  // ����

	message->setFixedWidth(width + 5); // ������ ���� ������
	message->setFixedHeight(height + 10); //������
	messageFrame->setFixedHeight(height - 10);


	messageLayout->addWidget(message); // ���������� ����� �� ������
	messageLayout->addWidget(placeHolder); // ���������� ���� �� ������ ������, ���� ��������� �����

	messageFrame->setStyleSheet("background-color : QColor(255, 0, 0, 255);");
	//messageFrame->setFixedHeight(height + 5);

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
