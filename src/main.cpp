#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setApplicationName("Game Of Life");
    QApplication::setApplicationVersion("0.1");
    QApplication::setOrganizationName("Alex R.");

    MainWindow w;
    w.show();

    return a.exec();
}
