#pragma once
#include <QWidget>
#include <list>
#include <QString>
#include <QDateTime>

enum MessageSeverity = { EVENT, WARNING, ERROR };
enum dateType = { INTERNATIONAL, USA, GERMANY, UK, HUNGARY };

class TraceMessage
{
private:
	MessageSeverity type;
	dateType dtype;
	QString body;
	QDateTime dt;
public:
	TraceMessage(QString body, MessageSeverity type = EVENT, dateType dtype = INTERNATIONAL, QDateTime dt = NULL);
	void setDateType(dateType dtype);
	QString out();
	~TraceMessage();
};

class CChatTrace : public QWidget
{
	Q_OBJECT;

private:
	dateType dtype;
	QString filename;
	Qlist <TraceMessage> list;


public signals:
	listIncreased(TraceMessage message);
public slots:
	void transmit(TraceMessage message);
public:
	CChatTrace(QWidget* parent = nullptr, QString filename = "", dateType dtype = INTERNATIONAL);
	void import();
	void add(QString ms, MessageSeverity type = EVENT);
	void setDateType(dateType dtype);
	~CChatTrace();
};