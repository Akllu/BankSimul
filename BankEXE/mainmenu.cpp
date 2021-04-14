#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent):
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("BankSimul");
}

MainMenu::~MainMenu()
{
    delete ui;
    ui = nullptr;
}


/***************PÄÄVALIKKO***************/

void MainMenu::on_mainWithdrawButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
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
    ui->stackedWidget->setCurrentIndex(7);
}

void MainMenu::on_wtdrButtonClose_clicked()
{
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

}

void MainMenu::on_otherButton1_clicked()
{

}

void MainMenu::on_otherButton2_clicked()
{

}

void MainMenu::on_otherButton3_clicked()
{

}

void MainMenu::on_otherButton4_clicked()
{

}

void MainMenu::on_otherButton5_clicked()
{

}

void MainMenu::on_otherButton6_clicked()
{

}

void MainMenu::on_otherButton7_clicked()
{

}

void MainMenu::on_otherButton8_clicked()
{

}

void MainMenu::on_otherButton9_clicked()
{

}

void MainMenu::on_otherClearButton_clicked()
{

}

void MainMenu::on_otherNextButton_clicked()
{

}

void MainMenu::on_otherCancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


/***************TILINUMERON SYÖTTÖ***************/

void MainMenu::on_accNumButton0_clicked()
{

}

void MainMenu::on_accNumButton1_clicked()
{

}

void MainMenu::on_accNumButton2_clicked()
{

}

void MainMenu::on_accNumButton3_clicked()
{

}

void MainMenu::on_accNumButton4_clicked()
{

}

void MainMenu::on_accNumButton5_clicked()
{

}

void MainMenu::on_accNumButton6_clicked()
{

}

void MainMenu::on_accNumButton7_clicked()
{

}

void MainMenu::on_accNumButton8_clicked()
{

}

void MainMenu::on_accNumButton9_clicked()
{

}

void MainMenu::on_accNumClearButton_clicked()
{

}

void MainMenu::on_accNumNextButton_clicked()
{

}

void MainMenu::on_accNumCancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    //Clear?
}


/***************SIIRRETTÄVÄN SUMMAN SYÖTTÖ***************/

void MainMenu::on_amountInsertButton0_clicked()
{

}

void MainMenu::on_amountInsertButton1_clicked()
{

}

void MainMenu::on_amountInsertButton2_clicked()
{

}

void MainMenu::on_amountInsertButton3_clicked()
{

}

void MainMenu::on_amountInsertButton4_clicked()
{

}

void MainMenu::on_amountInsertButton5_clicked()
{

}

void MainMenu::on_amountInsertButton6_clicked()
{

}

void MainMenu::on_amountInsertButton7_clicked()
{

}

void MainMenu::on_amountInsertButton8_clicked()
{

}

void MainMenu::on_amountInsertButton9_clicked()
{

}

void MainMenu::on_amountInsertClearButton_clicked()
{

}

void MainMenu::on_amountInsertNextButton_clicked()
{

}

void MainMenu::on_amountInsertCancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    //Clear??
}
