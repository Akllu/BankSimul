#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;

}

void MainDialog::receiveSignal()
{
    this->show();
}

void MainDialog::on_withdrawButton_clicked()
{
    ptrWithdraw = new WithdrawDialog;
    ptrWithdraw->setWindowTitle("BankSimul");
    ptrWithdraw->show();
    this->hide();
    ptrWithdraw->exec();
    delete ptrWithdraw;
    ptrWithdraw = nullptr;
}

void MainDialog::on_balanceButton_clicked()
{
    ptrBalance = new balanceDialog;
    ptrBalance->setWindowTitle("BankSimul");
    ptrBalance->show();
    this->hide();
    ptrBalance->exec();
    delete ptrBalance;
    ptrBalance = nullptr;

}

void MainDialog::on_transactionButton_clicked()
{
    ptrTransactions = new transactionsDialog;
    ptrTransactions->setWindowTitle("BankSimul");
    ptrTransactions->show();
    this->hide();
    ptrTransactions->exec();
    delete ptrTransactions;
    ptrTransactions = nullptr;
}

void MainDialog::on_transferButton_clicked()
{
    ptrTransfer = new transferDialog;
    ptrTransfer->setWindowTitle("BankSimul");
    ptrTransfer->show();
    this->hide();
    ptrTransfer->exec();
    delete ptrTransfer;
    ptrTransfer = nullptr;

}

void MainDialog::on_logoutButton_clicked()
{   /*
    QMessageBox message;
    message.setText("Kirjaudutaan ulos..");
    int counter = 10;
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&message,&counter,&timer]()->void
    {
        if(--counter < 0)
        {
            timer.stop();
            message.close();
        }
        timer.start(1000);
        message.exec();
    });
    */
    this->close();
}
