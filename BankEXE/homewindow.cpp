#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    ui->pushButton->hide();
    setWindowTitle("BankSimul");
    loginCounter = 0;

    ptrMainMenu = new MainMenu;
    ptrSerialPort = new SerialPortDLL;
    ptrPIN = new PinInterface;
    ptrRestAPI = new DLLRestAPI;

    ui->stackedWidget->insertWidget(1, ptrMainMenu);    //Lisätään pääkäyttöliittymä stackedwidgettinä

    QPixmap pic(":/resources/Pictures/rfid.png");
    ui->pictureLabel->setPixmap(pic.scaled(500,500,Qt::KeepAspectRatio));   //Skaalataan kuva

    connect(ptrMainMenu, SIGNAL(logoutSignal()),    //Yhdistetään Kirjaudu ulos-painike aloituskäyttölittyymään palaamiseen
            this, SLOT(backToHome()));


/***************RAJAPINTAFUNKTIOT***************/

    connect(this, SIGNAL(readRFID()),       //DLLSerialPort
            this, SLOT(getValueFromRFID()));
    connect(ptrSerialPort, SIGNAL(sendtoEXEStatus(QString)),
            this, SLOT(dataFromRFID(QString)));

    connect(ptrPIN, SIGNAL(timeoutSignal()),       //DLLPinCode
            this, SLOT(getValueFromRFID()));
    connect(ptrPIN, SIGNAL(PINInserted()),
            this, SLOT(login()));

    connect(ptrRestAPI, SIGNAL(loginResultToEXE(QString)),  //Kirjautuminen
            this, SLOT(loginResult(QString)));

    connect(ptrRestAPI, SIGNAL(customerDataToEXE(QString,QString,QString,QString)), //Käyttäjän tietojen haku
            this, SLOT(handleCustomerData(QString,QString,QString,QString)));
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
    delete ptrSerialPort;
    ptrSerialPort = nullptr;
    delete ptrPIN;
    ptrPIN = nullptr;
    delete ptrRestAPI;
    ptrRestAPI = nullptr;
}

void HomeWindow::getValueFromRFID() //Avataan sarjaportti
{
    ptrSerialPort->openSerialPort();

}

void HomeWindow::dataFromRFID(QString data)
{
    cardNum = data;      //Tallennetaan kortin sarjanumero
    ptrPIN->generatePinDialog();    //Avataan PIN-kyselyikkuna
    ptrSerialPort->closeSerialdata();   //Suljetaan sarjaportti
}

void HomeWindow::login()
{
    cardPIN = ptrPIN->returnPinCode();  //Tallennetaan syötetty PIN-koodi
    ptrRestAPI->login(cardNum,cardPIN); //Yritetään kirjautua luetulla&annetulla arvoilla
}

void HomeWindow::on_pushButton_clicked()    //Tämä on vain EXE:n demoa varten
{
   //dataFromRFID("-06000E1B4D");
}

void HomeWindow::backToHome()
{
    ui->stackedWidget->setCurrentIndex(0);  //Näytetään aloituskäyttöliittymä
    getValueFromRFID(); //Luetaan sarjaporttia uudelleen
}

void HomeWindow::loginResult(QString result)
{
    if(result == "loginsuccesful")  //Jos syötetty PIN-koodi vastasi tietokannassa olevaa tietoa:
    {
        getCustomerData(cardNum);   //Haetaan kirjautuneen käyttäjän tiedot tietokannasta
        ui->stackedWidget->setCurrentIndex(1);  //Näytetään pääkäyttöliittymä
        ptrMainMenu->startHomeWindowTimer();    //Käynnistetään 30s ajastin
        loginCounter = 0;           //Nollataan kirjautumisyritykset
    }
    else if(result == "error")  //Jos tietokantaan ei saada yhteyttä
    {
        QMessageBox::warning(this, "Virheilmoitus", "Virhe tietokantayhteydessä!");
        getValueFromRFID();
    }
    else if(result == "locked") //Jos kortti on lukittuna
    {
        QMessageBox::warning(this, "Virheilmoitus", "Kortti on lukittuna!");
        getValueFromRFID();
    }
    else    //Jos PIN-koodi on väärä:
    {
        loginCounter++; //Lisätään kirjautumisyritys
        if(loginCounter <= 2)
        {
            QMessageBox::warning(this, "Virheilmoitus", "Väärä PIN-koodi!");
            ptrPIN->generatePinDialog();    //Kysytään uudestaan PIN-koodia
        }
        else    //Käyttäjä on syöttänyt PIN-koodin kolme kertaa väärin:
        {
            QMessageBox::warning(this, "Virheilmoitus", "PIN-koodi syötetty väärin liian monta kertaa! Kortti lukittu!");
            ptrRestAPI->lockCard(cardNum);  //Lukitaan kortti
            loginCounter = 0;
            getValueFromRFID();
        }
    }
}

void HomeWindow::getCustomerData(QString cardID)
{
    ptrRestAPI->getCustomerData(cardID);    //Haetaan kirjautuneen käyttäjän tiedot tietokannasta
    ptrMainMenu->saveID(cardID);            //Viedään kortin sarjanumero pääkäyttöliittymälle
}

void HomeWindow::getTransactions(QString cardID, QString startingPoint)
{
    ptrRestAPI->getTransactions(cardID,startingPoint);  //Haetaan tilitapahtumat tietokannasta
}

void HomeWindow::handleWithdraw(int ID, double amount)
{
    ptrRestAPI->withdraw(ID, amount);   //Suoritetaan nosto-proseduuri
}

void HomeWindow::handleTransfer(int customerID, int receiverAccNum, double amount)
{
    ptrRestAPI->transfer(customerID, receiverAccNum, amount);   //Suoritetaan tilisiirto-proseduuri
}

void HomeWindow::handleCustomerData(QString nameID, QString name, QString accNum, QString balance)
{
    ptrMainMenu->setCustomerData(nameID,name,accNum,balance);   //Viedään käyttäjän tiedot pääkäyttöliittymälle
}

void HomeWindow::handleTransactions(QString event, QString amount, QString date)
{
    ptrMainMenu->setTransactions(event,amount,date);    //Viedään käyttäjän tilitapahtumat pääkäyttöliittymälle
}
