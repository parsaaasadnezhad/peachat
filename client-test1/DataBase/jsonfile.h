#ifndef JSONFILE_H
#define JSONFILE_H

#include "abstractdb.h"
#include <QObject>

class JSonFile : public QObject
{
    Q_OBJECT
public:
    explicit JSonFile(AbstractDB *db , QObject *parent = nullptr);

signals:

private:
    AbstractDB *abstractDB = nullptr;
    void _readFile();

};

#endif // JSONFILE_H
