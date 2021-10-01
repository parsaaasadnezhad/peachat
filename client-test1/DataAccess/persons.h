#ifndef PERSONS_H
#define PERSONS_H

#include "person.h"
#include <QObject>

class Persons : public QObject
{
    Q_OBJECT
public:
    explicit Persons(QObject *parent = nullptr);
    void appendPerson(Person *person);
    [[nodiscard]]bool search(const QString &username, const QString &password);


signals:

private:
    std::vector<Person*> m_persons;
};

#endif // PERSONS_H
