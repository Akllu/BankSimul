const express = require('express');
const router = express.Router();
const saldo = require('../models/saldo_model');

router.get('/saldo/:id',
    function(request, response){
    saldo.getSaldo(request.params.id,function(err,dbResult){
        if(err){
            response.json(err.errno);
        }
        else{
            console.log(dbResult);
            response.json(dbResult);
        }
    })
}
);
router.get('/nimi/:id',
    function(request, response){
    saldo.getNimi(request.params.id,function(err,dbResult){
        if(err){
            response.json(err.errno);
        }
        else{
            console.log(dbResult);
            response.send(dbResult);
        }
    })
}
);
router.get('/tapahtumat/:cardID/:startingPoint',
    function(request, response){
    saldo.getTapahtumat(request.params.cardID,request.params.startingPoint, function(err,dbResult){
        if(err){
            response.json(err.errno);
        }
        else{
            console.log(dbResult);
            response.json(dbResult);
        }
    })
});
router.get('/kortintiedot/:id',
    function(request,response){
        saldo.getKortintiedot(request.params.id,function(err,dbResult){
            if(err){
                response.json(err.errno);
            }
            else{
                console.log(dbResult);
                response.json(dbResult[0]);
            }
        })
    
    
});
router.post('/nosto', 
function(request, response) {
  saldo.nosto(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult.affectedRows);
    }
})
  });
  router.post('/siirto', 
function(request, response) {
  saldo.siirto(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult.affectedRows);
    }
})
  });
router.get('/tilitiedot/:id',
    function(request, response){
    saldo.getTilitiedot(request.params.id,function(err,dbResult){
        if(err){
            response.json(err.errno);
        }
        else{
            console.log(dbResult);
            response.json(dbResult[0]);
        }
    }) 
        
 
});
module.exports = router;