#ifndef TRANSACTIONSDIALOG_H
#define TRANSACTIONSDIALOG_H

#include <QDialog>

namespace Ui {
class transactionsDialog;
}

class transactionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit transactionsDialog(QWidget *parent = nullptr);
    ~transactionsDialog();

private slots:
    void on_nextButton_clicked();

    void on_previousButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::transactionsDialog *ui;
};

#endif // TRANSACTIONSDIALOG_H
