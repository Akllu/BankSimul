#include "transferdialog.h"
#include "ui_transferdialog.h"

transferDialog::transferDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transferDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Tilisiirto");
    transferAmount = 0;

    dialogTimer = new QTimer(this);
    dialogTimer->setInterval(10000);
    dialogTimer->setSingleShot(true);
    connect(dialogTimer, SIGNAL(timeout()), this, SLOT(on_closeButton_clicked()));

}

transferDialog::~transferDialog()
{
    delete ui;
    ui = nullptr;
    delete dialogTimer;
    dialogTimer = nullptr;
}

void transferDialog::resetTimer()
{
    dialogTimer->stop();
    dialogTimer->start();
}

void transferDialog::on_nextButton_clicked()
{
    dialogTimer->stop();
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
    else
    {
        dialogTimer->start();
    }
}

void transferDialog::on_closeButton_clicked()
{
    dialogTimer->stop();
    ui->accountLineEdit->setText("");   //Nollataan tiedot jos näkymästä palataan takaisin
    ui->amountSpinBox->setValue(0.00);
    this->close();
    emit closeSignal();
}
