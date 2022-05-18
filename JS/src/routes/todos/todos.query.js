const express = require("express");
var bcrypt = require('bcrypt');
const router = express();
const jwt = require('jsonwebtoken');
var con = require('../../config/db.js');
const bodyparser = require("body-parser");
var token = require('../../index');
const jsonparser = bodyparser.json();
require('dotenv').config();
var email_use = null;
// var token = null;

router.delete("/todos/:id",jsonparser, (reqe, rese, next) => {
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        var middleware = reqe.params.id;
        con.query('DELETE FROM todo WHERE id = ?', [middleware], function(error, results, fields) {
                rese.status(200).json;
        });
    });
});

// 
router.get("/todos", jsonparser,(reqe, rese, next) => {
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        con.query('select * from todo', function(error, results, fields) {
            rese.send(results);
        });
    });
});

router.get("/todos/:id",jsonparser, (reqe, rese, next) => {
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        var middleware = reqe.params.id;
        con.query('select * from todo where id = ?', [middleware], function(error, results, fields) {
                rese.send(results);
        });
    });
});


module.exports = router;