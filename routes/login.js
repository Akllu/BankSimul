const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');

router.post('/', 
  function(request, response) {
    if(request.body.Tunnus_kortti && request.body.Pin_koodi){
      const id_kortti = request.body.Tunnus_kortti;
      const Pin_koodi = request.body.Pin_koodi;
        login.checkPinkoodi(id_kortti, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(Pin_koodi,dbResult[0].Pin_koodi, function(err,compareResult) {
                if(compareResult) {
                  if(dbResult[0].lukittu == 1)
                  {
                    console.log("locked");
                    response.send("locked");
                  }
                  else{
                    console.log("success");
                    response.send(true);
                  }

                }
                else {
                    console.log("Väärä pin_koodi");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("user does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("Tunnus_kortti or pin_koodi missing");
      response.send(false);
    }
  }
);

module.exports=router;