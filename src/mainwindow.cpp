#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Сначала все обнулить
    m_proc  = nullptr;
    currentIteration = 0;
    currentCellCount = 0;

    // Зададим текст для статусбара
    statusBarText   = QString(tr("Поколение: %1;\tКоличество живых клеток: %2"))
            .arg(QString::number(currentIteration))
            .arg(QString::number(currentCellCount));

    // Выделим память под m_label и перекинем в статусбар
    m_label = new QLabel(statusBarText, ui->statusBar);
    ui->statusBar->addWidget(m_label);
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
    connect(m_proc, SIGNAL(sigGenIteration(uint,uint)), SLOT(slotIteration(uint,uint)));
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
    QString _out = QString(tr("Игра окончена на %1 итерации")).
            arg(QString::number(currentIteration));
    QMessageBox::warning(this, tr("Конец"), _out);
}

void MainWindow::slotIteration(uint genNum, uint aliveCellsCount)
{
    // Стот новой итерации

//    currentIteration = genNum;
//    currentCellCount = aliveCellsCount;

//    m_label->setText(statusBarText);

}
