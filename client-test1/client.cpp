#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    this->socket = new QTcpSocket(this);
}

void Client::connection(QString username)
{
    _username = username;
    m_onlineUser = false;
    socket->connectToHost("127.0.0.1" , 2020);
    connect(socket , &QTcpSocket::connected , this , &Client::onConnected);
    connect(socket , &QTcpSocket::readyRead , this , &Client::onReadyRead);
    sendClientInfo(_username);
    //    qInfo() << "usernmae  "<<_username;
}

void Client::onlineUsers()
{
//    qInfo() << "onlineusers is called";
    QJsonObject object;
    object["type"] = "onlineUsers";
    socket->write(QJsonDocument(object).toJson());
}

void Client::operator=(const Client &client)
{
    this->socket = client.socket;
}

void Client::onReadyRead()
{
    QByteArray data;
    data = socket->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject object = doc.object();
    QString type = object["type"].toString();
    if(type == "message")
    {
        setMosage(object["text"].toString());
    }
    else if(type == "login")
    {
        setMosage(object["text"].toString());
    }
    else if(type == "left")
    {
        setMosage(object["text"].toString());
    }
    else if(type == "onlineUsers")
    {
        onlineUserList.clear();
        for(int i=0 ; i<object["users"].toArray().count() ; i++)
            onlineUserList.append(object["users"].toArray()[i].toString());
        if(m_onlineUser == true)
            setOnlineUser(false);
        else
            setOnlineUser(true);
    }
}

void Client::onConnected()
{
    qInfo() << "socket connected successfully";
}

void Client::sendMessage(QString message)
{ 
    //    qInfo() << message;
    QJsonObject object;
    object["type"] = "message";
    object["text"] = this->_username + ": " + message;
    socket->write(QJsonDocument(object).toJson());
    socket->waitForBytesWritten();
}

void Client::sendClientInfo(QString username)
{
    QJsonObject object;
    object["type"] = "userInfo";
    object["text"] = username;
    socket->write(QJsonDocument(object).toJson());
}

void Client::setMosage(QString mosage)
{
    if (m_mosage == mosage)
        return;

    m_mosage = mosage;
    emit mosageChanged(m_mosage);
}

void Client::setOnlineUser(bool onlineUser)
{
    if (m_onlineUser == onlineUser)
        return;

    m_onlineUser = onlineUser;
    emit onlineUserChanged(m_onlineUser);
}

QList<QString> Client::getOnlineUserList()
{
    return onlineUserList;
}


QString Client::mosage() const
{
    return m_mosage;
}

bool Client::onlineUser() const
{

    return m_onlineUser;
}

void Client::setUsername(const QString &username)
{
    _username = username;
}

QString Client::getUsername() const
{
    return _username;
}

