#include "controlpanel.h"
#include "ui_controlpanel.h"

ControlPanel::ControlPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlPanel)
{
    ui->setupUi(this);
    ui->openButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    ui->previousButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    ui->nextButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
}

ControlPanel::~ControlPanel()
{
    delete ui;
}

void ControlPanel::on_openButton_clicked()
{
    emit openMedia();
}

void ControlPanel::on_playButton_clicked()
{
    emit play();
}

void ControlPanel::on_pauseButton_clicked()
{
    emit pause();
}

void ControlPanel::on_previousButton_clicked()
{
    emit previous();
}

void ControlPanel::on_nextButton_clicked()
{
    emit next();
}
