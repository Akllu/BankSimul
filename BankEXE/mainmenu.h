#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QMessageBox>
#include <QTimer>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

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

    void on_otherButton0_clicked();

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

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
