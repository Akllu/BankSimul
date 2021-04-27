const db = require('../database');

const tapahtuma = {
  getById: function(id, callback) {
    return db.query('select * from tapahtuma where id_tapahtuma=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tapahtuma', callback);
  },
  add: function(tapahtuma, callback) {
    return db.query(
      'insert into tapahtuma (rahan_maara, tapahtuma_tyyppi,paivays, id_Tili) values(?,?,?,?)',
      [tapahtuma.rahan_maara, tapahtuma.tapahtuma_tyyppi, tapahtuma.paivays,tapahtuma.id_Tili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tapahtuma where id_tapahtuma=?', [id], callback);
  },
  update: function(id, tapahtuma, callback) {
    return db.query(
      'update tapahtuma set rahan_maara=?, tapahtuma_tyyppi=? paivays=? where id_tapahtuma=?',
      [tapahtuma.rahan_maara, tapahtuma.tapahtuma_tyyppi,tapahtuma.paivays, id_Tapahtuma],
      callback
    );
  }
};
module.exports = tapahtuma;