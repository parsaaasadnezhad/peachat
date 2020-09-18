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

private:
    void connectDb();

public slots:

    void insert(QString username ,QString password);
//    void remove();
//    void update();
    bool search(QString username ,QString password);

signals:
    void clientConnection(QString username);

private:
    QSqlDatabase* _Db;
//    int _Id;
//    QString _Password;
//    QString _Username;
//    QString _Gmail;


};

#endif // PERSON_H
