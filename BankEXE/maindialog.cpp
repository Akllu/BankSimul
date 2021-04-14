#include "maindialog.h"
#include "ui_maindialog.h"
//#include "mainwindow.h"

MainDialog::MainDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("BankSimul");
    ptrWithdraw = new WithdrawDialog;
    ptrBalance = new balanceDialog;
    ptrTransactions = new transactionsDialog;
    ptrTransfer = new transferDialog;

    connect(ptrWithdraw, SIGNAL(closeSignal()), //Yhdistetään Sulje -painikkeet valikkoon palaamiseen
            this, SLOT(show()));

    connect(ptrBalance, SIGNAL(closeSignal()),
            this, SLOT(show()));

    connect(ptrTransactions, SIGNAL(closeSignal()),
            this, SLOT(show()));

    connect(ptrTransfer, SIGNAL(closeSignal()),
            this, SLOT(show()));

    connect(this, SIGNAL(timerSignal()),
            ptrWithdraw, SLOT(resetTimer()));

    connect(this, SIGNAL(timerSignal()),
            ptrBalance, SLOT(resetTimer()));

    connect(this, SIGNAL(timerSignal()),
            ptrTransactions, SLOT(resetTimer()));

    connect(this, SIGNAL(timerSignal()),
            ptrTransfer, SLOT(resetTimer()));
}

MainDialog::~MainDialog()
{
    delete ui;
    ui = nullptr;
    delete ptrWithdraw;
    ptrWithdraw = nullptr;
    delete ptrBalance;
    ptrBalance = nullptr;
    delete ptrTransactions;
    ptrTransactions = nullptr;
    delete ptrTransfer;
    ptrTransfer = nullptr;
}

void MainDialog::on_withdrawButton_clicked()
{
    this->close();
    emit timerSignal();
    ptrWithdraw->show();
}

void MainDialog::on_balanceButton_clicked()
{
    this->close();
    emit timerSignal();
    ptrBalance->show();
}

void MainDialog::on_transactionButton_clicked()
{
    this->close();
    emit timerSignal();
    ptrTransactions->show();
}

void MainDialog::on_transferButton_clicked()
{
    this->hide();
    emit timerSignal();
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
    emit logoutSignal();
}

