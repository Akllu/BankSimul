#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI()
{
    ptrEngine = new Engine;

    connect(ptrEngine, SIGNAL(returnLoginResult(QString)),  //Yhdistetään enginen signaalit slotteihin
            this, SLOT(sendLoginResult(QString)));

    connect(ptrEngine, SIGNAL(returnCustomerData(QString,QString,QString)),
            this, SLOT(sendCustomerDataResult(QString,QString,QString)));

    connect(ptrEngine, SIGNAL(returnTransactions(QString,QString,QString)),
            this, SLOT(sendTransactionResult(QString,QString,QString)));

    connect(ptrEngine, SIGNAL(returnWithdrawResult(QString)),
            this, SLOT(sendWithdrawResult(QString)));

    connect(ptrEngine, SIGNAL(returnTransferResult(QString)),
            this, SLOT(sendTransferResult(QString)));
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

void DLLRestAPI::lockCard(QString cardID)
{
    ptrEngine->lockCard(cardID);
}

void DLLRestAPI::getCustomerData(QString cardID)
{
    ptrEngine->getCustomerData(cardID);
}

void DLLRestAPI::getTransactions(QString cardID, QString startingPoint)
{
    ptrEngine->getTransactions(cardID,startingPoint);
}

void DLLRestAPI::withdraw(int cardID, double amount)
{
    ptrEngine->withdraw(cardID, amount);
}

void DLLRestAPI::transfer(int senderAccNum, int receiverAccNum, double amount)
{
    ptrEngine->transfer(senderAccNum, receiverAccNum, amount);
}


/***************Signaalit EXE:lle***************/

void DLLRestAPI::sendLoginResult(QString result)
{
    emit loginResultToEXE(result);
}

void DLLRestAPI::sendCustomerDataResult(QString name, QString accNum, QString balance)
{
    emit customerDataToEXE(name,accNum,balance);
}

void DLLRestAPI::sendTransactionResult(QString event, QString amount, QString date)
{
    emit transactionsToEXE(event,amount,date);
}

void DLLRestAPI::sendWithdrawResult(QString result)
{
    emit withdrawResultToEXE(result);
}

void DLLRestAPI::sendTransferResult(QString result)
{
    emit transferResultToEXE(result);
}
