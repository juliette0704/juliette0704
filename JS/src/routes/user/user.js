const express = require("express");
var bcrypt = require('bcrypt');
const router = express();
const jwt = require('jsonwebtoken');
var con = require('../../config/db.js');
const bodyparser = require("body-parser");
const jsonparser = bodyparser.json();
require('dotenv').config();
var email_use = null;
// var token = null;
var token = require('../../index')(token);


router.get("/user",jsonparser, (reqe, rese, next) => {
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        console.log(token);
        con.query('select * from user', function(error, results, fields) {
            rese.send(results);
        });
    });
});

// view all user task
router.get("/user/todo",jsonparser, (reqe, rese, next) => {
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        con.query('select id from user where email = ?', [email_use], function(error, results, fields) {
            var iduse = results[0];
            con.query('select * from todo where user_id = ?', [iduse], function(error2, results2, fields2) {
                rese.send(results2);
            });
        }); 
    });
});

// delete user
router.delete("/user/:id", jsonparser,(reqe, rese, next) => {
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        var middleware = reqe.params.id;
        con.query('DELETE FROM user WHERE id = ?', [middleware], function(error, results, fields) {
                rese.status(200).json;
        });
    });
});

module.exports = router;