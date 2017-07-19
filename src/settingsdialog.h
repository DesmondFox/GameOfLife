#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

    // сеттеры/геттеры для полей
    void setRowsCols(uint _row, uint _col);
    void setCellSize(short _px);

    uint getRows() const;
    uint getCols() const;
    short getCellSize() const;

private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
