#include "transactionsdialog.h"
#include "ui_transactionsdialog.h"

transactionsDialog::transactionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transactionsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Tilitapahtumat");

    dialogTimer = new QTimer(this);
    dialogTimer->setInterval(10000);    //Jos käyttäjä ei tee mitään 10s, palataan päävalikkoon
    dialogTimer->setSingleShot(true);
    connect(dialogTimer, SIGNAL(timeout()), SLOT(on_closeButton_clicked()));
}

transactionsDialog::~transactionsDialog()
{
    delete ui;
    ui = nullptr;
    delete dialogTimer;
    dialogTimer = nullptr;
}

void transactionsDialog::resetTimer()
{
    dialogTimer->stop();
    dialogTimer->start();
}

void transactionsDialog::on_nextButton_clicked()
{
    //Eteenpäin 10 tilitapahtumaa
    resetTimer();
}

void transactionsDialog::on_previousButton_clicked()
{
    //Taaksepäin 10 tilitapahtumaa
    resetTimer();
}

void transactionsDialog::on_closeButton_clicked()
{
    dialogTimer->stop();
    this->close();
    emit closeSignal();
}
