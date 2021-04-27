const db = require('../database');

const tili = {
  getById: function(id, callback) {
    return db.query('select * from tili where id_Tili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  add: function(tili, callback) {
    return db.query(
      'insert into tili (Tilinumero, Tilin_saldo) values(?,?)',
      [tili.Tilinumero, tili.Tilin_saldo],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili where id_Tili=?', [id], callback);
  },
  update: function(id, tili, callback) {
    return db.query(
      'update tili set Tilinumero=?, Tilin_saldo=? where id_Tili=?',
      [tili.Tilinumero, tili.Tilin_saldo, id_Tili],
      callback
    );
  }
};
module.exports = tili;