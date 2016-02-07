#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QDir>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QDirIterator>
#include <QtAlgorithms>
#include <mediawidget.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void initializeFile(QString file);
    void initializeFolder(QString folder, bool recursively);

private:
    Ui::Widget      *ui;
    MediaWidget     *m_mediaWidget;
    qint64          m_currentFile;
    QStringList     m_fileList;
    QMenu           *m_menu;
    QMenuBar        *m_menuBar;
    QAction         *m_openDirAct;
    QAction         *m_openDirActRec;
    QAction         *m_openFileAct;
    QStringList     m_nameFilter;

    virtual void keyPressEvent(QKeyEvent* ev);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    void showMedia(int currentFile);

private slots:

    void openDir();
    void openDirRec();
    void openFile();

};

#endif // WIDGET_H
