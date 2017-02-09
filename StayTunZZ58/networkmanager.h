#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QtNetwork>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QIODevice>
#include <QJsonObject>
#include "track.h"
class NetWorkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetWorkManager(QObject *parent = 0);
    void launchTrackRequest(const QString &trackName);
signals:
    void launchTrack(Track* track);

public slots:
    void replyTrackFinished(QNetworkReply* reply);
private :
    QNetworkAccessManager* manager;
    QJsonParseError error;

};

#endif // NETWORKMANAGER_H
