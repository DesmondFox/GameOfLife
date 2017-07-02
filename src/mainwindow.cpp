#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "start";
    LifeMatrix *mt = new LifeMatrix(this);
    LifeMatrix *mx = new LifeMatrix(this);
    mt->allocate(50, 21);
    mx->allocate(49, 50);

    if (mt == mx)
        qDebug() << "ololo";

}

MainWindow::~MainWindow()
{
    delete ui;
}
