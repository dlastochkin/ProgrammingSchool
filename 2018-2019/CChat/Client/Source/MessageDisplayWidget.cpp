#include "MessageDisplayWidget.h"

MessageDisplayWidget::MessageDisplayWidget()
{
}

void MessageDisplayWidget::printMessage(QString messageText, QString userName)
{
	QFrame* messageFrame = new QFrame(scrollArea); // Фрейм сообщения
	QHBoxLayout* messageLayout = new QHBoxLayout(messageFrame); // Лэйаут сообщения (строка)
	QTextEdit* message = new QTextEdit(messageFrame); // окошко сообщения
	QWidget* placeHolder = new QWidget(messageFrame); // Виджет, который просто занимает место  
	QFont messageFont("Courier", 13, QFont::Bold); // Стиль текста
	QFontMetrics messageFontMetrics(messageFont); // Размер текста (пиксели)
	int width = 0;
	int height = 0;

	message->setText(messageText); // Устанавливаем текст сообщения 
	message->setFont(messageFont); // Устанавливаем стиль текста
	message->setStyleSheet("background-color : QColor(0, 0, 65, 255); color : black; border:0px solid black;"); // Красивый задний фон сообщения блин
	message->setReadOnly(true);
	message->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	message->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	if (messageFontMetrics.width(message->toPlainText()) < 350)
	{
		width = messageFontMetrics.width(message->toPlainText()); // Ширина текста
		height = 40;
	}
	else
	{
		height = 20 * ((messageFontMetrics.width(message->toPlainText()) / 350) + 1);
		width = 350;
	}

	std::cout << width << " | " << height << std::endl;  // жопа

	message->setFixedWidth(width + 5); // Ширина окна текста
	message->setFixedHeight(height + 10); //Высота
	messageFrame->setFixedHeight(height - 10);


	messageLayout->addWidget(message); // Закидываем лэйбл на лэйаут
	messageLayout->addWidget(placeHolder); // Запихиваем туда же пустой виджет, дабы заполнить место

	messageFrame->setStyleSheet("background-color : QColor(255, 0, 0, 255);");
	//messageFrame->setFixedHeight(height + 5);

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
