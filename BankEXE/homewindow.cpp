#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    ptrMainMenu = new MainMenu;
    ui->stackedWidget->insertWidget(1, ptrMainMenu);

    QPixmap pic(":/resources/Pictures/rfid.png");
    ui->pictureLabel->setPixmap(pic.scaled(500,500,Qt::KeepAspectRatio));   //Skaalataan kuva
    setWindowTitle("BankSimul");

    connect(ptrMainMenu, SIGNAL(logoutSignal()),
            this, SLOT(backToHome()));
}

HomeWindow::~HomeWindow()
{
    delete ui;
    ui = nullptr;
    delete ptrMainMenu;
    ptrMainMenu = nullptr;
}

void HomeWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void HomeWindow::backToHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}
