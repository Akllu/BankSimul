#ifndef PININTERFACE_H
#define PININTERFACE_H

#include "DLLPinCode_global.h"
#include "pinengine.h"
#include <QDebug>


class DLLPINCODE_EXPORT PinInterface : public QObject {

    Q_OBJECT
  public:
    PinInterface(QObject *parent = nullptr);
    ~PinInterface();
    QString returnPinCode();
    void generatePinDialog();
  signals:
    void timeoutSignal();
    void PINInserted();
  private slots:
    void timeoutSignalToEXE();
    void insertSignalToEXE();
  private:
    PinEngine  *pPinEngine;

};

#endif // PININTERFACE_H
