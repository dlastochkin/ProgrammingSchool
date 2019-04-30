#include "MessageDisplayWidget.h"

MessageDisplayWidget::MessageDisplayWidget()
{
}

void MessageDisplayWidget::printMessage(QString messageText, QString userName)
{
	QFrame* messageFrame = new QFrame(scrollArea); // Фрейм сообщения
	QVBoxLayout* messageFrameLayout = new QVBoxLayout(messageFrame);
	QHBoxLayout* messageLayout = new QHBoxLayout(messageFrame); // Лэйаут сообщения (строка)
	QTextEdit* message = new QTextEdit(messageFrame); // окошко сообщения
	QTextEdit* name = new QTextEdit(messageFrame); // окошко имени
	QFont nameFont("Courier", 10, QFont::Bold); // Стиль текста
	QFont messageFont("Courier", 13, QFont::Bold); // Стиль текста
	QFontMetrics messageFontMetrics(messageFont); // Размер текста (пиксели)
	int width = 0;
	int height = 0;

	name->setText(userName);
	name->setFont(nameFont);
	name->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	name->setAlignment(Qt::AlignLeft);

	name->setStyleSheet("background-color : QColor(0, 0, 65, 255); border:0px solid black;");
	message->setReadOnly(true);
	message->setText(messageText); // Устанавливаем текст сообщения 
	message->setFont(messageFont); // Устанавливаем стиль текста
	message->setStyleSheet("background-color : QColor(0, 0, 65, 255); color : black; border:0px solid black;"); // Красивый задний фон сообщения блин
	message->setReadOnly(true);
	message->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	message->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	messageLayout->setMargin(0);

	if (messageFontMetrics.width(message->toPlainText()) < 370)
	{
		width = messageFontMetrics.width(message->toPlainText()); // Ширина текста
		height = 20;
	}
	else
	{
		height = 20 * ((messageFontMetrics.width(message->toPlainText()) / 370) + 1);
		width = 370;
	}

	std::cout << width << " | " << height << std::endl;  // жопа


	name->setFixedHeight(20);
	message->setFixedWidth(width + 10); // Ширина окна текста
	message->setFixedHeight(height + 10); //Высота
	messageLayout->setAlignment(Qt::AlignBottom);
	messageFrame->setFixedHeight(height + 30);


	messageFrameLayout->setMargin(0);
	
	messageFrame->setLayout(messageFrameLayout);
	messageFrameLayout->addWidget(name);
	messageFrameLayout->addLayout(messageLayout);

	messageLayout->addWidget(message); // Закидываем сообщение на лэйаут

	//messageFrame->setStyleSheet("background-color : QColor(255, 0, 0, 255);");

	scrollAreaLayout->addWidget(messageFrame); // добавляем фрэйм сообщения в ScrollArea
}

void MessageDisplayWidget::setScrollArea(QFrame* parent, QVBoxLayout* layout)
{
	scrollArea = new QScrollArea(parent);
	scrollAreaLayout = new QVBoxLayout(scrollArea);
	scrollAreaLayout->setMargin(0);
	QScrollBar* scroll = new QScrollBar(parent);

	layout->addWidget(scrollArea);

	scrollArea->setLayout(scrollAreaLayout);
	scrollArea->setVerticalScrollBar(scroll);
	scrollArea->setStyleSheet("background-color : QColor(0, 0, 35, 255);");
	scrollArea->setFrameShape(QFrame::NoFrame);
}

void MessageDisplayWidget::clear()
{
}

MessageDisplayWidget::~MessageDisplayWidget()
{
}
