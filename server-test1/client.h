#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDataStream>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    bool setSocketDescriptor(qintptr handle);
    void sendMessage(const QString &message);
    void sendMessage(const QJsonObject &object);
    QString getUsername()const;
    void setUsername(const QString &username);

public slots:
    void onReadyRead();
    void onDisconnected();
    void onConnected();

signals:
    void received(const QJsonObject &object);
    void disconnected();

private:
    QTcpSocket *socket;
    QString username;
};

#endif // CLIENT_H
