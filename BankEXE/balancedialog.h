#ifndef BALANCEDIALOG_H
#define BALANCEDIALOG_H

#include <QDialog>

namespace Ui {
class balanceDialog;
}

class balanceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit balanceDialog(QWidget *parent = nullptr);
    ~balanceDialog();

signals:
    void closeSignal();

private slots:
    void on_closeButton_clicked();

private:
    Ui::balanceDialog *ui;
};

#endif // BALANCEDIALOG_H
