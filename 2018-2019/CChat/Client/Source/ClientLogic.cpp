void SimpleClient::sendMessageToServer(QString message, quint8 type)
{
	QByteArray messageBytes;
	QDataStream out(&messageBytes, QIODevice::WriteOnly);

	out << type << quint32(0) <<message;
	out.device()->seek(1);
	out << quint32(messageBytes.size() - sizeof(quint32)- sizeof(quint8));

	socket->write(messageBytes);
}
void SimpleClient::readDataFromServerSlot()
{
	QDataStream in(socket);
	while (true)
	{
		
	}
}