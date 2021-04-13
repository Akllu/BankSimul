/*
Aleksi Kalliokoski TVT20SPL
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "pindialog.h"
#include "maindialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showMainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    PINDialog *ptrPINDialog;
    MainDialog *ptrMainDialog;
};

#endif // MAINWINDOW_H
