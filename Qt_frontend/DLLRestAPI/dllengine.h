#ifndef DLLENGINE_H
#define DLLENGINE_H

#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class dllengine : public QObject
{
    Q_OBJECT
public:
    dllengine(QObject *parent = nullptr);
    ~dllengine();
    void getLoginResult(QString cardID, QString PINCode);
    void lockCard(QString cardID);
    void getCustomerData(QString cardID);
    void getTransactions(QString cardID, QString startingPoint);
    void withdraw(int cardID, double amount);
    void transfer(int customerID, int receiverAccNum, double amount);

signals:
    void returnLoginResult(QString);
    void returnCustomerData(QString,QString,QString,QString);
    void returnTransactions(QString,QString,QString);
    void returnWithdrawResult(QString);
    void returnTransferResult(QString);

private slots:
    void loginSlot(QNetworkReply *reply);
    void cardLockSlot(QNetworkReply *reply);
    void customerSlot(QNetworkReply *reply);
    void transactionsSlot(QNetworkReply *reply);
    void withdrawSlot(QNetworkReply *reply);
    void transferSlot(QNetworkReply *reply);

private:
    QNetworkAccessManager *loginManager;
    QNetworkReply *loginReply;
    QNetworkAccessManager *cardLockManager;
    QNetworkReply *cardLockReply;
    QNetworkAccessManager *customerManager;
    QNetworkReply *customerReply;
    QNetworkAccessManager *transactionManager;
    QNetworkReply *transactionReply;
    QNetworkAccessManager *withdrawManager;
    QNetworkReply *withdrawReply;
    QNetworkAccessManager *transferManager;
    QNetworkReply *transferReply;
};
#endif // DLLENGINE_H
