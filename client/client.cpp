#include "client.h"

Client::Client(QObject *parent, quint16 port) : QObject(parent)
{
    socket = new QTcpSocket();
    this->port = port;

    connect(socket , &QTcpSocket::connected , this , &Client::onConnected);
    connect(socket , &QTcpSocket::disconnected , this , &Client::onDisconnected);
    connect(socket , &QTcpSocket::readyRead , this , &Client::onReadyRead);
}

void Client::connectToServer()
{
    socket->connectToHost("127.0.0.1" , port);
    sendMessage("paghsa");
}

void Client::disconnectFromServer()
{
    socket->disconnectFromHost();
    socket->close();
    socket->deleteLater();
}

void Client::sendMessage(const QString &message)
{
    QDataStream data(socket);
    data.setVersion(QDataStream::Qt_5_15);
    QJsonObject object;
    object["type"] = "message";
    object["text"] = message;
    data << QJsonDocument(object).toJson();
}

void Client::sendLoginStatus(const QString &username)
{
    QDataStream data(socket);
    data.setVersion(QDataStream::Qt_5_15);
    QJsonObject object;
    object["type"] = "login";
    object["username"] = username;
    data << QJsonDocument(object).toJson();
}

void Client::onReadyRead()
{
    QByteArray jsonData;
    QDataStream data(socket);
    data.setVersion(QDataStream::Qt_5_15);
    data >> jsonData;
    const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    onJsonReceived(jsonDoc.object());
}

void Client::onConnected()
{
    qInfo() << "connected.";
}

void Client::onDisconnected()
{
    qInfo() << "disconnected.";
}

void Client::onJsonReceived(const QJsonObject &jsonObject)
{
    qInfo() << jsonObject;
}
