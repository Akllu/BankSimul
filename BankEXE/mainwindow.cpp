#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pic("C:/rfid.png"); //HUOM! Kuvan osoite
    ui->pictureLabel->setPixmap(pic.scaled(500,500,Qt::KeepAspectRatio));   //Skaalataan kuva
    setWindowTitle("BankSimul");
    ptrPINDialog = new PINDialog;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrPINDialog;
    ptrPINDialog = nullptr;
}

void MainWindow::on_pushButton_clicked()
{
    ptrPINDialog->setWindowTitle("BankSimul");
    //this->hide();
    ptrPINDialog->show();
}
