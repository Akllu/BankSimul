#include "pindialog.h"
#include "ui_pindialog.h"

PINDialog::PINDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PINDialog)
{
    ui->setupUi(this);
    ptrMainDialog = new MainDialog;
    attempts = 1;
}

PINDialog::~PINDialog()
{
    delete ui;
    delete ptrMainDialog;
    ptrMainDialog = nullptr;
}

void PINDialog::on_sendButton_clicked()
{
    //PIN-koodin tarkistus
    ptrMainDialog->setWindowTitle("BankSimul");
    number = ui->lineEdit->text().toDouble();   //Otetaan käyttäjän syöttämä PIN-koodi talteen
    if(number == 4444)
    {
        this->close();
        ptrMainDialog->show();
        ui->lineEdit->setText("");  //Nollataan tiedot
        attempts = 1;
    }
    else
    {
        if(attempts < 3)
        {
            //Jos salasana syötetään väärin, annetaan virheilmoitus
            //Huom!! Täytyy varmaan luoda oliot erikseen
            QMessageBox::warning(this, "Virheilmoitus", "Väärä salasana!");
        }
        attempts++;
        if(attempts > 3) {
            //Jos salasana syötetään väärin kolme kertaa, annetaan virheilmoitus ja lukitaan kortti
            QMessageBox::warning(this, "Virheilmoitus", "PIN-koodi syötetty väärin liian monta kertaa! Kortti lukittu!");
            //Lukitaan kortti
        }
    }
}
