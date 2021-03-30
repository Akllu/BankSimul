#ifndef OTHERWITHDRAWDIALOG_H
#define OTHERWITHDRAWDIALOG_H

#include <QDialog>

namespace Ui {
class otherWithdrawDialog;
}

class otherWithdrawDialog : public QDialog
{
    Q_OBJECT

public:
    explicit otherWithdrawDialog(QWidget *parent = nullptr);
    ~otherWithdrawDialog();
    double returnAmount();

private slots:
    void on_withdrawButton_clicked();

private:
    Ui::otherWithdrawDialog *ui;
    double amount;
};

#endif // OTHERWITHDRAWDIALOG_H
