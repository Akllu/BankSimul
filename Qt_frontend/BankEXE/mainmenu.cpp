#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent):
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("BankSimul");
    transferCommaCounter = 0;
    startingPoint = 0;

    failMessage = new QMessageBox;     //Virheilmoitus jos saldo ei riitä
    failMessage->setWindowTitle("Virheellinen rahasumma");
    failMessage->setIcon(QMessageBox::Warning);
    failMessage->setText("Tilin saldo ei riitä!");

    mainMenuTimer = new QTimer(this);   //10s ajastin toiminnallisuuksille
    mainMenuTimer->setInterval(10000);
    mainMenuTimer->setSingleShot(true);

    homeWindowTimer = new QTimer(this); //30s ajastin pääkäyttöliittymälle
    homeWindowTimer->setInterval(30000);
    homeWindowTimer->setSingleShot(true);

    connect(mainMenuTimer, SIGNAL(timeout()),   //Jos 10s ei tehdä mitään, palataan pääkäyttöliittymään
            this, SLOT(backToMainMenu()));

    connect(homeWindowTimer, SIGNAL(timeout()), //Jos 30s ei tehdä mitään, kirjaudutaan ulos
            this, SLOT(on_mainLogoutButton_clicked()));
}

MainMenu::~MainMenu()
{
    delete ui;
    ui = nullptr;
    delete failMessage;
    failMessage = nullptr;
    delete mainMenuTimer;
    mainMenuTimer = nullptr;
    delete homeWindowTimer;
    homeWindowTimer = nullptr;
}

void MainMenu::insertOtherAmountNum(QString i)  //Lisätään painetut numerot nostettavaan summaan
{
    wtdrAmount.append(i);
    ui->otherAmountLineEdit->setText(wtdrAmount);
}

void MainMenu::insertAccNum(QString i)  //Lisätään painetut numerot tilinumeroon
{
    trfAccNum.append(i);
    ui->accNumLineEdit->setText(trfAccNum);
}

void MainMenu::insertAmountNum(QString i)   //Lisätään painetut numerot siirrettävään summaan
{
    trfAmount.append(i);
    ui->amountInsertLineEdit->setText(trfAmount);
}

void MainMenu::resetTimer() //"Nollataan" ajastin
{
    mainMenuTimer->stop();
    mainMenuTimer->start();
}

void MainMenu::startHomeWindowTimer()   //Käynnistetään 30s ajastin
{
    homeWindowTimer->start();
}

void MainMenu::saveID(QString cardID)   //Tallennetaan kortin sarjanumero
{
    customerCardID = cardID;
}

void MainMenu::setCustomerData(QString nameID, QString name, QString accNum, QString balance)
{
    //Asetetaan käyttäjän tiedot näkyviin käyttöliittymiin
    customerID = nameID.toInt();
    customerName = name;
    customerAccountNumber = accNum;
    customerBalance = balance;
    ui->mainNameLabel->setText(name);
}

void MainMenu::setTransactions(QString event, QString amount, QString date)
{
    //Asetetaan käyttäjän tilitapahtumat näkyviin käyttöliittymiin
    ui->blcEventLabel->setText(event);
    ui->blcAmountLabel->setText(amount);
    ui->blcDateLabel->setText(date);
    ui->trcEventLabel->setText(event);
    ui->trcAmountLabel->setText(amount);
    ui->trcDateLabel->setText(date);
}

void MainMenu::backToMainMenu()
{
    //Palataan pääkäyttöliittymään ja nollataan mahdollisesti syötetyt tiedot
    ui->stackedWidget->setCurrentIndex(0);
    ui->otherAmountLineEdit->clear();
    ui->trfAccNumLineEdit->clear();
    ui->trfAmountLineEdit->clear();
    ui->accNumLineEdit->clear();
    ui->amountInsertLineEdit->clear();
    wtdrAmount = "";
    trfAccNum = "";
    trfAmount = "";
    homeWindowTimer->start();
}

