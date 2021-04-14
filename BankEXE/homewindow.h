/*
Aleksi Kalliokoski TVT20SPL
*/

#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>

#include "mainmenu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HomeWindow; }
QT_END_NAMESPACE

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

private slots:
    void on_pushButton_clicked();
    void backToHome();

private:
    Ui::HomeWindow *ui;
    MainMenu *ptrMainMenu;
};

#endif // HOMEWINDOW_H
