#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI()
{
    ptrEngine = new Engine;

    connect(ptrEngine, SIGNAL(returnLoginResult(QString)),
            this, SLOT(sendLoginResultToEXE(QString)));

    connect(ptrEngine, SIGNAL(returnNameResult(QString)),
            this, SLOT(sendNameResultToEXE(QString)));

    connect(ptrEngine, SIGNAL(returnWithdrawResult(QString)),
            this, SLOT(sendWithdrawResultToEXE(QString)));

    connect(ptrEngine, SIGNAL(returnBalanceResult(QString)),
            this, SLOT(sendBalanceResultToEXE(QString)));

    connect(ptrEngine, SIGNAL(returnTransferResult(QString)),
            this, SLOT(sendTransferResultToEXE(QString)));
}

DLLRestAPI::~DLLRestAPI()
{
    delete ptrEngine;
    ptrEngine = nullptr;
}

void DLLRestAPI::login(QString cardID, QString PINCode)
{
    ptrEngine->returnLoginResult(cardID, PINCode);
}

void DLLRestAPI::name(QString cardID)
{
    ptrEngine->getName(cardID);
}

void DLLRestAPI::withdraw(QString cardID, double amount)
{
    ptrEngine->withdraw(cardID, amount);
}

void DLLRestAPI::balance(QString ID)
{
    ptrEngine->balance(ID);
}

void DLLRestAPI::transfer(QString senderID, QString receiverID, double amount)
{
    ptrEngine->transfer(senderID, receiverID, amount);
}

void DLLRestAPI::sendLoginResultToEXE(QString result)
{
    emit loginResultToEXE(result);
}

void DLLRestAPI::sendNameResultToEXE(QString result)
{
    emit nameResultToEXE(result);
}

void DLLRestAPI::sendWithdrawResultToEXE(QString result)
{
    emit withdrawResultToEXE(result);
}

void DLLRestAPI::sendBalanceResultToEXE(QString result)
{
    emit balanceResultToEXE(result);
}

void DLLRestAPI::sendTransferResultToEXE(QString result)
{
    emit transferResultToEXE(result);
}
