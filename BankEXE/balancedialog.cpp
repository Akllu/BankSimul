#include "balancedialog.h"
#include "ui_balancedialog.h"

balanceDialog::balanceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::balanceDialog)
{
    ui->setupUi(this);
}

balanceDialog::~balanceDialog()
{
    delete ui;
}

void balanceDialog::on_closeButton_clicked()
{
    this->close();
}
