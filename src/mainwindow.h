#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtEvents>
#include <QMessageBox>
#include <QLabel>

#include "lifeview.h"
#include "processing.h"

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
    void slotIteration(uint genNum, uint aliveCellsCount);

private slots:
    void on_pushStartPause_clicked();
    void on_pushNextStep_clicked();
private:
    Ui::MainWindow *ui;
    QLabel  *m_label;   // Для вывод текущей итерации
    Processing  *m_proc;
    void    setButtonsEnabled(bool enabled);

    // Хранение текущего номера поколения и колич. ячеекы
    uint    currentIteration;
    uint    currentCellCount;

    // Текст для статусбара
    QString statusBarText;
};

#endif // MAINWINDOW_H
