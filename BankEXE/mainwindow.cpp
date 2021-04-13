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
    ptrMainDialog = new MainDialog;
    connect(ptrMainDialog, SIGNAL(logoutSignal()),
            this, SLOT(show()));
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete ptrMainDialog;
    ptrMainDialog = nullptr;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    ptrMainDialog->show();
}
