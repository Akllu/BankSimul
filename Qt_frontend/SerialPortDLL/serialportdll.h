#ifndef SERIALPORTDLL_H
#define SERIALPORTDLL_H

#include "SerialPortDLL_global.h"
#include "engine.h"


class SERIALPORTDLL_EXPORT SerialPortDLL: public QObject
{
    Q_OBJECT
public:
    SerialPortDLL(QObject *parent = nullptr);
    ~SerialPortDLL();
    void openSerialPort(void);
    void closeSerialdata(void);
private:
    engine *pEngine; 


signals:
    void sendtoEXEStatus(QString);
public slots:
    void receiveData(QString);

};

#endif // SERIALPORTDLL_H
