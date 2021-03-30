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

}

void MainDialog::on_transactionButton_clicked()
{

}

void MainDialog::on_transferButton_clicked()
{

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
