#ifndef ABSTRACTDB_H
#define ABSTRACTDB_H

#include "../DataAccess/persons.h"
#include "../DataAccess/person.h"
#include <QObject>

class AbstractDB : public QObject
{
    Q_OBJECT
public:
    explicit AbstractDB(QObject *parent = nullptr);

    void appendPerson(Person *person);
    Q_INVOKABLE bool search(const QString &username , const QString &password);

signals:
    void clientConnectionRequest(const QString &username);

private:
//    Persons *m_persons = nullptr;
    QList<Person*> m_persons;


};

#endif // ABSTRACTDB_H
