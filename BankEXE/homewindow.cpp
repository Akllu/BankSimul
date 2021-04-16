#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    setWindowTitle("BankSimul");

    ptrMainMenu = new MainMenu;
    //ptrSerialPort = new SerialPortDLL;
    //ptrPIN = new PinInterface;

    ui->stackedWidget->insertWidget(1, ptrMainMenu);    //Lisätään pääkäyttöliittymä stackedwidgettinä

    QPixmap pic(":/resources/Pictures/rfid.png");
    ui->pictureLabel->setPixmap(pic.scaled(500,500,Qt::KeepAspectRatio));   //Skaalataan kuva

    //emit readRFID();    //Lähetetään signaali sarjaportin avaamiseksi

    connect(ptrMainMenu, SIGNAL(logoutSignal()),    //Yhdistetään Kirjaudu ulos-painike aloituskäyttölittyymään palaamiseen
            this, SLOT(backToHome()));
/*
    connect(ptrSerialPort, SIGNAL(sendtoEXEStatus(QString)),
            this, SLOT(dataFromRFID(QString)));

    connect(this, SIGNAL(readRFID()),
            this, SLOT(getValueFromRFID()));
*/
}

HomeWindow::~HomeWindow()
{
    delete ui;
    ui = nullptr;
    delete ptrMainMenu;
    ptrMainMenu = nullptr;
    //delete ptrSerialPort;
    //ptrSerialPort = nullptr;
    //delete ptrPIN;
    //ptrPIN = nullptr;
}

/*
void HomeWindow::getValueFromRFID()
{
    ptrSerialPort->openSerialPort();
    ptrPIN->generatePinDialog("TähänRFID");
    loginResult = ptrPIN->getLoginResult();
    if(loginResult == "true")
    {
        ui->stackedWidget->setCurrentIndex(1);  //Näytetään pääkäyttöliittymä
        ptrMainMenu->startHomeWindowTimer();    //Käynnistetään 30s ajastin
    }
    else
    {
        QMessageBox::warning(this, "Ei oikeuksia", "Sisäänkirjautuminen epäonnistui!");
    }
}

void HomeWindow::dataFromRFID(QString data)
{
    CardValueRFID = data;
    ui->stackedWidget->setCurrentIndex(1);
    ptrSerialPort->closeSerialdata();
}

*/

void HomeWindow::on_pushButton_clicked()    //Tämä on vain EXE:n demoa varten
{
    ui->stackedWidget->setCurrentIndex(1);  //Näytetään pääkäyttöliittymä
    ptrMainMenu->startHomeWindowTimer();
}

void HomeWindow::backToHome()
{
    ui->stackedWidget->setCurrentIndex(0);  //Näytetään aloituskäyttöliittymä
    //getValueFromRFID(); //Luetaan sarjaporttia uudelleen
}
