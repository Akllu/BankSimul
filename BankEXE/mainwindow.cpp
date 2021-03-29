#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pic("C:/rfid.jpg");
    ui->pictureLabel->setPixmap(pic.scaled(400,400,Qt::KeepAspectRatio));
    setWindowTitle("BankSimul");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ptrPINDialog = new PINDialog;
    ptrPINDialog->setWindowTitle("BankSimul");
    ptrPINDialog->show();
    this->close();
    ptrPINDialog->exec();
    delete ptrPINDialog;
    ptrPINDialog = nullptr;
}
