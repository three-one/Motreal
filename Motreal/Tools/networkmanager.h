#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#ifndef __cplusplus
#error You must use the CPlusPlus Complier!!!
#endif

#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>

// Prepear Decliar
class MString;

class NetworkManager : public QThread
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent = nullptr);
    ~NetworkManager();
    void SetServerConfig(const QString &ip, const quint16 &port);
protected slots:
    void CreateSocket();
    void Transmit(const QByteArray &str);
    void ReceiveMsg(QByteArray &str);
protected:
    void run();
private:
    NetworkManager(const NetworkManager &) = delete ;
    NetworkManager(const NetworkManager &&) = delete ;
    NetworkManager& operator=(const NetworkManager &) = delete ;
    NetworkManager& operator=(const NetworkManager &&) = delete ;
private:
    QTcpServer *pServer;
    QTcpSocket *pSocket;
    QHostAddress ServerAddr;
    quint16 ServerPort;
};

#endif // NETWORKMANAGER_H
