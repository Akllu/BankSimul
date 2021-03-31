#include "transferdialog.h"
#include "ui_transferdialog.h"

transferDialog::transferDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transferDialog)
{
    ui->setupUi(this);
}

transferDialog::~transferDialog()
{
    delete ui;
}

void transferDialog::on_nextButton_clicked()
{
    //Varmista siirrettävä rahasumma
}

void transferDialog::on_closeButton_clicked()
{
    this->close();
}
