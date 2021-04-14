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

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
