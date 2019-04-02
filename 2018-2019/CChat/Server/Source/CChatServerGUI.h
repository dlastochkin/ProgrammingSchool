
#include <QWidget.h>

class CChatServerGUI : public QObject
{
	Q_OBJECT

public:
	CChatServerGUI()
	{

	}
	~CChatServerGUI();

private:
	void drawClientsList();
	void drawMessageBox(); //������ ���������
	void drawMessageButton(); //������ ���������
	void drawTraceButton(); //������ ��� ������ ������
	void drawStartStop(); //������ ��� ������/��������� �������
	void drawServerInfo();
	void drawMoreBox();
	void drawChatList();

private slots:
	void startServer();
	void stopServer();
	void updateList();
	void sendMessageConectSlot(QString messsage);
	void sendMessageSlot(QString messsage);
	void traceSlot();
	void kickSlot();
	void showMoreSlot();

signals:
	void startServerSignal();
	void stopServerSignal();
	void updateListSignal();
	void sendMessageConectSignal(QString messsage);
	void sendMessageSignal(QString messsage);
	void traceSignal();
	void kickSignal();
	void showMoreSignal();
};


