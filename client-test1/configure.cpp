#include "configure.h"

Configure::Configure(QObject *parent) : QObject(parent)
{
    connect();
}

void Configure::connect()
{
    QFile file(":/language.json");

    if(file.open(QIODevice::ReadOnly))
    {
        qInfo() << "ok";
        QByteArray data = file.readAll();
        this->doc = QJsonDocument::fromJson(data);
    }

    else
    {
        qInfo() << "no";
    }

    file.close();
}

QString Configure::translate(QString filename, QString id , QString language)
{
    QJsonObject object = this->doc.object();

    QString result = object[filename].toObject()[id].toObject()[language].toString();
    return result;
}
