#include "engine.h"

Engine::Engine(QObject *parent) :
    QObject(parent)
{

}

Engine::~Engine()
{

}


/***************KIRJAUTUMINEN***************/

void Engine::returnLoginResult(QString cardID, QString PINCode)
{
    QJsonObject json_obj;
    json_obj.insert("Tunnus_kortti",cardID);
    json_obj.insert("Pin_koodi", PINCode);
    QString site_url="http://localhost:3000/login/";
    QString credentials="pankki:p1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(loginSlot(QNetworkReply*)));
    loginReply = loginManager->post(request, QJsonDocument(json_obj).toJson());
}

void Engine::loginSlot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    if(response_data.compare("true") == 0)
    {
        emit returnLoginResult("loginsuccesful");
    }
    else if(response_data.compare("-4078") == 0)
    {
        emit returnLoginResult("virhe");
    }
    else if(response_data.compare("locked") == 0)
    {
        emit returnLoginResult("lukossa");
    }
    else
    {
        emit returnLoginResult("accessdenied");
    }

    loginReply->deleteLater();
    reply->deleteLater();
    loginManager->deleteLater();
}


/***************KORTIN LUKITUS***************/

void Engine::lockCard(QString cardID)
{
    QJsonObject json_obj;
    json_obj.insert("Tunnus_kortti", cardID);
    json_obj.insert("Lukkotieto", 1);
    QString site_url="http://localhost:3000/kortti/"+cardID;
    QString credentials="pankki:p1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    cardLockManager = new QNetworkAccessManager(this);
    connect(cardLockManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(cardLockSlot(QNetworkReply*)));
    cardLockReply = cardLockManager->put(request, QJsonDocument(json_obj).toJson());
}

void Engine::cardLockSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    if(response_data.compare("0") == 0)
    {
        qDebug() << "Kortin lukitus epäonnistui";
    }
    else if(response_data.compare("-4078") == 0)
    {
        qDebug() << "Virhe tietokantayhteydessä!";
    }
    else
    {
        qDebug() << "Kortin lukitus onnistui";
    }

    cardLockReply->deleteLater();
    reply->deleteLater();
    cardLockManager->deleteLater();
}


/***************ASIAKKAAN TIEDOT***************/

void Engine::getCustomerData(QString cardID)
{
    QString site_url="http://localhost:3000/saldo/saldo/"+cardID;
    QString credentials="pankki:p1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    customerManager = new QNetworkAccessManager(this);
    connect(customerManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(customerSlot(QNetworkReply*)));
    customerReply = customerManager->get(request);
}

void Engine::customerSlot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    if(response_data.compare("") == 0)
    {
        qDebug() << "Person not found";
    }
    else if(response_data.compare("-4078") == 0)
    {
        qDebug() << "Virhe tietokantayhteydessä";
    }
    else
    {
        QJsonDocument json_doc=QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();
        QString name;
        QString accNum;
        QString balance;
        foreach(const QJsonValue &value,json_array)
        {
            QJsonObject json_obj = value.toObject();
            name += json_obj["nimi"].toString()+"\r\n";
            accNum += json_obj["Tilinumero"].toString()+"\r\n";
            balance = QString::number(json_obj["Tilin_saldo"].toDouble());
        }
        emit returnCustomerData(name,accNum,balance);
    }

    customerReply->deleteLater();
    reply->deleteLater();
    customerManager->deleteLater();
}


/***************TILITAPAHTUMAT***************/

void Engine::getTransactions(QString cardID)
{
    QString site_url="http://localhost:3000/saldo/tapahtumat/"+cardID;
    QString credentials="pankki:p1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    transactionManager = new QNetworkAccessManager(this);
    connect(transactionManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(transactionsSlot(QNetworkReply*)));
    transactionReply = transactionManager->get(request);
}

void Engine::transactionsSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    if(response_data.compare("0") == 0)
    {
        qDebug() << "Haku epäonnistui";
    }
    else if(response_data.compare("-4078") == 0)
    {
        qDebug() << "Virhe tietokantayhteydessä";
    }
    else
    {
    QJsonDocument json_doc=QJsonDocument::fromJson(response_data);
    QJsonArray json_array=json_doc.array();
    QString event;
    QString amount;
    QString date;
    foreach(const QJsonValue &value, json_array)
    {
        QJsonObject json_obj=value.toObject();
        event += json_obj["Tapahtuma_tyyppi"].toString()+"\r\n\n";
        amount += QString::number(json_obj["Rahan_maara"].toDouble())+"€"+"\r\n\n";
        date += json_obj["tapahtuma"].toString()+"\r\n\n";
    }
    qDebug() << date;
    emit returnTransactions(event,amount,date);

    transactionReply->deleteLater();
    reply->deleteLater();
    transactionManager->deleteLater();
    }
}


/***************NOSTA RAHAA***************/

void Engine::withdraw(int cardID, double amount)
{
    QJsonObject json_obj;
    json_obj.insert("id", cardID);
    json_obj.insert("summa", amount);
    QString site_url="http://localhost:3000/saldo/nosto";
    QString credentials="pankki:p1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    withdrawManager = new QNetworkAccessManager(this);
    connect(withdrawManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(withdrawSlot(QNetworkReply*)));
    withdrawReply = withdrawManager->post(request, QJsonDocument(json_obj).toJson());
}

void Engine::withdrawSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug() << response_data;
    if(response_data.compare("0") == 0)
    {
        qDebug() << "nosto epäonnistui";
        emit returnWithdrawResult("false");
    }
    else if(response_data.compare("-4078") == 0)
    {
        qDebug() << "Virhe tietokantayhteydessä";
        emit returnWithdrawResult("error");
    }
    else
    {
        qDebug() << "nosto onnistui";
        emit returnWithdrawResult("true");
    }

    withdrawReply->deleteLater();
    reply->deleteLater();
    withdrawManager->deleteLater();
}


/***************TILISIIRTO***************/

void Engine::transfer(int senderAccNum, int receiverAccNum, double amount)
{
    qDebug() << "Lähettäjän tilinro = " << senderAccNum;
    qDebug() << "Vastaanottajan tilinro = " << receiverAccNum;
    qDebug() << "Siirtosumma = " << amount;
    QJsonObject json_obj;
    json_obj.insert("id", receiverAccNum);
    json_obj.insert("id2", senderAccNum);
    json_obj.insert("summa", amount);
    QString site_url="http://localhost:3000/saldo/siirto";
    QString credentials="pankki:p1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    transferManager = new QNetworkAccessManager(this);
    connect(transferManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(transferSlot(QNetworkReply*)));
    transferReply = transferManager->post(request, QJsonDocument(json_obj).toJson());
}

void Engine::transferSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug() << "Response data = " << response_data;
    if(response_data.compare("0") == 0)
    {
        qDebug() << "siirto epäonnistui";
        emit returnTransferResult("false");
    }
    else if(response_data.compare("-4078") == 0)
    {
        qDebug() << "Virhe tietokantayhteydessä";
        emit returnTransferResult("error");
    }
    else
    {
        qDebug() << "siirto onnistui";
        emit returnTransferResult("true");
    }

    transferReply->deleteLater();
    reply->deleteLater();
    transferManager->deleteLater();
}
