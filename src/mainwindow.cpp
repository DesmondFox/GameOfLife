#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Сначала все указатели прировнять nullptr. На всякий случай
    m_proc  = nullptr;


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *event)
{
    qDebug() << "Notice:\t Window has been loaded: " << event->type();
    // Действия уже при загрузке окна
    // Узнать значение вьюпорта и закинуть в класс обработки
    m_proc  = new Processing(ui->graphicsView->viewport()->width(),
                             ui->graphicsView->viewport()->height(), 10, this);
    ui->graphicsView->setScene(m_proc->getScene());
    ui->graphicsView->setMouseTracking(true);

    connect(m_proc, SIGNAL(sigGameOver()), SLOT(slotEndOfGame()));
}

void MainWindow::setButtonsEnabled(bool enabled)
{
    // Установка доступности кнопок при старте/стопе

    ui->pushSettings->setEnabled(enabled);
    ui->pushClear->setEnabled(enabled);
    ui->pushNextStep->setEnabled(enabled);
}

void MainWindow::on_pushStartPause_clicked()
{
    this->setButtonsEnabled(!ui->pushStartPause->isChecked());
    if (ui->pushStartPause->isChecked())
    {

    }
    else
    {

    }
}

void MainWindow::on_pushNextStep_clicked()
{
    m_proc->solveOneStep();
}

void MainWindow::slotEndOfGame()
{
    QMessageBox::warning(this, "ss", "ololo");
}
