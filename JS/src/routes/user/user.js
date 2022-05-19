const express = require("express");
var bcrypt = require('bcrypt');
const router = express();
const jwt = require('jsonwebtoken');
var con = require('../../config/db.js');
const bodyparser = require("body-parser");
const res = require("express/lib/response");
const jsonparser = bodyparser.json();
require('dotenv').config();
var email_use = null;
var token = null;


router.get("/user",jsonparser, (reqe, rese, next) => {
    const autheader = reqe.headers['authorization']
    const token = autheader && autheader.split(' ')[1]
    if (token == null) return rese.send({"msg": "No token, authorization denied"});
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        if (err) return rese.send({" msg ": " Token is not valid "})
        con.query('select * from user', function(error, results, fields) {
            rese.send(results);
        });
    });
});

// view all user task
router.get("/user/todos",jsonparser, (reqe, rese, next) => {
    const autheader = reqe.headers['authorization']
    const token = autheader && autheader.split(' ')[1]
    if (token == null) return rese.send({"msg": "No token, authorization denied"});
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        if (err) return rese.send({" msg ": " Token is not valid "})
        email_use = jwt.decode(token)['email'];
        con.query('select id from user where email = ?', [email_use], function(error, results, fields) {
            if (error) return rese.send({"msg": "Not found"});
            var iduse = results[0]['id'];
            con.query('select * from todo where user_id = ?', [iduse], function(error2, results2, fields2) {
                rese.send(results2);
            });
        }); 
    });
});

// delete user
router.delete("/user/:id", jsonparser,(reqe, rese, next) => {
    const autheader = reqe.headers['authorization']
    const token = autheader && autheader.split(' ')[1]
    if (token == null) return rese.send({"msg": "No token, authorization denied"});
    jwt.verify(token,process.env.TOKENSECRET, (err, verifiedJwt) => {
        if (err) return rese.send({" msg ": " Token is not valid "})
        var middleware = reqe.params.id;
        con.query('SELECT * FROM user WHERE id = ?', [middleware], function(error, results, fields) {
            if (results[0] == undefined) return rese.send({"msg": "Not found"});
            else {
                con.query('DELETE FROM user WHERE id = ?', [middleware], function(error, results, fields) {
                    if (error) return rese.send({"msg": "Not found"});
                    else rese.send({"msg": "Successfully deleted record number : "+ middleware});
                });
            };
        });
    });
});

module.exports = router;