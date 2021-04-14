#ifndef WITHDRAWDIALOG_H
#define WITHDRAWDIALOG_H

#include <QDialog>
#include <QTimer>

#include "otherwithdrawdialog.h"

namespace Ui {
class WithdrawDialog;
}

class WithdrawDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WithdrawDialog(QWidget *parent = nullptr);
    ~WithdrawDialog();

public slots:
    void resetTimer();

signals:
    void closeSignal();

private slots:
    void on_button20_clicked();
    void on_button40_clicked();
    void on_button60_clicked();
    void on_button100_clicked();
    void on_button200_clicked();
    void on_button500_clicked();
    void on_buttonOther_clicked();
    void on_buttonClose_clicked();

private:
    Ui::WithdrawDialog *ui;
    otherWithdrawDialog *ptrOtherWithdraw;
    double otherAmount;
    QTimer *dialogTimer;
};

#endif // WITHDRAWDIALOG_H
