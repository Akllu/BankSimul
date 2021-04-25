var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');


var asiakasRouter = require('./routes/asiakas');
var korttiRouter = require('./routes/kortti');
var tiliRouter = require('./routes/tili');
var tapahtumaRouter = require('./routes/tapahtuma');
var saldoRouter = require('./routes/saldo')
var asiakas_tiliRouter = require('./routes/asiakas_tili');
var loginRouter = require('./routes/login');
var app = express();
const basicAuth = require('express-basic-auth');
app.use(basicAuth({users: { 'pankki': 'p1234' }}))

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));



app.use('/asiakas', asiakasRouter);
app.use('/kortti', korttiRouter);
app.use('/tili', tiliRouter);
app.use('/tapahtuma', tapahtumaRouter);
app.use('/saldo', saldoRouter);
app.use('/asiakas_tili', asiakas_tiliRouter);
app.use('/login', loginRouter);
module.exports = app;
