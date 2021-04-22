#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "DLLRestAPI_global.h"
#include "engine.h"


class DLLRESTAPI_EXPORT DLLRestAPI : public QObject
{
    Q_OBJECT
public:
    DLLRestAPI();
    ~DLLRestAPI();
    void login(QString cardID, QString PINCode);    //Kirjautuminen
    void name(QString cardID);                      //Nimen hakeminen päävalikkoon
    void withdraw(QString cardID, double amount);   //Nosta rahaa
    void balance(QString ID);                       //Näytä saldo

    void transfer(QString senderID, QString receiverID, double amount); //Tilisiirto

signals:
    void loginResultToEXE(QString);
    void nameResultToEXE(QString);
    void withdrawResultToEXE(QString);
    void balanceResultToEXE(QString);
    void transferResultToEXE(QString);

private:
    Engine *ptrEngine;

private slots:
    void sendLoginResultToEXE(QString result);
    void sendNameResultToEXE(QString result);
    void sendWithdrawResultToEXE(QString result);
    void sendBalanceResultToEXE(QString result);
    void sendTransferResultToEXE(QString result);
};

#endif // DLLRESTAPI_H
