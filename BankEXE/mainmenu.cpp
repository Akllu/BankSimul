#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent):
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("BankSimul");
    mainMenuTimer = new QTimer(this);
    mainMenuTimer->setInterval(10000);
    mainMenuTimer->setSingleShot(true);
    connect(mainMenuTimer, SIGNAL(timeout()),
            this, SLOT(backToMainMenu()));
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

void MainMenu::backToMainMenu()
{
    ui->stackedWidget->setCurrentIndex(0);
}


/***************PÄÄVALIKKO***************/

void MainMenu::on_mainWithdrawButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    mainMenuTimer->start();
}

void MainMenu::on_mainBalanceButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainMenu::on_mainTransactionButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainMenu::on_mainTransferButton_clicked()
{
    on_accNumClearButton_clicked();
    on_amountInsertClearButton_clicked();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainMenu::on_mainLogoutButton_clicked()
{
    emit logoutSignal();
}


/***************NOSTA RAHAA***************/

void MainMenu::on_wtdrButton20_clicked()
{
    //Varmista saldo
    //Vähennä käyttäjältä 20€
}

void MainMenu::on_wtdrButton40_clicked()
{
    //Varmista saldo
    //Vähennä käyttäjältä 40€
}

void MainMenu::on_wtdrButton60_clicked()
{
    //Varmista saldo
    //Vähennä käyttäjältä 60€
}

void MainMenu::on_wtdrButton100_clicked()
{
    //Varmista saldo
    //Vähennä käyttäjältä 100€
}

void MainMenu::on_wtdrButton200_clicked()
{
    //Varmista saldo
    //Vähennä käyttäjältä 200€
}

void MainMenu::on_wtdrButton500_clicked()
{
    //Varmista saldo
    //Vähennä käyttäjältä 500€
}

void MainMenu::on_wtdrButtonOther_clicked()
{
    mainMenuTimer->stop();
    ui->stackedWidget->setCurrentIndex(7);
}

void MainMenu::on_wtdrButtonClose_clicked()
{
    mainMenuTimer->stop();
    ui->stackedWidget->setCurrentIndex(0);
}


/***************NÄYTÄ SALDO***************/

void MainMenu::on_blcCloseButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


/***************TILITAPAHTUMAT***************/

void MainMenu::on_trcNextButton_clicked()
{
    //10 tilitapahtumaa eteenpäin
}

void MainMenu::on_trcPreviousButton_clicked()
{
    //10 tilitapahtumaa taaksepäin
}

void MainMenu::on_trcCloseButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


/***************TILISIIRTO***************/

void MainMenu::on_trfNextButton_clicked()
{
    QMessageBox confirmation;
    confirmation.setText(tr("Haluatko varmasti siirtää valitun summan?"));
    QAbstractButton *pButtonYes = confirmation.addButton(tr("Kyllä"), QMessageBox::YesRole);
    confirmation.addButton(tr("Peruuta"), QMessageBox::NoRole);
    confirmation.exec();
    if(confirmation.clickedButton() == pButtonYes)
    {
        //Tarkista rahat
        //Siirrä rahat
        //trfAccNum  Tilinumero
        //trfAmount  Siirrettävä rahasumma
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MainMenu::on_trfCloseButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainMenu::on_trfAddAccNumButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainMenu::on_trfAddAmountButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


/***************MUU SUMMA***************/

void MainMenu::on_otherButton0_clicked()
{
    clickedNum = "0";
    insertOtherAmountNum(clickedNum);
}

void MainMenu::on_otherButton1_clicked()
{
    clickedNum = "1";
    insertOtherAmountNum(clickedNum);
}

void MainMenu::on_otherButton2_clicked()
{
    clickedNum = "2";
    insertOtherAmountNum(clickedNum);
}

void MainMenu::on_otherButton3_clicked()
{
    clickedNum = "3";
    insertOtherAmountNum(clickedNum);
}

void MainMenu::on_otherButton4_clicked()
{
    clickedNum = "4";
    insertOtherAmountNum(clickedNum);
}

void MainMenu::on_otherButton5_clicked()
{
    clickedNum = "5";
    insertOtherAmountNum(clickedNum);
}

void MainMenu::on_otherButton6_clicked()
{
    clickedNum = "6";
    insertOtherAmountNum(clickedNum);
}

void MainMenu::on_otherButton7_clicked()
{
    clickedNum = "7";
    insertOtherAmountNum(clickedNum);
}

void MainMenu::on_otherButton8_clicked()
{
    clickedNum = "8";
    insertOtherAmountNum(clickedNum);
}

void MainMenu::on_otherButton9_clicked()
{
    clickedNum = "9";
    insertOtherAmountNum(clickedNum);
}

void MainMenu::on_otherClearButton_clicked()
{
    ui->otherAmountLineEdit->clear();
    wtdrAmount = "";
}

void MainMenu::on_otherNextButton_clicked()
{
    wtdrOtherAmount = ui->otherAmountLineEdit->text().toDouble();    //Otetaan käyttäjän syöttämä rahasumma talteen
    if(std::fmod(wtdrOtherAmount, 10) != 0)
    {
        QMessageBox::warning(this, "Virheellinen rahasumma", "Huomioithan, että pienin nostettava seteli on 10€");
        on_otherClearButton_clicked();
        wtdrOtherAmount = 0;
        qDebug() << wtdrOtherAmount;
    }
    else
    {
        QMessageBox::information(this, "Onnistunut nosto", "Haluamasi summan nosto onnistui! Kirjaudutaan ulos..");
        qDebug() << wtdrOtherAmount;
        on_otherClearButton_clicked();
        wtdrOtherAmount = 0;
        ui->stackedWidget->setCurrentIndex(0);
        emit logoutSignal();
    }
}

void MainMenu::on_otherCancelButton_clicked()
{
    on_otherClearButton_clicked();
    ui->stackedWidget->setCurrentIndex(1);
}


/***************TILINUMERON SYÖTTÖ***************/

void MainMenu::on_accNumButton0_clicked()
{
    clickedNum = "0";
    insertAccNum(clickedNum);
}

void MainMenu::on_accNumButton1_clicked()
{
    clickedNum = "1";
    insertAccNum(clickedNum);
}

void MainMenu::on_accNumButton2_clicked()
{
    clickedNum = "2";
    insertAccNum(clickedNum);
}

void MainMenu::on_accNumButton3_clicked()
{
    clickedNum = "3";
    insertAccNum(clickedNum);
}

void MainMenu::on_accNumButton4_clicked()
{
    clickedNum = "4";
    insertAccNum(clickedNum);
}

void MainMenu::on_accNumButton5_clicked()
{
    clickedNum = "5";
    insertAccNum(clickedNum);
}

void MainMenu::on_accNumButton6_clicked()
{
    clickedNum = "6";
    insertAccNum(clickedNum);
}

void MainMenu::on_accNumButton7_clicked()
{
    clickedNum = "7";
    insertAccNum(clickedNum);
}

void MainMenu::on_accNumButton8_clicked()
{
    clickedNum = "8";
    insertAccNum(clickedNum);
}

void MainMenu::on_accNumButton9_clicked()
{
    clickedNum = "9";
    insertAccNum(clickedNum);
}

void MainMenu::on_accNumClearButton_clicked()
{
    ui->trfAccNumLineEdit->clear();
    ui->accNumLineEdit->clear();
    trfAccNum = "";
}

void MainMenu::on_accNumNextButton_clicked()
{
    ui->trfAccNumLineEdit->setText(trfAccNum);
    ui->stackedWidget->setCurrentIndex(4);
}

void MainMenu::on_accNumCancelButton_clicked()
{
    on_accNumClearButton_clicked();
    ui->stackedWidget->setCurrentIndex(4);
}


/***************SIIRRETTÄVÄN SUMMAN SYÖTTÖ***************/

void MainMenu::on_amountInsertButton0_clicked()
{
    clickedNum = "0";
    insertAmountNum(clickedNum);
}

void MainMenu::on_amountInsertButton1_clicked()
{
    clickedNum = "1";
    insertAmountNum(clickedNum);
}

void MainMenu::on_amountInsertButton2_clicked()
{
    clickedNum = "2";
    insertAmountNum(clickedNum);
}

void MainMenu::on_amountInsertButton3_clicked()
{
    clickedNum = "3";
    insertAmountNum(clickedNum);
}

void MainMenu::on_amountInsertButton4_clicked()
{
    clickedNum = "4";
    insertAmountNum(clickedNum);
}

void MainMenu::on_amountInsertButton5_clicked()
{
    clickedNum = "5";
    insertAmountNum(clickedNum);
}

void MainMenu::on_amountInsertButton6_clicked()
{
    clickedNum = "6";
    insertAmountNum(clickedNum);
}

void MainMenu::on_amountInsertButton7_clicked()
{
    clickedNum = "7";
    insertAmountNum(clickedNum);
}

void MainMenu::on_amountInsertButton8_clicked()
{
    clickedNum = "8";
    insertAmountNum(clickedNum);
}

void MainMenu::on_amountInsertButton9_clicked()
{
    clickedNum = "9";
    insertAmountNum(clickedNum);
}

void MainMenu::on_amountInsertClearButton_clicked()
{
    ui->amountInsertLineEdit->clear();
    ui->trfAmountLineEdit->clear();
    trfAmount = "";
}

void MainMenu::on_amountInsertNextButton_clicked()
{
    trfAmount.toDouble();   //Muunnetaan siirrettävä summa double tyyppiseksi
    ui->trfAmountLineEdit->setText(trfAmount);
    ui->stackedWidget->setCurrentIndex(4);
}

void MainMenu::on_amountInsertCancelButton_clicked()
{
    on_amountInsertClearButton_clicked();
    ui->stackedWidget->setCurrentIndex(4);
}
