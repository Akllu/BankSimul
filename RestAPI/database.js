const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'asiakas',
  password: 'test',
  database: 'testi'
});
module.exports = connection;