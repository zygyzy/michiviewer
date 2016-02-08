#include "utility.h"





Utility::Utility(QObject *parent) : QObject(parent)
{
}





bool Utility::isVideo(QFileInfo info)
{
    QStringList l = getValidVideoExts();
    QString suffix = info.completeSuffix();
    suffix = suffix.toLower();
    if (l.contains(suffix, Qt::CaseInsensitive))
        return true;
    else
        return false;
}





bool Utility::isPhoto(QFileInfo info)
{
    QStringList l = getValidPhotoExts();
    QString suffix = info.completeSuffix();
    suffix = suffix.toLower();
    if (l.contains(suffix, Qt::CaseInsensitive))
        return true;
    else
        return false;
}





QStringList Utility::getPlaylist(QString folder, bool recursively)
{
    QStringList playList;
    QStringList suffixList = getValidPhotoExts() + getValidVideoExts();

    if (recursively)
    {
        QDirIterator it(folder, QDirIterator::Subdirectories);
        while(it.hasNext())
        {
            it.next();
            foreach(QString suffix, suffixList)
            {
                suffix.remove(0,2);
                QString currentSuffix = it.fileInfo().completeSuffix();
                if(suffix.compare(currentSuffix, Qt::CaseInsensitive) == 0)
                {
                    playList.append(it.fileInfo().absoluteFilePath());
                    break;
                }
            }
        }
        playList.sort(Qt::CaseInsensitive);
    }
    else
    {
        QDir dir(folder);
        foreach(QString file, dir.entryList(suffixList, QDir::Files))
            playList.append(folder + "\\" + file);
    }


    return playList;
}





QStringList Utility::getValidVideoExts()
{
    QStringList list;
    list << "*.wmv" << "*.mp4" << "*.mpg" << "*.mpeg" << "*.avi" << "*.mov" << "*.mkv" << "*.ogg";
    return list;
}





QStringList Utility::getValidPhotoExts()
{
    QStringList list;
    list << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp" << "*.gif" << "*.tif" << "*.tiff" << "*.tga";
    return list;
}









