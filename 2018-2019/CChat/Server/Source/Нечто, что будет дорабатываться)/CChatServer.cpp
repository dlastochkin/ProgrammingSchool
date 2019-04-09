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
	QByteArray* arr = new QByteArray();
	QDataStream* os = new QDataStream(arr, QIODevice::WriteOnly);
}

void CChatServer::sendMessage(QString message, QString fromUsername)
{
		QObject* owner = sender();

		QByteArray messageBytes;		
		QDataStream os(&messageBytes, QIODevice::WriteOnly);
		QTcpSocket* fromSocket;
		//QDataStream out(&messageBytes, QIODevice::WriteOnly);

		qint8 type;

		os >> type;
		qDebug() << "Received command " << type;

		qint32 length;
		os >> length;

		switch (type)
		{
		case VERSION:
		{
			os << type << quint32(0) << minorV << majorV;//MinorBite and MajorBite quint16
			os.device()->seek(1);

			os << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

			foreach(QString value, clients.values())
			{
				fromSocket = clients.key(value);
			}

			fromSocket->write(messageBytes);
		}
		case CLIENT_CONNECTED:
		{
			//out « type;
			//« name;//NameOfOurClient
			//socket->write(messageBytes);
		}
		}
		/*out « type« quint32(0) « message;
		out.device()->seek(1);
		out « quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));

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

CChatServer::CChatServer(QObject * parent)
{
}

CChatServer::~CChatServer()
{
}