void MainMenu::withdrawResult(QString result)
{
    if(result == "false")    //Jos käyttäjällä ei ollut tarpeeksi rahaa nostoon
    {
        failMessage->show();
        QTimer::singleShot(10000, failMessage, SLOT(close()));
        mainMenuTimer->start();
        on_otherClearButton_clicked();
    }
    else if(result == "error")  //Jos tietokantaan ei saada yhteyttä
    {
        QMessageBox::warning(this, "Virhe", "Virhe tietokantayhteydessä!");
        mainMenuTimer->start();
        on_otherClearButton_clicked();
    }
    else    //Nosto onnistui, ilmoitetaan käyttäjälle ja kirjaudutaan ulos
    {
        QMessageBox::information(this, "Onnistunut nosto", "Haluamasi summan nosto onnistui! Kirjaudutaan ulos..");
        ui->stackedWidget->setCurrentIndex(0);
        on_otherClearButton_clicked();
        emit logoutSignal();
    }
}

void MainMenu::transferResult(QString result)
{
    if(result == "false")   //Jos käyttäjällä ei ollut tarpeeksi rahaa siirtoon
    {
        failMessage->show();
        QTimer::singleShot(10000, failMessage, SLOT(close()));
        mainMenuTimer->start();
    }
    else if(result == "error")  //Jos tietokantaan ei saada yhteyttä
    {
        QMessageBox::warning(this, "Virhe", "Virhe tietokantayhteydessä!");
        mainMenuTimer->start();
    }
    else    //Tilisiirto onnistui, ilmoitetaan käyttäjälle, päivitetään tiedot ja palataan pääkäyttöliittymään
    {
        QMessageBox::information(this, "Onnistunut siirto", "Tilisiirto onnistui!");
        on_trfCloseButton_clicked();
        emit updateCustomerData(customerCardID);
    }
}


/***************PÄÄVALIKKO***************/

void MainMenu::on_mainWithdrawButton_clicked()  //Painetaan Nosta rahaa-painiketta
{
    homeWindowTimer->stop();
    mainMenuTimer->start();
    ui->wtdrNameLabel->setText(customerName);
    ui->wtdrBalanceLabel->setText(customerBalance+"€");
    ui->stackedWidget->setCurrentIndex(1);    
}

void MainMenu::on_mainBalanceButton_clicked()   //Painetaan Näytä saldo-painiketta
{
    homeWindowTimer->stop();
    mainMenuTimer->start();
    emit transactions(customerCardID,"0");
    ui->blcNameLabel->setText(customerName);
    ui->blcAccountLabel->setText(customerAccountNumber);
    ui->blcBalanceLabel->setText(customerBalance+"€");
    ui->stackedWidget->setCurrentIndex(2);    
}

void MainMenu::on_mainTransactionButton_clicked()   //Painetaan Selaa tilitapahtumia-painiketta
{
    homeWindowTimer->stop();
    mainMenuTimer->start();
    emit transactions(customerCardID,"0");
    ui->trcNameLabel->setText(customerName);
    ui->trcAccountLabel->setText(customerAccountNumber);
    ui->trcBalanceLabel->setText(customerBalance+"€");
    ui->stackedWidget->setCurrentIndex(3);    
}

void MainMenu::on_mainTransferButton_clicked()  //Painetaan Tilisiirto-painiketta
{
    homeWindowTimer->stop();
    mainMenuTimer->start();
    ui->trfNameLabel->setText(customerName);
    ui->trfAccountNumLabel->setText(customerAccountNumber);
    ui->trfBalanceLabel->setText(customerBalance+"€");
    ui->stackedWidget->setCurrentIndex(4);    
}

void MainMenu::on_mainLogoutButton_clicked()    //Painetaan Kirjaudu ulos-painiketta
{
    homeWindowTimer->stop();
    customerName = "";
    emit logoutSignal();
}


/***************NOSTA RAHAA***************/

void MainMenu::on_wtdrButton20_clicked()    //Nostetaan käyttäjän haluama summa
{
    qDebug() << "Customer ID: " << customerID;
    mainMenuTimer->stop();
    emit withdraw(customerID, 20);
}

void MainMenu::on_wtdrButton40_clicked()
{
    mainMenuTimer->stop();
    emit withdraw(customerID, 40);
}

void MainMenu::on_wtdrButton60_clicked()
{
    mainMenuTimer->stop();
    emit withdraw(customerID, 60);
}

void MainMenu::on_wtdrButton100_clicked()
{
    mainMenuTimer->stop();
    emit withdraw(customerID, 100);
}

void MainMenu::on_wtdrButton200_clicked()
{
    mainMenuTimer->stop();
    emit withdraw(customerID, 200);
}

void MainMenu::on_wtdrButton500_clicked()
{
    mainMenuTimer->stop();
    emit withdraw(customerID, 500);
}

void MainMenu::on_wtdrButtonOther_clicked()
{
    resetTimer();
    ui->stackedWidget->setCurrentIndex(7);
}

