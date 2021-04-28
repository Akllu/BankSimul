#ifndef ENGINE_H
#define ENGINE_H

#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class engine : public QObject
{
    Q_OBJECT
public:
    explicit engine(QObject *parent = nullptr);
    ~engine();
    void open();
    void info(void);
    void close(void);

signals:
    void SignalFromEngine(QString);

private:
    void receiveInfo(QString);
    QString deviceaddress;
    QString driver=" ";
    int changeError = 0;
    QString data;
    QSerialPort *Serialport;
    QSerialPortInfo *SerialportInfo;


public slots:
    void readDataFromPort();

};

#endif // ENGINE_H
