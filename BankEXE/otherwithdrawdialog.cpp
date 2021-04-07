#include "otherwithdrawdialog.h"
#include "ui_otherwithdrawdialog.h"

otherWithdrawDialog::otherWithdrawDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otherWithdrawDialog)
{
    ui->setupUi(this);
    ui->amountEdit->setValidator(new QIntValidator(0, 1000, this)); //Rajoitetaan käyttäjä syöttämään lukuja väliltä 0-9000
    amount = 0;
}

otherWithdrawDialog::~otherWithdrawDialog()
{
    delete ui;
}

void otherWithdrawDialog::on_withdrawButton_clicked()
{
    amount = ui->amountEdit->text().toDouble(); //Otetaan käyttäjän syöttämä rahasumma talteen
    this->close();
}

double otherWithdrawDialog::returnAmount()
{
    return amount;
}

void otherWithdrawDialog::on_closeButton_clicked()
{
    ui->amountEdit->setText("");    //Nollataan summa jos näkymästä palataan takaisin
    this->close();
    emit closeSignal();
}
