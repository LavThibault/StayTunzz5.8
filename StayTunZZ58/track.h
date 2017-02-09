#ifndef TRACK_H
#define TRACK_H

#include <QObject>

class Track : public QObject
{
    Q_OBJECT
    QString m_trackName;

    QString m_trackArtist;

    QString m_trackAlbum;

    qint32 m_musId;

    qint32 m_artId;

    qint32 m_albId;

public:
    explicit Track(const QString &name,const QString &artist="NULL",const QString &album="NULL",const qint32 musId=0,const qint32 artId=0,const qint32 albID=0,QObject *parent = 0);


    Q_PROPERTY(QString trackName READ trackName WRITE setTrackName NOTIFY trackNameChanged)
    Q_PROPERTY(QString trackArtist READ trackArtist WRITE setTrackArtist NOTIFY trackArtistChanged)
    Q_PROPERTY(QString trackAlbum READ trackAlbum WRITE setTrackAlbum NOTIFY trackAlbumChanged)
    Q_PROPERTY(qint32 musId READ musId WRITE setMusId NOTIFY musIdChanged)
    Q_PROPERTY(qint32 artId READ artId WRITE setArtId NOTIFY artIdChanged)
    Q_PROPERTY(qint32 albId READ albId WRITE setAlbId NOTIFY albIdChanged)


    void printTrack();

QString trackName() const
{
    return m_trackName;
}

QString trackArtist() const
{
    return m_trackArtist;
}

QString trackAlbum() const
{
    return m_trackAlbum;
}

qint32 musId() const
{
    return m_musId;
}

qint32 artId() const
{
    return m_artId;
}

qint32 albId() const
{
    return m_albId;
}

signals:

void trackNameChanged(QString trackName);

void trackArtistChanged(QString trackArtist);

void trackAlbumChanged(QString trackAlbum);

void musIdChanged(qint32 musId);

void artIdChanged(qint32 artId);

void albIdChanged(qint32 albId);

public slots:
void setTrackName(QString trackName)
{
    if (m_trackName == trackName)
        return;

    m_trackName = trackName;
    emit trackNameChanged(trackName);
}
void setTrackArtist(QString trackArtist)
{
    if (m_trackArtist == trackArtist)
        return;

    m_trackArtist = trackArtist;
    emit trackArtistChanged(trackArtist);
}
void setTrackAlbum(QString trackAlbum)
{
    if (m_trackAlbum == trackAlbum)
        return;

    m_trackAlbum = trackAlbum;
    emit trackAlbumChanged(trackAlbum);
}
void setMusId(qint32 musId)
{
    if (m_musId == musId)
        return;

    m_musId = musId;
    emit musIdChanged(musId);
}
void setArtId(qint32 artId)
{
    if (m_artId == artId)
        return;

    m_artId = artId;
    emit artIdChanged(artId);
}
void setAlbId(qint32 albId)
{
    if (m_albId == albId)
        return;

    m_albId = albId;
    emit albIdChanged(albId);
}
};

#endif // TRACK_H
