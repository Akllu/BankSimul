#ifndef TRANSACTIONSDIALOG_H
#define TRANSACTIONSDIALOG_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class transactionsDialog;
}

class transactionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit transactionsDialog(QWidget *parent = nullptr);
    ~transactionsDialog();

public slots:
    void resetTimer();

signals:
    void closeSignal();

private slots:
    void on_nextButton_clicked();
    void on_previousButton_clicked();
    void on_closeButton_clicked();

private:
    Ui::transactionsDialog *ui;
    QTimer *dialogTimer;
};

#endif // TRANSACTIONSDIALOG_H
