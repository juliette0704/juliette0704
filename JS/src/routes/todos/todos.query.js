const express = require("express");
var bcrypt = require('bcrypt');
const router = express();
const jwt = require('jsonwebtoken');
var con = require('../../config/db.js');
const bodyparser = require("body-parser");
const jsonparser = bodyparser.json();
require('dotenv').config();
var email_use = null;
var token = null;

router.delete("/todos/:id",jsonparser, (reqe, rese, next) => {
    const autheader = reqe.headers['authorization']
    const token = autheader && autheader.split(' ')[1]
    if (token == null) return rese.send({"msg": "No token, authorization denied"});
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        var middleware = reqe.params.id;
        con.query('SELECT * FROM todo WHERE id = ?', [middleware], function(error1, results1, fields1) {
            if (error) return res.send({"msg": "Internal server error"});
            if (results1[0] == undefined) return res.send({"msg": "Not found"})
            else {
                con.query('DELETE FROM todo WHERE id = ?', [middleware], function(error, results, fields) {
                    if (error) return rese.send({"msg": "Internal server error"});
                    rese.send({"msg": "Successfully deleted record number :" + middleware});
                });
            }
        });
    });
});

// 
router.get("/todos", jsonparser,(reqe, rese, next) => {
    const autheader = reqe.headers['authorization']
    const token = autheader && autheader.split(' ')[1]
    if (token == null) return rese.send({"msg": "No token, authorization denied"});
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        con.query('select * from todo', function(error, results, fields) {
            if (error) return rese.send({"msg": "Internal server error"});
            rese.send(results);
        });
    });
});

router.get("/todos/:id",jsonparser, (reqe, rese, next) => {
    const autheader = reqe.headers['authorization']
    const token = autheader && autheader.split(' ')[1]
    if (token == null) return rese.send({"msg": "No token, authorization denied"});
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        if (err) return rese.send({" msg ": " Token is not valid "})
        var middleware = reqe.params.id;
        con.query('select * from todo where id = ?', [middleware], function(error, results, fields) {
            if (error) return rese.send({"msg": "Internal server error"});
            if (results[0] == undefined) return rese.send({"msg": "Not found"});
            else rese.send(results);
        });
    });
});

module.exports = router;