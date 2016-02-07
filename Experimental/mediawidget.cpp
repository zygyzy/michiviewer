#include "mediawidget.h"
#include "ui_mediawidget.h"





MediaWidget::MediaWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MediaWidget)
{
    ui->setupUi(this);
    m_videoWidget = new QVideoWidget;
    ui->verticalLayout->addWidget(m_videoWidget);
    m_mediaPlayer.setVideoOutput(m_videoWidget);
}





MediaWidget::~MediaWidget()
{
    delete m_videoWidget;
    delete ui;
}





void MediaWidget::showMedia(QString file)
{
    if (!file.isEmpty())
    {
        QFileInfo info(file);
        QString suffix = info.completeSuffix();
        suffix = suffix.toLower();
        if (suffix == "avi" || suffix == "mpg" || suffix == "mpeg" || suffix == "mp4" || suffix == "mov" || suffix == "wmv")
            showVideo(file);
        else
            showImage(file);
    }
}





void MediaWidget::play()
{
}





void MediaWidget::pause()
{
}





void MediaWidget::showImage(QString file)
{
    if (!file.isEmpty())
    {
        m_mediaPlayer.stop();
        m_videoWidget->hide();
        ui->imageViewer->show();
        QPixmap pixmap(file);
        pixmap = pixmap.scaled(QSize(1920,1080),Qt::KeepAspectRatio,Qt::SmoothTransformation);
        //pixmap = pixmap.scaled(QSize(this->parentWidget()->width(),this->parentWidget()->height()),Qt::KeepAspectRatio,Qt::SmoothTransformation);
        ui->imageViewer->setPixmap(pixmap);
    }
}





void MediaWidget::showVideo(QString file)
{
    if (!file.isEmpty())
    {
        ui->imageViewer->hide();
        m_videoWidget->show();
        m_mediaPlayer.setMedia(QUrl::fromLocalFile(file));
        m_mediaPlayer.play();
    }
}
