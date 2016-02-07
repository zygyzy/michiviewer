#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.initialize(argv[1]);
    w.showMaximized();
    return a.exec();
}
