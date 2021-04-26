/*
Aleksi Kalliokoski TVT20SPL
*/

#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>

#include "mainmenu.h"
#include "serialportdll.h"
#include "pininterface.h"
#include "dllrestapi.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HomeWindow; }
QT_END_NAMESPACE

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

public slots:
    void backToHome();
    void getValueFromRFID();
    void dataFromRFID(QString);
    void login();
    void loginResult(QString);
    void getCustomerData(QString cardID);
    void getTransactions(QString cardID, int startingPoint);

signals:
    //void readRFID();

private slots:
    void on_pushButton_clicked();
    void handleWithdraw(int ID, double amount);
    void handleTransfer(int senderAccNum, int receiverAccNum, double amount);
    void handleCustomerData(QString nameID, QString name, QString accNum, QString balance);
    void handleTransactions(QString event, QString amount, QString date);

private:
    Ui::HomeWindow *ui;
    MainMenu *ptrMainMenu;
    SerialPortDLL *ptrSerialPort;
    PinInterface *ptrPIN;
    DLLRestAPI *ptrRestAPI;

    QString cardNum;
    QString cardPIN;
    short loginCounter;
};

#endif // HOMEWINDOW_H
