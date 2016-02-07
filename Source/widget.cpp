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

    m_nameFilter << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp" << "*.gif" << "*.tif" << "*.tiff" << "*.tga"
                 << "*.wmv" << "*.mp4" << "*.mpg" << "*.mpeg" << "*.avi" << "*.mov" << "*.mkv" << "*.ogg";
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
        if (m_currentFile == m_fileList.size()-1)
            m_currentFile = 0;
        else
            m_currentFile++;
        showMedia(m_currentFile);
    }
    if (ev -> key() == Qt::Key_Left)
    {
        if (m_currentFile == 0)
            m_currentFile = m_fileList.size()-1;
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





void Widget::initializeFile(QString file)
{
    if (!file.isEmpty())
    {
        m_currentFile = 0;
        m_fileList.clear();
        m_fileList.append(file);
        showMedia(m_currentFile);
    }
    showMaximized();
}





void Widget::initializeFolder(QString folder, bool recursively)
{
    if (!folder.isEmpty())
    {
        m_currentFile = 0;
        m_fileList.clear();

        if (recursively)
        {
            QDirIterator it(folder, QDirIterator::Subdirectories);
            while(it.hasNext())
            {
                it.next();
                foreach(QString suffix, m_nameFilter)
                {
                    suffix.remove(0,2);
                    QString currentSuffix = it.fileInfo().completeSuffix();
                    if(suffix.compare(currentSuffix, Qt::CaseInsensitive) == 0)
                    {
                        m_fileList.append(it.fileInfo().absoluteFilePath());
                        break;
                    }
                }
            }
            m_fileList.sort(Qt::CaseInsensitive);
        }
        else
        {
            QDir dir(folder);
            foreach(QString file, dir.entryList(m_nameFilter, QDir::Files))
                m_fileList.append(folder + "\\" + file);
        }

        showMedia(m_currentFile);
    }
    showMaximized();
}





void Widget::showMedia(int currentFile)
{
    if (m_fileList.size() > 0)
    {
        this->setWindowTitle(this->m_fileList.at(currentFile));
        m_mediaWidget->showMedia(this->m_fileList.at(currentFile));
    }
}





void Widget::openDir()
{
    QString dirName = QFileDialog::getExistingDirectory(this, "Open Directory", "", QFileDialog::ShowDirsOnly);
    initializeFolder(dirName, false);
}





void Widget::openDirRec()
{
    QString dirName = QFileDialog::getExistingDirectory(this, "Open Directory and Subdirectories", "", QFileDialog::ShowDirsOnly);
    initializeFolder(dirName, true);
}





void Widget::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Files (*.*)");
    initializeFile(fileName);
}
