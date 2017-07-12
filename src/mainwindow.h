#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtEvents>
#include <QMessageBox>

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

private slots:
    void on_pushStartPause_clicked();

    void on_pushNextStep_clicked();



private:
    Ui::MainWindow *ui;
    Processing  *m_proc;
    void setButtonsEnabled(bool enabled);
};

#endif // MAINWINDOW_H
