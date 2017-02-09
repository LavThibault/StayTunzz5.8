#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "track.h"
#include "trackmodel.h"
#include "networkmanager.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    NetWorkManager myMan;
    TrackModel myTrackModel;
    QObject::connect(&myMan,SIGNAL(launchTrack(Track* )),&myTrackModel,SLOT(trackReceived(Track*)));
    myMan.launchTrackRequest("i need a dollar");
    engine.rootContext()->setContextProperty("trackModel",&myTrackModel);


    engine.load(QUrl(QLatin1String("qrc:/main.qml")));




    return app.exec();
}
