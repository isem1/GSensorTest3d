#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "model/PortSettingsModel.h"

int main(int argc, char** argv) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    PortSettingsModel::registerQmlType();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return EXIT_FAILURE;

    return app.exec();
}
