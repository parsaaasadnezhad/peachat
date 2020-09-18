#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDataStream>
#include <QDebug>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr , quint16 port = 1400);
    void connectToServer();
    void disconnectFromServer();
    void sendMessage(const QString &message);
    void sendLoginStatus(const QString &username);

private slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();


private:
    QTcpSocket *socket;
    quint16 port;
    void onJsonReceived(const QJsonObject &jsonObject);

};

#endif // CLIENT_H
