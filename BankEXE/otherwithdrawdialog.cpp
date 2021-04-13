#include "otherwithdrawdialog.h"
#include "ui_otherwithdrawdialog.h"

otherWithdrawDialog::otherWithdrawDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otherWithdrawDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Muu summa");
    ui->amountEdit->setValidator(new QIntValidator(0, 1000, this)); //Rajoitetaan käyttäjä syöttämään lukuja väliltä 0-9000
    amount = 0;
}

otherWithdrawDialog::~otherWithdrawDialog()
{
    delete ui;
    ui = nullptr;
}

void otherWithdrawDialog::on_withdrawButton_clicked()
{
    amount = ui->amountEdit->text().toDouble(); //Otetaan käyttäjän syöttämä rahasumma talteen
    if(std::fmod(amount,10) != 0)   //Rajoitetaan 10€ pienimmäksi nostettavaksi seteliksi
    {
        QMessageBox::warning(this, "Virheellinen rahasumma", "Huomioithan, että pienin nostettava seteli on 10€!");
        ui->amountEdit->clear();
        amount = 0;
    }
    else
    {
        this->close();
    }

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
