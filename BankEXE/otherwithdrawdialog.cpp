#include "otherwithdrawdialog.h"
#include "ui_otherwithdrawdialog.h"

otherWithdrawDialog::otherWithdrawDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otherWithdrawDialog)
{
    ui->setupUi(this);
    amount = 0;
}

otherWithdrawDialog::~otherWithdrawDialog()
{
    delete ui;
}

void otherWithdrawDialog::on_withdrawButton_clicked()
{
    amount = ui->amountEdit->text().toDouble();
    this->close();
}

double otherWithdrawDialog::returnAmount()
{
    return amount;
}
