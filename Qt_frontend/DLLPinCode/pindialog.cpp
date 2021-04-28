#include "pindialog.h"
#include "ui_pindialog.h"

PinDialog::PinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PinDialog) {
    ui->setupUi(this);

    diaTimer = new QTimer(this);                                    //Luodaan diaTimer-niminen ajastin
    diaTimer->setInterval(10000);                                   //säädetään se "laukeamaan" 10s päästä
    diaTimer->setSingleShot(true);                                  //säädetään se "laukeamaan" vain kerran
    connect(diaTimer, SIGNAL(timeout()), SLOT(timerRanOut()));      //säädetään se sulkemaan ikkuna "lauetessaan"
    ui->pinLine->setValidator(new QIntValidator(0, 1000, this));    //Rajoitetaan käyttäjä syöttämään 4-numeroinen PIN-koodi
    qDebug() << "Luodaan PinDialog.";

}

PinDialog::~PinDialog() {
    qDebug() << "Tuhotaan PinDialog.";
    delete ui;
}

void PinDialog::timerRanOut() {
//  lähetetään signaali joka ilmoittaa ajastin sulkeutui
    emit timedOut();
    this->close();
}

QString PinDialog::returnPinCode() {
//  lähetetään syötetty pinkoodi takaisin
    return pinCode;
}

void PinDialog::on_okButton_clicked() {
    /*******************************************
     * Talletetaan käyttäjän syöttämä pinkoodi *
     * pinLine-elementistä, tyhjennetään se ja *
     * suljetaan dialogi-ikkuna.               *
     *******************************************/
    diaTimer->stop(); //pysäytetään ajastin koska dialogi sulkeutuu
    pinCode = ui->pinLine->text();
    ui->pinLine->QLineEdit::clear();
    emit pinInserted(); //lähetetään signaali että käyttäjä syötti koodin
    this -> close();
}

void PinDialog::timerReset() {
//  Pysäytetään ja käynnistetään ajastin uudelleen sen nollaamiseksi.
    diaTimer->stop();
    diaTimer->start();
    qDebug() << "Timer Reset";
}

void PinDialog::buttonCharInserter(QString i) {
    /******************************************
     * Tallennetaan pinLine:ssä oleva teksti, *
     * lisätään sen perään metodiin annettu   *
     * merkki. Syötetään tämä pinLine:lle.    *
     ******************************************/
    QString j = ui->pinLine->text();
    j.append(i);
    ui->pinLine->setText(j);
    timerReset(); // nollataan ajastin jokaisella syötteellä
}

void PinDialog::on_clearButton_clicked() {
//  tyhjennetään pinLine käyttäjän pyynnöstä
    ui->pinLine->QLineEdit::clear();
    timerReset();
}


void PinDialog::on_numButton_0_clicked() {
//  syötetään merkki pinLine:lle
    QString i = "0";
    buttonCharInserter(i);
}

void PinDialog::on_numButton_1_clicked() {
//  syötetään merkki pinLine:lle
    QString i = "1";
    buttonCharInserter(i);
}

void PinDialog::on_numButton_2_clicked() {
//  syötetään merkki pinLine:lle
    QString i = "2";
    buttonCharInserter(i);
}

void PinDialog::on_numButton_3_clicked() {
//  syötetään merkki pinLine:lle
    QString i = "3";
    buttonCharInserter(i);
}

void PinDialog::on_numButton_4_clicked() {
//  syötetään merkki pinLine:lle
    QString i = "4";
    buttonCharInserter(i);
}

void PinDialog::on_numButton_5_clicked() {
//  syötetään merkki pinLine:lle
    QString i = "5";
    buttonCharInserter(i);
}

void PinDialog::on_numButton_6_clicked() {
//  syötetään merkki pinLine:lle
    QString i = "6";
    buttonCharInserter(i);
}

void PinDialog::on_numButton_7_clicked() {
//  syötetään merkki pinLine:lle
    QString i = "7";
    buttonCharInserter(i);
}

void PinDialog::on_numButton_8_clicked() {
//  syötetään merkki pinLine:lle
    QString i = "8";
    buttonCharInserter(i);
}

void PinDialog::on_numButton_9_clicked() {
//  syötetään merkki pinLine:lle
    QString i = "9";
    buttonCharInserter(i);
}
