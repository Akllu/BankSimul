#ifndef BALANCEDIALOG_H
#define BALANCEDIALOG_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class balanceDialog;
}

class balanceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit balanceDialog(QWidget *parent = nullptr);
    ~balanceDialog();

public slots:
    void resetTimer();

signals:
    void closeSignal();

private slots:
    void on_closeButton_clicked();

private:
    Ui::balanceDialog *ui;
    QTimer *dialogTimer;
};

#endif // BALANCEDIALOG_H
