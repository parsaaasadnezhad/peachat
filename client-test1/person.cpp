#include "person.h"

Person::Person(QObject *parent) : QObject(parent)
{
    _Db = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL"));
    connectDb();

}

void Person::connectDb()
{
    _Db->setHostName("127.0.0.1");
    //    _Db->setPort(3306);
    _Db->setDatabaseName("paghsa");/*peachat1_leila*/
    _Db->setUserName("root");/*peachat1_paghsasdfsxv*/
    _Db->setPassword("");/*Parsamysql1379*/

    if(_Db->open())
    {
        qInfo() << "connected successfully";
    }
    else
    {
        qInfo() << "couldn't connect.";
        qInfo() << _Db->lastError().text();
    }

}

void Person::insert(QString username ,QString password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO user (username, password) VALUES (?,?)");
    query.bindValue(0 , username);
    query.bindValue(1 , password);
    if(query.exec())        // اینجا exec  و ورودی نگیرهه باید خالی باشه
    {
        qInfo() << "new person added successfully.";
        search(username , password);
    }
    else
    {
        qInfo() << "couldn't add person to database.";
        qInfo() << query.lastError().text();
        qInfo() << this->_Db->lastError().text();
    }
}

bool Person::search(QString username , QString password)
{
    QSqlQuery query;
    QString order = "SELECT * FROM paghsa.user WHERE username=:username AND password=:password";
    query.prepare(order);
    query.bindValue(":username" , username);
    query.bindValue(":password" , password);

    if(!query.exec())
    {
        qInfo() << _Db->lastError().text();
        qInfo() << query.lastError().text();
        return false;
    }
    if (query.first())
    {
        QSqlRecord record = query.record();
        int id = record.value(0).toInt();
        QString user = record.value(1).toString();
        QString pass = record.value("password").toString();

        emit clientConnection(user);
        qInfo() << id << " : " << username << " : " << password;
        return true;
    }
    else
    {
        qInfo() << "check your password or username.";
        return false;
    }

}
