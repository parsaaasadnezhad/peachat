#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QObject>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include <QIODevice>

class Configure : public QObject
{
    Q_OBJECT
public:
    explicit Configure(QObject *parent = nullptr);
    void connect();

public slots:
    QString translate(QString filename , QString id , QString language);

signals:

private:
    QJsonDocument doc;

};

#endif // CONFIGURE_H
