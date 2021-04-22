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
    else
    {
        emit returnLoginResult("accessdenied");
    }

    loginReply->deleteLater();
    reply->deleteLater();
    loginManager->deleteLater();
}


/***************NIMI PÄÄVALIKKOON***************/

void Engine::getName(QString cardID)
{
    QString site_url="http://localhost:3000/saldo/nimi/"+cardID;
    QString credentials="pankki:p1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    nameManager = new QNetworkAccessManager(this);
    connect(nameManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(nameSlot(QNetworkReply*)));
    nameReply = nameManager->get(request);
}

void Engine::nameSlot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    if(response_data.compare("")==0)
    {
        qDebug() << "henkilöä ei löydy";
    }
    else
    {
        QJsonDocument json_doc=QJsonDocument::fromJson(response_data);
        QJsonObject json_obj=json_doc.object();
        QString nimi=json_obj["nimi"].toString();

        qDebug() << response_data;
        qDebug() << nimi;
        emit returnNameResult(response_data);
    }

    nameReply->deleteLater();
    reply->deleteLater();
    nameManager->deleteLater();
}


/***************NOSTA RAHAA***************/

void Engine::withdraw(QString cardID, double amount)
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
    }
    else
    {
        qDebug() << "nosto onnistui";
    }

    withdrawReply->deleteLater();
    reply->deleteLater();
    withdrawManager->deleteLater();
}


/***************NÄYTÄ SALDO***************/

void Engine::balance(QString ID)
{
    QString site_url="http://localhost:3000/saldo/tapahtumat/"+ID;
    QString credentials="pankki:p1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    balanceManager = new QNetworkAccessManager(this);
    connect(balanceManager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(balanceSlot(QNetworkReply*)));
    balanceReply = balanceManager->get(request);
}

void Engine::balanceSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug() << response_data;
    QJsonDocument json_doc=QJsonDocument::fromJson(response_data);
    QJsonArray json_array=json_doc.array();
    QString saldo;
    foreach(const QJsonValue &value, json_array)
    {
    QJsonObject json_obj=value.toObject();
    saldo+=QString::number((json_obj["id_Asiakas"].toInt()))+" "+json_obj["nimi"].toString()+" "+json_obj["osoite"].toString()+" "
                           +QString::number(json_obj["Tilin_saldo"].toDouble())+" "+json_obj["tapahtuma"].toString()+ "\r\n";
    }
    qDebug() << saldo;

    balanceReply->deleteLater();
    reply->deleteLater();
    balanceManager->deleteLater();
}


/***************TILISIIRTO***************/

void Engine::transfer(QString senderID, QString receiverID, double amount)
{
    QJsonObject json_obj;
    json_obj.insert("id", senderID);
    json_obj.insert("id2", receiverID);
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
    qDebug() << response_data;
    if(response_data.compare("0") == 0)
    {
        qDebug() << "siirto epäonnistui";
    }
    else
    {
        qDebug() << "siirto onnistui";
    }

    transferReply->deleteLater();
    reply->deleteLater();
    transferManager->deleteLater();
}
