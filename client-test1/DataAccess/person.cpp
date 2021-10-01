#include "person.h"

Person::Person(QObject *parent) : QObject(parent)
{
    connectDb();

}

void Person::connectDb()
{


}

void Person::setAttributes(const QString &username, int id, const QString &password, const QString &gmail)
{
    m_username = username;
    m_id       = id;
    m_password = password;
    m_gmail    =   gmail;
}

void Person::insert(QString username ,QString password)
{

}

bool Person::search(QString username , QString password)
{


}

int Person::id() const
{
    return m_id;
}

void Person::setId(int newId)
{
    m_id = newId;
}

const QString &Person::gmail() const
{
    return m_gmail;
}

void Person::setGmail(const QString &newGmail)
{
    m_gmail = newGmail;
}

const QString &Person::username() const
{
    return m_username;
}

void Person::setUsername(const QString &newUsername)
{
    m_username = newUsername;
}

const QString &Person::password() const
{
    return m_password;
}

void Person::setPassword(const QString &newPassword)
{
    m_password = newPassword;
}
