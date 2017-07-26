#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtEvents>
#include <QMessageBox>
#include <QLabel>
#include <QTimer>

#include "lifeview.h"
#include "processing.h"
#include "settingsdialog.h"
#include "aboutdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showEvent(QShowEvent *event);

public slots:
    // Слот окончания игры
    void slotEndOfGame();
    // Слот новой итерации
    void slotIteration(uint _aliveCells);

private slots:
    // метод для таймера
    void slotTimerTimeout();

    void slotSpeedTimerTimeout();

    void on_acStartStop_triggered();

    void on_acSettings_triggered();

    void on_acNextStep_triggered();

    void on_acClear_triggered();

    void on_acAbout_triggered();

private:
    Ui::MainWindow  *ui;
    QLabel  *m_label;   // Для вывод текущей итерации
    QLabel  *m_speedLabel; // Для вывода скорости вычисления
    Processing      *m_proc;
    void    setButtonsEnabled(bool enabled);

    // Хранение текущего номера поколения и колич. ячеекы
    uint    currentIteration;

    // Текст для статусбара
    QString statusBarText;
    void updateStatusBar(uint _gen, uint _alive);
    // Текст для скорости
    QString speedBarText;
    void updateSpeedLabel(uint _iternum);

    // Таймер для вычислений поколений
    QTimer  m_mainTimer;
    // Таймер для замера скорости вычисления
    QTimer  m_speedTimer;

    // Для вычисления скорости
    volatile uint    _itnum;
signals:
    // Сигнал для очистки поля от живых клеток
    void sigClear();
};

#endif // MAINWINDOW_H
