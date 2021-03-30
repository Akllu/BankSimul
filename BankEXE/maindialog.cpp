#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;

}

void MainDialog::receiveSignal()
{
    this->show();
}

void MainDialog::on_withdrawButton_clicked()
{
    ptrWithdraw = new WithdrawDialog;
    ptrWithdraw->setWindowTitle("BankSimul");
    ptrWithdraw->show();
    this->hide();
    ptrWithdraw->exec();
    delete ptrWithdraw;
    ptrWithdraw = nullptr;
}

void MainDialog::on_balanceButton_clicked()
{
    ui->infoLabel->setText("Sulla mitää rahaa oo");
}

void MainDialog::on_transactionButton_clicked()
{

}

void MainDialog::on_transferButton_clicked()
{

}

void MainDialog::on_logoutButton_clicked()
{
    //Mahdollisesti jokin teksti käyttäjälle?
    this->close();
}
