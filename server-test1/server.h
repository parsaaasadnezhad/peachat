#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include "client.h"

class Server : public QTcpServer
{
public:
    Server();
public slots:
    void receivedData(Client *sender , const QJsonObject &object);
    void disconnected(Client *disconnectedClient);

    // QTcpServer interface
protected:
    virtual void incomingConnection(qintptr handle);

private:
    QList <Client*> users;
};

#endif // SERVER_H
