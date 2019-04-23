#include <QUrl>
#include <QFile>
#include <QTextStream>
#include "TraceLoader.h"

QList<TraceMessage*> TraceLoader::load(QString filename) //returns empty list if load is failed or loaded list
{
	QList<TraceMessage*> result;
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly))
	{
		TraceMessage* err = new TraceMessage("File open failed", MessageSeverity::ERROR);
		result.append(err);
		return result;
	}
	QTextStream in(&file);
	QString str;
	while(!in.atEnd())
	{
		TraceMessage* tmp = new TraceMessage("",MessageSeverity::ERROR);
		str = in.readLine();	
		tmp->fromString(str);
		result.append(tmp);
	}
	file.close();
	return result;
}
