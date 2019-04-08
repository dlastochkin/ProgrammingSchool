#include <QUrl>
#include <QFile>
#include <QTextStream>
#include "TraceLoader.h"

QList<TraceMessage> TraceLoader::load(QString filename) //returns empty list if load is failed or loaded list
{
	QList<TraceMessage> result;
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly))
	{
		TraceMessage err("File open failed", ERROR);
		result.append(err);
		return result;
	}
	QTextStream in(&file);
	QString str;
	TraceMessage tmp("",ERROR);
	while(!in.atEnd())
	{
		str = in.readLine();	
		tmp.fromString(str);
	}
	file.close();
	return result;
}
