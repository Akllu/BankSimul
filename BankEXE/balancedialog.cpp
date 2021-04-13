#include "balancedialog.h"
#include "ui_balancedialog.h"

balanceDialog::balanceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::balanceDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Saldo");
}

balanceDialog::~balanceDialog()
{
    delete ui;
    ui = nullptr;
}

void balanceDialog::on_closeButton_clicked()
{
    this->close();
    emit closeSignal();
}
