const db = require('../database');

const asiakas = {
  getById: function(id, callback) {
    return db.query('select * from asiakas where id_Asiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (tunnus, nimi, osoite, puhelinnumero, kortin_tunnus) values(?,?,?,?,?)',
      [asiakas.tunnus, asiakas.nimi, asiakas.osoite, asiakas.puhelinnumero, asiakas.kortin_tunnus],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where id_Asiakas=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set tunnus=?, nimi=?, osoite=?, puhelinnumero=?, kortin_tunnus=? where id_Asiakas=?',
      [ asiakas.tunnus, asiakas.nimi, asiakas.osoite, asiakas.puhelinnumero, asiakas.kortin_tunnus, id_Asiakas],
      callback
    );
  }
};
module.exports = asiakas;