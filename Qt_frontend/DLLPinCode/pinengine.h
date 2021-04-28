#ifndef PINENGINE_H
#define PINENGINE_H

#include "pindialog.h"
#include <QDebug>
#include <QObject>

class PinEngine : public QObject {

    Q_OBJECT
  public:
    PinEngine(QObject *parent = nullptr);
    ~PinEngine();
    QString returnPinCode();
    void generateDialog();

  signals:
    void timedOut();
    void pinInserted();

  private slots:
    void timerTimedOut();
    void sendInsertToInterface();

  private:
    PinDialog *ptrDialog;
    QString pinCode;


};

#endif // PINENGINE_H
