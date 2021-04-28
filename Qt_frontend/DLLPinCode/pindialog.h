#ifndef PINDIALOG_H
#define PINDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QTimer>
#include <QIntValidator>

namespace Ui {
class PinDialog;
}

class PinDialog : public QDialog {
    Q_OBJECT

  public:
    explicit PinDialog(QWidget *parent = nullptr);
    ~PinDialog();
    QString returnPinCode();
    void buttonCharInserter(QString i);
    void createTimer();
    void timerReset();

  signals:
    void timedOut();
    void pinInserted();

  private slots:
    void on_okButton_clicked();
    void on_clearButton_clicked();
    void on_numButton_8_clicked();
    void on_numButton_0_clicked();
    void on_numButton_1_clicked();
    void on_numButton_2_clicked();
    void on_numButton_3_clicked();
    void on_numButton_4_clicked();
    void on_numButton_5_clicked();
    void on_numButton_6_clicked();
    void on_numButton_7_clicked();
    void on_numButton_9_clicked();
    void timerRanOut();


  private:
    Ui::PinDialog *ui;
    QTimer *diaTimer;
    QString pinInput;
    QString pinCode;
};

#endif // PINDIALOG_H
