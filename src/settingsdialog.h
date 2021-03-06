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
    void setRowsCols(int _row, int _col);
    void setCellSize(short _px);
    void setDelay(short _ms);

    int getRows() const;
    int getCols() const;
    short getCellSize() const;
    short getDelay() const;

private:
    Ui::SettingsDialog *ui;

    // При каких значениях показывать предупреждающую надпись
    static const int WrnCount = 1000;
    // Показ предупреждающей надписи
    void showingWrn();

private slots:
    void slotAnyValuesChanged();
};

#endif // SETTINGSDIALOG_H
