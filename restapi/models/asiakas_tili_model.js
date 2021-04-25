const db = require('../database');

const asiakas_tili = {
  getById: function(id, callback) {
    return db.query('select * from asiakas_tili where id_Asiakas=?',[id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas_tili', callback);
  },
  add: function(asiakas_tili, callback) {
    return db.query(
      'insert into asiakas_tili (id_Asiakas, id_Tili) values(?,?)',
      [asiakas_tili.id_Asiakas, asiakas_tili.id_Tili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas_tili where id_Asiakas=?', [id], callback);
  },
  update: function(id, asiakas_tili, callback) {
    return db.query(
      'update asiakas_tili set id_Tili=? where id_Asiakas=?',
      [asiakas_tili.id_Tili, id_Asiakas],
      callback
    );
  }
};
module.exports = asiakas_tili;