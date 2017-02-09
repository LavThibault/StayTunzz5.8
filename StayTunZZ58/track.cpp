#include "track.h"
#include <iostream>

Track::Track(const QString &name,
             const QString &artist,
             const QString &album,
             const qint32 musId,
             const qint32 artId,
             const qint32 albID,
             QObject *parent):QObject(parent),m_trackName(name),m_trackArtist(artist),m_trackAlbum(album),m_musId(musId),m_artId(artId),m_albId(albID)
{

}

void Track::printTrack()
{
   std::cout<<"nom chanson :"<<trackName().toStdString()<<std::endl;
   std::cout<<"nom artiste :"<<trackArtist().toStdString()<<std::endl;
   std::cout<<"nom album :"<<trackAlbum().toStdString()<<std::endl;

}
