#include "aboutdialog.h"
#include "ui_aboutdialog.h"


AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    ui->labelVersion->setText(QString(tr("Версия: %1")).arg(QApplication::applicationVersion()));
    ui->labelAuthor->setText(QString(tr("Автор: %1")).arg(QApplication::organizationName()));
    ui->labelBuild->setText(QString(tr("Время сборки: %1 %2")).arg(QString(__DATE__)).arg(QString(__TIME__)));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
