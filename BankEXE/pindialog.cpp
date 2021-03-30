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
    }
    else {
        if(attempts < 3)
        {
            QMessageBox::warning(this, "Virheilmoitus", "Väärä salasana!");
        }
        attempts++;
        if(attempts > 3) {
            QMessageBox::warning(this, "Virheilmoitus", "PIN-koodi syötetty väärin liian monta kertaa! Kortti lukittu!");
            //Lukitaan kortti
        }
        }
    delete ptrMainDialog;
    ptrMainDialog = nullptr;
}
