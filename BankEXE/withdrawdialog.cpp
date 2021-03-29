#include "withdrawdialog.h"
#include "ui_withdrawdialog.h"

WithdrawDialog::WithdrawDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WithdrawDialog)
{
    ui->setupUi(this);
}

WithdrawDialog::~WithdrawDialog()
{
    delete ui;
}

void WithdrawDialog::on_button20_clicked()
{

}

void WithdrawDialog::on_button40_clicked()
{

}

void WithdrawDialog::on_button60_clicked()
{

}

void WithdrawDialog::on_button100_clicked()
{

}

void WithdrawDialog::on_button200_clicked()
{

}

void WithdrawDialog::on_button500_clicked()
{

}

void WithdrawDialog::on_buttonOther_clicked()
{

}

void WithdrawDialog::on_buttonClose_clicked()
{
    this->close();
}
