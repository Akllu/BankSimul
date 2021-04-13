#include "transferdialog.h"
#include "ui_transferdialog.h"

transferDialog::transferDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transferDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Tilisiirto");
    transferAmount = 0;
}

transferDialog::~transferDialog()
{
    delete ui;
    ui = nullptr;
}

void transferDialog::on_nextButton_clicked()
{
    //Varmistetaan siirrettävä rahasumma
    transferAccount = ui->accountLineEdit->text();
    transferAmount = ui->amountSpinBox->value();    //HUOM! arvo pyöristetään
    QMessageBox confirmation;
    confirmation.setText(tr("Haluatko varmasti siirtää valitun summan?"));
    QAbstractButton *pButtonYes = confirmation.addButton(tr("Kyllä"),QMessageBox::YesRole);
    confirmation.addButton(tr("Peruuta"), QMessageBox::NoRole);
    confirmation.exec();
    if(confirmation.clickedButton() == pButtonYes)
    {
        //Tarkista rahat
        //Siirrä rahat
        this->close();
    }
}

void transferDialog::on_closeButton_clicked()
{
    ui->accountLineEdit->setText("");   //Nollataan tiedot jos näkymästä palataan takaisin
    ui->amountSpinBox->setValue(0.00);
    this->close();
    emit closeSignal();
}