void MainMenu::on_wtdrButtonClose_clicked()
{
    mainMenuTimer->stop();
    homeWindowTimer->start();
    ui->stackedWidget->setCurrentIndex(0); 
}


/***************NÄYTÄ SALDO***************/

void MainMenu::on_blcCloseButton_clicked()
{
    mainMenuTimer->stop();
    homeWindowTimer->start();
    ui->stackedWidget->setCurrentIndex(0); 
}


/***************TILITAPAHTUMAT***************/

void MainMenu::on_trcNextButton_clicked()   //10 tilitapahtumaa eteenpäin
{
    startingPoint += 10;
    QString sPoint = QString::number(startingPoint);
    emit transactions(customerCardID, sPoint);
    resetTimer();
}

void MainMenu::on_trcPreviousButton_clicked()   //10 tilitapahtumaa taaksepäin
{
    if(startingPoint != 0)
    {
        startingPoint -= 10;
    }
    QString sPoint = QString::number(startingPoint);
    emit transactions(customerCardID, sPoint);
    resetTimer();
}

void MainMenu::on_trcCloseButton_clicked()
{
    mainMenuTimer->stop();
    homeWindowTimer->start();
    ui->stackedWidget->setCurrentIndex(0);
}


/***************TILISIIRTO***************/

void MainMenu::on_trfNextButton_clicked()
{
    mainMenuTimer->stop();
    int transferAccount;
    transferAccount = trfAccNum.toInt();    //Otetaan käyttäjän syöttämä tilinro talteen
    double transferAmount;
    transferAmount = trfAmount.toDouble();  //Otetaan käyttäjän syöttämä siirrettävä summa talteen
    QMessageBox confirmation;
    confirmation.setText(tr("Haluatko varmasti siirtää valitun summan?"));
    QAbstractButton *pButtonYes = confirmation.addButton(tr("Kyllä"), QMessageBox::YesRole);
    confirmation.addButton(tr("Peruuta"), QMessageBox::NoRole);
    confirmation.exec();
    if(confirmation.clickedButton() == pButtonYes)
    {
        emit transfer(customerID, transferAccount, transferAmount);
    }
    else
    {
        mainMenuTimer->start();
    }
}

void MainMenu::on_trfCloseButton_clicked()
{
    on_accNumClearButton_clicked();
    on_amountInsertClearButton_clicked();
    mainMenuTimer->stop();
    homeWindowTimer->start();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainMenu::on_trfAddAccNumButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    resetTimer();
}

void MainMenu::on_trfAddAmountButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    resetTimer();
}


/***************MUU SUMMA***************/

void MainMenu::on_otherButton0_clicked()
{
    insertOtherAmountNum("0");
    resetTimer();
}

void MainMenu::on_otherButton1_clicked()
{
    insertOtherAmountNum("1");
    resetTimer();
}

void MainMenu::on_otherButton2_clicked()
{
    insertOtherAmountNum("2");
    resetTimer();
}

void MainMenu::on_otherButton3_clicked()
{
    insertOtherAmountNum("3");
    resetTimer();
}

void MainMenu::on_otherButton4_clicked()
{
    insertOtherAmountNum("4");
    resetTimer();
}

void MainMenu::on_otherButton5_clicked()
{
    insertOtherAmountNum("5");
    resetTimer();
}

void MainMenu::on_otherButton6_clicked()
{
    insertOtherAmountNum("6");
    resetTimer();
}

void MainMenu::on_otherButton7_clicked()
{
    insertOtherAmountNum("7");
    resetTimer();
}

void MainMenu::on_otherButton8_clicked()
{
    insertOtherAmountNum("8");
    resetTimer();
}

void MainMenu::on_otherButton9_clicked()
{
    insertOtherAmountNum("9");
    resetTimer();
}

void MainMenu::on_otherClearButton_clicked()
{
    ui->otherAmountLineEdit->clear();
    wtdrAmount = "";
    resetTimer();
}

void MainMenu::on_otherNextButton_clicked()
{
    double wtdrOtherAmount;
    wtdrOtherAmount = ui->otherAmountLineEdit->text().toDouble();    //Otetaan käyttäjän syöttämä rahasumma talteen
    if(std::fmod(wtdrOtherAmount, 10) != 0)
    {
        QMessageBox::warning(this, "Virheellinen rahasumma", "Huomioithan, että pienin nostettava seteli on 10€");
        on_otherClearButton_clicked();
    }
    else
    {
        emit withdraw(customerID, wtdrOtherAmount);
    }
}

