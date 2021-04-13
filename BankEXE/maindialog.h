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

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

signals:
    void logoutSignal();

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

    int status;
};

#endif // MAINDIALOG_H
