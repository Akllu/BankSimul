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

}

void MainMenu::on_wtdrButtonClose_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
