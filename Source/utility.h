#ifndef UTILITY_H
#define UTILITY_H

#include <QObject>
#include <QFileInfo>
#include <QStringList>
#include <QDirIterator>

class Utility : public QObject
{
    Q_OBJECT
public:
    explicit Utility(QObject *parent = 0);

    static bool isVideo(QFileInfo info);
    static bool isPhoto(QFileInfo info);
    static QStringList getPlaylist(QString folder, bool recursively);

private:
    static QStringList getValidVideoExts();
    static QStringList getValidPhotoExts();

signals:

public slots:

};

#endif // UTILITY_H
