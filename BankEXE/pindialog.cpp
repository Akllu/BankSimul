#include "pindialog.h"
#include "ui_pindialog.h"
#include <QDebug>

PINDialog::PINDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PINDialog)
{
    ui->setupUi(this);
    attempts = 1;
}

PINDialog::~PINDialog()
{
    delete ui;
}

void PINDialog::on_sendButton_clicked()
{
    //PIN-koodin tarkistus
    ptrMainDialog = new MainDialog;
    ptrMainDialog->setWindowTitle("BankSimul");
    number = ui->lineEdit->text().toDouble();
    if(number == 4444)
    {
        ptrMainDialog->show();
        this->close();
        ptrMainDialog->exec();
        attempts = 1;
    }
    else {
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
    delete ptrMainDialog;
    ptrMainDialog = nullptr;
}
