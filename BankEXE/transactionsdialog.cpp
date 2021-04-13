#include "transactionsdialog.h"
#include "ui_transactionsdialog.h"

transactionsDialog::transactionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transactionsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Tilitapahtumat");
}

transactionsDialog::~transactionsDialog()
{
    delete ui;
    ui = nullptr;
}

void transactionsDialog::on_nextButton_clicked()
{
    //Eteenpäin 10 tilitapahtumaa
}

void transactionsDialog::on_previousButton_clicked()
{
    //Taaksepäin 10 tilitapahtumaa
}

void transactionsDialog::on_closeButton_clicked()
{
    this->close();
    emit closeSignal();
}
