#include "jsonfile.h"

#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QIODevice>

JSonFile::JSonFile(AbstractDB *db , QObject *parent) : QObject(parent)
{
    abstractDB = db;
    _readFile();
}


void JSonFile::_readFile()
{
    QFile file(":/users.json");
    if (!file.open(QIODevice::ReadOnly))
    {
        qInfo() << "unable to open file";
        return;
    }
    QByteArray byteArray = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(byteArray);
    QJsonObject   obj = doc.object();
    QJsonArray    arr = obj[obj.keys().at(0)].toArray();

    for (const QJsonValue &item : arr)
    {
        Person* person = new Person(this);
        QString username , password , gmail;
//        QString userKey , passwordKey , gmailKey , idKey;
        int id;

        username = item["username"].toString();
        id       = item["id"].toInt();
        gmail    = item["email"].toString();
        password = item["password"].toString();

        person->setAttributes(username , id , password , gmail);
        abstractDB->appendPerson(person);
    }
}
