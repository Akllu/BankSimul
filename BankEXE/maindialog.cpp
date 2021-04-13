#include "maindialog.h"
#include "ui_maindialog.h"
//#include "mainwindow.h"

MainDialog::MainDialog(QWidget *parent): //, MainWindow *ptr) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("BankSimul");
    ptrWithdraw = new WithdrawDialog;
    ptrBalance = new balanceDialog;
    ptrTransactions = new transactionsDialog;
    ptrTransfer = new transferDialog;
    //ptrMainWindow = ptr;

    status = 1;

    /*connect(ptrWithdraw, SIGNAL(closeSignal()), //Yhdistetään Sulje -painikkeet valikkoon palaamiseen
            this, SLOT(show()));

    connect(ptrBalance, SIGNAL(closeSignal()),
            this, SLOT(returnToDialog()));

    connect(ptrTransactions, SIGNAL(closeSignal()),
            this, SLOT(returnToDialog()));

    connect(ptrTransfer, SIGNAL(closeSignal()),
            this, SLOT(returnToDialog()));*/
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
    this->hide();
    ptrWithdraw->exec();
    this->show();
    qDebug() << "Testi";
}

void MainDialog::on_balanceButton_clicked()
{
    this->hide();
    ptrBalance->exec();
    this->show();
}

void MainDialog::on_transactionButton_clicked()
{
    this->hide();
    ptrTransactions->exec();
    this->show();
}

void MainDialog::on_transferButton_clicked()
{
    this->hide();
    ptrTransfer->exec();
    this->show();
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
    //status = 0;

    this->close();

    //ptrMainWindow->show();
    //emit sendSignal();
}

