#include <QUrl>
#include <QFile>
#include <QTextStream>
#include "TraceLoader.h"

QList<TraceMessage*>* TraceLoader::load(QString filename) //returns empty list if load is failed or loaded list
{
	QList<TraceMessage*>* result = new QList<TraceMessage*>();
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly))
	{
		/*TraceMessage* err = new TraceMessage("File open failed", MessageSeverity::ERROR);
		result->append(err);
		return result;*/
	}
	QTextStream in(&file);
	QString str;
	int counter = 0;
	while(!in.atEnd())
	{
		++counter; 
		TraceMessage* tmp;
		try
		{
			tmp = new TraceMessage(in.readLine());
		}
		catch (EXCEPTION ex) {
			//delete tmp;
			tmp = new TraceMessage(ex + " at line " + QVariant(counter).toString(), MessageSeverity::ERROR);
		}
		result->append(tmp);
	}
	file.close();
	return result;
}
