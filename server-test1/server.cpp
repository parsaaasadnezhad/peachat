#include "server.h"

Server::Server()
{
    if(this->listen(QHostAddress::Any , 2020))
        qInfo() << "listning";
    else
        qInfo() << "no listening";
}

void Server::incomingConnection(qintptr handle)
{
    qInfo() << "incomming connection";
    Client *client = new Client(this);
    if(!client->setSocketDescriptor(handle))
    {
        return;
    }
    connect(client , &Client::received , this , std::bind(&Server::receivedData , this , client , std::placeholders::_1));
    connect(client , &Client::disconnected , this , std::bind(&Server::disconnected , this , client));

    //    QString data = "new user joined.";
    //    QJsonObject object;
    //    object["type"] = "login";
    //    object["text"] = data;
    //    foreach(Client *user , users)
    //    {
    //        user->sendMessage(object);
    //        delete user;
    //    }

    users << client;

    //    QJsonObject object;
    //    QJsonArray list;
    //    object["type"] = "onlineUsers";

    //    foreach(Client* user , users)
    //    {
    //        list.push_back(user->getUsername());
    //    }
    //    object["users"] = list;

    //    foreach(Client *user , users)
    //    {
    //        user->sendMessage(object);
    //    }
}

void Server::receivedData(Client *sender, const QJsonObject &object)
{
    QString type = object["type"].toString();
    qInfo() << type;
    if(type == "message")
    {
        foreach(Client* user , users)
        {
            if(user != sender)
            {
                QString data = object["text"].toString();
                user->sendMessage(data);
            }
        }
    }
    else if(type == "onlineUsers")
    {
        QJsonObject object;
        QJsonArray list;
        object["type"] = "onlineUsers";

        foreach(Client* user , users)
        {
            list.push_back(user->getUsername());
        }
        object["users"] = list;
        sender->sendMessage(object);
    }
    else if(type == "userInfo")
    {
        QString username = object["text"].toString();
        sender->setUsername(username);
    }
}

void Server::disconnected(Client *disconnectedClient)
{
    users.removeAt(users.indexOf(disconnectedClient));
    QString data = disconnectedClient->getUsername() + " left.";
    QJsonObject object;
    object["type"] = "left";
    object["text"] = data;
    foreach(Client *user , users)
    {
        if(user != disconnectedClient)
            user->sendMessage(object);
        //        delete user;
    }
}
