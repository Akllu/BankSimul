#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class Engine : public QObject
{
    Q_OBJECT
public:
    Engine(QObject *parent = nullptr);
    ~Engine();
    void returnLoginResult(QString cardID, QString PINCode);
    void getName(QString cardID);
    void withdraw(QString cardID, double amount);
    void balance(QString ID);
    void transfer(QString senderID, QString receiverID, double amount);

signals:
    void returnLoginResult(QString);
    void returnNameResult(QString);
    void returnWithdrawResult(QString);
    void returnBalanceResult(QString);
    void returnTransferResult(QString);

private slots:
    void loginSlot(QNetworkReply *reply);
    void nameSlot(QNetworkReply *reply);
    void withdrawSlot(QNetworkReply *reply);
    void balanceSlot(QNetworkReply *reply);
    void transferSlot(QNetworkReply *reply);

private:
    QNetworkAccessManager *loginManager;
    QNetworkReply *loginReply;
    QNetworkAccessManager *nameManager;
    QNetworkReply *nameReply;
    QNetworkAccessManager *withdrawManager;
    QNetworkReply *withdrawReply;
    QNetworkAccessManager *balanceManager;
    QNetworkReply *balanceReply;
    QNetworkAccessManager *transferManager;
    QNetworkReply *transferReply;
};

#endif // ENGINE_H
