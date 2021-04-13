#include "pindialog.h"
#include "ui_pindialog.h"

PINDialog::PINDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PINDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Kirjaudu sisään");
    ui->lineEdit->setValidator(new QIntValidator(0, 1000, this));   //Rajoitetaan käyttäjä syöttämään 4-numeroinen PIN-koodi
    attempts = 1;
}

PINDialog::~PINDialog()
{
    delete ui;
    ui = nullptr;
}

void PINDialog::on_sendButton_clicked()
{
    //PIN-koodin tarkistus
    number = ui->lineEdit->text().toDouble();   //Otetaan käyttäjän syöttämä PIN-koodi talteen
    if(number == 4444)
    {
        this->close();
    }
    else
    {
        if(attempts < 3)
        {
            //Jos salasana syötetään väärin, annetaan virheilmoitus
            //Huom!! Täytyy varmaan luoda oliot erikseen
            ui->lineEdit->setText("");  //Nollataan syöte
            QMessageBox::warning(this, "Virheilmoitus", "Väärä salasana!");
        }
        attempts++;
        if(attempts > 3) {
            //Jos salasana syötetään väärin kolme kertaa, annetaan virheilmoitus ja lukitaan kortti
            ui->lineEdit->setText("");  //Nollataan syöte
            QMessageBox::warning(this, "Virheilmoitus", "PIN-koodi syötetty väärin liian monta kertaa! Kortti lukittu!");
            //Lukitaan kortti
        }
    }
}
