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

    connect(ptrMainMenu, SIGNAL(transactions(QString,int)),     //Tilitapahtumien haku
            this, SLOT(getTransactions(QString,int)));
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

void HomeWindow::getValueFromRFID()
{
    ptrSerialPort->openSerialPort();

}

void HomeWindow::dataFromRFID(QString data)
{
    cardNum = data;
    ptrPIN->generatePinDialog();
    //ptrSerialPort->closeSerialdata();
}

void HomeWindow::login()
{
    cardPIN = ptrPIN->returnPinCode();
    ptrRestAPI->login(cardNum,cardPIN);
}

void HomeWindow::on_pushButton_clicked()    //Tämä on vain EXE:n demoa varten
{
   dataFromRFID("-06000DE540");

   // ui->stackedWidget->setCurrentIndex(1);  //Näytetään pääkäyttöliittymä
   // ptrMainMenu->startHomeWindowTimer();
}

void HomeWindow::backToHome()
{
    ui->stackedWidget->setCurrentIndex(0);  //Näytetään aloituskäyttöliittymä
    //getValueFromRFID(); //Luetaan sarjaporttia uudelleen
}



void HomeWindow::loginResult(QString result)
{
    qDebug() << result;
    if(result == "loginsuccesful")
    {
        getCustomerData(cardNum);
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
            ptrPIN->generatePinDialog();
        }
        else
        {
            QMessageBox::warning(this, "Virheilmoitus", "PIN-koodi syötetty väärin liian monta kertaa! Kortti lukittu!");
            ptrRestAPI->lockCard(cardNum);
        }
    }
}

void HomeWindow::getCustomerData(QString cardID)
{
    ptrRestAPI->getCustomerData(cardID);
    ptrMainMenu->saveID(cardID);
}

void HomeWindow::getTransactions(QString cardID, int startingPoint)
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

void HomeWindow::handleCustomerData(QString nameID, QString name, QString accNum, QString balance)
{
    ptrMainMenu->setCustomerData(nameID,name,accNum,balance);
}

void HomeWindow::handleTransactions(QString event, QString amount, QString date)
{
    ptrMainMenu->setTransactions(event,amount,date);
}
