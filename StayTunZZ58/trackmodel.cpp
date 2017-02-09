#include "trackmodel.h"

TrackModel::TrackModel(QObject *parent)
{

}

void TrackModel::ajouterTrack(Track *track)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    m_TrackList.operator <<(track);
    endInsertRows();

    track->printTrack();
}

int TrackModel::rowCount(const QModelIndex &parent) const
{
    return m_TrackList.count();
}

QVariant TrackModel::data(const QModelIndex &index, int role) const
{
    if (index.row()<0 || index.row()> m_TrackList.count())
        return QVariant();
     const Track* tr=m_TrackList[index.row()];

    if(role==TrackNameRole)
        return tr->trackName();
    if(role==TrackArtistRole)
        return tr->trackArtist();
    if(role==TrackAlbumRole)
        return tr->trackAlbum();

    return QVariant();
}

QHash<int, QByteArray> TrackModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TrackNameRole]="trackName";
    roles[TrackArtistRole]="trackArtist";
    roles[TrackAlbumRole]="trackAlbum";
    return roles;
}

void TrackModel::trackReceived(Track* tracRec)
{
    ajouterTrack(tracRec);
}
