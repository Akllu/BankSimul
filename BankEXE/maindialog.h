#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

#include "withdrawdialog.h"
#include "balancedialog.h"
#include "transactionsdialog.h"
#include "transferdialog.h"

//class MainWindow;

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);//, MainWindow *ptr = nullptr);
    ~MainDialog();

signals:
    void sendSignal();

private slots:
    void on_withdrawButton_clicked();
    void on_balanceButton_clicked();
    void on_transactionButton_clicked();
    void on_transferButton_clicked();
    void on_logoutButton_clicked();

private:
    Ui::MainDialog *ui;
    WithdrawDialog *ptrWithdraw;
    balanceDialog *ptrBalance;
    transactionsDialog *ptrTransactions;
    transferDialog *ptrTransfer;
    //MainWindow *ptrMainWindow

    int status;
};

#endif // MAINDIALOG_H
