#include "networkmanager.h"
#include <QMessageBox>

NetworkManager::NetworkManager(QObject *parent)
    : QThread(parent),
      pServer(new QTcpServer(this)),
      pSocket(nullptr)
{
    connect(pServer, &QTcpServer::newConnection, this,  &NetworkManager::CreateSocket);
}

NetworkManager::~NetworkManager()
{
    if(pSocket != nullptr) {
        if(pSocket->isOpen())
            pSocket->abort();
        pSocket->close();
        pSocket->deleteLater();
        pSocket = nullptr;
    }

    if(pServer != nullptr) {
        if(pServer->isListening())
            pServer->close();
        pServer->deleteLater();
        pServer = nullptr;
    }
}

void NetworkManager::SetServerConfig(const QString &ip, const quint16 &port)
{
    ServerPort = port;
}

void NetworkManager::CreateSocket()
{
    if(pSocket != nullptr) {
        pSocket->close();
        delete pSocket;
        pSocket = nullptr;
    }

    pSocket = pServer->nextPendingConnection();
    if(pSocket == nullptr) {
        QMessageBox::warning(nullptr, QString("Error"), QString("Create Socket Failure!!!"));
        return;
    }
}

void NetworkManager::Transmit(const QByteArray &str)
{

}

void NetworkManager::ReceiveMsg(QByteArray &str)
{

}

void NetworkManager::run()
{
    if(pServer == nullptr)
        pServer = new QTcpServer(this);

    pServer->listen();
    while(1) {
        ;
    }
}

