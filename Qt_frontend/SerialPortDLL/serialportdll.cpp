#include "serialportdll.h"

SerialPortDLL::SerialPortDLL(QObject *parent) : QObject(parent) //dllSerialportin constructori
{
    pEngine = new engine(this);

    connect(pEngine,SIGNAL(SignalFromEngine(QString)),
            this,SLOT(receiveData(QString)));

}

SerialPortDLL::~SerialPortDLL() //dllSerialPortin destructori
{
    delete pEngine;
    pEngine = nullptr;


}

void SerialPortDLL::openSerialPort() //Avaa sarjaportin ja lukee komennon
{
    qDebug() << "Avataan sarjaportti";
    pEngine->open();

}

void SerialPortDLL::closeSerialdata() //Lähettää enginen puolelle sarjaportin sulkevan komennon
{
    qDebug() << "Ajetaan sulku komento";
    pEngine->close();
}



void SerialPortDLL::receiveData(QString arvo) //Saa engineltä saadun tiedon ja lähettää sen EXE:lle
{
    qDebug() << "receiveFromSignal aloitettu";
    qDebug() << "Näyttö suljettu";

    emit sendtoEXEStatus(arvo);
}






