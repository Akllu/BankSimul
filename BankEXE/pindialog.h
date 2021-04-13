#ifndef PINDIALOG_H
#define PINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QIntValidator>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>

namespace Ui {
class PINDialog;
}

class PINDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PINDialog(QWidget *parent = nullptr);
    ~PINDialog();

private slots:
    void on_sendButton_clicked();

private:
    Ui::PINDialog *ui;
    short number;
    short attempts;
};

#endif // PINDIALOG_H
