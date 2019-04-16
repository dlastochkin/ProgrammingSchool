#pragma once
#include <QObject>
#include <QList>
#include "TraceMessage.h"


class TraceLoader : public QObject
{
	Q_OBJECT;
public:
	static QList<TraceMessage*> load(QString filename);
};
