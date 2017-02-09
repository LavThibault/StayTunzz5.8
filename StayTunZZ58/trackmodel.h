#ifndef TRACKMODEL_H
#define TRACKMODEL_H
#include <QAbstractListModel>
#include "track.h"

class TrackModel:public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TrackModel(QObject* parent=0);

    enum TrackRole{
        TypeRole=Qt::UserRole+1,TrackNameRole,TrackArtistRole,TrackAlbumRole
    };

    void ajouterTrack(Track* track);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int,QByteArray> roleNames() const;
public slots:
    void trackReceived(Track* tracRec);
private :
    QList<Track*> m_TrackList;
};


#endif // TRACKMODEL_H
