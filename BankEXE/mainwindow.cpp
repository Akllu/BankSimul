#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pic(":/resources/Pictures/rfid.png");
    ui->pictureLabel->setPixmap(pic.scaled(500,500,Qt::KeepAspectRatio));   //Skaalataan kuva
    setWindowTitle("BankSimul");
    ptrPINDialog = new PINDialog;
    ptrMainDialog = new MainDialog;
    /*
      connect(ptrMainDialog, SIGNAL(sendSignal()),
            this, SLOT(showMainWindow()));
            */
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete ptrPINDialog;
    ptrPINDialog = nullptr;
    delete ptrMainDialog;
    ptrMainDialog = nullptr;
}

void MainWindow::showMainWindow()
{
    //this->show();
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    ptrPINDialog->exec();
    ptrMainDialog->exec();
    this->show();
}





