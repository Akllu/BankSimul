const { request } = require('express');
const database = require('../database');
global.paivays=0;
const saldo= {
    getSaldo: function(id,callback){
        return database.query('select Asiakas.id_Asiakas, nimi, osoite, puhelinnumero, Tilinumero, Tilin_saldo from Asiakas join Asiakas_tili on Asiakas.id_Asiakas=Asiakas_tili.id_Asiakas join Tili on Asiakas_tili.id_tili=Tili.id_tili where kortin_tunnus=?',[id], callback);

    },
    getTilitiedot: function(id, callback){
        return database.query('select nimi, osoite, puhelinnumero, Tilinumero, Tilin_saldo from Asiakas join Asiakas_tili on Asiakas.id_Asiakas=Asiakas_tili.id_Asiakas join Tili on Asiakas_tili.id_tili=Tili.id_tili where tunnus=?',[id], callback);
    },
    getKortintiedot: function(id, callback){
        return database.query('select id_kortti, Pin_koodi from kortti where id_kortti=?',[id], callback);
    },
    getTapahtumat: function(cardID, startingPoint, callback){
        const startingPointToInt = parseInt(startingPoint);
        return database.query('select Tapahtuma_tyyppi, Rahan_maara, @paivays:=Paivays as tapahtuma from Asiakas join Asiakas_tili on Asiakas.id_Asiakas=Asiakas_tili.id_Asiakas join Tili on Asiakas_tili.id_tili=Tili.id_tili join tapahtuma on Tili.id_tili=tapahtuma.id_tili where kortin_tunnus=? order by Paivays desc limit ?,10',[cardID,startingPointToInt], callback);
    },
    getNimi: function(id, callback){
        return database.query('select nimi from asiakas where kortin_tunnus=?',[id],callback);
    },
    nosto: function(procedure_params, callback) {
        return database.query(
          'CALL nosto (?,-?)',
          [procedure_params.id, procedure_params.summa],
          callback
        );
      },
    siirto: function(procedure_params, callback){
        return database.query(
            'CALL siirto (?, ?,?)',
            [procedure_params.id,procedure_params.id2,procedure_params.summa],
            callback
        );
    }
    

};
module.exports = saldo;