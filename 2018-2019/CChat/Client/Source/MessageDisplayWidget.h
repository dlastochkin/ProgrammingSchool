#pragma once
#include <QWidget.h>
#include <QColor.h>
#include <QScrollArea>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QDesktopWidget>

class MessageDisplayWidget : public QMainWindow
{
	Q_OBJECT
	
public:
	MessageDisplayWidget(int width, int height);
	~MessageDisplayWidget();
	void addMessage(); //Добавить сообщение в чат
	void clear(); //очистить чат
private:
	void display(); //Отрисовка дисплея
	void scrollDown(); //Перемещение ползунка вниз
	

public:
	void printMessage(QString messageText, QString* userName, QScrollArea* scrollArea); //Р’С‹РІРѕРґ СЃРѕРѕР±С‰РµРЅРёСЏ Рё РёРјРµРЅРё
	//void printName(); //Р’С‹РІРѕРґ РёРјРµРЅРё
	void setMessageBackground(QColor* color); //Р—Р°РґРЅРёР№ С„РѕРЅ СЃРѕРѕР±С‰РµРЅРёСЏ
	void clear(); //РѕС‡РёСЃС‚РєР°
	void addScrollArea(QFrame* parent, QHBoxLayout* layout);

public:
	QScrollArea* scrollArea;
};
