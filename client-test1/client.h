#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


class Client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString mosage READ mosage WRITE setMosage NOTIFY mosageChanged)
    Q_PROPERTY(bool onlineUser READ onlineUser WRITE setOnlineUser NOTIFY onlineUserChanged)

public:
    explicit Client(QObject *parent = nullptr);
    void connection(QString username);
    void setUsername(const QString &username);
    QString getUsername()const;
    Q_INVOKABLE void onlineUsers();
    void operator=(const Client &client);

    QString mosage() const;

    bool onlineUser() const;

public slots:
    void onReadyRead();
    void onConnected();
    void sendMessage(QString message);
    void sendClientInfo(QString username);

    void setMosage(QString mosage);

    void setOnlineUser(bool onlineUser);

    QList<QString> getOnlineUserList();

signals:
    void mosageChanged(QString mosage);

    void onlineUserChanged(bool onlineUser);

private:
    QTcpSocket *socket;
    QString _username;
//    QString _gmail;
//    QString _password;
//    int _id;

    QString m_mosage;
    bool m_onlineUser;

    QList <QString> onlineUserList;
};

#endif // CLIENT_H
