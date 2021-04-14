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


/***************PÄÄVALIKON PAINIKKEET***************/

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
    ui->stackedWidget->setCurrentIndex(5);
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


/***************TILISIIRTO***************/

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
