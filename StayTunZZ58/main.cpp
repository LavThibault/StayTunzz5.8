#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "track.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Track t("la zoubida","lagaffe","unknow",1,2,3);
    t.printTrack();
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));




    return app.exec();
}
