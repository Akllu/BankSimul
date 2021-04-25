const db = require('../database');

const login={
  checkPinkoodi: function(Tunnus_kortti, callback) {
      return db.query('SELECT Pin_koodi FROM kortti WHERE Tunnus_Kortti = ?',[Tunnus_kortti], callback); 
    }
};
          
module.exports = login;