#include "networkmanager.h"
#include <iostream>

NetWorkManager::NetWorkManager(QObject *parent) : QObject(parent)
{
    manager=new QNetworkAccessManager();



}

void NetWorkManager::launchTrackRequest(const QString &trackName)
{
    QString request="https://api.deezer.com/search?q=track:\""+trackName+"\"";
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyTrackFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(request)));
}

void NetWorkManager::replyTrackFinished(QNetworkReply *reply)
{
    QJsonDocument mJsonFile;
    if (1){

            mJsonFile = QJsonDocument::fromJson(reply->readAll(), &error);

            }
        else{
            std::cout << "Error: File not found!"<<std::endl;
        }

        if (mJsonFile.isNull() || mJsonFile.isEmpty()){
            std::cout << "Error: " << error.errorString().toStdString() << std::endl;
            }
        else{
            std::cout<< " has been parsed correctly."<<std::endl;
            }
        if(mJsonFile.object()["total"].toInt()==0)
        {
            std::cout<<"no result found"<<std::endl;
        }else{
            foreach (QJsonValue field, mJsonFile.object()["data"].toArray()) {
                Track* track=new Track(field.toObject()["title"].toString());
                launchTrack(track);

            }

        }

}
