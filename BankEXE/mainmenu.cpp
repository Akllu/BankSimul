#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent):
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("BankSimul");

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
}

void MainMenu::insertOtherAmountNum(QString i)
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

void MainMenu::resetTimer()
{
    mainMenuTimer->stop();
    mainMenuTimer->start();
}

void MainMenu::withdrawSuccessful()
{
    QMessageBox::information(this, "Onnistunut nosto", "Haluamasi summan nosto onnistui! Kirjaudutaan ulos..");
    ui->stackedWidget->setCurrentIndex(0);
    emit logoutSignal();
}

void MainMenu::withdrawFailed()
{

    QMessageBox *failMessage = new QMessageBox;
    failMessage->setWindowTitle("Virheellinen rahasumma");
    failMessage->setIcon(QMessageBox::Warning);
    failMessage->setText("Tilin saldo ei riitä!");

    failMessage->show();
    QTimer::singleShot(10000, failMessage, SLOT(close()));
    //QMessageBox::warning(this, "Virheellinen rahasumma", "Tilin saldo ei riitä!");
    mainMenuTimer->start();

}

void MainMenu::startHomeWindowTimer()
{
    homeWindowTimer->start();
}

void MainMenu::backToMainMenu()
{
    ui->stackedWidget->setCurrentIndex(0);  //Palataan pääkäyttöliittymään ja nollataan mahdollisesti syötetyt tiedot
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


/***************PÄÄVALIKKO***************/

void MainMenu::on_mainWithdrawButton_clicked()
{
    homeWindowTimer->stop();
    mainMenuTimer->start();
    ui->stackedWidget->setCurrentIndex(1);    
}

void MainMenu::on_mainBalanceButton_clicked()
{
    homeWindowTimer->stop();
    mainMenuTimer->start();
    ui->stackedWidget->setCurrentIndex(2);    
}

void MainMenu::on_mainTransactionButton_clicked()
{
    homeWindowTimer->stop();
    mainMenuTimer->start();
    ui->stackedWidget->setCurrentIndex(3);    
}

void MainMenu::on_mainTransferButton_clicked()
{
    homeWindowTimer->stop();
    mainMenuTimer->start();
    ui->stackedWidget->setCurrentIndex(4);    
}

void MainMenu::on_mainLogoutButton_clicked()
{
    homeWindowTimer->stop();
    emit logoutSignal();
}


/***************NOSTA RAHAA***************/

void MainMenu::on_wtdrButton20_clicked()
{
    mainMenuTimer->stop();
    if (balance < 20) //Tarkistetaan voidaanko syötetty summa nostaa
    {
        withdrawFailed();
    }
    else
    {
        //Vähennetään kirjautuneen tililtä 20€
        withdrawSuccessful();
    }
}

void MainMenu::on_wtdrButton40_clicked()
{
    mainMenuTimer->stop();
    if (balance < 40)
    {
        withdrawFailed();
    }
    else
    {
        //Vähennetään kirjautuneen tililtä 40€
        withdrawSuccessful();
    }
}

void MainMenu::on_wtdrButton60_clicked()
{
    mainMenuTimer->stop();
    if (balance < 60)
    {
        withdrawFailed();
    }
    else
    {
        //Vähennetään kirjautuneen tililtä 60€
        withdrawSuccessful();
    }
}

void MainMenu::on_wtdrButton100_clicked()
{
    mainMenuTimer->stop();
    if (balance < 100)
    {
        withdrawFailed();
    }
    else
    {
        //Vähennetään kirjautuneen tililtä 100€
        withdrawSuccessful();
    }
}

void MainMenu::on_wtdrButton200_clicked()
{
    mainMenuTimer->stop();
    if (balance < 200)
    {
        withdrawFailed();
    }
    else
    {
        //Vähennetään kirjautuneen tililtä 200€
        withdrawSuccessful();
    }
}

void MainMenu::on_wtdrButton500_clicked()
{
    mainMenuTimer->stop();
    if (balance < 500)
    {
        withdrawFailed();
    }
    else
    {
        //Vähennetään kirjautuneen tililtä 500€
        withdrawSuccessful();
    }
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

void MainMenu::on_trcNextButton_clicked()
{
    //10 tilitapahtumaa eteenpäin
    resetTimer();
}

void MainMenu::on_trcPreviousButton_clicked()
{
    //10 tilitapahtumaa taaksepäin
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
    transferAmount = trfAmount.toDouble();
    QMessageBox confirmation;
    confirmation.setText(tr("Haluatko varmasti siirtää valitun summan?"));
    QAbstractButton *pButtonYes = confirmation.addButton(tr("Kyllä"), QMessageBox::YesRole);
    confirmation.addButton(tr("Peruuta"), QMessageBox::NoRole);
    confirmation.exec();
    if(confirmation.clickedButton() == pButtonYes)
    {
        if(balance < transferAmount)    //Tarkistetaan onko käyttäjällä rahaa siirtoon
        {
            withdrawFailed();
        }
        else
        {
            //Siirrä rahat ja vähennä summa lähettäjältä
            //HUOM! trfAccNum = Tilinumero johon rahat siirretään JA transferAmount = Siirrettävä summa
            QMessageBox::information(this, "Onnistunut siirto", "Tilisiirto onnistui!");
            on_trfCloseButton_clicked();
        }
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
    clickedNum = "0";
    insertOtherAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_otherButton1_clicked()
{
    clickedNum = "1";
    insertOtherAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_otherButton2_clicked()
{
    clickedNum = "2";
    insertOtherAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_otherButton3_clicked()
{
    clickedNum = "3";
    insertOtherAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_otherButton4_clicked()
{
    clickedNum = "4";
    insertOtherAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_otherButton5_clicked()
{
    clickedNum = "5";
    insertOtherAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_otherButton6_clicked()
{
    clickedNum = "6";
    insertOtherAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_otherButton7_clicked()
{
    clickedNum = "7";
    insertOtherAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_otherButton8_clicked()
{
    clickedNum = "8";
    insertOtherAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_otherButton9_clicked()
{
    clickedNum = "9";
    insertOtherAmountNum(clickedNum);
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
    wtdrOtherAmount = ui->otherAmountLineEdit->text().toDouble();    //Otetaan käyttäjän syöttämä rahasumma talteen
    if(std::fmod(wtdrOtherAmount, 10) != 0)
    {
        QMessageBox::warning(this, "Virheellinen rahasumma", "Huomioithan, että pienin nostettava seteli on 10€");
        on_otherClearButton_clicked();
        wtdrOtherAmount = 0;
    }

    else if (balance < wtdrOtherAmount) //Tarkistetaan voidaanko syötetty summa nostaa
    {
        withdrawFailed();
        on_otherClearButton_clicked();
        wtdrOtherAmount = 0;
    }

    else
    {
        //Vähennetään kirjautuneen tililtä annettu summa
        withdrawSuccessful();
        on_otherClearButton_clicked();
        wtdrOtherAmount = 0;
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
    clickedNum = "0";
    insertAccNum(clickedNum);
    resetTimer();
}

void MainMenu::on_accNumButton1_clicked()
{
    clickedNum = "1";
    insertAccNum(clickedNum);
    resetTimer();
}

void MainMenu::on_accNumButton2_clicked()
{
    clickedNum = "2";
    insertAccNum(clickedNum);
    resetTimer();
}

void MainMenu::on_accNumButton3_clicked()
{
    clickedNum = "3";
    insertAccNum(clickedNum);
    resetTimer();
}

void MainMenu::on_accNumButton4_clicked()
{
    clickedNum = "4";
    insertAccNum(clickedNum);
    resetTimer();
}

void MainMenu::on_accNumButton5_clicked()
{
    clickedNum = "5";
    insertAccNum(clickedNum);
    resetTimer();
}

void MainMenu::on_accNumButton6_clicked()
{
    clickedNum = "6";
    insertAccNum(clickedNum);
    resetTimer();
}

void MainMenu::on_accNumButton7_clicked()
{
    clickedNum = "7";
    insertAccNum(clickedNum);
    resetTimer();
}

void MainMenu::on_accNumButton8_clicked()
{
    clickedNum = "8";
    insertAccNum(clickedNum);
    resetTimer();
}

void MainMenu::on_accNumButton9_clicked()
{
    clickedNum = "9";
    insertAccNum(clickedNum);
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
    clickedNum = "0";
    insertAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_amountInsertButton1_clicked()
{
    clickedNum = "1";
    insertAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_amountInsertButton2_clicked()
{
    clickedNum = "2";
    insertAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_amountInsertButton3_clicked()
{
    clickedNum = "3";
    insertAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_amountInsertButton4_clicked()
{
    clickedNum = "4";
    insertAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_amountInsertButton5_clicked()
{
    clickedNum = "5";
    insertAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_amountInsertButton6_clicked()
{
    clickedNum = "6";
    insertAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_amountInsertButton7_clicked()
{
    clickedNum = "7";
    insertAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_amountInsertButton8_clicked()
{
    clickedNum = "8";
    insertAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_amountInsertButton9_clicked()
{
    clickedNum = "9";
    insertAmountNum(clickedNum);
    resetTimer();
}

void MainMenu::on_amountInsertClearButton_clicked()
{
    ui->amountInsertLineEdit->clear();
    ui->trfAmountLineEdit->clear();
    trfAmount = "";
    resetTimer();
}

void MainMenu::on_amountInsertNextButton_clicked()
{
    ui->trfAmountLineEdit->setText(trfAmount);
    ui->stackedWidget->setCurrentIndex(4);
    resetTimer();
}

void MainMenu::on_amountInsertCancelButton_clicked()
{
    on_amountInsertClearButton_clicked();
    ui->stackedWidget->setCurrentIndex(4);
    resetTimer();
}
