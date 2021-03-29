#ifndef PINDIALOG_H
#define PINDIALOG_H

#include <QDialog>
#include "maindialog.h"

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
    MainDialog *ptrMainDialog;
    short number;
};

#endif // PINDIALOG_H
