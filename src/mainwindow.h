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
    void on_pushStartPause_clicked();
    void on_pushNextStep_clicked();
    void on_pushClear_clicked();
    // метод для таймера
    void slotTimerTimeout();

    void on_pushSettings_clicked();

private:
    Ui::MainWindow  *ui;
    QLabel          *m_label;   // Для вывод текущей итерации
    Processing      *m_proc;
    void    setButtonsEnabled(bool enabled);

    // Хранение текущего номера поколения и колич. ячеекы
    uint    currentIteration;

    // Текст для статусбара
    QString statusBarText;
    void updateStatusBar(uint _gen, uint _alive);

    QTimer  m_timer;
signals:
    // Сигнал для очистки поля от живых клеток
    void sigClear();
};

#endif // MAINWINDOW_H
