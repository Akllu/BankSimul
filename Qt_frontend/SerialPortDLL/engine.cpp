#include "engine.h"

/*main ohjelmaan
connect(olio ohjelmalta,SIGNAL(sendtoEXEStatus(QString)),
            this,SLOT(tallenna_slottiin(QString)));

*/

engine::engine(QObject *parent) : QObject(parent) //Enginen constructori
{
    qDebug() << "Ollaan enginen constructorissa";
    Serialport = new QSerialPort;
    SerialportInfo = new QSerialPortInfo;

    info(); //Kutsuu infoa selvittääkseen sarjaportin osoitteen
    connect(Serialport,SIGNAL(readyRead()),
            this,SLOT(readDataFromPort()));


}

engine::~engine() //Enginen destructori
{
    qDebug() << "Ollaan enginen destructorissa";
    delete Serialport;
    delete SerialportInfo;
    Serialport = nullptr;
    SerialportInfo = nullptr;
}

void engine::open() //Avaa sarjaportti liikenteen saadulla portilla
{
    qDebug() << "Sarjaliikenteen avausfunktiossa";
    qDebug() << deviceaddress;
    Serialport->setPortName(deviceaddress);
    Serialport->setBaudRate(9600);
    Serialport->setDataBits(QSerialPort::Data8);
    Serialport->setParity(QSerialPort::NoParity);
    Serialport->setStopBits(QSerialPort::OneStop);
    Serialport->setFlowControl(QSerialPort::HardwareControl);

    if(!Serialport->open(QIODevice::ReadWrite)) {
        qDebug() << "Serialportti ei auennut";
        if(changeError == 0){
            qDebug() << "Sarjaportti viesti ERROR";
            //emit SignalFromEngine("ERROR with reader");
        }else if(changeError == 1){
            qDebug() << "Sarjaportti viesti already use";
            //emit SignalFromEngine("Reader is already use");
        }
    }else{
        if(changeError == 0){
            changeError++;
        }
        qDebug() << "Serialportti aukesi";
    }
    Serialport->clear(); //Tyhjennetään sarjaportti ettei tule mitään ylimääräistä

}

void engine::info() //Lukee avoimet portit ja lähettää ne receive infoon määriteltäväksi oikea portti.
{
    QList<QSerialPortInfo> ports = SerialportInfo->availablePorts();
    foreach(QSerialPortInfo info, ports){
        receiveInfo(info.manufacturer());
        receiveInfo(info.portName());
    }
    qDebug() << "info ajettu";
}

void engine::close() //Sarjaportin sulkeva käsky.
{
    Serialport->close();
    if(changeError==0){
        //emit SignalFromEngine("Reader is already closed");
    }else{
        //emit SignalFromEngine("");
    }
    changeError=0;
    qDebug() << "Suljetaan sarjaportti";

}

void engine::receiveInfo(QString arvot) //Määrittelee microsoft sarjaportissa olevan RFID MOD-RFID125-BOX lukijan.
{
    if(driver =="Microsoft"){
        deviceaddress = arvot;
        driver=" ";
    }
    if(arvot=="Microsoft"){
        driver = arvot;
    }
    qDebug() << "Infoa engineltä";
}


void engine::readDataFromPort() //Lukee tiedon ja välittää sen dllSerialPortille.
{
    qDebug() << "readDatafromPort aloitettu";
    data = Serialport->readAll();
    data.remove(0, 2);
    data.remove(11, 14);
    qDebug() << "Ollaan readDataFromPortissa";
    emit SignalFromEngine(data);
}












