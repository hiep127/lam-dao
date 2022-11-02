#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "AppMain.h"
#include <QQmlContext>
#include <QSortFilterProxyModel>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication application(argc, argv);

    QQmlApplicationEngine engine;

    AppMain app;
    app.initContext(engine.rootContext());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return application.exec();
}
