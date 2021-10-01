#include "persons.h"
#include <algorithm>
#include <QDebug>

Persons::Persons(QObject *parent) : QObject(parent)
{

}

void Persons::appendPerson(Person *person)
{
    qInfo() << person->username();
    m_persons.push_back(person);
}

bool Persons::search(const QString &username, const QString &password)
{
    qInfo() << m_persons.size();
    for (Person *person : m_persons)
    {
        if (person->username() == username)
            if (person->password() == password)
                return true;
    }
    return false;
}
