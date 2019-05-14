#include "ClientLogic.h"

ClientLogic::ClientLogic()
{

}

ClientLogic::~ClientLogic()
{
}

void ClientLogic::start(int w, int h)
{
	ClientGraphic* gui = new ClientGraphic(w, h);
	gui->show();

	connect(gui, SIGNAL(connectTrying(QString, QString, quint16)), this, SLOT(connectToKek()));
	connect(socket, SIGNAL(error(QAbstractSocket::HostNotFoundError)), this, SLOT(connectStatus()));

	//socket = new QTcpSocket(this);
	
}

void ClientLogic::connectStatus(bool tmp)
{
	emit connectOrNot(tmp);
}

 
void ClientLogic::connectToKek(QString name, QString ip, quint16 port)
{
	Name = name;
	IP = ip;
	this->port = port;

	socket->connectToHost(ip, port, QIODevice::ReadWrite);
}

/*
void ClientLogic::readDataFromServerSlot()
{
	QDataStream in(socket);
	while (true)
	{
		if (!nextBlockSize)
		{
			if (socket->bytesAvailable() < sizeof(quint16))
			{
				break;
			}
			in >> nextBlockSize;
		}

		if (socket->bytesAvailable() < nextBlockSize)
		{
			break;
		}

		QString serverMessage;
		in >> serverMessage;
		qDebug() << "Server send message: " << serverMessage << "\n";

		nextBlockSize = 0;
	}
}
*/

void ClientLogic::sendVersion(QString version)
{
	QByteArray messageBytes;
	QDataStream out(&messageBytes, QIODevice::WriteOnly);
	
		out << VERSION << quint32(0) << MinorBite << MajorBite;//MinorBite and MajorBite quint16
		out.device()->seek(1);
		out << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));
		socket->write(messageBytes);
}

void  ClientLogic::clientConnected(QString* name)
{
	QByteArray messageBytes;
	QDataStream out(&messageBytes, QIODevice::WriteOnly);

	out << CLIENT_CONNECTION << quint32(0) <<name;//MinorBite and MajorBite quint16
	out.device()->seek(1);
	out << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));
	socket->write(messageBytes);
}

void ClientLogic::privateMessage(QString message)
{
	QByteArray messageBytes;
	QDataStream out(&messageBytes, QIODevice::WriteOnly);

	out << PRIVATE_MESSAGE << quint32(0) << message;//MinorBite and MajorBite quint16
	out.device()->seek(1);
	out << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));
	socket->write(messageBytes);
}

void ClientLogic::chatMessage(QString* message)
{
	QByteArray messageBytes;
	QDataStream out(&messageBytes, QIODevice::WriteOnly);

	out << CHAT_MESSAGE << quint32(0) << message;//MinorBite and MajorBite quint16
	out.device()->seek(1);
	out << quint32(messageBytes.size() - sizeof(quint32) - sizeof(quint8));
	socket->write(messageBytes);

}

void ClientLogic::clientDisconnected()
{
	QByteArray messageBytes;
	QDataStream out(&messageBytes, QIODevice::WriteOnly);

	out << CLIENT_DISCONNECTED;
	socket->write(messageBytes);
}

void ClientLogic::keepAliveRS()
{
	QByteArray messageBytes;
	QDataStream out(&messageBytes, QIODevice::WriteOnly);

	out << KEEP_ALIVE_RS;
	socket->write(messageBytes);
}

void ClientLogic::recieveMessage()
{
	quint8 type;
	quint32 lenght;
	QDataStream in(socket);
	while (true)
	{
		if (!type)
		{
			if (socket->bytesAvailable() < sizeof(quint8))
			{
				break;
			}
			in >> type;
		}

		if (!lenght)
		{
			if (socket->bytesAvailable() < sizeof(quint32))
			{
				break;
			}
			in >> lenght;
		}

		if (socket->bytesAvailable() < lenght)
		{
			break;
		}

		switch (type)
		{
		case VERSION:
		{

		}
		case CLIENTS_LIST:
		{
			int i = 0;
			QString Message;
			in >> Message;
			clientList = Message.split("/0");
		}
		case PRIVATE_MESSAGE:
		{
			QString Message;
			in >> Message;
			QStringList Messages;
			PrivateCurrentName = Messages.takeFirst();
			PrivateCurrentMessage = Messages.takeLast();

		}
		case CHAT_MESSAGE:
		{
			QString Message;
			in >> Message;
			QStringList Messages;
			ChatCurrentName = Messages.takeFirst();
			ChatCurrentMessage = Messages.takeLast();
		}
		case KICK:
		{
			QString kickReason;
			in >> kickReason;

		}
		case SERVER_SHUTDOWN:
		{

		}
		};

		lenght = 0;
		type = 0;
	}
}
