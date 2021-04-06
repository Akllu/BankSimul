#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    ptrWithdraw = new WithdrawDialog();
    connect(ptrWithdraw, SIGNAL(closeSignal()), //Yhdistetään Sulje -painikkeet valikkoon palaamiseen
            this, SLOT(returnToDialog()));
    ptrBalance = new balanceDialog;
    connect(ptrBalance, SIGNAL(closeSignal()),
            this, SLOT(returnToDialog()));
    ptrTransactions = new transactionsDialog;
    connect(ptrTransactions, SIGNAL(closeSignal()),
            this, SLOT(returnToDialog()));
    ptrTransfer = new transferDialog;
    connect(ptrTransfer, SIGNAL(closeSignal()),
            this, SLOT(returnToDialog()));
}

MainDialog::~MainDialog()
{
    delete ui;
    delete ptrWithdraw;
    ptrWithdraw = nullptr;
    delete ptrBalance;
    ptrBalance = nullptr;
    delete ptrTransactions;
    ptrTransactions = nullptr;
    delete ptrTransfer;
    ptrTransfer = nullptr;
}

void MainDialog::returnToDialog()
{
    this->show();
}


void MainDialog::on_withdrawButton_clicked()
{
    ptrWithdraw->setWindowTitle("BankSimul");
    this->hide();
    ptrWithdraw->show();
}

void MainDialog::on_balanceButton_clicked()
{
    ptrBalance->setWindowTitle("BankSimul");
    this->hide();
    ptrBalance->show();
}

void MainDialog::on_transactionButton_clicked()
{
    ptrTransactions->setWindowTitle("BankSimul");
    this->hide();
    ptrTransactions->show();    
}

void MainDialog::on_transferButton_clicked()
{
    ptrTransfer->setWindowTitle("BankSimul");
    this->hide();
    ptrTransfer->show();
}

void MainDialog::on_logoutButton_clicked()
{
    /* QMessageBox message;
    message.setText("Kirjaudutaan ulos..");
    int counter = 10;
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&message,&counter,&timer]()->void
    {
        if(counter > 0)
        {
            timer.stop();
            message.close();
        }
        counter--;
        timer.start(1000);
        message.exec();
    });
    */

    this->close();
}

