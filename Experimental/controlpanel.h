#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QWidget>

namespace Ui {
class ControlPanel;
}

class ControlPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ControlPanel(QWidget *parent = 0);
    ~ControlPanel();

private slots:
    void on_openButton_clicked();

    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_previousButton_clicked();

    void on_nextButton_clicked();

signals:
     void openMedia();
     void play();
     void pause();
     void previous();
     void next();

private:
    Ui::ControlPanel *ui;
};

#endif // CONTROLPANEL_H
