const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where id_kortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
    bcrypt.hash(kortti.Pin_koodi, saltRounds, function(err, hash){
    return db.query(
      'insert into kortti (Pin_koodi, kortinnumero, id_Tili) values(?,?,?)',
      [hash ,kortti.kortinnumero, kortti.id_Tili],
      callback)
    });
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where id_kortti=?', [id], callback);
  },
  update: function(id, callback) {
    return db.query('UPDATE kortti SET lukittu = 1 WHERE Tunnus_kortti=?',
      [id],
      callback)
    },
};
module.exports = kortti;