#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    setWindowTitle("BankSimul");
    loginCounter = 0;

    ptrMainMenu = new MainMenu;
    //ptrSerialPort = new SerialPortDLL;
    //ptrPIN = new PinInterface;
    ptrRestAPI = new DLLRestAPI;

    ui->stackedWidget->insertWidget(1, ptrMainMenu);    //Lisätään pääkäyttöliittymä stackedwidgettinä

    QPixmap pic(":/resources/Pictures/rfid.png");
    ui->pictureLabel->setPixmap(pic.scaled(500,500,Qt::KeepAspectRatio));   //Skaalataan kuva

    //emit readRFID();    //Lähetetään signaali sarjaportin avaamiseksi

    connect(ptrMainMenu, SIGNAL(logoutSignal()),    //Yhdistetään Kirjaudu ulos-painike aloituskäyttölittyymään palaamiseen
            this, SLOT(backToHome()));


/***************RAJAPINTAFUNKTIOT***************/

    /*connect(ptrSerialPort, SIGNAL(sendtoEXEStatus(QString)),
            this, SLOT(dataFromRFID(QString)));

    connect(this, SIGNAL(readRFID()),
            this, SLOT(getValueFromRFID()));
*/
    connect(ptrRestAPI, SIGNAL(loginResultToEXE(QString)),  //Kirjautuminen
            this, SLOT(login(QString)));

    connect(ptrRestAPI, SIGNAL(customerDataToEXE(QString,QString,QString)), //Käyttäjän tietojen haku
            this, SLOT(handleCustomerData(QString,QString,QString)));
    connect(ptrMainMenu, SIGNAL(updateCustomerData(QString)),
            this, SLOT(getCustomerData(QString)));

    connect(ptrMainMenu, SIGNAL(transactions(QString,QString)),     //Tilitapahtumien haku
            this, SLOT(getTransactions(QString,QString)));
    connect(ptrRestAPI, SIGNAL(transactionsToEXE(QString,QString,QString)),
            this, SLOT(handleTransactions(QString,QString,QString)));

    connect(ptrMainMenu, SIGNAL(withdraw(int,double)),  //Rahan nostot
            this, SLOT(handleWithdraw(int,double)));
    connect(ptrRestAPI, SIGNAL(withdrawResultToEXE(QString)),
            ptrMainMenu, SLOT(withdrawResult(QString)));

    connect(ptrMainMenu, SIGNAL(transfer(int,int,double)),  //Tilisiirrot
            this, SLOT(handleTransfer(int,int,double)));
    connect(ptrRestAPI, SIGNAL(transferResultToEXE(QString)),
            ptrMainMenu, SLOT(transferResult(QString)));
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
    delete ptrRestAPI;
    ptrRestAPI = nullptr;
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
    ptrRestAPI->login("-06000DE53B","1235");

   // ui->stackedWidget->setCurrentIndex(1);  //Näytetään pääkäyttöliittymä
   // ptrMainMenu->startHomeWindowTimer();
}

void HomeWindow::backToHome()
{
    ui->stackedWidget->setCurrentIndex(0);  //Näytetään aloituskäyttöliittymä
    //getValueFromRFID(); //Luetaan sarjaporttia uudelleen
}

void HomeWindow::login(QString result)
{
    qDebug() << result;
    if(result == "loginsuccesful")
    {
        getCustomerData("-06000DE53B");
        ui->stackedWidget->setCurrentIndex(1);
        ptrMainMenu->startHomeWindowTimer();
        loginCounter = 0;
    }
    else if(result == "virhe")
    {
        QMessageBox::warning(this, "Virheilmoitus", "Virhe tietokantayhteydessä!");
    }
    else if(result == "lukossa")
    {
        QMessageBox::warning(this, "Virheilmoitus", "Kortti on lukittuna!");
    }
    else
    {
        loginCounter++;
        if(loginCounter <= 2)
        {
            QMessageBox::warning(this, "Virheilmoitus", "Väärä PIN-koodi!");
        }
        else
        {
            ptrRestAPI->lockCard("-06000DE53B");
            QMessageBox::warning(this, "Virheilmoitus", "PIN-koodi syötetty väärin liian monta kertaa! Kortti lukittu!");
        }
    }
}

void HomeWindow::getCustomerData(QString cardID)
{
    ptrRestAPI->getCustomerData(cardID);
    ptrMainMenu->saveID(cardID);
}

void HomeWindow::getTransactions(QString cardID, QString startingPoint)
{
    ptrRestAPI->getTransactions(cardID,startingPoint);
}

void HomeWindow::handleWithdraw(int ID, double amount)
{
    ptrRestAPI->withdraw(ID, amount);
}

void HomeWindow::handleTransfer(int senderAccNum, int receiverAccNum, double amount)
{
    ptrRestAPI->transfer(senderAccNum, receiverAccNum, amount);
}

void HomeWindow::handleCustomerData(QString name, QString accNum, QString balance)
{
    ptrMainMenu->setCustomerData(name,accNum,balance);
}

void HomeWindow::handleTransactions(QString event, QString amount, QString date)
{
    ptrMainMenu->setTransactions(event,amount,date);
}
