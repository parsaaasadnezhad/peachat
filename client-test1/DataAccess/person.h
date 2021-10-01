#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <client.h>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);
    void setAttributes(const QString &username , int id , const QString &password , const QString &gmail);

    const QString &password() const;
    void setPassword(const QString &newPassword);

    const QString &username() const;
    void setUsername(const QString &newUsername);

    const QString &gmail() const;
    void setGmail(const QString &newGmail);

    int id() const;
    void setId(int newId);

private:
    void connectDb();
public slots:
    void insert(QString username ,QString password);
    bool search(QString username ,QString password);
//    void remove();
//    void update();

signals:
    void clientConnection(QString username);

private:
    int    m_id;
    QString m_password;
    QString m_username;
    QString m_gmail;


};

#endif // PERSON_H
