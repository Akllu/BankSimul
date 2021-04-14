#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QMessageBox>
#include <QTimer>
#include <QIntValidator>
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
    void insertAccNum(QString i);
    void insertAmountNum(QString i);

signals:
    void logoutSignal();

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

private:
    Ui::MainMenu *ui;
    double otherAmount; //Käyttäjän syöttämä Muu summa
    QString clickedNum; //Näppäimistöstä painettu näppäin
    QString trfAccNum;  //Saajan tilinumero
    QString trfAmount;  //Saajalle menevä summa
};

#endif // MAINMENU_H