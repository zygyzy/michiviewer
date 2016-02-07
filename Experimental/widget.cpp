#include "widget.h"
#include "ui_widget.h"





Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_mediaWidget = new MediaWidget(this);
    ui->verticalLayout->addWidget(m_mediaWidget);

    //m_controlPanel = new ControlPanel(this);
    //ui->verticalLayout->addWidget(m_controlPanel);

    connect(m_controlPanel, SIGNAL(openMedia()),this, SLOT(openMedia()));
    connect(m_controlPanel, SIGNAL(play()),this, SLOT(play()));
    connect(m_controlPanel, SIGNAL(pause()),this, SLOT(pause()));
    connect(m_controlPanel, SIGNAL(next()),this, SLOT(next()));
    connect(m_controlPanel, SIGNAL(previous()),this, SLOT(previous()));
}





Widget::~Widget()
{
    delete ui;
}





void Widget::keyPressEvent(QKeyEvent* ev)
{
    QWidget::keyPressEvent(ev);
    if (ev -> key() == Qt::Key_Escape)
    {
        if (isFullScreen())
        {
            showMaximized();
            //m_controlPanel->show();
        }
        else
        {
            showFullScreen();
            //m_controlPanel->hide();
        }
    }
    if (ev -> key() == Qt::Key_M)
    {
        next();
    }
    if (ev -> key() == Qt::Key_N)
    {
        previous();
    }
}





void Widget::initialize(QString file)
{
    file = "C:\\Users\\Michi\\Downloads\\Snowboard Trick Tips_ How to Ollie.mpg";
    if (!file.isEmpty())
    {
        m_currentFile = 0;
        this->setWindowTitle(file);

        QDir dir(file);
        QString baseName = dir.dirName();
        dir.cdUp();
        QStringList nameFilter;
        nameFilter << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp" << "*.gif" << "*.tif" << "*.tiff" << "*.tga" << "*.wmv" << "*.mp4" << "*.mpg" << "*.mpeg" << "*.avi" << "*.mov";
        m_fileList = dir.entryList(nameFilter, QDir::Files);
        m_folder = dir.absolutePath();

        for (qint64 i=0; i <= m_fileList.size()-1; i++)
        {
            QString currentBaseName = m_fileList.at(i);
            if (baseName.compare(currentBaseName, Qt::CaseInsensitive) == 0)
                m_currentFile = i;
        }
        //showFullScreen();
        showMedia(m_currentFile);
        showMaximized();
    }
    else
        showMaximized();
}





void Widget::showMedia(int currentFile)
{
    if (m_fileList.size() > 0)
    {
        m_mediaWidget->showMedia(this->m_folder + "\\" + this->m_fileList.at(currentFile));
    }
}





void Widget::openMedia()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Media File","","Files (*.*)");
    initialize(fileName);
}





void Widget::play()
{

}





void Widget::pause()
{}





void Widget::previous()
{
    if (m_currentFile == 0)
        m_currentFile = m_fileList.size()-1;
    else
        m_currentFile--;
    showMedia(m_currentFile);
}





void Widget::next()
{
    if (m_currentFile == m_fileList.size()-1)
        m_currentFile = 0;
    else
        m_currentFile++;
    showMedia(m_currentFile);
}
