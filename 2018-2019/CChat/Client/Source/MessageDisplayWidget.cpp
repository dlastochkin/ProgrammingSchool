#include "MessageDisplayWidget.h"

MessageDisplayWidget::MessageDisplayWidget()
{
}

void MessageDisplayWidget::printMessage(QString messageText, QString userName)
{
	QFrame* messageFrame = new QFrame(scrollArea); // Фрейм сообщения
	QHBoxLayout* messageLayout = new QHBoxLayout(messageFrame); // Лэйаут сообщения (строка)
	QLabel* message = new QLabel(messageFrame); // Лэйбл сообщения
	QWidget* placeHolder = new QWidget(messageFrame); // Виджет, который просто занимает место  
	QFont messageFont("Courier", 13, QFont::Bold); // Стиль текста
	QFontMetrics messageFontMetrics(messageFont); // Размер текста (пиксели)
	int width = 0;
	int height = 0;

	message->setWordWrap(true);
	message->setText(messageText); // Устанавливаем текст сообщения 
	message->setFont(messageFont); // Устанавливаем стиль текста
	message->setStyleSheet("background-color : QColor(0, 0, 65, 255); color : black;"); // Красивый задний фон сообщения блин

	if (messageFontMetrics.width(message->text()) + 5 < 350)
	{
		width = messageFontMetrics.width(message->text()) + 5; // Ширина текста
	}
	else
	{
		width = 350;
	}

	height = messageFontMetrics.height(); // Высота текста
	
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
	std::cout << width << " | " << height << std::endl;  // жопа

	message->setFixedWidth(width); // Размер лэйбла текста
	message->setFixedHeight(height + 10);

	messageLayout->addWidget(message); // Закидываем лэйбл на лэйаут
	messageLayout->addWidget(placeHolder); // Запихиваем туда же пустой виджет, дабы заполнить место

	messageFrame->setStyleSheet("background-color : QColor(255, 0, 0, 255);");

	scrollAreaLayout->addWidget(messageFrame); // добавляем фрэйм сообщения в ScrollArea
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
