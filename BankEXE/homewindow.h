/*
Aleksi Kalliokoski TVT20SPL
*/

#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>

#include "mainmenu.h"
//#include "serialportdll.h"
//#include "pininterface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HomeWindow; }
QT_END_NAMESPACE

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();
    //void getValueFromRFID();

public slots:
    void backToHome();
    //void dataFromRFID(QString);

signals:
    //void readRFID();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HomeWindow *ui;
    MainMenu *ptrMainMenu;
    //SerialPortDLL *ptrSerialPort;
    //PinInterface *ptrPIN;

    //QString CardValueRFID;
};

#endif // HOMEWINDOW_H
