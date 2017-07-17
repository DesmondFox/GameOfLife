#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::updateStatusBar(uint _gen, uint _alive)
{
    // Обновление текст статусбара

    QString _str  = QString(tr("Поколение: %1;\tКоличество живых клеток: %2"))
            .arg(QString::number(_gen))
            .arg(QString::number(_alive));
    this->m_label->setText(_str);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Сначала все обнулить
    this->m_proc  = nullptr;
    this->currentIteration = 0;

    // Выделим память под m_label и перекинем в статусбар
    this->m_label = new QLabel(statusBarText, ui->statusBar);
    ui->statusBar->addWidget(m_label);
    // Зададим текст для статусбара
    updateStatusBar(0, 0);

    // Зададим интервал для таймера
    // TODO: Регулирование таймера
    this->m_timer.setInterval(1);
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

    connect(m_proc, SIGNAL(sigGameOver()),          SLOT(slotEndOfGame()));
    connect(m_proc, SIGNAL(sigGenIteration(uint)),  SLOT(slotIteration(uint)));
    connect(&this->m_timer, SIGNAL(timeout()),      SLOT(slotTimerTimeout()));
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
    // Нажатие кнопки Старт/Стоп

    this->setButtonsEnabled(!ui->pushStartPause->isChecked());
    if (ui->pushStartPause->isChecked())
    {
        ui->pushStartPause->setText(tr("Стоп"));

        this->currentIteration = 0;
        this->updateStatusBar(0, 0);


        this->m_timer.start();
        qDebug() << "Notice:\t Timer: Started";

    }
    else
    {
        ui->pushStartPause->setText(tr("Старт"));
        this->m_timer.stop();
        qDebug() << "Notice:\t Timer: Stopped";
    }
}

void MainWindow::on_pushNextStep_clicked()
{
    m_proc->solveOneStep();
}

void MainWindow::slotEndOfGame()
{
    ui->pushStartPause->setText(tr("Старт"));
    ui->pushStartPause->setChecked(false);

    this->setButtonsEnabled(true);
    this->m_timer.stop();
    QString _out;

    // Проверяем, было ли поле до этого пустое,
    // то есть проверяем на ненулевую генерацию
    if (this->currentIteration != 0)
        _out = QString(tr("Игра окончена на %1 итерации")).
                   arg(QString::number(currentIteration));
    else
        _out = QString(tr("Поле пустое"));

    QMessageBox::warning(this, tr("Конец"), _out);
}

void MainWindow::slotIteration(uint _aliveCells)
{
    // Стот новой итерации

    currentIteration++;
    this->updateStatusBar(currentIteration, _aliveCells);
}

void MainWindow::on_pushClear_clicked()
{
    // Очистка поля, обнуление переменных
    this->currentIteration = 0;
    this->updateStatusBar(0, 0);
    this->m_proc->clearField();
}

void MainWindow::slotTimerTimeout()
{
    // Действия при включенном таймере
    this->m_proc->solveOneStep();
}

void MainWindow::on_pushSettings_clicked()
{
    SettingsDialog settingsDialog;

    if (settingsDialog.exec() == SettingsDialog::Accepted)
        qDebug() << "ololo";
}
