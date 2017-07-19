#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::setRowsCols(int _row, int _col)
{
    // Задать количество строк/столбцов в форме
    Q_ASSERT(_row < ui->sbRows->maximum()
             && _row > ui->sbRows->minimum());
    Q_ASSERT(_col < ui->sbCols->maximum()
             && _col > ui->sbCols->minimum());

    ui->sbRows->setValue(_row);
    ui->sbCols->setValue(_col);
}

void SettingsDialog::setCellSize(short _px)
{
    // Задать размер клетки
    Q_ASSERT(_px < ui->sbCellSize->maximum()
             && _px > ui->sbCellSize->minimum());

    ui->sbCellSize->setValue(_px);
}

int SettingsDialog::getRows() const
{
    return ui->sbRows->value();
}

int SettingsDialog::getCols() const
{
    return ui->sbCols->value();
}

short SettingsDialog::getCellSize() const
{
    return ui->sbCellSize->value();
}
