#include <QDataStream>
#include "CChatServer.h"


#define VERSION				0x1
#define CLIENT_CONNECTED	0x2
#define CLIENTS_LIST		0X3
#define PRIVATE_MESSAGE		0X4
#define CHAT_MESSAGE		0X5
#define KICK				0X6
#define CLIENT_DISCONNECTED	0X7
#define SERVER_SHUTDOWN		0X8
#define KEEP_ALIVE_RQ		0X9
#define KEEP_ALIVE_RS		0XA


void CChatServer::sendMessageConect(QString messsage)
{
	
}

void CChatServer::sendMessage(QString message, QString fromUsername)
{
		

		QByteArray messageBytes;		
		QDataStream os(&messageBytes, QIODevice::WriteOnly);
		QTcpSocket* fromSocket;
		//QDataStream out(&messageBytes, QIODevice::WriteOnly);

		qint8 type;

		os >> type;
		qDebug() << "Received command: " << type;

		qint32 length;
		os >> length;

		QString message;
		os >> message;

		switch (type)
		{
		case VERSION:
		{
			os << type << quint32(0) << minorV << majorV;//MinorBite and MajorBite quint16
			os.device()->seek(1);

			os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

			foreach(QString value, clients.values())
			{
				if(value == fromUsername) clients.key(value)->write(messageBytes);// only one (if with no that: !=)
			}
		}
		case CLIENT_CONNECTED:
		{
			os << type << quint32(0) << fromUsername;//name
			os.device()->seek(1);

			os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(fromUsername));


			foreach(QString value, clients.values())
			{
				clients.key(value)->write(messageBytes);// to all
			}
		}
		case CLIENTS_LIST:
		{
			unsigned long long nameSize;//size of all names

			os << type << quint32(0);//MinorBite and MajorBite quint16
			foreach(QString value, clients.values())
			{
				os << value << '\\0';
				nameSize += sizeof(value);
			}
			os.device()->seek(1);

			os << quint32(messageBytes.size() - sizeof(quint32) - nameSize);


			foreach(QString value, clients.values())
			{
				if (value == fromUsername) clients.key(value)->write(messageBytes);//to sender
			}
		}
		case PRIVATE_MESSAGE:
		{
			QStringList to = message.split("\\0");
			for (int i = 0; i < message.size()-1; i++)
			{
				if (message.at(i) == "\\" && message.at(i + 1) == "0") message = message.right(i + 1);
			}

			os << type << quint32(0) << message;//message
			os.device()->seek(1);

			os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

			foreach(QString value, clients.values())
			{
				if (value == to[0]) clients.key(value)->write(messageBytes);// only one (if with no that: !=)
			}
		}
		}
		/*out � type� quint32(0) � message;
		out.device()->seek(1);
		out � quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

		socket->write(messageBytes);*/
		
	
}

void CChatServer::printServerInfo(QString messsage)
{
}

void CChatServer::trace()
{
}

void CChatServer::saveIntoTrace()
{
}

void CChatServer::convertIn()
{
}

void CChatServer::convertOut()
{
}

void CChatServer::kick()
{
}

void CChatServer::start(int port)
{
}

void CChatServer::stop()
{
}

void CChatServer::newClientConnectionSlot()
{

}

void CChatServer::showMore()
{
}

void CChatServer::readDataFromClientSlot()
{
}

void CChatServer::startServer()
{
}

void CChatServer::stopServer()
{
}

void CChatServer::updateList()
{
}

void CChatServer::sendMessageConectSlot(QString messsage)
{
}

void CChatServer::sendMessageSlot(QString messsage)
{
}

void CChatServer::traceSlot()
{
}

void CChatServer::kickSlot()
{
}

void CChatServer::showMoreSlot()
{
}

void incomeConnection()
{

}

CChatServer::CChatServer(QObject * parent)
{
	server = new QTcpServer(this);
}

CChatServer::~CChatServer()
{
}
