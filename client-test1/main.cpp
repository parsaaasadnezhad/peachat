
#include "DataBase/jsonfile.h"
#include "DataBase/abstractdb.h"
#include "DataAccess/person.h"
#include "client.h"
#include <configure.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    AbstractDB abstractDb;
    JSonFile jsFile(&abstractDb);

    Client client;

    QObject::connect(&abstractDb , &AbstractDB::clientConnectionRequest , &client , &Client::connection);
//    Person person;
//    QObject::connect(&person , &Person::clientConnection , &client , std::bind(&Client::connection , &client , std::placeholders::_1));
    Configure conf;
    engine.rootContext()->setContextProperty("Client" , &client);
    engine.rootContext()->setContextProperty("Database" , &abstractDb);
    engine.rootContext()->setContextProperty("Configure" , &conf);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);

    }, Qt::QueuedConnection);
    engine.load(url);

//    if(engine.rootObjects().isEmpty())
//        return -1;
//    else
//        client.setQmlRootObject(engine.rootObjects().first());

    return app.exec();
}
