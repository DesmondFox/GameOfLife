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

void MainWindow::updateSpeedLabel(uint _iternum)
{
    // Обновление текста скорости

    QString _str = QString(tr("Скорость вычисления: %1 п-ний/сек"))
            .arg(QString::number(_iternum));
    this->m_speedLabel->setText(_str);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Сначала все обнулить
    this->m_proc  = nullptr;
    this->currentIteration = 0;
    this->_itnum = 0;

    // Выделим память под m_label и перекинем в статусбар
    this->m_label = new QLabel(statusBarText, ui->statusBar);
    this->m_speedLabel = new QLabel(speedBarText, ui->statusBar);
    ui->statusBar->addWidget(m_label);
    ui->statusBar->addWidget(m_speedLabel, 5);

    // Зададим текст для статусбара
    updateStatusBar(0, 0);
    updateSpeedLabel(0);

    // Зададим интервал для таймера
    this->m_mainTimer.setInterval(100);

    // Зададим иконку для приложения
    this->setWindowIcon(QIcon(":/icons/icons/winicon.png"));

    this->m_speedTimer.setInterval(1000);

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
    connect(&this->m_mainTimer, SIGNAL(timeout()),  SLOT(slotTimerTimeout()));
    connect(&this->m_speedTimer, SIGNAL(timeout()), SLOT(slotSpeedTimerTimeout()));
}

void MainWindow::setButtonsEnabled(bool enabled)
{
    // Установка доступности кнопок при старте/стопе

    ui->acSettings->setEnabled(enabled);
    ui->acClear->setEnabled(enabled);
    ui->acNextStep->setEnabled(enabled);
}

void MainWindow::slotEndOfGame()
{
    ui->acStartStop->setText(tr("Старт"));
    ui->acStartStop->setChecked(false);

    this->setButtonsEnabled(true);

    m_proc->setNeedToReadField(true);

    if (this->m_mainTimer.isActive())
    {
        this->m_mainTimer.stop();
        qDebug() << "Notice:\t Timer: Stopped";
    }

    this->updateSpeedLabel(0);

    QString _out;
    // Проверяем, было ли поле до этого пустое,
    // то есть проверяем на ненулевую генерацию
    if (this->currentIteration != 0)
        _out = QString(tr("Игра окончена на %1 итерации")).
                   arg(QString::number(currentIteration));
    else
        _out = QString(tr("Поле пустое"));

    QMessageBox::information(this, tr("Конец"), _out);
}

void MainWindow::slotIteration(uint _aliveCells)
{
    // Стот новой итерации

    currentIteration++;
    this->updateStatusBar(currentIteration, _aliveCells);
}

void MainWindow::slotTimerTimeout()
{
    // Действия при включенном таймере
    this->m_proc->solveOneStep();
    _itnum++;
}

void MainWindow::slotSpeedTimerTimeout()
{

    updateSpeedLabel(_itnum);
    _itnum = 0;
}

void MainWindow::on_acStartStop_triggered()
{
    // Нажатие кнопки Старт/Стоп

    this->setButtonsEnabled(!ui->acStartStop->isChecked());
    if (ui->acStartStop->isChecked())
    {
        ui->acStartStop->setText(tr("Стоп"));

        this->currentIteration = 0;
        this->updateStatusBar(0, 0);
        this->m_proc->setNeedToReadField(false);

        this->m_mainTimer.start();
        this->m_speedTimer.start();
        qDebug() << "Notice:\t Timer: Started";

    }
    else
    {
        ui->acStartStop->setText(tr("Старт"));
        this->m_proc->setNeedToReadField(true);
        this->m_mainTimer.stop();
        this->m_speedTimer.stop();
        this->updateSpeedLabel(0);

        qDebug() << "Notice:\t Timer: Stopped";
    }
}

void MainWindow::on_acSettings_triggered()
{
    Q_CHECK_PTR(m_proc);

    SettingsDialog settingsDialog;

    // Зададим текущие значения поля
    settingsDialog.setRowsCols(m_proc->getRows(), m_proc->getCols());
    settingsDialog.setCellSize(m_proc->getCellSize());
    settingsDialog.setDelay(this->m_mainTimer.interval());

    if (settingsDialog.exec() == SettingsDialog::Accepted)
    {
        qDebug() << "Notice:\t Settings: New parameters";
        this->m_proc->setParameters(settingsDialog.getRows(),
                                    settingsDialog.getCols(),
                                    settingsDialog.getCellSize());
        this->m_mainTimer.setInterval(settingsDialog.getDelay());
    }

}

void MainWindow::on_acNextStep_triggered()
{
    m_proc->solveOneStep();
}

void MainWindow::on_acClear_triggered()
{
    // Очистка поля, обнуление переменных
    this->currentIteration = 0;
    this->updateStatusBar(0, 0);
    this->m_proc->clearField();
}

void MainWindow::on_acAbout_triggered()
{
    AboutDialog aboutDlg;
    aboutDlg.exec();
}
