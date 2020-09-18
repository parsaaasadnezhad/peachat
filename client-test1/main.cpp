#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "client.h"
#include <person.h>
#include <configure.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;
    Client client;
    Person person;
    QObject::connect(&person , &Person::clientConnection , &client , std::bind(&Client::connection , &client , std::placeholders::_1));
    Configure conf;
    engine.rootContext()->setContextProperty("Client" , &client);
    engine.rootContext()->setContextProperty("Database" , &person);
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
