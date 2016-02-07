#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileInfo>

namespace Ui {
class MediaWidget;
}

class MediaWidget : public QWidget
{
    Q_OBJECT

public:

    explicit MediaWidget(QWidget *parent = 0);
    ~MediaWidget();
    void showMedia(QString file);
    void play();
    void pause();

private:

    Ui::MediaWidget *ui;
    QMediaPlayer    m_mediaPlayer;
    QVideoWidget    *m_videoWidget;

    void showImage(QString file);
    void showVideo(QString file);
};

#endif // MEDIAWIDGET_H
