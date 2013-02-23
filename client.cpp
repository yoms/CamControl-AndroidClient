#include "client.h"
#include <QUdpSocket>
Client::Client(QObject *parent) :
    QObject(parent)
{
    m_tcpSocket = new QTcpSocket(this);
    m_pingSocket = new QUdpSocket(this);
    connect(m_pingSocket, SIGNAL(readyRead()),
            SLOT(onNewServeurRecieved()));
    m_pingSocket->bind(QHostAddress::Any, 8002);
}

void Client::updateServerRequest()
{
    m_pingSocket->writeDatagram("ping", QHostAddress::Broadcast, 8000);
}

void Client::connectToServer(QHostAddress serverAdress)
{
    m_serverAdress = serverAdress;
    m_tcpSocket->connectToHost(m_serverAdress, 8001);
}

void Client::sendCommand(const QByteArray& command)
{
    while(!m_tcpSocket->isWritable());
        m_tcpSocket->write(command);
}

void Client::onNewServeurRecieved()
{
    qDebug() << "NewServeurRecieved";
    while (m_pingSocket->hasPendingDatagrams()) {
         QByteArray datagram;
         datagram.resize(m_pingSocket->pendingDatagramSize());
         QHostAddress sender;
         quint16 senderPort;

         m_pingSocket->readDatagram(datagram.data(), datagram.size(),
                                 &sender, &senderPort);
         if(!m_hostList.contains(sender))
         {
             m_hostList << sender;
             emit serverListChanged();
         }
     }

}
