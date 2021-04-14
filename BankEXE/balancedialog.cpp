#include "balancedialog.h"
#include "ui_balancedialog.h"

balanceDialog::balanceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::balanceDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Saldo");

    dialogTimer = new QTimer(this);
    dialogTimer->setInterval(10000);    //Jos käyttäjä ei tee mitään 10s, palataan päävalikkoon
    dialogTimer->setSingleShot(true);
    connect(dialogTimer, SIGNAL(timeout()), this, SLOT(on_closeButton_clicked()));
}

balanceDialog::~balanceDialog()
{
    delete ui;
    ui = nullptr;
    delete dialogTimer;
    dialogTimer = nullptr;
}

void balanceDialog::resetTimer()
{
    dialogTimer->stop();
    dialogTimer->start();
}

void balanceDialog::on_closeButton_clicked()
{
    dialogTimer->stop();
    this->close();
    emit closeSignal();
}
