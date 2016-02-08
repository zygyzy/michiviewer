#include "widget.h"
#include "ui_widget.h"





Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_mediaWidget = new MediaWidget;
    ui->verticalLayout->addWidget(m_mediaWidget);

    m_menuBar = new QMenuBar(this);
    m_menu = m_menuBar->addMenu("Open");
    m_openFileAct = new QAction("File", this);
    m_openDirAct = new QAction("Directory", this);
    m_openDirActRec = new QAction("Directory (Recursively)", this);
    m_menu->addAction(m_openFileAct);
    m_menu->addAction(m_openDirAct);
    m_menu->addAction(m_openDirActRec);
    connect(m_openFileAct, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(m_openDirAct, SIGNAL(triggered()), this, SLOT(openDir()));
    connect(m_openDirActRec, SIGNAL(triggered()), this, SLOT(openDirRec()));
}





Widget::~Widget()
{
    delete m_mediaWidget;
    delete ui;
}





void Widget::keyPressEvent(QKeyEvent* ev)
{
    QWidget::keyPressEvent(ev);
    if (ev -> key() == Qt::Key_Escape)
    {
        QApplication::quit();
    }
    if (ev -> key() == Qt::Key_Right)
    {
        if (m_currentFile == m_playList.size()-1)
            m_currentFile = 0;
        else
            m_currentFile++;
        showMedia(m_currentFile);
    }
    if (ev -> key() == Qt::Key_Left)
    {
        if (m_currentFile == 0)
            m_currentFile = m_playList.size()-1;
        else
            m_currentFile--;
        showMedia(m_currentFile);
    }
}





void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (isFullScreen())
    {
        showMaximized();
        m_menuBar->show();
    }
    else
    {
        showFullScreen();
        m_menuBar->hide();
    }
    showMedia(m_currentFile);
}





void Widget::initializePlaylistWithFile(QString file)
{
    if (!file.isEmpty())
    {
        m_currentFile = 0;
        m_playList.clear();
        m_playList.append(file);
        showMedia(m_currentFile);
    }
    showMaximized();
}





void Widget::initializePlaylistWithFolder(QString folder, bool recursively)
{
    if (!folder.isEmpty())
    {
        m_currentFile = 0;
        m_playList.clear();
        m_playList = Utility::getPlaylist(folder, recursively);
        showMedia(m_currentFile);
    }
    showMaximized();
}





void Widget::showMedia(int currentFile)
{
    if (m_playList.size() > 0)
    {
        this->setWindowTitle(this->m_playList.at(currentFile));
        m_mediaWidget->showMedia(this->m_playList.at(currentFile));
    }
}





void Widget::openDir()
{
    QString dirName = QFileDialog::getExistingDirectory(this, "Open Directory", "", QFileDialog::ShowDirsOnly);
    initializePlaylistWithFolder(dirName, false);
}





void Widget::openDirRec()
{
    QString dirName = QFileDialog::getExistingDirectory(this, "Open Directory and Subdirectories", "", QFileDialog::ShowDirsOnly);
    initializePlaylistWithFolder(dirName, true);
}





void Widget::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Files (*.*)");
    initializePlaylistWithFile(fileName);
}
