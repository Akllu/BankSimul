#include "pininterface.h"

PinInterface::PinInterface(QObject *parent) :
    QObject(parent) {
    qDebug() << "Luodaan DLL:n PinInterface.";
    pPinEngine = new PinEngine;
    connect(pPinEngine, SIGNAL(timedOut()),
            this, SLOT(timeoutSignalToEXE()));

    connect(pPinEngine, SIGNAL(pinInserted()),
            this, SLOT(insertSignalToEXE()));

}

PinInterface::~PinInterface() {
    qDebug() << "Tuhotaan DLL:n PinInterface.";
    delete pPinEngine;
    pPinEngine = nullptr;
}

QString PinInterface::returnPinCode() {
//  palautetaan pinkoodi EXE:lle
    return pPinEngine->returnPinCode();
}

void PinInterface::generatePinDialog() {
//  luodaan dialogi
    pPinEngine->generateDialog();
}

void PinInterface::timeoutSignalToEXE() {
//  välitetään signaali EXE:lle
    emit timeoutSignal();

}
void PinInterface::insertSignalToEXE() {
//  välitetään signaali EXE:lle
    emit PINInserted();
}
