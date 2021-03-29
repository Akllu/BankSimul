#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include "withdrawdialog.h"

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

public slots:
    void receiveSignal();

private slots:
    void on_withdrawButton_clicked();
    void on_balanceButton_clicked();
    void on_transactionButton_clicked();
    void on_transferButton_clicked();
    void on_logoutButton_clicked();

private:
    Ui::MainDialog *ui;
    WithdrawDialog *ptrWithdraw;


};

#endif // MAINDIALOG_H
