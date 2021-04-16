#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    ptrMainMenu = new MainMenu;
    //ptrPIN = new PinInterface;
    ui->stackedWidget->insertWidget(1, ptrMainMenu);

    QPixmap pic(":/resources/Pictures/rfid.png");
    ui->pictureLabel->setPixmap(pic.scaled(500,500,Qt::KeepAspectRatio));   //Skaalataan kuva
    setWindowTitle("BankSimul");

    connect(ptrMainMenu, SIGNAL(logoutSignal()),    //Yhdistetään Kirjaudu ulos-painike aloituskäyttölittyymään palaamiseen
            this, SLOT(backToHome()));
}

HomeWindow::~HomeWindow()
{
    delete ui;
    ui = nullptr;
    delete ptrMainMenu;
    ptrMainMenu = nullptr;
    //delete ptrPIN;
    //ptrPIN = nullptr;
}

void HomeWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);  //Näytetään pääkäyttöliittymä
    ptrMainMenu->startHomeWindowTimer();
    /*
    ptrPIN->generatePinDialog("TähänRFID");
    loginResult = ptrPIN->getLoginResult();
    if(loginResult == "true")
    {
        ui->stackedWidget->setCurrentIndex(1);  //Näytetään pääkäyttöliittymä
    }
    else
    {
        QMessageBox::warning(this, "Ei oikeuksia", "Sisäänkirjautuminen epäonnistui!");
    }
    */
}

void HomeWindow::backToHome()
{
    ui->stackedWidget->setCurrentIndex(0);  //Näytetään aloituskäyttöliittymä
}
