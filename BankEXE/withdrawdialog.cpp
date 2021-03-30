#include "withdrawdialog.h"
#include "ui_withdrawdialog.h"

WithdrawDialog::WithdrawDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WithdrawDialog)
{
    ui->setupUi(this);
    otherAmount = 0;
}

WithdrawDialog::~WithdrawDialog()
{
    delete ui;
}

void WithdrawDialog::on_button20_clicked()
{
    //Vähennetään käyttäjältä 20€
}

void WithdrawDialog::on_button40_clicked()
{
    //Vähennetään käyttäjältä 40€
}

void WithdrawDialog::on_button60_clicked()
{
    //Vähennetään käyttäjältä 60€
}

void WithdrawDialog::on_button100_clicked()
{
    //Vähennetään käyttäjältä 100€
}

void WithdrawDialog::on_button200_clicked()
{
    //Vähennetään käyttäjältä 200€
}

void WithdrawDialog::on_button500_clicked()
{
    //Vähennetään käyttäjältä 500€
}

void WithdrawDialog::on_buttonOther_clicked()
{
    ptrOtherWithdraw = new otherWithdrawDialog;
    ptrOtherWithdraw->setWindowTitle("BankSimul");
    ptrOtherWithdraw->show();
    this->hide();
    ptrOtherWithdraw->exec();
    otherAmount = ptrOtherWithdraw->returnAmount();
    //Vähennetään käyttäjältä otherAmount
    delete ptrOtherWithdraw;
    ptrOtherWithdraw = nullptr;
}

void WithdrawDialog::on_buttonClose_clicked()
{
    this->close();
}
