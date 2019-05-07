#include <QDataStream>
#include "CChatServer.h"

/*
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
#define SERVER_REJECTED_REQUEST		0XB

#define EXCEPTION QString;
#define NULL_MESSAGE_EXCEPTION "Null message";*/


void CChatServer::sendMessageConect(QString messsage)
{
	
}

void CChatServer::sendMessageTo(QString text, QString toUsername)
{
	QByteArray messageBytes;
	QDataStream os(&messageBytes, QIODevice::WriteOnly);
	//need to convert our text toi bite array with the tags
	//if MESSAGETYPE bla-bla-bla
	//if private message

	switch (messageType)
	{
	case PRIVATE_MESSAGE:
		os << messageType << quint32(0) << text;
		os.device()->seek(1);

		os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

		foreach(QString value, clients.values())
		{
			if (value == toUsername) clients.key(value)->write(messageBytes);// only one (if with no that: !=)
		}
		break;

	case CHAT_MESSAGE:
		os << messageType << quint32(0) << text;
		os.device()->seek(1);

		os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

		foreach(QString value, clients.values())
		{
			clients.key(value)->write(messageBytes);// for all
		}
		break;

	case KICK:
		os << messageType << quint32(0) << text; //reason
		os.device()->seek(1);

		os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

		foreach(QString value, clients.values())
		{
			if (value == toUsername)
			{
				clients.key(value)->write(messageBytes);// for one
				//disconnect user
				clients.remove(clients.key(value));//remove from QMap
			}
		}
		break;

	case SERVER_SHUTDOWN:
		os << messageType << quint32(0) << "Server shutdown";
		os.device()->seek(1);

		os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

		foreach(QString value, clients.values())
		{
				clients.key(value)->write(messageBytes);// for all
				//disconnect users
				clients.remove(clients.key(value));//remove from QMap
		}
		break;

	case SERVER_REJECTED_REQUEST:
		os << messageType << quint32(0) << text; //reason
		os.device()->seek(1);

		os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

		foreach(QString value, clients.values())
		{
			if (value == toUsername)
			{
				clients.key(value)->write(messageBytes);// for one
				//what to do??
			}
		}
		break;

	case KEEP_ALIVE_RQ:
		os << messageType << quint32(0) << text; //reason
		os.device()->seek(1);

		os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

		foreach(QString value, clients.values())
		{
			if (value == toUsername)
			{
				clients.key(value)->write(messageBytes);// for one
				//what to do??
			}
		}
		break;

	default:
		break;
	}


	
}

void CChatServer::sendMessage(QString fromUsername)
{
		QByteArray messageBytes;		
		QDataStream os(&messageBytes, QIODevice::ReadWrite);
		//QTcpSocket* fromSocket;
		//QDataStream out(&messageBytes, QIODevice::WriteOnly);

		if (messageBytes == "")
		{
			throw NULL_MESSAGE_EXCEPTION + " from:" + fromUsername;
		}

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
			qint8 c_minorV;
			qint8 c_majorV;

			os >> c_minorV >> c_majorV;

			if (c_majorV != majorV)
			{
				//DISCONNECT CLIENT
				return;
			}

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
			os << type << quint32(0) << fromUsername + "connected";//name
			os.device()->seek(1);

			os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));


			foreach(QString value, clients.values())
			{
				clients.key(value)->write(messageBytes);// to all
			}
		}
		case PRIVATE_MESSAGE:
		{
			QStringList to = message.split("\0");

			if (to.length() < 2);
			{
				throw NOT_FULL_MESSAGE_EXCEPTION + " from:" + fromUsername;
			}
			
			os << type << quint32(0) << fromUsername + ":" + to[1];//message
			os.device()->seek(1);

			os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

			foreach(QString value, clients.values())
			{
				if (value == to[0]) clients.key(value)->write(messageBytes);// only one (if with no that: !=)
			}
		}
		case CHAT_MESSAGE:
		{
			os << type << quint32(0) << fromUsername + ":" + message;//message
			os.device()->seek(1);

			os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

			foreach(QString value, clients.values())
			{
				clients.key(value)->write(messageBytes);// for all
			}
		}
		case CLIENT_DISCONNECTED:
		{
			os << type << quint32(0) << fromUsername + "disconnected";//name
			os.device()->seek(1);

			os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));


			foreach(QString value, clients.values())
			{
				clients.key(value)->write(messageBytes);// to all
			}
		}
		case KEEP_ALIVE_RS:
		{
			//smth
		}
		}
}

/*
case CLIENTS_LIST:
		{
			//unsigned long long nameSize;//size of all names

			os << type << quint32(0);//MinorBite and MajorBite quint16
			foreach(QString value, clients.values())
			{
				os << value << '\0';
				//nameSize += sizeof(value);
			}
			os.device()->seek(1);

			os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));


			foreach(QString value, clients.values())
			{
				if (value == fromUsername) clients.key(value)->write(messageBytes);//to sender
			}
		}
*/

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
