#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QList>
#include <QHostAddress>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QHostAddress>
#include "message.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);

    void updateServerRequest();
    void connectToServer(QHostAddress serverAdress);
    const QList<QHostAddress>& getHostList()
    { return m_hostList; }
    
signals:
    void serverListChanged();
public slots:
    void sendMessage(const Message& message);
private slots:
    void onNewServeurRecieved();
private:
    QTcpSocket *m_tcpSocket;
    QHostAddress m_serverAdress;
    QUdpSocket *m_pingSocket;
    QList<QHostAddress>  m_hostList;
    
};

#endif // CLIENT_H