void MainMenu::on_otherCancelButton_clicked()
{
    on_otherClearButton_clicked();
    ui->stackedWidget->setCurrentIndex(1);
    resetTimer();
}


/***************TILINUMERON SYÖTTÖ***************/

void MainMenu::on_accNumButton0_clicked()
{
    insertAccNum("0");
    resetTimer();
}

void MainMenu::on_accNumButton1_clicked()
{
    insertAccNum("1");
    resetTimer();
}

void MainMenu::on_accNumButton2_clicked()
{
    insertAccNum("2");
    resetTimer();
}

void MainMenu::on_accNumButton3_clicked()
{
    insertAccNum("3");
    resetTimer();
}

void MainMenu::on_accNumButton4_clicked()
{
    insertAccNum("4");
    resetTimer();
}

void MainMenu::on_accNumButton5_clicked()
{
    insertAccNum("5");
    resetTimer();
}

void MainMenu::on_accNumButton6_clicked()
{
    insertAccNum("6");
    resetTimer();
}

void MainMenu::on_accNumButton7_clicked()
{
    insertAccNum("7");
    resetTimer();
}

void MainMenu::on_accNumButton8_clicked()
{
    insertAccNum("8");
    resetTimer();
}

void MainMenu::on_accNumButton9_clicked()
{
    insertAccNum("9");
    resetTimer();
}

void MainMenu::on_accNumClearButton_clicked()
{
    ui->trfAccNumLineEdit->clear();
    ui->accNumLineEdit->clear();
    trfAccNum = "";
    resetTimer();
}

void MainMenu::on_accNumNextButton_clicked()
{
    ui->trfAccNumLineEdit->setText(trfAccNum);
    ui->stackedWidget->setCurrentIndex(4);
    resetTimer();
}

void MainMenu::on_accNumCancelButton_clicked()
{
    on_accNumClearButton_clicked();
    ui->stackedWidget->setCurrentIndex(4);
    resetTimer();
}


/***************SIIRRETTÄVÄN SUMMAN SYÖTTÖ***************/

void MainMenu::on_amountInsertButton0_clicked()
{
    insertAmountNum("0");
    resetTimer();
}

void MainMenu::on_amountInsertButton1_clicked()
{
    insertAmountNum("1");
    resetTimer();
}

void MainMenu::on_amountInsertButton2_clicked()
{
    insertAmountNum("2");
    resetTimer();
}

void MainMenu::on_amountInsertButton3_clicked()
{
    insertAmountNum("3");
    resetTimer();
}

void MainMenu::on_amountInsertButton4_clicked()
{
    insertAmountNum("4");
    resetTimer();
}

void MainMenu::on_amountInsertButton5_clicked()
{
    insertAmountNum("5");
    resetTimer();
}

void MainMenu::on_amountInsertButton6_clicked()
{
    insertAmountNum("6");
    resetTimer();
}

void MainMenu::on_amountInsertButton7_clicked()
{
    insertAmountNum("7");
    resetTimer();
}

void MainMenu::on_amountInsertButton8_clicked()
{
    insertAmountNum("8");
    resetTimer();
}

void MainMenu::on_amountInsertButton9_clicked()
{
    insertAmountNum("9");
    resetTimer();
}

void MainMenu::on_amountInsertCommaButton_clicked()
{
    if(transferCommaCounter == 0) //Varmistetaan ettei käyttäjä syötä montaa pilkkua
    {
        insertAmountNum(".");
    }
    else
    {
        QMessageBox::warning(this, "Virhe", "Liikaa desimaaleja syötetty!");
    }
    transferCommaCounter++;
    resetTimer();
}

void MainMenu::on_amountInsertClearButton_clicked()
{
    ui->amountInsertLineEdit->clear();
    ui->trfAmountLineEdit->clear();
    trfAmount = "";
    transferCommaCounter = 0;
    resetTimer();
}

void MainMenu::on_amountInsertNextButton_clicked()
{
    ui->trfAmountLineEdit->setText(trfAmount+"€");
    ui->stackedWidget->setCurrentIndex(4);
    resetTimer();
}

void MainMenu::on_amountInsertCancelButton_clicked()
{
    on_amountInsertClearButton_clicked();
    ui->stackedWidget->setCurrentIndex(4);
    resetTimer();
}
