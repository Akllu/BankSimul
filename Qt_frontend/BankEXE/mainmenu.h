#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QMessageBox>
#include <QTimer>
#include <cmath>
#include <QDebug>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
    void insertOtherAmountNum(QString i);
    void insertAccNum(QString i);
    void insertAmountNum(QString i);
    void resetTimer();
    void startHomeWindowTimer();
    void saveID(QString cardID);
    void setCustomerData(QString nameID, QString name, QString accNum, QString balance);
    void setTransactions(QString event, QString amount, QString date);

public slots:
    void backToMainMenu();
    void withdrawResult(QString result);
    void transferResult(QString result);

signals:
    void logoutSignal();
    void updateCustomerData(QString);
    void transactions(QString,QString);
    void withdraw(int,double);
    void transfer(int,int,double);

private slots:
    void on_mainWithdrawButton_clicked();   //Päävalikko
    void on_mainBalanceButton_clicked();
    void on_mainTransactionButton_clicked();
    void on_mainTransferButton_clicked();
    void on_mainLogoutButton_clicked();

    void on_wtdrButtonClose_clicked();  //Nosta rahaa
    void on_wtdrButton20_clicked();
    void on_wtdrButton40_clicked();
    void on_wtdrButton60_clicked();
    void on_wtdrButton100_clicked();
    void on_wtdrButton200_clicked();
    void on_wtdrButton500_clicked();
    void on_wtdrButtonOther_clicked();

    void on_blcCloseButton_clicked();   //Näytä saldo

    void on_trcNextButton_clicked();    //Tilitapahtumat
    void on_trcPreviousButton_clicked();
    void on_trcCloseButton_clicked();

    void on_trfNextButton_clicked();    //Tilisiirto
    void on_trfCloseButton_clicked();
    void on_trfAddAccNumButton_clicked();
    void on_trfAddAmountButton_clicked();

    void on_otherButton0_clicked();     //Muu summa
    void on_otherButton1_clicked();
    void on_otherButton2_clicked();
    void on_otherButton3_clicked();
    void on_otherButton4_clicked();
    void on_otherButton5_clicked();
    void on_otherButton6_clicked();
    void on_otherButton7_clicked();
    void on_otherButton8_clicked();
    void on_otherButton9_clicked();
    void on_otherClearButton_clicked();
    void on_otherNextButton_clicked();
    void on_otherCancelButton_clicked();

    void on_accNumButton0_clicked();    //Tilinumeron syöttö
    void on_accNumButton1_clicked();
    void on_accNumButton2_clicked();
    void on_accNumButton3_clicked();
    void on_accNumButton4_clicked();
    void on_accNumButton5_clicked();
    void on_accNumButton6_clicked();
    void on_accNumButton7_clicked();
    void on_accNumButton8_clicked();
    void on_accNumButton9_clicked();
    void on_accNumClearButton_clicked();
    void on_accNumNextButton_clicked();
    void on_accNumCancelButton_clicked();

    void on_amountInsertButton0_clicked();  //Siirrettävän summan syöttö
    void on_amountInsertButton1_clicked();
    void on_amountInsertButton2_clicked();
    void on_amountInsertButton3_clicked();
    void on_amountInsertButton4_clicked();
    void on_amountInsertButton5_clicked();
    void on_amountInsertButton6_clicked();
    void on_amountInsertButton7_clicked();
    void on_amountInsertButton8_clicked();
    void on_amountInsertButton9_clicked();
    void on_amountInsertClearButton_clicked();
    void on_amountInsertNextButton_clicked();
    void on_amountInsertCancelButton_clicked();
    void on_amountInsertCommaButton_clicked();

private:
    Ui::MainMenu *ui;
    QString wtdrAmount; //Käyttäjän syöttämä Muu summa
    QString trfAccNum;  //Saajan tilinumero
    QString trfAmount;  //Tilisiirron summa
    QString customerName;   //Käyttäjän nimi
    QString customerAccountNumber;  //Käyttäjän tilinumero
    QString customerBalance;    //Käyttäjän saldo
    QString customerCardID;     //Käyttäjän kortin sarjanumero
    QTimer *mainMenuTimer;      //10s ajastimet
    QTimer *homeWindowTimer;    //30s ajastin
    QMessageBox *failMessage;   //Ilmoitus jos saldo ei riitä

    int customerID;     //Käyttäjän ID-numero
    int transferCommaCounter;    //Laskuri tilisiirron pilkkuja varten
    int startingPoint;
};

#endif // MAINMENU_H
