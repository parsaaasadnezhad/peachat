#include "abstractdb.h"
#include <QDebug>

AbstractDB::AbstractDB(QObject *parent) : QObject(parent)
{
//    m_persons = new Persons(this);
}

void AbstractDB::appendPerson(Person *person)
{
//    m_persons->appendPerson(person);
    m_persons.append(person);
    qInfo() << m_persons.size();

}

bool AbstractDB::search(const QString &username, const QString &password)
{

    for (Person *person : qAsConst(m_persons))
    {
        if (person->username() == username)
            if (person->password() == password)
            {
                emit clientConnectionRequest(username);
                return true;
            }
    }
    return false;
//    if (m_persons->search(username , password))
//    {
//        return true;
//    }
//    return false;
}
