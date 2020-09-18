#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    //
    socket = new QTcpSocket(this);
    connect(socket , &QTcpSocket::connected , this , &Client::onConnected);
    connect(socket , &QTcpSocket::readyRead , this , &Client::onReadyRead);
    connect(socket , &QTcpSocket::disconnected , this , &Client::onDisconnected);
}

bool Client::setSocketDescriptor(qintptr handle)
{
    return socket->setSocketDescriptor(handle);
}

void Client::sendMessage(const QString &message)
{
    QJsonObject object;
    object["type"]="message";
    object["text"]=message;
    QByteArray data = QJsonDocument(object).toJson();
    socket->write(data);
    qInfo()<<"send message string";
}

void Client::sendMessage(const QJsonObject &object)
{
    QByteArray data = QJsonDocument(object).toJson();
    socket->write(data);
    qInfo() << "send message object";
}

QString Client::getUsername() const
{
    return this->username;
}

void Client::setUsername(const QString &username)
{
    this->username = username;
}

void Client::onReadyRead()
{   
    QByteArray data;
    data = socket->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject object = doc.object();
    qInfo() << "from client in server: "<<object;
    emit received(object);
//    qInfo()<<object;
}

void Client::onConnected()
{
    qInfo() << "connected successfully";
}

void Client::onDisconnected()
{
    emit disconnected();
    qInfo() << "disconnected";
}
