#ifndef TRANSFERDIALOG_H
#define TRANSFERDIALOG_H

#include <QDialog>

namespace Ui {
class transferDialog;
}

class transferDialog : public QDialog
{
    Q_OBJECT

public:
    explicit transferDialog(QWidget *parent = nullptr);
    ~transferDialog();

private slots:
    void on_nextButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::transferDialog *ui;
};

#endif // TRANSFERDIALOG_H
