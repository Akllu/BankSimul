#include "pinengine.h"

PinEngine::PinEngine(QObject *parent): QObject(parent) {
    qDebug() << "Luodaan DLL:n PinEngine.";
    ptrDialog = new PinDialog;
    connect(ptrDialog, SIGNAL(timedOut()),
            this, SLOT(timerTimedOut()));
    connect(ptrDialog, SIGNAL(pinInserted()),
            this, SLOT(sendInsertToInterface()));

}

PinEngine::~PinEngine() {
    qDebug() << "Tuhotaan DLL:n PinEngine.";
    delete ptrDialog;
    ptrDialog = nullptr;
}

QString PinEngine::returnPinCode() {
//  talletetaan vastaanotettu pinkoodi ja toimitetaan se eteenpäin
    pinCode = ptrDialog->returnPinCode();
    return pinCode;
}

void PinEngine::generateDialog() {
//  luodaan dialogi ja suoritetaan se
    ptrDialog->setWindowTitle("Enter PIN code");
    ptrDialog->show();
    ptrDialog->timerReset(); //käynnistetään dialogin ajastin
}

void PinEngine::timerTimedOut() {
//  välitetään signaali eteenpäin
    emit timedOut();
}
void PinEngine::sendInsertToInterface() {
//  välitetään signaali eteenpäin
    emit pinInserted();
}
