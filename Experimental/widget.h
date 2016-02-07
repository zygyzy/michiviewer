#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QDir>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <mediawidget.h>
#include <controlpanel.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void initialize(QString file);

private:
    Ui::Widget      *ui;
    MediaWidget     *m_mediaWidget;
    qint64           m_currentFile;
    QStringList      m_fileList;
    QString          m_folder;
    ControlPanel    *m_controlPanel;

    virtual void keyPressEvent(QKeyEvent* ev);
    void showMedia(int currentFile);

public slots:

    void openMedia();
    void play();
    void pause();
    void previous();
    void next();

};

#endif // WIDGET_H
